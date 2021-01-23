// Programa: Rangi
// Autor: Dinossauro_Bebado
//------------Sumario------------
//testa_motores( );
//testa_motor(motor);
//frente(motor,motor,velocidade);


 
// carrega a biblioteca do Shield
#include <AFMotor.h>
//carrega a biblioteca do Controle de PS2 
#include <PS2X_lib.h>

// Define o motor e  a posição dos motores 
  AF_DCMotor frente_esquerda(1); 
  AF_DCMotor frente_direita(4);
  AF_DCMotor tras_direita(3); 
  AF_DCMotor tras_esquerda(2); 
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
  // Define a velocidade maxima para os motores 
  frente_esquerda.setSpeed(255); 
  frente_direita.setSpeed(255); 
  tras_esquerda.setSpeed(255); 
  tras_direita.setSpeed(255); 
  //Setup Controle de Ps2 
  Serial.begin(57600);
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
    
    if(ps2x.Button(PSB_START))              
        //Start Rangi 
         Serial.println("Start Rangi");
    if(ps2x.Button(PSB_SELECT))
        // protocolo de teste 
         Serial.println("Protocolo de Testes");
    if(ps2x.Button(PSB_RED))            
         Serial.println("Circulo:Emoção 2");
         
    if(ps2x.Button(PSB_PINK))            
         Serial.println("Quadrado:Emoção 4");     
    
    if(ps2x.Button(PSB_BLUE))            
         Serial.println("XIS :Emoção 3"); 
            
    if(ps2x.Button(PSB_GREEN))
         Serial.println("Triangulo:Emoção 1");
        
    if( ps2x.Button(PSB_R2)) // Acelera
    {   velocidade_y = ps2x.Analog(PSS_LY);
        frente(tras_direita,tras_esquerda,velocidade_y);
        frente(frente_direita,frente_esquerda,velocidade_y);
        Serial.print("Stick Values:");
        Serial.print(ps2x.Analog(PSS_LY)); //Left stick, Y axis. Other options: LX, RY, RX  
        Serial.print(",");
        Serial.println(ps2x.Analog(PSS_LX));   
    } else {
        tras_direita.run(RELEASE); 
        tras_esquerda.run(RELEASE);
        frente_direita.run(RELEASE); 
        frente_esquerda.run(RELEASE);
    }
 
 }
 delay(50);    
  
  }
void frente(AF_DCMotor motor1,AF_DCMotor motor2,int velocidade)
  {
  //todos os motores frente_ Isso podia estar melhor mais foda-se
          Serial.println("------------------");
          Serial.print("Velocidade:");
          Serial.println(velocidade);// quando vc acelera no controle vai pra 0 e quando vc da re vai para 255
          //Então a funçaõ map inverte isso para quando acelerar ir para 127, velocidade max do motor, e quando da re ir para -128
          velocidade = map(velocidade,0, 255,127,-127); 
          Serial.print("Velocidade pos map:");
          Serial.println(velocidade);
          if (velocidade > 12)// se o analogico estiver para frente 
              {
               Serial.println("------------------");
               Serial.print("Velocidade frente:");
               Serial.println(velocidade*2); 
               motor1.setSpeed(velocidade*2); //multiplica por dois para alcançar a velo max do motor 2*127 = 254
               motor2.setSpeed(velocidade*2); 
               motor1.run(FORWARD);
               motor2.run(FORWARD);
              }
           else if (velocidade < -12)//analogico para tras 
              { 
                Serial.println("------------------");
                Serial.print("Velocidade tras:");
                Serial.println(velocidade*(-2));
                delay(100);//para a inercia do motor nao danificar o arduino 
                motor1.setSpeed(velocidade*(-2)); //multiplica por menos dois para alcançar a velo max do motor -2*-127 = 254
                motor2.setSpeed(velocidade*(-2)); 
                motor1.run(BACKWARD);
                motor2.run(BACKWARD);
              }
           else // analogico parado 
              {
               motor1.run(RELEASE);
               motor2.run(RELEASE);
              }
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
