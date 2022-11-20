#include <PIDController.h>
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
//Servo servo6;
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
byte interruptPin = PB4;
byte channelAmount = 8;
PPMReader ppm(interruptPin, channelAmount);
int channel_[10]={0,1,2,3,4,5,6,7,8,9};
int forward,side,turn;
int f_r,f_l,b_r,b_l;
int _f_r,_f_l,_b_r,_b_l;
int minimum_pwm=40;
int home1=100,home2=130,home3=1,home4=100,home5=90,home6=90;
int home1_=100,home2_=130,home3_=180,home4_=100,home6_=90,home5_;
int pos1=home1,pos2=home2,pos3=home3,pos4=home4,pos5=home5,pos6=home6;
int min_speed=20,max_speed=8;//servo delay time
int sdelayt=20,delayt=max_speed, loading=0;
int delay1,delay2,delay3,delay4,delay5;
int max1=180,max2=130,max3=180,max4=180,max5=180;
int min1=0,min2=0,min3=0,min4=0,min5=0;
unsigned long time1,time2,time3,time4,time5,addtime,time_ch7;
//1: x_r
//2: y_r
//3: y_l
//4: x_r
//5: SD 3 position
//6: SF
//7: SH button
void setup() {
  servo1.attach(PA8);
  servo2.attach(PA9);
  servo3.attach(PA10);
  servo4.attach(PA3);
  servo5.attach(PA2);
  //servo6.attach(PB4);
  
  Serial.begin(115200);
  //pinMode(5,1);
  pos_pid.begin();    
  pos_pid.tune(15, 0, 2000);    
  pos_pid.limit(-255, 255);
  

  delay(1000);
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
  //servo6.write(home6);
}

void loop() {
  get_ppm();
  addtime=millis();
  if (channel_[5]<2100 && channel_[5]>1900){
    servo_control();
    if(channel_[7]>1500 &&channel_[7]<2100){
      if((millis()-time_ch7)>200){
      loading=2;}
      }
    else time_ch7=millis();
    if(loading==0)servo_control();
  //servo6.write(home6);
  Serial.println(channel_[7]);
  }
  if(loading>=1)loading_function();
  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);
  servo5.write(180-pos4);

}
