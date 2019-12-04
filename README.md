## Arch 40

![assembled_keyboard_1](https://i.imgur.com/mGvHH25.jpg)
![assembled_keyboard_2](https://i.imgur.com/xLTRGtF.jpg)

#### Case Renders:
![case_render_1](https://i.imgur.com/kMommcw.jpg)
![case_render_2](https://i.imgur.com/q0FfRJi.jpg)

#### Switch Plate:
![switch_plate_render](https://i.imgur.com/iD0z3CB.jpg)

## 40% Ortholinear + Columnar Stagger Keyboard
* Inspired by the Ergodox, Atreus, Iris, Corne, and probably others

* Design goals:
    * Efficiency and minimalism of a 40% form factor
    * Ergo benefits of tilted columnar stagger layout
    * Ease of use coming from ANSI style layouts
    * Simplicity of a non-split keyboard
    * Compatability with Ergodox style keysets

## Assembly:
* Now includes option to assemble using a PCB and microcontroller, or can be handwired with a microcontroller
    * **Huge thanks to [ibnuda](https://github.com/ibnuda) for designing the PCB!**
* Stacked acrylic layer case, acrylic/metal switch plate 
    * Layer dimensions and path lengths are outlined in `path_length.md`
* Files for laser cutting by Ponoko/other services in `./illustrator_files` and `./inkscape_files`
    * `./illustrator_files` includes case layer DXF files imported into Adobe Illustrator at 1:1 scale with units in millimeters
        * `final_cut_layout.eps` is Ponoko's P3 size template with case layers, **without plate**
            * Use this if you choose to go with a metal plate
        * `final_cut_layout_plate.eps` is Ponoko's P3 size template with case layers, **with plate**
            * Use this if you choose to go with an acrylic plate

    * `./inkscape_files` includes pdf-compatible Adobe `.ai` files as well as `.SVG` files of the case layers and plate
____

#### Component list:
* Acrylic case layers + plate
* PCB (optional, can be handwired as well)
    * Pro Micro (PCB is designed to use this microcontroller)
    * Teensy2.0 (if handwiring and not using PCB)
* (49) Cherry MX style switches
* (1) 2u Cherry style stabilizer
    * **Plate-mounted** works perfectly with 1.5mm metal switch plate
    * **Requires some modification** to work properly with 3.0mm acrylic plate
* Adafruit USB-mini breakout board (or a simple female USB-mini)
* WS2812B LED strips (optional)
* (49) 1N4184 diodes
* M2 Standoffs and screws
    * 5mm screw length
    * 10mm standoff length for use with a **1.5mm metal plate**
    * 12mm standoff length for use with a **3.0mm acrylic plate**

____

#### Case Stack Order:
1) `arch_40_case_layer0`
2) `arch_40_plate`
3) `arch_40_case_layer2-3`
4) `arch_40_case_layer2-3` (repeated)
5) `arch_40_case_layer4`
7) `arch_40_case_layer5`

* **Note:** `arch_40_case_layer2-3` is intended to be used twice, it contains the cutout for the USB connection

____

#### PCB:
* QMK files for PCB firmware in `./firmware/qmk_files`
* PCB can be made by sending the zipped gerber files in `./pcb/arch_40_rev1_gerber.zip` to a PCB prototyping service such as [JLCPCB](https://jlcpcb.com/quote#/?orderType=1&stencilWidth=100&stencilLength=100&stencilCounts=5&stencilLayer=2&stencilPly=1.6&steelmeshSellingPriceRecordNum=A8256537-5522-491C-965C-646F5842AEC9&purchaseNumber=)

* **Note**: The Pro Micro controller needs to be soldered onto the PCB as close as possible, need to remove the spacers on the headers of the Pro Micro

![pcb_image](https://i.imgur.com/BZhSc7j.jpg)

##### Pro Micro Pinout:
* Diode direction: row to column
* Column 0 = ESC key column
* Row 0 = QWERTY row
~~~
Rows:              Columns:                            LED:
-----------------------------------------------------------------
r0 : D3            c0 : F4         c6 : B2             vcc : VCC
r1 : D1            c1 : F5         c7 : B6             gnd : GND
r2 : D0            c2 : F6         c8 : B5            data : D2
r3 : D4            c3 : F7         c9 : B4
                   c4 : B1        c10 : E6
                   c5 : B3        c11 : D7
                                  c12 : C6
~~~
____

#### Handwiring:

##### Matrix:
![matrix](https://i.imgur.com/ph9qbX4.jpg)

##### Teensy2.0 Pinout:
* Diode direction: column to row
* Column 0 = ESC key column
* Row 0 = QWERTY row
~~~
Rows:               Columns:                            LED:
-----------------------------------------------------------------
r0 : F0             c0 : F7         c6 : C6             vcc : VCC
r1 : F1             c1 : B6         c7 : D3             gnd : GND
r2 : F4             c2 : B5         c8 : D2            data : B1 
r3 : F5             c3 : B4         c9 : D1
r4 : F6             c4 : D7        c10 : D0
                    c5 : C7        c11 : B7
~~~

##### Wiring Example:
![wiring_example_no_led](https://i.imgur.com/JU2SwzP.png)

##### Wiring Example With Underglow LED's:
![wiring_example_with_led](https://i.imgur.com/pITj7ql.jpg)

## Firmware Flashing:

#### PCB Builds:
* Linux:
    * The Pro Micro controller can be flashed with [avrdude](https://www.nongnu.org/avrdude/)
    * **Note:** Navigate to the `./firmware` directory of the repo where the `arch40firmware_pcb.hex` file is to flash
~~~
$ avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 flash:w:arch40firmware_pcb.hex
~~~
##### LED Backlighting:
* Default firmware `arch40firmware_pcb.hex` includes configuration for WS2812B LED backlighting strips
    * The data pin for the LED's is set to pin D2 on the Pro Micro
    * Default 12 LED quantity, 10 backlight brightness levels, variable color hue
    * To change the LED configuration, the `arch40firmware_pcb.json` file can be uploaded to [Keyboard Firmware Builder](https://kbfirmware.com/) and edited/recompiled as desired
____

#### Handwired Builds:
* Linux:
    * The Teensy2.0 controller can be flashed with the [teensy-loader-cli](https://www.pjrc.com/teensy/loader_cli.html)

~~~
$ teensy-loader-cli --mcu=atmega32u4 -w -v ./firmware/arch40firmware_hw.hex
~~~
* MacOS/Windows:
    * Can be flashed with the [Teensy Loader Application](https://www.pjrc.com/teensy/loader.html)
##### LED Backlighting:
* Default firmware `arch40firmware_hw.hex` includes configuration for WS2812B LED backlighting strips
    * The data pin for the LED's is set to pin B1 on the Teensy2.0

## Note:
* Kerf of plate and case layers is set to 0.15mm (typical for Ponoko/ Laserboost/ Lasergist)

## To-do:
* Add image of default keymap

###### Model was created in Solidworks, then exported as STL/DXF. Feel free to use/modify/redistribute.
