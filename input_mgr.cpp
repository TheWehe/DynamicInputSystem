#include "input_mgr.h"

#include "util.h"



InputMgr::InputMgr()
{
	FOREACH_I_IN_RANGE(0, KB_COUNT)
	{
		m_keyboardButtonStates[i] = false;
		m_lastKeyboardButtonStates[i] = false;
	}

	FOREACH_I_IN_RANGE(0, MB_COUNT)
	{
		m_mouseButtonStates[i] = false;
		m_lastMouseButtonStates[i] = false;
	}
}

void InputMgr::Init()
{
	const auto gamepadCount = SDL_NumJoysticks();
	FOREACH_I_IN_RANGE(0, gamepadCount)
	{
		InitGamepad(i);
	}
}

void InputMgr::Release()
{
	FOREACH_IT_IN_LIST(m_gamepads)
	{
		SDL_JoystickClose(it->pHandle);
	}
}

void InputMgr::OnPreEventLoop()
{
	FOREACH_I_IN_RANGE(0, KB_COUNT)
	{
		m_lastKeyboardButtonStates[i] = m_keyboardButtonStates[i];
	}

	FOREACH_I_IN_RANGE(0, MB_COUNT)
	{
		m_lastMouseButtonStates[i] = m_mouseButtonStates[i];
	}

	m_lastMouseDeltaX = m_mouseDeltaX;
	m_mouseDeltaX = 0;
	m_lastMouseDeltaY = m_mouseDeltaY;
	m_mouseDeltaY = 0;

	m_lastMouseWheelDelta = m_mouseWheelDelta;
	m_mouseWheelDelta = 0;

	FOREACH_IT_IN_LIST(m_gamepads)
	{
		FOREACH_I_IN_RANGE(0, it->buttonStates.size())
		{
			it->lastButtonStates[i] = it->buttonStates[i];
		}

		FOREACH_I_IN_RANGE(0, it->axisStates.size())
		{
			it->lastAxisStates[i] = it->axisStates[i];
		}

		FOREACH_I_IN_RANGE(0, it->dPadStates.size())
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
		if (event.wheel.y > 0.f) m_mouseWheelDelta = 1.f;
		else if (event.wheel.y < 0.f) m_mouseWheelDelta = 1.f;
		else m_mouseWheelDelta = 0.f;
		break;

	case SDL_JOYBUTTONDOWN:
	{
		FOREACH_IT_IN_LIST(m_gamepads)
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
		FOREACH_IT_IN_LIST(m_gamepads)
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
		FOREACH_IT_IN_LIST(m_gamepads)
		{
			if (SDL_JoystickFromInstanceID(event.jhat.which) == it->pHandle)
			{
				auto state = (float)event.jaxis.value;
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
		FOREACH_IT_IN_LIST(m_gamepads)
		{
			if (SDL_JoystickFromInstanceID(event.jhat.which) == it->pHandle)
			{
				TranslateSDLDPadStateToArray(event.jhat.value, &it->dPadStates[event.jhat.hat]);
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
		FOREACH_IT_IN_LIST(m_gamepads)
		{
			if (SDL_JoystickFromInstanceID(event.jhat.which) == it->pHandle)
			{
				SDL_JoystickClose(it->pHandle);
				m_gamepads.erase(it);
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
			return m_keyboardButtonStates[inputObj.inputID] ? 1.f : 0.f;
		}
	}
	else if (inputObj.deviceType == DeviceType::Mouse)
	{
		if (inputObj.inputType == InputType::Button)
		{
			if (inputObj.inputID < MB_COUNT)
			{
				return m_mouseButtonStates[inputObj.inputID] ? 1.f : 0.f;
			}
		}
		else if (inputObj.inputType == InputType::Axis)
		{
			if (inputObj.inputID == MA_X &&
				inputObj.direction == Direction::Positive &&
				m_mouseDeltaX > 0.f) return m_mouseDeltaX;
			else if (inputObj.inputID == MA_X &&
				inputObj.direction == Direction::Negative &&
				m_mouseDeltaX < 0.f) return fabsf(m_mouseDeltaX);
			else if (inputObj.inputID == MA_Y &&
				inputObj.direction == Direction::Positive &&
				m_mouseDeltaY > 0.f) return m_mouseDeltaY;
			else if (inputObj.inputID == MA_Y &&
				inputObj.direction == Direction::Negative &&
				m_mouseDeltaY < 0.f) return fabsf(m_mouseDeltaY);
			else if (inputObj.inputID == MA_WHEEL &&
				inputObj.direction == Direction::Positive &&
				m_mouseWheelDelta > 0.f) return m_mouseWheelDelta;
			else if (inputObj.inputID == MA_WHEEL &&
				inputObj.direction == Direction::Negative &&
				m_mouseWheelDelta < 0.f) return fabsf(m_mouseWheelDelta);
		}
	}
	else if (inputObj.deviceType == DeviceType::Gamepad)
	{
		if (inputObj.deviceID < m_gamepads.size())
		{
			auto it = m_gamepads.begin();
			for (; it != m_gamepads.end(); it++)
			{
				if (SDL_JoystickInstanceID(it->pHandle) == inputObj.deviceID) break;
			}

			if (it != m_gamepads.end())
			{
				if (inputObj.inputType == InputType::Button)
				{
					if (inputObj.inputID >= it->buttonStates.size() &&
						inputObj.inputID < it->buttonStates.size() + it->dPadStates.size() * 4)
					{
						auto pov = inputObj.inputID - it->buttonStates.size();
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
						auto state = it->axisStates[inputObj.inputID];

						if (inputObj.direction == Direction::Positive &&
							state > 0.f) return state;
						else if (inputObj.direction == Direction::Negative &&
							state < 0.f) return fabsf(state);
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
			return m_lastKeyboardButtonStates[inputObj.inputID] ? 1.f : 0.f;
		}
	}
	else if (inputObj.deviceType == DeviceType::Mouse)
	{
		if (inputObj.inputType == InputType::Button)
		{
			if (inputObj.inputID < MB_COUNT)
			{
				return m_lastMouseButtonStates[inputObj.inputID] ? 1.f : 0.f;
			}
		}
		else if (inputObj.inputType == InputType::Axis)
		{
			if (inputObj.inputID == MA_X &&
				inputObj.direction == Direction::Positive &&
				m_lastMouseDeltaX > 0.f) return m_lastMouseDeltaX;
			else if (inputObj.inputID == MA_X &&
				inputObj.direction == Direction::Negative &&
				m_lastMouseDeltaX < 0.f) return fabsf(m_lastMouseDeltaX);
			else if (inputObj.inputID == MA_Y &&
				inputObj.direction == Direction::Positive &&
				m_lastMouseDeltaY > 0.f) return m_lastMouseDeltaY;
			else if (inputObj.inputID == MA_Y &&
				inputObj.direction == Direction::Negative &&
				m_lastMouseDeltaY < 0.f) return fabsf(m_lastMouseDeltaY);
			else if (inputObj.inputID == MA_WHEEL &&
				inputObj.direction == Direction::Positive &&
				m_lastMouseWheelDelta > 0.f) return m_lastMouseWheelDelta;
			else if (inputObj.inputID == MA_WHEEL &&
				inputObj.direction == Direction::Negative &&
				m_lastMouseWheelDelta < 0.f) return fabsf(m_lastMouseWheelDelta);
		}
	}
	else if (inputObj.deviceType == DeviceType::Gamepad)
	{
		if (inputObj.deviceID < m_gamepads.size())
		{
			auto it = m_gamepads.begin();
			for (; it != m_gamepads.end(); it++)
			{
				if (SDL_JoystickInstanceID(it->pHandle) == inputObj.deviceID) break;
			}

			if (it != m_gamepads.end())
			{
				if (inputObj.inputType == InputType::Button)
				{
					if (inputObj.inputID >= it->lastButtonStates.size() &&
						inputObj.inputID < it->lastButtonStates.size() + it->lastDPadStates.size() * 4)
					{
						auto pov = inputObj.inputID - it->lastButtonStates.size();
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
						auto state = it->lastAxisStates[inputObj.inputID];

						if (inputObj.direction == Direction::Positive &&
							state > 0.f) return state;
						else if (inputObj.direction == Direction::Negative &&
							state < 0.f) return fabsf(state);
					}
				}
			}
		}
	}

	return 0.f;
}

bool InputMgr::InitGamepad(uint32_t gamepad)
{
	GamepadData gamepadData;
	gamepadData.pHandle = SDL_JoystickOpen(gamepad);

	if (gamepadData.pHandle)
	{
		const auto buttonCount = SDL_JoystickNumButtons(gamepadData.pHandle);
		FOREACH_I_IN_RANGE(0, buttonCount)
		{
			gamepadData.buttonStates.push_back(false);
			gamepadData.lastButtonStates.push_back(false);
		}
		gamepadData.buttonStates.shrink_to_fit();
		gamepadData.lastButtonStates.shrink_to_fit();

		const auto axisCount = SDL_JoystickNumAxes(gamepadData.pHandle);
		FOREACH_I_IN_RANGE(0, axisCount)
		{
			gamepadData.axisStates.push_back(0.f);
			gamepadData.lastAxisStates.push_back(0.f);
		}
		gamepadData.axisStates.shrink_to_fit();
		gamepadData.lastAxisStates.shrink_to_fit();

		const auto dPadCount = SDL_JoystickNumHats(gamepadData.pHandle);
		FOREACH_I_IN_RANGE(0, dPadCount)
		{
			gamepadData.dPadStates.push_back({ false, false, false, false });
			gamepadData.lastDPadStates.push_back({ false, false, false, false });
		}
		gamepadData.dPadStates.shrink_to_fit();
		gamepadData.lastDPadStates.shrink_to_fit();

		m_gamepads.push_back(gamepadData);

		return true;
	}
	else
	{
		return false;
	}
}