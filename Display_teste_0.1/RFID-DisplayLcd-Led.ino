// ARDUINO MEGA: RST: 5 MISO: 50 MOSI: 51 SCK: 52 SDA: 53

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
 
#define SS_PIN 53
#define RST_PIN 5
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
LiquidCrystal lcd(2, 3, 4, 8, 6, 7); 
 
char st[20];
 
void setup() 
{
  Serial.begin(9600);   // Inicia a serial
  SPI.begin();      // Inicia  SPI bus
  mfrc522.PCD_Init();   // Inicia MFRC522
  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();
  pinMode(47, OUTPUT);
  //Define o número de colunas e linhas do LCD:  
  lcd.begin(16, 2);  
}
 
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Mostra UID na serial
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  conteudo.toUpperCase();
  if (conteudo.substring(1) == "96 F0 A4 AC") //UID 1 - Chaveiro
  {
    Serial.println("Ola Carlos !");
    Serial.println();
    Serial.println("Led aceso");
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ola Carlos !");
    lcd.setCursor(0,1);
    lcd.print("Acesso liberado!");
    digitalWrite(47, HIGH);
    delay(3000);
    digitalWrite(47, LOW);
  }
 
  if (conteudo.substring(1) == "10 D1 1F A4") //UID 2 - Cartao
  {
    Serial.println("Ola Carlos!");
    Serial.println();
    Serial.println("Led apagado");
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ola Cartao !");
    lcd.setCursor(0,1);
    lcd.print("Acesso Negado !");
    digitalWrite(47, LOW);
    delay(3000);
  }
} 
