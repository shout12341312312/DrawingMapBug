/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include "Texture.h"

Texture::Texture()
{
	mWidth = mHeight = 0;
	mTexture = NULL;
}

Texture::~Texture()
{
	free();
}

void Texture::free()
{
	SDL_DestroyTexture(mTexture);

	mWidth = mHeight = 0;
	mTexture = NULL;
}

void Texture::render(int x, int y, SDL_Renderer* renderer)
{
	SDL_Rect rect = { x,y,mWidth,mHeight };

	SDL_RenderCopy(renderer, mTexture, NULL, &rect);
}

void Texture::render(int x, int y, SDL_Renderer* renderer, SDL_Rect *clip)
{
	SDL_Rect rect = { x,y,mWidth,mHeight };

	rect.w = clip->w;
	rect.h = clip->h;

	SDL_RenderCopy(renderer, mTexture, clip, &rect);
}

bool Texture::loadFromFile(std::string path, SDL_Renderer *renderer)
{
	free();
	SDL_Texture*newTexture = NULL;

	this->path = path;
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface != 0)
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0, 0));
	}

	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

	SDL_QueryTexture(newTexture, NULL, NULL, &mWidth, &mHeight);

	SDL_FreeSurface(loadedSurface);
	
	mTexture = newTexture;
	return mTexture;
}

int Texture::getHeight()
{
	return mHeight;
}

int Texture::getWidth()
{
	return mWidth;
}

void Texture::setAlphaMode(float alpha)
{
	SDL_SetTextureAlphaMod(mTexture, alpha);
}
void Texture::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(mTexture, blending);
}

std::string &Texture::GetPath()
{
	return path;
}