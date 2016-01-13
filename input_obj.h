#ifndef INPUT_OBJ_H
#define INPUT_OBJ_H

#include "keyboard_defs.h"
#include "mouse_defs.h"


enum class DeviceType
{
	Keyboard,
	Mouse,
};

enum class InputType
{
	Button,
	Axis,
};

struct InputObj
{
	DeviceType deviceType;
	unsigned deviceID;
	InputType inputType;
	unsigned inputID;

	InputObj() = default;
	InputObj(DeviceType dt, unsigned did, InputType it, unsigned iid) 
		: deviceType(dt), deviceID(did), inputType(it), inputID(iid) {}

	static bool Detect(const SDL_Event& event, InputObj* pOut)
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			pOut->deviceType = DeviceType::Keyboard;
			pOut->deviceID = 0;
			pOut->inputType = InputType::Button;
			pOut->inputID = SDLToKB(event.key.keysym.sym);
			return true;

		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
			pOut->deviceType = DeviceType::Mouse;
			pOut->deviceID = 0;
			pOut->inputType = InputType::Button;
			pOut->inputID = SDLToMB(event.button.button);
			return true;

		case SDL_MOUSEMOTION:
			pOut->deviceType = DeviceType::Mouse;
			pOut->deviceID = 0;
			pOut->inputType = InputType::Axis;
			if (abs(event.motion.xrel) > abs(event.motion.yrel))
			{
				if (event.motion.xrel > 0) pOut->inputID = MA_X_POS;
				else pOut->inputID = MA_X_NEG;
			}
			else
			{
				if (event.motion.yrel > 0) pOut->inputID = MA_Y_POS;
				else pOut->inputID = MA_Y_NEG;
			}
			return true;

		case SDL_MOUSEWHEEL:
			pOut->deviceType = DeviceType::Mouse;
			pOut->deviceID = 0;
			pOut->inputType = InputType::Axis;
			if (event.wheel.x > 0) pOut->inputID = MA_WHEEL_POS;
			else pOut->inputID = MA_WHEEL_NEG;
			return true;
		}

		return false;
	}
};

#endif