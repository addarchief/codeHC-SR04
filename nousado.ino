// Definir los pines del sensor
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  // Inicializar la comunicación serie
  Serial.begin(9600);

  // Configurar los pines
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Enviar un pulso de 10 microsegundos al pin Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leer el tiempo que tarda el pulso en volver
  long duration = pulseIn(echoPin, HIGH);

  // Verificar si la lectura es válida
  if (duration == 0) {
    Serial.println("Error: No se recibió señal de respuesta");
    return;
  }

  // Calcular la distancia en centímetros
  long distance = duration * 0.034 / 2;

  // Verificar si la distancia está fuera de rango
  if (distance >= 400 || distance <= 0) {
    Serial.println("Error: Lectura fuera de rango");
    return;
  }

  // Imprimir la distancia por el puerto serie
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Esperar un poco antes de la siguiente medición
  delay(500);
}
