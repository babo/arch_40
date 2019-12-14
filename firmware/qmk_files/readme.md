## Compiling:
`$ make arch40:default` in `qmk_firmware` build environment

## Flashing:
~~~
$ avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 flash:w:arch40_promicro_default.hex
~~~

## Notes:
* `info.json` is the raw data from [Keyboard Layout Editor](http://www.keyboard-layout-editor.com/) converted by [QMK Firmware converter](https://qmk.fm/converter/)
