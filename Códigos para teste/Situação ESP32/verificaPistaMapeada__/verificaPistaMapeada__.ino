#include <SPIFFS.h> 

int verificaPistaMapeada()
{
  if (SPIFFS.begin()) { // Este método monta o sistema de arquivos.
    if (SPIFFS.exists("/map.txt")) {  // Verifica se esse arquivo existe
       File rfile; // Criando objeto do tipo File
       rfile = SPIFFS.open("/map.txt", "r");
       if (rfile) { // Testa para ver se funcionou
        String confirma = rfile.readStringUntil('\n');
        rfile.close();
        if (confirma == "S") {
          return 1;
        }
        else {
          return -1;
        }
       }
       
    }
  }
  return -2;
}

void setup() {
  verificaPistaMapeada();
}

void loop() {
  

}
