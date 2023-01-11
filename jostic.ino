// MOHSEN SALARI 9711312

#define COMMUNICATION_SPEED 9600                                                  // communication speed for Serial port
#define SCALE 5.115                                                               // set a range for analog read data
#define MIN_RANGE 100                                                             // set ofset for min range output

// X parametr variables
int8_t xPin = A3;
uint16_t xParamet = 0;

// Y parametr variables
int8_t yPin = A4;
uint16_t yParamet = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(COMMUNICATION_SPEED);                                             // start Serial communication
  Serial.println("STARTING PROGRAM");
  // initall value analog variable
  xParamet = analogRead(xPin);
  yParamet = analogRead(yPin);
}

void loop() {
  if (xParamet != analogRead(xPin) || yParamet != analogRead(yPin)) {           // if change value of each analog pins loging last data
    // update the input pin
    xParamet = analogRead(xPin);
    yParamet = analogRead(yPin);
    // loging read data
    Serial.println("(" + String((int)(xParamet / SCALE ) - MIN_RANGE) + ", " + String((int)(yParamet / SCALE ) - MIN_RANGE) + ")");
  }

}
