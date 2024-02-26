#define CAMERA_PIN 2
#define SENSOR_PIN 3
#define BUZZER_PIN 4

#define BUZZER_FREQUENCY 1000
#define IMAGE_THRESHOLD 100

void setup() {
  // put your setup code here, to run once:
  pinMode(CAMERA_PIN, INPUT);
  pinMode(SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int imageValue = analogRead(CAMERA_PIN);
  int sensorValue = digitalRead(SENSOR_PIN);

  if(imageValue>IMAGE_THRESHOLD && sensorValue==HIGH){
    longBeep();
  }
}

void longBeep(){
  tone(BUZZER_PIN, BUZZER_FREQUENCY);
  delay(2000);
  noTone(BUZZER_PIN);
}
