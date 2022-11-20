void take_1_cube() 
{
  while(pos3!=180)servo3_go(min_speed,180);

  while(pos1!=60 && pos2!=140){
    servo1_go(min_speed,60);
    servo2_go(min_speed,140);}
  Serial.println("done take 1 cube");
  wait(1000);


  while(pos1!=home1 && pos2!=home2){
    servo1_go(min_speed,home1);
    servo2_go(min_speed,home2);
    }
  while(pos3!=home3)servo3_go(min_speed,home3);

  Serial.println("done take 1 cube");
}

void servo1_go(int speed,int degree){
  addtime=millis();
   if(pos1>degree){
    if((addtime-time1)>speed){
    pos1=pos1-1;
    time1=millis();
    servo1.write(pos1);}}
   if(pos1<degree){
    if((addtime-time1)>speed){
    pos1=pos1+1;
    time1=millis();
    servo1.write(pos1);}}
  
}

void servo2_go(int speed,int degree){
  addtime=millis();
   if(pos2>degree){
    if((addtime-time2)>speed){
    pos2=pos2-1;
    time2=millis();
    servo2.write(pos2);}}
   if(pos2<degree){
    if((addtime-time2)>speed){
    pos2=pos2+1;
    time2=millis();
    servo2.write(pos2);}}
}

void servo3_go(int speed,int degree){
  addtime=millis();
   if(pos3>degree){
    if((addtime-time3)>speed){
    pos3=pos3-1;
    time3=millis();
    servo3.write(pos3);}}
   if(pos3<degree){
    if((addtime-time3)>speed){
    pos3=pos3+1;
    time3=millis();
    servo3.write(pos3);}}
}

void servo4_go(int speed,int degree){
  addtime=millis();
   if(pos4>degree){
    if((addtime-time4)>speed){
    pos4=pos4-1;
    time4=millis();
    servo4.write(pos4);
    servo5.write(180-pos4);}}
   if(pos4<degree){
    if((addtime-time4)>speed){
    pos4=pos4+1;
    time4=millis();
    servo4.write(pos4);
    servo5.write(180-pos4);}}
}

void update_servo(){
  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);
  servo5.write(180-pos4);
  servo6.write(home6);
}

void print_servo(){
  Serial.print(pos1);
  Serial.print("  ");
  Serial.print(pos2);
  Serial.print("  ");
  Serial.print(pos3);
  Serial.print("  ");
  Serial.print(pos4);
  Serial.print("  ");
  Serial.print(pos5);
  Serial.print("  ");
  Serial.print(pos6);
  Serial.println();
}