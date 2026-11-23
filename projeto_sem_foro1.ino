// Semáforo — versão 1
 // Semáforo para carros e pedestres

const int VERMELHO = 12;
const int AMARELO = 11;
const int VERDE = 10;
const int PED_VERMELHO = 8;
const int PED_VERDE = 9;

void setup() {
  pinMode(VERMELHO, OUTPUT);
  pinMode(AMARELO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(PED_VERMELHO, OUTPUT);
  pinMode(PED_VERDE, OUTPUT);

  // Estado inicial
  digitalWrite(PED_VERMELHO, HIGH);
  digitalWrite(PED_VERDE, LOW);
}

void loop() {

  // Carros no verde
  digitalWrite(VERDE, HIGH);
  digitalWrite(PED_VERMELHO, HIGH);
  delay(4000);

  digitalWrite(VERDE, LOW);

  // Carros no amarelo
  digitalWrite(AMARELO, HIGH);
  delay(2000);
  digitalWrite(AMARELO, LOW);

  // Carros no vermelho
  digitalWrite(VERMELHO, HIGH);

  // Pedestres podem atravessar
  digitalWrite(PED_VERMELHO, LOW);
  digitalWrite(PED_VERDE, HIGH);
  delay(4000);

  // Pedestres devem parar
  digitalWrite(PED_VERDE, LOW);
  digitalWrite(PED_VERMELHO, HIGH);
  delay(1000);

  // Libera os carros
  digitalWrite(VERMELHO, LOW);
}
