#include <LiquidCrystal.h>
#define pinPIR 53
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int aceso = 0;
void setup()
{
  pinMode(pinPIR, INPUT);
  Serial.begin(9600);
  pinMode(52, OUTPUT);
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
}
 
void loop()
{
  bool valorPIR = digitalRead(pinPIR);
  
  if (valorPIR) {
   
    digitalWrite(52, HIGH); 
    if(aceso == 1){
      lcd.clear();
      lcd.print("Aceso");
      Serial.println("Aceso");
    }
    aceso = 0;
    delay(500);
  } else {
    digitalWrite(52, LOW);
    
    if(aceso == 0){
       lcd.clear();
      lcd.print("Apagado");
      Serial.println("Apagado");
    }
    aceso = 1;
    delay(250);
  }
}
