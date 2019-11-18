void vbat()
{
  char outbat[3];
  int value = analogRead(A2);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  int vbat = value * (50.0/(0.357*1023.0));
  // print out the value you read:
  sprintf(outbat,"%03d",vbat);
  dado[10] = outbat[0];
  dado[11] = outbat[1];
  dado[12] = '.';
  dado[13] = outbat[2]; 
}
