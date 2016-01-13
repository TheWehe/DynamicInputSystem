#ifndef INPUT_MGR_H
#define INPUT_MGR_H

#include "input_obj.h"
#include "keyboard_defs.h"
#include "mouse_defs.h"


class InputMgr
{
public:
	InputMgr();

	bool Init();
	void Release();

	bool OnFocusGained();
	void OnFocusLost();

	void OnPreEventLoop();
	void OnEvent(const SDL_Event& event);

	float GetState(const InputObj& inputObj) const;
	float GetLastState(const InputObj& inputObj) const;

private:
	// keyboard buttons
	bool m_keyboardButtonStates[KB_COUNT];
	bool m_lastKeyboardButtonStates[KB_COUNT];

	// mouse buttons
	bool m_mouseButtonStates[MB_COUNT];
	bool m_lastMouseButtonStates[MB_COUNT];

	// mouse position/delta
	float m_mouseDeltaX = 0.f, m_mouseDeltaY = 0.f;
	float m_lastMouseDeltaX = 0.f, m_lastMouseDeltaY = 0.f;

	// mouse wheel
	float m_mouseWheelDelta = 0.f;
	float m_lastMouseWheelDelta = 0.f;
};


#endif