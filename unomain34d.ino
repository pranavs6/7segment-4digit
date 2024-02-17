const int ledPins1[] ={A0, 12, A2, A4, 2, A5, A3};
const int ledPins[] = {3,4,5,6,7,8,9};
const int bl = 10;
unsigned long previousMillis = 0;
int displayDuration = 1000;
int numberToDisplay = 0;
bool displayNumber = false;

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(ledPins1[i], OUTPUT);
    pinMode(ledPins[i], OUTPUT);
  }
  digitalWrite(bl, LOW); // Ensure the LED is initially off
  Serial.begin(9600);
}

void display(int x, int y) {
  int digitPatterns[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
  };
  for (int i = 0; i < 7; i++) {
    digitalWrite(ledPins[i], digitPatterns[x][i]);
    digitalWrite(ledPins1[i], digitPatterns[y][i]);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  // Blink pin 12 (bl) every second
  if (currentMillis - previousMillis >= 1000) {
    if (digitalRead(bl) == LOW) {
      digitalWrite(bl, HIGH);
    } else {
      digitalWrite(bl, LOW);
    }
    previousMillis = currentMillis;
  }

  if (Serial.available() >= 2) {
    // Read the two-digit number from serial input
    char input[5];
    Serial.readBytes(input, 5);
    int num = atoi(input);
    num=num%100;
    if (num >= 0 && num <= 99) {
      numberToDisplay = num;
      displayNumber = true;
    }
  }

  if (displayNumber) {
    int d1 = numberToDisplay / 10;
    int d2 = numberToDisplay % 10;
    display(d1, d2);
  }
}
