#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

const int buttonPin = 2;    // Button pin
int buttonState = 0;        // Current state of the button
int lastButtonState = 0;    // Previous state of the button
bool isPlaying = false;     // Flag to track if audio is playing

TMRpcm tmrpcm;

void setup()
{
  tmrpcm.speakerPin = 9;
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  
  if (!SD.begin(SD_ChipSelectPin))
  {
    Serial.println("SD fail");
    return;
  }
  
  tmrpcm.setVolume(5);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Check if the button is pressed
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      // Toggle the playing state
      isPlaying = !isPlaying;
      if (isPlaying) {
        // Start playing the audio
        tmrpcm.play("Bowser.wav");
        Serial.println("Playing Bowser");
      } else {
        // Stop playing the audio
        tmrpcm.stopPlayback();
        Serial.println("Stopped");
      }
    }
    delay(50); // Debounce delay
  }
  
  lastButtonState = buttonState;

  // Additional audio handling if needed
  if (isPlaying) {
    // Check if current track has finished playing
    if (!tmrpcm.isPlaying()) {
      // Play the next track or restart the current one
      tmrpcm.play("birds.wav");
      Serial.println("Playing birds");
    }
  }

    if (buttonState == LOW) {
    Serial.println("Button pressed");
  } else {
    Serial.println("Button released");
  }

  delay(1000);  // Debounce delay
}
