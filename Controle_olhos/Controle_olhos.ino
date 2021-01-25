 //--------------------------------------------------------------------------------------------
//-----Projeto:31:01                                                                      ---------
//-----Titulo:Controle + OLed                                                                     ---------
//-----Autor:@dinossauro.bebado/@DinossauroBbad1                                     ---------
//-----Objetivo :                                                                    ---------
//-----Data : 24/01/21                                                                        ---------
//--------------------------------------------------------------------------------------------

//carrega a biblioteca do Controle de PS2 
#include <PS2X_lib.h>
#include <Arduino.h>
#include <Wire.h>
#include <MicroLCD.h>


LCD_SSD1306 lcd;
//Cria a classe do PS2 
  PS2X ps2x;
//variaveis para o controle de ps2 
  int error = 0;
  byte type = 0;
  byte vibrate = 0;
//outras
  int velocidade_y = 0; //Conversão do analogico esquerdo para a velocidade do motor 
 
void setup()
{
  
  //Setup Controle de Ps2 
  Serial.begin(57600);
  lcd.begin();
  
  delay(30);
  //setup pins and settings:  GamePad(clock, command, attention, 
  //data, Pressures?, Rumble?) check for error
  error = ps2x.config_gamepad(13,9,10,2, false, false);  
  //Testa por erros na conexão ps2<--> Adaptador
         if(error == 0){
         Serial.println("Found Controller, configured successful");
       }
        
        else if(error == 1)
         Serial.println("No controller found, check wiring, see readme.txt to enable debug.");
         
        else if(error == 2)
         Serial.println("Controller found but not accepting commands. see readme.txt to enable debug.");
         
        else if(error == 3)
         Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
         type = ps2x.readType(); 
           switch(type) {
             case 0:
              Serial.println("Unknown Controller type");
             break;
             case 1:
              Serial.println("DualShock Controller Found");
             break;
             case 2:
              Serial.println("GuitarHero Controller Found");
             break;
     }
}
void loop (){ 
//aonde roda o codigo principal 
 /* You must Read Gamepad to get new values
   Read GamePad and set vibration values
   ps2x.read_gamepad(small motor on/off, larger motor strenght from 0-255)
   if you don't enable the rumble, use ps2x.read_gamepad(); with no values
   
   you should call this at least once a second
   */
   
 if(error == 1) //skip loop if no controller found
  return; 
  
 if(type == 2){ //Guitar Hero Controller
   Serial.println("Error 1 ");
 }

 else { //DualShock Controller
  
    ps2x.read_gamepad(false,vibrate);          //read controller and set large motor to spin at 'vibrate' speed,was (false,vibrate) nao entendi oq faz exatamente
    
    if(ps2x.Button(PSB_START)){              
        //Start Rangi 
         Serial.println("Start Rangi");}
    else if(ps2x.Button(PSB_SELECT)){
        // protocolo de teste 
         Serial.println("Protocolo de Testes");}
    else if (ps2x.Button(PSB_RED)) {           
         Serial.println("Circulo:Emoção 2");
         
         lcd.clear();
         lcd.setFontSize(FONT_SIZE_SMALL);
         lcd.println("Ola, Mundo!");
         delay(100);
         lcd.clear();
         }
        
    else if (ps2x.Button(PSB_PINK))     {       
         Serial.println("Quadrado:Emoção 4");
         lcd.clear();
         lcd.setFontSize(FONT_SIZE_MEDIUM);
         lcd.println("Ola, Mundo!");
         delay(100);
         lcd.clear();
         } 
    else if (ps2x.Button(PSB_BLUE))   {         
         Serial.println("XIS :Emoção 3");
         lcd.clear();
         lcd.setCursor(0, 0);
         lcd.setFontSize(FONT_SIZE_SMALL);
         lcd.printLong(12345678);
         lcd.clear();}
         
           
    else if (ps2x.Button(PSB_GREEN)){
         Serial.println("Triangulo:Emoção 1");
         lcd.clear();
         lcd.setCursor(0, 0);
         lcd.setFontSize(FONT_SIZE_MEDIUM);
         lcd.printLong(12345678);
         lcd.clear();}
        
    else if ( ps2x.Button(PSB_R2)) // Acelera
    {   Serial.print("Stick Values:");
        Serial.print(ps2x.Analog(PSS_LY)); //Left stick, Y axis. Other options: LX, RY, RX  
        Serial.print(",");
        Serial.println(ps2x.Analog(PSS_LX));   
    } else {
  
        
    }
 
 }
 delay(50);   

  
  }
