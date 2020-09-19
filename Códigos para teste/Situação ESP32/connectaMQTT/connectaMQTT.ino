#include <PubSubClient.h>

// Constantes -------------------------------------------
// Broker local
const char*   MQTT_SERVER         = "192.168...";
// Porta padrão
const int     MQTT_PORT           = 1883;
// Tópico
const char*   MQTT_TOPIC          = "test";
// Cliente
const char*   MQTT_CLIENT         = "meuESPmara20";

// Instancias -------------------------------------------
WiFiClient espClient; // Cria o objeto espClient
PubSubClient client(espClient); // Instancia o Cliente client passando o objeto espClient

int connectaMQTT()
{
  client.setServer(MQTT_SERVER, MQTT_PORT);

  for (int i=0; i<10 || client.connected() != 1; i++)
  {
     // Conecta
    if (client.connect(MQTT_CLIENT)) 
    {
      client.subscribe(MQTT_TOPIC);  // Assina ao topico 
    }
    else
    {
      // Falha na conexao
      delay(100);
    }
  }
  if (client.connect(MQTT_CLIENT))
  {
    return 1;
  }
  else 
  {
    return -1;
  }
}

void setup() {
  connectaMQTT();
}

void loop() {
  //keep-alive da comunicação com broker MQTT
    client.loop();
}
