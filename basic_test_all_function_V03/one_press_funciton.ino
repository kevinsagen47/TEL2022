void one_press(){
  
   while(pos2!=81 ){servo2_go(15,81);run();}
   while(pos3!=47 ){servo3_go(15,47);run();}
   forward_degree(120,500);wait(500);
   side_degree(120,-300);
   //while (analogRead(A3)>210||analogRead(A5)>210){side_speed(-120);reset_encoder();}
   follow_left_down_A0_A1(200);wait(500);
   side_degree(120,700);wait(1000);//675原本接影像的平移
   /*forward_degree(130,560);wait(600);
   turn_degree(140,-150);wait(800);
   cal_front(430);wait(1000);
   forward_degree(120,-215);wait(1500);//退一個固定的度數「拍照」
   turn_degree(140,190);wait(800);*/
   
   follow_right_down_A2_A4(220);wait(1200);
   side_degree(120,-720);wait(1000);
   follow_left_time(200,5200);wait(500);//5000
   //forward_degree(120,1200);wait(1000);
   side_degree(120,770);wait(500);
   
  
   second_post();//第二關的模塊

   third_post();//第三關的模塊

  Serial.println(press_count);}