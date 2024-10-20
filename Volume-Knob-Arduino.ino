#include <HID-Project.h>

int potPin = A0;    // Pin connected to potentiometer
int potValue = 0;   // Variable to store potentiometer value (0-1023)
int lastVolume = 0; // Previous volume value
int volume = 0;     // Variable to store scaled volume (0-255)

void setup() {
  Consumer.begin();
  Serial.begin(9600);  // Initialize serial communication for debugging
}

void loop() {
  potValue = analogRead(potPin);            // Read potentiometer value
  volume = map(potValue, 0, 1023, 0, 255);  // Scale to 0-255 for volume control
  Serial.println(volume);                   // Print volume for debugging
  
  // If volume has changed by more than 5 units, simulate key press
  if (abs(volume - lastVolume) > 4) {
    if (volume > lastVolume) {
      Consumer.write(MEDIA_VOLUME_UP);  // Simulate volume up key
      Consumer.write(MEDIA_VOLUME_UP);  // Simulate volume up key
    } else if (volume < lastVolume) {
      Consumer.write(MEDIA_VOLUME_DOWN); // Simulate volume down key
      Consumer.write(MEDIA_VOLUME_DOWN); // Simulate volume down key
    }
    lastVolume = volume;  // Update lastVolume
  }

  delay(100);  // Short delay for stability
}