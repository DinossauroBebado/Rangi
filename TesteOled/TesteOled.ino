#include <Adafruit_SSD1306.h>


Adafruit_SSD1306 display(4);
 


#define pinVRx A2
#define pinVRy A1
#define pinSW  2

int raio_olho = 10;


void setup()
{
  pinMode(pinVRx, INPUT);
  pinMode(pinVRy, INPUT);
  pinMode(pinSW,  INPUT_PULLUP);
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  display.fillCircle(60, 15,raio_olho, WHITE);
  display.display();
  display.clearDisplay();
  }

void loop( ) {

bool statusSW = digitalRead(pinSW);
int X = map(analogRead(pinVRx),0,1023,(raio_olho),(display.width()- raio_olho));
int Y = map(analogRead(pinVRy),0,1023,(raio_olho),(display.height()- raio_olho));
int X_antes = 60 ; 
int Y_antes = 16 ; 

if (statusSW) {
   Serial.println("  Botao: [Solto] "); 
} else {
   piscada();
   delay(1000);
   asterisco();
   delay(1000);
   hashtag();
   delay(1000);
   ponto();
   delay(1000);
   
}

if (X != X_antes || Y != Y_antes)
{     Serial.println(".");
      while(X != X_antes && Y != Y_antes)
      {                
            if (max(X,X_antes)==X)
            {
                  if(max(Y,Y_antes)==Y)
                  {     X_antes=X;
                        Y_antes =Y;
                        Y--;
                        X=X-10;
                        display.fillCircle(X, Y, raio_olho, WHITE);
                        display.display();
                        Serial.print("Valor VRx: ");
                        Serial.print(Y); 
                        Serial.print("Valor VRy: ");
                        Serial.println(X);  
                        display.clearDisplay();
                  }     
                   else
                   {  X_antes=X;
                      Y_antes =Y;
                      Y++;
                      X=X-10;
                      display.fillCircle(X, Y, raio_olho, WHITE);
                      display.display();
                      Serial.print("Valor VRx: ");
                      Serial.print(Y); 
                      Serial.print("Valor VRy: ");
                      Serial.println(X);  
                      display.clearDisplay();
                  }
             }
      
            else{
                 if(max(Y,Y_antes)==Y)
                  {   X_antes=X;
                      Y_antes =Y;
                      Y--;
                      X=X+10;
                      display.fillCircle(X, Y, raio_olho, WHITE);
                      display.display();
                      Serial.print("Valor VRx: ");
                      Serial.print(Y); 
                      Serial.print("Valor VRy: ");
                      Serial.println(X);  
                      display.clearDisplay();
                  }
                  else
                  {   X_antes=X;
                      Y_antes =Y;
                      Y++;
                      X=X+10;
                      display.fillCircle(X, Y, raio_olho, WHITE);
                      display.display();
                      Serial.print("Valor VRx: ");
                      Serial.print(Y); 
                      Serial.print("Valor VRy: ");
                      Serial.println(X);  
                      display.clearDisplay();                  
                  }
      }                 X = map(analogRead(pinVRx),0,1023,(raio_olho),(display.width()- raio_olho));
                        Y = map(analogRead(pinVRy),0,1023,(raio_olho),(display.height()- raio_olho));  }
}
else {
    display.fillCircle(X_antes, Y_antes,raio_olho, WHITE);
    display.display();
   
}
// display.drawCircle(centerX, centerY, radius, color).
  }


void piscada( ){
   display.clearDisplay();
   Serial.println("  Botao: [Apertado] ");
   display.setTextColor(WHITE);
   display.setTextSize(6);
   display.setCursor(40,7);
   display.println("^");
   display.display();
   delay(200);
   display.clearDisplay();}

void asterisco( ){
   display.clearDisplay();
   Serial.println("  Botao: [Apertado] ");
   display.setTextColor(WHITE);
   display.setTextSize(4);
   display.setCursor(40,0);
   display.println("*");
   display.display();
   delay(200);
   display.clearDisplay();
}
void hashtag( ){
   display.clearDisplay();
   Serial.println("  Botao: [Apertado] ");
   display.setTextColor(WHITE);
   display.setTextSize(4);
   display.setCursor(40,0);
   display.println("#");
   display.display();
   delay(200);
   display.clearDisplay();
}
void ponto( ){
   display.clearDisplay();
   Serial.println("  Botao: [Apertado] ");
   display.setTextColor(WHITE);
   display.setTextSize(5);
   display.setCursor(60,0);
   display.println(".");
   display.display();
   delay(200);
   display.clearDisplay();
  
  }
