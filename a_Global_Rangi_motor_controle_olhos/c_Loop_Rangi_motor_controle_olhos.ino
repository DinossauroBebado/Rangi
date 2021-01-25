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
    if( ps2x.Button(PSB_R2)) // Acelera
    {   motor_y = map(ps2x.Analog(PSS_LY),0, 255,127,-127); 
        motor_x = map(ps2x.Analog(PSS_LX),0, 255,127,-127); 
        //frente(tras_direita,tras_esquerda,velocidade_y);
        //frente(frente_direita,frente_esquerda,velocidade_y);
        Serial.print("Analogico Esquerdo: ");
        Serial.print(motor_x); 
        Serial.print(",");
        Serial.println(motor_y); 
        //if( motor_x < 
        
    }        else {
       tras_direita.run(RELEASE); 
       tras_esquerda.run(RELEASE);
       frente_direita.run(RELEASE); 
       frente_esquerda.run(RELEASE);
       display.clearDisplay();
    }
 }
 delay(50);    
 display.clearDisplay();
  }
