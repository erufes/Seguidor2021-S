// Bibliotecas
#include <FS.h> // Incluindo biblioteca FS.h

// A maioria das funções retorna 0 ou 1

/**
  * --- Inicializando SPIFSS ---
  * @descrição: inicializa o sistema de arquivos
*/
void abrirFS() {
  //Abre o sistema de arquivos
  Serial.println("\nInicializando SPIFSS ---------------------");
  if (SPIFFS.begin()) { // Este método monta o sistema de arquivos.
    Serial.println("Ok");
  }
  else {
    Serial.println("Falha"); // Teste de falha
    while (true); // Loop eterno para travar a execução se houver falha na inicialização
  }
}

/**
  * --- Gravando arquivo ---
  * @descrição: escreve conteúdo em um arquivo
*/
void gravarArquivo() {
  File file; // Criando objeto do tipo File

  file = SPIFFS.open("/Log/Log.txt", "a"); // Abrindo o arquivo com modo de acesso "a" para escrever no final

  if (file) { // Testa para ver se funcionou
    file.println("Inicializando...");
    file.printf("Registro %u\r\n", millis()); // Grava no arquivo
    file.close();                             // Fechando o arquivo
  }
}

/**
  * --- Lendo arquivo ---
  * @descrição: lê conteúdo de um arquivo
*/
void lerArquivo() {
  Serial.println("\nLendo Arquivo ----------------------------");
  file = SPIFFS.open("/Log/Log.txt", "r"); // Abrindo o arquivo com modo de acesso "r" para apenas ler

  if (file) { // Se for verdadeiro
    Serial.printf("Nome: %s - %u bytes\n", file.name(), file.size());
    while (file.available()) {                                            // Enquanto tem conteudo no arquivo
      String texto = file.readStringUntil('\n'); // Lê o arquivo linha a linha até o final da linha
      Serial.println(texto);
    }
    file.close(); // Fecha o arquivo
  }
}

/**
  * --- Excluindo arquivo ---
*/
void excluirArquivo() {
  Serial.println("\nExcluindo Arquivo ----------------------------");
  if (SPIFFS.remove("/Log/Log.txt")) { // Teste de funcinamento
    Serial.println("Arquivo '/Log/Log.txt' excluído");
  }
  else {
    Serial.println("Exclusão '/Log/Log.txt' falhou");
  }
}

void setup() {
  Serial.begin(115200);

  abrirFS();

  gravarArquivo();

  lerArquivo();

  excluirArquivo();
}

void loop() {
}
