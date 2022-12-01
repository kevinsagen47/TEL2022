
//callibrate position with front IR

void reset_encoder(){
  a=encoder_pos1;
  b=encoder_pos2;
  c=encoder_pos3;
  d=encoder_pos4;
}


void cal_front(int distance){
  right_ir=analogRead(A0);
  left_ir =analogRead(A1);
  while (right_ir>distance || right_ir<distance-dist_tol 
          || left_ir>distance || left_ir<distance-dist_tol){
    
    right_ir=analogRead(A0);
    left_ir =analogRead(A1);

    if(right_ir<distance-dist_tol && left_ir<distance-dist_tol)forward_speed(cal_speed);
      //if(prev_dir==0)forward_speed(cal_speed);
      //else wait(100);prev_dir=0;}
    else if(right_ir>distance && left_ir>distance)forward_speed(-cal_speed);
      //if(prev_dir==1)forward_speed(-cal_speed);
      //else wait(100);prev_dir=1;}
    else if(right_ir>distance || left_ir<distance-dist_tol)turn_speed(cal_speed);
        //if(prev_dir==2)turn_speed(cal_speed);
        //else wait(100);prev_dir=2;}
    else if(left_ir>distance || right_ir<distance-dist_tol)turn_speed(-cal_speed);
        //if(prev_dir==3)turn_speed(-cal_speed);
        //else wait(100);prev_dir=3;}
    delayMicroseconds(delaymic);
    Serial.print(left_ir);
  Serial.print("  ");
  Serial.println(right_ir);
  }
  
  a=encoder_pos1;
  b=encoder_pos2;
  c=encoder_pos3;
  d=encoder_pos4;
  reset_encoder();
}



void cal_right(int distance){
  front_right_ir=analogRead(A2); 
  rear_right_ir =analogRead(A4);
  while (front_right_ir>distance || front_right_ir<distance-dist_tol 
          || rear_right_ir>distance || rear_right_ir<distance-dist_tol){
    
    front_right_ir=analogRead(A2);
    rear_right_ir =analogRead(A4);

    if(front_right_ir<distance-dist_tol && rear_right_ir<distance-dist_tol)side_speed(cal_side_speed);
    else if(front_right_ir>distance && rear_right_ir>distance)side_speed(-cal_side_speed);
    else if(front_right_ir>distance || rear_right_ir<distance-dist_tol)turn_speed(-cal_side_speed);
    else if(rear_right_ir>distance || front_right_ir<distance-dist_tol)turn_speed(cal_side_speed);
    delayMicroseconds(delaymic);
  }
  
  a=encoder_pos1;
  b=encoder_pos2;
  c=encoder_pos3;
  d=encoder_pos4;
  reset_encoder();
}

void cal_right_slope(int distance){
  front_right_ir=analogRead(A2); 
  rear_right_ir =analogRead(A4);
  while (front_right_ir>distance || front_right_ir<distance-dist_tol 
          || rear_right_ir>distance || rear_right_ir<distance-dist_tol){
    
    front_right_ir=analogRead(A2);
    rear_right_ir =analogRead(A4);

    if(front_right_ir<distance-dist_tol && rear_right_ir<distance-dist_tol)side_speed(-100);
    else if(front_right_ir>distance && rear_right_ir>distance)side_speed(100);
    else if(front_right_ir>distance || rear_right_ir<distance-dist_tol)turn_speed(100);
    else if(rear_right_ir>distance || front_right_ir<distance-dist_tol)turn_speed(-100);
    delayMicroseconds(delaymic);
  }
  
  a=encoder_pos1;
  b=encoder_pos2;
  c=encoder_pos3;
  d=encoder_pos4;
  reset_encoder();
}

void cal_left(int distance){
  front_left_ir=analogRead(A3); 
  rear_left_ir =analogRead(A5);
  while (front_left_ir>distance || front_left_ir<distance-dist_tol 
          || rear_left_ir>distance || rear_left_ir<distance-dist_tol){
    
    front_left_ir=analogRead(A3);
    rear_left_ir =analogRead(A5);

    if(front_left_ir<distance-dist_tol && rear_left_ir<distance-dist_tol)side_speed(-cal_side_speed);
    else if(front_left_ir>distance && rear_left_ir>distance)side_speed(cal_side_speed);
    else if(front_left_ir>distance || rear_left_ir<distance-dist_tol)turn_speed(cal_side_speed);
    else if(rear_left_ir>distance || front_left_ir<distance-dist_tol)turn_speed(-cal_side_speed);
    delayMicroseconds(delaymic);
    /*
    Serial.print(rear_left_ir);
  Serial.print("  ");
  Serial.println(front_left_ir);
  */
  }
  
  a=encoder_pos1;
  b=encoder_pos2;
  c=encoder_pos3;
  d=encoder_pos4;
  reset_encoder();
}
void cal_back(int distance){
  back_left_ir=analogRead(A6);
  back_right_ir =analogRead(A7);
  while (back_right_ir>distance || back_right_ir<distance-dist_tol 
          || back_left_ir>distance || back_left_ir<distance-dist_tol){
    
    back_left_ir=analogRead(A6);
    back_right_ir =analogRead(A7);

    if(back_right_ir<distance-dist_tol && back_left_ir<distance-dist_tol)forward_speed(-cal_back_speed);//-cal_speed
    else if(back_right_ir>distance && back_left_ir>distance)forward_speed(cal_back_speed);
    else if(back_right_ir>distance || back_left_ir<distance-dist_tol)turn_speed(-cal_back_speed);
    else if(back_left_ir>distance || back_right_ir<distance-dist_tol)turn_speed(cal_back_speed);
    delayMicroseconds(delaymic);

  }
  
  a=encoder_pos1;
  b=encoder_pos2;
  c=encoder_pos3;
  d=encoder_pos4;
  reset_encoder();
}

void cal_back_cliff(int distance){
  back_left_ir=analogRead(A6);
  back_right_ir =analogRead(A7);
  while (back_right_ir>distance || back_right_ir<distance-5 
          || back_left_ir>distance || back_left_ir<distance-5){
    
    back_left_ir=analogRead(A6);
    back_right_ir =analogRead(A7);

    if(back_right_ir<distance-5 && back_left_ir<distance-5)forward_speed(cal_back_speed);//-cal_speed
    else if(back_right_ir>distance && back_left_ir>distance)forward_speed(-cal_back_speed);
    else if(back_right_ir>distance || back_left_ir<distance-5)turn_speed(cal_back_speed_cliff);
    else if(back_left_ir>distance || back_right_ir<distance-5)turn_speed(-cal_back_speed_cliff);
    delayMicroseconds(delaymic);

  }
  
  a=encoder_pos1;
  b=encoder_pos2;
  c=encoder_pos3;
  d=encoder_pos4;
  reset_encoder();
}

void follow_left_down_A0_A1(int distance){
  front_left_ir=analogRead(A3); 
  rear_left_ir =analogRead(A5);
  right_ir=analogRead(A0);
  left_ir=analogRead(A1);
  while (right_ir<430 && left_ir<430) {
    right_ir=analogRead(A0);
    left_ir=analogRead(A1);
    front_left_ir=analogRead(A3);
    rear_left_ir =analogRead(A5);
    if(front_left_ir<distance && rear_left_ir<distance && front_left_ir>distance+follow_tol && rear_left_ir>distance+follow_tol)forward_speed(cal_speed);
    else if(front_left_ir<distance && rear_left_ir<distance){m1f(follow_speed);m2f(0);m3f(0);m4f(follow_speed);}//diagonal right
    else if(front_left_ir>distance+follow_tol && rear_left_ir>distance+follow_tol){m1f(0);m2f(follow_speed);m3f(follow_speed);m4f(0);}//diagonal left
    else if(front_left_ir>distance+follow_tol || rear_left_ir<distance-dist_tol){m1f(follow_speed);m3f(follow_speed);m2f(0);m4f(0);}//turn left
    else if(rear_left_ir>distance+follow_tol || front_left_ir<distance-dist_tol){m2f(follow_speed);m4f(follow_speed);m1f(0);m3f(0);}//turn right
    /*if(front_left_ir<distance && rear_left_ir<distance && front_left_ir>distance+follow_tol && rear_left_ir>distance+follow_tol)forward_speed(cal_speed);
    else if(front_left_ir<distance && rear_left_ir<distance)side_speed(cal_speed);
    else if(front_left_ir>distance+follow_tol && rear_left_ir>distance+follow_tol)side_speed(-cal_speed);
    else if(front_left_ir>distance+follow_tol || rear_left_ir<distance-dist_tol){m1f(follow_speed);m3f(follow_speed);}
    else if(rear_left_ir>distance+follow_tol || front_left_ir<distance-dist_tol){m2f(follow_speed);m4f(follow_speed);} */
    delayMicroseconds(delaymic);
    
  //Serial.print(left_ir);
  //Serial.print("  ");
  //Serial.println(left_ir);
  
  }
   turn_off_motor();
 reset_encoder();
  
}


void follow_left_down_slope_A2_A4(int distance){
  right_ir=analogRead(A0);
  left_ir=analogRead(A1);
  while (analogRead(A2)<350 &&analogRead(A4)<350) {
    right_ir=analogRead(A0);
    left_ir=analogRead(A1);
    if(right_ir<distance && left_ir<distance && right_ir>distance+20 && left_ir>distance+20)side_speed(cal_speed);
    else if(right_ir<distance && left_ir<distance){m1b(50);m2b(follow_speed);m3b(follow_speed);m4b(50);}//diagonal l
    else if(right_ir>distance+20 && left_ir>distance+20){m1f(follow_speed);m2f(50);m3f(50);m4f(follow_speed);}//diagonal r
    else if( left_ir<distance){m2b(follow_speed);m4b(follow_speed);m1f(50);m3f(50);}//turn left
    else if(right_ir<distance){m1b(follow_speed);m3b(follow_speed);m2f(50);m4f(50);}//turn right
    else {Serial.println("F");}
    delayMicroseconds(delaymic);
    
  Serial.print(right_ir);
  Serial.print("  ");
  Serial.println(left_ir);
  
  }
   turn_off_motor();
 reset_encoder();
  
}



void follow_left_time(int distance, int millisec){
  front_left_ir=analogRead(A3); 
  rear_left_ir =analogRead(A5);
  long int start_time = millis();
  while (millis() - start_time <= millisec) {
    right_ir=analogRead(A0);
    left_ir=analogRead(A1);
    front_left_ir=analogRead(A3);
    rear_left_ir =analogRead(A5);
    if(front_left_ir<distance && rear_left_ir<distance && front_left_ir>distance+follow_tol && rear_left_ir>distance+follow_tol)forward_speed(cal_speed);
    else if(front_left_ir<distance && rear_left_ir<distance){m1f(follow_speed);m2f(0);m3f(0);m4f(follow_speed);}//diagonal right
    else if(front_left_ir>distance+follow_tol && rear_left_ir>distance+follow_tol){m1f(0);m2f(follow_speed);m3f(follow_speed);m4f(0);}//diagonal left
    else if(front_left_ir>distance+follow_tol || rear_left_ir<distance-dist_tol){m1f(follow_speed);m3f(follow_speed);m2f(0);m4f(0);}//turn left
    else if(rear_left_ir>distance+follow_tol || front_left_ir<distance-dist_tol){m2f(follow_speed);m4f(follow_speed);m1f(0);m3f(0);}//turn right
    /*if(front_left_ir<distance && rear_left_ir<distance && front_left_ir>distance+follow_tol && rear_left_ir>distance+follow_tol)forward_speed(cal_speed);
    else if(front_left_ir<distance && rear_left_ir<distance)side_speed(cal_speed);
    else if(front_left_ir>distance+follow_tol && rear_left_ir>distance+follow_tol)side_speed(-cal_speed);
    else if(front_left_ir>distance+follow_tol || rear_left_ir<distance-dist_tol){m1f(follow_speed);m3f(follow_speed);}
    else if(rear_left_ir>distance+follow_tol || front_left_ir<distance-dist_tol){m2f(follow_speed);m4f(follow_speed);} */
    delayMicroseconds(delaymic);
    
  //Serial.print(left_ir);
  //Serial.print("  ");
  //Serial.println(left_ir);
  
  }
   turn_off_motor();
  reset_encoder();
}

void follow_right_down_back_A2_A4(int distance){
  front_right_ir=analogRead(A2); 
  rear_right_ir =analogRead(A4);
  back_left_ir=analogRead(A6);
  back_right_ir =analogRead(A7);
  while (back_left_ir<370 && back_right_ir<370) {
    front_right_ir=analogRead(A2); 
    rear_right_ir =analogRead(A4);
    back_left_ir=analogRead(A6);
    back_right_ir =analogRead(A7);
    if(front_right_ir<distance && rear_right_ir<distance && front_right_ir>distance+follow_tol && rear_right_ir>distance+follow_tol)forward_speed(-cal_speed);
    else if(front_right_ir<distance && rear_right_ir<distance){m1b(follow_speed);m2f(0);m3f(0);m4b(follow_speed);}//diagonal left
    else if(front_right_ir>distance+follow_tol && rear_right_ir>distance+follow_tol){m1f(0);m2b(follow_speed);m3b(follow_speed);m4f(0);}//diagonal right
    else if(front_right_ir>distance+follow_tol || rear_right_ir<distance-dist_tol){m1b(follow_speed);m3b(follow_speed);m2f(0);m4f(0);}//turn right
    else if(rear_right_ir>distance+follow_tol || front_right_ir<distance-dist_tol){m2b(follow_speed);m4b(follow_speed);m1f(0);m3f(0);}//turn left{m2b(follow_speed);m4b(follow_speed);m1f(0);m3f(0);}
    delayMicroseconds(delaymic);
    
  //Serial.print(left_ir);
  //Serial.print("  ");
  //Serial.println(left_ir);
  
  }
   turn_off_motor();
  a=encoder_pos1;
  b=encoder_pos2;
  c=encoder_pos3;
  d=encoder_pos4;
  reset_encoder();
}


void follow_right_down_back_last_slope_A2_A4(int distance){
  front_right_ir=analogRead(A2); 
  rear_right_ir =analogRead(A4);
  back_left_ir=analogRead(A6);
  back_right_ir =analogRead(A7);
  while (back_left_ir>200 && back_right_ir>200) {
    front_right_ir=analogRead(A2); 
    rear_right_ir =analogRead(A4);
    back_left_ir=analogRead(A6);
    back_right_ir =analogRead(A7);
    if(front_right_ir<distance && rear_right_ir<distance && front_right_ir>distance+follow_tol && rear_right_ir>distance+follow_tol)forward_speed(-cal_speed);
    else if(front_right_ir<distance && rear_right_ir<distance){m1f(0);m2b(follow_speed);m3b(follow_speed);m4f(0);}//diagonal right
    else if(front_right_ir>distance+follow_tol && rear_right_ir>distance+follow_tol){m1b(follow_speed);m2f(0);m3f(0);m4b(follow_speed);}//diagonal left
    else if(rear_right_ir>distance+follow_tol || front_right_ir<distance-dist_tol){m1b(follow_speed);m3b(follow_speed);m2f(0);m4f(0);}//turn right{m2b(follow_speed);m4b(follow_speed);m1f(0);m3f(0);}//turn left
    delayMicroseconds(delaymic);
    
  //Serial.print(left_ir);
  //Serial.print("  ");
  //Serial.println(left_ir);
  
  }
   turn_off_motor();
  a=encoder_pos1;
  b=encoder_pos2;
  c=encoder_pos3;
  d=encoder_pos4;
  reset_encoder();
}

void follow_right_down_A2_A4(int distance){
  front_right_ir=analogRead(A2); 
  rear_right_ir =analogRead(A4);
  right_ir=analogRead(A0);
  left_ir=analogRead(A1);
  while (right_ir<460 && left_ir<460) {
    right_ir=analogRead(A0);
    left_ir=analogRead(A1);
    front_right_ir=analogRead(A2);
    rear_right_ir =analogRead(A4);
    if(front_right_ir<distance && rear_right_ir<distance && front_right_ir>distance+follow_tol && rear_right_ir>distance+follow_tol)forward_speed(cal_speed);
    else if(front_right_ir<distance && rear_right_ir<distance){m1f(0);m2f(follow_speed);m3f(follow_speed);m4f(0);}//diagonal left
    else if(front_right_ir>distance+follow_tol && rear_right_ir>distance+follow_tol){m1f(follow_speed);m2f(0);m3f(0);m4f(follow_speed);}//diagonal right
    else if(front_right_ir>distance+follow_tol || rear_right_ir<distance-dist_tol){m2f(follow_speed);m4f(follow_speed);m1f(0);m3f(0);}//turn right
    else if(rear_right_ir>distance+follow_tol || front_right_ir<distance-dist_tol){m1f(follow_speed);m3f(follow_speed);m2f(0);m4f(0);}//turn left
    delayMicroseconds(delaymic);
    
  //Serial.print(left_ir);
  //Serial.print("  ");
  //Serial.println(left_ir);
  
  }
   turn_off_motor();
  a=encoder_pos1;
  b=encoder_pos2;
  c=encoder_pos3;
  d=encoder_pos4;
  reset_encoder();
  
}

void encoder4(){
  if(digitalRead(17) == HIGH)encoder_pos4++;
  else encoder_pos4--;
  }

void encoder3(){
  if(digitalRead(16) == HIGH)encoder_pos3--;
  else encoder_pos3++;}

void encoder2(){
  if(digitalRead(15) == HIGH)encoder_pos2++;
  else encoder_pos2--;}

void encoder(){
  if(digitalRead(14) == HIGH)encoder_pos1--;
  else encoder_pos1++;
  }

void getppm(){
  for (byte channel = 1; channel <= channelAmount; ++channel) {
        unsigned value = ppm.latestValidChannelValue(channel, 0);
        //Serial.print(value);
        channel_[channel]=value;
        if(channel < channelAmount) Serial.print('\t');}
}

void print_pwm(){

  Serial.print(motor_value1);
  Serial.print("  ");
  Serial.print(motor_value2);
  Serial.print("  ");
  Serial.print(motor_value3);
  Serial.print("  ");
  Serial.print(motor_value4);
  Serial.println();
}
void print_encoder(){

  Serial.print("Enc: ");
  Serial.print(encoder_pos1);
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
