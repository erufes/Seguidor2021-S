#include<WiFi.h>
#include<PubSubClient.h>

const char* ssid = ""        //host do wifi
const char* pass = ""        //senha do wifi
const char* brokerUser = ""  //broker id
const char* brokerPass = ""  //broker pass
const char* broker = ""      //broker
const char* clientId = ""    //client id
const char* inTopic = ""     //topico de entrada

String number;               //valor a ser recebido
int value=0;                 //valor convertido a pode ser usado no motor

WiFiClient espClient;
PubSubClient client(espClient);


void setupwifi(){
  delay(100);
  Serial.print("\nConectando ao:");
  Serial.println(ssid);
  
  WiFi.begin(ssid,pass);

  while(WiFi.status() != WL_CONNECTED){
    delay(100);
    Serial.print("-");
  }

  Serial.print("\nConectado ao:");
  Serial.println(ssid);
}

void reconnect(){
  while(!client.connected()){
    Serial.print("\nConectando ao");
    Serial.println(broker);
    if(client.connect(clientId, brokerUser, brokerPass)){
      Serial.print("\nConectado ao");
      Serial.println(broker);
      client.subscribe(inTopic);
    }else{
      Serial.println("tentando se conectar de novo");
      delay(2000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length){
  Serial.print("recieved messages; ");
  Serial.println(topic);
  for(int i=0; i<length; i++){
    Serial.print((char)payload[i]);
    number+=(char)payload[i];
  }
  Serial.println();
  number.toInt(Value);
}

void setup() {
  // put your setup code here, to run once:
  serial.begin(115200);
  setupwifi();
  client.setServer(broker, 1883);
  client.setCallback(callback);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!client.connected()){
    recennect();
  }
  client.loop();
}
