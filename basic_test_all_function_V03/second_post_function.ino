void second_post(){
forward_degree(120,1100);wait(500);//出發前進第二關20
  cal_left(360);wait(1000);//靠左矯正-到第一個點
  forward_degree(200,800);wait(1000);//出發前進第二關40
  side_degree(120,-530);wait(1000);//左移
  forward_degree(200,800);wait(500);//前進
  cal_right(310);wait(1000);//靠右矯正-到第二個點
  forward_degree(200,700);wait(1000);//出發前進第二關60
  side_degree(120,380);wait(1000);//右移
  forward_degree(180,700);wait(500);//前進到第二關60
  cal_left(310);wait(5000);//靠右矯正-到第三個點
  take_1_cube(); 
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