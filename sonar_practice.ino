const int echoPin = 7;
const int trigPin = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long dist = getDist(echoPin, trigPin);
  Serial.println(dist);
  delay(50);
}

long getDist(int echo, int trig){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echo, HIGH);
  long distance = duration / 57.8;
  return distance;
}
