//----------------------Funções de controle dos olhos---------------------------------
void emocao(char expressao,int olho_x,int olho_y,int tamanho ){
   //função que cria as emoções recebe o caracter que vai ser usado e a posição no espaço alem do tamanho 
   Serial.println(expressao);
   display.clearDisplay();
   display.setTextColor(WHITE);
   display.setTextSize(tamanho);
   display.setCursor(olho_x,olho_y);
   display.println(expressao);
   display.display();
   delay(200);
   display.clearDisplay();
   }
void texto(const char* palavra_cima, const char* palavra_baixo){
   display.clearDisplay();
   display.setTextColor(WHITE);
   display.setTextSize(2);
   display.setCursor(0,0);
   display.println(palavra_cima);
   display.println(palavra_baixo);
   display.display();
   delay(500);
   display.clearDisplay();
 }
