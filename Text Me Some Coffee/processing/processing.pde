import processing.serial.*;
Serial ComPort;
String input[];

//Set up the serial port at 9600 baud
void setup() {
  String portName = Serial.list()[0];
  ComPort = new Serial(this, portName, 9600);
  ComPort.bufferUntil('\n');
}

//Check a text file on the server and send its value to the serial port
void draw() {
  input = loadStrings("https://laserfiche.zeno-cloud.com/Arduino/disco.txt");
  if (input != null) {
    if(input.length != 0) {
      println(input[0]);
      int status = Integer.parseInt(input[0]);
      ComPort.write(status);
    }
  }
  delay(1000); //Check the text file every second
}