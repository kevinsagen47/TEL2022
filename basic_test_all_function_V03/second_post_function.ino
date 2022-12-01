void second_post(){
  while(pos2!=81 ){servo2_go(15,81);run();}
  while(pos3!=47 ){servo3_go(15,47);run();}
   follow_right_down_back_A2_A4(220);wait(500);
   side_degree(60,-110);wait(1000);
   cal_back(380);wait(1000);
   forward_degree(120,120);wait(1000);
   cal_back(380);wait(1500);

  forward_degree(120,1400);wait(500);//「前進」到第一個20
  to_the_left(); //撞牆矯正
  cal_right(310);wait(1000);//靠右矯正
  forward_degree(120,600);wait(1000);//前進
  side_degree(110,-600);wait(1000);//左移 
  forward_degree(130,900);wait(500);//「前進」到第一個40
  to_the_left();//撞牆矯正
  cal_right(310);wait(1000);//靠右矯正
  forward_degree(130,750);wait(1000);//前進
  side_degree(120,400);wait(1000);//右移 
  forward_degree(130,660);wait(500);//「前進」到第一個60
  to_the_left();//撞牆矯正
  cal_right(310);wait(1000);//靠右矯正
  }

void to_the_left()//撞牆矯正
{
    side_time(-140,800);
    side_time(-100,500);wait(1000);
}
void cal_compass(int degree){
    Serial.println("hi compass");
    steady_angle=0;
    //while((degree-abs_angle)>2 || (degree-abs_angle)<2){
      //for(int i=0;i<3; i++){

        while((degree-abs_angle)>5 || (degree-abs_angle)<-5){// || steady_angle<5){
          compass.read();
          azimuth=compass.getAzimuth();
          abs_angle=start_angle-azimuth;
          if(abs_angle>180)abs_angle=abs_angle-360;
          else if(abs_angle<-180)abs_angle=abs_angle+360;
          
          Serial.println(degree-abs_angle);
          if((degree-abs_angle)>5)turn_speed(120);
          else if((degree-abs_angle)<-5)turn_speed(-120);

          if((degree-abs_angle)>1 && (degree-abs_angle)<1 )steady_angle++;
          else steady_angle=0;
        }
        reset_encoder();
        wait(1000);
      //}
    wait(500);  
    print_compass();
    // Serial.println(abs_angle);
    //}
    //reset_encoder();
}
void print_compass(){
    compass.read();
    azimuth=compass.getAzimuth();
    abs_angle=start_angle-azimuth;
    if(abs_angle>180)abs_angle=abs_angle-360;
    if(abs_angle<-180)abs_angle=abs_angle+360;
    
    Serial.println(abs_angle);
}

void cal_compass2(int degree){
  compass.read();
  azimuth=compass.getAzimuth();
  abs_angle=start_angle-azimuth;
  if(abs_angle>180)abs_angle=abs_angle-360;
  if(abs_angle<-180)abs_angle=abs_angle+360;

  Serial.println(abs_angle);
  delta_degree=degree-abs_angle;
  while(delta_degree>5 || delta_degree<-5){
    compass.read();
    int azimuth;
    azimuth=compass.getAzimuth();
    abs_angle=start_angle-azimuth;
    if(abs_angle>180)abs_angle=abs_angle-360;
    if(abs_angle<-180)abs_angle=abs_angle+360;
    //Serial.println(abs_angle);
    delta_degree=degree-abs_angle;

    if(delta_degree>5)turn_speed(120);// Serial.println("belok kanan");
    if(delta_degree<-5)turn_speed(-120);//Serial.println("belok kiri");// turn_speed(-120);

  }
  reset_encoder();
  Serial.println("I AM DONE");
  //reset_encoder();
  wait(500);
}