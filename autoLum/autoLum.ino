const int buttonPin = 2;
const int ledPinMain =  4;  // indicateur état système
// relais actionnant les LEDs
const int relayPin1 =  8;
const int relayPin2 =  9;
const int relayPin3 =  10;
const int relayPin4 =  11;

int photocellPin = 0; // the cell and 10K pulldown are connected to a0
int photocellReading; // the analog reading from the analog resistor divider

int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  pinMode(ledPinMain, OUTPUT);
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(relayPin3, OUTPUT);
  pinMode(relayPin4, OUTPUT);
  
  pinMode(buttonPin, INPUT);
  
  digitalWrite(ledPinMain, HIGH); // système actif par défaut
  // relais actionné par défaut pour éteindre les 4 LEDS
  digitalWrite(relayPin1, HIGH);
  digitalWrite(relayPin2, HIGH);
  digitalWrite(relayPin3, HIGH);
  digitalWrite(relayPin4, HIGH);
  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  photocellReading = analogRead(photocellPin);

  if (buttonState == HIGH) {
    if (digitalRead(ledPinMain) == HIGH) {  // cas contrôle manuel
      // indicateur éteins
      digitalWrite(ledPinMain, LOW);  
      // actionner les relais
      digitalWrite(relayPin1, LOW);
      digitalWrite(relayPin2, LOW);
      digitalWrite(relayPin3, LOW);
      digitalWrite(relayPin4, LOW);
    } else {
      // turn LED off:
      digitalWrite(ledPinMain, LOW);
    }
  }
  while (buttonState == LOW && digitalRead(ledPinMain) == HIGH) {  // contrôle automatique
    Serial.print("Analog reading = ");
    Serial.print(photocellReading); // valeur codée sur 10 bits (0-1023)
    
    if (photocellReading < 95) {
      digitalWrite(relayPin1, LOW);
      digitalWrite(relayPin2, LOW);
      digitalWrite(relayPin3, LOW);
      digitalWrite(relayPin4, LOW);
      Serial.println(" - Noir");
    } else if (photocellReading < 120) {
      digitalWrite(relayPin1, LOW);
      digitalWrite(relayPin2, LOW);
      digitalWrite(relayPin3, LOW);
      digitalWrite(relayPin4, HIGH);
      Serial.println(" - Sombre");
    } else if (photocellReading < 200) {
      digitalWrite(relayPin1, LOW);
      digitalWrite(relayPin2, LOW);
      digitalWrite(relayPin3, HIGH);
      digitalWrite(relayPin4, HIGH);
      Serial.println(" - Lumiere");
    } else if (photocellReading < 320) {
      digitalWrite(relayPin1, LOW);
      digitalWrite(relayPin2, HIGH);
      digitalWrite(relayPin3, HIGH);
      digitalWrite(relayPin4, HIGH);
      Serial.println(" - Lumineux");
    } else {
      Serial.println(" - Tres lumineux");
      digitalWrite(relayPin1, HIGH);
      digitalWrite(relayPin2, HIGH);
      digitalWrite(relayPin3, HIGH);
      digitalWrite(relayPin4, HIGH);
    }
    delay(250);
  }
}
