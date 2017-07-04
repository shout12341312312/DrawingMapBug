/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include "Animation.h"

Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::LoadContent(std::string text, std::string &path, float posX, float posY, SDL_Renderer *renderer)
{
	this->preText = text;
	this->posX = posX;
	this->posY = posY;
	this->pathImage = path;

	active = false;
	alpha = 1.0f;
	textColor = { 0xff, 0xff ,0xff };
	int Size = 0;

	this->sprite.loadFromFile(path, renderer);
	this->text.LoadText(text, textColor, renderer);

	amountOfFrames = std::pair<int, int>(4, 2);
	currentFrame = std::pair<int, int>(1, 0);
}

void Animation::LoadContent(std::string text, std::vector<std::string> &path, float posX, float posY, SDL_Renderer *renderer)
{
	this->preText = text;
	this->posX = posX;
	this->posY = posY;
	this->pathImage = path.size();

	active = false;
	alpha = 1.0f;
	textColor = { 0xff, 0xff ,0xff };
	int Size = 0;

	this->sprite.loadFromFile(pathImage, renderer);
	this->text.LoadText(text, textColor, renderer);

	amountOfFrames = std::pair<int, int>(4, 2);
	currentFrame = std::pair<int, int>(1, 0);
}

void Animation::LoadContent(Texture image, float posX, float posY, SDL_Renderer *renderer)
{
	this->posX = posX;
	this->posY = posY;
	Image() = image;

	active = false;
	alpha = 1.0f;
	textColor = { 0xff, 0xff ,0xff };
	int Size = 0;

	amountOfFrames = std::pair<int, int>(4, 2);
	currentFrame = std::pair<int, int>(1, 0);
}

void Animation::UnloadContent()
{
	this->text.free();
	this->sprite.free();
	this->preText = "";
	this->posX = 0;
	this->posY = 0;
}
void Animation::Update(Animation &a)
{
}

void Animation::Draw(SDL_Renderer *renderer)
{
	if (preText != "")
	{
		text.render(posX, posY, renderer);
	}

	this->sprite.render(posX, posY, renderer);
}

void Animation::Draw(SDL_Renderer *renderer, SDL_Rect rect)
{
	this->sprite.render(posX, posY, renderer,&rect);
}

void Animation::SetTextColorMode(int r, int g, int b)
{
	SDL_SetTextureColorMod(text.GetTexture(), r, g, b);
}

bool &Animation::getActive()
{
	return active;
}

float &Animation::getAlpha()
{
	return alpha;
}

float &Animation::getScale()
{
	return scale;
}

int &Animation::getPositionX()
{
	return posX;
}

int &Animation::getPositionY()
{
	return posY;
}

Texture &Animation::Image()
{
	return sprite;
}

Text Animation::getText()
{
	return text;
}

std::pair<int, int> &Animation::CurrentFrame()
{
	return currentFrame;
}
std::pair<int, int> &Animation::AmountOfFrames()
{
	return amountOfFrames;
}

std::pair<int, int> Animation::FrameDimentions()
{
	std::pair <int, int> fd(sprite.getWidth()/amountOfFrames.first, sprite.getHeight() / amountOfFrames.second);
	return fd;
}