////////////// Variaveis da Bateria //////////////
#define AMOSTRAS 12                                                       // Quantidades de vezes que vai fazer a leitura da entrada 
#define LED 4                                                              // LED designado a bateria
#define EntradaTensao A0                                                   // Entrada de tensao(Porta Analogica)
float V;                                                                  // Tensao adquirida
float aRef = 3.3;                                                           // Tensão máxima que pode ser lida numa porta analógica (3 ou 5)
float relacao = (143 / 43);

////////////// Main e Funçoes auxiliares da Bateria //////////////

float lePorta(uint8_t portaAnalogica);
int verificaBateria();

////////////// setup() da Bateria //////////////

void setup() {
  pinMode(EntradaTensao, INPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.print(" Verifica Bateria: ");
  Serial.print(verificaBateria());
  Serial.print(" e V: ");
  Serial.println(V);
  delay(500);  
}

float lePorta(uint8_t portaAnalogica) {
  float total = 0;
  for (int i = 0; i < AMOSTRAS; i++) {
    total += 1.0 * analogRead(portaAnalogica);
    delay(5);
  }
  return total / (float)AMOSTRAS;
}

int verificaBateria() {
  V = (lePorta(EntradaTensao) * aRef) / 1023.0;
  V *= relacao;
  if (V <= 8.2 || V >= 8.4) {
    return -1;
  }
  else return V;
}
