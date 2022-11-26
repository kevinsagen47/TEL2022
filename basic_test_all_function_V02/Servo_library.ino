
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

void servo6_go(int speed,int degree){
  addtime=millis();
   if(pos6>degree){
    if((addtime-time6)>speed){
    pos6=pos6-1;
    time6=millis();
    servo6.write(pos6);}}
   if(pos6<degree){
    if((addtime-time6)>speed){
    pos6=pos6+1;
    time6=millis();
    servo6.write(pos6);}}
}
void servo7_go(int speed,int degree){
  addtime=millis();
   if(pos7>degree){
    if((addtime-time7)>speed){
    pos7=pos7-1;
    time7=millis();
    servo7.write(pos3);}}
   if(pos7<degree){
    if((addtime-time7)>speed){
    pos7=pos7+1;
    time7=millis();
    servo7.write(pos7);}}
}

void update_servo(){
  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);
  servo6.write(pos6);
  servo6.write(pos7);
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