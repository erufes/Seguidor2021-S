int n = ?;                                                      // colocar a quantidade total de leds
int LED[n] = { ? };                                             // colocar os respectivos pinos correspondentes dos leds
int i;                                                          // variavel
void setup() {
  // put your setup code here, to run once:
  for (i = 0; i < n; i++) {
    pinMode(LED[i], OUTPUT);
  }
}

void verificaLed() {
  // put your main code here, to run repeatedly:
  for (i = 0; i < n; i++) {
    digitalWrite(LED[i], HIGH);
    delay(30);
  }

  delay(500 - 30 * n);

  for (i = 0; i < n; i++) {
    digitalWrite(LED[i], LOW);
    delay(30);
  }
}
