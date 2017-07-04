/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include "Player.h"

Player::Player()
{
	posX = 0;
	posY = 0;
}

Player::~Player()
{
}

void Player::LoadContent(SDL_Renderer *renderer)
{
	file.LoadContent("Files/config/Player.cfg", attributes, contents);
	for (int i = 0; i < attributes.size(); i++)
	{
		for (int j = 0; j < attributes[i].size(); j++)
		{
			std::string att = attributes[i][j];
			std::string con = contents[i][j];

			if (att == "Image")
			{
				pAnim.LoadContent("", con, 0, 0, renderer);
			}
		}
	}
	moveSpeed = 0.5f;
	direction = Direction::Right;

	rect = new FloatRect(posX, posY, 41, 60);
	prevRect = new FloatRect(posX, posY, 41, 60);
}
void Player::UnloadContent()
{
	attributes.clear();
	contents.clear();
	pAnim.UnloadContent();
	ssAnim.UnloadContent();
}
void Player::Draw(SDL_Renderer *renderer)
{
	ssAnim.Draw(pAnim, renderer);
}
void Player::Update(SDL_Renderer *renderer, InputManager input)
{
	prevPosX = posX;
	prevPosY = posY;

	pAnim.getActive() = true;
	if (input.KeyDown(SDLK_LEFT))
	{
		direction = Direction::Left;
		posX -= moveSpeed;
	}
	else if (input.KeyDown(SDLK_RIGHT))
	{
		direction = Direction::Right;
		posX += moveSpeed;
	}
	else if (input.KeyDown(SDLK_UP))
	{
		posY -= moveSpeed;
	}

	else if (input.KeyDown(SDLK_DOWN))
	{
		posY += moveSpeed;
	}
	else
	{
		pAnim.getActive() = false;
	}

	pAnim.CurrentFrame().second = direction;
	pAnim.getPositionX() = posX;
	pAnim.getPositionY() = posY;
	ssAnim.Update(pAnim);

	delete rect;
	delete prevRect;

	rect = new FloatRect(posX, posY, 41, 60);
	prevRect = new FloatRect(prevPosX, prevPosY, 41, 60);
}