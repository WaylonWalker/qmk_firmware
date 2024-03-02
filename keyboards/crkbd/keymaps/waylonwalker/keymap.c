/*
Copyright 2019 @foosta
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2021 Waylon Walker @_waylonwalker

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


#include QMK_KEYBOARD_H
#include <stdio.h>

#define MINECRAFT 6

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
};

enum custom_keycodes {
    VIM___B = SAFE_RANGE,
    /* VIM___D, */
    VIM___E,
    VIM___O,
    VIM___P,
    VIM___W,
    VIM___Y,
    SUPERF1,
    SUPERF2,
    SUPERF3,
    SUPERF4,
    SUPERF5,
    SUPERF6,
    SUPERF7,
    SUPERF8,
    SUPERF9,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    case VIM___B:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_LEFT)SS_UP(X_LCTL));
        } else {
        }
        break;
    /* case VIM___D: */
    /*     if (record->event.pressed) { */
    /*         SEND_STRING(SS_TAP(X_HOME)SS_DOWN(X_LSHIFT)SS_TAP(X_END)SS_UP(X_LSHIFT)); */
    /*     } else { */
    /*     } */
        break;
    case VIM___E:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_RIGHT)SS_UP(X_LCTL)SS_TAP(X_LEFT));
        } else {
        }
        break;
    case VIM___O:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_END)SS_TAP(X_ENTER));
        } else {
        }
        break;
    case VIM___P:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)"v"SS_UP(X_LCTL));
        } else {
        }
        break;
    case VIM___W:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_RIGHT)SS_UP(X_LCTL));
        } else {
        }
        break;
    case VIM___Y:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)"c"SS_UP(X_LCTL));
        } else {
        }
        break;
    case SUPERF1:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI)"c"SS_UP(X_LCTL));
        } else {
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // base layer
  //
  // inludes modified homerow mods
  // z super
  // x alt
  // d shift
  // f ctrl
  // j ctrl
  // k shift
  // . alt
  // / super
  //
  //
  // workspace management
  // c go to workspace
  // v switch to workspace
  // b send window to workspace
  [0] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------------------------------------.     ,--------------------------------------------------------------------------------------------.
      LT(2, KC_TAB),    KC_Q,             KC_W,           LT(3, KC_E),   KC_R,          LT(12, KC_T),       KC_Y,    KC_U,           KC_I,             KC_O,            KC_P,            KC_BSPC,
  //|-----------------+-------------+------------------+---------------+--------------+--------------|     |-------+---------------+-----------------+----------------+----------------+----------------|
      LT(7, KC_ESC),    LT(4, KC_A),      LT(5, KC_S),    LSFT_T(KC_D),  LCTL_T(KC_F),  KC_G,               KC_H,    RCTL_T(KC_J),   RSFT_T(KC_K),     LT(5, KC_L),     LT(4, KC_SCLN),  LT(7, KC_QUOT),
  //|-----------------+-------------+------------------+---------------+--------------+--------------|     |-------+---------------+-----------------+----------------+----------------+----------------|
      KC_LSFT,          LGUI_T(KC_Z),     LALT_T(KC_X),   LT(11, KC_C),  LT(9, KC_V),   LT(10, KC_B),       KC_N,    RCTL_T(KC_M),   RSFT_T(KC_COMM),  RALT_T(KC_DOT),  RGUI_T(KC_SLSH), KC_HYPR,
  //|-----------------+-------------+------------------+---------------+--------------+--------------|     |-------+---------------+--------+--------+----------------+----------------+----------------|
                                                                       KC_LGUI,   KC_LALT,   KC_LCTL,       LT(4, KC_ENT),   LT(2, KC_SPC),   KC_RSFT
                                                                   //`----------+----------+----------'   `----------------+----------------+---------'
  ),

  // default layer 1 unused
  [1] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------------.                    ,-----------------------------------------------------.
        MO(3), KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  //|--------+--------+--------+--------+--------+-----------------------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DEL,
  //|--------+--------+--------+--------+--------+-----------------------|                    |--------+--------+--------+--------+--------+--------|
      _______, LGUI_T(KC_Z), XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,                                  KC_MINUS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+-----------------------|  |--------+--------+--------+--------+--------+--------+--------|
                                                         _______, _______,  _______,     _______, _______, _______
                                                     //`--------------------------'  `--------------------------'
  ),

  // used only for symbols, needs merged with layer 3
  [2] = LAYOUT_split_3x6_3(
  // from base RH Middle Thumb
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        MO(3), KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_END, KC_HOME, KC_PGDN , XXXXXXX,    LCTL_T(KC_MEDIA_PLAY_PAUSE),       LCTL_T( KC_LEFT ), KC_DOWN,   KC_UP,KC_RIGHT,  KC_F11,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS, KC_UNDS,                      KC_MINUS, KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC,   KC_TAB,  KC_DEL,     LT(3, KC_ENT), _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // rgb - mouse
  // i really don't use this much
  [3] = LAYOUT_split_3x6_3(
  // from base hold e
  // from base hole right thumb left and thumb middle (for the rgb stuff)
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    QK_REBOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, KC_WH_D,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_VOLD, KC_VOLU,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_ACL0, KC_ACL1,  KC_ACL2,     KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3
                                      //`--------------------------'  `--------------------------'
  ),


  // paren - numppad
  [4] = LAYOUT_split_3x6_3(
  // from base layer hold a
  // from base layer hold semicolon (unused)
  // from base layer hold right thumb (unused)
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_PERC,                     KC_PLUS, KC_7, KC_8, KC_9, KC_PAST, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_UNDS, KC_LPRN, KC_RPRN, KC_DLR,                      LCTL_T( KC_MINS ), KC_4, KC_5, KC_6, KC_UNDS, KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_SLSH, KC_DOT, KC_LCBR, KC_RCBR,    KC_0,                      KC_0,   KC_1, KC_2, KC_3, KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, TT(6),  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),


  // parens
  // unused unless I use it by mistake
  // I use layer 4 instead of this
  // I do use this layer to tap into minecraft hold s tap q
  [5] = LAYOUT_split_3x6_3(
  // from base layer hold s
  // from base layer hold l (unused)
  //
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, TT(6),   XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,                      XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX,                      KC_BSPC, KC_DEL, KC_RPRN, XXXXXXX, KC_QUOT,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX,                      KC_GRV, KC_TILDE, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // left space for minecraft / gaming
  [6] = LAYOUT_split_3x6_3(
  // from base layer hold s press q
  //,-----------------------------------------------------------------------.                     ,-------------------------------------------------------.
      LT(1, KC_TAB),             XXXXXXX,    KC_W,    KC_E,    KC_1, KC_T,                         KC_Q,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------------------------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+----------|
      KC_LSFT,                   KC_A,    KC_S,    KC_D,    KC_F, KC_GRV,                          KC_F3,    KC_MS_BTN2,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------------------------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+----------|
      MT(MOD_LCTL, KC_ESC),      KC_6,    KC_5,    KC_4,    KC_3, KC_B,                             KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_HYPR,
  //|--------------------------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+----------|
                                                     KC_LSFT,   KC_SPC,  KC_LCTL,          LT(0, KC_ENT),   LT(2, KC_SPC), TG(6)
                                               //`-----------------------------------'   `---------------------------------------'
  ),

  // vimmy navigation
  [7] = LAYOUT_split_3x6_3(
  // from base layer hold CAPS (well where a norla CAPSLOCK is)
  // from base layer hold ' (unused)
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, MO(4), VIM___W, VIM___E, KC_VOLD, KC_VOLU,                       VIM___Y, KC_PGUP,  KC_HOME, VIM___O, VIM___P, KC_DEL,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_LSFT, KC_END, KC_HOME, LSFT_T(KC_PGDN) , LCTL_T(KC_MUTE),  KC_MPLY,     LCTL_T( KC_LEFT ), KC_DOWN,   KC_UP,KC_RIGHT,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL, XXXXXXX, KC_DEL, XXXXXXX, KC_GRV, VIM___B,                       KC_MNXT, KC_MPRV, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, MO(8),  _______,     _______,   MO(3), _______
                                      //`--------------------------'  `--------------------------'
  ),
  // unused
  // no way in here
  [8] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_MS_WH_UP,                 KC_PLUS, KC_7, KC_8, KC_9, KC_PAST, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_UNDS, KC_LPRN, KC_RPRN, LCTL_T( KC_MS_WH_DOWN ),               LCTL_T( KC_MINS ), KC_4, KC_5, KC_6, KC_UNDS, KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_SLSH, KC_DOT, KC_LCBR, KC_RCBR,    KC_0,                      KC_0,   KC_1, KC_2, KC_3, KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, TT(6),  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),


  // Next 3 layers 9, 10, 11 are for navigating workspaces.
  // This is critical to how I navigate workspaces in pretty much any window
  // manager
  //
  // 9  (x) = go to workspace numpad
  // 10 (c) = join with workspace numpad
  // 11 (v) = send window to workspace numpad
  //
  // awesome wm go to tag numpad
  [9] = LAYOUT_split_3x6_3(
  // from base layer hold s
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, LCTL(LGUI(KC_7)), LCTL(LGUI(KC_8)), LCTL(LGUI(KC_9)), XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, LCTL(LGUI(KC_4)), LCTL(LGUI(KC_5)), LCTL(LGUI(KC_6)), XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, LCTL(LGUI(KC_1)), LCTL(LGUI(KC_2)), LCTL(LGUI(KC_3)), XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, LCTL(LGUI(KC_SPC)), _______
                                      //`--------------------------'  `--------------------------'

  ),
  // awesome wm join with tag numpad
  [10] = LAYOUT_split_3x6_3(
  // from base layer hold c
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, LSFT(LGUI(KC_7)), LSFT(LGUI(KC_8)), LSFT(LGUI(KC_9)), XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, LSFT(LGUI(KC_4)), LSFT(LGUI(KC_5)), LSFT(LGUI(KC_6)), XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, LSFT(LGUI(KC_1)), LSFT(LGUI(KC_2)), LSFT(LGUI(KC_3)), XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'

  ),

  // awesome wm send window to tag numpad
  [11] = LAYOUT_split_3x6_3(
  // from base layer hold v
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'

  ),

  // Fkeys
  [12] = LAYOUT_split_3x6_3(
  // from base layer hold t
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_F7, KC_F8, KC_F9, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OSM(MOD_LCTL|MOD_LALT),       XXXXXXX, KC_F4, KC_F5, KC_F6, KC_F11, KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_F10, KC_F1, KC_F2, KC_F3, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //
                                   KC_LGUI,   KC_LALT,  KC_LCTL,         LT(4, KC_ENT),   LT(2, KC_SPC), KC_RSFT
                                      //`--------------------------'  `--------------------------'
  )


};
