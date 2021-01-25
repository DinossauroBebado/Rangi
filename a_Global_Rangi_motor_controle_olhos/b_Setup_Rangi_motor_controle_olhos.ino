void setup()
{//------------------
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
   display.clearDisplay();
   texto("Dinossauro","Bebado");
   
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
         texto("Controle","Achado");
       }
        
        else if(error == 1){
         Serial.println("No controller found, check wiring, see readme.txt to enable debug.");
         texto("Conecte","Controle");
        }
        else if(error == 2){
         Serial.println("Controller found but not accepting commands. see readme.txt to enable debug.");
         texto("Controle","Bugado");
        }
        else if(error == 3){
         Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
         type = ps2x.readType(); 
        }
         switch(type) {
             case 0:
              Serial.println("Unknown Controller type");
              texto("Controle","Desconhecido");
             break;
             case 1:
              Serial.println("DualShock Controller Found");
              texto("Dualshock","Conectado");
             break;
             case 2:
              Serial.println("GuitarHero Controller Found");
              texto("Erro","01");
              break;
     }

//-------------------------------------------
 
}
