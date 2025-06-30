#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

// Define button pins
const int buttonPin1 = 2; 
const int buttonPin2 = 3; 
// const int buttonPin3 = 4; 
// const int buttonPin4 = 5; 

// Define speaker pin
const int speakerPin = 9;

// Track button states
int lastButtonState1 = HIGH;  
int lastButtonState2 = HIGH;  
// int lastButtonState3 = HIGH;  
// int lastButtonState4 = HIGH;  

// Track playback states
bool isPlaying1 = false;
bool isPlaying2 = false;
// bool isPlaying3 = false;
// bool isPlaying4 = false;

TMRpcm tmrpcm;

void setup() {
  tmrpcm.speakerPin = speakerPin;
  Serial.begin(9600);
  
  // Initialize button pins as inputs
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  // pinMode(buttonPin3, INPUT_PULLUP);
  // pinMode(buttonPin4, INPUT_PULLUP);
  
  // Initialize SD card
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  }
  
  // Set volume
  tmrpcm.setVolume(5);
}

void loop() {
  // Read button states
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  // int buttonState3 = digitalRead(buttonPin3);
  // int buttonState4 = digitalRead(buttonPin4);

  // Handle button 1
  if (buttonState1 != lastButtonState1) {
    if (buttonState1 == LOW) {
      isPlaying1 = !isPlaying1;
      if (isPlaying1) {
        stopAllPlayback();
        tmrpcm.play("bowser.wav");
        Serial.println("Playing song1");
      } else {
        tmrpcm.stopPlayback();
        Serial.println("Stopped song1");
      }
    }
    delay(200); // Debounce delay
  }
  lastButtonState1 = buttonState1;

  // Handle button 2
  if (buttonState2 != lastButtonState2) {
    if (buttonState2 == LOW) {
      isPlaying2 = !isPlaying2;
      if (isPlaying2) {
        stopAllPlayback();
        tmrpcm.play("birds.wav");
        Serial.println("Playing song2");
      } else {
        tmrpcm.stopPlayback();
        Serial.println("Stopped song2");
      }
    }
    delay(200); // Debounce delay
  }
  lastButtonState2 = buttonState2;

  // // Handle button 3
  // if (buttonState3 != lastButtonState3) {
  //   if (buttonState3 == LOW) {
  //     isPlaying3 = !isPlaying3;
  //     if (isPlaying3) {
  //       stopAllPlayback();
  //       tmrpcm.play("song3.wav");
  //       Serial.println("Playing song3");
  //     } else {
  //       tmrpcm.stopPlayback();
  //       Serial.println("Stopped song3");
  //     }
  //   }
  //   delay(200); // Debounce delay
  // }
  // lastButtonState3 = buttonState3;

  // // Handle button 4
  // if (buttonState4 != lastButtonState4) {
  //   if (buttonState4 == LOW) {
  //     isPlaying4 = !isPlaying4;
  //     if (isPlaying4) {
  //       stopAllPlayback();
  //       tmrpcm.play("song4.wav");
  //       Serial.println("Playing song4");
  //     } else {
  //       tmrpcm.stopPlayback();
  //       Serial.println("Stopped song4");
  //     }
  //   }
  //   delay(200); // Debounce delay
  // }
  // lastButtonState4 = buttonState4;
}

// Function to stop all playback
void stopAllPlayback() {
  tmrpcm.stopPlayback();
  isPlaying1 = false;
  isPlaying2 = false;
  // isPlaying3 = false;
  // isPlaying4 = false;
}
