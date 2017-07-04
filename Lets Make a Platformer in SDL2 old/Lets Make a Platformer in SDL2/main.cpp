/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "ScreenManager.h"

int main(int argc, char *args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	SDL_Window *window = SDL_CreateWindow("SDL Platformer Coding Made Easy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );

	bool quit = false;
	SDL_Event event;

	ScreenManager::GetInstance().Initialize(renderer);
	ScreenManager::GetInstance().LoadContent(renderer);

	SDL_Rect Fade = { 0,0,ScreenWidth, ScreenHeight };

	float FPStime = 0;
	float frameTime = 0;
	float MIN_FRAME_TIME = 3.33333f;

	FPStime = SDL_GetTicks();
	while (!quit)
	{
		frameTime = SDL_GetTicks();
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				return 0;
			}
			ScreenManager::GetInstance().UpdateEvent(event);
		}

		SDL_RenderClear(renderer);
		ScreenManager::GetInstance().Update(renderer,event);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255 * ScreenManager::GetInstance().getAlpha());
		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
		ScreenManager::GetInstance().Draw(renderer);
		SDL_RenderFillRect(renderer, &Fade);

		SDL_RenderPresent(renderer);

		if (SDL_GetTicks() - frameTime < MIN_FRAME_TIME)
		{
			SDL_Delay(MIN_FRAME_TIME - (SDL_GetTicks() - frameTime));
		}
	}

	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	TTF_Quit();
	SDL_Quit();
	IMG_Quit();
	ScreenManager::GetInstance().UnloadContent();

	return 0;
}