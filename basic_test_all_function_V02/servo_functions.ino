void take_1_cube() 
{
  while(pos3!=60){
  run();
  servo3_go(min_speed,60);}
  //wait(1000);
  while(pos3!=30){
  run();
  servo3_go(min_speed,30);}
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
