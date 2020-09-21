#include QMK_KEYBOARD_H

#define DEFAULT_LAYER 0
#define ADDON_LAYER 1

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    CK_ADDON = MO(ADDON_LAYER)
};

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT_LAYER] = LAYOUT_ortho_5x15( \
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,   KC_6,       KC_7,   KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSLS,    KC_GRV, \
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,   KC_Y,       KC_U,   KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSPC,    KC_BSPC, \
        KC_BSPC,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,   KC_H,       KC_J,   KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_ENT,     KC_ENT,     KC_HOME, \
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,   KC_N,       KC_M,   KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,    KC_RSFT,    KC_UP,      KC_END, \
        KC_LCTL,    KC_LGUI,    KC_LALT,    CK_ADDON,   KC_SPC,     KC_SPC, KC_SPC,     KC_SPC, KC_SPC,     KC_SPC,     KC_RALT,    KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RGHT),
    [ADDON_LAYER] = LAYOUT_ortho_5x15( \
        KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,  KC_F6,      KC_F7,  KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      RESET, \
        KC_TAB,     KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_VOLU,    KC_NO,  KC_PAST,    KC_P7,  KC_P8,      KC_P9,      KC_PPLS,    KC_NO,      KC_NLCK,    KC_SLCK,    KC_NO, \
        KC_DEL,     KC_PSCR,    KC_PAUS,    KC_NO,      KC_VOLD,    KC_NO,  KC_PSLS,    KC_P4,  KC_P5,      KC_P6,      KC_PPLS,    KC_NO,      KC_NO,      KC_NO,      KC_NO, \
        KC_LSFT,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,  KC_PMNS,    KC_P1,  KC_P2,      KC_P3,      KC_PENT,    KC_NO,      KC_NO,      KC_NO,      KC_NO, \
        KC_LCTL,    KC_LGUI,    KC_LALT,    KC_TRNS,    KC_SPC,     KC_SPC, KC_SPC,     KC_P0,  KC_P0,      KC_PDOT,    KC_PENT,    KC_NO,      KC_NO,      KC_NO,      KC_NO)
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void matrix_init_user(void) {
    rgblight_enable();
}

void matrix_scan_user(void) {
    #ifdef RGBLIGHT_ENABLE

    static uint8_t old_layer = 255;
    uint8_t new_layer = biton32(layer_state);

    if (old_layer != new_layer) {
        switch (new_layer) {
            case DEFAULT_LAYER:
                rgblight_setrgb(0xA7, 0x51, 0xCA);
                break;
            case ADDON_LAYER:
                rgblight_setrgb(0x51, 0xA7, 0xCA);
                break;
        }

        old_layer = new_layer;
    }

    #endif //RGBLIGHT_ENABLE
}
