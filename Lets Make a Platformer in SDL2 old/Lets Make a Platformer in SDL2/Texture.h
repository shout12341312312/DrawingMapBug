/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Texture
{
public:
	Texture();
	~Texture();
	bool loadFromFile(std::string path, SDL_Renderer *renderer);

	void render(int x, int y, SDL_Renderer *renderer);
	void render(int x, int y, SDL_Renderer *renderer, SDL_Rect*clip);
	void free();
	void setAlphaMode(float alpha);
	void setBlendMode(SDL_BlendMode blending);

	std::string &GetPath();

	int getHeight();
	int getWidth();

private:
	SDL_Texture *mTexture;
	std::string path;

	int mWidth, mHeight;
};

