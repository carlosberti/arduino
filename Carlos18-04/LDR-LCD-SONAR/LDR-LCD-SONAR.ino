#include <Ultrasonic.h>
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/*
 * Pass as a parameter the trigger and echo pin, respectively,
 * or only the signal pin (for sensors 3 pins), like:
 * Ultrasonic ultrasonic(13);
 */
Ultrasonic ultrasonic(53, 52);
int distance;
int pinoLed = 13; 
int pinoSensorLuz = A0;               
int valorLuz = 0; 

void setup() {
  lcd.begin(16, 2);
   pinMode(pinoLed,OUTPUT);  
  Serial.begin(9600);
}

void loop() {
  // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read();
  lcd.clear();
  lcd.setCursor(6,0);
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  lcd.print(distance);
  lcd.println("cm");
  valorLuz = analogRead(pinoSensorLuz);
  
  if(valorLuz>1000)
  {      
    lcd.setCursor(5,1);          
    lcd.print("Ligado");
    digitalWrite(pinoLed,HIGH);
  }
  else
  {           
    lcd.setCursor(4,1);
    lcd.print("Desligado");         
    digitalWrite(pinoLed,LOW);
  }
  
  Serial.println(valorLuz);
  delay(1000);
}
