 /* Copyright 2021 OpenAnnePro community
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

 enum anne_pro_layers {
     BASE,
     FN1,
     FN2,
 };

 //TAP hold f1->f12 declarations
 enum {
     TH_F1,
     TH_F2,
     TH_F3,
     TH_F4,
     TH_F5,
     TH_F6,
     TH_F7,
     TH_F8,
     TH_F9,
     TH_F10,
     TH_F11,
     TH_F12,
 };

 enum custom_keycodes {
     WIN_LCK,
 };

 // clang-format off
 // Key symbols are based on QMK. Use them to remap your keyboard
 /*
  * Layer BASE
  * ,-----------------------------------------------------------------------------------------.
  * | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | FN1     |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN2  |  F12  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  * Layer TAP in BASE
  * ,-----------------------------------------------------------------------------------------.
  * |     | F1  |  F2 | F3  | F4  | F5  | F6  | F7  | F8  |  F9 | F10 | F11 | F12 |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |     |     |     |     |     |     |     |     |     |     |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  */
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [BASE] = LAYOUT_60_ansi( /* Base */
     KC_ESC,           TD(TH_F1),    TD(TH_F2),    TD(TH_F3),    TD(TH_F4),     TD(TH_F5),           TD(TH_F6),          TD(TH_F7), TD(TH_F8), TD(TH_F9),    TD(TH_F10),   TD(TH_F11),       TD(TH_F12),    KC_BSPC,
     KC_TAB,           KC_Q,         KC_W,         KC_E,         KC_R,          KC_T,                KC_Y,               KC_U,      KC_I,      KC_O,         KC_P,         KC_LBRC,          KC_RBRC,       KC_BSLS,
     MO(FN1),          KC_A,         KC_S,         KC_D,         KC_F,          KC_G,                KC_H,               KC_J,      KC_K,      KC_L,         KC_SCLN,      KC_QUOT,          KC_ENT,
     KC_LSFT,          KC_Z,         KC_X,         KC_C,         KC_V,          KC_B,                KC_N,               KC_M,      KC_COMM,   KC_DOT,       KC_SLSH,      KC_RSFT,
     KC_LCTL,          KC_LGUI,      KC_LALT,      KC_SPC,       KC_RALT,       MO(FN2),             KC_F12,             KC_RCTL
     ),
     /*
      * Layer FN1
      * ,-----------------------------------------------------------------------------------------.
      * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
      * |-----------------------------------------------------------------------------------------+
      * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
      * |-----------------------------------------------------------------------------------------+
      * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
      * |-----------------------------------------------------------------------------------------+
      * | Shift      |V-UP |V-DWN|MUUTE|  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
      * |-----------------------------------------------------------------------------------------+
      * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
      * \-----------------------------------------------------------------------------------------/
      *
      */
     [FN1] = LAYOUT_60_ansi( /* FN1 */
     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
     _______, KC_BTN1, KC_UP,   _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME, KC_END,  _______,
     _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______,
     _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, _______,
     _______, _______, _______,                            _______,                   _______, _______, MO(FN2), _______
     ),
     /*
      * Layer FN2
      * ,-----------------------------------------------------------------------------------------.
      * |  ~  | BT1 | BT2 | BT3 | BT4 | TOG | MOD |HUE+|HUE-| SAT+| SAT-| BRI+ | BRI- |    Bksp   |
      * |-----------------------------------------------------------------------------------------+
      * | Tab    | LKM | MUP | PKM |WHUP |  t  |  y  |  u  |SPI+ |SPI- | PS | HOME | END |   \    |
      * |-----------------------------------------------------------------------------------------+
      * | Esc     |MEFT |MOWN |MIGHT|WHOWN|  g  |  h  |  j  |  k  | lck | PGUP|PGDN |    Enter    |
      * |-----------------------------------------------------------------------------------------+
      * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  | ACR |INSRT| DEL |    Shift       |
      * |-----------------------------------------------------------------------------------------+
      * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
      * \-----------------------------------------------------------------------------------------/
      *
      */
     [FN2] = LAYOUT_60_ansi( /* FN2 */
     KC_AP2_BT_UNPAIR, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_AP_RGB_TOG,     KC_AP_RGB_MOD,  RGB_HUI, RGB_HUD, RGB_SAI,  RGB_SAD, KC_AP_RGB_VAI, KC_AP_RGB_VAD, KC_DEL,
     _______,          KC_BTN1,    KC_MS_U,    KC_BTN2,    KC_WH_U,    _______,           _______,        _______, RGB_SPI, RGB_SPD,  KC_PSCR,       KC_HOME,       KC_END,        _______,
     _______,          KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_WH_D,    _______,           _______,        _______, _______, WIN_LCK,  KC_PGUP,       KC_PGDN,       _______,
     _______,          _______,    _______,    _______,    _______,    _______,           _______,        _______, AC_TOGG, KC_INS,   KC_DEL,        _______,
     _______,          _______,    _______,                                               _______,                   _______,         MO(FN1),       MO(FN2),       _______
     ),
 };
 // clang-format on








 //BIG FUCK TAP HOLD FUNCTION IMPLEMENTARY
 typedef struct {
     uint16_t tap;
     uint16_t hold;
     uint16_t held;
 } tap_dance_tap_hold_t;

 bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     tap_dance_action_t *action;

     switch (keycode) {
         case TD(TH_F1):  // list all tap dance keycodes with tap-hold configurati
             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
             if (!record->event.pressed && action->state.count && !action->state.finished) {
                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                 tap_code16(tap_hold->tap);
             }; break;
         case TD(TH_F2):  // list all tap dance keycodes with tap-hold configurati
             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
             if (!record->event.pressed && action->state.count && !action->state.finished) {
                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                 tap_code16(tap_hold->tap);
             }; break;
         case TD(TH_F3):  // list all tap dance keycodes with tap-hold configurati
             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
             if (!record->event.pressed && action->state.count && !action->state.finished) {
                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                 tap_code16(tap_hold->tap);
             }; break;
         case TD(TH_F4):  // list all tap dance keycodes with tap-hold configurati
             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
             if (!record->event.pressed && action->state.count && !action->state.finished) {
                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                 tap_code16(tap_hold->tap);
             }; break;
         case TD(TH_F5):  // list all tap dance keycodes with tap-hold configurati
             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
             if (!record->event.pressed && action->state.count && !action->state.finished) {
                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                 tap_code16(tap_hold->tap);
             }; break;
         case TD(TH_F6):  // list all tap dance keycodes with tap-hold configurati
             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
             if (!record->event.pressed && action->state.count && !action->state.finished) {
                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                 tap_code16(tap_hold->tap);
             }; break;
         case TD(TH_F7):  // list all tap dance keycodes with tap-hold configurati
             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
             if (!record->event.pressed && action->state.count && !action->state.finished) {
                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                 tap_code16(tap_hold->tap);
             }; break;
         case TD(TH_F8):  // list all tap dance keycodes with tap-hold configurati
             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
             if (!record->event.pressed && action->state.count && !action->state.finished) {
                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                 tap_code16(tap_hold->tap);
             }; break;
         case TD(TH_F9):  // list all tap dance keycodes with tap-hold configurati
             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
             if (!record->event.pressed && action->state.count && !action->state.finished) {
                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                 tap_code16(tap_hold->tap);
             }; break;
         case TD(TH_F10):  // list all tap dance keycodes with tap-hold configurati
             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
             if (!record->event.pressed && action->state.count && !action->state.finished) {
                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                 tap_code16(tap_hold->tap);
             }; break;
         case TD(TH_F11):  // list all tap dance keycodes with tap-hold configurati
             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
             if (!record->event.pressed && action->state.count && !action->state.finished) {
                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                 tap_code16(tap_hold->tap);
             }; break;
         case TD(TH_F12):  // list all tap dance keycodes with tap-hold configurati
             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
             if (!record->event.pressed && action->state.count && !action->state.finished) {
                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                 tap_code16(tap_hold->tap);
             }; break;

     }


     switch (keycode) {
         case WIN_LCK:
             if (record->event.pressed) {
                 // when macro is pressed
                 SEND_STRING(SS_LGUI("l"));
             } else {
                 // when macro is released
             }
             break;
     }
     return true;
 }

 void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
     tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

     if (state->pressed) {
         if (state->count == 1
             #ifndef PERMISSIVE_HOLD
             && !state->interrupted
             #endif
         ) {
             register_code16(tap_hold->hold);
             tap_hold->held = tap_hold->hold;
         } else {
             register_code16(tap_hold->tap);
             tap_hold->held = tap_hold->tap;
         }
     }
 }

 void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
     tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

     if (tap_hold->held) {
         unregister_code16(tap_hold->held);
         tap_hold->held = 0;
     }
 }

 #define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
 { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

 tap_dance_action_t tap_dance_actions[] = {
     [TH_F1] = ACTION_TAP_DANCE_TAP_HOLD(KC_1, KC_F1),
     [TH_F2] = ACTION_TAP_DANCE_TAP_HOLD(KC_2, KC_F2),
     [TH_F3] = ACTION_TAP_DANCE_TAP_HOLD(KC_3, KC_F3),
     [TH_F4] = ACTION_TAP_DANCE_TAP_HOLD(KC_4, KC_F4),
     [TH_F5] = ACTION_TAP_DANCE_TAP_HOLD(KC_5, KC_F5),
     [TH_F6] = ACTION_TAP_DANCE_TAP_HOLD(KC_6, KC_F6),
     [TH_F7] = ACTION_TAP_DANCE_TAP_HOLD(KC_7, KC_F7),
     [TH_F8] = ACTION_TAP_DANCE_TAP_HOLD(KC_8, KC_F8),
     [TH_F9] = ACTION_TAP_DANCE_TAP_HOLD(KC_9, KC_F9),
     [TH_F10] = ACTION_TAP_DANCE_TAP_HOLD(KC_0, KC_F10),
     [TH_F11] = ACTION_TAP_DANCE_TAP_HOLD(KC_MINUS, KC_F11),
     [TH_F12] = ACTION_TAP_DANCE_TAP_HOLD(KC_EQUAL, KC_F12),
 };
 // END OF BIG FUCK TAP HOLD

 //MACRO IMPLEMENTARY



