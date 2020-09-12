////////////// Variaveis do Sensor Frente //////////////
#define n  6                                                          // Numero de sensores 
#define LED 13                                                        // LED

int Sensores[n] = [ ?, ?, ?, ?, ?, ? ];                               // Sensores

float VSen[n];                                                        // Valor dos sensores
int i = 0;                                                            // Variavel qualquer usada em funçoes for()
int j = 0;                                                            // Variavel qualquer usada em funçoes for()
for ( i = 0; i < n; i++) {
  VSen[i] = 0;
}

int ResultadoSen[n];                                                  // array que sera inserido os resultados: 1 para sensor nao danificado e -1 para sensor danificado

float VPadraoSen[n] = [ ?, ?, ?, ?, ?, ? ];                            // Valor padrao para comparar se so sensores estão em boas condiçôes

float IPadraoSen[n] = [ ?, ?, ?, ?, ?, ? ];                            // Intervalo de confianca para comparar se os sensores estãao em boas condições  (1 >= x > 0)

////////////// setup() do Sensor Frente //////////////

void setup() {
  // put your setup code here, to run once:
  for (i = 0; i < n; i++) {
    pinMode(Sensores[i], INPUT);
  }
  pinMode(LED, OUTPUT);
}
////////////// Main e Funçoes auxiliares do Sensor Frente //////////////

int verificarSensoresLinha() {
  // put your main code here, to run repeatedly:
  for (i = 0; i < n; i++) {
    digitalWrite(LED, HIGH);
    if (i == 0) delay(1200);                                    // para dar tempo para girar o carro na mao mesmo;
    else       delay(600);
    digitalWrite(LED, LOW);                                     // Lembrar que começa da direita para esquerda;

    for (j = 0; j < 10; j++) {
      VSen[i] += digitalRead(Sensores[i]);
      delay(20);
    }
    VSen[i] /= 10;
  }

  for (i = 0 ; i < n; i++) {
    if ( (VSen[i] <= VPadraoSen[i] - (VPadraoSen[i]*IPadraoSen[i])) || (VSen[i] s >= VPadraoSen[i] + (VPadraoSen[i]*IPadraoSen[i]))) {
      ResultadosSen[i] = -1;
    } else ResultadosSen[i] = 1;
  }

  for (i = 0; i < n; i++) {
    if (ResultadoSen[i] == -1) {
      return -1;
    }
  }
  return 1;
}
