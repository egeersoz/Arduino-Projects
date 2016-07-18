int ledPins[] = {4,5,6,7,8,9,10,11,12,13};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 4; i < 14; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    int key = Serial.read();
    if (key == 1) {
      for(int i = 4;i < 14; i++) {
        digitalWrite(i, HIGH);
      }
    } else if (key == 0) {
      for(int i = 4; i < 14; i++) {
        digitalWrite(i, LOW);
      }
    } else if (key == 2) {
      discoMode();
    }
  }
}

void discoMode() {
  for(int i = 4; i < 14; i++) {
    digitalWrite(i, HIGH);
    delay(50);
  }
  for(int k = 4; k < 14; k++) {
    digitalWrite(k, LOW);
    delay(50);
  }
}

