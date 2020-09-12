/*
Montagem:
• 2 Leds
• 2 Resistores de 220 ohm
• ESP32
• Protoboard

Led verde indica que o ESP está conectado
Led vermelho é usado para visualizar a atualização feita pelo OTA
*/
#include <WiFi.h> //lib para configuração do Wifi
#include <ArduinoOTA.h> //lib do ArduinoOTA 
#include <ESPmDNS.h> //lib necessária para comunicação network
#include <WiFiUdp.h> //lib necessária para comunicação network

#define ledVerde 23 //este led sinaliza que o ESP foi conectado
//#define ledVermelho 22 //este led é usado como exemplo de atualização.Deve ser descomentado quando estiver em OTA.

const char* ssid = "robotica"; //nome da rede
const char* password = "12345678"; //senha da rede

void setup()
{
  //define pino como saída
  pinMode(ledVerde,OUTPUT);
  
  //define pino como saída
  //código da atualização.Deve ser descomentado quando estiver em OTA.  
  //pinMode(ledVermelho,OUTPUT);

  //inicia serial com 115200 bits por segundo
  Serial.begin(115200);
  
  Serial.println("Booting");

  //define wifi como station (estação)
  WiFi.mode(WIFI_STA);

  //inicializa wifi
  WiFi.begin(ssid, password);

  //enquanto o wifi não for conectado aguarda
  while (WiFi.waitForConnectResult() != WL_CONNECTED) 
  {
    //caso falha da conexão, reinicia wifi
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  // A porta fica default como 3232
  // ArduinoOTA.setPort(3232);

  // Define o hostname (opcional)
  ArduinoOTA.setHostname("meuesp32");

  // Define a senha (opcional)
  ArduinoOTA.setPassword("senha123");

  // É possível definir uma criptografia hash md5 para a senha usando a função "setPasswordHash"
  // Exemplo de MD5 para senha "admin" = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  //define o que será executado quando o ArduinoOTA iniciar
  ArduinoOTA.onStart( startOTA ); //startOTA é uma função criada para simplificar o código 

  //define o que será executado quando o ArduinoOTA terminar
  ArduinoOTA.onEnd( endOTA ); //endOTA é uma função criada para simplificar o código 

  //define o que será executado quando o ArduinoOTA estiver gravando
  ArduinoOTA.onProgress( progressOTA ); //progressOTA é uma função criada para simplificar o código 

  //define o que será executado quando o ArduinoOTA encontrar um erro
  ArduinoOTA.onError( errorOTA );//errorOTA é uma função criada para simplificar o código 
  
  //inicializa ArduinoOTA
  ArduinoOTA.begin();

  //exibe pronto e o ip utilizado pelo ESP
  Serial.println("Pronto");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  digitalWrite(ledVerde,HIGH);
}

//#######################################################################################
//funções de exibição dos estágios de upload (start, progress, end e error) do ArduinoOTA
void startOTA()
{
   String type;
   
   //caso a atualização esteja sendo gravada na memória flash externa, então informa "flash"
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "flash";
    else  //caso a atualização seja feita pela memória interna (file system), então informa "filesystem"
      type = "filesystem"; // U_SPIFFS

    //exibe mensagem junto ao tipo de gravação
    Serial.println("Start updating " + type);

    digitalWrite(ledVerde,HIGH);
    delay(300);
    digitalWrite(ledVerde,LOW);
    delay(300);
    digitalWrite(ledVerde,HIGH);
    delay(300);
    digitalWrite(ledVerde,LOW);
    delay(300);
}

//exibe mensagem
void endOTA()
{
  Serial.println("\nEnd");
}

//exibe progresso em porcentagem
void progressOTA(unsigned int progress, unsigned int total)
{
   Serial.printf("Progress: %u%%\r", (progress / (total / 100))); 
}

//caso aconteça algum erro, exibe especificamente o tipo do erro
void errorOTA(ota_error_t error)
{  
      Serial.printf("Error[%u]: ", error);
      
      if (error == OTA_AUTH_ERROR) 
        Serial.println("Auth Failed");
      else
      if (error == OTA_BEGIN_ERROR)
        Serial.println("Begin Failed");
      else 
      if (error == OTA_CONNECT_ERROR)
        Serial.println("Connect Failed");
      else
      if (error == OTA_RECEIVE_ERROR) 
        Serial.println("Receive Failed");
      else 
      if (error == OTA_END_ERROR)
        Serial.println("End Failed");
}

//#######################################################################################

void loop() 
{
  //Handle é descritor que referencia variáveis no bloco de memória
  //Ele é usado como um "guia" para que o ESP possa se comunicar com o computador pela rede
  ArduinoOTA.handle();

  //código de atualização. Deve ser descomentado quando estiver em OTA.    
  /*
  digitalWrite(ledVermelho,HIGH);
  delay(1000);
  digitalWrite(ledVermelho,LOW);
  delay(1000);  
  */
}
