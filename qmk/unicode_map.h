
#include QMK_KEYBOARD_H

/*
 * remember rules.mk: UNICODEMAP_ENABLE = yes
 * remember config..h: #define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
 */

enum unicode_names {
	KC_ae, KC_AE,
	KC_oe, KC_OE,
	KC_aa, KC_AA,
	KC_ny, KC_NY
};

// U+2134 => 0x2134. it is not utf-8 hex
const uint32_t unicode_map[] PROGMEM = {
	[KC_ae] = 0x00E6,
	[KC_AE] = 0x00E6,
	[KC_oe] = 0x00F8,
	[KC_OE] = 0x00D8,
	[KC_aa] = 0x00E5,
	[KC_AA] = 0x00C5,
	[KC_ny] = 0x00F1,
	[KC_NY] = 0x00D1,
};

