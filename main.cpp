#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

#include <iostream>
#include <cmath>
#include <SDL.h>
#include "input_mgr.h"



int main(int argCount, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &pWindow, &pRenderer);

	InputMgr input;
	input.Init();

	InputObj exitButton(DeviceType::Keyboard, 0, InputType::Button, KB_ESCAPE, Direction::None);
	InputObj left1(DeviceType::Gamepad, 0, InputType::Axis, 0, Direction::Negative);
	InputObj right1(DeviceType::Gamepad, 0, InputType::Axis, 0, Direction::Positive);
	InputObj up1(DeviceType::Gamepad, 0, InputType::Axis, 1, Direction::Negative);
	InputObj down1(DeviceType::Gamepad, 0, InputType::Axis, 1, Direction::Positive);
	InputObj left2(DeviceType::Gamepad, 1, InputType::Axis, 0, Direction::Negative);
	InputObj right2(DeviceType::Gamepad, 1, InputType::Axis, 0, Direction::Positive);
	InputObj up2(DeviceType::Gamepad, 1, InputType::Axis, 1, Direction::Negative);
	InputObj down2(DeviceType::Gamepad, 1, InputType::Axis, 1, Direction::Positive);

	SDL_Rect player = { 0, 0, 50, 50 };
	auto player1X = 0.f, player1Y = 0.f;
	auto player2X = 750.f, player2Y = 550.f;
	const auto speed = 500.f;

	auto lastTime = SDL_GetTicks();
	SDL_Event event;
	bool running = true;
	while (running)
	{
		auto cur = SDL_GetTicks();
		auto delta = (float)(cur - lastTime) / 1000.f;
		lastTime = cur;



		input.OnPreEventLoop();

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			}

			input.OnEvent(event);
		}



		if (!input.GetState(exitButton) && input.GetLastState(exitButton))
		{
			running = false;
		}



		auto x = input.GetState(right1) - input.GetState(left1);
		auto y = input.GetState(down1) - input.GetState(up1);
		
		auto len = sqrtf(x * x + y * y);
		if (len > 0.1f)
		{
			if (len > 1.f)
			{
				x /= len;
				y /= len;
			}

			player1X += x * speed * delta;
			player1Y += y * speed * delta;
		}



		x = input.GetState(right2) - input.GetState(left2);
		y = input.GetState(down2) - input.GetState(up2);

		len = sqrtf(x * x + y * y);
		if (len > 0.1f)
		{
			if (len > 1.f)
			{
				x /= len;
				y /= len;
			}

			player2X += x * speed * delta;
			player2Y += y * speed * delta;
		}



		SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
		SDL_RenderClear(pRenderer);

		SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255);
		player.x = static_cast<int>(player1X);
		player.y = static_cast<int>(player1Y);
		SDL_RenderFillRect(pRenderer, &player);

		SDL_SetRenderDrawColor(pRenderer, 0, 0, 255, 255);
		player.x = static_cast<int>(player2X);
		player.y = static_cast<int>(player2Y);
		SDL_RenderFillRect(pRenderer, &player);

		SDL_RenderPresent(pRenderer);
	}

	input.Release();

	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();
	return 0;
}