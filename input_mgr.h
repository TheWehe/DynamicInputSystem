#ifndef INPUT_MGR_H
#define INPUT_MGR_H

#include <list>
#include <vector>
#include <array>
#include "input_obj.h"
#include "device_defs.h"



class InputMgr
{
private:
	struct GamepadData
	{
		SDL_Joystick* pHandle;
		std::vector<float> axisStates;
		std::vector<float> lastAxisStates;
		std::vector<bool> buttonStates;
		std::vector<bool> lastButtonStates;
		std::vector<std::array<bool, 4>> dPadStates;
		std::vector<std::array<bool, 4>> lastDPadStates;
	};

public:
	InputMgr();

	void Init();
	void Release();

	void OnPreEventLoop();
	void OnEvent(const SDL_Event& event);
	float GetState(const InputObj& inputObj) const;
	float GetLastState(const InputObj& inputObj) const;

private:
	bool InitGamepad(uint32_t gamepad);

	bool m_keyboardButtonStates[KB_COUNT];
	bool m_lastKeyboardButtonStates[KB_COUNT];
	bool m_mouseButtonStates[MB_COUNT];
	bool m_lastMouseButtonStates[MB_COUNT];
	float m_mouseDeltaX = 0.f, m_mouseDeltaY = 0.f;
	float m_lastMouseDeltaX = 0.f, m_lastMouseDeltaY = 0.f;
	float m_mouseWheelDelta = 0.f,  m_lastMouseWheelDelta = 0.f;
	std::list<GamepadData> m_gamepads;
};

#endif