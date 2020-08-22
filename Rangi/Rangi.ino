// Programa: Rangi
// Autor: Dinossauro_Bebado
 
// carrega a biblioteca do Shield
#include <AFMotor.h>

// Define o motor e  a posição dos motores 
  AF_DCMotor frente_esquerda(1); 
  AF_DCMotor frente_direita(4);
  AF_DCMotor tras_direita(3); 
  AF_DCMotor tras_esquerda(2); 
 
 
void setup()
{
  // Define a velocidade maxima para os motores 
  frente_esquerda.setSpeed(255); 
  frente_direita.setSpeed(255); 
  tras_esquerda.setSpeed(255); 
  tras_direita.setSpeed(255); 

}
void loop (){ 
//aonde roda o codigo principal 
testa_motores();
  }
void testa_motores()
{//testa todos os motores 
         testa_motor(frente_direita);
         delay(1000);
         testa_motor(tras_direita);
         delay(1000);
         testa_motor(tras_esquerda);
         delay(1000);
         testa_motor(frente_esquerda);
         delay(1000);
}
void testa_motor(AF_DCMotor motor)
{//função que testa o motor 
        motor.run(FORWARD); 
        delay(2000);
        motor.run(BACKWARD); 
        delay(2000);
        motor.run(RELEASE); 
  }
