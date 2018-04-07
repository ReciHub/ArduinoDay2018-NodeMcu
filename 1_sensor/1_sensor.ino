// Valores de constantes nao mudam. Sao usualmente utilizados para pinagem:
const int buttonPin = 14;     // O valor do pino do push button
// Variaveis que serao modificadas
int buttonState = 0;         // Variavel que salva o status do botao

void setup() {
  Serial.begin(9600);
  // Inicializa o Botao como entrada
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Le o valor do push button
  buttonState = digitalRead(buttonPin);

  // Verifica se o botao esta pressionado
  if (buttonState == HIGH) {
    Serial.println("O Valor do Botao esta em nivel Alto");
  } else {
    Serial.println("O Valor do Botao esta em nivel Baixo");
  }
}
