int echopin = 2;
int trigpin = 3;
long duration;
int distance;

void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = duration * 0.034 / 2;
  if (distance<=19){
    digitalWrite(13, HIGH);
  	digitalWrite(12, LOW);
    digitalWrite(11, LOW);}
  else if (distance<=39 and distance>=20){
    digitalWrite(12, HIGH);
  	digitalWrite(11, LOW);
    digitalWrite(13, LOW);}
  else if (distance<=50 and distance>=40){
    digitalWrite(11, HIGH);
  	digitalWrite(12, LOW);
    digitalWrite(13, LOW);}
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(10);
}