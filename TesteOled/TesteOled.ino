#include <Arduino.h>
#include <Wire.h>
#include <MicroLCD.h>

LCD_SSD1306 lcd; /* para módulo contralado pelo CI SSD1306 OLED */


#define pinVRx A2
#define pinVRy A1
#define pinSW  2

void setup()
{
  pinMode(pinVRx, INPUT);
  pinMode(pinVRy, INPUT);
  pinMode(pinSW,  INPUT_PULLUP);
    Serial.begin(9600);
      lcd.begin();
  
  }

void loop( ) {
 int valorVRx = analogRead(pinVRx);
 int valorVRy = analogRead(pinVRy);
 bool statusSW = digitalRead(pinSW);

 Serial.print("Valor VRx: ");
 Serial.print(map(valorVRx,0,1023,0,63)); 
  
 Serial.print("  Valor VRy: ");
 Serial.print(map(valorVRy,0,1023,0,127));  

 if (statusSW) {
     Serial.println("  Botao: [Solto] "); 
 } else {
     Serial.println("  Botao: [Apertado] ");
 }  
int X = map(valorVRx,0,1023,0,63);
int Y = map(valorVRy,0,1023,0,127);
  lcd.clear();
  lcd.setFontSize(FONT_SIZE_MEDIUM);
  lcd.setCursor(X,Y);
  lcd.println("Bartolomeu");
  lcd.println();
  delay(1000);

  
  }
