#include QMK_KEYBOARD_H
#include "version.h"

// Tap dance keycodes
enum
{
    ALT_TMUX
};

typedef enum
{
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD
} td_state_t;

// Instantiate tapdante state for ALT_TMUX
static td_state_t td_state;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * L0: basic Dvorak Keyboard Layout
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   CL   |   1  |   2  |   3  |   4  |   5  |  󰐪   |           |     |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Del  |   ;  |   ,  |   .  |   P  |   Y  |     |           |     |   F  |   G  |   C  |   C  |   R  |   ~    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   LA   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  | S.CAPS |
 * |--------+------+------+------+------+------|   !  |           |  ?   |------+------+------+------+------+--------|
 * | LShift |  ''  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                  Meta/ |  󱁐/  | Home |       | PgUp |        |      |
 *                                 | Esc  |  L1  |------|       |------|   󰭜    |   󰌑  |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */

[0] = LAYOUT_ergodox_pretty(
  TO(0),        KC_1,       KC_2,       KC_3,   KC_4,    KC_5,    KC_PSCR,              KC_MUTE,    KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_NO,
  KC_DEL,       KC_SCLN,    KC_COMM,    KC_DOT, KC_P,    KC_Y,    KC_VOLU,              KC_VOLD,    KC_F,   KC_G,   KC_C,   KC_R,   KC_L,   KC_TILDE,
  TG(5),        KC_A,       KC_O,       KC_E,   KC_U,    KC_I,                                      KC_D,   KC_H,   KC_T,   KC_N,   KC_S,   CW_TOGG,
  KC_LSFT,      KC_QUOTE,   KC_Q,       KC_J,   KC_K,    KC_X,    KC_EXLM,              KC_QUES,    KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,   KC_RSFT,
  KC_NO,        KC_NO,      TG(3),      TG(2),  TG(1),                                              KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,

                                                KC_NO,  KC_NO,                  KC_NO, KC_NO,
                                                        KC_NO,                  KC_NO,
                        LGUI_T(KC_ESC), LT(4, KC_SPC),  LCTL_T(KC_TAB),         TD(ALT_TMUX), KC_BSPC, KC_ENT
),

/*
 * L1: LoL layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   CL   |   1  |   2  |   3  |   4  |   5  |  󰐪   |           |     |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Del  |   ;  |   ,  |   .  |   P  |   Y  |     |           |     |   F  |   G  |   C  |   C  |   R  |   ~    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   LA   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  | S.CAPS |
 * |--------+------+------+------+------+------|   !  |           |  ?   |------+------+------+------+------+--------|
 * | LShift |  ''  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                  Meta/ |  󱁐/  | Home |       | PgUp |        |      |
 *                                 | Esc  |  L1  |------|       |------|   󰭜    |   󰌑  |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */

[1] = LAYOUT_ergodox_pretty(
  KC_TRNS,      KC_1,       KC_2,       KC_3,   KC_4,    KC_5,    KC_P,             KC_NO,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TAB,       KC_SCLN,    KC_COMM,    KC_DOT, KC_P,    KC_Y,    KC_TRNS,          KC_TRNS,    KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       KC_TRNS,
  KC_ESC,       KC_A,       KC_O,       KC_E,   KC_U,    KC_I,                                  KC_D,       KC_H,       KC_T,       KC_N,       KC_S,       KC_TRNS,
  KC_LSFT,      KC_QUOTE,   KC_Q,       KC_J,   KC_K,    KC_X,    KC_TRNS,          KC_TRNS,    KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,       KC_TRNS,
  KC_NO,        KC_NO,      KC_NO,      KC_NO,  KC_TRNS,                                        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,

                                                KC_NO,  KC_NO,                  KC_NO, KC_NO,
                                                        KC_NO,                  KC_NO,
                        LALT_T(KC_R),   LT(5, KC_SPC),  KC_LCTL,                KC_NO, KC_BSPC, KC_ENT
),
/* L2: General Gaming
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[2] = LAYOUT_ergodox_pretty(
  KC_TRNS,      KC_1,       KC_2,       KC_3,       KC_4,    KC_5,    KC_P,             KC_NO,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TAB,       KC_Q,       KC_W,       KC_E,       KC_R,    KC_T,    KC_TRNS,          KC_TRNS,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_TRNS,
  KC_ESC,       KC_A,       KC_S,       KC_D,       KC_F,    KC_G,                                  KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_TRNS,
  KC_LSFT,      KC_Z,       KC_X,       KC_C,       KC_V,    KC_B,    KC_M,             KC_TRNS,    KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_SCLN,    KC_TRNS,
  KC_NO,        KC_NO,      KC_NO,      KC_TRNS,    KC_NO,                                          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,

                                                KC_NO,  KC_NO,                      KC_NO, KC_NO,
                                                        KC_NO,                      KC_NO,
                                    KC_SPC,    KC_LALT, KC_LCTL,                    KC_NO, KC_BSPC, KC_ENT
),

/* L3: Star Citizen
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[3] = LAYOUT_ergodox_pretty(
  KC_TRNS,      KC_1,       KC_2,       KC_3,       KC_4,    KC_5,    KC_P,             KC_NO,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TAB,       KC_Q,       KC_W,       KC_E,       KC_R,    KC_T,    KC_TRNS,          KC_TRNS,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_TRNS,
  KC_ESC,       KC_A,       KC_S,       KC_D,       KC_F,    KC_G,                                  KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_TRNS,
  KC_LSFT,      KC_Z,       KC_X,       KC_C,       KC_V,    KC_B,    KC_M,             KC_TRNS,    KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_SCLN,    KC_TRNS,
  KC_NO,        KC_NO,      KC_TRNS,    KC_NO,      OSL(5),                                          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,

                                                KC_NO,  KC_NO,                      KC_NO, KC_NO,
                                                        KC_NO,                      KC_NO,
                                    KC_SPC,    KC_LCTL, KC_LALT,                    KC_NO, KC_BSPC, KC_ENT
),

/* L4: Special Symbols
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[4] = LAYOUT_ergodox_pretty(
  KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,     KC_TRNS,    KC_TRNS,
  KC_NO,        KC_NO,      KC_ASTR,    KC_AMPR,    KC_LBRC,    KC_LABK,    KC_NO,                  KC_NO,      KC_RABK,    KC_RBRC,    KC_PIPE,   KC_CIRC,     KC_NO,      KC_NO,
  KC_0,         KC_COLN,    KC_BSLS,    KC_LPRN,    KC_LCBR,    KC_PLUS,                                        KC_EQUAL,   KC_RCBR,    KC_RPRN,   KC_SLASH,    KC_SCLN,    KC_DLR,
  KC_TRNS,      KC_DQT,     KC_HASH,    KC_MINUS,   KC_AT,      KC_TILDE,   KC_NO,                  KC_NO,      KC_GRV,     KC_PSTE,    KC_UNDS,   KC_PERC,     KC_QUOT,    KC_NO,
                KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,

                                                    KC_NO,  KC_NO,                                                  KC_NO,  KC_NO,
                                                            KC_NO,                                                  KC_NO,
                                            KC_NO,  KC_NO,  KC_NO,                                                  KC_NO, KC_NO, KC_NO
),

/* L5: Special Symbols */
[5] = LAYOUT_ergodox_pretty(
  KC_TRNS,      KC_NO,  KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_PSCR,            KC_NO,  KC_NO,      KC_NO,  KC_NO,      KC_NO,  KC_NO,      KC_NO,
  KC_NO,        KC_F1,  KC_F2,  KC_F3,      KC_F4,      KC_F5,      KC_NO,              KC_NO,  KC_F6,      KC_F7,  KC_F8,      KC_F9,  KC_F10,     KC_NO,
  KC_TRNS,      KC_1,   KC_2,   KC_3,       KC_4,       KC_5,                                   KC_6,       KC_7,   KC_8,       KC_9,   KC_0,       KC_NO,
  KC_LSFT,      KC_F11, KC_NO,  KC_LEFT,    KC_DOWN,    KC_DOT,     KC_NO,              KC_NO,  KC_COMM,    KC_UP,  KC_RIGHT,   KC_F12, KC_NO,      KC_RSFT,
  KC_NO,        KC_NO,  KC_NO,  KC_NO,      KC_NO,                                                          KC_NO,  KC_NO,      KC_NO,  KC_NO,      KC_NO,

                                                    KC_TRNS,    KC_TRNS,                                    KC_TRNS, KC_TRNS,
                                                                KC_TRNS,                                    KC_TRNS,
                                            KC_TRNS,  KC_TRNS,  KC_TRNS,                                    KC_TRNS, KC_TRNS, KC_TRNS
)
};

td_state_t cur_dance(tap_dance_state_t *state)
{
    if (state->count == 1)
    {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    else return TD_UNKNOWN;
};

void alt_tmux_finished(tap_dance_state_t *state, void *user_data)
{
    td_state = cur_dance(state);

    switch (td_state)
    {
        case TD_SINGLE_TAP:
            register_mods(MOD_BIT(KC_LCTL));
            register_code(KC_B);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LALT));
            break;
        default:
            break;
    }
};

void alt_tmux_reset(tap_dance_state_t *state, void *user_data)
{
    switch (td_state)
    {
        case TD_SINGLE_TAP:
            unregister_code(KC_B);
            unregister_mods(MOD_BIT(KC_LCTL));
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT));
            break;
        default:
            break;
    }
};

tap_dance_action_t tap_dance_actions[] = {
    [ALT_TMUX] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_tmux_finished, alt_tmux_reset),
};

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
