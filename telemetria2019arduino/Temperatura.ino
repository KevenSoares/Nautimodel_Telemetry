void temperatura()
{
  char outtemp[3];
  int vdo = analogRead(A1);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  int inttemp = vdo * (100.0 / 1023);
  // print out the value you read:
  sprintf(outtemp,"%03d",inttemp);
  dado[0] = outtemp[0];
  dado[1] = outtemp[1];
  dado[2] = outtemp[2];
}
