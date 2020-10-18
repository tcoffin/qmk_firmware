/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 */

#include "gergoplex.h"
#include "g/keymap_combo.h"


enum {
    _ALPHA,   // default
    _SPECIAL, // special characters
    _NUMBERS  // numbers/function/motion
};

#define KC_CTL_A  MT(MOD_LCTL, KC_A)     // Tap for A, hold for Control
#define KC_CTL_CL MT(MOD_LCTL, KC_SCLN)  // Tap for colon, hold for Control
#define KC_SFT_Z  MT(MOD_RSFT, KC_Z)     // Tap for Z, hold for Shift
#define KC_SFT_SL MT(MOD_RSFT, KC_SLSH)  // Tap for slash, hold for Shift

#define KC_GUI_ESC MT(MOD_LGUI, KC_ESC)  // Tap for Esc, hold for GUI (Meta, Command, Win)
#define KC_ALT_ENT MT(MOD_LALT, KC_ENT)  // Tap for Enter, hold for Alt (Option)
#define KC_SYM_SPC LT(_SPECIAL, KC_SPC)  // Tap for Space, hold for Symbol layer
#define KC_NUM_SPC LT(_NUMBERS, KC_SPC)  // Tap for Space, hold for Numbers layer
#define KC_SFT_TAB MT(MOD_RSFT, KC_TAB)  // Tap for Tab, hold for Right Shift

#define KC_CMB_TOG CMB_TOG  // A hack to allow KC_-less keycode along with KC_-ful ones

    /* Combomap
     *
     * ,-------------------------------.      ,-------------------------------.
     * |       |    ESC    |     |     |      |     |    ESC    |    BSLH     |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |       |   BSPC   ENT    |     |      |    LES   COLN  GRT    |       |
     * |-------+-----+-----+-RMB-+-LMB-|      |-----+-----+-----+-----+-------|
     * |       |   MINS    |     |     |      |    QUO   UNDS   |     |       |
     * `-------------------------------'      `-------------------------------'
     *            .-----------------.            .-----------------.
     *            |     |     |     |            |     |     |     |
     *            '-----------------'            '-----------------'
     */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Alpha layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * | TAB/Q |  W  |  F  |  P  |  G  |      |  J  |  L  |  U  |  Y  |   ;   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * | Ctl/A |  R  |  S  |  T  |  D  |      |  H  |  N  |  E  |  I  |   O   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * | Sft/Z |  X  |  C  |  V  |  B  |      |  K  |  M  |  ,  |  .  | / SFT |
     * `-------------------------------'      `-------------------------------'
     *   .------------------------------.    .----------------------.
     *   | ESC META | ENT ALT | SPC SYM |    | SPC NUM | SHFT | TAB |
     *   '------------------------------'    '----------------------'
     */
    [_ALPHA] = LAYOUT_kc(
    // ,-------------------------------.      ,-------------------------------.
           Q   ,  W  ,  F  ,  P  ,  G  ,         J  ,  L  ,  U  ,  Y  , AMPR  ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         CTL_A ,  R  ,  S  ,  T  ,  D  ,         H  ,  N  ,  E  ,  I  ,   O   ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         SFT_Z ,  X  ,  C  ,  V  ,  B  ,         K  ,  M  ,COMMA, DOT , SFT_SL,
    // '-------------------------------'      '-------------------------------'
    //    .---------------------------.        .------------------------.
            GUI_ESC, ALT_ENT, SYM_SPC ,          NUM_SPC, LSFT, SFT_TAB ),
    //    '---------------------------'        '------------------------'

    /* Keymap 1: Special characters layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * |    !  |  @  |  #  |  $  |  %  |      |  ^  |  &  |  *  |  (  |   )   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |    [  |  ]  |  {  |  }  |  `  |      |     |  -  |  _  |  +  |   =   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |    `  |  ~  |     |     |  ~  |      |     |     | Prev|Pl/Pu| Next  |
     * `-------------------------------'      `-------------------------------'
     *     .-------------------------.          .-----------------.
     *     | ComboToggle |  ;  |  =  |          |  =  |  ;  | DEL |
     *     '-------------------------'          '-----------------'
     */
    [_SPECIAL] = LAYOUT_kc(
    // ,-------------------------------.      ,-------------------------------.
         EXLM  , AT  , HASH, DLR , PERC,        CIRC, AMPR, ASTR, LPRN, RPRN  ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         LBRC  , RBRC, LCBR, RCBR, PLUS,        TRNS, MINS, UNDS, PLUS, EQL   ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         GRV   , TILD, TRNS, TRNS, TILD,        TRNS, TRNS, TRNS, TRNS, TRNS  ,
    // '-------------------------------'      '-------------------------------'
    //    .---------------------------.        .------------------------.
            CMB_TOG, SCLN    , EQL    ,          EQL    , SCLN   , DEL  ),
    //    '---------------------------'        '------------------------'

    /* Keymap 2: Numbers/Function/Motion layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * |   1   |  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  |   0   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |  F1   | F2  | F3  | F4  | F5  |      | LFT | DWN | UP  | RGT | VOLUP |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |  F6   | F7  | F8  | F9  | F10 |      | MLFT| MDWN| MUP | MRGT| VOLDN |
     * `-------------------------------'      `-------------------------------'
     *             .-----------------.          .-----------------.
     *             | F11 | F12 |     |          |     | PLY | SKP |
     *             '-----------------'          '-----------------'
     */
    [_NUMBERS] = LAYOUT_kc(
    // ,-------------------------------.      ,-------------------------------.
           1   ,  2  ,  3  ,  4  ,  5  ,         6  ,  7  ,  8  ,  9  ,   0   ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
           F1  ,  F2 ,  F3 ,  F4 , F5  ,        LEFT, DOWN,  UP , RGHT,  VOLU ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
           F6  ,  F7 ,  F8 ,  F9 , F10 ,        MS_L, MS_D, MS_U, MS_R,  VOLD ,
    // '-------------------------------'      '-------------------------------'
    //    .---------------------------.        .------------------------.
              F11  ,   F12   , TRNS   ,           TRNS  ,  MPLY ,  MNXT )
    //    '---------------------------'        '------------------------'
};
