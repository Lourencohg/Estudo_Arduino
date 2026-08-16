// Codigo para transmitir a mensagem "S.O.S" em código morse por meio de um led no pino 12
// S.O.S = ...---...
// . = piscar por 200 ms
// - = piscar por 500 ms
int ledPin = 12;

int durations[] = {200, 200, 200, 500, 500, 500, 200, 200, 200}; // Verificar se tem 9 elementos, menos elementos o sis

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 9; i++){ // O numero de valores da lista de ser ou maior ou igual a o numero de loops que devem ser realizados na estrutura de repetição
    flash(durations[i]);
  }
  delay(1000);// delay para remandar a msg segundos
}

void flash(int duration){
  digitalWrite(ledPin, HIGH);
  delay(duration);
  digitalWrite(ledPin, LOW);
  delay(duration);
}


