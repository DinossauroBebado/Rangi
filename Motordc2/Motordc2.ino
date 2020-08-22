// Programa: Arduino Motor Shield - Controle motores DC
// Autor: Arduino e Cia
 
// carrega a biblioteca AFMotor
#include <AFMotor.h>

// Define o motor1 ligado a conexao 1
AF_DCMotor frente_esquerda(1); 
AF_DCMotor tras_direita(3); 
AF_DCMotor tras_esquerda(2); 
AF_DCMotor frente_direita(4); 
 
void setup()
{
  // Define a velocidade maxima para os motores 1 e 2
  frente_esquerda.setSpeed(255); 
  frente_direita.setSpeed(255); 
  tras_esquerda.setSpeed(255); 
  tras_direita.setSpeed(255); 

}
void loop (){ 
  testa_motores();}




void testa_motores()
{
 testa_motor(frente_direita);
 delay(1000);
 testa_motor(tras_direita);
 delay(1000);
 testa_motor(tras_esquerda);
 delay(1000);
 testa_motor(frente_esquerda);
 delay(1000);
}
void testa_motor(AF_DCMotor motor){
  motor.run(FORWARD); 
  delay(2000);
  motor.run(BACKWARD); 
  delay(2000);
  motor.run(RELEASE); 
  }
