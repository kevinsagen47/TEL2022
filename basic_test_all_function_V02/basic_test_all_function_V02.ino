#include <PIDController.h>
#include <Servo.h>
//#include <TimeInterrupt.h>

////////////////////////USER ADJUSTABLESSSSS//////////////////////////////
int minimum_pwm=100,_minimum_pwm=-100;//EX.機器人要移動100度，但超過5度，調誤差回的速度
int start_pwm=90,end_pwm=90;//start speed, if too fast can slip
int  tolerance=5;//可接受誤差
int dist_tol=5;//distance tolerance(紅外線可接受的誤差值)
int offset1=10,offset2=9,offset3=7,offset4=0;//pwm forward  (前進四輪速度的補值)
int _offset1=16,_offset2=0,_offset3=12,_offset4=13;//pwm backwards(後退四輪速度的補值)
int cal_speed=70;

int follow_dist=180;//high 150 floor 180<--------------------------------------------------------!!!!!!!!!!!!!!!
int follow_speed=110;//走在邊邊，左右邊的輪子矯正的速度(一邊兩顆馬達的速度)
int follow_tol=10;//high=50, floor=20<-----------------------------------------------------------!!!!!!!!!!!!!!
bool speed_correction=false;//ture=要測四輪的速度 prints speed, degree/100ms
int tol_time=1000;
//////////////////////////////////////////////////////////////////////////
//normal 230
//floor minimum 180//reccomended 200
//100

//pos6  min 58 //close
//pos6 max 155 //open
//pos7 65 min//opem
//pos7 147 max closed
//pos7 138 oopen a little
int popping;


Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
int home1_=80,home2_=130,home3_=180,home4_=100,home6_=58,home5_;//folded out positition, prepare to take (degree)
int home1=91,home2=53,home3=0,home4=90,home5=90,home6=58,home7=138;//load-off payload 91 53 0 148
int home1_30=91,home2_30=115,home3_30=59,home4_30=90,home5_30=90,home6_30=58,home7_30=138;//start position (hand folded <30cm)
int pos1=home1_30,pos2=home2_30,pos3=home3_30,pos4=home4_30,pos5=home5_30,pos6=home6_30,pos7=home7_30;

int min_speed=20,max_speed=8;//servo delay time
int sdelayt=20,delayt=max_speed,loading=0;
int delay1,delay2,delay3,delay4,delay5;
int max1=180,max2=140,max3=180,max4=180,max5=180;
int min1=0,min2=0,min3=0,min4=0,min5=0;
unsigned long time1,time2,time3,time4,time5,time6,time7,addtime;



volatile long int encoder_pos1 = 0;
volatile long int encoder_pos2 = 0;
volatile long int encoder_pos3 = 0;
volatile long int encoder_pos4 = 0;
volatile long int prev_encoder_pos1 = 0;
volatile long int prev_encoder_pos2 = 0;
volatile long int prev_encoder_pos3 = 0;
volatile long int prev_encoder_pos4 = 0;
int speed1,speed2,speed3,speed4;
int32_t measured_time, measured_time_start;
uint8_t channel_select_counter;
PIDController pos_pid1;
PIDController pos_pid2; 
PIDController pos_pid3; 
PIDController pos_pid4; 
int motor_value = 255;
unsigned int integerValue=0; 
char incomingByte;
#include <PPMReader.h>
byte interruptPin = 2;
byte channelAmount = 8;
PPMReader ppm(interruptPin, channelAmount);
int channel_[10]={0,1,2,3,4,5,6,7,8,9};
int right_ir, left_ir;
int delaymic=0;
int motor_value1,motor_value2,motor_value3,motor_value4;
int a,b,c,d,stationary;
//int minimum_pwm2=50,minimum_pwm3=50,minimum_pwm4=50,_minimum_pwm2=-50,_minimum_pwm3=-50,_minimum_pwm4=-50;
int minimum_pwm2=minimum_pwm,minimum_pwm3=minimum_pwm,minimum_pwm4=minimum_pwm,_minimum_pwm2=_minimum_pwm,_minimum_pwm3=_minimum_pwm,_minimum_pwm4=_minimum_pwm;
//int minimum_pwm=100,minimum_pwm2=100,minimum_pwm3=100,minimum_pwm4=100;
int current_speed,speed_time;
int speed_time_var=20;//accel slope, the smaller number, accel faster
unsigned long elapsed, elapsedd,timee,timeee;
int prev_dir=0;
int max_attempt=5,count_attempt;
unsigned speed_timer1,speed_timer2,speed_timer3,speed_timer4;
int t1,t2,t3,t4;
int _t1,_t2,_t3,_t4;
int speed_tol=3;
int front_right_ir,rear_right_ir;
int front_left_ir,rear_left_ir;
bool done_waiting=false;


void setup() {
  setup_robot();
  
  servo1.attach(3);
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(44);
  servo5.attach(45);
  servo6.attach(46);
  servo7.attach(47);
  /*
  servo6.write(home6_30);
  delay(100);
  servo7.write(home7_30);
  delay(100);
  servo3.write(home3_30);
  delay(500);
  servo2.write(home2_30);
  delay(100);
  servo1.write(home1_30); 
  delay(100);
  servo4.write(home4_30);
  delay(100);
  servo5.write(180-home4_30);
  int pos1=home1_30,pos2=home2_30,pos3=home3_30,pos4=home4_30,pos5=home5_30,pos6=home6_30,pos7=home7_30;
  */

  servo6.write(home6);
  delay(100);
  servo7.write(home7);
  delay(100);
  servo3.write(home3);
  delay(500);
  servo2.write(home2);
  delay(100);
  servo1.write(home1); 
  delay(100);
  servo4.write(home4);
  delay(100);
  servo5.write(180-home4);
  pos1=home1;pos2=home2;pos3=home3;pos4=home4;pos5=home5;pos6=home6;pos7=home7;
}


void loop() {
  print_encoder();
  delay(200);
  while(digitalRead(42))run(); 

  //*/////////////////////second part///////////////////////////
  forward_degree(120,1100);wait(500);//出發前進第二關20
  cal_left(360);wait(1000);//靠左矯正-到第一個點
  forward_degree(220,800);wait(500);//出發前進第二關40
  side_degree(150,-440);wait(1000);//左移
  forward_degree(220,800);wait(500);//前進
  cal_right(310);wait(1000);//靠右矯正-到第二個點
  forward_degree(220,700);wait(1000);//出發前進第二關60
  side_degree(150,430);wait(500);//右移
  forward_degree(180,660);wait(500);//前進到第二關60
  cal_left(310);wait(5000);//靠右矯正-到第三個點
//*/////////////////////////////////////////////////////////



  //side_degree(150,600);Serial.print("Doneeeee");wait(500);
  //take_1_cube(); 
  //turn_off_motor();
  take_1_cube(); 
  //while(1)delay(1000);
      
      
      
      
  
 // right_slide_A1_leave(140);wait(500);
  /*forward_degree(100,600);wait(500);
  follow_left_down_A0_A1(follow_dist);//150
  side_degree(150,300)
  wait(1000);
  cal_front(400);
  take_1_cube(); 
  turn_off_motor();
  //cal_left(550);
  //while(1)print_servo();
  Serial.println("done");
  //while(1)delay(1000);
  */

}
//stop();
  //getppm();
//forward_degree(100,200);wait(1000);forward_degree(75,-200);
  //side_degree(150,300);wait(1000);side_degree(150,-300);
  //side_degree(75,400);wait(500);forward_degree(100,400);wait(500);side_degree(75,-400);wait((500));forward_degree(100,-400);
  //turn_degree(150,-200);wait(1000);turn_degree(150,200);
    //cal_front(400);//max 550