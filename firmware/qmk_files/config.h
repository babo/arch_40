#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */

#define VENDOR_ID       0x6131 // rand
#define PRODUCT_ID      0xC6AF // rand
#define DEVICE_VER      0x0001
#define MANUFACTURER    jp
#define PRODUCT         Arch40
#define DESCRIPTION     QMK keyboard firmware for Arch40

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 13

/* number of backlight levels */
#define BACKLIGHT_LEVELS 10

/* define led underglow pin */
#define BACKLIGHT_PIN D2

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
/* #define LOCKING_SUPPORT_ENABLE */
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
