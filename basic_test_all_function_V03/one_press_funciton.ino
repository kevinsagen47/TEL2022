void one_press(){
   forward_degree(120,500);wait(500);
    side_degree(120,-700);wait(500);
   //while (analogRead(A3)>210||analogRead(A5)>210){side_speed(-120);reset_encoder();}
   follow_left_down_A0_A1(200);wait(500);
   //while (analogRead(A1)>310){side_speed(105);reset_encoder();}
   side_degree(120,680);wait(1000);//660
   forward_degree(130,560);wait(600);
   turn_degree(340,-145);wait(800);
   cal_front(430);wait(1000);
   forward_degree(120,-215);wait(1500);//退一個固定的度數「拍照」
   turn_degree(360,170);wait(800);
   follow_right_down_A2_A4(220);wait(1200);
   side_degree(120,-720);wait(1000);
   follow_left_time(200,5000);wait(500);
   //forward_degree(120,1200);wait(1000);
   side_degree(120,770);wait(500);
   follow_right_down_back_A2_A4(220);wait(500);
   side_degree(60,-110);wait(1000);
   cal_back(380);wait(1000);
   forward_degree(120,120);wait(1000);
   cal_back(380);wait(1500);

  forward_degree(120,1400);wait(500);//出發前進20
  to_the_left(); 
  cal_right(310);wait(1000);//靠右矯正-到第一個點
  //while (analogRead(A2)>220)forward_speed(105);reset_encoder();
  forward_degree(120,600);wait(1000);//出發前進40
  side_degree(110,-620);wait(1000);//左移 
  forward_degree(130,820);wait(500);//前進750太少
  to_the_left();
  cal_right(310);wait(1000);//靠右矯正-到第二個點
  //while (analogRead(A2)>220)forward_speed(105);reset_encoder();
  forward_degree(130,750);wait(1000);//出發前進60
  side_degree(120,390);wait(1000);//右移
  forward_degree(130,690);wait(500);//前進到第二關60
  to_the_left();
  cal_right(310);wait(1000);//靠右矯正-到第三個點
  //while (analogRead(A2)>220)forward_speed(105);reset_encoder();

  forward_degree(170,1100);
  forward_time(195,5100);wait(1000);//4800太少
  //forward_degree(210,3000);forward_degree(210,3000);forward_degree(210,3000);wait(500);//4200只能爬上去第一階
  while(pos2!=115 || pos3!=59){servo2_go(15,115);run();servo3_go(15,59);run();}
  side_degree(120,-600);wait(500);
  cal_front(450);wait(1000);
  side_degree(120,600);wait(500);

 
  
   
  Serial.println(press_count);}