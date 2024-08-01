#define led_vermelho 13
#define led_amarelo 12
#define led_verde 11
#define botao 9
#define barulho 10

void setup() {
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(barulho, OUTPUT);
}

void ligar() {
  for(int i = led_vermelho; i >= led_verde; i--) {
    switch(i){
      case led_vermelho:
        ligar_led_vermelho(1000);
        break;
      case led_amarelo: 
        ligar_led_amarelo(1000);
        break;
      case led_verde:
        ligar_led_verde(1000);
        break;
      default:
        ligar_led_vermelho(7000);
    }
  }
}

void ligar_led_vermelho(int tempo) {
  digitalWrite(led_vermelho, HIGH);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_verde, LOW);
  delay(tempo);
}

void ligar_led_amarelo(int tempo) {
  digitalWrite(led_amarelo, HIGH);
  digitalWrite(led_vermelho, LOW);
  digitalWrite(led_verde, LOW);
  delay(tempo);
}

void ligar_led_verde(int tempo) {
  digitalWrite(led_verde, HIGH);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_vermelho, LOW);
  delay(tempo);
}

void loop() {
  int estadoBotao = digitalRead(botao);
  if (estadoBotao == HIGH) {
    ligar();
  }
}
