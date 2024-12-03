const int GREEN = 14;
const int YELLOW = 12;
const int RED = 13;
const int GREEN_BTN = 18;
const int YELLOW_BTN = 19;
const int RED_BTN = 23;

int state = 1;
unsigned long timeMilli = millis();

void RedLight() {
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  
}

void YellowLight() {
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);
  
}

void GreenLight() {
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);
}

void toRed() {
  state = 1;
}

void toYellow() {
  state = 2;
}

void toGreen() {
  state = 3;
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(23), toRed, HIGH);
  attachInterrupt(digitalPinToInterrupt(19), toYellow, HIGH);
  attachInterrupt(digitalPinToInterrupt(18), toGreen, HIGH);
}



void loop() {
  while (1) {
    switch (state) {
      case 1:
        RedLight();
        timeMilli = millis();
        state = -1;
        break;
      case 2:
        YellowLight();
        timeMilli = millis();
        state = -2;
        break;
      case 3:
        GreenLight();
        timeMilli = millis();
        state = -3;
        break;
      case -1: // wait for 5 sec, then to go green
        if (millis() - timeMilli >= 5000) {
          state = 3;
        }
        break;
      case -2: // wait for 2 sec, then go to green
        if (millis() - timeMilli >= 2000) {
          state = 1;
        }
        break;
      case -3: // wait for 2 sec, then go to red
        if (millis() - timeMilli >= 5000) {
          state = 2;
        }
        break;
    }
  }
}
