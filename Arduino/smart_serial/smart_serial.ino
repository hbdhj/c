
// 0: return + 0.0 g , 1: return + 1.0 g, 2: return + 2.0 g
int state = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    int data = Serial.read();
    if (data > 47 && data < 58)
      state = data - 48;
    Serial.print("I received: ");
    Serial.println(state);
  }
  if (state == 1)
    Serial.println("+ 1.0 g");
  else if (state == 2)
    Serial.println("+ 2.0 g");
  else
    Serial.println("+ 0.0 g");
  delay(100);
}
