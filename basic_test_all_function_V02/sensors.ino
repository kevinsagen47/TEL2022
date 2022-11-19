//callibrate position with front IR




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
}


void cal_right(int distance){
  front_right_ir=analogRead(A2); 
  rear_right_ir =analogRead(A4);
  while (front_right_ir>distance || front_right_ir<distance-dist_tol 
          || rear_right_ir>distance || rear_right_ir<distance-dist_tol){
    
    front_right_ir=analogRead(A2);
    rear_right_ir =analogRead(A4);

    if(front_right_ir<distance-dist_tol && rear_right_ir<distance-dist_tol)side_speed(cal_speed);
      //if(prev_dir==0)forward_speed(cal_speed);
      //else wait(100);prev_dir=0;}
    else if(front_right_ir>distance && rear_right_ir>distance)side_speed(-cal_speed);
      //if(prev_dir==1)forward_speed(-cal_speed);
      //else wait(100);prev_dir=1;}
    else if(front_right_ir>distance || rear_right_ir<distance-dist_tol)turn_speed(-cal_speed);
        //if(prev_dir==2)turn_speed(cal_speed);
        //else wait(100);prev_dir=2;}
    else if(rear_right_ir>distance || front_right_ir<distance-dist_tol)turn_speed(cal_speed);
        //if(prev_dir==3)turn_speed(-cal_speed);
        //else wait(100);prev_dir=3;}
    delayMicroseconds(delaymic);
    /*
    Serial.print(rear_right_ir);
  Serial.print("  ");
  Serial.println(front_right_ir);
  */
  }
}

void cal_left(int distance){
  front_left_ir=analogRead(A3); 
  rear_left_ir =analogRead(A5);
  while (front_left_ir>distance || front_left_ir<distance-dist_tol 
          || rear_left_ir>distance || rear_left_ir<distance-dist_tol){
    
    front_left_ir=analogRead(A3);
    rear_left_ir =analogRead(A5);

    if(front_left_ir<distance-dist_tol && rear_left_ir<distance-dist_tol)side_speed(-cal_speed);
      //if(prev_dir==0)forward_speed(cal_speed);
      //else wait(100);prev_dir=0;}
    else if(front_left_ir>distance && rear_left_ir>distance)side_speed(cal_speed);
      //if(prev_dir==1)forward_speed(-cal_speed);
      //else wait(100);prev_dir=1;}
    else if(front_left_ir>distance || rear_left_ir<distance-dist_tol)turn_speed(cal_speed);
        //if(prev_dir==2)turn_speed(cal_speed);
        //else wait(100);prev_dir=2;}
    else if(rear_left_ir>distance || front_left_ir<distance-dist_tol)turn_speed(-cal_speed);
        //if(prev_dir==3)turn_speed(-cal_speed);
        //else wait(100);prev_dir=3;}
    delayMicroseconds(delaymic);
    /*
    Serial.print(rear_left_ir);
  Serial.print("  ");
  Serial.println(front_left_ir);
  */
  }
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
        if(channel < channelAmount) Serial.print('\t');
    }
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
