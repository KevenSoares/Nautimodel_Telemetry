int baixo = 5;
int medio = 6;
int alto = 7;
int srotac = 8;
char dado[] = {'0','2','7','2','9','0','0','0','8','2','1','2','.','5','a'};
long freq, tempo, rot;
int pulsos;
boolean pulso;
void setup() 
{
  pulso=HIGH;
  pinMode(2,INPUT);
  Serial.begin(115200);
  pinMode(alto, INPUT_PULLUP);
  pinMode(medio, INPUT_PULLUP);
  pinMode(baixo, INPUT_PULLUP);
  pinMode(13,OUTPUT);

}

void loop() 
{ 
   Serial.flush();
   lux();
   temperatura();
   vbat();
   nivelagua();
   rotac();
   Serial.println(dado);
   Serial.flush();
}

//Serial.flush();
//  
//  Serial.println(dado);
//  delay(1000);
//  Serial.flush();
//  dado[1] = '3';
//  dado[4] = '7';
//  dado[8] = '9';
//  dado[11] = '1';
//  dado[13] = 'b';
//  Serial.println(dado);
//  Serial.flush();
//  delay(1000);
//  dado[1] = '5';
//  dado[4] = '2';
//  dado[8] = '5';
//  dado[11] = '7';
//  dado[13] = 'c';
//  Serial.println(dado);
//  Serial.flush();
