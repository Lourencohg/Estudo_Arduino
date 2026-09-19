// Basic Traffic Light sketch where the lights only changes when a button is pressed 

int redLED = 4;
int yellowLED = 3;
int greenLED = 2;

int button = 5;

int state = 0;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(button, INPUT_PULLUP); // //Activate the internal pullup resistor so it will not be a floating pin
  setlight(HIGH, LOW, LOW);
}

void loop() {
  if (digitalRead(button) == LOW) {
    delay(50); //prevent eletrical noises

    state = (state + 1) % 3;

    if (state == 0) {
      setlight(HIGH, LOW, LOW);
    } else if (state == 1) {
      setlight(LOW, LOW, HIGH);
    } else {
      setlight(LOW, HIGH, LOW); 
      //state = 0;
    }

    while (digitalRead(button) == LOW) {
      delay(10);
    }
  }
}

void setlight(int RED, int YELLOW, int GREEN){
  digitalWrite(redLED, RED);
  digitalWrite(yellowLED, YELLOW);
  digitalWrite(greenLED, GREEN);
}

