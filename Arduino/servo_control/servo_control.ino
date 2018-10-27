int servoPin = 9;
int servoPos = 1500;
int servoMidPos = 1500;
int servoLeftPos = 1000;
int servoRightPos = 2000;
int direction = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(servoPin, OUTPUT);
}

void controlServo(int pos) {
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pos);
  digitalWrite(servoPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (servoPos > servoRightPos)
    servoPos = servoRightPos;
  else if (servoPos < servoLeftPos)
    servoPos = servoLeftPos;
  else if ((servoPos < servoRightPos) && (servoPos > servoLeftPos))
    if (direction == 1)
      servoPos += 100;
    else
      servoPos -= 100;
  else if (servoPos == servoRightPos) {
    direction = 0;
    servoPos -= 100;
  }
  else if (servoPos == servoLeftPos) {
    direction = 1;
    servoPos += 100;
  }
  Serial.println(servoPos);
  controlServo(servoPos);
  delay(200);
}
