////////////// Bibliotecas //////////////
#include "pitches.h"     // biblioteca para o buzzer
#include <ESP8266WiFi.h> // Se for ESP8266
//#include <WiFi.h>        // Se for ESP32
#include <PubSubClient.h> // Importa a Biblioteca para as publicações via mqtt
#include <SPIFFS.h>       // biblioteca para o mapeamento

////////////// Variaveis da auxiliares //////////////
int i = 0;
int j = 0;
unsigned long t; //usado para transmisão de dados
String msg;      //usado para transmisão de dados
File rfile;      // Criando objeto do tipo File
int cor = 1;     // cor da linha 1 preto 0 branco

////////////// Variaveis da Bateria //////////////
#define AMOSTRAS 12 // Quantidades de vezes que vai fazer a leitura da entrada
float V;            // Tensao adquirida
float aRef = 3.3;   // Tensão máxima que pode ser lida numa porta analógica (3 ou 5)
float relacao = (143 / 43);

////////////// Variaveis do Sensor Frente e calibracao //////////////
#define nSensoresFrente 6 // Numero de sensores
int calibracaoMIN[nSensoresFrente];
int calibracaoMAX[nSensoresFrente];
float VSen[nSensoresFrente]; // Valor dos sensores
for (i = 0; i < n; i++)
{
    VSen[i] = 0;
}

int ResultadoSen[nSensoresFrente];                                        // array que sera inserido os resultados: 1 para sensor nao danificado e -1 para sensor danificado
float VPadraoSen[nSensoresFrente] = [ ?, ?, ?, ?, ?, ? ];                 // Valor padrao para comparar se so sensores estão em boas condiçôes
float IPadraoSen[nSensoresFrente] = [ ?, ?, ?, ?, ?, ? ];                 // Intervalo de confianca para comparar se os sensores estãao em boas condições  (1 >= x > 0)

////////////// Variaveis do Sensor Frente //////////////
float VDPadrao ? ; // valor direito padrao para comparar se o sensor esta em boa condicao
float VEpadrao ? ; // valor esquerdo padrao para comparar se o sensor esta em boa condicao

float IDPadrao ? ; // Intervalo de confianca direito para comparar se o sensor esta em boa condicao  (1 >= x > 0)
float IEpadrao ? ; // Intervalo de confianca esquerdo para comparar se o sensor esta em boa condicao (1 >= x > 0)

////////////// Variaveis dos LEDs //////////////
int nQuatidadeLeds = ? ; // colocar a quantidade total de leds

////////////// Variaveis do Buzzer //////////////
///////////// Musica take on me    /////////////
int melody[] = {
    NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_E5,
    NOTE_E5, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5,
    NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, NOTE_D5, NOTE_FS5,
    NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5};

int durations[] = {
    8, 8, 8, 4, 4, 4,
    4, 5, 8, 8, 8, 8,
    8, 8, 8, 4, 4, 4,
    4, 5, 8, 8, 8, 8};

int songLength = sizeof(melody) / sizeof(melody[0]);

////////////// Andar //////////////
const int motorEsq[3] = {?, ?, ?};    // {dig, dig, pwm}
const int motorDir[3] =  {?, ?, ?};   // {dig, dig, pwm}

////////////// WIFI //////////////
const char *SSID = "SSID";      // SSID / nome da rede WI-FI que deseja se conectar
const char *PASSWORD = "SENHA"; // Senha da rede WI-FI que deseja se conectar

////////////// MQTT //////////////
// Broker local
const char *MQTT_SERVER = "127.0.0.1"; // ou "localhost"
// Porta padrão
const int MQTT_PORT = 1883;
// Tópico
const char *MQTT_TOPIC = "test";
// Cliente
const char *MQTT_CLIENT = "meuESPmara19";

// Instancias -------------------------------------------
WiFiClient espClient;           // Cria o objeto espClient
PubSubClient client(espClient); // Instancia o Cliente client passando o objeto espClient

////////////// Definicao de pinos //////////////
#define EntradaTensao A0 // Entrada de tensao(Porta Analogica)
#define LEDbateria 4     // LED designado a bateria
#define SenD ?           // Sendor direito
#define SenE ?           // Sendor esquerdo
#define LED 13           // LED
#define Buzzer ?         // Pino do Buzzer
//#define D0    16                                                        // define do codigo do MQTT
int SensoresFrente[nSensoresFrente] = [ ?, ?, ?, ?, ?, ? ];               // Sensores da frente
int LEDs[nQuatidadeLeds] = {? };                                          // colocar os respectivos pinos correspondentes dos leds

void setup()
{
    for (i = 0; i < nSensoresFrente; i++)
    {
        pinMode(SensoresFrente[i], INPUT);
    }
    for (i = 0; i < n; i++)
    {
        pinMode(LED[i], OUTPUT);
    }
    pinMode(EntradaTensao, INPUT);
    pinMode(LED, OUTPUT);
    pinMode(SenD, INPUT);
    pinMode(SenE, INPUT);
    Serial.begin(115200);

    /*//Inicializações:
    //InitOutput();
    initWiFi();
    initMQTT();
    verificaPistaMapeada();*/
}

void loop()
{
    /*//garante funcionamento das conexões WiFi e ao broker MQTT
    VerificaConexoesWiFIEMQTT();

    //keep-alive da comunicação com broker MQTT
    client.loop();

    // Publica mensagem a cada 5s
    if (millis() - t > 5000)
    {
        t = millis();
        msg = "Tempo ativo " + String(t / 1000) + "s";
        Serial.println("Publicado: " + msg);
        client.publish(MQTT_TOPIC, msg.c_str());
    }*/// Implementar mais futuramente
    
}