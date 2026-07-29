#include <Keypad.h>
#include <Adafruit_TinyUSB.h>
// Initialize the USB Consumer (Media) HID interface
Adafruit_USBD_HID usb_hid;

enum {
  RID_KEYBOARD = 1,
  RID_CONSUMER_CONTROL
};

uint8_t const desc_hid_report[] = {
  TUD_HID_REPORT_DESC_KEYBOARD( HID_REPORT_ID(RID_KEYBOARD) ),
  TUD_HID_REPORT_DESC_CONSUMER( HID_REPORT_ID(RID_CONSUMER_CONTROL) )
};

static hid_keyboard_report_t pressed_keys = { 0 };

// ---------- Keypad ----------
const byte ROWS = 4;
const byte COLS = 5;

uint8_t keys[ROWS][COLS] = {
  { HID_KEY_NUM_LOCK, HID_KEY_KEYPAD_7, HID_KEY_KEYPAD_4, HID_KEY_KEYPAD_1, HID_KEY_KEYPAD_0 },
  { HID_KEY_KEYPAD_DIVIDE, HID_KEY_KEYPAD_8, HID_KEY_KEYPAD_5, HID_KEY_KEYPAD_2, ' ' },
  { HID_KEY_KEYPAD_MULTIPLY, HID_KEY_KEYPAD_9, HID_KEY_KEYPAD_6, HID_KEY_KEYPAD_3, HID_KEY_KEYPAD_DECIMAL },
  { HID_KEY_KEYPAD_SUBTRACT, HID_KEY_KEYPAD_ADD, ' ', HID_KEY_KEYPAD_ENTER, ' ' },
};

byte columnPins[COLS] = { D4, D5, D6, D9, D10 };
byte rowPins[ROWS] = { D3, D2, D1, D0 };

Keypad customKeypad = Keypad(
  makeKeymap(keys),
  rowPins,
  columnPins,
  ROWS,
  COLS);

// ---------- Rotary encoder ----------
const int encoderPinA = D8; 
const int encoderPinB = D7;  

int lastA = 0;
int lastB = 0;

void setup() {

  Serial.begin(9600);

  // Encoder inputs with pull-ups
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);

  lastA = digitalRead(encoderPinA);
  lastB = digitalRead(encoderPinB);

  usb_hid.setPollInterval(2);
  usb_hid.setReportDescriptor(desc_hid_report, sizeof(desc_hid_report));
  usb_hid.begin();
}

void loop() {

  if (customKeypad.getKeys()) {
    Serial.println("pressed");
    for (int i = 0; i < 10; i++) {
      if (customKeypad.key[i].stateChanged) 
      {
        if (customKeypad.key[i].kstate == PRESSED) 
        {
          
          uint8_t targetKey = customKeypad.key[i].kchar;

          for (int i = 0; i < 6; i++) 
          {
            if (pressed_keys.keycode[i] == 0) { // Find an empty slot
              pressed_keys.keycode[i] = targetKey; // Add the key
              Serial.println(targetKey);
              break;
            }
          }
          usb_hid.sendReport(RID_KEYBOARD, &pressed_keys, sizeof(pressed_keys));
        }         
        else if (customKeypad.key[i].kstate == RELEASED) 
        {
          uint8_t targetKey = customKeypad.key[i].kchar;

          for (int i = 0; i < 6; i++) 
          {
            if (pressed_keys.keycode[i] == targetKey) 
            {
              pressed_keys.keycode[i] = 0; // Clear ONLY this key slot
              break;
            }
          }
          usb_hid.sendReport(RID_KEYBOARD, &pressed_keys, sizeof(pressed_keys));

        }
      }
    }
  }

  // ----- Encoder handling -----
  int a = digitalRead(encoderPinA);
  int b = digitalRead(encoderPinB);

  // Only act when A changes; B tells direction
  if (a != lastA) {
    if (a == b) {
      // One direction: send e.g. Arrow Up
      uint16_t keycode = HID_USAGE_CONSUMER_VOLUME_INCREMENT;
      usb_hid.sendReport16(RID_CONSUMER_CONTROL, keycode);
      usb_hid.sendReport16(RID_CONSUMER_CONTROL, 0); 

    } else {
      // Other direction: send e.g. Arrow Down
      uint16_t keycode = HID_USAGE_CONSUMER_VOLUME_DECREMENT;
      usb_hid.sendReport16(RID_CONSUMER_CONTROL, keycode);
      usb_hid.sendReport16(RID_CONSUMER_CONTROL, 0); 
    }
  }
  lastA = a;
  lastB = b;
}
