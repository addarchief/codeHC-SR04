#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Enviar pulso
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Medir duración del pulso
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Comprobar si la duración es válida
  if (duration == 0) {
    Serial.println("No se detecta señal de retorno");
  } else {
    float distance = duration / 58.2;
    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
