// Valores de constantes nao mudam. Sao usualmente utilizados para pinagem:
const int buttonPin = A0;     // O valor do pino do push button
// Variaveis que serao modificadas
int entradaSensor = 0;         // Variavel que salva o status do botao

void setup() {
  Serial.begin(9600);
  // Inicializa o Botao como entrada
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Le o valor do push button
  entradaSensor = analogRead(buttonPin);

  // Verifica se o botao esta pressionado
  if (entradaSensor > 127) {
    Serial.println("Tem muita umidade nesse lugar");
  } else {
    Serial.println("Tem pouca umidade");
  }
}
