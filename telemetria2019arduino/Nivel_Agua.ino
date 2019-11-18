void nivelagua()
{
  if(digitalRead(alto) == HIGH && digitalRead(medio) == HIGH && digitalRead(baixo) == HIGH)
    dado[14] = 'a';
  else if(digitalRead(alto) == HIGH && digitalRead(medio) == HIGH && digitalRead(baixo) == LOW)
    dado[14] = 'b';
  else if(digitalRead(alto) == HIGH && digitalRead(medio) == LOW && digitalRead(baixo) == LOW)
    dado[14] = 'c';
  else if(digitalRead(alto) == LOW && digitalRead(medio) == LOW && digitalRead(baixo) == LOW)
    dado[14] = 'd';
  else
    dado[14] = 'e';
  
}
