#include <ESP8266WiFi.h>

/* Configuration de la partie wifi avec un ESP 12F. 
   Un ESP 12F peut être configuré de deux façons: 
   - En mode Access Point, ce mode permet à la carte ESP de générer
   son propre réseau wifi avec son identifiant et son mot de passe (Ce mode
   ne permet pas d'aller sur internet, il n'y a aucune connexion au web avec ce mode).
  
  - En mode Station ou Client,ce mode permet à l'ESP de se connecter à un point 
   accès(Téléphone, box ...). L'ESP se comporte comme un ordinateur qui serait 
   connecté à une box. Si la box est réliée à internet, alors l'ESP
   peut accéder à internet. 
 
  Dans le cadre de notre projet, nous avons besion d'internet pour pouvoir 
  récuperer les données, du coup j'ai opté pour le MODE CLIENT.
 */

const char* ssid = "iPhone de Channel"; // Nom du WiFi
const char* password = "46qp8m9av3y0b"; // Mot de passe du WiFi

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  delay(10);
  
 // Mengatur WiFi ----------------------------------------------------------
  Serial.println();
  Serial.print("Configuration du point  accès...");
  
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
   }
  
  Serial.println("");
  Serial.println("WiFi connecté");
   
 // Start the server -------------------------------------------------------
  server.begin();
  Serial.println("Serveur");
   
 // Print the IP address ---------------------------------------------------
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
