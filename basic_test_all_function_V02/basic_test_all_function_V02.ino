////////////////////////USER ADJUSTABLESSSSS//////////////////////////////
int minimum_pwm=70,_minimum_pwm=-70;
int start_pwm=80,end_pwm=70;//start speed, if too fast can slip
int  tolerance=5;//可接受誤差
int offset1=-4,offset2=-9,offset3=-4,offset4=-14;//pwm forward
//int offset1=0,offset2=0,offset3=0,offset4=0;
int _offset1=-2,_offset2=5,_offset3=2,_offset4=3;//pwm backwards
#include <PIDController.h>
#include <TimeInterrupt.h>
int dist_tol=5;//distance tolerance(紅外線可接受的誤差值)
int cal_speed=70;
bool speed_correction=false;//prints speed, degree/100ms
//////////////////////////////////////////////////////////////////////////






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
int delaymic=50;
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
}


void loop() {
  
  while(digitalRead(42))wait(100);
  
  wait(500);
  
  
  

  cal_left(550);
  Serial.println("done");

}
  //getppm();
//forward_degree(100,200);wait(1000);forward_degree(75,-200);
  //side_degree(150,300);wait(1000);side_degree(150,-300);
  //side_degree(75,400);wait(500);forward_degree(100,400);wait(500);side_degree(75,-400);wait((500));forward_degree(100,-400);
  //turn_degree(150,-200);wait(1000);turn_degree(150,200);
    //cal_front(400);//max 550