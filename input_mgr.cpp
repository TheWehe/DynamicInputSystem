#include "input_mgr.h"

InputMgr::InputMgr()
{
	for (int i = 0; i < KB_COUNT; i++)
	{
		m_keyboardButtonStates[i] = false;
		m_lastKeyboardButtonStates[i] = false;
	}

	for (int i = 0; i < MB_COUNT; i++)
	{
		m_mouseButtonStates[i] = false;
		m_lastMouseButtonStates[i] = false;
	}
}

bool InputMgr::Init()
{
	return OnFocusGained();
}

void InputMgr::Release()
{
	OnFocusLost();
}

bool InputMgr::OnFocusGained()
{
	if (SDL_CaptureMouse(SDL_TRUE) != 0) return false;
	if (SDL_SetRelativeMouseMode(SDL_TRUE) != 0) return false;

	return true;
}

void InputMgr::OnFocusLost()
{
	SDL_CaptureMouse(SDL_FALSE);
	SDL_SetRelativeMouseMode(SDL_FALSE);
}

void InputMgr::OnPreEventLoop()
{
	for (int i = 0; i < KB_COUNT; i++)
	{
		m_lastKeyboardButtonStates[i] = m_keyboardButtonStates[i];
	}

	for (int i = 0; i < MB_COUNT; i++)
	{
		m_lastMouseButtonStates[i] = m_mouseButtonStates[i];
	}

	m_lastMouseDeltaX = m_mouseDeltaX;
	m_mouseDeltaX = 0;
	m_lastMouseDeltaY = m_mouseDeltaY;
	m_mouseDeltaY = 0;

	m_lastMouseWheelDelta = m_mouseWheelDelta;
	m_mouseWheelDelta = 0;
}

void InputMgr::OnEvent(const SDL_Event& event)
{
	switch (event.type)
	{
	case SDL_KEYDOWN:
		m_keyboardButtonStates[SDLToKB(event.key.keysym.sym)] = true;
		break;

	case SDL_KEYUP:
		m_keyboardButtonStates[SDLToKB(event.key.keysym.sym)] = false;
		break;

	case SDL_MOUSEBUTTONDOWN:
		m_mouseButtonStates[SDLToMB(event.button.button)] = true;
		break;

	case SDL_MOUSEBUTTONUP:
		m_mouseButtonStates[SDLToMB(event.button.button)] = false;
		break;

	case SDL_MOUSEMOTION:
		m_mouseDeltaX = (float)event.motion.xrel;
		m_mouseDeltaY = (float)event.motion.yrel;
		break;

	case SDL_MOUSEWHEEL:
		m_mouseWheelDelta = (float)event.wheel.y;
		break;
	}
}

float InputMgr::GetState(const InputObj& inputObj) const
{
	if (inputObj.deviceType == DeviceType::Keyboard)
	{
		if (inputObj.inputType == InputType::Button)
		{
			return m_keyboardButtonStates[inputObj.inputID] ? 1.f : 0.f;
		}
	}
	else if (inputObj.deviceType == DeviceType::Mouse)
	{
		if (inputObj.inputType == InputType::Button)
		{
			return m_mouseButtonStates[inputObj.inputID] ? 1.f : 0.f;
		}
		else if (inputObj.inputType == InputType::Axis)
		{
			if (inputObj.inputID == MA_X_POS && m_mouseDeltaX > 0.f) return m_mouseDeltaX;
			if (inputObj.inputID == MA_X_NEG && m_mouseDeltaX < 0.f) return fabsf(m_mouseDeltaX);
			if (inputObj.inputID == MA_Y_POS && m_mouseDeltaY > 0.f) return m_mouseDeltaY;
			if (inputObj.inputID == MA_Y_NEG && m_mouseDeltaY < 0.f) return fabsf(m_mouseDeltaY);

			if (inputObj.inputID == MA_WHEEL_POS && m_mouseWheelDelta > 0.f) return m_mouseWheelDelta;
			if (inputObj.inputID == MA_WHEEL_NEG && m_mouseWheelDelta < 0.f) return fabsf(m_mouseWheelDelta);
		}
	}

	return 0.f;
}

float InputMgr::GetLastState(const InputObj& inputObj) const
{
	if (inputObj.deviceType == DeviceType::Keyboard)
	{
		if (inputObj.inputType == InputType::Button)
		{
			return m_lastKeyboardButtonStates[inputObj.inputID] ? 1.f : 0.f;
		}
	}
	else if (inputObj.deviceType == DeviceType::Mouse)
	{
		if (inputObj.deviceID == 0)
		{
			if (inputObj.inputType == InputType::Button)
			{
				return m_lastMouseButtonStates[inputObj.inputID] ? 1.f : 0.f;
			}
			else if (inputObj.inputType == InputType::Axis)
			{
				if (inputObj.inputID == MA_X_POS && m_mouseDeltaX > 0.f) return m_mouseDeltaX;
				if (inputObj.inputID == MA_X_NEG && m_mouseDeltaX < 0.f) return m_mouseDeltaX;
				if (inputObj.inputID == MA_Y_POS && m_mouseDeltaY > 0.f) return m_mouseDeltaY;
				if (inputObj.inputID == MA_Y_NEG && m_mouseDeltaY < 0.f) return m_mouseDeltaY;

				if (inputObj.inputID == MA_WHEEL_POS && m_lastMouseWheelDelta > 0.f) return m_lastMouseWheelDelta;
				if (inputObj.inputID == MA_WHEEL_NEG && m_lastMouseWheelDelta < 0.f) return m_lastMouseWheelDelta;
			}
		}
	}

	return 0.f;
}