/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/

#pragma once
#include <SDL.h>
#include <iostream>
#include "Texture.h"
#include "Text.h"
#include <vector>

class Animation
{
public:
	Animation();
	~Animation();

	void LoadContent(std::string text, std::string &path, float posX, float posY, SDL_Renderer *renderer);
	void LoadContent(Texture image, float posX, float posY, SDL_Renderer *renderer);
	void LoadContent(std::string text, std::vector<std::string> &path, float posX, float posY, SDL_Renderer *renderer);
	void UnloadContent();
	void Update(Animation &a);
	void Draw(SDL_Renderer *renderer);
	void Draw(SDL_Renderer *renderer, SDL_Rect rect);
	void SetTextColorMode(int r, int g, int b);

	bool &getActive();

	float &getAlpha();
	float &getScale();

	int &getPositionX();
	int &getPositionY();

	Text getText();
	Texture &Image();

	std::pair<int, int> &CurrentFrame();
	std::pair<int, int> &AmountOfFrames();

	std::pair<int, int> FrameDimentions();

private:

	std::pair<int, int> currentFrame;
	std::pair<int, int> amountOfFrames;

	SDL_Rect rect;

	int posX, posY;

	float alpha;
	float scale;

	bool active;

	std::string pathImage;
	std::string preText;

	SDL_Color textColor;

	Texture sprite;
	Text text;
};


