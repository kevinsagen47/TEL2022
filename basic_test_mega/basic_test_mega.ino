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
  
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(18), encoder, RISING);
  attachInterrupt(digitalPinToInterrupt(19), encoder2, RISING);
  attachInterrupt(digitalPinToInterrupt(20), encoder3, RISING);
  attachInterrupt(digitalPinToInterrupt(21), encoder4, RISING);
  

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
    //Serial.println();

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
*/
   motor_value = pos_pid.compute(encoder_pos);
if(motor_value > 0){
  MotorCounterClockwise(motor_value);
}else{
  MotorClockwise(abs(motor_value));
}
  Serial.print("Enc: ");
  Serial.print(encoder_pos);
  Serial.print("  ");
  Serial.print(encoder_pos2);
  Serial.print("  ");
  Serial.print(encoder_pos3);
  Serial.print("  ");
  Serial.print(encoder_pos4);
  /*
  Serial.print("  ppm: ");
  Serial.print(channel_[1]);
  Serial.print("  ");
  Serial.print(channel_[2]);
  Serial.print("  ");
  Serial.print(channel_[3]);
  Serial.print("  ");
  Serial.print(channel_[4]);
  Serial.print("  ");
  Serial.print(channel_[5]);
  Serial.print("  ");
  Serial.print(channel_[6]);
  Serial.print("  ");
  Serial.print(channel_[7]);
  */
  Serial.println();
  delay(100);
}

/*
  pinMode(PB12, INPUT);
  pinMode(PB13, INPUT);
  
  pinMode(PB14, INPUT);
  pinMode(PB15, INPUT);
  
  pinMode(PA15, INPUT);
  pinMode(PB3, INPUT);
  
  pinMode(PB4, INPUT);
  pinMode(PB5, INPUT);
  
  pinMode(PB6, OUTPUT);
  pinMode(PB7, OUTPUT);
*/
void encoder4(){
  if(digitalRead(17) == HIGH)encoder_pos4++;
  else encoder_pos4--;}


void encoder3(){
  if(digitalRead(16) == HIGH)encoder_pos3++;
  else encoder_pos3--;}


void encoder2(){
  if(digitalRead(15) == HIGH)encoder_pos2++;
  else encoder_pos2--;}

void encoder(){
  if(digitalRead(14) == HIGH)encoder_pos--;
  else encoder_pos++;}

void MotorClockwise(int power){
  if(power > 100){
  analogWrite(9, power);
  digitalWrite(10, LOW);
  }else{
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }
}

void MotorCounterClockwise(int power){
  if(power > 100){
  analogWrite(10, power);
  digitalWrite(9, LOW);
  }else{
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }
}
