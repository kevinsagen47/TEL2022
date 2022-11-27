void get_ppm(){
for (byte channel = 1; channel <= channelAmount; ++channel) {
        unsigned value = ppm.latestValidChannelValue(channel, 0);
        //Serial.print(value);
        channel_[channel]=value;
        if(channel < channelAmount) Serial.print('\t');
    }

}
void print_servo(){
  Serial.print(pos1);
  Serial.print("  ");
  Serial.print(pos2);
  Serial.print("  ");
  Serial.print(pos3);
  Serial.print("  ");
  Serial.print(pos4);
  Serial.print("  ");
  Serial.print(pos5);
  Serial.print("  ");
  Serial.print(pos6);
  Serial.println();
}