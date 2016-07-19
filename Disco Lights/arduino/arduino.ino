//Create an array for the pins that will be hooked up to LEDs
int ledPins[] = {4,5,6,7,8,9,10,11,12,13};

void setup() {
  // Set the serial baud to 9600 (has to match the baud in the Processing file)
  Serial.begin(9600);

  // Initialize the pins as output, and turn them off in case they are on
  for(int i = 4; i < 14; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

// If the serial port receives a 0, turn off the LEDs
// If it receives a 1, turn them on.
// If it receives a 2, engage disco mode!
void loop() {
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

// Turn off and turn on the LEDs repetitively by setting voltage to
// high (on) and low (off).
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

