void slope(){
cal_right_slope(180);
    wait(500);
    cal_back_cliff(180);
    wait(500);
    side_degree(100,520);
    wait(1000);
    diagonal_left_time(150,1600);
    
    
    wait(1000);
    follow_left_down_slope_A2_A4(180);
    wait(1000);
    //follow_right_down_back_last_slope_A2_A4(300);//not used
    side_degree(150,-200);
    wait(1000);
    
    while  (analogRead(A6)>200 && analogRead(A7)>200) {
      m1b(170);
      m4b(170);
      m2b(70);
      m3b(70);
    }
    reset_encoder();
    wait(1000);
    side_degree(150,500);}