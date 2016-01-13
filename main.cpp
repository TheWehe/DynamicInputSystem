#include <SDL.h>
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

#include "input_mgr.h"


int main(int argCount, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	int width = 800;
	int height = 600;

	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, &pWindow, &pRenderer);



	InputMgr input;
	input.Init();
	
	SDL_Rect thing = { 0, 0, 50, 50 };

	InputObj exitButton(DeviceType::Mouse, 0, InputType::Button, MB_LEFT);
	InputObj leftButton(DeviceType::Mouse, 0, InputType::Axis, MA_X_NEG);
	InputObj upButton(DeviceType::Mouse, 0, InputType::Axis, MA_Y_POS);
	InputObj downButton(DeviceType::Mouse, 0, InputType::Axis, MA_Y_NEG);
	InputObj rightButton(DeviceType::Mouse, 0, InputType::Axis, MA_X_POS);

	SDL_Event event;
	bool running = true;
	while (running)
	{
		// Event handling
		//
		input.OnPreEventLoop();

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;

			case SDL_WINDOWEVENT:
				switch (event.window.type)
				{
				case SDL_WINDOWEVENT_FOCUS_GAINED:
					input.OnFocusGained();
					break;

				case SDL_WINDOWEVENT_FOCUS_LOST:
					input.OnFocusLost();
					break;
				}
			}

			input.OnEvent(event);
		}

		// Update
		//
		if (input.GetState(exitButton) &&
			!input.GetLastState(exitButton))
		{
			running = false;
		}

		thing.x += (int)input.GetState(rightButton);
		thing.x -= (int)input.GetState(leftButton);
		thing.y += (int)input.GetState(upButton);
		thing.y -= (int)input.GetState(downButton);

		// Rendering
		//
		SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
		SDL_RenderClear(pRenderer);

		SDL_SetRenderDrawColor(pRenderer, 50, 100, 255, 255);
		SDL_RenderFillRect(pRenderer, &thing);

		SDL_RenderPresent(pRenderer);
	}


	input.Release();

	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();
	return 0;
}