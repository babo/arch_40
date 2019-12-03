## Arch 40
[Project Github Page](https://github.com/jacekplonowski/arch_40)

![assembled_keyboard_2](https://i.imgur.com/xLTRGtF.jpg)
____
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

![pcb_image](https://i.imgur.com/BZhSc7j.jpg)

## Compiling:
~~~
$ make arch40:default
~~~

## Flashing:
~~~
$ avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 flash:w:arch40_promicro_default.hex
~~~
