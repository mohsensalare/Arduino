// initial ower variable
#define pin1 12                           // define pin to input
#define pin2 11                           // define pin to pullup_input
#define led_pin 8                         // define LED pin
uint8_t pin1_state = false;               // define variable and start state for pin1
uint8_t pin2_state = false;               // define variable and start state for pin2
uint8_t led_state = false;                // define variable and start state for LED
uint32_t previousMillis = 0;              // will store last time LED was updated
const uint32_t wait_time = 330;           // interval at which to blink (milliseconds)
unsigned long currentMillis;

void setup() {
  // setup device
  pinMode(pin2, INPUT);                   // set pin to input
  digitalWrite(pin2, HIGH);               // turn on pullup resistors
  pinMode(pin1, INPUT);                   // set pin to input
  pinMode(led_pin, OUTPUT);               // set pin to output
}


void loop() {
  // logic of program 
  if (digitalRead(pin1) == HIGH) {        // check if the input is HIGH (button released)
    while(digitalRead(pin1) == HIGH);     // wait while pushed button
    pin1_state  = !pin1_state;
  } 
  
  if (digitalRead(pin2) == LOW) {         // check if the input is HIGH (button released)
    while(digitalRead(pin2) == LOW);      // wait while pushed button
    pin2_state  = !pin2_state;
  }
  currentMillis = millis();               // update run time
  if (pin2_state and pin1_state){
    digitalWrite(led_pin, HIGH);          // turn ON LED
  }
  else if (currentMillis - previousMillis >= wait_time){
        previousMillis = currentMillis;
        led_state = !led_state;
        digitalWrite(led_pin, led_state); // change state LED
  }
}
