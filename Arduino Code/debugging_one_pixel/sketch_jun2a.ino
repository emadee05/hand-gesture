const int rowPins[] = {2};
const int colPins[] = {8};
const int tiaPin = A0;

bool startReading = false;  // flag to control continuous reading

void setup() {
  Serial.begin(115200);
  while (!Serial);  // wait for serial connection
 // initially off
  pinMode(rowPins[0], OUTPUT);
  digitalWrite(rowPins[0], LOW);  // initially off

  pinMode(colPins[0], OUTPUT);
  digitalWrite(colPins[0], LOW);  // initially off

  for (int i=3; i<8; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  for (int i=9; i<14; i++){
    pinMode(i,OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "START") {
      Serial.print("starting");
      digitalWrite(rowPins[0], HIGH);
      digitalWrite(colPins[0], HIGH);
      startReading = true;
    }
  }

  if (startReading) {
    int val = analogRead(tiaPin);
    Serial.println(val);
    delayMicroseconds(200);  // optional: limit speed a bit if needed
  }
  
}
