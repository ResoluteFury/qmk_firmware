#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _COLEMAK 0
#define _QWERTY 1
#define _DVORAK 2

#define _LOWER 3
#define _RAISE 4
#define _FUNCTION 15
#define _ADJUST 16

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  DVORAK,
  LOWER,
  RAISE,
  FUNCTION,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define FTAB LT(_FUNCTION, KC_TAB)
#define CTRLC RCTL(KC_C)
#define CTRLV RCTL(KC_V)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Colemak
   * ,------------------------------------------------.        ,-------+-----------------------------------------.
   * | Esc  |   Q  |   W  |   F  |   P  |   G  | Home |        |  Copy |   J  |   L  |   U  |   Y  |   ;  |   \  |
   * |------+------+------+------+------+-------------|        |-------|------+------+------+------+------+------|
   * | FTAB |   A  |   R  |   S  |   T  |   D  | End  |        | Paste |   H  |   N  |   E  |   I  |   O  |   '  |
   * |------+------+------+------+------+------.------|        .-------,------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  /      /        \       \   K  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------+ Bksp /        \ Space \------+------+------+------+------+------|
   * | Ctrl |  GUI | Alt  | Ent  |      / Lower/      /        \       \ Raise\      | Left |  Up  | Down |Right |
   * `----------------------------      `-----'`------/        '-------`-------      `---------------------------'
   */
  [_COLEMAK] = LAYOUT( \
    KC_ESC,        KC_Q,    KC_W,    KC_F,   KC_P, KC_G,       KC_HOME,      CTRLC,  KC_J,       KC_L, KC_U,    KC_Y,   KC_SCLN, KC_BSLS, \
    FTAB,          KC_A,    KC_R,    KC_S,   KC_T, KC_D,       KC_END,       CTRLV,  KC_H,       KC_N, KC_E,    KC_I,   KC_O,    KC_QUOT, \
    OSM(MOD_LSFT), KC_Z,    KC_X,    KC_C,   KC_V, KC_B,       KC_BSPC,      KC_SPC, KC_K,       KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
    KC_LCTL,       KC_LGUI, KC_LALT, KC_ENT,       TT(_LOWER), KC_BSPC,      KC_SPC, TT(_RAISE),       KC_LEFT, KC_UP,  KC_DOWN, KC_RGHT  \
  ),
  
  /* QWERTY
   * ,------------------------------------------------.        ,-------+-----------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  | Home |        |  Copy |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+-------------|        |-------|------+------+------+------+------+------|
   * | FTAB |   A  |   S  |   D  |   F  |   G  | End  |        | Paste |   H  |   J  |   K  |   L  |   ;  |   '  |
   * |------+------+------+------+------+------.------|        .-------,------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  /      /        \       \   N  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------+ Bksp /        \ Space \------+------+------+------+------+------|
   * | Ctrl |  GUI | Alt  | Ent  |      / Lower/      /        \       \ Raise\      | Left |  Up  | Down |Right |
   * `----------------------------      `-----'`------/        '-------`-------      `---------------------------'
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,        KC_Q,    KC_W,    KC_F,   KC_P, KC_G,       KC_HOME,      CTRLC,  KC_J,       KC_L, KC_U,    KC_Y,   KC_SCLN, KC_BSLS, \
    FTAB,          KC_A,    KC_R,    KC_S,   KC_T, KC_D,       KC_END,       CTRLV,  KC_H,       KC_N, KC_E,    KC_I,   KC_O,    KC_QUOT, \
    OSM(MOD_LSFT), KC_Z,    KC_X,    KC_C,   KC_V, KC_B,       KC_BSPC,      KC_SPC, KC_K,       KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
    KC_LCTL,       KC_LGUI, KC_LALT, KC_ENT,       TT(_LOWER), KC_BSPC,      KC_SPC, TT(_RAISE),       KC_LEFT, KC_UP,  KC_DOWN, KC_RGHT  \
  ),

  /* DVORAK
   * ,------------------------------------------------.        ,-------+-----------------------------------------.
   * | Esc  |   '  |   ,  |   .  |   P  |   Y  | Home |        |  Copy |   F  |   G  |   C  |   R  |   L  |   /  |
   * |------+------+------+------+------+-------------|        |-------|------+------+------+------+------+------|
   * | FTAB |   A  |   O  |   E  |   U  |   I  | End  |        | Paste |   D  |   H  |   T  |   N  |   S  |   -  |
   * |------+------+------+------+------+------.------|        .-------,------+------+------+------+------+------|
   * | Shift|   ;  |   Q  |   J  |   K  |   X  /      /        \       \   B  |   M  |   W  |   V  |   Z  |Shift |
   * |------+------+------+------+------+------+ Bksp /        \ Space \------+------+------+------+------+------|
   * | Ctrl |  GUI | Alt  | Ent  |      / Lower/      /        \       \ Raise\      | Left |  Up  | Down |Right |
   * `----------------------------      `-----'`------/        '-------`-------      `---------------------------'
   */
  [_DVORAK] = LAYOUT( \
    KC_ESC,        KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y,       KC_HOME,      CTRLC,  KC_F,       KC_G, KC_C,    KC_R,  KC_L,    KC_SLSH, \
    FTAB,          KC_A,    KC_O,    KC_E,   KC_U, KC_I,       KC_END,       CTRLV,  KC_D,       KC_H, KC_T,    KC_N,  KC_S,    KC_MINS, \
    OSM(MOD_LSFT), KC_SCLN, KC_Q,    KC_J,   KC_K, KC_X,       KC_BSPC,      KC_SPC, KC_B,       KC_M, KC_W,    KC_V,  KC_Z,    KC_RSFT, \
    KC_LCTL,       KC_LGUI, KC_LALT, KC_ENT,       TT(_LOWER), KC_BSPC,      KC_SPC, TT(_RAISE),       KC_LEFT, KC_UP, KC_DOWN, KC_RGHT  \
  ),

  /* LOWER
   * ,------------------------------------------------.        ,-------+-----------------------------------------.
   * |      |   !  |   @  |   #  |   $  |   %  |      |        |       |   ^  |   &  |   *  |   (  |   )  |  Del |
   * |------+------+------+------+------+-------------|        |-------|------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |        |       |  F6  |   _  |   +  |   {  |   }  |      |
   * |------+------+------+------+------+------.------|        .-------,------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 /      /        \       \  F7  |   ~  |   `  | Mute | Ctrl/|      |
   * |------+------+------+------+------+------+      /        \       \------+------+------+------+------+------|
   * |      |      |      |      |      /      /      /        \       \ADJUST\      | Next | Vol+ | Vol- | Play |
   * `----------------------------      `-----'`------/        '-------`-------      `---------------------------'
   */

  [_LOWER] = LAYOUT( \
    _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,    _______,      _______, KC_CIRC,    KC_AMPR,   KC_ASTR, KC_LPRN, KC_RPRN,       KC_DEL,  \
    _______, KC_F1,   KC_F2, KC_F3,   KC_F4,  KC_F5,      _______,      _______, KC_F6,      KC_UNDS,   KC_PLUS, KC_LCBR, KC_RCBR,       _______, \
    _______, KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11,     _______,      _______, KC_F12,     S(KC_GRV), KC_GRV,  KC_MUTE, RCTL(KC_BSLS), _______, \
    _______, _______, _______, _______,       _______,    _______,      _______, MO(_ADJUST),           KC_MNXT, KC_VOLU, KC_VOLD,       KC_MPLY  \
  ),

  /* RAISE
   * ,------------------------------------------------.        ,-------+-----------------------------------------.
   * |      |   1  |   2  |   3  |   4  |   5  |      |        |       |   6  |   7  |   8  |   9  |   0  |  Del |
   * |------+------+------+------+------+-------------|        |-------|------+------+------+------+------+------|
   * |      |   4  |   5  |   6  |   +  |   *  |      |        |       |      |   -  |   =  |   [  |   ]  |      |
   * |------+------+------+------+------+------.------|        .-------,------+------+------+------+------+------|
   * |      |   7  |   8  |   9  |   -  |   /  |      /        \       \      |ISO # |ISO / | Mute | Ctrl/|      |
   * |------+------+------+------+------+------+      /        \       \------+------+------+------+------+------|
   * |      |   ,  |   0  |   .  |      /ADJUST|      /        \       \      \      | Next | Vol+ | Vol- | Play |
   * `----------------------------      `-----'`------/        '-------`-------      `---------------------------'
   */

  [_RAISE] = LAYOUT( \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        _______,      _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          KC_DEL,  \
    _______, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_ASTR,     _______,      _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,       _______, \
    _______, KC_7,    KC_8,    KC_9,    KC_MINS, KC_SLSH,     _______,      _______, _______, KC_NUHS, KC_NUBS, KC_MUTE, RCTL(KC_BSLS), _______, \
    _______, _______, _______, _______,          MO(_ADJUST), _______,      _______, _______,          KC_MNXT, KC_VOLU, KC_VOLD,       KC_MPLY  \
  ),

  /* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Taskmg|      |      |      |      |      |      |      |RGBVAI|RGBSAI|RGBHUI|caltde|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |_COLEMAK|    |      |      |      |      |      |      |RGBVAD|RGBSAD|RGBHUD|RGBTOG|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |_DVORAK|     |      |      |      |      |      |      |      |      |      |BLSTEP|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |_QWERTY|     |      |      |      |      |      |      |      |      |      | RESET|
 * `-----------------------------------------------------------------------------------'
 */

  [_ADJUST] = LAYOUT( \
    TSKMGR,  _______, _______, _______, _______, _______, _______,      _______, _______, _______, RGB_VAI, RGB_SAI, RGB_HUI, CALTDEL,  \
    COLEMAK, _______, _______, _______, _______, _______, _______,      _______, _______, _______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG, \
    DVORAK,  _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, BL_STEP, \
    QWERTY,  _______, _______, _______,          _______, _______,      _______, _______,          _______, _______, _______, RESET  \
  ),

  /* Function
 * ,-----------------------------------------------------------------------------------.
 * | Caps |      |      |      |      |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

  [_FUNCTION] = LAYOUT( \
    KC_CAPS, _______, _______, _______, _______, _______, _______,      _______, _______, _______, KC_UP,   _______, _______, _______,  \
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______, _______,      _______, _______,          _______, _______, _______, _______  \
  )
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode)  {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
        clear_mods();
      }
      return false;
      break;

    case COLEMAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLEMAK);
        clear_mods();
      }
      return false;
      break;

    case DVORAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_DVORAK);
        clear_mods();
      }
      return false;
      break;
  }
  return true;
}
