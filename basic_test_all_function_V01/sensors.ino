void encoder4(){
  if(digitalRead(17) == HIGH)encoder_pos4++;
  else encoder_pos4--;}

void encoder3(){
  if(digitalRead(16) == HIGH)encoder_pos3--;
  else encoder_pos3++;}

void encoder2(){
  if(digitalRead(15) == HIGH)encoder_pos2++;
  else encoder_pos2--;}

void encoder(){
  if(digitalRead(14) == HIGH)encoder_pos1--;
  else encoder_pos1++;}

void getppm(){
  for (byte channel = 1; channel <= channelAmount; ++channel) {
        unsigned value = ppm.latestValidChannelValue(channel, 0);
        //Serial.print(value);
        channel_[channel]=value;
        if(channel < channelAmount) Serial.print('\t');
    }
}

void print_encoder(){

  Serial.print("Enc: ");
  Serial.print(encoder_pos1);
  Serial.print("  ");
  Serial.print(encoder_pos2);
  Serial.print("  ");
  Serial.print(encoder_pos3);
  Serial.print("  ");
  Serial.print(encoder_pos4);
  /*
  Serial.print("  ppm: ");
  Serial.print(channel_[1]);
  Serial.print("  ");
  Serial.print(channel_[2]);
  Serial.print("  ");
  Serial.print(channel_[3]);
  Serial.print("  ");
  Serial.print(channel_[4]);
  Serial.print("  ");
  Serial.print(channel_[5]);
  Serial.print("  ");
  Serial.print(channel_[6]);
  Serial.print("  ");
  Serial.print(channel_[7]);
  */
  Serial.println();
  delay(100);
}  