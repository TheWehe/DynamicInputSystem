#include "input_mgr.h"

#include <cmath>
#include "util.h"



InputMgr::InputMgr()
{
	for (int i = 0; i < KB_COUNT; i++)
	{
		m_KeyboardButtonStates[i] = false;
		m_LastKeyboardButtonStates[i] = false;
	}

	for (int i = 0; i < MB_COUNT; i++)
	{
		m_MouseButtonStates[i] = false;
		m_LastMouseButtonStates[i] = false;
	}
}

void InputMgr::Init()
{
	const unsigned gamepadCount = SDL_NumJoysticks();
	for (unsigned i = 0; i < gamepadCount; i++)
	{
		InitGamepad(i);
	}
}

void InputMgr::Release()
{
	FOREACH_IT_IN_LIST(m_Gamepads)
	{
		SDL_JoystickClose(it->pHandle);
	}
}

void InputMgr::OnPreEventLoop()
{
	for (int i = 0; i < KB_COUNT; i++)
	{
		m_LastKeyboardButtonStates[i] = m_KeyboardButtonStates[i];
	}

	for (int i = 0; i < MB_COUNT; i++)
	{
		m_LastMouseButtonStates[i] = m_MouseButtonStates[i];
	}

	m_LastMouseDeltaX = m_MouseDeltaX;
	m_MouseDeltaX = 0;
	m_LastMouseDeltaY = m_MouseDeltaY;
	m_MouseDeltaY = 0;

	m_LastMouseWheelDelta = m_MouseWheelDelta;
	m_MouseWheelDelta = 0;

	FOREACH_IT_IN_LIST(m_Gamepads)
	{
		for (unsigned i = 0; it->buttonStates.size(); i++)
		{
			it->lastButtonStates[i] = it->buttonStates[i];
		}

		for (unsigned i = 0; it->axisStates.size(); i++)
		{
			it->lastAxisStates[i] = it->axisStates[i];
		}

		for (unsigned i = 0; it->dPadStates.size(); i++)
		{
			it->lastDPadStates[i] = it->dPadStates[i];
		}
	}
}

void InputMgr::OnEvent(const SDL_Event& event)
{
	switch (event.type)
	{
	case SDL_KEYDOWN:
		m_KeyboardButtonStates[SDLToKB(event.key.keysym.sym)] = true;
		break;

	case SDL_KEYUP:
		m_KeyboardButtonStates[SDLToKB(event.key.keysym.sym)] = false;
		break;

	case SDL_MOUSEBUTTONDOWN:
		m_MouseButtonStates[SDLToMB(event.button.button)] = true;
		break;

	case SDL_MOUSEBUTTONUP:
		m_MouseButtonStates[SDLToMB(event.button.button)] = false;
		break;

	case SDL_MOUSEMOTION:
		m_MouseDeltaX = static_cast<float>(event.motion.xrel);
		m_MouseDeltaY = static_cast<float>(event.motion.yrel);
		break;

	case SDL_MOUSEWHEEL:
		if (event.wheel.y > 0.f) m_MouseWheelDelta = 1.f;
		else if (event.wheel.y < 0.f) m_MouseWheelDelta = 1.f;
		else m_MouseWheelDelta = 0.f;
		break;

	case SDL_JOYBUTTONDOWN:
	{
		FOREACH_IT_IN_LIST(m_Gamepads)
		{
			if (SDL_JoystickFromInstanceID(event.jhat.which) == it->pHandle)
			{
				it->buttonStates[event.jbutton.button] = true;
				break;
			}
		}
		break;
	}

	case SDL_JOYBUTTONUP:
	{
		FOREACH_IT_IN_LIST(m_Gamepads)
		{
			if (SDL_JoystickFromInstanceID(event.jhat.which) == it->pHandle)
			{
				it->buttonStates[event.jbutton.button] = false;
				break;
			}
		}
		break;
	}

	case SDL_JOYAXISMOTION:
	{
		FOREACH_IT_IN_LIST(m_Gamepads)
		{
			if (SDL_JoystickFromInstanceID(event.jhat.which) == it->pHandle)
			{
				float state = static_cast<float>(event.jaxis.value);
				if (state > 0) state /= GAMEPAD_AXIS_MAX_ABS;
				if (state < 0) state /= GAMEPAD_AXIS_MIN_ABS;
				if (event.jaxis.axis < it->axisStates.size()) it->axisStates[event.jaxis.axis] = state;
				break;
			}
		}
		break;
	}

	case SDL_JOYHATMOTION:
	{
		FOREACH_IT_IN_LIST(m_Gamepads)
		{
			if (SDL_JoystickFromInstanceID(event.jhat.which) == it->pHandle)
			{
				TranslateSDLDPadStateToArray(event.jhat.value, it->dPadStates[event.jhat.hat]);
				break;
			}
		}
		break;
	}

	case SDL_JOYDEVICEADDED:
	{
		InitGamepad(event.jdevice.which);
		break;
	}

	case SDL_JOYDEVICEREMOVED:
	{
		FOREACH_IT_IN_LIST(m_Gamepads)
		{
			if (SDL_JoystickFromInstanceID(event.jhat.which) == it->pHandle)
			{
				SDL_JoystickClose(it->pHandle);
				m_Gamepads.erase(it);
				break;
			}
		}
		break;
	}

	}
}

float InputMgr::GetState(const InputObj& inputObj) const
{
	if (inputObj.deviceType == DeviceType::Keyboard)
	{
		if (inputObj.inputID < KB_COUNT)
		{
			return m_KeyboardButtonStates[inputObj.inputID] ? 1.f : 0.f;
		}
	}
	else if (inputObj.deviceType == DeviceType::Mouse)
	{
		if (inputObj.inputType == InputType::Button)
		{
			if (inputObj.inputID < MB_COUNT)
			{
				return m_MouseButtonStates[inputObj.inputID] ? 1.f : 0.f;
			}
		}
		else if (inputObj.inputType == InputType::Axis)
		{
			if (inputObj.inputID == MA_X && inputObj.axisDir == AxisDir::Positive &&
				m_MouseDeltaX > 0.f) return m_MouseDeltaX;
			else if (inputObj.inputID == MA_X && inputObj.axisDir == AxisDir::Negative &&
				m_MouseDeltaX < 0.f) return abs(m_MouseDeltaX);
			else if (inputObj.inputID == MA_Y && inputObj.axisDir == AxisDir::Positive &&
				m_MouseDeltaY > 0.f) return m_MouseDeltaY;
			else if (inputObj.inputID == MA_Y && inputObj.axisDir == AxisDir::Negative &&
				m_MouseDeltaY < 0.f) return abs(m_MouseDeltaY);
			else if (inputObj.inputID == MA_WHEEL && inputObj.axisDir == AxisDir::Positive &&
				m_MouseWheelDelta > 0.f) return m_MouseWheelDelta;
			else if (inputObj.inputID == MA_WHEEL && inputObj.axisDir == AxisDir::Negative &&
				m_MouseWheelDelta < 0.f) return abs(m_MouseWheelDelta);
		}
	}
	else if (inputObj.deviceType == DeviceType::Gamepad)
	{
		if (inputObj.deviceID < m_Gamepads.size())
		{
			auto it = m_Gamepads.begin();
			for (; it != m_Gamepads.end(); it++)
			{
				if (SDL_JoystickInstanceID(it->pHandle) == inputObj.deviceID) break;
			}

			if (it != m_Gamepads.end())
			{
				if (inputObj.inputType == InputType::Button)
				{
					if (inputObj.inputID >= it->buttonStates.size() &&
						inputObj.inputID < it->buttonStates.size() + it->dPadStates.size() * 4)
					{
						unsigned pov = inputObj.inputID - it->buttonStates.size();
						return it->dPadStates[pov / 4][pov % 4] ? 1.f : 0.f;
					}
					else if(inputObj.inputID < it->buttonStates.size())
					{
						return it->buttonStates[inputObj.inputID] ? 1.f : 0.f;
					}
				}
				else if (inputObj.inputType == InputType::Axis)
				{
					if (inputObj.inputID < it->axisStates.size())
					{
						float state = it->axisStates[inputObj.inputID];

						if (inputObj.axisDir == AxisDir::Positive && state > 0.f) return state;
						else if (inputObj.axisDir == AxisDir::Negative && state < 0.f) return abs(state);
					}
				}
			}
		}
	}

	return 0.f;
}

float InputMgr::GetLastState(const InputObj& inputObj) const
{
	if (inputObj.deviceType == DeviceType::Keyboard)
	{
		if (inputObj.inputID < KB_COUNT)
		{
			return m_LastKeyboardButtonStates[inputObj.inputID] ? 1.f : 0.f;
		}
	}
	else if (inputObj.deviceType == DeviceType::Mouse)
	{
		if (inputObj.inputType == InputType::Button)
		{
			if (inputObj.inputID < MB_COUNT)
			{
				return m_LastMouseButtonStates[inputObj.inputID] ? 1.f : 0.f;
			}
		}
		else if (inputObj.inputType == InputType::Axis)
		{
			if (inputObj.inputID == MA_X && inputObj.axisDir == AxisDir::Positive &&
				m_LastMouseDeltaX > 0.f) return m_LastMouseDeltaX;
			else if (inputObj.inputID == MA_X && inputObj.axisDir == AxisDir::Negative &&
				m_LastMouseDeltaX < 0.f) return abs(m_LastMouseDeltaX);
			else if (inputObj.inputID == MA_Y && inputObj.axisDir == AxisDir::Positive &&
				m_LastMouseDeltaY > 0.f) return m_LastMouseDeltaY;
			else if (inputObj.inputID == MA_Y && inputObj.axisDir == AxisDir::Negative &&
				m_LastMouseDeltaY < 0.f) return abs(m_LastMouseDeltaY);
			else if (inputObj.inputID == MA_WHEEL && inputObj.axisDir == AxisDir::Positive &&
				m_LastMouseWheelDelta > 0.f) return m_LastMouseWheelDelta;
			else if (inputObj.inputID == MA_WHEEL && inputObj.axisDir == AxisDir::Negative &&
				m_LastMouseWheelDelta < 0.f) return abs(m_LastMouseWheelDelta);
		}
	}
	else if (inputObj.deviceType == DeviceType::Gamepad)
	{
		if (inputObj.deviceID < m_Gamepads.size())
		{
			auto it = m_Gamepads.begin();
			for (; it != m_Gamepads.end(); it++)
			{
				if (SDL_JoystickInstanceID(it->pHandle) == inputObj.deviceID) break;
			}

			if (it != m_Gamepads.end())
			{
				if (inputObj.inputType == InputType::Button)
				{
					if (inputObj.inputID >= it->lastButtonStates.size() &&
						inputObj.inputID < it->lastButtonStates.size() + it->lastDPadStates.size() * 4)
					{
						unsigned pov = inputObj.inputID - it->lastButtonStates.size();
						return it->lastDPadStates[pov / 4][pov % 4] ? 1.f : 0.f;
					}
					else if (inputObj.inputID < it->lastButtonStates.size())
					{
						return it->lastButtonStates[inputObj.inputID] ? 1.f : 0.f;
					}
				}
				else if (inputObj.inputType == InputType::Axis)
				{
					if (inputObj.inputID < it->lastAxisStates.size())
					{
						float state = it->lastAxisStates[inputObj.inputID];

						if (inputObj.axisDir == AxisDir::Positive && state > 0.f) return state;
						else if (inputObj.axisDir == AxisDir::Negative && state < 0.f) return abs(state);
					}
				}
			}
		}
	}

	return 0.f;
}

bool InputMgr::InitGamepad(unsigned gamepad)
{
	GamepadData gamepadData;
	gamepadData.pHandle = SDL_JoystickOpen(gamepad);

	if (gamepadData.pHandle)
	{
		const unsigned buttonCount = SDL_JoystickNumButtons(gamepadData.pHandle);
		for (unsigned i = 0; i < buttonCount; i++)
		{
			gamepadData.buttonStates.push_back(false);
			gamepadData.lastButtonStates.push_back(false);
		}
		gamepadData.buttonStates.shrink_to_fit();
		gamepadData.lastButtonStates.shrink_to_fit();

		const unsigned axisCount = SDL_JoystickNumAxes(gamepadData.pHandle);
		for (unsigned i = 0; i < axisCount; i++)
		{
			gamepadData.axisStates.push_back(0.f);
			gamepadData.lastAxisStates.push_back(0.f);
		}
		gamepadData.axisStates.shrink_to_fit();
		gamepadData.lastAxisStates.shrink_to_fit();

		const unsigned dPadCount = SDL_JoystickNumHats(gamepadData.pHandle);
		for (unsigned i = 0; i < dPadCount; i++)
		{
			gamepadData.dPadStates.push_back({ false, false, false, false });
			gamepadData.lastDPadStates.push_back({ false, false, false, false });
		}
		gamepadData.dPadStates.shrink_to_fit();
		gamepadData.lastDPadStates.shrink_to_fit();

		m_Gamepads.push_back(gamepadData);
		return true;
	}
	else
	{
		return false;
	}
}