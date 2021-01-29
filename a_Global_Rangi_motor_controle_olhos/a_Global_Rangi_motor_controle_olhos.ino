//--------------------------------------------------------------------------------------------
//-----Projeto: 31:01                                                                          ---------
//-----Titulo: Rangi + motor + controle + olhos                                                                        ---------
//-----Autor:@dinossauro.bebado/@DinossauroBbad1                                     ---------
//-----Objetivo :  adicionar as telas de oled ao robo                                                                   ---------
/*-----Data : 23/01/21 -
//            24/01/21 - 
              26/01/21 - 
              28/01/21 
*/
//--------------------------------------------------------------------------------------------
// carrega a biblioteca do Shield
#include <AFMotor.h>
//carrega a biblioteca do Controle de PS2 
#include <PS2X_lib.h>
//carrega a biblioteca dos oleds
#include <Adafruit_SSD1306.h>
//inicia o objeto do display 
Adafruit_SSD1306 display(4);
// Define o motor e  a posição dos motores 
  AF_DCMotor frente_esquerda(4); 
  AF_DCMotor frente_direita(1);
  AF_DCMotor tras_direita(2); 
  AF_DCMotor tras_esquerda(3); 
//Cria a classe do PS2 
  PS2X ps2x;
//variaveis para o controle de ps2 
  int error = 0;
  byte type = 0;
  byte vibrate = 0;
//variaveis motor 
  int max_speed = 255 ; 
  int tolerancia = 30;  
  int motor_y ; 
  int motor_x ;
//variaveis olhos 
  int raio_olho = 7 ; 
  int olho_y ;
  int olho_x ; 
  
