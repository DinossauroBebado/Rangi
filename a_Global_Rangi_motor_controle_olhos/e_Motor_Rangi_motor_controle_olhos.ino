void direita(){
  frente_esquerda.run(FORWARD); ; 
  frente_direita.run(BACKWARD);
  tras_direita.run(BACKWARD); 
  tras_esquerda.run(FORWARD); 
  display.fillCircle(0, display.height()/2, raio_olho, WHITE);
  display.display();
}
void esquerda(){
  frente_esquerda.run(BACKWARD);
  frente_direita.run(FORWARD);
  tras_direita.run(FORWARD); 
  tras_esquerda.run(BACKWARD); 
 display.fillCircle(128, display.height()/2, raio_olho, WHITE);
  display.display();
}
void tras(){
  frente_esquerda.run(BACKWARD); 
  frente_direita.run(BACKWARD);
  tras_direita.run(BACKWARD); 
  tras_esquerda.run(BACKWARD); 
  
  }
void frente(){
    frente_esquerda.run(FORWARD); 
    frente_direita.run(FORWARD);
    tras_direita.run(FORWARD); 
    tras_esquerda.run(FORWARD); 
  
}
