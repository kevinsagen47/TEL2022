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
//int minimum_pwm=50,minimum_pwm2=95,minimum_pwm3=95,minimum_pwm4=60;
int minimum_pwm=50,minimum_pwm2=50,minimum_pwm3=50,minimum_pwm4=50;
int _minimum_pwm=-50,_minimum_pwm2=-50,_minimum_pwm3=-50,_minimum_pwm4=-50;
//int minimum_pwm=100,minimum_pwm2=100,minimum_pwm3=100,minimum_pwm4=100;
int start_pwm=50,end_pwm=50, tolerance=5;
int current_speed,speed_time,speed_time_var=20;
unsigned long elapsed, elapsedd,timee,timeee;
int dist_tol=10;//distance tolerance
int cal_speed=38,prev_dir=0;
int max_attempt=5,count_attempt;
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
  delay(100);
}

void loop() {
  //delay(1000);
  getppm();
  
  //forward_degree(75,200);wait(1000);forward_degree(75,-200);
  //side_degree(150,-200);wait(1000);side_degree(150,200);
  //turn_degree(150,-100);wait(1000);turn_degree(150,100);
  
  wait(500);
  //Serial.println("done");
  cal_front(500);
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


