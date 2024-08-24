// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
/**
 * 
 *  @file        ANSI.h
 *  @brief       A collection of ANSI escape codes for terminal manipulation.
 *  @author      GITHUB: xMo-101 | DISCORD: alexanderaugustus | xMo
 *  @version     v1.0
 *  SOURCE:      GITHUB: fnky ( https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797 )
 *  @date        24.08.2024 (DD.MM.YYYY)
 * 
 **/
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

#ifndef ANSI_H
#define ANSI_H

#define ANSI_ESC "\x1b"
#define ANSI_CSI ANSI_ESC"["

/* ################################################################### */
/* ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ { CURSOR CONTROLS } ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ */
/* ################################################################### */

#define ANSI_CURSOR_HOME             ANSI_CSI"H"         // Move Cursor to (0, 0)
#define ANSI_CURSOR_XY(x, y)         ANSI_CSI#x";"#y"H"    // Move Cursor to (x, y)
#define ANSI_CURSOR_UP(n)            ANSI_CSI#n"A"       // Move Cursor up (n) lines
#define ANSI_CURSOR_DOWN(n)          ANSI_CSI#n"B"       // Move Cursor down (n) lines
#define ANSI_CURSOR_RIGHT(n)         ANSI_CSI#n"C"       // Move Cursor right (n) columns
#define ANSI_CURSOR_LEFT(n)          ANSI_CSI#n"D"       // Move Cursor left (n) columns
#define ANSI_CURSOR_TOCOLUMN(n)      ANSI_CSI#n"G"       // Move Cursor to column n
#define ANSI_CURSOR_GETPOS           ANSI_CSI"6n"        // Get Cursor Position (format: ESC[(#);(#)R)
#define ANSI_CURSOR_1UP              ANSI_ESC"M"         // Move Cursor up 1 line
#define ANSI_CURSOR_SAVEPOS          ANSI_ESC"7"         // Save Cursor Position
#define ANSI_CURSOR_RESTOREPOS       ANSI_ESC"8"         // Restore Cursor Position

/* ################################################################### */
/* ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ { ERASE FUNCTIONS } ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ */
/* ################################################################### */

#define ANSI_ERASE_INDISPLAY         ANSI_CSI"J"         // Erase in Display
#define ANSI_ERASE_CURSORTOBEGIN     ANSI_CSI"1J"        // Erase Cursor to Beginning of Display
#define ANSI_ERASE_SCREEN            ANSI_CSI"2J"        // Erase Screen
#define ANSI_ERASE_SAVEDLINES        ANSI_CSI"3J"        // Erase Saved Lines
#define ANSI_ERASE_INLINE            ANSI_CSI"K"         // Erase in Line
#define ANSI_ERASE_STARTTOCURSOR     ANSI_CSI"1K"        // Erase Start to Cursor
#define ANSI_ERASE_LINE              ANSI_CSI"2K"        // Erase Line

/* ########################################################################## */
/* ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ { COLORS / GRAPHICS MODE } ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ */
/* ########################################################################## */

#define ANSI_GRAPHICS_RESET          ANSI_CSI"0m"        // Reset Graphics Mode
#define ANSI_GRAPHICS_BOLD           ANSI_CSI"1m"        // Bold
#define ANSI_GRAPHICS_FAINT          ANSI_CSI"2m"        // Faint
#define ANSI_GRAPHICS_ITALIC         ANSI_CSI"3m"        // Italic
#define ANSI_GRAPHICS_UNDERLINE      ANSI_CSI"4m"        // Underline
#define ANSI_GRAPHICS_BLINKSLOW      ANSI_CSI"5m"        // Blink Slow
#define ANSI_GRAPHICS_INVERSE        ANSI_CSI"7m"        // Inverse
#define ANSI_GRAPHICS_HIDDEN         ANSI_CSI"8m"        // Hidden
#define ANSI_GRAPHICS_STRIKETHROUGH  ANSI_CSI"9m"        // Strikethrough

/* ############################################################### */
/* ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ { COLOR CODES } ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ */ 
/* ############################################################### */

// FOREGROUND: 30-39
#define ANSI_COLOR_RESET             ANSI_GRAPHICS_RESET // Reset Color
#define ANSI_COLOR_FGBLACK           ANSI_CSI"30m"       // Foreground Black
#define ANSI_COLOR_FGRED             ANSI_CSI"31m"       // Foreground Red
#define ANSI_COLOR_FGGREEN           ANSI_CSI"32m"       // Foreground Green
#define ANSI_COLOR_FGYELLOW          ANSI_CSI"33m"       // Foreground Yellow
#define ANSI_COLOR_FGBLUE            ANSI_CSI"34m"       // Foreground Blue
#define ANSI_COLOR_FGMAGENTA         ANSI_CSI"35m"       // Foreground Magenta
#define ANSI_COLOR_FGCYAN            ANSI_CSI"36m"       // Foreground Cyan
#define ANSI_COLOR_FGWHITE           ANSI_CSI"37m"       // Foreground White
#define ANSI_COLOR_FGDEFAULT         ANSI_CSI"39m"       // Foreground Default
// BACKGROUND: 40-49
#define ANSI_COLOR_BGBLACK           ANSI_CSI"40m"       // Background Black
#define ANSI_COLOR_BGRED             ANSI_CSI"41m"       // Background Red
#define ANSI_COLOR_BGGREEN           ANSI_CSI"42m"       // Background Green
#define ANSI_COLOR_BGYELLOW          ANSI_CSI"43m"       // Background Yellow
#define ANSI_COLOR_BGBLUE            ANSI_CSI"44m"       // Background Blue
#define ANSI_COLOR_BGMAGENTA         ANSI_CSI"45m"       // Background Magenta
#define ANSI_COLOR_BGCYAN            ANSI_CSI"46m"       // Background Cyan
#define ANSI_COLOR_BGWHITE           ANSI_CSI"47m"       // Background White
#define ANSI_COLOR_BGDEFAULT         ANSI_CSI"49m"       // Background Default
// For bright colors, add 60 to the color code. (or see SOURCE)
// For more colors, see SOURCE

/* ######################################################################## */
/* ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ { COMMON PRIVATE MODES } ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ */
/* ######################################################################## */

#define ANSI_PRIVATE_INVISIBLECURSOR ANSI_CSI"?25l"       // Invisible Cursor
#define ANSI_PRIVATE_VISIBLECURSOR   ANSI_CSI"?25h"       // Visible Cursor
#define ANSI_PRIVATE_SAVESCREEN      ANSI_CSI"?47h"       // Save Screen
#define ANSI_PRIVATE_RESTORESCREEN   ANSI_CSI"?47l"       // Restore Screen
#define ANSI_PRIVATE_ALTERNATESCROLL ANSI_CSI"?1049h"     // Alternate Scroll
#define ANSI_PRIVATE_NORMALSCROLL    ANSI_CSI"?1049l"     // Normal Scroll

/* ######################################################## */
/* ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ { KEYS } ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ */
/* ######################################################## */

/** IMPORTANT: To use function, CTRL or ALT keycodes, you need to set up your terminal accordingly.
 *  SEE: Windows: CmdSetup.c | Linux: TerminalSetup.c
 *  IMPORTANT: Some codes may vary depending on keyboard
 * */

// Function keys
#define KEY_F1              59
#define KEY_F1_SHIFT        84
#define KEY_F1_CTRL         94
#define KEY_F1_ALT          104

#define KEY_F2              60
#define KEY_F2_SHIFT        85
#define KEY_F2_CTRL         95
#define KEY_F2_ALT          105

#define KEY_F3              61
#define KEY_F3_SHIFT        86
#define KEY_F3_CTRL         96
#define KEY_F3_ALT          106

#define KEY_F4              62
#define KEY_F4_SHIFT        87
#define KEY_F4_CTRL         97
#define KEY_F4_ALT          107

#define KEY_F5              63
#define KEY_F5_SHIFT        88
#define KEY_F5_CTRL         98
#define KEY_F5_ALT          108

#define KEY_F6              64
#define KEY_F6_SHIFT        89
#define KEY_F6_CTRL         99
#define KEY_F6_ALT          109

#define KEY_F7              65
#define KEY_F7_SHIFT        90
#define KEY_F7_CTRL         100
#define KEY_F7_ALT          110

#define KEY_F8              66
#define KEY_F8_SHIFT        91
#define KEY_F8_CTRL         101
#define KEY_F8_ALT          111

#define KEY_F9              67
#define KEY_F9_SHIFT        92
#define KEY_F9_CTRL         102
#define KEY_F9_ALT          112

#define KEY_F10             68
#define KEY_F10_SHIFT       93
#define KEY_F10_CTRL        103
#define KEY_F10_ALT         113

#define KEY_F11             133
#define KEY_F11_SHIFT       135
#define KEY_F11_CTRL        137
#define KEY_F11_ALT         139

#define KEY_F12             134
#define KEY_F12_SHIFT       136
#define KEY_F12_CTRL        138
#define KEY_F12_ALT         140

// Special character keys
#define KEY_ENTER_KEYPAD      13
#define KEY_ENTER_KEYPAD_CTRL 10
#define KEY_ENTER_KEYPAD_ALT  166

// Alphabet keys with Control, Shift, and Alt variations
#define KEY_A              97
#define KEY_A_SHIFT        65
#define KEY_A_CTRL         1
#define KEY_A_ALT          30

#define KEY_B              98
#define KEY_B_SHIFT        66
#define KEY_B_CTRL         2
#define KEY_B_ALT          48

#define KEY_C              99
#define KEY_C_SHIFT        66
#define KEY_C_CTRL         3
#define KEY_C_ALT          46

#define KEY_D              100
#define KEY_D_SHIFT        68
#define KEY_D_CTRL         4
#define KEY_D_ALT          32

#define KEY_E              101
#define KEY_E_SHIFT        69
#define KEY_E_CTRL         5
#define KEY_E_ALT          18

#define KEY_F              102
#define KEY_F_SHIFT        70
#define KEY_F_CTRL         6
#define KEY_F_ALT          33

#define KEY_G              103
#define KEY_G_SHIFT        71
#define KEY_G_CTRL         7
#define KEY_G_ALT          34

#define KEY_H              104
#define KEY_H_SHIFT        72
#define KEY_H_CTRL         8
#define KEY_H_ALT          35

#define KEY_I              105
#define KEY_I_SHIFT        73
#define KEY_I_CTRL         9
#define KEY_I_ALT          23

#define KEY_J              106
#define KEY_J_SHIFT        74
#define KEY_J_CTRL         10
#define KEY_J_ALT          36

#define KEY_K              107
#define KEY_K_SHIFT        75
#define KEY_K_CTRL         11
#define KEY_K_ALT          37

#define KEY_L              108
#define KEY_L_SHIFT        76
#define KEY_L_CTRL         12
#define KEY_L_ALT          38

#define KEY_M              109
#define KEY_M_SHIFT        77
#define KEY_M_CTRL         13
#define KEY_M_ALT          50

#define KEY_N              110
#define KEY_N_SHIFT        78
#define KEY_N_CTRL         14
#define KEY_N_ALT          49

#define KEY_O              111
#define KEY_O_SHIFT        79
#define KEY_O_CTRL         15
#define KEY_O_ALT          24

#define KEY_P              112
#define KEY_P_SHIFT        80
#define KEY_P_CTRL         16
#define KEY_P_ALT          25

#define KEY_Q              113
#define KEY_Q_SHIFT        81
#define KEY_Q_CTRL         17
#define KEY_Q_ALT          16

#define KEY_R              114
#define KEY_R_SHIFT        82
#define KEY_R_CTRL         18
#define KEY_R_ALT          19

#define KEY_S              115
#define KEY_S_SHIFT        83
#define KEY_S_CTRL         19
#define KEY_S_ALT          31

#define KEY_T              116
#define KEY_T_SHIFT        84
#define KEY_T_CTRL         20
#define KEY_T_ALT          20

#define KEY_U              117
#define KEY_U_SHIFT        85
#define KEY_U_CTRL         21
#define KEY_U_ALT          22

#define KEY_V              118
#define KEY_V_SHIFT        86
#define KEY_V_CTRL         22
#define KEY_V_ALT          47

#define KEY_W              119
#define KEY_W_SHIFT        87
#define KEY_W_CTRL         23
#define KEY_W_ALT          17

#define KEY_X              120
#define KEY_X_SHIFT        88
#define KEY_X_CTRL         24
#define KEY_X_ALT          45

#define KEY_Y              121
#define KEY_Y_SHIFT        89
#define KEY_Y_CTRL         25
#define KEY_Y_ALT          21

#define KEY_Z              122
#define KEY_Z_SHIFT        90
#define KEY_Z_CTRL         26
#define KEY_Z_ALT          44

#endif // ANSI_H
