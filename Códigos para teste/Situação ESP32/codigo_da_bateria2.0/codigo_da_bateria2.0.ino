////////////// Variaveis da Bateria //////////////
#define AMOSTRAS 12                                                       // Quantidades de vezes que vai fazer a leitura da entrada 
#define LED                                                               // LED designado a bateria
#define EntradaTensao ?                                                   // Entrada de tensao(Porta Analogica)
float V;                                                                  // Tensao adquirida
float aRef = 3;                                                           // Tensão máxima que pode ser lida numa porta analógica (3 ou 5)
float relacao = (143 / 43);

float verificaBateria();
float lePorta(uint8_t portaAnalogica);

////////////// setup() da Bateria //////////////

void setup() {
  pinMode(EntradaTensao, INPUT);
}

////////////// Main e Funçoes auxiliares da Bateria //////////////

float lePorta(uint8_t portaAnalogica) {
  float total = 0;
  for (int i = 0; i < AMOSTRAS; i++) {
    total += 1.0 * analogRead(portaAnalogica);
    delay(5);
  }
  return total / (float)AMOSTRAS;
}


float verificaBateria() {
  V = (lePorta(EntradaTensao) * aRef) / 1023.0);
  V *= relacao;
  if (V <= 8.2 || V >= 8.4) {
    return -1;
  }
  else return V;
}
