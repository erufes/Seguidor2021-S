////////////// Funçoes auxiliares //////////////
float lePorta(uint8_t portaAnalogica); // funcao auxiliar da bateria que retorna a media de amostras coletadas
int verificaBateria();                 // verifica tensao da bateria
int verificarSensoresLinha();          // verifica sensores frontais
int verificaSensoresLaterais();        // verifica sensores laterais
void verificaLed();                    // verifica os leds
void verificaBuzzer();                 // faz o buzzer gritar
int verificaPistaMapeada();            // verifica

////////////// Bateria //////////////
float lePorta(uint8_t portaAnalogica)
{
  float total = 0;
  for (int i = 0; i < AMOSTRAS; i++)
  {
    total += 1.0 * analogRead(portaAnalogica);
    delay(5);
  }
  return total / (float)AMOSTRAS;
}

int verificaBateria()
{
  V = (lePorta(EntradaTensao) * aRef) / 1023.0;
  V *= relacao;
  if (V <= 8.2 || V >= 8.4)
  {
    return -1;
  }
  else
    return V;
}

////////////// Sensores Frente //////////////
int verificarSensoresLinha()
{
  for (i = 0; i < nSensoresFrente; i++)
  {
    digitalWrite(LED, HIGH);
    if (i == 0)
      delay(1200); // para dar tempo para girar o carro na mao mesmo;
    else
      delay(600);
    digitalWrite(LED, LOW); // Lembrar que começa da direita para esquerda;

    for (j = 0; j < 10; j++)
    {
      VSen[i] += analogRead(SensoresFrente[i]);
      delay(20);
    }
    VSen[i] /= 10;
  }

  for (i = 0; i < n; i++)
  {
    if ((VSen[i] <= VPadraoSen[i] - (VPadraoSen[i] * IPadraoSen[i])) || (VSen[i] s >= VPadraoSen[i] + (VPadraoSen[i] * IPadraoSen[i])))
    {
      ResultadosSen[i] = -1;
    }
    else
      ResultadosSen[i] = 1;
  }

  for (i = 0; i < n; i++)
  {
    if (ResultadoSen[i] == -1)
    {
      return -1;
    }
  }
  return 1;
}

////////////// Sensores Laterais //////////////
int verificaSensoresLaterais()
{
  int ValorD = 0;
  int valorE = 0;
  int retorno = 1;

  digitalWrite(LED, HIGH);
  delay(1500);            // para dar tempo para girar o carro na mao mesmo;
  digitalWrite(LED, LOW); // Lembrar que começa da direita para esquerda;

  for (int i = 0; i < 10; i++)
  {
    if (digitalRead(SenD) = !Cor)
      ValorD++;
    delay(20);
  }

  if (ValorD > 4)
  {
    retorno = -1;
  }

  digitalWrite(LED, HIGH);
  delay(1500); // para dar tempo para girar o carro na mao mesmo;
  digitalWrite(LED, LOW);

  for (int i = 0; i < 10; i++)
  {
    if (digitalRead(SenE) = !Cor)
      ValorE++;
    delay(20);
  }

  if (ValorE > 4)
  {
    if (retorno == -1)
      retorno = -3;
    else
      retorno = -2;
  }
  return retorno;
}

////////////// LEDs//////////////
void verificaLed()
{
  for (i = 0; i < nQuatidadeLeds; i++)
  {
    digitalWrite(LEDs[i], HIGH);
    delay(30);
  }

  delay(500 - 30 * nQuatidadeLeds);

  for (i = 0; i < nQuatidadeLeds; i++)
  {
    digitalWrite(LEDs[i], LOW);
    delay(30);
  }
}

////////////// Buzzer //////////////
void verificaBuzzer()
{
  for (int thisNote = 0; thisNote < songLength; thisNote++)
  {

    int duration = 1000 / durations[thisNote];
    tone(Buzzer, melody[thisNote], duration);
    int pause = duration * 1.3;
    delay(pause);
    noTone(Buzzer);
  }
}
////////////// Mapeaamento //////////////
int verificaPistaMapeada()
{
  if (SPIFFS.begin())
  { // Este método monta o sistema de arquivos.
    if (SPIFFS.exists("/map.txt"))
    { // Verifica se esse arquivo existe
      rfile = SPIFFS.open("/map.txt", "r");
      if (rfile)
      { // Testa para ver se funcionou
        String confirma = rfile.readStringUntil('\n');
        rfile.close();
        if (confirma == "S")
        {
          return 1;
        }
        else
        {
          return -1;
        }
      }
    }
  }
  return -2;
}