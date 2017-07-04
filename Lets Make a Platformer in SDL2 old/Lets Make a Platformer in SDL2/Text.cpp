/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include"Text.h"

Text::Text()
{
}

Text::~Text()
{
	free();
}

void Text::LoadText(std::string file, SDL_Color color,SDL_Renderer *renderer)
{
	font = TTF_OpenFont("Files/Fonts/arial.ttf", 50);
	SDL_Surface *loadedSurface = TTF_RenderText_Blended(font, file.c_str(), color);

	Texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

	SDL_QueryTexture(Texture, NULL, NULL, &width, &height);

	SDL_FreeSurface(loadedSurface);
}

void Text::render(int x, int y,SDL_Renderer *renderer)
{
	SDL_Rect rect = { x,y,width,height };
	SDL_RenderCopy(renderer, Texture, NULL, &rect);
}

void Text::free()
{
	width = height = 0;
	Texture = NULL;
}

void Text::SetAlphaMode(float alpha)
{
	SDL_SetTextureAlphaMod(Texture,alpha);
}
void Text::SetBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(Texture,blending);
}

void Text::SetTextureColorMode(int r, int g, int b)
{
	SDL_SetTextureColorMod(Texture, r, g, b);
}

int Text::getHeight()
{
	return height;
}

int Text::getWidth()
{
	return width;
}
SDL_Texture* Text::GetTexture()
{
	return Texture;
}