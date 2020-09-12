include <WiFi.h>

const char* ssid = "nome_da_rede";
const char* password =  "senha_da_rede";

void setup() {
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
  }
}

void loop() {}
