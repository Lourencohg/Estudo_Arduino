int ledPin = 12;
int dotDelay = 200; // duração de um ponto

const char* letters[]= {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", 
  "....", "..", ".---", "-.-", ".-..", "--", "-.", 
  "---", ".--.", "--.-", ".-.", "...", "-", "..-",
  "...-", ".--", "-..-", "-.--", "--.."
};

const char* numbers[] = {
  "-----", ".----", "..---", "...--", "....-", // 0 - 4
  ".....", "-....", "--...", "---..", "----."}; // 5 - 9


void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Iniciando a porta serial para 
  Serial.print("Bem vindo, mande uma mensagem para ser transmitida via código Morse"); //
}

void loop() {
  char ch;
  if (Serial.available())
  {
    ch = Serial.read();
    if (ch >= 'a' && ch <= 'z')
    {
      flashSequence(letters[ch - 'a']);
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
      flashSequence(letters[ch - 'A']);
    }
    else if (ch >= '0' && ch <= '9')
    {
      flashSequence(numbers[ch - '0']);
    }
    else if (ch == ' ')
    {
      delay(dotDelay * 4);
    }
  }
}

void flashSequence(char* sequence)
{
  int i = 0;
  while (sequence[i] !=NULL)
  {
    flashDotOrDash(sequence[i]);
    i++;
  }
  delay(dotDelay * 3);
}

void flashDotOrDash(char dotOrDash)
{
  digitalWrite(ledPin, HIGH);
  if (dotOrDash == '.') // verificar se é um "."
  {
    delay(dotDelay);
  }
  else  // se não for "." será um "-"
  {
    delay(dotDelay * 3);
  }
  digitalWrite(ledPin, LOW);
  delay(dotDelay);
}


