/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include "MenuManager.h"
#include "ScreenManager.h"

MenuManager::MenuManager()
{
}
MenuManager::~MenuManager()
{
}
void MenuManager::EqualizeMenuItems()
{
	for (int i = 0; i < menuItems.size(); i++)
	{
		if (imageTexture.size() == i)
		{
			imageTexture.push_back(null);
		}
	}

	for (int i = 0; i < imageTexture.size(); i++)
	{
		if (menuItems.size() == i)
		{
			menuItems.push_back("");
		}
	}
}
void MenuManager::SetAnimation(SDL_Renderer *renderer)
{
	for (int i = 0; i < menuItems.size(); i++)
	{
		animation.push_back(new Animation);
		animation[animation.size() - 1]->LoadContent(menuItems[i],contents[i],posX,posY,renderer);
	}
}
void MenuManager::SetPosition()
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

void MenuManager::LoadContent(std::string id, SDL_Renderer *renderer)
{
	null.loadFromFile("Files/Images/no.png",renderer);
	itemNumber = 0;
	system("cls");

	file.LoadContent("Files/config/Menu.cfg", attributes, contents, id);

	for (int i = 0; i < attributes.size(); i++)
	{
		for (int j = 0; j < attributes[i].size(); j++)
		{
			std::string att = attributes[i][j];
			std::string con = contents[i][j];

			if (att == "Text")
			{
				menuItems.push_back(con);
			}
			else if (att == "Image")
			{
				Image.loadFromFile(con, renderer);
				imageTexture.push_back(Image);
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
			else if (att == "ItemLink")
			{
				menuLinks.push_back(con);
			}	
		}
	}

	EqualizeMenuItems();
	SetAnimation(renderer);
	SetPosition();
}

void MenuManager::Update(SDL_Renderer *renderer, InputManager input)
{	
	if (input.KeyPressed(SDLK_RETURN))
	{
		ScreenManager::GetInstance().AddScreen(menuLinks[itemNumber], renderer);

		if (itemNumber == 4)
		{
			SDL_Quit();
		}
	}

	if (itemNumber < 0)
	{
		itemNumber = 0;
	}
	else if (itemNumber > menuItems.size() - 1)
	{
		itemNumber = menuItems.size() - 1;
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


void MenuManager::UpdateEvent(InputManager input)
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

void MenuManager::Draw(SDL_Renderer *renderer)
{
	for (int i = 0; i < animation.size(); i++)
	{
		animation[i]->Draw(renderer);
	}
}

void MenuManager::UnloadContent()
{
	Image.free();

	attributes.clear();
	contents.clear();
	animation.clear();
	imageTexture.clear();
	menuItems.clear();
	menuLinks.clear();

	for (int i = 0; i < animation.size(); i++)
	{
		delete animation[i];
	}
	animation.clear();
	animationTypes.clear();
}
