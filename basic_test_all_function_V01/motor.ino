//forward with certain speed, input -255-0, 0-255, minus means backward
void forward_degree(int speed,int degree){
  a=encoder_pos1+degree;
  b=encoder_pos2+degree;
  c=encoder_pos3+degree;
  d=encoder_pos4+degree;
  pos_pid1.limit(-1*speed, speed);
  pos_pid2.limit(-1*speed, speed);
  pos_pid3.limit(-1*speed, speed);
  pos_pid4.limit(-1*speed, speed);
  while(encoder_pos1<(a-2) || encoder_pos1>(a+2)
        ||encoder_pos2<(b-2) || encoder_pos2>(b+2) 
        ||encoder_pos3<(c-2) || encoder_pos3>(c+2)
        ||encoder_pos4<(d-2) || encoder_pos4>(d+2)
        || stationary==0){
    elapsed=millis();

    if(encoder_pos1<(a-2) || encoder_pos1>(a+2)
       ||encoder_pos2<(b-2) || encoder_pos2>(b+2)
       ||encoder_pos3<(c-2) || encoder_pos3>(c+2)
       ||encoder_pos4<(d-2) || encoder_pos4>(d+2))elapsedd=millis();
    if((elapsed-elapsedd)>200)stationary=1;
    run();

    
  //Serial.println("running");
  delayMicroseconds(delaymic);
  }
}

//side with certain speed, input -255-0, 0-255, minus means left, positive right
void side_degree(int speed,int degree){
  a=encoder_pos1+degree;
  b=encoder_pos2-degree;
  c=encoder_pos3-degree;
  d=encoder_pos4+degree;
  pos_pid1.limit(-1*speed, speed);
  pos_pid2.limit(-1*speed, speed);
  pos_pid3.limit(-1*speed, speed);
  pos_pid4.limit(-1*speed, speed);
  while(encoder_pos1<(a-2) || encoder_pos1>(a+2)
        ||encoder_pos2<(b-2) || encoder_pos2>(b+2) 
        ||encoder_pos3<(c-2) || encoder_pos3>(c+2)
        ||encoder_pos4<(d-2) || encoder_pos4>(d+2)
        || stationary==0){
    elapsed=millis();

    if(encoder_pos1<(a-2) || encoder_pos1>(a+2)
       ||encoder_pos2<(b-2) || encoder_pos2>(b+2)
       ||encoder_pos3<(c-2) || encoder_pos3>(c+2)
       ||encoder_pos4<(d-2) || encoder_pos4>(d+2))elapsedd=millis();
    if((elapsed-elapsedd)>200)stationary=1;
    run();

    
  //Serial.println("running");
  delayMicroseconds(delaymic);
  }
}

void run(){
    pos_pid1.setpoint(a);  
    motor_value1 = pos_pid1.compute(encoder_pos1);
    //if (motor_value1<minimum_pwm and motor_value1>0)motor_value1=minimum_pwm;
    //if (motor_value1>-minimum_pwm and motor_value1<0)motor_value1=-1*minimum_pwm;
    Serial.println(motor_value1);
    if(motor_value1 > 0)m1f(motor_value1);
    else                m1b(-1*motor_value1);

    pos_pid2.setpoint(b);
    motor_value2 = pos_pid2.compute(encoder_pos2);
    if(motor_value2 > 0)m2f(motor_value2);
    else                m2b(-1*motor_value2);
    
    pos_pid3.setpoint(c);
    motor_value3 = pos_pid3.compute(encoder_pos3);
    if(motor_value3 > 0)m3f(motor_value3);
    else                m3b(-1*motor_value3);

    pos_pid4.setpoint(d);
    motor_value4 = pos_pid4.compute(encoder_pos4);
    if(motor_value4 > 0)m4f(motor_value4);
    else                m4b(-1*motor_value4);
    
    
    }


void stop_move(){//stop all motor
  analogWrite(13,0);
  analogWrite(12,0);
  analogWrite(11,0);
  analogWrite(10,0);
  analogWrite(9,0);
  analogWrite(8,0);
  analogWrite(7,0);
  analogWrite(6,0);}

//forward with certain speed, input -255-0, 0-255, minus means backward
void forward_speed(int speed){
  if(speed>=0){
    analogWrite(13,speed);
    analogWrite(11,speed);
    analogWrite(9,speed);
    analogWrite(7,speed);

    analogWrite(12,0);
    analogWrite(10,0);
    analogWrite(8,0);
    analogWrite(6,0);}
  else {
    analogWrite(12,-1*speed);
    analogWrite(10,-1*speed);
    analogWrite(8,-1*speed);
    analogWrite(6,-1*speed);
    
    analogWrite(13,0);
    analogWrite(11,0);
    analogWrite(9,0);
    analogWrite(7,0);}}

//turn with certain speed, input -255-0, 0-255, minus means left, positive means right
void turn_speed(int speed){
  if(speed>=0){
    analogWrite(12,speed);
    analogWrite(10,speed);
    analogWrite(9,speed);
    analogWrite(7,speed);

    analogWrite(13,0);
    analogWrite(11,0);
    analogWrite(8,0);
    analogWrite(6,0);}
  else {
    analogWrite(13,-1*speed);
    analogWrite(11,-1*speed);
    analogWrite(8,-1*speed);
    analogWrite(6,-1*speed);
    
    analogWrite(12,0);
    analogWrite(10,0);
    analogWrite(9,0);
    analogWrite(7,0);}}



//m1 foward
void m1f(int power){
  if(power > 10){
  analogWrite(13, power);
  analogWrite(12, 0);
  }else{
    analogWrite(12, 0);
    analogWrite(13, 0);
  }}

//m1 backward
void m1b(int power){
  if(power > 10){
  analogWrite(12, power);
  analogWrite(13, 0);
  }else{
    analogWrite(12, 0);
    analogWrite(13, 0);
  }}

//m2 foward
void m2f(int power){
  if(power > 10){
  analogWrite(11, power);
  analogWrite(10, 0);
  }else{
    analogWrite(11, 0);
    analogWrite(10, 0);
  }
}

//m2 backward
void m2b(int power){
  if(power > 10){
  analogWrite(10, power);
  analogWrite(11, 0);
  }else{
    analogWrite(11, 0);
    analogWrite(10, 0);
  }
}

//m3 foward
void m3f(int power){
  if(power > 10){
  analogWrite(9, power);
  analogWrite(8, 0);
  }else{
    analogWrite(9, 0);
    analogWrite(8, 0);
  }
}

//m3 backward
void m3b(int power){
  if(power > 10){
  analogWrite(8, power);
  analogWrite(9, 0);
  }else{
    analogWrite(9, 0);
    analogWrite(8, 0);
  }
}

//m4 foward
void m4f(int power){
  if(power > 10){
  analogWrite(7, power);
  analogWrite(6, 0);
  }else{
    analogWrite(6, 0);
    analogWrite(7, 0);
  }
}

//m4 backward
void m4b(int power){
  if(power > 10){
  analogWrite(6, power);
  analogWrite(7, 0);
  }else{
    analogWrite(6, 0);
    analogWrite(7, 0);
  }
}