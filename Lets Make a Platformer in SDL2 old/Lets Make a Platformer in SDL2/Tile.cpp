/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include "Tile.h"

Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::SetContent(std::string image, State state, float posX, float posY, SDL_Renderer *renderer, SDL_Rect rect)
{
	this->rect = rect;
	this->posX = posX;
	this->posY = posY;
	this->anim.LoadContent("", image, posX, posY, renderer);
}
void Tile::UnloadContent()
{
	anim.UnloadContent();
	State::Passive;
}
void Tile::Update(Player &e)
{
	FloatRect tileRect(posX, posY, 32, 32);

	if (e.rect->Collision(tileRect) && state == State::Solid)
	{
		if (e.rect->Right >= tileRect.Left && e.prevRect->Right <= tileRect.Left)
		{
			e.posX = tileRect.Left - 32;
		}
		else if (e.rect->Left <= tileRect.Right && e.prevRect->Left >= tileRect.Right)
		{
			e.posX = tileRect.Right;
		}
		else if (e.rect->Bottom >= tileRect.Top && e.prevRect->Bottom <= tileRect.Top)
		{
			e.posY = tileRect.Top - 32;
		}
		else if (e.rect->Top <= tileRect.Bottom && e.prevRect->Top >= tileRect.Bottom)
		{
			e.posY = tileRect.Bottom;
		}
	}
}
void Tile::Draw(SDL_Renderer *renderer)
{
	anim.Draw(renderer, rect);
}