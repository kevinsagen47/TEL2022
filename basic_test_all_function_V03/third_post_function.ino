void third_post(){
  to_the_left();//撞牆矯正
  side_time(100,200);
  cal_right(280);wait(1000);//靠右矯正

  forward_degree(170,1100);
  //forward_time(210,4200);wait(1000);//衝上斜坡
  timee=millis();
  timeee=millis();
  //while((timee-timeee)<4200){
  while(((timee-timeee)<3500) || analogRead(A1)<430){
    m2f(250);
    m3f(230);
    m1f(190);
    m4f(210);
    timee=millis();
  }
  reset_encoder();
  //wait(500);
  //while(pos2!=115 || pos3!=59){servo2_go(15,115);run();servo3_go(15,59);run();}
  forward_degree(120,-200);wait(500);
  turn_degree(140,-150);wait(1000);
  while(analogRead(A6)>180&&analogRead(A7)>180)forward_speed(-90);
  wait(500);
  cal_back_cliff(210);wait(500);
  cal_right_slope(180);wait(500);
  cal_back_cliff(180);wait(500);
  side_degree(100,550);wait(1000);
  diagonal_left_time(150,1600);wait(1000);
  follow_left_down_slope_A2_A4(180);wait(1000);

  //follow_right_down_back_last_slope_A2_A4(300);//not used
 // side_degree(150,-200);wait(1000);
    
  while (analogRead(A6)>180 && analogRead(A7)>180)
  {m1b(170);m4b(170); m2b(70);m3b(70);}reset_encoder();wait(1000);
  //forward_degree(120,60);wait(1000);
  while(pos1!=160){servo1_go(15,160);run();}
  while(pos1!=91 ){servo1_go(15,91);run();}
  //while(pos2!=home2_30 ){servo2_go(15,home2_30);run();}
  //while(pos3!=50 ){servo3_go(15,50);run();}
  forward_degree(120,700);wait(1000);
  side_degree(150,1000);
  wait(1000);
  }