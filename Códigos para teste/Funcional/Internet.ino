////////////// Funçoes auxiliares //////////////
void initWiFi();
void initMQTT();
void reconnectMQTT();
void reconectWiFi();
void callback(char *topic, byte *payload, unsigned int length);
void VerificaConexoesWiFIEMQTT();
//void InitOutput();

//Função: inicializa e conecta-se na rede WI-FI desejada
void initWiFi()
{

    delay(10);
    Serial.println("------Conexao WI-FI------");
    Serial.print("Conectando-se na rede: ");
    Serial.println(SSID);
    Serial.println("Aguarde");

    reconectWiFi();
}

//Função: inicializa parâmetros de conexão MQTT(endereço do
//        broker, porta e seta função de callback)
void initMQTT()
{
    client.setServer(MQTT_SERVER, MQTT_PORT); //Seta servidor com o broker e a porta
    client.setCallback(callback);             //atribui função de callback (função chamada quando qualquer informação de um dos tópicos subescritos chega)
}

//Função: função de callback
//        esta função é chamada toda vez que uma informação de
//        um dos tópicos subescritos chega)
void callback(char *topic, byte *payload, unsigned int length)
{
    // Processa mensagens recebidas
    Serial.print("Recebido [");
    Serial.print(topic);
    Serial.print("] ");
    String s = "";
    for (int i = 0; i < length; i++) //obtem a string do payload recebido
    {
        s += (char)payload[i];
    }
    Serial.println(s);

    //toma ação dependendo da string recebida:
    //verifica se deve colocar nivel alto de tensão na saída D0:
    //IMPORTANTE: o Led já contido na placa é acionado com lógica invertida (ou seja,
    //enviar HIGH para o output faz o Led apagar / enviar LOW faz o Led acender)
    /*if (s.equals("L"))
    {
        digitalWrite(D0, LOW);
    }
 
    //verifica se deve colocar nivel alto de tensão na saída D0:
    if (s.equals("D"))
    {
        digitalWrite(D0, HIGH);
    }*/
}

//Função: reconecta-se ao broker MQTT (caso ainda não esteja conectado ou em caso de a conexão cair)
//        em caso de sucesso na conexão ou reconexão, o subscribe dos tópicos é refeito.
void reconnectMQTT()
{
    //Loop até que o MQTT esteja conectado
    while (!client.connected())
    {
        Serial.println("Connectando Broker...");

        // Conecta
        if (client.connect(MQTT_CLIENT))
        {
            Serial.println("Conectado");
            client.subscribe(MQTT_TOPIC); // Assina topico "test"
        }
        else
        {
            // Falha na conexao
            Serial.println("Falha ao reconectar no broker.");
            delay(5000);
        }
    }
}

//Função: reconecta/conecta ao WiFi
void reconectWiFi()
{
    //se já está conectado a rede WI-FI, nada é feito.
    //Caso contrário, são efetuadas tentativas de conexão
    if (WiFi.status() == WL_CONNECTED)
        return;

    WiFi.begin(SSID, PASSWORD); // Conecta na rede WI-FI

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(100);
        Serial.print(".");
    }

    Serial.println();
    Serial.print("Conectado com sucesso na rede ");
    Serial.print(SSID);
    Serial.println("IP obtido: ");
    Serial.println(WiFi.localIP());
}

//Função: verifica o estado das conexões WiFI e ao broker MQTT.
//        Em caso de desconexão, a conexão é refeita.
void VerificaConexoesWiFIEMQTT()
{
    if (!client.connected())
        reconnectMQTT(); //se não há conexão com o Broker, a conexão é refeita

    reconectWiFi(); //se não há conexão com o WiFI, a conexão é refeita
}

//Função: inicializa o output em nível lógico baixo
/*void InitOutput()
{
    //IMPORTANTE: o Led já contido na placa é acionado com lógica invertida (ou seja,
    //enviar HIGH para o output faz o Led apagar / enviar LOW faz o Led acender)
    pinMode(D0, OUTPUT);
    digitalWrite(D0, HIGH);          
}*/