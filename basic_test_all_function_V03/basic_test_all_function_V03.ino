#include <PIDController.h>
#include <Servo.h>
//#include <TimeInterrupt.h>

////////////////////////USER ADJUSTABLESSSSS//////////////////////////////
int minimum_pwm=100,_minimum_pwm=-100;//EX.機器人要移動100度，但超過5度，調誤差回的速度
int start_pwm=90,end_pwm=90;//start speed, if too fast can slip 90
int tolerance=5;//可接受誤差
int dist_tol=5;//distance tolerance(紅外線可接受的誤差值)


int offset1=0,offset2=0,offset3=0,offset4=0;//pwm forward  (前進四輪速度的補值)5 12 9 30
int _offset1=0,_offset2=0,_offset3=0,_offset4=0;//pwm backwards(後退四輪速度的補值)9 20 20 13
int cal_speed=80;
int follow_dist=190;//high 150 floor 180<------------------------------------------------------------------------------------------------------------------------------------!!!!!!!!!!!!!!!
int follow_speed=110;//走在邊邊，左右邊的輪子矯正的速度(一邊兩顆馬達的速度)
int follow_tol=10;//high=50, floor=20<----------------------------------------------------------------------------------------------------------------------------------------!!!!!!!!!!!!!!
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
int home1_=80,home2_=130,home3_=180,home4_=100,home6_=58,home5_,home7_=65;//folded out positition, prepare to take (degree)
int home1=91,home2=53,home3=0,home4=90,home5=90,home6=58,home7=138;//load-off payload 91 53 0 148
int home1_30=91,home2_30=115,home3_30=59,home4_30=90,home5_30=90,home6_30=58,home7_30=138;//start position (hand folded <30cm)
int pos1=home1_30,pos2=home2_30,pos3=home3_30,pos4=home4_30,pos5=home5_30,pos6=home6_30,pos7=home7_30;
int balance1=91,balance2=120,balance3=90;
//balance 91 81 47 
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
int back_right_ir,back_left_ir;
bool done_waiting=false;


int forward,side,turn;
int f_r,f_l,b_r,b_l;
int _f_r,_f_l,_b_r,_b_l;
int open_door;

unsigned long wait_start_button,debounce_timer;
bool reset_button;
bool first_3rd_pos=false;
int press_count;
void setup() {
  setup_robot();
  
  servo1.attach(3);
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(44);
  servo5.attach(45);
  servo6.attach(46);
  servo7.attach(47);
  /*//*<--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
  //*<--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  servo6.write(home6);
  delay(100);
  servo7.write(home7);
  delay(100);
  servo3.write(balance3);
  delay(500);
  servo2.write(balance2);
  delay(100);
  servo1.write(balance1); 
  delay(100);
  servo4.write(home4);
  delay(100);
  servo5.write(180-home4);
  pos1=balance1;pos2=balance2;pos3=balance3;pos4=home4;pos5=home5;pos6=home6;pos7=home7;
  //*///<--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
}


void loop() {
  print_encoder();
  //delay(200);
  wait_start_button=millis();
  press_count=0;first_3rd_pos=false;
  while((millis()-wait_start_button)<2000){
    if(press_count==0){wait_start_button=millis();}
    if(digitalRead(42)==1){debounce_timer=millis();reset_button=false;}
    if(((millis()-debounce_timer)>100) && reset_button==false){press_count++;reset_button=true;Serial.println("press detected");}
    //Serial.println(press_count);
    //run();//<--------------------------------------------------------------------------------------------------------------------------------------------on D-day!!!!!!!!!!!!!!!!!!
    //print_sensor();
    rc_v02();//print_servo();//<-------------------------------------------------------------------------------------------------------------------------------------------on D-day!!!!!!!!!!!!!!!!!!
  }
  reset_encoder();
  Serial.print("button count: ");Serial.println(press_count);
  //while(1)digitalWrite(13, 1);
  if(press_count==1)
  {forward_degree(120,500);wait(500);
   while (analogRead(A3)>210||analogRead(A5)>210){side_speed(-120);reset_encoder();}
   follow_left_down_A0_A1(215);wait(500);
   //cal_front(430);wait(1000);
   //while (analogRead(A1)>310){side_speed(105);reset_encoder();}
   side_degree(120,660);wait(1000);
   forward_degree(130,550);wait(600);
   turn_degree(130,-142);wait(800);
   cal_front(420);wait(1000);
   forward_degree(130,-215);wait(1000);//退一個固定的度數「拍照」
   turn_degree(130,150);wait(800);
   follow_right_down_A2_A4(220);wait(1200);
   cal_front(450);wait(1000);
   //while (analogRead(A1)>320){side_speed(-120);reset_encoder();}
   side_degree(120,-690);wait(1000);
   forward_degree(130,1200);wait(1000);
   side_degree(120,500);wait(500);
   while (analogRead(A2)>220||analogRead(A4)>220)side_speed(120);reset_encoder();
   side_degree(105,-210);wait(1000);
   cal_back(380);wait(1000);

  forward_degree(120,1500);wait(500);//出發前進第二關20
  cal_right(310);wait(1000);//靠左矯正-到第一個點
  forward_degree(130,800);wait(1000);//出發前進第二關40
  side_degree(120,-645);wait(1000);//左移
  forward_degree(130,700);wait(500);//前進
  cal_right(310);wait(1000);//靠右矯正-到第二個點
  forward_degree(130,700);wait(1000);//出發前進第二關60
  side_degree(120,380);wait(1000);//右移
  forward_degree(130,700);wait(500);//前進到第二關60
  cal_right(310);wait(1000);//靠右矯正-到第二個點
   
  Serial.println(press_count);}




  
  if(press_count==2){second_post();}//press_count==3;
  if(press_count==3){
    /*forward_degree(150,1100);
    forward_degree(210,30000);forward_degree(210,30000);forward_degree(210,450);wait(800);
    while (analogRead(A0)<325)side_speed(-120);reset_encoder();
    side_degree(120,-550);wait(500);
    cal_front(370);wait(1000);
    side_degree(120,600);wait(500);
    */
    forward_degree(120,400);
    side_degree(180,-850);wait(1000);//下坡有問題!!
    forward_degree(120,300);wait(500);
    side_degree(120,800);wait(5000);

    Serial.println(press_count);}
  if(press_count==4){forward_degree(210,30000);forward_degree(210,30000);wait(500);Serial.println(press_count);}//爬坡
  if(press_count==5){
  //*/////////////////////second part///////////////////////////
  second_post();
  //*/////////////////////////////////////////////////////////
  }
  
  //side_degree(150,600);Serial.print("Doneeeee");wait(500);
  //take_1_cube(); 
  //turn_off_motor();
  
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