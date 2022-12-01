
void rc_v02(){
  get_ppm();
  //print_channels();
  addtime=millis();
  if(channel_[5]<1300 && channel_[5]>0)
  {motor_control();
  if(channel_[7]>1800&&channel_[7]<2100)  open_door=1;
  else open_door=0;
  first_3rd_pos=false;
  }
  else if (channel_[5]<1600 && channel_[5]>1400){  
    if(channel_[7]>1500)loading=2;
    if(loading==0)servo_control();  
    open_door=0;all_stop();
    first_3rd_pos=false;}    

  else {//all_stop();
        if(first_3rd_pos==false){reset_encoder();first_3rd_pos=true;}
        open_door=0;run();}
  
  if(loading_function>=1)loading_function();
  if(open_door==1 && pos7!=home7_)servo7_go(20, home7_);
  else if(open_door==0 && pos7!=home7)servo7_go(20, home7);
  update_servo();
  if(channel_[6]>1800 && channel_[6]<2100)digitalWrite(A10,1);
  else digitalWrite(A10,0);
  //delayMicroseconds(100);
  
}

void get_ppm(){
for (byte channel = 1; channel <= channelAmount; ++channel) {
        unsigned value = ppm.latestValidChannelValue(channel, 0);
        //Serial.print(value);
        channel_[channel]=value;
        if(channel < channelAmount) Serial.print('\t');
    }

}

void motor_control(){
if(channel_[2]>50){
    if(channel_[2]>1549)forward=map(channel_[2],1550,2000,minimum_pwm,255);
    else if (channel_[2]<1450) forward=-1*map(channel_[2],1450,1000,minimum_pwm,255);
    else forward=0;

    if (channel_[1]>50){
      if(channel_[1]>1549)side=map(channel_[1],1550,2000,minimum_pwm,255);
      else if (channel_[1]<1450)side=-1*map(channel_[1],1450,1000,minimum_pwm,255);
      else side=0;}

    if (channel_[4]>50){
      if(channel_[4]>1549)turn=map(channel_[4],1550,2000,minimum_pwm,255);
      else if (channel_[4]<1450)turn=-1*map(channel_[4],1450,1000,minimum_pwm,255);
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
  if(f_r>=minimum_pwm){
    analogWrite(13,f_r);
    analogWrite(12,0);}
  else if(f_r<=-minimum_pwm){
    analogWrite(12,-1*f_r);
    analogWrite(13,0);}
  else {
    analogWrite(12,0);
    analogWrite(13,0);}
  
    
  if(f_l>=0){
    analogWrite(11,f_l);
    analogWrite(10,0);}
  else if(f_l<=-minimum_pwm){
    analogWrite(10,-1*f_l);
    analogWrite(11,0);}
  else {
    analogWrite(11,0);
    analogWrite(10,0);}
  

  if(b_r>=0){
    analogWrite(9,b_r);
    analogWrite(8,0);}
  else if(b_r<=-minimum_pwm){
    analogWrite(8,-1*b_r);
    analogWrite(9,0);}
  else {
    analogWrite(9,0);
    analogWrite(8,0);}
  

  if(b_l>=0){
    analogWrite(7,b_l);
    analogWrite(6,0);}
  else if(b_l<=-minimum_pwm){
    analogWrite(6,-1*b_l);
    analogWrite(7,0);}
  
  else {
    analogWrite(6,0);
    analogWrite(7,0);}
  }

void all_stop(){
  analogWrite(13,0);
  analogWrite(12,0);
  analogWrite(11,0);
  analogWrite(10,0);
  analogWrite(9,0);
  analogWrite(8,0);
  analogWrite(7,0);
  analogWrite(6,0);  
}

void servo_control(){
//addtime=millis();
    if(channel_[1]>1550){
      delay1=map(channel_[1],1550,2000,minimum_pwm,max_speed);
      if((addtime-time1)> delay1){
        if(pos1>min1)pos1--;
        time1=millis();
      }
    }
    else if(channel_[1]<1450){
      delay1=map(channel_[1],1450,1000,minimum_pwm,max_speed);
      if((addtime-time1)> delay1){
        if(pos1<max1)pos1++;
        time1=millis();
      }
    }

    if(channel_[2]>1550){
      delay2=map(channel_[2],1550,2000,minimum_pwm,max_speed);
      if((addtime-time2)> delay2){
        if(pos2>min2)pos2--;
        time2=millis();
      }
    }
    else if(channel_[2]<1450){
      delay2=map(channel_[2],1450,1000,minimum_pwm,max_speed);
      if((addtime-time2)> delay2){
        if(pos2<max2)pos2++;
        time2=millis();
      }
    }

    if(channel_[3]>1550){
      delay3=map(channel_[3],1550,2000,minimum_pwm,max_speed);
      if((addtime-time3)> delay3){
        
        if(pos3<max3)pos3++;
        time3=millis();
      }
    }
    else if(channel_[3]<1450){
      delay3=map(channel_[3],1450,1000,minimum_pwm,max_speed);
      if((addtime-time3)> delay3){
        if(pos3>min3)pos3--;
        time3=millis();
      }
    }

    if(channel_[4]>1550){
      delay4=map(channel_[4],1550,2000,minimum_pwm,max_speed);
      if((addtime-time4)> delay4){
        if(pos4>min4)pos4--;
        time4=millis();
      }
    }
    else if(channel_[4]<1450){
      delay4=map(channel_[4],1450,1000,minimum_pwm,max_speed);
      if((addtime-time4)> delay4){
        if(pos4<max4)pos4++;
        time4=millis();
      }
    }}

    void loading_function(){
if(loading==2){
  if(pos1>home1){
    if((addtime-time1)>sdelayt){
    pos1=pos1-1;
    time1=millis();}}
   if(pos1<home1){
    if((addtime-time1)>sdelayt){
    pos1=pos1+1;
    time1=millis();}}

    if(pos2>home2){
    if((addtime-time2)>sdelayt){
    pos2=pos2-1;
    time2=millis();}}
   if(pos2<home2){
    if((addtime-time2)>sdelayt){
    pos2=pos2+1;
    time2=millis();}}

    if(pos3>home3){
    if((addtime-time3)>sdelayt){
    pos3=pos3-1;
    time3=millis();}}

    if(pos3<home3){
    if((addtime-time3)>sdelayt){
    pos3=pos3++;
    time3=millis();}}



  if(pos1<=home1 && pos1>=home1 &&
     pos2<=home2 && pos2>=home2 &&
     pos3<=home3 && pos3>=home3){
      pos4=home4_;
     loading=3;}
}
if(loading==3&&(addtime-time3)>1000)loading=1;
 if(loading==1){
   //Serial.println("stuck here");
   //Serial.println("AHHHHHHHHHHHHHHH");
   if(pos2<home2_){
    if((addtime-time2)>sdelayt){
    pos2++;
    time2=millis();}
  }
    if(pos3<home3_){
    if((addtime-time3)>delayt){
    pos3=pos3+1;
    time3=millis();}
  }

  if(pos2>=home2_&&pos3>=home3_)loading=0;
  
 }}