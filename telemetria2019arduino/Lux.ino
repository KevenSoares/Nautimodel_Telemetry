void lux()
{
  char outlux[3];
  int ldr = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  int intlux = ldr * (100.0 / 1023.0);
  // print out the value you read:
  sprintf(outlux,"03%d",intlux);
  //Serial.println(intlux);
  //Serial.println(outlux);
  dado[7] = outlux[0];

  dado[8] = outlux[1];

  dado[9] = outlux[2];

}
