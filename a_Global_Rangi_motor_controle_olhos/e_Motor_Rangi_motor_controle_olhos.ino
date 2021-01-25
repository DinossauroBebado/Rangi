void direita(){
  frente_esquerda.run(FORWARD); ; 
  frente_direita.run(BACKWARD);
  tras_direita.run(BACKWARD); 
  tras_esquerda.run(FORWARD); 
}
void esquerda(){
  frente_esquerda.run(BACKWARD); ; 
  frente_direita.run(FORWARD);
  tras_direita.run(FORWARD); 
  tras_esquerda.run(BACKWARD); 
}
void tras(){
  frente_esquerda.run(BACKWARD); ; 
  frente_direita.run(BACKWARD);
  tras_direita.run(BACKWARD); 
  tras_esquerda.run(BACKWARD); 
  
  }
void frente(){
    frente_esquerda.run(FORWARD); ; 
    frente_direita.run(FORWARD);
    tras_direita.run(FORWARD); 
    tras_esquerda.run(FORWARD); 
  
}
/*
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
  }*/
