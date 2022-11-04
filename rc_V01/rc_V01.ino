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
int forward,side,turn;
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
    if(channel_[2]>1549)forward=map(channel_[2],1550,2000,0,255);
    else if (channel_[2]<1450) forward=-1*map(channel_[2],1450,1000,0,255);
    else forward=0;

    if (channel_[1]>50){
      if(channel_[1]>1549)side=map(channel_[1],1550,2000,0,255);
      else if (channel_[1]<1450)side=-1*map(channel_[1],1450,1000,0,255);
      else side=0;}

    if (channel_[4]>50){
      if(channel_[4]>1549)turn=map(channel_[4],1550,2000,0,255);
      else if (channel_[4]<1450)turn=-1*map(channel_[4],1450,1000,0,255);
      else turn=0;}
    
    //backward=0;
    f_r=   forward+   side+-1*turn;
    f_l=   forward+-1*side+   turn;
    b_r=forward+-1*side+-1*turn;
    b_l=forward+   side+   turn;
  }
  else{
    f_r=0;
    f_l=0;
    b_r=0;
    b_l=0;   
  }

  //Serial.print(forward);
  //Serial.print("  ");
  //Serial.print(backward);
  Serial.print(channel_[4]);
  Serial.println();
  
  
  

  if(f_r>=0){
    analogWrite(13,f_r);
    analogWrite(12,0);}
  else {
    analogWrite(12,-1*f_r);
    analogWrite(13,0);}
    
  if(f_l>=0){
    analogWrite(11,f_l);
    analogWrite(10,0);}
  else {
    analogWrite(10,-1*f_l);
    analogWrite(11,0);}
  
  if(b_r>=0){
    analogWrite(9,b_r);
    analogWrite(8,0);}
  else {
    analogWrite(8,-1*b_r);
    analogWrite(9,0);}

  if(b_l>=0){
    analogWrite(7,b_l);
    analogWrite(6,0);}
  else {
    analogWrite(6,-1*b_l);
    analogWrite(7,0);}

}

