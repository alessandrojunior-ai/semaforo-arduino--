// Semáforo Carros + Pedestres
const int VERMELHO = 12;
const int AMARELO = 11;
const int VERDE = 10;

const int PED_VERMELHO = 9;
const int PED_VERDE = 8;

void setup() {
  pinMode(VERMELHO, OUTPUT);
  pinMode(AMARELO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(PED_VERMELHO, OUTPUT);
  pinMode(PED_VERDE, OUTPUT);
}

void loop() {
  // 1. Carros: VERDE (4s) | Pedestres: VERMELHO
  digitalWrite(VERDE, HIGH);
  digitalWrite(PED_VERMELHO, HIGH);
  delay(4000);
  digitalWrite(VERDE, LOW);

  // 2. Carros: AMARELO (2s) | Pedestres: VERMELHO
  digitalWrite(AMARELO, HIGH);
  delay(2000);
  digitalWrite(AMARELO, LOW);
  digitalWrite(PED_VERMELHO, LOW); // Apaga o vermelho do pedestre antes de abrir

  // 3. Carros: VERMELHO (5s) | Pedestres: VERDE
  digitalWrite(VERMELHO, HIGH);
  digitalWrite(PED_VERDE, HIGH);
  delay(5000);
  digitalWrite(VERMELHO, LOW);
  digitalWrite(PED_VERDE, LOW); // Apaga o verde do pedestre para reiniciar o ciclo
}