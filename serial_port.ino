// MOHSEN SALARI 9711312

#define REQUEST_MESSAGE "Enter your name \n"
#define RESPOND_MESSAGE "Salam bar shoma,"
#define UPLOAD_SPEED 9600
#define LINE_SIZE 255
#define CHAR_TERMINATOR '\n'

bool showMessage;
//+1 for handle null
char buffer[LINE_SIZE + 1];

void setup()
{
  Serial.begin(UPLOAD_SPEED);
  showMessage = true;
}

void loop()
{
  if (showMessage)
  {
    Serial.print(REQUEST_MESSAGE);
    showMessage = false;
  }
  if (Serial.available())
  {
    size_t size = Serial.readBytesUntil(CHAR_TERMINATOR, buffer, LINE_SIZE);
    buffer[size] = '\0';
    Serial.print(RESPOND_MESSAGE);
    Serial.println(buffer);
    showMessage = true;
  }
}
