﻿/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#pragma once
#include "GameScreen.h"
#include "Map.h"


class GameplayScreen : public GameScreen
{
public:
	GameplayScreen();
	~GameplayScreen();
	void LoadContent(SDL_Renderer *renderer);
	void UnloadContent();
	void Update(SDL_Renderer *renderer, SDL_Event &event);
	void UpdateEvent(SDL_Event &event);
	void Draw(SDL_Renderer *renderer);

private:
	Player player;
	Map map;
};

