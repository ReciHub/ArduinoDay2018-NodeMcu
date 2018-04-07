char nome[] = "Thiago Augusto"; // Digite o seu nome dentro das ""

void setup() {
  // Comeca a comunicacao com o pc a 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // Exibe Hello World no Serial Monitor
  Serial.println("Hello World");
  Serial.print(nome);
  Serial.print("\n");
  delay(1000);
}
