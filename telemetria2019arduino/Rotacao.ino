void rotac()
{
  char outrot[4];
  tempo = millis();
  if(digitalRead(2)==HIGH)
  {
    if(pulso==HIGH)
    {
      pulsos = pulsos + 1;
    }

    pulso=LOW; 

  }
  else{
    pulso=HIGH;
  }
  if(tempo%2000==0){
    freq = pulsos/2;
    rot = freq/60;
    sprintf(outrot,"%04d",rot);
    pulsos=0;  
  }
  dado[3] = outrot[0];
  dado[4] = outrot[1];
  dado[5] = outrot[2];
  dado[6] = outrot[3];
  
}
