#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"
// const int buttonPin = 2;

// int buttonState = 0;

TMRpcm tmrpcm;

void setup()
{
tmrpcm.speakerPin=9;
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
tmrpcm.setVolume(5);
// pinMode(buttonPin, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
// tmrpcm.play("birds.wav");
// Serial.println("birds");

// delay (5000); // play the music for the amount of time you want

// tmrpcm.play("ziguezon.wav");
// Serial.println("ziguezon");

// delay (5000);
// buttonState = digitalRead(buttonPin);
//  if (buttonState == HIGH) {
//     // turn LED on:
//     digitalWrite(ledPin, HIGH);
//   } else {
//     // turn LED off:
//     digitalWrite(ledPin, LOW);

tmrpcm.play("Bowser.wav");
Serial.println("Bowser");

delay (5000);

tmrpcm.play("Pis_Bowser.wav");
Serial.println("Pis Bowser");

delay (2000);


}
