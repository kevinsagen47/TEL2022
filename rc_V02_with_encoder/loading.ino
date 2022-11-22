void loading_function(){
if(loading==2){
  if(pos1>home1){
    if((addtime-time1)>sdelayt){
    pos1=pos1-1;
    time1=millis();}}
   if(pos1<home1){
    if((addtime-time1)>sdelayt){
    pos1=pos1+1;
    time1=millis();}}

    if(pos2>home2){
    if((addtime-time2)>sdelayt){
    pos2=pos2-1;
    time2=millis();}}
   if(pos2<home2){
    if((addtime-time2)>sdelayt){
    pos2=pos2+1;
    time2=millis();}}

    if(pos3>home3){
    if((addtime-time3)>sdelayt){
    pos3=pos3-1;
    time3=millis();}}

    if(pos3<home3){
    if((addtime-time3)>sdelayt){
    pos3=pos3++;
    time3=millis();}}



  if(pos1<=home1 && pos1>=home1 &&
     pos2<=home2 && pos2>=home2 &&
     pos3<=home3 && pos3>=home3){
      pos4=home4_;
     loading=3;}
}
if(loading==3&&(addtime-time3)>1000)loading=1;
 if(loading==1){
   //Serial.println("stuck here");
   //Serial.println("AHHHHHHHHHHHHHHH");
   if(pos2<home2_){
    if((addtime-time2)>sdelayt){
    pos2++;
    time2=millis();}
  }
    if(pos3<home3_){
    if((addtime-time3)>delayt){
    pos3=pos3+1;
    time3=millis();}
  }

  if(pos2>=home2_&&pos3>=home3_)loading=0;
  
 }}