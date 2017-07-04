/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>

class Text
{
public:
	Text();
	~Text();

	void LoadText(std::string file, SDL_Color color, SDL_Renderer *renderer);
	void render(int x, int y,SDL_Renderer *renderer);
	void free();
	void SetAlphaMode(float alpha);
	void SetBlendMode(SDL_BlendMode blending);
	void SetTextureColorMode(int r, int g, int b);
	SDL_Texture* GetTexture();

	int getHeight();
	int getWidth();

private:

	SDL_Texture *Texture;
	int width, height;
	TTF_Font *font;
	SDL_Color color;

};