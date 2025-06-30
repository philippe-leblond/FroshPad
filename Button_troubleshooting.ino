const int buttonPin = 2;  // Button pin
int buttonState = 0;      // Variable to hold the button state

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);  // Enable internal pull-up resistor
}

void loop() {
  buttonState = digitalRead(buttonPin);  // Read the button state
  Serial.println(buttonState);           // Print button state for debugging

  // Check if the button is pressed (LOW state due to pull-up resistor)
  if (buttonState == LOW) {
    Serial.println("Button pressed");
  } else {
    Serial.println("Button released");
  }

  delay(50);  // Debounce delay
}
