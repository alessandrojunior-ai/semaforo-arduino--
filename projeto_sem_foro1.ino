// Definição dos pinos utilizando constantes
const int LED_VERMELHO_CARRO = 13;
const int LED_AMARELO_CARRO  = 12;
const int LED_VERDE_CARRO    = 11;

const int LED_VERMELHO_PEDESTRE = 9;
const int LED_VERDE_PEDESTRE    = 8;

// Tempos em milissegundos
const int TEMPO_VERDE_CARRO   = 5000;
const int TEMPO_AMARELO_CARRO = 2000;
const int TEMPO_TRAVESSIA     = 5000;

void setup() {
  pinMode(LED_VERMELHO_CARRO, OUTPUT);
  pinMode(LED_AMARELO_CARRO, OUTPUT);
  pinMode(LED_VERDE_CARRO, OUTPUT);
  pinMode(LED_VERMELHO_PEDESTRE, OUTPUT);
  pinMode(LED_VERDE_PEDESTRE, OUTPUT);
}

void loop() {
  // Etapa 1: Carros passam, pedestres aguardam
  digitalWrite(LED_VERDE_CARRO, HIGH);
  digitalWrite(LED_AMARELO_CARRO, LOW);
  digitalWrite(LED_VERMELHO_CARRO, LOW);
  digitalWrite(LED_VERMELHO_PEDESTRE, HIGH);
  digitalWrite(LED_VERDE_PEDESTRE, LOW);
  delay(TEMPO_VERDE_CARRO);

  // Etapa 2: Atenção para os carros
  digitalWrite(LED_VERDE_CARRO, LOW);
  digitalWrite(LED_AMARELO_CARRO, HIGH);
  delay(TEMPO_AMARELO_CARRO);

  // Etapa 3: Carros param, pedestres atravessam
  digitalWrite(LED_AMARELO_CARRO, LOW);
  digitalWrite(LED_VERMELHO_CARRO, HIGH);
  digitalWrite(LED_VERMELHO_PEDESTRE, LOW);
  digitalWrite(LED_VERDE_PEDESTRE, HIGH);
  delay(TEMPO_TRAVESSIA);

  // Etapa 4: Sinal verde do pedestre pisca alertando fim da travessia
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_VERDE_PEDESTRE, LOW);
    delay(400);
    digitalWrite(LED_VERDE_PEDESTRE, HIGH);
    delay(400);
}
}
