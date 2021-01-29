void loop (){ 
// o codigo principal 
 /* You must Read Gamepad to get new values
   Read GamePad and set vibration values
   ps2x.read_gamepad(small motor on/off, larger motor strenght from 0-255)
   if you don't enable the rumble, use ps2x.read_gamepad(); with no values
   
   you should call this at least once a second
   */
 display.clearDisplay(); 
 if(error == 1){ //skip loop if no controller found
  texto("Erro","00");
  return; }
  
 if(type == 2){ //Guitar Hero Controller
   Serial.println("Error 1 ");
   texto("Erro","01");
 }

 else { //DualShock Controller
  
    ps2x.read_gamepad(false,vibrate);          //read controller and set large motor to spin at 'vibrate' speed,was (false,vibrate) nao entendi oq faz exatamente
    
    if(ps2x.Button(PSB_START))              
        //Start Rangi 
         Serial.println("Start Rangi");
    if(ps2x.Button(PSB_SELECT))
        // protocolo de teste 
         Serial.println("Protocolo de Testes");
    if(ps2x.Button(PSB_RED)) {           
         Serial.println("Circulo:Emoção 2");
         emocao('.',60,0,5);
    }
    if(ps2x.Button(PSB_PINK)){            
         Serial.println("Quadrado:Emoção 4");
         emocao('^',40,7,6);
    }
    if(ps2x.Button(PSB_BLUE))  {          
         Serial.println("XIS :Emoção 3"); 
         emocao('*',40,0,4);
    }       
    if(ps2x.Button(PSB_GREEN)){
         Serial.println("Triangulo:Emoção 1");
          emocao('#',40,0,4);
    }    
    if( ps2x.Button(PSB_R2)) //Controle dos motores 
    {   //Mapeia o analogico de 0-255 para um plano cartesiano em que um o analogico parado fica no 0,0 
        motor_y = map(ps2x.Analog(PSS_LY),0, 255,127,-127); 
        motor_x = map(ps2x.Analog(PSS_LX),0, 255,-127,127); 
        
        Serial.print("Analogico Esquerdo: ");
        Serial.print(motor_x); 
        Serial.print(",");
        Serial.println(motor_y); 

        //-----Decide para que lado o motor vai, a variavel tolerancia é oq decide quanto demora pra 
        //realmente aceitar o comando, evita falsos inputs 
        if(motor_y == 0){
            if(motor_x > tolerancia){
              direita();
            }
            else if (motor_x < -tolerancia){
              esquerda();
            }
        }
        if(motor_x == 0){
            if (motor_y > tolerancia){
              frente();
            }
            else if (motor_y <-tolerancia){
              tras(); 
            }
        }
        
    } else {
      //quando o R2 nao é apertado o Rangi para 
       tras_direita.run(RELEASE); 
       tras_esquerda.run(RELEASE);
       frente_direita.run(RELEASE); 
       frente_esquerda.run(RELEASE);
    }        
    if(ps2x.Button(PSB_L2)){
      olho_x =  map(ps2x.Analog(PSS_RX),0, 255,(raio_olho),(display.width()- raio_olho));
      olho_y = map(ps2x.Analog(PSS_RY),0,255,(raio_olho),(display.height()- raio_olho));
      display.clearDisplay();
      olho(olho_x,olho_y);
    }else{
      olho(display.width()/2,display.height()/2); 
      }
   
 }
 delay(50);    
  }
