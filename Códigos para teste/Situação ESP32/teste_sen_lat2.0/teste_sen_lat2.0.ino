////////////// Variaveis do Sensor Frente //////////////
#define SenD ?                                                     // Sendor direito
#define SenE ?                                                     // Sendor esquerdo
#define LED  13                                                    // LED
#define

float VDPadrao ?;                                                  // valor direito padrao para comparar se o sensor esta em boa condicao
float VEpadrao ?;                                                  // valor esquerdo padrao para comparar se o sensor esta em boa condicao

float IDPadrao ?;                                                  // Intervalo de confianca direito para comparar se o sensor esta em boa condicao  (1 >= x > 0)
float IEpadrao ?;                                                  // Intervalo de confianca esquerdo para comparar se o sensor esta em boa condicao (1 >= x > 0)

////////////// setup() do Sensor Frente //////////////
void setup() {
  // put your setup code here, to run once:
  pinMode(SenD, INPUT);
  pinMode(SenE, INPUT);
  pinMode(LED, OUTPUT);
}

////////////// Main e Funçoes auxiliares do Sensor Frente //////////////
int verificaSensoresLaterais() {
  // put your main code here, to run repeatedly:
  float ValorD = 0;
  float valorE = 0;
  int retorno = 1;

  digitalWrite(LED, HIGH);
  delay(1500);                                                // para dar tempo para girar o carro na mao mesmo;
  digitalWrite(LED, LOW);                                     // Lembrar que começa da direita para esquerda;

  for (int i = 0; i < 10; i++) {
    ValorD += digitalRead(SenD);
    delay(20);
  }

  if ( (SenD / 10 <= VDPadrao - (VDPadrao * IDPadrao)) || (SenD / 10 >= VDPadrao + (VDPadrao * IDPadrao))) {
    retorno = -1;
  }

  digitalWrite(LED, HIGH);
  delay(1500);                                                // para dar tempo para girar o carro na mao mesmo;
  digitalWrite(LED, LOW);

  for (int i = 0; i < 10; i++) {
    ValorE += digitalRead(SenE);
    delay(20);
  }

  if ( (SenE / 10 <= VEPadrao - (VEPadrao * IEPadrao)) || (SenE / 10 >= VEPadrao + (VEPadrao * IEPadrao))) {
    if (retorno == -1) retorno = -3;
    else retorno = -2;
  }
  return retorno;
}
