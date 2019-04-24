
int pinoLed = 13; 
int pinoSensorLuz = A0;               
int valorLuz = 0;                      
 
void setup()
{
     pinMode(pinoLed,OUTPUT);  
     Serial.begin(9600);      
}
 
void loop()
{
  valorLuz = analogRead(pinoSensorLuz);        
  if(valorLuz>1000)
  {                
    digitalWrite(pinoLed,HIGH);
  }
  else
  {                    
    digitalWrite(pinoLed,LOW);
  }
  Serial.println(valorLuz);
 delay(100);
  delay(10);                   
}
