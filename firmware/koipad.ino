#include <Keypad.h>
#include <Keyboard.h>

// ---------- Keypad ----------
const byte ROWS = 5;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'X', '/', '*', '-'},
  {'7', '8', '9', '+'},
  {'4', '5', '6', ' '},
  {'1', '2', '3', 'E'},
  {'0', ',', ' ', ' '}
};

byte rowPins[ROWS]    = {5, 6, 7, 10, 11};
byte columnPins[COLS] = {4, 3, 2, 1};

Keypad customKeypad = Keypad(
  makeKeymap(keys),
  rowPins,
  columnPins,
  ROWS,
  COLS
);

// ---------- Rotary encoder ----------
const int encoderPinA = 9;   // R0 -> A
const int encoderPinB = 8;   // R1 -> B

int lastA = 0;
int lastB = 0;

void setup() {
  Keyboard.begin();

  // Encoder inputs with pull-ups
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);

  lastA = digitalRead(encoderPinA);
  lastB = digitalRead(encoderPinB);
}

void loop() {
  // ----- Keypad handling -----
  char customKey = customKeypad.getKey();

  if (customKey) {
    if (customKey == 'E') {
      Keyboard.write(KEY_RETURN);
    } 
    else if (customKey == 'X')
    {
      Keyboard.write(KEY_NUM_LOCK);
    }
    else if (customKey != ' ') {
      Keyboard.write(customKey);
    }
  }

  // ----- Encoder handling -----
  int a = digitalRead(encoderPinA);
  int b = digitalRead(encoderPinB);

  // Only act when A changes; B tells direction
  if (a != lastA) {
    if (a == b) {
      // One direction: send e.g. Arrow Up
      Keyboard.write(KEY_MEDIA_VOLUME_UP);
    } else {
      // Other direction: send e.g. Arrow Down
      Keyboard.write(KEY_MEDIA_VOLUME_DOWN);
    }
  }

  lastA = a;
  lastB = b;
}
