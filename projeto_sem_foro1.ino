# Semáforo Inteligente com Arduino

Projeto desenvolvido para simular o controle de tráfego de veículos e a travessia segura de pedestres utilizando Arduino Uno, LEDs e resistores de proteção (220 Ω).

## Circuito no Tinkercad

* **Link da simulação:** [Cole aqui o link público do seu projeto no Tinkercad]

![Captura do circuito no Tinkercad](COLE_AQUI_O_LINK_GERADO_AO_ARRASTAR_A_IMAGEM)

---

## Uso na escola

* **Ano/Série:** 8º ano do Ensino Fundamental (Anos Finais)
* **Componentes Curriculares:** Ciências, Matemática e Educação Digital / Pensamento Computacional

### Problema do cotidiano escolar
No horário de entrada e saída das aulas, o fluxo intenso de veículos em frente à escola gera insegurança para os estudantes que precisam atravessar a rua, especialmente quando os motoristas não respeitam o tempo necessário para a travessia de grupos maiores ou pessoas com mobilidade reduzida.

### Condução do desafio com os estudantes
A atividade será conduzida em três etapas investigativas ao longo de quatro aulas:
1. **Observação e levantamento de dados:** Em grupos, os estudantes cronometram o tempo real que um colega leva para atravessar a faixa em frente à escola e observam o fluxo de carros, definindo parâmetros reais para o problema.
2. **Prototipagem virtual no Tinkercad:** Os grupos montam o circuito eletrônico (entendendo a função de proteção dos resistores) e programam a lógica sequencial do semáforo de veículos e pedestres, ajustando as variáveis de tempo conforme os dados coletados na rua.
3. **Teste e validação:** Os colegas testam os circuitos uns dos outros simulando situações críticas (como o tempo de alerta antes do sinal fechar) e propõem melhorias, como a inclusão de um botão de solicitação ou alerta sonoro.

### O que os estudantes aprenderão
Na prática, os estudantes desenvolverão habilidades integradas: em **Ciências**, compreenderão o funcionamento de circuitos elétricos simples, polaridade e resistência elétrica; em **Matemática**, trabalharão com grandezas e medidas de tempo (conversão entre segundos e milissegundos) e raciocínio lógico; e em **Computação**, aplicarão conceitos fundamentais de algoritmos, sequenciamento, variáveis/constantes e laços de repetição (`for` e `loop`) para resolver um problema real de cidadania e segurança no trânsito.// Semáforo Carros + Pedestres
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
