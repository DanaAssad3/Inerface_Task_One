#define trigPin 11
#define echoPin 10
#define pot A4 
#define red 4
#define yello 3
#define green 2

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(red, OUTPUT);
  pinMode(yello, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration) / 29.1;
  distance = distance / 2;

  int potValue = analogRead(pot);
  int minThreshold = map(potValue, 0, 1023, 10, 400);
  int midThreshold = minThreshold + 10;

  if (distance < minThreshold) {
    digitalWrite(red, HIGH);
    digitalWrite(yello, LOW);
    digitalWrite(green, LOW);
  } else if (distance >= minThreshold && distance < midThreshold) {
    digitalWrite(red, LOW);
    digitalWrite(yello, HIGH);
    digitalWrite(green, LOW);
  } else {
    digitalWrite(red, LOW);
    digitalWrite(yello, LOW);
    digitalWrite(green, HIGH);
  }

  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
