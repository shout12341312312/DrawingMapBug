/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#pragma once

#include <SDL.h>
#include <iostream>
#include "Texture.h"
#include "Animation.h"
#include "Player.h"

class Tile
{
public:
	Tile();
	~Tile();

	static enum State { Solid, Passive };

	void SetContent(std::string image, State state, float posX, float posY, SDL_Renderer *renderer, SDL_Rect rect);
	void UnloadContent();
	void Update(Player &e);
	void Draw(SDL_Renderer *renderer);

private:
	Animation anim;
	State state;
	SDL_Rect rect;

	float posX, posY;
};

