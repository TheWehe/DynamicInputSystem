#ifndef DEVICE_DEVS_H
#define DEVICE_DEVS_H

#include <SDL.h>
#include <array>



extern const float GAMEPAD_AXIS_MAX_ABS;
extern const float GAMEPAD_AXIS_MIN_ABS;

enum KeyboardButton
{
	KB_UNKNOWN,
	KB_BACKSPACE,
	KB_TAB,
	KB_RETURN,
	KB_ESCAPE,
	KB_SPACE,
	KB_EXCLAIM,
	KB_QUOTEDBL,
	KB_HASH,
	KB_DOLLAR,
	KB_PERCENT,
	KB_AMPERSAND,
	KB_QUOTE,
	KB_LEFTPAREN,
	KB_RIGHTPAREN,
	KB_ASTERISK,
	KB_PLUS,
	KB_COMMA,
	KB_MINUS,
	KB_PERIOD,
	KB_SLASH,
	KB_0,
	KB_1,
	KB_2,
	KB_3,
	KB_4,
	KB_5,
	KB_6,
	KB_7,
	KB_8,
	KB_9,
	KB_COLON,
	KB_SEMICOLON,
	KB_LESS,
	KB_EQUALS,
	KB_GREATER,
	KB_QUESTION,
	KB_AT,
	KB_LEFTBRACKET,
	KB_BACKSLASH,
	KB_RIGHTBRACKET,
	KB_CARET,
	KB_UNDERSCORE,
	KB_BACKQUOTE,
	KB_A,
	KB_B,
	KB_C,
	KB_D,
	KB_E,
	KB_F,
	KB_G,
	KB_H,
	KB_I,
	KB_J,
	KB_K,
	KB_L,
	KB_M,
	KB_N,
	KB_O,
	KB_P,
	KB_Q,
	KB_R,
	KB_S,
	KB_T,
	KB_U,
	KB_V,
	KB_W,
	KB_X,
	KB_Y,
	KB_Z,
	KB_DELETE,
	KB_CAPSLOCK,
	KB_F1,
	KB_F2,
	KB_F3,
	KB_F4,
	KB_F5,
	KB_F6,
	KB_F7,
	KB_F8,
	KB_F9,
	KB_F10,
	KB_F11,
	KB_F12,
	KB_PRINTSCREEN,
	KB_SCROLLLOCK,
	KB_PAUSE,
	KB_INSERT,
	KB_HOME,
	KB_PAGEUP,
	KB_END,
	KB_PAGEDOWN,
	KB_RIGHT,
	KB_LEFT,
	KB_DOWN,
	KB_UP,
	KB_NUMLOCKCLEAR,
	KB_KP_DIVIDE,
	KB_KP_MULTIPLY,
	KB_KP_MINUS,
	KB_KP_PLUS,
	KB_KP_ENTER,
	KB_KP_1,
	KB_KP_2,
	KB_KP_3,
	KB_KP_4,
	KB_KP_5,
	KB_KP_6,
	KB_KP_7,
	KB_KP_8,
	KB_KP_9,
	KB_KP_0,
	KB_KP_PERIOD,
	KB_APPLICATION,
	KB_POWER,
	KB_KP_EQUALS,
	KB_F13,
	KB_F14,
	KB_F15,
	KB_F16,
	KB_F17,
	KB_F18,
	KB_F19,
	KB_F20,
	KB_F21,
	KB_F22,
	KB_F23,
	KB_F24,
	KB_EXECUTE,
	KB_HELP,
	KB_MENU,
	KB_SELECT,
	KB_STOP,
	KB_AGAIN,
	KB_UNDO,
	KB_CUT,
	KB_COPY,
	KB_PASTE,
	KB_FIND,
	KB_MUTE,
	KB_VOLUMEUP,
	KB_VOLUMEDOWN,
	KB_KP_COMMA,
	KB_KP_EQUALSAS400,
	KB_ALTERASE,
	KB_SYSREQ,
	KB_CANCEL,
	KB_CLEAR,
	KB_PRIOR,
	KB_RETURN2,
	KB_SEPARATOR,
	KB_OUT,
	KB_OPER,
	KB_CLEARAGAIN,
	KB_CRSEL,
	KB_EXSEL,
	KB_KP_00,
	KB_KP_000,
	KB_THOUSANDSSEPARATOR,
	KB_DECIMALSEPARATOR,
	KB_CURRENCYUNIT,
	KB_CURRENCYSUBUNIT,
	KB_KP_LEFTPAREN,
	KB_KP_RIGHTPAREN,
	KB_KP_LEFTBRACE,
	KB_KP_RIGHTBRACE,
	KB_KP_TAB,
	KB_KP_BACKSPACE,
	KB_KP_A,
	KB_KP_B,
	KB_KP_C,
	KB_KP_D,
	KB_KP_E,
	KB_KP_F,
	KB_KP_XOR,
	KB_KP_POWER,
	KB_KP_PERCENT,
	KB_KP_LESS,
	KB_KP_GREATER,
	KB_KP_AMPERSAND,
	KB_KP_DBLAMPERSAND,
	KB_KP_VERTICALBAR,
	KB_KP_DBLVERTICALBAR,
	KB_KP_COLON,
	KB_KP_HASH,
	KB_KP_SPACE,
	KB_KP_AT,
	KB_KP_EXCLAM,
	KB_KP_MEMSTORE,
	KB_KP_MEMRECALL,
	KB_KP_MEMCLEAR,
	KB_KP_MEMADD,
	KB_KP_MEMSUBTRACT,
	KB_KP_MEMMULTIPLY,
	KB_KP_MEMDIVIDE,
	KB_KP_PLUSMINUS,
	KB_KP_CLEAR,
	KB_KP_CLEARENTRY,
	KB_KP_BINARY,
	KB_KP_OCTAL,
	KB_KP_DECIMAL,
	KB_KP_HEXADECIMAL,
	KB_LCTRL,
	KB_LSHIFT,
	KB_LALT,
	KB_LGUI,
	KB_RCTRL,
	KB_RSHIFT,
	KB_RALT,
	KB_RGUI,
	KB_MODE,
	KB_AUDIONEXT,
	KB_AUDIOPREV,
	KB_AUDIOSTOP,
	KB_AUDIOPLAY,
	KB_AUDIOMUTE,
	KB_MEDIASELECT,
	KB_WWW,
	KB_MAIL,
	KB_CALCULATOR,
	KB_COMPUTER,
	KB_AC_SEARCH,
	KB_AC_HOME,
	KB_AC_BACK,
	KB_AC_FORWARD,
	KB_AC_STOP,
	KB_AC_REFRESH,
	KB_AC_BOOKMARKS,
	KB_BRIGHTNESSDOWN,
	KB_BRIGHTNESSUP,
	KB_DISPLAYSWITCH,
	KB_KBDILLUMTOGGLE,
	KB_KBDILLUMDOWN,
	KB_KBDILLUMUP,
	KB_EJECT,
	KB_SLEEP,

	KB_COUNT,
};
enum MouseButton
{
	MB_UNKNOWN,
	MB_LEFT,
	MB_MIDDLE,
	MB_RIGHT,
	MB_SPECIAL1,
	MB_SPECIAL2,

	MB_COUNT,
};
enum MouseAxis
{
	MA_X,
	MA_Y,
	MA_WHEEL,
};
enum DPadState
{
	DPS_UP,
	DPS_RIGHT,
	DPS_DOWN,
	DPS_LEFT,
};

inline SDL_Keycode KBToSDL(KeyboardButton kb)
{
	switch (kb)
	{
	case KB_UNKNOWN: return SDLK_UNKNOWN;
	case KB_BACKSPACE: return SDLK_BACKSPACE;
	case KB_TAB: return SDLK_TAB;
	case KB_RETURN: return SDLK_RETURN;
	case KB_ESCAPE: return SDLK_ESCAPE;
	case KB_SPACE: return SDLK_SPACE;
	case KB_EXCLAIM: return SDLK_EXCLAIM;
	case KB_QUOTEDBL: return SDLK_QUOTEDBL;
	case KB_HASH: return SDLK_HASH;
	case KB_DOLLAR: return SDLK_DOLLAR;
	case KB_PERCENT: return SDLK_PERCENT;
	case KB_AMPERSAND: return SDLK_AMPERSAND;
	case KB_QUOTE: return SDLK_QUOTE;
	case KB_LEFTPAREN: return SDLK_LEFTPAREN;
	case KB_RIGHTPAREN: return SDLK_RIGHTPAREN;
	case KB_ASTERISK: return SDLK_ASTERISK;
	case KB_PLUS: return SDLK_PLUS;
	case KB_COMMA: return SDLK_COMMA;
	case KB_MINUS: return SDLK_MINUS;
	case KB_PERIOD: return SDLK_PERIOD;
	case KB_SLASH: return SDLK_SLASH;
	case KB_0: return SDLK_0;
	case KB_1: return SDLK_1;
	case KB_2: return SDLK_2;
	case KB_3: return SDLK_3;
	case KB_4: return SDLK_4;
	case KB_5: return SDLK_5;
	case KB_6: return SDLK_6;
	case KB_7: return SDLK_7;
	case KB_8: return SDLK_8;
	case KB_9: return SDLK_9;
	case KB_COLON: return SDLK_COLON;
	case KB_SEMICOLON: return SDLK_SEMICOLON;
	case KB_LESS: return SDLK_LESS;
	case KB_EQUALS: return SDLK_EQUALS;
	case KB_GREATER: return SDLK_GREATER;
	case KB_QUESTION: return SDLK_QUESTION;
	case KB_AT: return SDLK_AT;
	case KB_LEFTBRACKET: return SDLK_LEFTBRACKET;
	case KB_BACKSLASH: return SDLK_BACKSLASH;
	case KB_RIGHTBRACKET: return SDLK_RIGHTBRACKET;
	case KB_CARET: return SDLK_CARET;
	case KB_UNDERSCORE: return SDLK_UNDERSCORE;
	case KB_BACKQUOTE: return SDLK_BACKQUOTE;
	case KB_A: return SDLK_a;
	case KB_B: return SDLK_b;
	case KB_C: return SDLK_c;
	case KB_D: return SDLK_d;
	case KB_E: return SDLK_e;
	case KB_F: return SDLK_f;
	case KB_G: return SDLK_g;
	case KB_H: return SDLK_h;
	case KB_I: return SDLK_i;
	case KB_J: return SDLK_j;
	case KB_K: return SDLK_k;
	case KB_L: return SDLK_l;
	case KB_M: return SDLK_m;
	case KB_N: return SDLK_n;
	case KB_O: return SDLK_o;
	case KB_P: return SDLK_p;
	case KB_Q: return SDLK_q;
	case KB_R: return SDLK_r;
	case KB_S: return SDLK_s;
	case KB_T: return SDLK_t;
	case KB_U: return SDLK_u;
	case KB_V: return SDLK_v;
	case KB_W: return SDLK_w;
	case KB_X: return SDLK_x;
	case KB_Y: return SDLK_y;
	case KB_Z: return SDLK_z;
	case KB_DELETE: return SDLK_DELETE;
	case KB_CAPSLOCK: return SDLK_CAPSLOCK;
	case KB_F1: return SDLK_F1;
	case KB_F2: return SDLK_F2;
	case KB_F3: return SDLK_F3;
	case KB_F4: return SDLK_F4;
	case KB_F5: return SDLK_F5;
	case KB_F6: return SDLK_F6;
	case KB_F7: return SDLK_F7;
	case KB_F8: return SDLK_F8;
	case KB_F9: return SDLK_F9;
	case KB_F10: return SDLK_F10;
	case KB_F11: return SDLK_F11;
	case KB_F12: return SDLK_F12;
	case KB_PRINTSCREEN: return SDLK_PRINTSCREEN;
	case KB_SCROLLLOCK: return SDLK_SCROLLLOCK;
	case KB_PAUSE: return SDLK_PAUSE;
	case KB_INSERT: return SDLK_INSERT;
	case KB_HOME: return SDLK_HOME;
	case KB_PAGEUP: return SDLK_PAGEUP;
	case KB_END: return SDLK_END;
	case KB_PAGEDOWN: return SDLK_PAGEDOWN;
	case KB_RIGHT: return SDLK_RIGHT;
	case KB_LEFT: return SDLK_LEFT;
	case KB_DOWN: return SDLK_DOWN;
	case KB_UP: return SDLK_UP;
	case KB_NUMLOCKCLEAR: return SDLK_NUMLOCKCLEAR;
	case KB_KP_DIVIDE: return SDLK_KP_DIVIDE;
	case KB_KP_MULTIPLY: return SDLK_KP_MULTIPLY;
	case KB_KP_MINUS: return SDLK_KP_MINUS;
	case KB_KP_PLUS: return SDLK_KP_PLUS;
	case KB_KP_ENTER: return SDLK_KP_ENTER;
	case KB_KP_1: return SDLK_KP_1;
	case KB_KP_2: return SDLK_KP_2;
	case KB_KP_3: return SDLK_KP_3;
	case KB_KP_4: return SDLK_KP_4;
	case KB_KP_5: return SDLK_KP_5;
	case KB_KP_6: return SDLK_KP_6;
	case KB_KP_7: return SDLK_KP_7;
	case KB_KP_8: return SDLK_KP_8;
	case KB_KP_9: return SDLK_KP_9;
	case KB_KP_0: return SDLK_KP_0;
	case KB_KP_PERIOD: return SDLK_KP_PERIOD;
	case KB_APPLICATION: return SDLK_APPLICATION;
	case KB_POWER: return SDLK_POWER;
	case KB_KP_EQUALS: return SDLK_KP_EQUALS;
	case KB_F13: return SDLK_F13;
	case KB_F14: return SDLK_F14;
	case KB_F15: return SDLK_F15;
	case KB_F16: return SDLK_F16;
	case KB_F17: return SDLK_F17;
	case KB_F18: return SDLK_F18;
	case KB_F19: return SDLK_F19;
	case KB_F20: return SDLK_F20;
	case KB_F21: return SDLK_F21;
	case KB_F22: return SDLK_F22;
	case KB_F23: return SDLK_F23;
	case KB_F24: return SDLK_F24;
	case KB_EXECUTE: return SDLK_EXECUTE;
	case KB_HELP: return SDLK_HELP;
	case KB_MENU: return SDLK_MENU;
	case KB_SELECT: return SDLK_SELECT;
	case KB_STOP: return SDLK_STOP;
	case KB_AGAIN: return SDLK_AGAIN;
	case KB_UNDO: return SDLK_UNDO;
	case KB_CUT: return SDLK_CUT;
	case KB_COPY: return SDLK_COPY;
	case KB_PASTE: return SDLK_PASTE;
	case KB_FIND: return SDLK_FIND;
	case KB_MUTE: return SDLK_MUTE;
	case KB_VOLUMEUP: return SDLK_VOLUMEUP;
	case KB_VOLUMEDOWN: return SDLK_VOLUMEDOWN;
	case KB_KP_COMMA: return SDLK_KP_COMMA;
	case KB_KP_EQUALSAS400: return SDLK_KP_EQUALSAS400;
	case KB_ALTERASE: return SDLK_ALTERASE;
	case KB_SYSREQ: return SDLK_SYSREQ;
	case KB_CANCEL: return SDLK_CANCEL;
	case KB_CLEAR: return SDLK_CLEAR;
	case KB_PRIOR: return SDLK_PRIOR;
	case KB_RETURN2: return SDLK_RETURN2;
	case KB_SEPARATOR: return SDLK_SEPARATOR;
	case KB_OUT: return SDLK_OUT;
	case KB_OPER: return SDLK_OPER;
	case KB_CLEARAGAIN: return SDLK_CLEARAGAIN;
	case KB_CRSEL: return SDLK_CRSEL;
	case KB_EXSEL: return SDLK_EXSEL;
	case KB_KP_00: return SDLK_KP_00;
	case KB_KP_000: return SDLK_KP_000;
	case KB_THOUSANDSSEPARATOR: return SDLK_THOUSANDSSEPARATOR;
	case KB_DECIMALSEPARATOR: return SDLK_DECIMALSEPARATOR;
	case KB_CURRENCYUNIT: return SDLK_CURRENCYUNIT;
	case KB_CURRENCYSUBUNIT: return SDLK_CURRENCYSUBUNIT;
	case KB_KP_LEFTPAREN: return SDLK_KP_LEFTPAREN;
	case KB_KP_RIGHTPAREN: return SDLK_KP_RIGHTPAREN;
	case KB_KP_LEFTBRACE: return SDLK_KP_LEFTBRACE;
	case KB_KP_RIGHTBRACE: return SDLK_KP_RIGHTBRACE;
	case KB_KP_TAB: return SDLK_KP_TAB;
	case KB_KP_BACKSPACE: return SDLK_KP_BACKSPACE;
	case KB_KP_A: return SDLK_KP_A;
	case KB_KP_B: return SDLK_KP_B;
	case KB_KP_C: return SDLK_KP_C;
	case KB_KP_D: return SDLK_KP_D;
	case KB_KP_E: return SDLK_KP_E;
	case KB_KP_F: return SDLK_KP_F;
	case KB_KP_XOR: return SDLK_KP_XOR;
	case KB_KP_POWER: return SDLK_KP_POWER;
	case KB_KP_PERCENT: return SDLK_KP_PERCENT;
	case KB_KP_LESS: return SDLK_KP_LESS;
	case KB_KP_GREATER: return SDLK_KP_GREATER;
	case KB_KP_AMPERSAND: return SDLK_KP_AMPERSAND;
	case KB_KP_DBLAMPERSAND: return SDLK_KP_DBLAMPERSAND;
	case KB_KP_VERTICALBAR: return SDLK_KP_VERTICALBAR;
	case KB_KP_DBLVERTICALBAR: return SDLK_KP_DBLVERTICALBAR;
	case KB_KP_COLON: return SDLK_KP_COLON;
	case KB_KP_HASH: return SDLK_KP_HASH;
	case KB_KP_SPACE: return SDLK_KP_SPACE;
	case KB_KP_AT: return SDLK_KP_AT;
	case KB_KP_EXCLAM: return SDLK_KP_EXCLAM;
	case KB_KP_MEMSTORE: return SDLK_KP_MEMSTORE;
	case KB_KP_MEMRECALL: return SDLK_KP_MEMRECALL;
	case KB_KP_MEMCLEAR: return SDLK_KP_MEMCLEAR;
	case KB_KP_MEMADD: return SDLK_KP_MEMADD;
	case KB_KP_MEMSUBTRACT: return SDLK_KP_MEMSUBTRACT;
	case KB_KP_MEMMULTIPLY: return SDLK_KP_MEMMULTIPLY;
	case KB_KP_MEMDIVIDE: return SDLK_KP_MEMDIVIDE;
	case KB_KP_PLUSMINUS: return SDLK_KP_PLUSMINUS;
	case KB_KP_CLEAR: return SDLK_KP_CLEAR;
	case KB_KP_CLEARENTRY: return SDLK_KP_CLEARENTRY;
	case KB_KP_BINARY: return SDLK_KP_BINARY;
	case KB_KP_OCTAL: return SDLK_KP_OCTAL;
	case KB_KP_DECIMAL: return SDLK_KP_DECIMAL;
	case KB_KP_HEXADECIMAL: return SDLK_KP_HEXADECIMAL;
	case KB_LCTRL: return SDLK_LCTRL;
	case KB_LSHIFT: return SDLK_LSHIFT;
	case KB_LALT: return SDLK_LALT;
	case KB_LGUI: return SDLK_LGUI;
	case KB_RCTRL: return SDLK_RCTRL;
	case KB_RSHIFT: return SDLK_RSHIFT;
	case KB_RALT: return SDLK_RALT;
	case KB_RGUI: return SDLK_RGUI;
	case KB_MODE: return SDLK_MODE;
	case KB_AUDIONEXT: return SDLK_AUDIONEXT;
	case KB_AUDIOPREV: return SDLK_AUDIOPREV;
	case KB_AUDIOSTOP: return SDLK_AUDIOSTOP;
	case KB_AUDIOPLAY: return SDLK_AUDIOPLAY;
	case KB_AUDIOMUTE: return SDLK_AUDIOMUTE;
	case KB_MEDIASELECT: return SDLK_MEDIASELECT;
	case KB_WWW: return SDLK_WWW;
	case KB_MAIL: return SDLK_MAIL;
	case KB_CALCULATOR: return SDLK_CALCULATOR;
	case KB_COMPUTER: return SDLK_COMPUTER;
	case KB_AC_SEARCH: return SDLK_AC_SEARCH;
	case KB_AC_HOME: return SDLK_AC_HOME;
	case KB_AC_BACK: return SDLK_AC_BACK;
	case KB_AC_FORWARD: return SDLK_AC_FORWARD;
	case KB_AC_STOP: return SDLK_AC_STOP;
	case KB_AC_REFRESH: return SDLK_AC_REFRESH;
	case KB_AC_BOOKMARKS: return SDLK_AC_BOOKMARKS;
	case KB_BRIGHTNESSDOWN: return SDLK_BRIGHTNESSDOWN;
	case KB_BRIGHTNESSUP: return SDLK_BRIGHTNESSUP;
	case KB_DISPLAYSWITCH: return SDLK_DISPLAYSWITCH;
	case KB_KBDILLUMTOGGLE: return SDLK_KBDILLUMTOGGLE;
	case KB_KBDILLUMDOWN: return SDLK_KBDILLUMDOWN;
	case KB_KBDILLUMUP: return SDLK_KBDILLUMUP;
	case KB_EJECT: return SDLK_EJECT;
	case KB_SLEEP: return SDLK_SLEEP;
	}

	return SDLK_UNKNOWN;
}
inline KeyboardButton SDLToKB(SDL_Keycode sdlkb)
{
	switch (sdlkb)
	{
	case SDLK_UNKNOWN: return KB_UNKNOWN;
	case SDLK_BACKSPACE: return KB_BACKSPACE;
	case SDLK_TAB: return KB_TAB;
	case SDLK_RETURN: return KB_RETURN;
	case SDLK_ESCAPE: return KB_ESCAPE;
	case SDLK_SPACE: return KB_SPACE;
	case SDLK_EXCLAIM: return KB_EXCLAIM;
	case SDLK_QUOTEDBL: return KB_QUOTEDBL;
	case SDLK_HASH: return KB_HASH;
	case SDLK_DOLLAR: return KB_DOLLAR;
	case SDLK_PERCENT: return KB_PERCENT;
	case SDLK_AMPERSAND: return KB_AMPERSAND;
	case SDLK_QUOTE: return KB_QUOTE;
	case SDLK_LEFTPAREN: return KB_LEFTPAREN;
	case SDLK_RIGHTPAREN: return KB_RIGHTPAREN;
	case SDLK_ASTERISK: return KB_ASTERISK;
	case SDLK_PLUS: return KB_PLUS;
	case SDLK_COMMA: return KB_COMMA;
	case SDLK_MINUS: return KB_MINUS;
	case SDLK_PERIOD: return KB_PERIOD;
	case SDLK_SLASH: return KB_SLASH;
	case SDLK_0: return KB_0;
	case SDLK_1: return KB_1;
	case SDLK_2: return KB_2;
	case SDLK_3: return KB_3;
	case SDLK_4: return KB_4;
	case SDLK_5: return KB_5;
	case SDLK_6: return KB_6;
	case SDLK_7: return KB_7;
	case SDLK_8: return KB_8;
	case SDLK_9: return KB_9;
	case SDLK_COLON: return KB_COLON;
	case SDLK_SEMICOLON: return KB_SEMICOLON;
	case SDLK_LESS: return KB_LESS;
	case SDLK_EQUALS: return KB_EQUALS;
	case SDLK_GREATER: return KB_GREATER;
	case SDLK_QUESTION: return KB_QUESTION;
	case SDLK_AT: return KB_AT;
	case SDLK_LEFTBRACKET: return KB_LEFTBRACKET;
	case SDLK_BACKSLASH: return KB_BACKSLASH;
	case SDLK_RIGHTBRACKET: return KB_RIGHTBRACKET;
	case SDLK_CARET: return KB_CARET;
	case SDLK_UNDERSCORE: return KB_UNDERSCORE;
	case SDLK_BACKQUOTE: return KB_BACKQUOTE;
	case SDLK_a: return KB_A;
	case SDLK_b: return KB_B;
	case SDLK_c: return KB_C;
	case SDLK_d: return KB_D;
	case SDLK_e: return KB_E;
	case SDLK_f: return KB_F;
	case SDLK_g: return KB_G;
	case SDLK_h: return KB_H;
	case SDLK_i: return KB_I;
	case SDLK_j: return KB_J;
	case SDLK_k: return KB_K;
	case SDLK_l: return KB_L;
	case SDLK_m: return KB_M;
	case SDLK_n: return KB_N;
	case SDLK_o: return KB_O;
	case SDLK_p: return KB_P;
	case SDLK_q: return KB_Q;
	case SDLK_r: return KB_R;
	case SDLK_s: return KB_S;
	case SDLK_t: return KB_T;
	case SDLK_u: return KB_U;
	case SDLK_v: return KB_V;
	case SDLK_w: return KB_W;
	case SDLK_x: return KB_X;
	case SDLK_y: return KB_Y;
	case SDLK_z: return KB_Z;
	case SDLK_DELETE: return KB_DELETE;
	case SDLK_CAPSLOCK: return KB_CAPSLOCK;
	case SDLK_F1: return KB_F1;
	case SDLK_F2: return KB_F2;
	case SDLK_F3: return KB_F3;
	case SDLK_F4: return KB_F4;
	case SDLK_F5: return KB_F5;
	case SDLK_F6: return KB_F6;
	case SDLK_F7: return KB_F7;
	case SDLK_F8: return KB_F8;
	case SDLK_F9: return KB_F9;
	case SDLK_F10: return KB_F10;
	case SDLK_F11: return KB_F11;
	case SDLK_F12: return KB_F12;
	case SDLK_PRINTSCREEN: return KB_PRINTSCREEN;
	case SDLK_SCROLLLOCK: return KB_SCROLLLOCK;
	case SDLK_PAUSE: return KB_PAUSE;
	case SDLK_INSERT: return KB_INSERT;
	case SDLK_HOME: return KB_HOME;
	case SDLK_PAGEUP: return KB_PAGEUP;
	case SDLK_END: return KB_END;
	case SDLK_PAGEDOWN: return KB_PAGEDOWN;
	case SDLK_RIGHT: return KB_RIGHT;
	case SDLK_LEFT: return KB_LEFT;
	case SDLK_DOWN: return KB_DOWN;
	case SDLK_UP: return KB_UP;
	case SDLK_NUMLOCKCLEAR: return KB_NUMLOCKCLEAR;
	case SDLK_KP_DIVIDE: return KB_KP_DIVIDE;
	case SDLK_KP_MULTIPLY: return KB_KP_MULTIPLY;
	case SDLK_KP_MINUS: return KB_KP_MINUS;
	case SDLK_KP_PLUS: return KB_KP_PLUS;
	case SDLK_KP_ENTER: return KB_KP_ENTER;
	case SDLK_KP_1: return KB_KP_1;
	case SDLK_KP_2: return KB_KP_2;
	case SDLK_KP_3: return KB_KP_3;
	case SDLK_KP_4: return KB_KP_4;
	case SDLK_KP_5: return KB_KP_5;
	case SDLK_KP_6: return KB_KP_6;
	case SDLK_KP_7: return KB_KP_7;
	case SDLK_KP_8: return KB_KP_8;
	case SDLK_KP_9: return KB_KP_9;
	case SDLK_KP_0: return KB_KP_0;
	case SDLK_KP_PERIOD: return KB_KP_PERIOD;
	case SDLK_APPLICATION: return KB_APPLICATION;
	case SDLK_POWER: return KB_POWER;
	case SDLK_KP_EQUALS: return KB_KP_EQUALS;
	case SDLK_F13: return KB_F13;
	case SDLK_F14: return KB_F14;
	case SDLK_F15: return KB_F15;
	case SDLK_F16: return KB_F16;
	case SDLK_F17: return KB_F17;
	case SDLK_F18: return KB_F18;
	case SDLK_F19: return KB_F19;
	case SDLK_F20: return KB_F20;
	case SDLK_F21: return KB_F21;
	case SDLK_F22: return KB_F22;
	case SDLK_F23: return KB_F23;
	case SDLK_F24: return KB_F24;
	case SDLK_EXECUTE: return KB_EXECUTE;
	case SDLK_HELP: return KB_HELP;
	case SDLK_MENU: return KB_MENU;
	case SDLK_SELECT: return KB_SELECT;
	case SDLK_STOP: return KB_STOP;
	case SDLK_AGAIN: return KB_AGAIN;
	case SDLK_UNDO: return KB_UNDO;
	case SDLK_CUT: return KB_CUT;
	case SDLK_COPY: return KB_COPY;
	case SDLK_PASTE: return KB_PASTE;
	case SDLK_FIND: return KB_FIND;
	case SDLK_MUTE: return KB_MUTE;
	case SDLK_VOLUMEUP: return KB_VOLUMEUP;
	case SDLK_VOLUMEDOWN: return KB_VOLUMEDOWN;
	case SDLK_KP_COMMA: return KB_KP_COMMA;
	case SDLK_KP_EQUALSAS400: return KB_KP_EQUALSAS400;
	case SDLK_ALTERASE: return KB_ALTERASE;
	case SDLK_SYSREQ: return KB_SYSREQ;
	case SDLK_CANCEL: return KB_CANCEL;
	case SDLK_CLEAR: return KB_CLEAR;
	case SDLK_PRIOR: return KB_PRIOR;
	case SDLK_RETURN2: return KB_RETURN2;
	case SDLK_SEPARATOR: return KB_SEPARATOR;
	case SDLK_OUT: return KB_OUT;
	case SDLK_OPER: return KB_OPER;
	case SDLK_CLEARAGAIN: return KB_CLEARAGAIN;
	case SDLK_CRSEL: return KB_CRSEL;
	case SDLK_EXSEL: return KB_EXSEL;
	case SDLK_KP_00: return KB_KP_00;
	case SDLK_KP_000: return KB_KP_000;
	case SDLK_THOUSANDSSEPARATOR: return KB_THOUSANDSSEPARATOR;
	case SDLK_DECIMALSEPARATOR: return KB_DECIMALSEPARATOR;
	case SDLK_CURRENCYUNIT: return KB_CURRENCYUNIT;
	case SDLK_CURRENCYSUBUNIT: return KB_CURRENCYSUBUNIT;
	case SDLK_KP_LEFTPAREN: return KB_KP_LEFTPAREN;
	case SDLK_KP_RIGHTPAREN: return KB_KP_RIGHTPAREN;
	case SDLK_KP_LEFTBRACE: return KB_KP_LEFTBRACE;
	case SDLK_KP_RIGHTBRACE: return KB_KP_RIGHTBRACE;
	case SDLK_KP_TAB: return KB_KP_TAB;
	case SDLK_KP_BACKSPACE: return KB_KP_BACKSPACE;
	case SDLK_KP_A: return KB_KP_A;
	case SDLK_KP_B: return KB_KP_B;
	case SDLK_KP_C: return KB_KP_C;
	case SDLK_KP_D: return KB_KP_D;
	case SDLK_KP_E: return KB_KP_E;
	case SDLK_KP_F: return KB_KP_F;
	case SDLK_KP_XOR: return KB_KP_XOR;
	case SDLK_KP_POWER: return KB_KP_POWER;
	case SDLK_KP_PERCENT: return KB_KP_PERCENT;
	case SDLK_KP_LESS: return KB_KP_LESS;
	case SDLK_KP_GREATER: return KB_KP_GREATER;
	case SDLK_KP_AMPERSAND: return KB_KP_AMPERSAND;
	case SDLK_KP_DBLAMPERSAND: return KB_KP_DBLAMPERSAND;
	case SDLK_KP_VERTICALBAR: return KB_KP_VERTICALBAR;
	case SDLK_KP_DBLVERTICALBAR: return KB_KP_DBLVERTICALBAR;
	case SDLK_KP_COLON: return KB_KP_COLON;
	case SDLK_KP_HASH: return KB_KP_HASH;
	case SDLK_KP_SPACE: return KB_KP_SPACE;
	case SDLK_KP_AT: return KB_KP_AT;
	case SDLK_KP_EXCLAM: return KB_KP_EXCLAM;
	case SDLK_KP_MEMSTORE: return KB_KP_MEMSTORE;
	case SDLK_KP_MEMRECALL: return KB_KP_MEMRECALL;
	case SDLK_KP_MEMCLEAR: return KB_KP_MEMCLEAR;
	case SDLK_KP_MEMADD: return KB_KP_MEMADD;
	case SDLK_KP_MEMSUBTRACT: return KB_KP_MEMSUBTRACT;
	case SDLK_KP_MEMMULTIPLY: return KB_KP_MEMMULTIPLY;
	case SDLK_KP_MEMDIVIDE: return KB_KP_MEMDIVIDE;
	case SDLK_KP_PLUSMINUS: return KB_KP_PLUSMINUS;
	case SDLK_KP_CLEAR: return KB_KP_CLEAR;
	case SDLK_KP_CLEARENTRY: return KB_KP_CLEARENTRY;
	case SDLK_KP_BINARY: return KB_KP_BINARY;
	case SDLK_KP_OCTAL: return KB_KP_OCTAL;
	case SDLK_KP_DECIMAL: return KB_KP_DECIMAL;
	case SDLK_KP_HEXADECIMAL: return KB_KP_HEXADECIMAL;
	case SDLK_LCTRL: return KB_LCTRL;
	case SDLK_LSHIFT: return KB_LSHIFT;
	case SDLK_LALT: return KB_LALT;
	case SDLK_LGUI: return KB_LGUI;
	case SDLK_RCTRL: return KB_RCTRL;
	case SDLK_RSHIFT: return KB_RSHIFT;
	case SDLK_RALT: return KB_RALT;
	case SDLK_RGUI: return KB_RGUI;
	case SDLK_MODE: return KB_MODE;
	case SDLK_AUDIONEXT: return KB_AUDIONEXT;
	case SDLK_AUDIOPREV: return KB_AUDIOPREV;
	case SDLK_AUDIOSTOP: return KB_AUDIOSTOP;
	case SDLK_AUDIOPLAY: return KB_AUDIOPLAY;
	case SDLK_AUDIOMUTE: return KB_AUDIOMUTE;
	case SDLK_MEDIASELECT: return KB_MEDIASELECT;
	case SDLK_WWW: return KB_WWW;
	case SDLK_MAIL: return KB_MAIL;
	case SDLK_CALCULATOR: return KB_CALCULATOR;
	case SDLK_COMPUTER: return KB_COMPUTER;
	case SDLK_AC_SEARCH: return KB_AC_SEARCH;
	case SDLK_AC_HOME: return KB_AC_HOME;
	case SDLK_AC_BACK: return KB_AC_BACK;
	case SDLK_AC_FORWARD: return KB_AC_FORWARD;
	case SDLK_AC_STOP: return KB_AC_STOP;
	case SDLK_AC_REFRESH: return KB_AC_REFRESH;
	case SDLK_AC_BOOKMARKS: return KB_AC_BOOKMARKS;
	case SDLK_BRIGHTNESSDOWN: return KB_BRIGHTNESSDOWN;
	case SDLK_BRIGHTNESSUP: return KB_BRIGHTNESSUP;
	case SDLK_DISPLAYSWITCH: return KB_DISPLAYSWITCH;
	case SDLK_KBDILLUMTOGGLE: return KB_KBDILLUMTOGGLE;
	case SDLK_KBDILLUMDOWN: return KB_KBDILLUMDOWN;
	case SDLK_KBDILLUMUP: return KB_KBDILLUMUP;
	case SDLK_EJECT: return KB_EJECT;
	case SDLK_SLEEP: return KB_SLEEP;
	}

	return KB_UNKNOWN;
}
inline unsigned char MBToSDL(MouseButton mb)
{
	if (mb >= MB_LEFT && mb <= MB_SPECIAL2)
	{
		return (unsigned char)mb;
	}
	else
	{
		return 0;
	}
}
inline MouseButton SDLToMB(unsigned char sdlmb)
{
	return (MouseButton)sdlmb;
}
inline void TranslateSDLDPadStateToArray(unsigned char sdl, std::array<bool, 4>* pArray)
{
	switch (sdl)
	{
	case SDL_HAT_CENTERED:
		(*pArray)[DPS_UP] = false;
		(*pArray)[DPS_RIGHT] = false;
		(*pArray)[DPS_DOWN] = false;
		(*pArray)[DPS_LEFT] = false;
		break;

	case SDL_HAT_UP:
		(*pArray)[DPS_UP] = true;
		(*pArray)[DPS_RIGHT] = false;
		(*pArray)[DPS_DOWN] = false;
		(*pArray)[DPS_LEFT] = false;
		break;

	case SDL_HAT_RIGHTUP:
		(*pArray)[DPS_UP] = true;
		(*pArray)[DPS_RIGHT] = true;
		(*pArray)[DPS_DOWN] = false;
		(*pArray)[DPS_LEFT] = false;
		break;

	case SDL_HAT_RIGHT:
		(*pArray)[DPS_UP] = false;
		(*pArray)[DPS_RIGHT] = true;
		(*pArray)[DPS_DOWN] = false;
		(*pArray)[DPS_LEFT] = false;
		break;

	case SDL_HAT_RIGHTDOWN:
		(*pArray)[DPS_UP] = false;
		(*pArray)[DPS_RIGHT] = true;
		(*pArray)[DPS_DOWN] = true;
		(*pArray)[DPS_LEFT] = false;
		break;

	case SDL_HAT_DOWN:
		(*pArray)[DPS_UP] = false;
		(*pArray)[DPS_RIGHT] = false;
		(*pArray)[DPS_DOWN] = true;
		(*pArray)[DPS_LEFT] = false;
		break;

	case SDL_HAT_LEFTDOWN:
		(*pArray)[DPS_UP] = false;
		(*pArray)[DPS_RIGHT] = false;
		(*pArray)[DPS_DOWN] = true;
		(*pArray)[DPS_LEFT] = true;
		break;

	case SDL_HAT_LEFT:
		(*pArray)[DPS_UP] = false;
		(*pArray)[DPS_RIGHT] = false;
		(*pArray)[DPS_DOWN] = false;
		(*pArray)[DPS_LEFT] = true;
		break;

	case SDL_HAT_LEFTUP:
		(*pArray)[DPS_UP] = true;
		(*pArray)[DPS_RIGHT] = false;
		(*pArray)[DPS_DOWN] = false;
		(*pArray)[DPS_LEFT] = true;
		break;
	}
}

#endif