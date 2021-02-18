//----------------------Funções de controle do display ---------------------------------
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

void happy(){
  display.fillCircle(64,16, raio_olho, WHITE);
  display.fillCircle(64,20, raio_olho, BLACK);
  display.display();
  delay(800);}
void sleepy(){
  display.fillCircle(64,16, raio_olho, WHITE);
  display.fillRect(50,-25, 40,40, BLACK);
  display.display();
  delay(800);
}
void texto(const char* palavra_cima, const char* palavra_baixo, int tempo){
   display.clearDisplay();
   display.setTextColor(WHITE);
   display.setTextSize(2);
   display.setCursor(0,0);
   display.println(palavra_cima);
   display.println(palavra_baixo);
   display.display();
   delay(tempo);
   display.clearDisplay();
 }
void olho(int X,int Y){
      // coloca o circulo no espaço recebendo as cordenadas 
      display.clearDisplay();
      display.fillCircle(X, Y, raio_olho, WHITE);
      display.display();
      Serial.print(Y); 
      Serial.print(":");
      Serial.println(X);  
      display.clearDisplay();
  }

void texto_central(const char* palavra_cima, const char* palavra_baixo, int tempo){
   display.clearDisplay();
   display.setTextColor(WHITE);
   display.setTextSize(2);
   display.setCursor(display.width()/2,display.height()/2);
   display.println(palavra_cima);
   display.println(palavra_baixo);        
   display.display();
   delay(tempo);
   display.clearDisplay();
 } 

void logo(){
   display.drawBitmap(10, -8,  DinossauroBebadoLogo, 103, 64, WHITE);
   display.fillRect(0, 0, 10, 64, WHITE);
   display.fillRect(113, 0, 20, 64, WHITE);
   display.invertDisplay(1);
   display.display();
   delay(5000);}

void loading() {
  display.clearDisplay();
  display.setCursor(30,8);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.print("Loading..");
  for (int i = 0; i <= 128; i = i +12) {
  display.drawRect(i, 16, 12, 10, WHITE);
  }
  display.display();
  for (int j = 0; j<= 128;j = j +12) {
  display.fillRect(j, 16, 12, 10, WHITE);
  display.drawRect(j, 16, 12, 10, BLACK);
  delay(500);
  display.display();
  }}
