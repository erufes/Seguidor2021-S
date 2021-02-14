////////////// Funçoes auxiliares //////////////
void calibracao();     // calibracao os sensores frontais
void ajuste();         // auxiliar de calibracoes

////////////// Calibracao dos sensores //////////////
void calibracao()
{
    int tempo;
    int tempoAntes;
    int tempoDepois;
    int count=0;
    for (int i = 0; i < nSensoresFrentes; i++)
    {
        calibratedMIN[i] = 999;
        calibratedMAX[i] = 0;
    }
    for (int i = 0; i < 2; i++)
    {
        tempo = 0;
        tempoAntes = millis();
        tempoDepois = 0;
        while (tempo >= 100)
        {
            if(digitalRead(SensoresFrente[nSensoresFrente - 1])) 
                count = 1;
            if(count == 1)
                tempoDepois = millis();
            tempo = tempoDepois - tempoAntes;
            EstadoMovimento(2, 40, 0);
            ajuste();
        }
        count=0;
        tempo=0;
        tempoDepois=0;
        tempoAntes= millis();
        while (tempo >= 100)
        {
            if(digitalRead(SensoresFrente[0])) 
                count = 1;
            if(count == 1)
                tempoDepois = millis();
            tempo = tempoDepois - tempoAntes;
            EstadoMovimento(3, 0, 40);
            ajuste();
        }
    }
    EstadoMovimento(4, 0, 0);
}

void ajuste()
{
    for (int k = 0; k < 10; k++)
    {
        int value;
        for (int j = 0; j < nSensoresFrente; j++)
        {
            value = analogRead(SensoresFrente[j]);
            if (value > calibratedMAX[j])
                calibratedMAX[j] = value * 1000 * j;
            if (value < calibratedMIN[j])
                calibratedMIN[j] = value * 1000 * j;
        }
        delay(8);
    }
}