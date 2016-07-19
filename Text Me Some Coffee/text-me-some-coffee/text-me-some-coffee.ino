const int powerPin = A0;
boolean powerOn = false;

int incomingByte;

void setup() {
  Serial.begin(9600);
  Serial.println(F("starting up"));
  
  pinMode(powerPin, OUTPUT);
  digitalWrite(powerPin, HIGH);
}

void loop() {

  if (Serial.available() > 0) {

    int key = Serial.read();

    if (key == 1) {
      digitalWrite(powerPin, LOW);
      Serial.println(F("ON"));
    } else if (key == 0){
      digitalWrite(powerPin, HIGH);
      Serial.println(F("OFF"));
    }

    while (Serial.available()) incomingByte = Serial.read();
  }
}
