void setup()
{//------------------
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
   display.clearDisplay();
   logo();
   display.invertDisplay(0);
   delay(1000);
   display.clearDisplay();
   //adicionar animação de loading 
   texto("Rangi","por :",1000);
   texto("Dinossauro","Bebado",1000);
   display.clearDisplay();
   loading();
   texto("Sistema","Iniciado",1000);
   display.clearDisplay();
  // Define a velocidade maxima para os motores 
  frente_esquerda.setSpeed(max_speed); 
  frente_direita.setSpeed(max_speed); 
  tras_esquerda.setSpeed(max_speed); 
  tras_direita.setSpeed(max_speed); 
  //Setup Controle de Ps2 
  Serial.begin(57600);
  //setup pins and settings:  GamePad(clock, command, attention, 
  //data, Pressures?, Rumble?) check for error
 error = ps2x.config_gamepad(13,9,10,2, false, false);  
  //Testa por erros na conexão ps2<--> Adaptador
         if(error == 0){
         Serial.println("Found Controller, configured successful");
         texto("Controle","Achado",500);
       }
        
        else if(error == 1){
         Serial.println("No controller found, check wiring, see readme.txt to enable debug.");
         texto("Conecte","Controle",500);
        }
        else if(error == 2){
         Serial.println("Controller found but not accepting commands. see readme.txt to enable debug.");
         texto("Controle","Bugado",500);
        }
        else if(error == 3){
         Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
        }
      type = ps2x.readType(); 
        
         switch(type) {
             case 0:
              Serial.println("Unknown Controller type");
              texto("Controle","Desconhecido",500);
             break;
             case 1:
              Serial.println("DualShock Controller Found");
              texto("Dualshock","Conectado",500);
             break;
             case 2:
              Serial.println("GuitarHero Controller Found");
              texto("Erro","01",500);
              break;
     }

//-------------------------------------------
              
}
