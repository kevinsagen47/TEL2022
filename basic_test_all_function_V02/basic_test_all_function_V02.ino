#include <PIDController.h>
//#include "TimerOne.h"


#include <TimeInterrupt.h>

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
unsigned int integerValue=0;  // Max value is 65535
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
//int minimum_pwm=50,minimum_pwm2=95,minimum_pwm3=95,minimum_pwm4=60;
int minimum_pwm=60,_minimum_pwm=-60;
int minimum_pwm2=50,minimum_pwm3=50,minimum_pwm4=50,_minimum_pwm2=-50,_minimum_pwm3=-50,_minimum_pwm4=-50;
//int minimum_pwm=100,minimum_pwm2=100,minimum_pwm3=100,minimum_pwm4=100;
int start_pwm=80,end_pwm=80, tolerance=5;
int current_speed,speed_time,speed_time_var=20;
unsigned long elapsed, elapsedd,timee,timeee;
int dist_tol=5;//distance tolerance
int cal_speed=55,prev_dir=0;
int max_attempt=5,count_attempt;
unsigned speed_timer1,speed_timer2,speed_timer3,speed_timer4;
int offset1=-4,offset2=-9,offset3=-4,offset4=-14;
int _offset1=-2,_offset2=5,_offset3=2,_offset4=3;
int t1,t2,t3,t4;
int _t1,_t2,_t3,_t4;
int speed_tol=3;
bool speed_correction=false,done_waiting=false;
void setup() {
  minimum_pwm2=minimum_pwm;
  minimum_pwm3=minimum_pwm;
  minimum_pwm4=minimum_pwm;

  _minimum_pwm2=_minimum_pwm;
  _minimum_pwm3=_minimum_pwm;
  _minimum_pwm4=_minimum_pwm;
  Serial.begin(115200);
  pinMode(18, INPUT);
  pinMode(14, INPUT);
  
  pinMode(19, INPUT);
  pinMode(15, INPUT);
  
  pinMode(20, INPUT);
  pinMode(16, INPUT);
  
  pinMode(21, INPUT);
  pinMode(17, INPUT);
  
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
  pinMode(13,1);
  pinMode(12,1);
  pinMode(11,1);
  pinMode(10,1);
  pinMode(9,1);
  pinMode(8,1);
  pinMode(7,1);
  pinMode(6,1);

  pinMode(43,1);
  digitalWrite(43,1);
  attachInterrupt(digitalPinToInterrupt(18), encoder, RISING);
  attachInterrupt(digitalPinToInterrupt(19), encoder2, RISING);
  attachInterrupt(digitalPinToInterrupt(20), encoder3, RISING);
  attachInterrupt(digitalPinToInterrupt(21), encoder4, RISING);

  pos_pid1.begin();    
  pos_pid1.tune(100, 0, 4000);    
  pos_pid1.limit(-255, 255);
  pos_pid1.setpoint(0);

  pos_pid2.begin();    
  pos_pid2.tune(100, 0, 4000);    
  pos_pid2.limit(-255, 255);
  pos_pid2.setpoint(0);

  pos_pid3.begin();    
  pos_pid3.tune(100, 0, 4000);    
  pos_pid3.limit(-255, 255);
  pos_pid3.setpoint(0);

  pos_pid4.begin();    
  pos_pid4.tune(100, 0, 4000);    
  pos_pid4.limit(-255, 255);
  pos_pid4.setpoint(0);
  TimeInterrupt.begin(NORMAL); 
  TimeInterrupt.addInterrupt(callback, 40);
  TimeInterrupt.addInterrupt(callback2, 40);
  /*
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(callback);
  */
  delay(100);
}
void callback2(){
if(speed_correction){  
Serial.print(speed1);
    Serial.print(" ");
    Serial.print(speed2);
    Serial.print(" ");
    Serial.print(speed3);
    Serial.print(" ");
    Serial.println(speed4);
  if(t1!=0){
  if(speed1<t1)  offset1++;
  else if(speed1+speed_tol>t1)  offset1--;}

  if(t2!=0){
  if(speed2<t2)  offset2++;
  else if(speed2+speed_tol>t2)  offset2--;}

  if(t3!=0){
  if(speed3<t3)  offset3++;
  else if(speed3+speed_tol>t3)  offset3--;}

  if(t4!=0){
  if(speed4<t4)  offset4++;
  else if(speed4+speed_tol>t4)  offset4--;}
  
  if(_t1!=0){
  if(-1*speed1<_t1)  _offset1++;
  else if(-1*speed1+speed_tol>t1)  _offset1--;}
  
  if(_t2!=0){
  if(-1*speed2<_t2)  _offset2++;
  else if(-1*speed2+speed_tol>t2)  _offset2--;}

  if(_t3!=0){
  if(-1*speed3<_t3)  _offset3++;
  else if(-1*speed3+speed_tol>t3)  _offset3--;}

  if(_t4!=0){
  if(-1*speed4<_t4)  _offset4++;
  else if(-1*speed4+speed_tol>t4)  _offset4--;}
}
}
void callback(){
  speed1=encoder_pos1-prev_encoder_pos1;
  prev_encoder_pos1=encoder_pos1;

  speed2=encoder_pos2-prev_encoder_pos2;
  prev_encoder_pos2=encoder_pos2;
  
  speed3=encoder_pos3-prev_encoder_pos3;
  prev_encoder_pos3=encoder_pos3;

  speed4=encoder_pos4-prev_encoder_pos4;
  prev_encoder_pos4=encoder_pos4;
}

void loop() {
  getppm();
  Serial.print(speed1);
  Serial.print(" ");
  Serial.print(speed2);
  Serial.print(" ");
  Serial.print(speed3);
  Serial.print(" ");
  Serial.println(speed4);
  delay(200);
  //*
  //while(1)
  //forward_speed(-60);
//*/
  //*
  wait(500);
  //forward_degree(100,400);wait(1000);forward_degree(75,-400);
  side_degree(75,400);wait(1000);side_degree(75,-400);
  //side_degree(75,400);wait(500);forward_degree(100,400);wait(500);side_degree(75,-400);wait((500));forward_degree(100,-400);
  //turn_degree(150,-100);wait(1000);turn_degree(150,100);
  
  
  cal_front(500);//max 550
  Serial.println("done");
  while(1){
    wait(1000);
    right_ir=analogRead(A0);
    left_ir =analogRead(A1);
    Serial.print(left_ir);
  Serial.print("  ");
  Serial.println(right_ir);
    //delay(100);
    }
    //*/
  //print_encoder();
  /*  
if (Serial.available() > 0) {  
    integerValue = 0;        
    while(1) {           
      incomingByte = Serial.read();
      if (incomingByte == '\n') break;   
      if (incomingByte == -1) continue;  
      integerValue *= 10;  
      integerValue = ((incomingByte - 48) + integerValue);
      pos_pid.setpoint(integerValue);
    }
}

   motor_value = pos_pid.compute(encoder_pos1);
if(motor_value > 0){
  MotorCounterClockwise(motor_value);
}else{
  MotorClockwise(abs(motor_value));
}
*/
 
}


