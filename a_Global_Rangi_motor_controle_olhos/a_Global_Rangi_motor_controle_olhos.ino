//--------------------------------------------------------------------------------------------
//-----Projeto: 31:01                                                                          ---------
//-----Titulo: Rangi + motor + controle + olhos                                                                        ---------
//-----Autor:@dinossauro.bebado/@DinossauroBbad1                                     ---------
//-----Objetivo :  adicionar as telas de oled ao robo                                                                   ---------
//-----Data : 23/01/21                                                                       ---------
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
//outras
  int tolerancia = 30;  
  int motor_y ; 
  int motor_x ;
//declara as funções 
/*void texto(const char*,const char*);

void emocao(char ,int ,int ,int  );

void testa_motores();
void testa_motor(AF_DCMotor );*/
