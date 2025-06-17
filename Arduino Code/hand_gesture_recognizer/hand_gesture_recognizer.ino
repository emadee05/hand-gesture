const int rowPins[6] = {2,3,4,5,6,7};
const int colPins[6] = {8,9,10,11,12,13};
const int tiaPin = A0;

bool startReading = false;  // flag to control continuous reading

void setup() {
  Serial.begin(115200);
  while (!Serial);  // wait for serial connection
  for (int i=0; i<6; i++){
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], LOW);  // initially off
  }
  
  for (int j=0; j<6; j++){
    pinMode(colPins[j], OUTPUT);
    digitalWrite(colPins[j], LOW);  // initially off
  }
  for (int i=3; i<8; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }

}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "START") {
    // Serial.println("NEW");
      for (int i=0; i<6; i++){
        digitalWrite(rowPins[i], HIGH);
        // Serial.print(rowPins[i]);
        // delay(10);
        // Serial.print(" ");
        for (int j=0; j<6; j++){
          digitalWrite(colPins[j], HIGH);
          // Serial.print(colPins[j]);
          // Serial.print(" ");

          delay(100);
          // add averaging
          
          int val = analogRead(tiaPin);
          Serial.print(val);
          Serial.print(" ");
          digitalWrite(colPins[j], LOW);
          delay(10);
        }
        Serial.println(" ");
        digitalWrite(rowPins[i], LOW);
        // delay(10);
      }
      startReading = true;
    }
  }
  // if (startReading) {

  // }
  // Serial.print("END");

}
