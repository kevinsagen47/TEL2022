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