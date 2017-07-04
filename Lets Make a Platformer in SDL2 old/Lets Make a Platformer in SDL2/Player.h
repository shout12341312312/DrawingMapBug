/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#pragma once

#include "SpriteSheetAnimation.h"
#include "FileManager.h"
#include "InputManager.h"
#include "Animation.h"
#include "FloatRect.h"

#include <SDL.h>
#include <iostream>


class Player
{
public:
	Player();
	~Player();

	void LoadContent(SDL_Renderer *renderer);
	void UnloadContent();
	void Draw(SDL_Renderer *renderer);
	void Update(SDL_Renderer *renderer, InputManager input);

	FloatRect *rect, *prevRect;
	float posX, posY, prevPosX,prevPosY;
private:

	std::vector<std::vector<std::string>> attributes;
	std::vector<std::vector<std::string>> contents;

	enum Direction
	{
		Right,
		Left
	};

	FileManager file;
	Texture image;
	Direction direction;
	Animation pAnim;
	SpriteSheetAnimation ssAnim;

	float moveSpeed;
};

