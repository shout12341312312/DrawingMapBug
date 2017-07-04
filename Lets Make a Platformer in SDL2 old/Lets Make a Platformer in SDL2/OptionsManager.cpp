/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include "OptionsManager.h"
#include "ScreenManager.h"

OptionsManager::OptionsManager()
{
}
OptionsManager::~OptionsManager()
{
}
void OptionsManager::EqualizeMenuItems()
{
	for (int i = 0; i < optionsItems.size(); i++)
	{
		if (imageTexture.size() == i)
		{
			imageTexture.push_back(null);
		}
	}

	for (int i = 0; i < imageTexture.size(); i++)
	{
		if (optionsItems.size() == i)
		{
			optionsItems.push_back("");
		}
	}
}
void OptionsManager::SetAnimation(SDL_Renderer *renderer)
{
	for (int i = 0; i < optionsItems.size(); i++)
	{
		animation.push_back(new Animation);
		animation[animation.size() - 1]->LoadContent(optionsItems[i],contents[i],posX,posY,renderer);
	}
}
void OptionsManager::SetPosition()
{
	int posx = posX;
	int posy = posY;

	for (int i = 0; i < animation.size(); i++)
	{
		animation[i]->getPositionX() = posx;
		animation[i]->getPositionY() = posy;

		float width = imageTexture[i].getWidth() + animation[i]->getText().getWidth();
		float height = imageTexture[i].getHeight() + animation[i]->getText().getHeight();;

		if (axis == 1)
		{
			posx += 10 + width;
		}
		else
		{
			posy += 10 + height;
		}
	}

	poSX = posX;
	poSY = posY;
}

void OptionsManager::LoadContent(std::string id, SDL_Renderer *renderer)
{
	itemNumber = 0;
	null.loadFromFile("Files/Images/no.png",renderer);
	system("cls");

	file.LoadContent("Files/config/Options.cfg", attributes, contents, id);

	for (int i = 0; i < attributes.size(); i++)
	{
		for (int j = 0; j < attributes[i].size(); j++)
		{
			std::string att = attributes[i][j];
			std::string con = contents[i][j];

			if (att == "Text")
			{
				optionsItems.push_back(con);
			}
			else if (att == "Image")
			{
				image.loadFromFile(con, renderer);
				imageTexture.push_back(image);
			}
			else if (att == "Axis")
			{
				axis = atoi(con.c_str());
			}
			else if (att == "Align")
			{
				align = con;
			}
			else if (att == "Position")
			{
				std::string pos[2];

				pos[0] = con.substr(0, con.find(','));
				pos[1] = con.substr(con.find(',') + 1);

				posX = atof(pos[0].c_str());
				posY = atof(pos[1].c_str());
			}
			else if (att == "Animation")
			{
				animationTypes.push_back(con);
			}
			else if (att == "Value")
			{
				optionsLinks.push_back(con);
			}
		}
	}

	EqualizeMenuItems();
	SetAnimation(renderer);
	SetPosition();
}

void OptionsManager::Update(SDL_Renderer *renderer, InputManager input)
{	
	if (input.KeyPressed(SDLK_RETURN))
	{
		ScreenManager::GetInstance().AddScreen(optionsLinks[itemNumber], renderer);

		if (itemNumber == 2)
		{
			SDL_Quit();
		}
	}

	if (itemNumber < 0)
	{
		itemNumber = 0;
	}
	else if (itemNumber > optionsItems.size() - 1)
	{
		itemNumber = optionsItems.size() - 1;
	}

	for (int i = 0; i < animation.size(); i++)
	{
		for (int j = 0; j < animationTypes.size(); j++)
		{
			animation[i]->getActive() = true;;
			animation[i]->SetTextColorMode(128, 128, 128);

			if (i == itemNumber)
			{
				animation[i]->SetTextColorMode(255,255,255);
				animation[i]->getActive() = false;
			}

			if (animationTypes[j] == "Fade")
			{
				fade.Update(*animation[i]);
			}
		}
	}
}


void OptionsManager::UpdateEvent(InputManager input)
{
	if (axis == 1)
	{
		if (input.KeyPressed(SDLK_RIGHT) || input.KeyPressed(SDLK_d))
		{
			itemNumber++;
		}

		else if (input.KeyPressed(SDLK_LEFT) || input.KeyPressed(SDLK_a))
		{
			itemNumber--;
		}
	}
	else
	{
		if (input.KeyPressed(SDLK_UP) || input.KeyPressed(SDLK_w))
		{
			itemNumber--;
		}

		else if (input.KeyPressed(SDLK_DOWN) || input.KeyPressed(SDLK_s))
		{
			itemNumber++;
		}
	}
}

void OptionsManager::Draw(SDL_Renderer *renderer)
{
	for (int i = 0; i < animation.size(); i++)
	{
		animation[i]->Draw(renderer);
	}
}

void OptionsManager::UnloadContent()
{
	image.free();

	attributes.clear();
	contents.clear();
	animation.clear();
	imageTexture.clear();
	optionsItems.clear();
	optionsLinks.clear();

	for (int i = 0; i < animation.size(); i++)
	{
		delete animation[i];
	}
	animation.clear();
	animationTypes.clear();
}
