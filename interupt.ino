#define   LED_PIN           LED_BUILTIN                           // pin connected to LED
#define   INTERRUPT_MODE    RISING                                // interrupt triggered mode
#define   PRESS_TIME        500                                   // time to wait in milli secs
#define   BUTTON_PIN        2                                     // external interrupt pin
bool      led_status =      LOW;                                  // start LED state
bool      pushed_button =   false;
uint32_t  start_push_ime = 0;
uint32_t  finish_push_time = 0;
void push_button_interrupt()
{
  pushed_button = true;
}
void setup() {
  // set pins mode 
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  // attachInterrupt 
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), push_button_interrupt, INTERRUPT_MODE);
}
void loop() {
  if (pushed_button) {
    start_push_ime = millis();                                    // start timer
    while (digitalRead(BUTTON_PIN) == HIGH) {                     // wait while pushed button
    }
    finish_push_time = millis();                                  // button released // stop timer
    if (((finish_push_time - start_push_ime) > PRESS_TIME)) {     // check push time
      led_status = !led_status;                                   // change pin state
      digitalWrite(LED_PIN, led_status);                          // write new pin satae
    }
    pushed_button = false;                                        // reset state
  }
}
