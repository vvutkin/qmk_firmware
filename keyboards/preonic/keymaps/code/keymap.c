/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "mousekey.h"
#include "muse.h"
#include "color.h"

enum preonic_layers { _QWERTY, _DVORAK, _LOWER, _RAISE, _MOUSE, _ADJUST };

enum preonic_keycodes { QWERTY = SAFE_RANGE, DVORAK, LOWER, RAISE, MOUSE, BACKLIT, M_MS_UL, M_MS_UR, M_MS_DL, M_MS_DR};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  = + |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | Super| Alt  | Alt  | Lower|    Space    | Raise| Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_preonic_grid(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_EQL ,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
        KC_LCTL, KC_LGUI, KC_LALT, KC_RALT, LOWER  , KC_SPC , KC_SPC , RAISE  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
        ),

    /* Dvorak
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  = + |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | Enter|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | Super| Alt  | Alt  | Lower|    Space    |Raise | Left | Down |  Up  | Right|
     * `-----------------------------------------------------------------------------------'
     */
    [_DVORAK] = LAYOUT_preonic_grid(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_EQL ,
        KC_TAB , KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   , KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_BSPC,
        KC_ESC , KC_A   , KC_O   , KC_E   , KC_U   , KC_I   , KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_SLSH,
        KC_LSFT, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   , KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , KC_ENT ,
        KC_LCTL, KC_LGUI, KC_LALT, KC_RALT, LOWER  , KC_SPC , KC_SPC , RAISE  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
        ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      | NmLk |  /   |  *   |  -   |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  F1  |  F2  |  F3  |  F4  |      |      | pad7 | pad8 | pad9 |  +   |  Del |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F5  |  F6  |  F7  |  F8  |      |      | pad4 | pad5 | pad6 |  +   |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F9  |  F10 |  F11 |  F12 |      |      | pad1 | pad2 | pad3 | Enter|      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | pad0 |  .   | Enter|      |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_preonic_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NUM , KC_PSLS, KC_PAST, KC_PMNS, _______,
        XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , XXXXXXX, XXXXXXX, KC_P7  , KC_P8  , KC_P9  , KC_PPLS, KC_DEL ,
        _______, KC_F5  , KC_F6  , KC_F7  , KC_F8 ,C(KC_INS), XXXXXXX, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, XXXXXXX,
        _______, KC_F9  , KC_F10 , KC_F11 , KC_F12,S(KC_INS), XXXXXXX, KC_P1  , KC_P2  , KC_P3  , KC_PENT, XXXXXXX,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_P0  , KC_PDOT, KC_PENT, XXXXXXX
        ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  = + |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   `  |   <  |   >  |   {  |   }  |      |      |   &  |   |  |   ^  |   !  | Del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |   (  |   )  |   [  |   ]  |      |      |   +  |   -  |  = + |   :  |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |   \  |   _  |      |      |   *  |   /  |   %  |   ?  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Home | Pg Dn| Pg Up| End  |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_preonic_grid(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_EQL ,
        KC_TILD, KC_LT  , KC_GT  , KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, KC_AMPR, KC_PIPE, KC_CIRC, KC_EXLM, KC_DEL ,
        _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, KC_PLUS, KC_MINS, KC_EQL , KC_COLN, XXXXXXX,
        _______, _______, XXXXXXX, KC_BSLS, KC_UNDS, XXXXXXX, XXXXXXX, KC_ASTR, KC_SLSH, KC_PERC, KC_QUES, XXXXXXX,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
        ),

    /* Mouse
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      | MS UL| MS U | MS UR|MS WHL|MS WHR|
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |MS BT5|MS BT4|MS BT3|MS BT2|      |      | MS L |      | MS R |      |MS WHU|
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      | MS DL| MS D | MS DR| MS U |MS WHD|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |   MS BT 1   |      |      | MS L | MS D | MS R |
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_preonic_grid(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, M_MS_UL, KC_MS_U, M_MS_UR, KC_WH_L, KC_WH_R,
        _______, KC_BTN5, KC_BTN4, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX, KC_MS_L, XXXXXXX, KC_MS_R, XXXXXXX, KC_WH_U,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, M_MS_DL, KC_MS_D, M_MS_DR, XXXXXXX, KC_WH_D,
        _______, _______, _______, _______, _______, KC_BTN1, KC_BTN1, _______, _______, _______, _______, _______
        ),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | Reset| Debug|      |      |      |      |      |      |      |      |  Del |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |Aud cy|Aud on|AudOff|      |      |Dvorak|Qwerty|      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|Mouse | Prev | Br - | Br + | Next |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Brite|RGBtgl|      |      |      |  Caps Lock  |      | Mute | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_preonic_grid(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
        _______, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL ,
        _______, _______, _______, AU_ON  , AU_OFF , _______, _______, DVORAK , QWERTY , _______, _______, _______,
        _______, _______, _______, MU_ON  , MU_OFF , MI_ON  , MI_OFF , MOUSE  , KC_MPRV, KC_BRID, KC_BRIU, KC_MNXT,
        BACKLIT, RGB_TOG, _______, _______, _______, KC_CAPS, KC_CAPS, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
        )};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case MOUSE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MOUSE);
            }
            return false;
            break;
#ifdef MOUSEKEY_ENABLE

        case M_MS_UL:
            if (record->event.pressed) {
              mousekey_on(KC_MS_UP);
              mousekey_on(KC_MS_LEFT);
            } else {
              mousekey_off(KC_MS_UP);
              mousekey_off(KC_MS_LEFT);
            }
            break;

        case M_MS_UR:
            if (record->event.pressed) {
              mousekey_on(KC_MS_UP);
              mousekey_on(KC_MS_RIGHT);
            } else {
              mousekey_off(KC_MS_UP);
              mousekey_off(KC_MS_RIGHT);
            }
            break;

        case M_MS_DL:
            if (record->event.pressed) {
              mousekey_on(KC_MS_DOWN);
              mousekey_on(KC_MS_LEFT);
            } else {
              mousekey_off(KC_MS_DOWN);
              mousekey_off(KC_MS_LEFT);
            }
            break;

        case M_MS_DR:
            if (record->event.pressed) {
              mousekey_on(KC_MS_DOWN);
              mousekey_on(KC_MS_RIGHT);
            } else {
              mousekey_off(KC_MS_DOWN);
              mousekey_off(KC_MS_RIGHT);
            }
            break;
#endif /* MOUSEKEY_ENABLE */

        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
                backlight_step();
#endif
#ifdef RGBLIGHT_ENABLE
                rgblight_step();
#endif
#ifdef __AVR__
                writePinLow(E6);
#endif
            } else {
                unregister_code(KC_RSFT);
#ifdef __AVR__
                writePinHigh(E6);
#endif
            }
            return false;
            break;
    }
    return true;
};

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo += 1;
            } else {
                muse_tempo -= 1;
            }
        }
    } else {
        if (clockwise) {
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        } else {
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        }
    }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}

#ifdef RGBLIGHT_ENABLE

void rgblight_set_hsv_and_mode(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode) {
    rgblight_sethsv_noeeprom(hue, sat, val);
    wait_us(175); // Add a slight delay between color and mode to ensure it's processed correctly
    rgblight_mode_noeeprom(mode);
}

// Set RGBLIGHT state depending on layer
void rgblight_change(uint8_t this_layer) {
    switch (this_layer) {
        case _DVORAK:
            rgblight_sethsv_noeeprom(HSV_MAGENTA);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 1);
            break;
        case _QWERTY:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 1);
            break;
        case _LOWER:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT + 1);
            rgblight_sethsv_noeeprom(HSV_GOLD);
            break;
        case _RAISE:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 1);
            rgblight_sethsv_noeeprom(HSV_CYAN);
            break;
        case _ADJUST:
            rgblight_sethsv_noeeprom(HSV_RED);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        default:
            rgblight_sethsv_noeeprom(0, 255, 255);
            break;
    }
}

#endif

__attribute__ ((weak)) layer_state_t layer_state_set_keymap (layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = layer_state_set_keymap (state);
#ifdef RGBLIGHT_ENABLE
    // Change RGB lighting depending on the last layer activated
    // rgblight_change( get_highest_layer(state) );
    switch (get_highest_layer(state)) {
        case _LOWER:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT + 1);
            rgblight_sethsv_noeeprom(HSV_GOLD);
            break;
        case _RAISE:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 1);
            rgblight_sethsv_noeeprom(HSV_CYAN);
            break;
        case _ADJUST:
            rgblight_sethsv_noeeprom(HSV_RED);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        default:
            switch (get_highest_layer(layer_state_set_keymap(default_layer_state))) {
                case _DVORAK:
                    rgblight_sethsv_noeeprom(HSV_MAGENTA);
                    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 1);
                    break;
                case _QWERTY:
                    rgblight_sethsv_noeeprom(HSV_GREEN);
                    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 1);
                    break;
                default:
                    // rgblight_sethsv_noeeprom_cyan();
                    break;
            }
            //   state == _MODS ? rgblight_mode_noeeprom(2) : rgblight_mode_noeeprom(1); // if _MODS layer is on, then breath to denote it
            break;
    }
#endif
    return state;
}
