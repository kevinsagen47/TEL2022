#include <PIDController.h>
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
int forward,backward,left,right,turn_left,turn_right;
int f_r,f_l,b_r,b_l;
int _f_r,_f_l,_b_r,_b_l;
//1: x_r
//2: y_r
//3: y_l
//4: x_r
//5: SD 3 position
//6: SF
//7: SH button
void setup() {

  Serial.begin(115200);
  pinMode(18, INPUT);
  pinMode(14, INPUT);
  
  pinMode(19, INPUT);
  pinMode(15, INPUT);
  
  pinMode(20, INPUT);
  pinMode(16, INPUT);
  
  pinMode(21, INPUT);
  pinMode(17, INPUT);

  

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
  delay(100);
}

void loop() {
for (byte channel = 1; channel <= channelAmount; ++channel) {
        unsigned value = ppm.latestValidChannelValue(channel, 0);
        //Serial.print(value);
        channel_[channel]=value;
        if(channel < channelAmount) Serial.print('\t');
    }

  if(channel_[2]>50){
    if(channel_[2]>1549){
      forward=map(channel_[2],1550,2000,0,255);
      backward=0;} 
    else if (channel_[2]<1450)  {
      backward=map(channel_[2],1450,1000,0,255);
      forward=0;}
    else {
      forward=0;
      backward=0;}

    if (channel_[1]>50){
      if(channel_[1]>1549){
        right=map(channel_[1],1550,2000,0,255);
        left=0;} 
      else if (channel_[1]<1450){
        left=map(channel_[1],1450,1000,0,255);
        right=0;}
      else {
        right=0;
        left=0;}
    }

    if (channel_[4]>50){
      if(channel_[4]>1549){
        turn_right=map(channel_[4],1550,2000,0,255);
        turn_left=0;} 
      else if (channel_[4]<1450){
        turn_left=map(channel_[4],1450,1000,0,255);
        turn_right=0;}
      else {
        turn_right=0;
        turn_left=0;}
    }
    
    //backward=0;
    f_r=forward+right+turn_left;
    f_l=forward+left+turn_right;
    b_r=forward+left+turn_left;
    b_l=forward+right+turn_right;

    _f_r=backward+left+turn_right;
    _f_l=backward+right+turn_left;
    _b_r=backward+right+turn_right;
    _b_l=backward+left+turn_left;
  }
  else{
    f_r=0;
    f_l=0;
    b_r=0;
    b_l=0;

    _f_r=0;
    _f_l=0;
    _b_r=0;
    _b_l=0;    
  }

  //Serial.print(forward);
  //Serial.print("  ");
  //Serial.print(backward);
  Serial.print(channel_[4]);
  Serial.println();
  analogWrite(13,f_r);
  analogWrite(11,f_l);
  analogWrite(9,b_r);
  analogWrite(7,b_l);

  if(f_r==0)analogWrite(12,_f_r);
  if(f_l==0)analogWrite(10,_f_l);
  if(b_r==0)analogWrite(8,_b_r);
  if(b_l==0)analogWrite(6,_b_l);

}

