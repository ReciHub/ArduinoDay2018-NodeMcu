
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

char nome[30] = "THiago";
int i = 0;
char frase[50] = "Oi, sou jose";
char inChar;

char mensagem[50]  = {};
void setup() {

  Serial.begin(9600);                                  //Serial connection
  
  WiFi.begin("235-ARDUINO DAY", "arduinoday");   //WiFi connection
  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
    delay(500);
    Serial.println("Waiting for connection");
  }
 /* 
  Serial.println("Qual o seu nome?");
  while (Serial.available() > 0) {
    inChar = Serial.read(); // Read a character
    nome[i] = inChar; // Store it
    i++; // Increment where to write next
    if(inChar == '\n')
      break;
    Serial.print("I received: ");
    Serial.println(inChar, DEC);
  }

  */

}

void loop() {

  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status

/*
    Serial.println("Digite uma frase para o chat");
    i = 0;
    while (Serial.available() > 0) {
      inChar = Serial.read(); // Read a character
      if (inChar = '\n')
        break;
      frase[i] = inChar; // Store it
      i++; // Increment where to write next
    }
*/

    HTTPClient http;    //Declare object of class HTTPClient

    http.begin("http://dev-thiagoaugustomartins.c9users.io:8080/mensagem");      //Specify request destination
    http.addHeader("Content-Type", "text/plain");  //Specify content-type header
    String mensagem = String(nome) + String(": ") + String(frase);
    int httpCode = http.POST(mensagem);  //Send the request
    String payload = http.getString();                  //Get the response payload

    Serial.println(httpCode);   //Print HTTP return code
    Serial.println(payload);    //Print request response payload

    http.end();  //Close connection

  } else {
    Serial.println("Error in WiFi connection");
  }

  delay(1000);  //Send a request every 30 seconds

}
