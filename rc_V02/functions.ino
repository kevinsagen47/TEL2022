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

  //Serial.print(forward);
  //Serial.print("  ");
  //Serial.print(backward);
  /*
  Serial.print(f_r);
  Serial.print("  ");
  Serial.print(f_l);
  Serial.print("  ");
  Serial.print(b_r);
  Serial.print("  ");
  Serial.print(b_l);
  Serial.print("  ");
  Serial.println();
  */
  
  
  

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