## Compiling:
`$ make arch40:default` in `qmk_firmware` build environment

## Flashing:
~~~
$ avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 flash:w:arch40_promicro_default.hex
~~~

## Notes:
* `info.json` files is not formatted like typical qmk json layout files, its taken from [Keyboard Layout Editor](http://www.keyboard-layout-editor.com/) 
