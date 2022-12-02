void third_post(){
  to_the_left();//撞牆矯正
  cal_right(310);wait(1000);//靠右矯正

  forward_degree(170,1100);
  forward_time(210,4800);wait(1000);//衝上斜坡
  //while(pos2!=115 || pos3!=59){servo2_go(15,115);run();servo3_go(15,59);run();}
  turn_degree(140,-180);wait(1000);
  cal_back_cliff(210);wait(500);
  cal_right_slope(180);wait(500);
  cal_back_cliff(180);wait(500);
  side_degree(100,520);wait(1000);
  diagonal_left_time(150,1600);wait(1000);
  follow_left_down_slope_A2_A4(180);wait(1000);

  //follow_right_down_back_last_slope_A2_A4(300);//not used
 // side_degree(150,-200);wait(1000);
    
  while (analogRead(A6)>180 && analogRead(A7)>180)
  {m1b(170);m4b(170); m2b(70);m3b(70);}reset_encoder();wait(1000);
  side_degree(150,550);}