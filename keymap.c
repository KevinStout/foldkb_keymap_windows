
// To compile this file navigate to it in the terminal and run 'qmk compile'
// To compile this file navigate to it in the terminal and run 'qmk compile'
// To compile this file navigate to it in the terminal and run 'qmk compile'

// We can flash each side of the keyboard with different keymaps.
// This will allow us to have a Mac and Windows layout on the same keyboard. 

/* Copyright 2022 Forrest Cahoon <forrest.cahoon@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Milliseconds the backlight is off (or on) when blinking to show
// caps lock is on. In other words, half the time of a full blink cycle.
#define CAPS_LOCK_BLINK_MS 350

#include QMK_KEYBOARD_H

enum layer {
    _QWERTY,
    _PG, // for "programming"
    _MS, // for "mouse"
    _VIM, // for "vim macros"
    _CON, // for "console"
};

enum custom_keycodes {
    PG_ARRO = SAFE_RANGE,
    PG_BANG,
    PG_ENDC,
    PG_EQEQ,
    PG_EQL,
    PG_LBRK,
    PG_LPAR,
    PG_MINS,
    PG_NEEQ,
    PG_TWOSLASH,
    PG_RBRK,
    PG_RPAR,
    PG_SLAS,
    PG_VBAR,
    MS_BTN,
    PG_FARRO,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
  // ┌────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┐        ┌────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬──────────┐
      KC_MCTL,          KC_ESC,          KC_GRV,          KC_1,            KC_2,            KC_3,            KC_4,            KC_5,                     KC_6,            KC_7,             KC_8,           KC_9,            KC_0,            KC_MINS,         KC_EQL,          KC_BSPC,
  // ├────────────────┼───┬────────────┴────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼──────────┤
      KC_HOME,              KC_TAB,                       KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,                     KC_Y,            KC_U,             KC_I,           KC_O,            KC_P,            KC_LBRC,         KC_RBRC,         KC_BSLS,
  // ├────────────────┼───┼─────────────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┴──────────┤
      TG(_VIM),             KC_CAPS,                      KC_A,            KC_S,            KC_D,            LT(_VIM, KC_F),  KC_G,                     LT(_MS, KC_H),   LT(_PG, KC_J),    LT(_CON, KC_K), KC_L,           KC_SCLN,         KC_QUOT,         KC_ENT,
  // ├────────────────┼───┴─────────────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┴───────────┬───────────┬───┘
      TG(_PG),              KC_LSFT,                      KC_Z,            KC_X,            KC_C,            KC_V,            KC_B,                     KC_N,            KC_M,             KC_COMM,        KC_DOT,          KC_SLSH,         KC_RSFT,                    KC_UP,
  // ├────────────────┼───┬──────────────────────────┬──┴──────────────┬─┴────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┴─┬──────────────┴──────────────┬─┴────────────────┼────────────────┴─┬─────────────────┬────────┴───────────┤
      TG(_MS),              KC_DEL,                       KC_RCTL,         KC_LOPT,         KC_RCMD,         KC_BSPC,         KC_BSPC,                  SFT_T(KC_SPC),    SFT_T(KC_SPC),               LT(_PG, KC_EQL),   KC_LEFT,           KC_RIGHT,                KC_DOWN
  // └────────────────┴───┴──────────────────────────┴─────────────────┴──────────────────┴────────────────┴────────────────┴────────────────┘        └──────────────────┴─────────────────────────────┴──────────────────┴──────────────────┴─────────────────┴────────────────────┘
    ),
    [_PG] = LAYOUT(
  // ┌────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┐        ┌────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬──────────┐
      KC_MCTL,          _______,         _______,         KC_1,            KC_2,            KC_LBRC,         KC_RBRC,         KC_5,                     KC_F6,           KC_F7,           KC_F8,           KC_F9,           KC_F10,          KC_F11,          KC_F12,          _______,
  // ├────────────────┼───┬────────────┴────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼──────────┤
      RGB_TOG,               _______,                     _______,         PG_SLAS,         PG_LPAR,         PG_RPAR,         PG_TWOSLASH,              _______,         KC_HOME,         KC_UP,           KC_PGUP,         KC_INS,          _______,         _______,         _______,
  // ├────────────────┼───┼─────────────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┴──────────┤
      RGB_MOD,               _______,                     PG_ENDC,         PG_VBAR,         PG_LBRK,         PG_RBRK,         KC_MINS,                  _______,         _______,         _______,         _______,         _______,         _______,         _______,
  // ├────────────────┼───┴─────────────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┴───────────┬───────────┬───┘
      _______,            _______,                        _______,         PG_FARRO,        KC_LT,           KC_GT,           PG_BANG,                  _______,         KC_END,          KC_DOWN,          KC_PGDN,        KC_DEL,          _______,                     _______,
  // ├────────────────┼───┬──────────────────────────┬──┴──────────────┬─┴────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┴─┬──────────────┴──────────────┬─┴────────────────┼────────────────┴─┬─────────────────┬────────┴───────────┤
      _______,              _______,                   _______,          _______,           KC_PLUS,         PG_ARRO,         PG_ARRO,                  KC_LSFT,           KC_LSFT,                      _______,           _______,           _______,                   _______
  // └────────────────┴───┴──────────────────────────┴─────────────────┴──────────────────┴────────────────┴────────────────┴────────────────┘        └──────────────────┴─────────────────────────────┴──────────────────┴──────────────────┴─────────────────┴────────────────────┘
    ),
    [_MS] = LAYOUT(
  // ┌────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┐        ┌────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬──────────┐
      _______,       LOPT(LCMD(KC_ESC)), _______,         KC_BTN5,         KC_BTN4,         KC_BTN3,         KC_BTN2,         KC_BTN1,                  KC_ACL0,         KC_ACL1,         KC_ACL2,         KC_ACL0,         RGB_M_TW,        RGB_M_G,         RGB_M_R,         RGB_M_P,
  // ├────────────────┼───┬────────────┴────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼──────────┤
      _______,              _______,                      _______,         _______,         KC_MS_U,         KC_BTN4,         KC_BTN5,                  KC_ACL0,         KC_WH_D,         KC_WH_D,         KC_WH_R,         RGB_HUI,         RGB_HUD,         RGB_SAI,         RGB_SAD,
  // ├────────────────┼───┼─────────────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┴──────────┤
      _______,              _______,                      _______,         KC_MS_L,         KC_MS_D,         KC_MS_R,         KC_WH_D,                  _______,         KC_WH_U,         KC_WH_U,         KC_WH_L,         _______,         _______,         _______,
  // ├────────────────┼───┴─────────────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┴───────────┬───────────┬───┘
      _______,          _______,                          _______,         _______,         _______,         _______,         KC_WH_U,                  _______,         KC_ACL0,         KC_ACL1,         KC_ACL2,         _______,         _______,                     RGB_VAI,
  // ├────────────────┼───┬──────────────────────────┬──┴──────────────┬─┴────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┴─┬──────────────┴──────────────┬─┴────────────────┼────────────────┴─┬─────────────────┬────────┴───────────┤
      _______,              _______,                   _______,          _______,           _______,         KC_BTN1,         KC_BTN1,                  KC_BTN2,           KC_BTN2,                      _______,           _______,           _______,                   RGB_VAD
  // └────────────────┴───┴──────────────────────────┴─────────────────┴──────────────────┴────────────────┴────────────────┴────────────────┘        └──────────────────┴─────────────────────────────┴──────────────────┴──────────────────┴─────────────────┴────────────────────┘
    ),
    [_VIM] = LAYOUT(
  // ┌────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┐        ┌────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬──────────┐
      _______,          _______,         _______,         _______,         _______,         _______,         _______,         _______,            RCTL(LCMD(KC_RIGHT)),  _______,     LCMD(LSFT(KC_BSLS)), _______,         _______,         _______,         _______,         _______,
  // ├────────────────┼───┬────────────┴────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼──────────┤
      _______,              _______,                      _______,         _______,         _______,         _______,         _______,           LCMD(LSFT(KC_LEFT)), LOPT(LSFT(KC_DOWN)), LOPT(LSFT(KC_UP)), LCMD(LSFT(KC_RIGHT)), LCMD(LSFT(KC_P)), _______,   _______,         _______,
  // ├────────────────┼───┼─────────────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┴──────────┤
      _______,              _______,                      _______,         _______,         _______,         _______,         _______,                  KC_LEFT,         KC_DOWN,         KC_UP,           KC_RIGHT,        _______,         _______,         _______,
  // ├────────────────┼───┴─────────────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┴───────────┬───────────┬───┘
      _______,          _______,                          _______,         _______,         _______,         _______,         _______,                  LCMD(KC_LEFT),   LOPT(KC_LEFT),   LOPT(KC_RIGHT),  LCMD(KC_RIGHT),  _______,         _______,                     _______,
  // ├────────────────┼───┬──────────────────────────┬──┴──────────────┬─┴────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┴─┬──────────────┴──────────────┬─┴────────────────┼────────────────┴─┬─────────────────┬────────┴───────────┤
      _______,              _______,                   _______,          _______,           _______,         LCTL(KC_GRV),    LCTL(KC_GRV),             KC_LSFT,           KC_LSFT,                      _______,           _______,           _______,                   _______
  // └────────────────┴───┴──────────────────────────┴─────────────────┴──────────────────┴────────────────┴────────────────┴────────────────┘        └──────────────────┴─────────────────────────────┴──────────────────┴──────────────────┴─────────────────┴────────────────────┘
    ),
    [_CON] = LAYOUT(
  // ┌────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┐        ┌────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬──────────┐
      _______,          _______,         _______,         LCTL(KC_1),      LCTL(KC_2),      LCTL(KC_3),      LCTL(KC_4),      LCTL(KC_5),               LCTL(KC_6),      LCTL(KC_7),      LCTL(KC_8),      LCTL(KC_9),      LCTL(KC_0),      _______,         _______,         _______,
  // ├────────────────┼───┬────────────┴────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼──────────┤
      _______,              _______,                      _______,         _______,         _______,         LCMD(KC_1),      LCMD(KC_2),               LCMD(KC_1),      LCMD(KC_2),      _______,         _______,         _______,         _______,         _______,         _______,
  // ├────────────────┼───┼─────────────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┴──────────┤
      _______,              _______,                      _______,         _______,         _______,         _______,         LCTL(LSFT(KC_TAB)),       _______,         _______,         _______,         _______,         _______,         _______,          _______,
  // ├────────────────┼───┴─────────────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┴───────────┬───────────┬───┘
      _______,          _______,                          _______,         _______,         _______,   RCTL(LCMD(KC_LEFT)),   RCTL(LCMD(KC_RIGHT)),     _______,         _______,         _______,         _______,         _______,         _______,                     _______,
  // ├────────────────┼───┬──────────────────────────┬──┴──────────────┬─┴────────────────┼────────────────┼────────────────┼────────────────┤        ├────────────────┴─┬──────────────┴──────────────┬─┴────────────────┼────────────────┴─┬─────────────────┬────────┴───────────┤
      _______,              _______,                   _______,          _______,           _______,         LCTL(KC_GRV),    LCTL(KC_GRV),             _______,           _______,                      _______,           _______,           _______,                   _______
  // └────────────────┴───┴──────────────────────────┴─────────────────┴──────────────────┴────────────────┴────────────────┴────────────────┘        └──────────────────┴─────────────────────────────┴──────────────────┴──────────────────┴─────────────────┴────────────────────┘
    ),
  };
// clang-format on

const key_override_t pg_lbrk_none  = ko_make_with_layers_and_negmods(0, PG_LBRK, KC_LEFT_CURLY_BRACE, ~0, ~0);
const key_override_t pg_lbrk_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_LBRK, KC_LEFT_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_lpar_none  = ko_make_with_layers_and_negmods(0, PG_LPAR, KC_LEFT_PAREN, ~0, ~0);
const key_override_t pg_lpar_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_LPAR, KC_LEFT_ANGLE_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_rbrk_none  = ko_make_with_layers_and_negmods(0, PG_RBRK, KC_RIGHT_CURLY_BRACE, ~0, ~0);
const key_override_t pg_rbrk_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_RBRK, KC_RIGHT_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_rpar_none  = ko_make_with_layers_and_negmods(0, PG_RPAR, KC_RIGHT_PAREN, ~0, ~0);
const key_override_t pg_rpar_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_RPAR, KC_RIGHT_ANGLE_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_slas_none  = ko_make_with_layers_and_negmods(0, PG_SLAS, KC_SLASH, ~0, ~0);
const key_override_t pg_slas_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_SLAS, KC_BACKSLASH, ~0, ~MOD_MASK_SHIFT);

const key_override_t ms_btn_none  = ko_make_with_layers_and_negmods(0, MS_BTN, KC_MS_BTN1, ~0, ~0);
const key_override_t ms_btn_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, MS_BTN, KC_MS_BTN2, ~0, ~MOD_MASK_SHIFT);

// clang-format off
const key_override_t **key_overrides = (const key_override_t *[]){
    &pg_lbrk_none, &pg_lbrk_shift,
    &pg_lpar_none, &pg_lpar_shift,
    &pg_rbrk_none, &pg_rbrk_shift,
    &pg_rpar_none, &pg_rpar_shift,
    &pg_slas_none, &pg_slas_shift,
    &ms_btn_none, &ms_btn_shift,
    NULL};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t std_mods     = get_mods();
    uint8_t oneshot_mods = get_oneshot_mods();
    uint8_t all_mods     = std_mods | oneshot_mods;
    bool    shift_on     = all_mods & MOD_MASK_SHIFT;
    bool    ctrl_on      = all_mods & MOD_MASK_CTRL;

    // None of our special keycodes use ALT or GUI mods (so far), so we
    // check once here at the top and let other code handle it if any of
    // these are set.
    if (all_mods & (MOD_MASK_ALT | MOD_MASK_GUI)) return true;

    switch (keycode) {
        case KC_CAPS:
            // On caps lock release, if caps lock just got turned off, ensure that
            // backlight is enabled when it stops blinking.
            if (!record->event.pressed) {
                if (!host_keyboard_led_state().caps_lock) {
                    backlight_enable();
                    // In this case, we want to continue processing
                    return true;
                }
            }
            break;
        case PG_ARRO:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (shift_on) {
                    if (!ctrl_on) SEND_STRING(" ");
                    SEND_STRING("->");
                    if (!ctrl_on) SEND_STRING(" ");
                } else {
                    if (ctrl_on) SEND_STRING(" ");
                    SEND_STRING(" => ");
                    if (ctrl_on) SEND_STRING(" ");
                }
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_BANG:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (shift_on) {
                    if (!ctrl_on) SEND_STRING(" ");
                    SEND_STRING("*");
                    if (!ctrl_on) SEND_STRING(" ");
                } else {
                    if (ctrl_on) SEND_STRING(" ");
                    SEND_STRING("!");
                }
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_ENDC:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                SEND_STRING(SS_TAP(X_END));
                if (!shift_on) SEND_STRING(";");
                if (!ctrl_on) SEND_STRING(SS_TAP(X_ENTER));
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_EQEQ:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (!ctrl_on) SEND_STRING(" ");
                shift_on ? SEND_STRING("==") : SEND_STRING("===");
                if (!ctrl_on) SEND_STRING(" ");
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_EQL:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (!ctrl_on) SEND_STRING(" ");
                shift_on ? SEND_STRING("+") : SEND_STRING("=");
                if (!ctrl_on) SEND_STRING(" ");
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_MINS:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (shift_on) {
                    if (ctrl_on) SEND_STRING(" ");
                    SEND_STRING("_");
                    if (ctrl_on) SEND_STRING(" ");
                } else {
                    if (!ctrl_on) SEND_STRING(" ");
                    SEND_STRING("-");
                    if (!ctrl_on) SEND_STRING(" ");
                }
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_NEEQ:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (!ctrl_on) SEND_STRING(" ");
                shift_on ? SEND_STRING("!=") : SEND_STRING("!==");
                if (!ctrl_on) SEND_STRING(" ");
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_TWOSLASH:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (!ctrl_on) SEND_STRING(" ");
                SEND_STRING("^?");
                if (!ctrl_on) SEND_STRING(" ");
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_VBAR:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (!ctrl_on) SEND_STRING(" ");
                shift_on ? SEND_STRING("&") : SEND_STRING("|");
                if (!ctrl_on) SEND_STRING(" ");
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
        case PG_FARRO:
            if (record->event.pressed) {
                SEND_STRING("() => ");
                return false;
            }
            break;
    }
    return true;
}

//layer lighting

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  //uint8_t hue = rgblight_get_hue();
    uint8_t sat = rgblight_get_sat();
    uint8_t val = rgblight_get_val();
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _QWERTY:
            rgblight_sethsv(201, sat, val);
            break;
        case _PG:
            rgblight_sethsv(21, sat, val);
            break;
        case _MS:
            rgblight_sethsv(127, sat, val);
            break;
        case _VIM:
            rgblight_sethsv(85, sat, val);
            break;
        case _CON:
            rgblight_sethsv(50, sat, val);
            break;
        default:
            rgblight_sethsv(0, sat, val);
            break;
    }
}

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_PURPLE);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif

extern rgblight_config_t rgblight_config;

uint32_t mode;
uint16_t hue;
uint8_t sat;
uint8_t val;

void matrix_init_user(void)
{
    rgblight_sethsv(255, 255, 255);
}

void led_set_user(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    mode = rgblight_get_mode();
    hue = rgblight_get_hue();
    sat = rgblight_get_sat();
    val = rgblight_get_val();

    rgblight_mode_noeeprom(1);
    rgblight_setrgb(255, 255, 255  );
  } else {
      rgb_matrix_indicators_advanced_user(0, 255);
//    rgblight_mode(mode);
//    rgblight_sethsv(hue, sat, val);
  }
}
