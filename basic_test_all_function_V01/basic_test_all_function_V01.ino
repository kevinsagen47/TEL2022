#include <PIDController.h>
volatile long int encoder_pos1 = 0;
volatile long int encoder_pos2 = 0;
volatile long int encoder_pos3 = 0;
volatile long int encoder_pos4 = 0;
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
int minimum_pwm=30;
unsigned long elapsed, elapsedd;
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
  
  pinMode(13,1);
  pinMode(12,1);
  pinMode(11,1);
  pinMode(10,1);
  pinMode(9,1);
  pinMode(8,1);
  pinMode(7,1);
  pinMode(6,1);
  attachInterrupt(digitalPinToInterrupt(18), encoder, RISING);
  attachInterrupt(digitalPinToInterrupt(19), encoder2, RISING);
  attachInterrupt(digitalPinToInterrupt(20), encoder3, RISING);
  attachInterrupt(digitalPinToInterrupt(21), encoder4, RISING);

  pos_pid1.begin();    
  pos_pid1.tune(100, 0, 8000);    
  pos_pid1.limit(-255, 255);
  pos_pid1.setpoint(0);

  pos_pid2.begin();    
  pos_pid2.tune(100, 0, 8000);    
  pos_pid2.limit(-255, 255);
  pos_pid2.setpoint(0);

  pos_pid3.begin();    
  pos_pid3.tune(100, 0, 8000);    
  pos_pid3.limit(-255, 255);
  pos_pid3.setpoint(0);

  pos_pid4.begin();    
  pos_pid4.tune(100, 0, 8000);    
  pos_pid4.limit(-255, 255);
  pos_pid4.setpoint(0);
  delay(100);
}

void loop() {
  //delay(1000);
  getppm();
  forward_degree(150,150);
  forward_degree(50,50);
  //side_degree(100,-100);
  while(1){
    run();
    //delay(100);
    }
  print_encoder();
/*  
  right_ir=analogRead(A0);
  left_ir =analogRead(A1);
  while (right_ir<550 && left_ir<550){
    right_ir=analogRead(A0);
    left_ir =analogRead(A1);
    forward_speed(75);
    delayMicroseconds(delaymic);
  }
  while(1){
    stop_move();
    delay(100);}*/
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


