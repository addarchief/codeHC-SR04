#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER_PIN 11

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration / 58.2;

  if (distance > 0 && distance < 10) {
    tone(BUZZER_PIN, 1000); // Genera un tono de 1kHz
  } else {
    noTone(BUZZER_PIN); // Apaga el buzzer
  }

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}
