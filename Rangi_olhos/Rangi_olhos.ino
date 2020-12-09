//--------------------------------------------------------------------------------------------
//-----Projeto: 31:01                                                                ---------
//-----Titulo:  Rangi ---> Olhos                                                     ---------
//-----Autor:@dinossauro.bebado/@DinossauroBbad1                                     ---------
//-----Objetivo : animar os olhos                                                    ---------
//-----Data :9/12/20                                                                        ---------
//--------------------------------------------------------------------------------------------
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(4);
#define pinVRx A2
#define pinVRy A1
#define pinSW  2
//void emocao(character,olho_x,olho_y,tamanho do caracter )
int raio_olho = 5;
int X_antes = 60 ; 
int Y_antes = 16 ; 

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
int X = map(analogRead(pinVRx),0,1023,(raio_olho),(display.width()- raio_olho));// mapeia o joystick no espaço do Oled e 
int Y = map(analogRead(pinVRy),0,1023,(raio_olho),(display.height()- raio_olho));//substrai o raio para nao sair da tela

if (statusSW) {                           //botao para as emoções 
   Serial.println("  Botao: [Solto] "); 
} else {
   emocao('^',40,7,6);
   delay(1000);
   emocao('*',40,0,4);
   delay(1000);
   emocao('#',40,0,4);
   delay(1000);
   emocao('.',60,0,5);
   delay(1000);
   
}

if (X != X_antes || Y != Y_antes)  //verifica se mudou de posição se nao mudou nao faz nada 
{     Serial.println(".");
      while(X != X_antes && Y != Y_antes) // cria animações mais suaves ao mudar os numeros de posição gradualmente
      {                
            if (max(X,X_antes)==X)
            {
                  if(max(Y,Y_antes)==Y)
                  {     X_antes=X;
                        Y_antes =Y;
                        Y--;
                        X=X-10;
                        olho(X,Y);
                  }     
                   else
                   {  X_antes=X;
                      Y_antes =Y;
                      Y++;
                      X=X-10;
                      olho(X,Y);
                  }
             }
      
            else{
                 if(max(Y,Y_antes)==Y)
                  {   X_antes=X;
                      Y_antes =Y;
                      Y--;
                      X=X+10;
                      olho(X,Y);
                  }
                  else
                  {   X_antes=X;
                      Y_antes =Y;
                      Y++;
                      X=X+10;
                      olho(X,Y);              
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

void emocao(char expressao,int olho_x,int olho_y,int tamanho ){
   //função que cria as emoções recebe o caracter que vai ser usado e a posição no espaço alem do tamanho 
   display.clearDisplay();
   Serial.println(expressao);
   display.setTextColor(WHITE);
   display.setTextSize(tamanho);
   display.setCursor(olho_x,olho_y);
   display.println(expressao);
   display.display();
   delay(200);
   display.clearDisplay();}

void olho(int X,int Y){
      // coloca o circulo no espaço recebendo as cordenadas 
      display.clearDisplay();
      display.fillCircle(X, Y, raio_olho, WHITE);
      display.display();
      Serial.print("Valor VRx: ");
      Serial.print(Y); 
      Serial.print("Valor VRy: ");
      Serial.println(X);  
      display.clearDisplay();
  
  
  }
