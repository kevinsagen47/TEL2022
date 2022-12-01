void one_press(){
   /*forward_degree(120,500);wait(500);
   while (analogRead(A3)>210||analogRead(A5)>210){side_speed(-120);reset_encoder();}
   follow_left_down_A0_A1(205);wait(500);
   //cal_front(430);wait(1000);
   //while (analogRead(A1)>310){side_speed(105);reset_encoder();}
   side_degree(120,670);wait(1000);//660
   forward_degree(130,560);wait(600);
   turn_degree(135,-143);wait(800);
   cal_front(430);wait(1000);
   forward_degree(120,-215);wait(1500);//退一個固定的度數「拍照」
   turn_degree(160,170);wait(800);
   follow_right_down_A2_A4(220);wait(1200);
   side_degree(120,-700);wait(1500);
   follow_left_time(200,5000);
   //forward_degree(120,1200);wait(1000);
   side_degree(120,770);wait(500);
   //while (analogRead(A2)>220||analogRead(A4)>220)side_speed(110);reset_encoder();
   //cal_back(350);wait(1000);*/
   follow_right_down_back_A2_A4(220);wait(500);
   side_degree(60,-100);wait(1000);
   cal_back(370);wait(1000);

  forward_degree(120,1200);wait(500);//出發前進第二關20
  
  cal_right(310);wait(1000);//靠右矯正-到第一個點
  while (analogRead(A2)>220)forward_speed(105);reset_encoder();
  forward_degree(120,600);wait(1000);//出發前進第二關40
  side_degree(110,-550);wait(1000);//左移 
  forward_degree(130,780);wait(500);//前進
  cal_right(310);wait(1000);//靠右矯正-到第二個點
  while (analogRead(A2)>220)forward_speed(105);reset_encoder();
  forward_degree(130,670);wait(1000);//出發前進第二關60
  side_degree(120,385);wait(1000);//右移
  forward_degree(130,630);wait(500);//前進到第二關60
  cal_right(310);wait(1000);//靠右矯正-到第三個點
  while (analogRead(A2)>220)forward_speed(105);reset_encoder();

  forward_degree(170,1100);
  forward_degree(210,20000);forward_degree(210,20000);forward_degree(210,20000);forward_degree(210,1000);wait(500);//4200只能爬上去第一階
  side_degree(120,-800);wait(500);
  
   
  Serial.println(press_count);}