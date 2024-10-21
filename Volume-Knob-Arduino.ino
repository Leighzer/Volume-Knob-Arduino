#include <HID-Project.h>

const int buttonUpPin = 5; 
const int buttonDownPin = 3;

int buttonUpState = 0;
int buttonDownState = 0;

void setup() {
  Consumer.begin();
  
  pinMode(buttonUpPin, INPUT);
  pinMode(buttonDownPin, INPUT);
}

void loop() {
  buttonUpState = digitalRead(buttonUpPin);
  buttonDownState = digitalRead(buttonDownPin);
  
  if (buttonUpState == HIGH) {
    Consumer.write(MEDIA_VOLUME_UP);
  }
  
  if (buttonDownState == HIGH) {
    Consumer.write(MEDIA_VOLUME_DOWN);
  }

  Serial.println("buttonDown " + String(buttonDownState) + " buttonUp " + String(buttonUpState));
  
  delay(50);
}
