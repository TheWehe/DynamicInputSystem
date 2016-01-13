#ifndef MOUSE_DEFS_H
#define MOUSE_DEFS_H

#include <SDL.h>


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
	MA_X_POS,
	MA_X_NEG,
	MA_Y_POS,
	MA_Y_NEG,

	MA_WHEEL_POS,
	MA_WHEEL_NEG,
};

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

#endif