#include <Keypad.h>

const byte ROWS = 3; // Three rows
const byte COLS = 3; // Three columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','*'}
};
// Connect keypad ROW0, ROW1, ROW2 to these Arduino pins.
byte rowPins[ROWS] = { 5, 6, 7 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 0, 1, 2 }; 

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#define ledpin 13

void setup()
{
  pinMode(ledpin,OUTPUT);
  digitalWrite(ledpin, HIGH);
  Serial.begin(9600);
}

void loop()
{
  char key = kpd.getKey();
  if(key)  // Check for a valid key.
  {
    switch (key)
    {
      case '*':
        digitalWrite(ledpin, LOW);
        break;
      default:
        Serial.println(key);
    }
  }
}
