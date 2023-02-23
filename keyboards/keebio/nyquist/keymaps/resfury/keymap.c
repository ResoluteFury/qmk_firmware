#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum resfury_layers {
    _COLEMAK,
    _QWERTY,
    _DVORAK,
};

enum resfury_keycodes {
  COLEMAK = SAFE_RANGE,
  DVORAK,
  QWERTY
};

#define _LOWER 3
#define _RAISE 4
#define _FUNCTION 5
#define _ADJUST 6

#define LOWER     MO(_LOWER)
#define RAISE     MO(_RAISE)
#define FUNCTION  MO(_FUNCTION)
#define ADJUST    MO(_ADJUST)

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |  Esc  |  1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |F/TAB |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Ent  |Lower | Bksp | Spc  |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

[_COLEMAK] = LAYOUT( \
  KC_ESC,               KC_1,     KC_2,    KC_3,    KC_4,  KC_5,    KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC,       \
  KC_GRV,               KC_Q,     KC_W,    KC_F,    KC_P,  KC_G,    KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_BSLS,       \
  LT(_FUNCTION,KC_TAB), KC_A,     KC_R,    KC_S,    KC_T,  KC_D,    KC_H,   KC_N,  KC_E,    KC_I,    KC_O,    KC_QUOT,       \
  OSM(MOD_LSFT),        KC_Z,     KC_X,    KC_C,    KC_V,  KC_B,    KC_K,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_RSFT), \
  KC_LCTL,              KC_LGUI,  KC_LALT, KC_ENT,  LOWER, KC_BSPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT        \
),

 /* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |  Esc  |  1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |F/TAB |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  | Ent  |Lower | Bksp | Spc  | Raise| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_ESC,               KC_1,     KC_2,    KC_3,    KC_4,  KC_5,    KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC,       \
  KC_GRV,               KC_Q,     KC_W,    KC_E,    KC_R,  KC_T,    KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSLS,       \
  LT(_FUNCTION,KC_TAB), KC_A,     KC_S,    KC_D,    KC_F,  KC_G,    KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,       \
  OSM(MOD_LSFT),        KC_Z,     KC_X,    KC_C,    KC_V,  KC_B,    KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_RSFT), \
  KC_LCTL,              KC_LGUI,  KC_LALT, KC_ENT,  LOWER, KC_BSPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT        \
),

 /* Dvorak
  * ,-----------------------------------------------------------------------------------.
 * |  Esc  |  1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |   /  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |F/TAB |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   R  |   L  |   -  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  | Ent  |Lower | Bksp | Spc  | Raise| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT( \
  KC_ESC,               KC_1,     KC_2,    KC_3,    KC_4,  KC_5,    KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC,       \
  KC_ESC,               KC_QUOT,  KC_COMM, KC_DOT,  KC_P,  KC_Y,    KC_F,   KC_G,  KC_C,    KC_R,    KC_L,    KC_SLSH,       \
  LT(_FUNCTION,KC_TAB), KC_A,     KC_O,    KC_E,    KC_U,  KC_I,    KC_D,   KC_H,  KC_T,    KC_N,    KC_S,    KC_MINS,       \
  OSM(MOD_LSFT),        KC_SCLN,  KC_Q,    KC_J,    KC_K,  KC_X,    KC_B,   KC_M,  KC_W,    KC_V,    KC_Z,    OSM(MOD_RSFT), \
  KC_LCTL,              KC_LGUI,  KC_LALT, KC_ENT,  LOWER, KC_BSPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT        \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  ~   |  `   | Mute | Ctl/ |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower | Bksp | Spc  |Adjust| Play | Vol+ | Vol- | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_ESC,  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,   KC_ASTR, KC_LPRN, KC_RPRN,       KC_DEL,  \
  _______, KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,   KC_ASTR, KC_LPRN, KC_RPRN,       KC_DEL,  \
  _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,   KC_PLUS, KC_LCBR, KC_RCBR,       _______, \
  _______, KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_GRV), KC_GRV,  KC_MUTE, RCTL(KC_BSLS), KC_PIPE, \
  _______, _______,  _______, _______, _______, KC_BSPC, KC_SPC,  ADJUST,    KC_MPLY, KC_VOLD, KC_VOLU,       KC_MNXT  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   4  |   5  |   6  |   +  |   -  |  +   |   -  |   =  |   [  |   ]  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   7  |   8  |   9  |   *  |   /  |  *   |   /  |   .  | Mute | Ctl/ |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ,  |   0  |  .   |Adjust| Bksp | Spc  |Raise | Play | Vol+ | Vol- | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,  KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          KC_DEL,  \
  _______, KC_1,    KC_2,  KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          KC_DEL,  \
  _______, KC_4,    KC_5,  KC_6,   KC_PLUS, KC_MINS, KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,       _______, \
  _______, KC_7,    KC_8,  KC_9,   KC_ASTR, KC_SLSH, KC_ASTR, KC_SLSH, KC_DOT,  KC_MUTE, RCTL(KC_BSLS), KC_BSLS, \
  _______, KC_COMM, KC_0,  KC_DOT, ADJUST,  KC_BSPC, KC_SPC,  _______, KC_MPLY, KC_VOLD, KC_VOLU,       KC_MNXT  \
),

/* Adjust (Lower + Raise)
 * ,-------------------------------------------------------------------------------------.
 * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * ,-------------------------------------------------------------------------------------.
 * | Taskmg |      |      |      |      |      |      |      |RGBVAI|RGBSAI|RGBHUI|caltde|
 * |-------+-------+------+------+------+------+------+------+------+------+------+------|
 * |_COLEMAK|      |      |      |      |      |      |      |RGBVAD|RGBSAD|RGBHUD|RGBTOG|
 * |-------+-------+------+------+------+------+------+------+------+------+------+------|
 * |_DVORAK |      |      |      |      |      |      |      |      |      |RGBMOD|BLSTEP|
 * |-------+-------+------+------+------+------+------+------+------+------+------+------|
 * |_QWERTY |      |      |      |      |      |      |      |      |      |      |QK_BT |
 * `-------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT( \
  KC_F1,        KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  TSKMGR,       _______, _______, _______, _______, _______, _______, _______, RGB_VAI, RGB_SAI, RGB_HUI, CALTDEL, \
  DF(_COLEMAK), _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG, \
  DF(_DVORAK),  _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, BL_STEP, \
  DF(_QWERTY),  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT  \
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * | Caps |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | S(Hm)| Home |  Up  | End  |S(End)|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Ctrl | Shift| Alt  |      |      | PgDn | Left | Down |Right | PgUp |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT( \
  KC_CAPS, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______,   _______, \
  _______, _______, _______, _______, _______, _______, S(KC_HOME), KC_HOME, KC_UP,   KC_END,  S(KC_END), _______, \
  _______, KC_LCTL, KC_LSFT, KC_LALT, _______, _______, KC_PGDN,    KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP,   _______, \
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______,   _______, \
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______,   _______  \
)

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

// void persistent_default_layer_set(uint16_t default_layer) {
//   eeconfig_update_default_layer(default_layer);
//   default_layer_set(default_layer);
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
  }
  return true;
}
