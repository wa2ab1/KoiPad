# KoiPad: External Numpad Companion with Rotary Encoder

KoiPad is an external numpad companion with a large rotary encoder, designed for a fun desk setup with fast numeric input.

<img width="1496" height="1082" alt="Numpad" src="https://github.com/user-attachments/assets/bdf5354d-26ef-4ee9-bae1-92bcd929a596" />

With its large 4 cm rotary encoder shaped like its eyeball and a USB-C cable inpsired by a fishing line, KoiPad adds a playful companion to your desk.

This macropad was made because I loved the shape of the "koi" from Hack Club's Fallout and wanted to make something more unique than just another macropad. When brainstorming case ideas, the ideas for the usb-c cable to be the fishing line at its mouth and the giant knob just made total sense with the fish case idea. With my current keyboard being a TKL layout, I'm missing a numpad as well, so this keypad will help give me easier access to crunching numbers than before.

## Features:

- 17-key standard numpad layout and num lock
- EC-11 rotary encoder for volume adjustment
- Seeeduino XIAO RP2040
- Standard MX switches with 2u PCB-mount stabilizers
- USB-C connection

<img width="1410" height="2000" alt="KoiPad Zine (2)" src="https://github.com/user-attachments/assets/96cf9644-28c7-4cc8-b16b-be12a3121514" />

## Case

3D print the top plate and bottom case separately, and secure them together using 5 mm M2 screws on the corners. The screws will need to be manually threaded into the bottom case.

<img width="1546" height="958" alt="image" src="https://github.com/user-attachments/assets/7bac565d-0e0a-4d3c-a7bb-4563f757e6ec" />

### Painting:

The top plate is printed in one color only (red), with the outlines raised for easy brush painting. You'll need 3 colors (yellow, white, black) and red (optional). You can mix the paints for beige and red. First paint the yellow and beige areas, then go over the black outlines and white eye area for a clean finish. You may want to use masking tape to protect the sides of the outlines for a cleaner look. 

<img width="1514" height="777" alt="image" src="https://github.com/user-attachments/assets/ac82af13-850f-4225-85b0-2abcc08542d0" />

## PCB

The KoiPad utilizes standard keyboard switches with 2u PCB mounted stabilizers for the larger keys. After soldering your diodes and switches and snapping on the stabilizers, screw the pcb with 4mm standoffs of M2 size through the countersinks on the bottom of the case and the designated holes on the pcb. Screw these in before screwing on the top plate, and avoid rescrewing the top plate unless necessary to prevent stripping.

<p float="left">
  <img width="500" height="862" alt="Screenshot 2026-05-28 011109" src="https://github.com/user-attachments/assets/4e64b532-c3f5-40b8-8ca6-b40e3e70ea48" />
  <img width="520" height="1016" alt="image" src="https://github.com/user-attachments/assets/d9ef42e6-e7d0-4063-8d78-f52a8d0c0a03"  />
  <img width="692" height="1195" alt="image" src="https://github.com/user-attachments/assets/a23d0284-706b-44ae-819e-3ff8287791ef" />
</p>


## Schematic

<img width="1671" height="981" alt="image" src="https://github.com/user-attachments/assets/0f3dc1c9-72ef-4d11-a9e1-02e66cbeecf0" />

## Firmware
The rotary encoder is configured to control system volume up/down, and the keypad includes Enter and Num Lock mappings. You may need to adjust these key codes if your environment handles these special keys differently.

### Libraries used: 
- Keypad
- Keyboard (support for Seed XIAO RP2040 Arduino core)

### Instructions:
- Find the board manager and look for "Seed SAMD Boards"
- Select XIAO RP2040 and upload the koipad.ino file.

## Credits
3D placeholder/reference models used in renders were sourced from other creators. Final hardware uses real components.

Keycap, switches, stabilizers, standoffs, encoder, and Seeeduino XIAO footprints and 3d models from [ScottoKeebs](https://github.com/joe-scotto/scottokeebs)

[Screws](https://grabcad.com/library/metric-screws-from-m2-x-2-5-to-m2-x-20-1)

[USB-C cable](https://grabcad.com/library/usb-usb-cable-1)

