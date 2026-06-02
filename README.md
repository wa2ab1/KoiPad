# KoiPad: External Numpad Companion with Rotary Encoder

KoiPad is your perfect external numpad companion to a numpad-less keyboard setup. With its large 4 cm rotary encoder shaped like its eyeball and a fishing line made of USB-C cable, you'll never have to work alone at your desk ever again! Use the numpad to crunch in numbers for projects and calculations!

<img width="1496" height="1082" alt="Numpad" src="https://github.com/user-attachments/assets/bdf5354d-26ef-4ee9-bae1-92bcd929a596" />

https://a360.co/41LIHIl
Fusion 360 3D case model file

## Features:

- 17-key numpad layout
- EC-11 rotary encoder
- Seeduino Xiao RP2040
- Standard MX switches with 2u PCB-mount stabilizers
- USB-C connection
  
## Case

The case should be 3d printed from PLA using a standard 0.3 mm nozzle. I use 10% gyroid infill. The top plate and bottom case are printed separately in red and secured together using 5 mm M2 screws on the corners. The screws will need to be manually threaded into the bottom case. The knob is also printed separately and should be printed upside down wth the top part on the printing surface.


<img width="1546" height="958" alt="image" src="https://github.com/user-attachments/assets/7bac565d-0e0a-4d3c-a7bb-4563f757e6ec" />


The top plate is printed in one color only (red), with the outlines raised for easy brush or spray painting. First paint the yellow and beige areas, then go over the black outlines and white eye area for a clean finish. You may want to use masking tape to protect the sides of the outlines for a cleaner look.  

<img width="1514" height="777" alt="image" src="https://github.com/user-attachments/assets/ac82af13-850f-4225-85b0-2abcc08542d0" />

## PCB

The koipad utilizes standard keyboard switches with 2u PCB mounted stabilizers for the larger keys. The pcb is suspended on 4mm standoffs of M2 size which screw in through the countersinks on the bottom of the case and the top of the pcb. Screw these in before screwing on the top plate which should stay permanently closed to avoid stripping the screw.

<img width="500" height="862" alt="Screenshot 2026-05-28 011109" src="https://github.com/user-attachments/assets/4e64b532-c3f5-40b8-8ca6-b40e3e70ea48" />

<img width="692" height="1195" alt="image" src="https://github.com/user-attachments/assets/a23d0284-706b-44ae-819e-3ff8287791ef" />


## Schematic

<img width="732" height="461" alt="Screenshot 2026-05-28 011202" src="https://github.com/user-attachments/assets/634f3a05-77e9-48e8-bd05-be496041839f" />

## Firmware
The seeduino should be loaded with the attached code using a software program like Arduino IDE, using the Seeed XIAO RP2040 board.
