//Simple Dice roll siualtion using a 3x3 led matrix and a randomizer for the output dice roll

int ledPins[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

//Dice patterns for the led matrix:

int dicePatterns[6][9] = {
  {0, 0, 0, 0, 1, 0, 0, 0, 0}, //Number 1
  {0, 0, 1, 0, 0, 0, 1, 0, 0}, //Number 2
  {1, 0, 0, 0, 1, 0, 0, 0, 1}, //Number 3
  {1, 0, 1, 0, 0, 0, 1, 0, 1}, //Number 4
  {1, 0, 1, 0, 1, 0, 1, 0, 1}, //Number 5
  {1, 1, 1, 0, 0, 0, 1, 1, 1}, //Number 6
};

//The leds on collums 3 and 5 are awalls 0


int button = 11;

void setup() {
  for (int i =0; i < 9; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  };
  randomSeed(analogRead(0));
  pinMode(button, INPUT_PULLUP);  //
}

void loop() {
  if (digitalRead(button) == LOW) {
    rollTheDice();
    delay(100);
  };
}

void rollTheDice() {
  int result = 0;
  result = random(0, 6);
  for (int i = 0; i < 9; i++)
  {
  digitalWrite(ledPins[i], dicePatterns[result][i]);
  }
  }
