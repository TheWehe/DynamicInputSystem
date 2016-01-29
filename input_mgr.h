#ifndef INPUT_MGR_H
#define INPUT_MGR_H

#include <list>
#include <vector>
#include <array>
#include "input_obj.h"
#include "device_defs.h"
#include "util.h"



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
	bool InitGamepad(unsigned gamepad);

	bool m_KeyboardButtonStates[KB_COUNT];
	bool m_LastKeyboardButtonStates[KB_COUNT];
	bool m_MouseButtonStates[MB_COUNT];
	bool m_LastMouseButtonStates[MB_COUNT];
	float m_MouseDeltaX = 0.f, m_MouseDeltaY = 0.f;
	float m_LastMouseDeltaX = 0.f, m_LastMouseDeltaY = 0.f;
	float m_MouseWheelDelta = 0.f,  m_LastMouseWheelDelta = 0.f;
	std::list<GamepadData> m_Gamepads;
};



#endif