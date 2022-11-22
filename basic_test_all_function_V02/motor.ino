void setup_robot(){
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
  pinMode(42, INPUT_PULLUP);
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
  /*
  if(speed_correction==true){
  TimeInterrupt.begin(NORMAL); 
  TimeInterrupt.addInterrupt(callback, 100);//calculate speed interupt
  /*
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(callback);
  */
  delay(100);
}
void callback(){//calculate speed FOR PWM CALIBRATION
  speed1=encoder_pos1-prev_encoder_pos1;
  prev_encoder_pos1=encoder_pos1;

  speed2=encoder_pos2-prev_encoder_pos2;
  prev_encoder_pos2=encoder_pos2;
  
  speed3=encoder_pos3-prev_encoder_pos3;
  prev_encoder_pos3=encoder_pos3;

  speed4=encoder_pos4-prev_encoder_pos4;
  prev_encoder_pos4=encoder_pos4;

  Serial.print(speed1);
    Serial.print(" ");
    Serial.print(speed2);
    Serial.print(" ");
    Serial.print(speed3);
    Serial.print(" ");
    Serial.println(speed4);
}

void turn_off_motor(){
  analogWrite(13,0);
  analogWrite(12,0);
  analogWrite(11,0);
  analogWrite(10,0);
  analogWrite(9,0);
  analogWrite(8,0);
  analogWrite(7,0);
  analogWrite(6,0);
}

//forward with certain speed, input -255-0, 0-255, minus means backward
void forward_degree(int speed,int degree){
  a=encoder_pos1+(degree*0.97);//input target
  b=encoder_pos2+(degree*1.02);
  c=encoder_pos3+(degree*1.03);
  d=encoder_pos4+(degree*0.94);
  pid_limit(start_pwm);
  current_speed=start_pwm;
  while(encoder_pos1<(a-tolerance) || encoder_pos1>(a+tolerance)//whhile target not yet reached
        ||encoder_pos2<(b-tolerance) || encoder_pos2>(b+tolerance) 
        ||encoder_pos3<(c-tolerance) || encoder_pos3>(c+tolerance)
        ||encoder_pos4<(d-tolerance) || encoder_pos4>(d+tolerance)
        || stationary==0){
    elapsed=millis();

    if(encoder_pos1<(a-tolerance) || encoder_pos1>(a+tolerance)//motor jitter but not working
       ||encoder_pos2<(b-tolerance) || encoder_pos2>(b+tolerance)
       ||encoder_pos3<(c-tolerance) || encoder_pos3>(c+tolerance)
       ||encoder_pos4<(d-tolerance) || encoder_pos4>(d+tolerance))elapsedd=millis();

    if((elapsed-elapsedd)>200)stationary=1;


    //Serial.print("enc  ");
    //Serial.println(current_speed);
    int absol=abs(a-encoder_pos1);
    
    if((speed_time-millis())>speed_time_var)     {
    if(absol<200&& current_speed>40)current_speed--;//decellerate
    else if (current_speed<speed)current_speed++;   //accelerate
    speed_time=millis();
    pid_limit(current_speed);}
    run();

    
  //Serial.println("running");
  delayMicroseconds(delaymic);
  }
  pid_limit(100);
}
  
//side with certain speed, input -255-0, 0-255, minus means left, positive right
void side_degree(int speed,int degree){
  a=encoder_pos1+(degree*0.97);//input target
  b=encoder_pos2+(degree*1.02);
  c=encoder_pos3+(degree*1.03);
  d=encoder_pos4+(degree*0.94);
  pid_limit(start_pwm);
  current_speed=start_pwm;
  while(encoder_pos1<(a-tolerance) || encoder_pos1>(a+tolerance)
        ||encoder_pos2<(b-tolerance) || encoder_pos2>(b+tolerance) 
        ||encoder_pos3<(c-tolerance) || encoder_pos3>(c+tolerance)
        ||encoder_pos4<(d-tolerance) || encoder_pos4>(d+tolerance)
        || stationary==0){
    elapsed=millis();

    if(encoder_pos1<(a-tolerance) || encoder_pos1>(a+tolerance)
       ||encoder_pos2<(b-tolerance) || encoder_pos2>(b+tolerance)
       ||encoder_pos3<(c-tolerance) || encoder_pos3>(c+tolerance)
       ||encoder_pos4<(d-tolerance) || encoder_pos4>(d+tolerance))elapsedd=millis();
    if((elapsed-elapsedd)>200)stationary=1;

    int absol=abs(a-encoder_pos1);
    
    if((speed_time-millis())>speed_time_var)     {
    if(absol<200&& current_speed>40)current_speed--;//decellerate
    else if (current_speed<speed)current_speed++;   //accelerate
    speed_time=millis();
    pid_limit(current_speed);}
    run();

    
  //Serial.println("running");
  delayMicroseconds(delaymic);
  }
  pid_limit(100);
}

void turn_degree(int speed,int degree){
  a=encoder_pos1+(degree*0.97);//input target
  b=encoder_pos2+(degree*1.02);
  c=encoder_pos3+(degree*1.03);
  d=encoder_pos4+(degree*0.94);
  pid_limit(start_pwm);
  current_speed=start_pwm;
  while(encoder_pos1<(a-tolerance) || encoder_pos1>(a+tolerance)
        ||encoder_pos2<(b-tolerance) || encoder_pos2>(b+tolerance) 
        ||encoder_pos3<(c-tolerance) || encoder_pos3>(c+tolerance)
        ||encoder_pos4<(d-tolerance) || encoder_pos4>(d+tolerance)
        || stationary==0){
    elapsed=millis();

    if(encoder_pos1<(a-tolerance) || encoder_pos1>(a+tolerance)
       ||encoder_pos2<(b-tolerance) || encoder_pos2>(b+tolerance)
       ||encoder_pos3<(c-tolerance) || encoder_pos3>(c+tolerance)
       ||encoder_pos4<(d-tolerance) || encoder_pos4>(d+tolerance))elapsedd=millis();
    if((elapsed-elapsedd)>200)stationary=1;


    int absol=abs(a-encoder_pos1);
    
    if((speed_time-millis())>speed_time_var)     {
    if(absol<200&& current_speed>40)current_speed--;//decellerate
    else if (current_speed<speed)current_speed++;   //accelerate
    speed_time=millis();
    pid_limit(current_speed);}
    run();

    
  //Serial.println("running");
  delayMicroseconds(delaymic);
  }
  pid_limit(100);
}

void wait(int del){
  timeee=millis();
  timee=millis();
  while((timee-timeee)<del){
    run();
    timee=millis();
  }
}
void stop(){
  a=encoder_pos1;
  b=encoder_pos2;
  c=encoder_pos3;
  d=encoder_pos4;
  run();
}
void run(){
    pos_pid1.setpoint(a);  
    motor_value1 = pos_pid1.compute(encoder_pos1);
    if (motor_value1<minimum_pwm && motor_value1>10)motor_value1=minimum_pwm;
    if (motor_value1>_minimum_pwm && motor_value1<-10)motor_value1=-1*minimum_pwm;
    //Serial.println(motor_value1);
    if(motor_value1 > 0)m1f(motor_value1);
    else                m1b(-1*motor_value1);

    
    pos_pid2.setpoint(b);
    motor_value2 = pos_pid2.compute(encoder_pos2);
    if (motor_value2<minimum_pwm2 && motor_value2>10)motor_value2=minimum_pwm2;
    if (motor_value2>_minimum_pwm2 && motor_value2<-10)motor_value2=-1*minimum_pwm2;
    if(motor_value2 > 0)m2f(motor_value2);
    else                m2b(-1*motor_value2);
    
    pos_pid3.setpoint(c);
    motor_value3 = pos_pid3.compute(encoder_pos3);
    if (motor_value3<minimum_pwm3 && motor_value3>10)motor_value3=minimum_pwm3;
    if (motor_value3>_minimum_pwm3 && motor_value3<-10)motor_value3=-1*minimum_pwm3;
    if(motor_value3 > 0)m3f(motor_value3);
    else                m3b(-1*motor_value3);

    
    pos_pid4.setpoint(d);
    motor_value4 = pos_pid4.compute(encoder_pos4);
    if (motor_value4<minimum_pwm4 && motor_value4>=10)motor_value4=minimum_pwm4;
    if (motor_value4>_minimum_pwm4 && motor_value4<=-10)motor_value4=-1*minimum_pwm4;
    if(motor_value4 > 0)m4f(motor_value4);
    else                m4b(-1*motor_value4);
    //print_pwm();
    
    }



//forward with certain speed, input -255-0, 0-255, minus means backward
void forward_speed(int speed){
  if(speed>=0){
    m1f(speed);
    m2f(speed);
    m3f(speed);
    m4f(speed);}
  else {
    m1b(-speed);
    m2b(-speed);
    m3b(-speed);
    m4b(-speed);}}

//turn with certain speed, input -255-0, 0-255, minus means left, positive means right
void turn_speed(int speed){
  if(speed>=0){
    m1b(speed);
    m2f(speed);
    m3b(speed);
    m4f(speed);}
  else {
    m1f(-speed);
    m2b(-speed);
    m3f(-speed);
    m4b(-speed);}}

//turn with certain speed, input -255-0, 0-255, minus means left, positive means right
void side_speed(int speed){
  if(speed>=0){
    m1f(speed);
    m2b(speed);
    m3b(speed);
    m4f(speed);}
  else {
    m1b(-speed);
    m2f(-speed);
    m3f(-speed);
    m4b(-speed);}}

//m1 foward
void m1f(int power){
  if(power > 10){
  t1=power*0.2;
  analogWrite(13, power+offset1);
  analogWrite(12, 0);
  }else{
    t1=0;
    _t1=0;
    analogWrite(12, 0);
    analogWrite(13, 0);
  }}

//m1 backward
void m1b(int power){
  if(power > 10){
    _t1=power*0.2;
  analogWrite(12, power+_offset1);
  analogWrite(13, 0);
  }else{
    t1=0;
    _t1=0;    
    analogWrite(12, 0);
    analogWrite(13, 0);
  }}

//m2 foward
void m2f(int power){
  if(power > 10){
  t2=power*0.2;  
  analogWrite(11, power+offset2);
  analogWrite(10, 0);
  }else{
    t2=0;
    _t2=0;
    analogWrite(11, 0);
    analogWrite(10, 0);
  }
}

//m2 backward
void m2b(int power){
  if(power > 10){
    _t2=power*0.2;
  analogWrite(10, power+_offset2);
  analogWrite(11, 0);
  }else{
    t2=0;
    _t2=0;
    analogWrite(11, 0);
    analogWrite(10, 0);
  }
}

//m3 foward
void m3f(int power){
  if(power > 10){
    t3=power*0.2;
  analogWrite(9, power+offset3);
  analogWrite(8, 0);
  }else{
    t3=0;
    _t3=0;
    analogWrite(9, 0);
    analogWrite(8, 0);
  }
}

//m3 backward
void m3b(int power){
  if(power > 10){
    _t3=power*0.2;
  analogWrite(8, power+_offset3);
  analogWrite(9, 0);
  }else{
    t3=0;
    _t3=0;
    analogWrite(9, 0);
    analogWrite(8, 0);
  }
}

//m4 foward
void m4f(int power){
  if(power > 10){
    t4=power*0.2;
  analogWrite(7, power+offset4);
  analogWrite(6, 0);
  }else{
    t4=0;
    _t4=0;
    analogWrite(6, 0);
    analogWrite(7, 0);
  }
}

//m4 backward
void m4b(int power){
  if(power > 10){
    _t4=power*0.2;
  analogWrite(6, power+_offset4);
  analogWrite(7, 0);
  }else{
    t4=0;
    _t4=0;
    analogWrite(6, 0);
    analogWrite(7, 0);
  }
}

void pid_limit(int limit){
  pos_pid1.limit(-1*limit, limit);
  pos_pid2.limit(-1*limit, limit);
  pos_pid3.limit(-1*limit, limit);
  pos_pid4.limit(-1*limit, limit);
}



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
 