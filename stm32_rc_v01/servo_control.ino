void servo_control(){
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
    }
}