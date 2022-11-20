#include <PIDController.h>
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
volatile long int encoder_pos = 0;
volatile long int encoder_pos2 = 0;
volatile long int encoder_pos3 = 0;
volatile long int encoder_pos4 = 0;
int32_t measured_time, measured_time_start;
uint8_t channel_select_counter;
PIDController pos_pid; 
int motor_value = 255;
unsigned int integerValue=0;  // Max value is 65535
char incomingByte;
#include <PPMReader.h>
byte interruptPin = 2;
byte channelAmount = 8;
PPMReader ppm(interruptPin, channelAmount);
int channel_[10]={0,1,2,3,4,5,6,7,8,9};
int forward,side,turn;
int f_r,f_l,b_r,b_l;
int _f_r,_f_l,_b_r,_b_l;
int minimum_pwm=40;
int home1_=80,home2_=130,home3_=180,home4_=100,home6_=90,home5_;//folded out positition, prepare to take
int home1=80,home2=110,home3=1,home4=90,home5=90,home6=90;//start position (hand folded <30cm)
int pos1=home1,pos2=home2,pos3=home3,pos4=home4,pos5=home5,pos6=home6;
int min_speed=20,max_speed=8;//servo delay time
int sdelayt=20,delayt=max_speed,loading=0;
int delay1,delay2,delay3,delay4,delay5;
int max1=180,max2=140,max3=180,max4=180,max5=180;
int min1=0,min2=0,min3=0,min4=0,min5=0;
unsigned long time1,time2,time3,time4,time5,addtime;
//1: x_r
//2: y_r
//3: y_l
//4: x_r
//5: SD 3 position
//6: SF
//7: SH button
void setup() {
  servo1.attach(3);
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(44);
  servo5.attach(45);
  servo6.attach(46);
  
  Serial.begin(115200);
  pinMode(18, INPUT);
  pinMode(14, INPUT);
  
  pinMode(19, INPUT);
  pinMode(15, INPUT);
  
  pinMode(20, INPUT);
  pinMode(16, INPUT);
  
  pinMode(21, INPUT);
  pinMode(17, INPUT);

  pinMode(43,1);
  digitalWrite(43,1);

  pinMode(13,1);
  pinMode(12,1);
  pinMode(11,1);
  pinMode(10,1);
  pinMode(9,1);
  pinMode(8,1);
  pinMode(7,1);
  pinMode(6,1);
  //pinMode(5,1);
  pos_pid.begin();    
  pos_pid.tune(15, 0, 2000);    
  pos_pid.limit(-255, 255);
  


  servo1.write(home1);
  delay(100);
  servo2.write(home2);
  delay(100);
  servo3.write(home3);
  delay(100);
  servo4.write(home4);
  delay(100);
  servo5.write(180-home4);
  delay(100);
  servo6.write(home6);
}

void loop() {
  get_ppm();
  print_channels();
  addtime=millis();
  if(channel_[5]<1300 && channel_[5]>0)motor_control();
  else if (channel_[5]<1600 && channel_[5]>1400){  
    if(channel_[7]>1500)loading=2;
    if(loading==0)servo_control();  
    /*
    Serial.print(pos2);
    Serial.print(" ");
    Serial.println(pos3);
    */
    all_stop();}    
  else all_stop();
  if(loading_function>=1)loading_function();
  update_servo();
  //Serial.println(loading);
  }
