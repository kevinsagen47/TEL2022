////////////////////////USER ADJUSTABLESSSSS//////////////////////////////
int minimum_pwm=70,_minimum_pwm=-70;
int start_pwm=90,end_pwm=90, tolerance=5;//start speed, if too fast can slip
int offset1=-4,offset2=-9,offset3=-4,offset4=-14;
#include <PIDController.h>
#include <TimeInterrupt.h>
int _offset1=-2,_offset2=5,_offset3=2,_offset4=3;
int dist_tol=5;//distance tolerance
int cal_speed=60;
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
int current_speed,speed_time,speed_time_var=20;
unsigned long elapsed, elapsedd,timee,timeee;
int prev_dir=0;
int max_attempt=5,count_attempt;
unsigned speed_timer1,speed_timer2,speed_timer3,speed_timer4;
int t1,t2,t3,t4;
int _t1,_t2,_t3,_t4;
int speed_tol=3;
int front_right_ir,rear_right_ir;
int front_left_ir,rear_left_ir;
bool speed_correction=false,done_waiting=false;


void setup() {
  setup_robot();
}


void loop() {
  //getppm();
  while(digitalRead(42))wait(100);
  
  wait(500);
  //forward_degree(100,200);wait(1000);forward_degree(75,-200);
  //side_degree(150,300);wait(1000);side_degree(150,-300);
  //side_degree(75,400);wait(500);forward_degree(100,400);wait(500);side_degree(75,-400);wait((500));forward_degree(100,-400);
  //turn_degree(150,-200);wait(1000);turn_degree(150,200);
  
  
  //cal_front_mini(400);//max 550
  cal_right_mini(550);
  Serial.println("done");
  /*
  while(1){
    wait(1000);
    right_ir=analogRead(A0);
    left_ir =analogRead(A1);
    Serial.print(left_ir);
  Serial.print("  ");
  Serial.println(right_ir);
    //delay(100);
    */
  //print_encoder();
 
}
