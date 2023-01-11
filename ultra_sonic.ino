// MOHSEN SALARI 9711312
#define COMMUNICATION_SPEED 9600
#define ECHO_PIN 2
#define TRIGN_PIN 3
#define CHANGE_SENSE 50
#define MESSAGE_START "STARTING PROGRAM"
#define INTERVAL 200
#define TIME_TRIGGER 10
#define EXPRIMENT_NUM 57.68

uint32_t last_read = 0;

void setup()
{
    Serial.begin(COMMUNICATION_SPEED);
    Serial.println(MESSAGE_START);
    pinMode(TRIGN_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    //for reset
    digitalWrite(TRIGN_PIN, LOW);
}

void loop()
{
    uint32_t last_value = readSensor();
    if (abs(last_read - last_value) > CHANGE_SENSE)
    {
        updateData(last_value);
    }
    delay(INTERVAL);
}

uint32_t readSensor()
{

    digitalWrite(TRIGN_PIN, HIGH);
    delayMicroseconds(TIME_TRIGGER);
    digitalWrite(TRIGN_PIN, LOW);
    return pulseIn(ECHO_PIN, HIGH);
}

void updateData(int lastVlue)
{
    last_read = lastVlue;
    Serial.println((uint32_t)(last_read / EXPRIMENT_NUM));
}
