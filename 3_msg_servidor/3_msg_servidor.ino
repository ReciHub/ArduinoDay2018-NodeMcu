	
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

char nome[] = "";
char read;
int index = 0;
char frase[] = "";

void setup() {
 
  Serial.begin(115200);                                  //Serial connection
  WiFi.begin("yourSSID", "yourPASS");   //WiFi connection
 
  Serial.println("Qual o seu nome?");

  while(Serial.available() > 0){
      inChar = Serial.read(); // Read a character
          inData[index] = inChar; // Store it
          index++; // Increment where to write next
  }

  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
 
    delay(500);
    Serial.println("Waiting for connection");
 
  }
 
}
 
void loop() {
 
 if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
   
   Serial.println("Digite uma frase para o chat");

    while(Serial.available() > 0){
      inChar = Serial.read(); // Read a character
      if(inChar =`'\n')
      break;
          frase[index] = inChar; // Store it
          index++; // Increment where to write next
     }


   HTTPClient http;    //Declare object of class HTTPClient
 
   http.begin("http://192.168.1.88:8085/hello");      //Specify request destination
   http.addHeader("Content-Type", "text/plain");  //Specify content-type header
 
   int httpCode = http.POST(ñome + ": "+ frase);   //Send the request
   String payload = http.getString();                  //Get the response payload
 
   Serial.println(httpCode);   //Print HTTP return code
   Serial.println(payload);    //Print request response payload
 
   http.end();  //Close connection
 
 }else{
 
    Serial.println("Error in WiFi connection");   
 
 }
 
  delay(30000);  //Send a request every 30 seconds
 
}