#include QMK_KEYBOARD_H

enum {
    TD_LGUI_TG = 0,
    TD_LGUI5_SPACE = 1,
    TD_LGUI2 = 2,
    TD_LGUI3 = 3,
    TD_LGUI4 = 4
};

void td_lgui_tg_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LGUI);
        register_code(KC_1);
        unregister_code(KC_1);
        unregister_code(KC_LGUI);
    } else if (state->count == 2) {
        layer_invert(1);
    } else if (state->count == 3) {
        layer_invert(6);
    }
}

void td_lgui_tg_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        // No need to unregister LGUI here because it's already done in the finished function.
    }
}

void td_lgui5_space(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LGUI);
        register_code(KC_5);
        unregister_code(KC_5);
        unregister_code(KC_LGUI);
    } else if (state->count == 2) {
        register_code(KC_SPACE);
        unregister_code(KC_SPACE);
    }
}

void td_lgui2(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LGUI);
        register_code(KC_2);
        unregister_code(KC_2);
        unregister_code(KC_LGUI);
    } else if (state->count == 2) {
        layer_on(2);
    }
}

void td_lgui3(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LGUI);
        register_code(KC_3);
        unregister_code(KC_3);
        unregister_code(KC_LGUI);
    } else if (state->count == 2) {
        layer_on(3);
    }
}

void td_lgui4(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LGUI);
        register_code(KC_4);
        unregister_code(KC_4);
        unregister_code(KC_LGUI);
    } else if (state->count == 2) {
        layer_on(4);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LGUI_TG] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_lgui_tg_finished, td_lgui_tg_reset),
    [TD_LGUI5_SPACE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_lgui5_space, NULL),
    [TD_LGUI2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_lgui2, NULL),
    [TD_LGUI3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_lgui3, NULL),
    [TD_LGUI4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_lgui4, NULL)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// TEMPLATE
// ╭─────────────────┬─────────────────┬─────────────────╮
// │                 │                 │                 │
//       _______,         _______,         _______,
// │                 │                 │                 │
// ├─────────────────┼─────────────────┼─────────────────┤
// │                 │                 │                 │
//       _______,         _______,         _______,
// │                 │                 │                 │
// ├─────────────────┼─────────────────┼─────────────────┤
// │                 │                 │                 │
//       _______,         _______,         _______,
// │                 │                 │                 │
// ╰─────────────────┴─────────────────┴─────────────────╯
    [0] = LAYOUT_ortho_3x3(
// go to workspace
// ╭─────────────────┬─────────────────┬─────────────────╮
// │                 │                 │                 │
         LGUI(KC_7),       LGUI(KC_8),       LGUI(KC_9),
// │                 │                 │                 │
// ├─────────────────┼─────────────────┼─────────────────┤
// │                 │                 │                 │
         TD(TD_LGUI4),       TD(TD_LGUI5_SPACE),       LGUI(KC_6),
// │                 │                 │                 │
// ├─────────────────┼─────────────────┼─────────────────┤
// │                 │                 │                 │
        TD(TD_LGUI_TG),      TD(TD_LGUI2),       TD(TD_LGUI3)
// │                 │                 │                 │
// ╰─────────────────┴─────────────────┴─────────────────╯
    ),
    [1] = LAYOUT_ortho_3x3(
// ╭─────────────────┬─────────────────┬─────────────────╮
// │                 │                 │                 │
      _______,           _______,            LGUI(KC_K),
// │                 │                 │                 │
// ├─────────────────┼─────────────────┼─────────────────┤
// │                 │                 │                 │
      _______,           KC_SPACE,         LGUI(KC_J),
// │                 │                 │                 │
// ├─────────────────┼─────────────────┼─────────────────┤
// │                 │                 │                 │
      TO(0),              _______,           _______
// │                 │                 │                 │
// ╰─────────────────┴─────────────────┴─────────────────╯
            ),
    [2] = LAYOUT_ortho_3x3(
// Arrows
// ╭─────────────────┬─────────────────┬─────────────────╮
// │                 │                 │                 │
       KC_PAGE_DOWN,         KC_UP,         KC_PAGE_UP,
// │                 │                 │                 │
// ├─────────────────┼─────────────────┼─────────────────┤
// │                 │                 │                 │
       KC_LEFT,         KC_DOWN,         KC_RIGHT,
// │                 │                 │                 │
// ├─────────────────┼─────────────────┼─────────────────┤
// │                 │                 │                 │
       TO(0),           KC_PAGE_DOWN,          KC_PAGE_UP
// │                 │                 │                 │
// ╰─────────────────┴─────────────────┴─────────────────╯
    ),
    [3] = LAYOUT_ortho_3x3(
// Media
// ╭─────────────────┬─────────────────┬─────────────────╮
// │                 │                 │                 │
       KC_MEDIA_PREV_TRACK,         KC_KB_VOLUME_UP,          KC_MEDIA_NEXT_TRACK,
// │                 │                 │                 │
// ├─────────────────┼─────────────────┼─────────────────┤
// │                 │                 │                 │
       KC_MEDIA_PLAY_PAUSE,         KC_KB_VOLUME_DOWN,         KC_MEDIA_PREV_TRACK,
// │                 │                 │                 │
// ├─────────────────┼─────────────────┼─────────────────┤
// │                 │                 │                 │
       TO(0),           _______,          _______
// │                 │                 │                 │
// ╰─────────────────┴─────────────────┴─────────────────╯
    ),
    [4] = LAYOUT_ortho_3x3(
// MINECRAFT 1
// ╭─────────────────┬─────────────────┬─────────────────╮
// │                 │                 │                 │
       LT(5, KC_Q),         KC_W,          KC_E,
// │                 │                 │                 │
// ├─────────────────┼─────────────────┼─────────────────┤
// │                 │                 │                 │
       KC_A,         KC_S,          KC_D,
// │                 │                 │                 │
// ├─────────────────┼─────────────────┼─────────────────┤
// │                 │                 │                 │
       KC_LSFT,           KC_LCTL,          KC_SPACE
// │                 │                 │                 │
// ╰─────────────────┴─────────────────┴─────────────────╯
    ),
    [5] = LAYOUT_ortho_3x3(
// MINECRAFT 2
// ╭─────────────────┬─────────────────┬─────────────────╮
// │                 │                 │                 │
       KC_Q,         _______,          TT(4),
// │                 │                 │                 │
// ├─────────────────┼─────────────────┼─────────────────┤
// │                 │                 │                 │
       KC_ESC,         KC_F,          KC_GRV,
// │                 │                 │                 │
// ├─────────────────┼─────────────────┼─────────────────┤
// │                 │                 │                 │
       _______,           _______,          _______
// │                 │                 │                 │
// ╰─────────────────┴─────────────────┴─────────────────╯
    ),
    [6] = LAYOUT_ortho_3x3(
// BOOT
// ╭─────────────────┬─────────────────┬─────────────────╮
// │                 │                 │                 │
       QK_BOOT,         _______,         _______,
// │                 │                 │                 │
// ├─────────────────┼─────────────────┼─────────────────┤
// │                 │                 │                 │
       _______,         _______,         _______,
// │                 │                 │                 │
// ├─────────────────┼─────────────────┼─────────────────┤
// │                 │                 │                 │
       TO(0),           _______,         _______
// │                 │                 │                 │
// ╰─────────────────┴─────────────────┴─────────────────╯
    )
};


