void take_1_cube() 
{
  while(pos3!=30){
  run();
  servo3_go(min_speed,30);}
  //wait(1000);
  while(pos3!=0){
  run();
  servo3_go(min_speed,0);}
  wait(1000);
void put_3_blocks() 
{
    while(pos3!=60){servo3_go(20,60);run();}
    while(pos6!=155){servo6_go(20,155);run();}
    wait(1000);
    while(pos7!=40){servo7_go(20,40);run();}
    //while(pos7!=55){servo7_go(20,55);run();}
   // wait(1000);
    //while(pos7!=10){servo7_go(8,10);run();}
    wait(1000);
    while(pos6!=58){servo6_go(20,58);run();}
    //wait(500);
    while(pos7!=138){servo7_go(5,138);run();}
}
  //stop();
  /*while(pos1!=60 && pos2!=140){
    servo1_go(min_speed,60);
    servo2_go(min_speed,140);
    stop();}
  Serial.println("done take 1 cube");
  wait(1000);


  while(pos1!=home1 && pos2!=home2){
    servo1_go(min_speed,home1);
    servo2_go(min_speed,home2);
    stop();
    }
  while(pos3!=home3){servo3_go(min_speed,home3);
  stop();}*/ 

  Serial.println("done take 1 cube");
}
void servo_standby(){
  while(pos2!=home2){run();servo2_go(max_speed, home2);}
  while(pos3!=home3){run();servo3_go(max_speed, home3);}
  }