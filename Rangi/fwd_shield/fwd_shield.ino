#include <AFMotor.h>
  AF_DCMotor frente_esquerda(1); 
  AF_DCMotor frente_direita(4);
  AF_DCMotor tras_direita(3); 
  AF_DCMotor tras_esquerda(2); 
void setup() {
  // put your setup code here, to run once:
  frente_esquerda.setSpeed(150); 
  frente_direita.setSpeed(150); 
  tras_esquerda.setSpeed(150); 
  tras_direita.setSpeed(150); 

}

void loop() {
  // put your main code here, to run repeatedly:
         testa_motor(frente_direita);
         testa_motor(frente_esquerda);
         testa_motor(tras_direita);
         testa_motor(tras_esquerda);
         
         
}
void testa_motor(AF_DCMotor motor)
{//função que testa o motor 
        motor.run(FORWARD); 
        //delay(2000);
        //motor.run(BACKWARD); 
        //delay(2000);
       // motor.run(RELEASE); 
       delay(100);
  }
