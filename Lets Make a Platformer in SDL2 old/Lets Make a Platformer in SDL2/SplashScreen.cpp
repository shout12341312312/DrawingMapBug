/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::LoadContent(SDL_Renderer *renderer)
{
	imageNumber = 0;
	keys.push_back(SDLK_ESCAPE);

	file.LoadContent("Files/config/Intro.cfg", attributes, contents);
	for (int i = 0; i < attributes.size(); i++)
	{
		for (int j = 0; j < attributes[i].size(); j++)
		{
			std::string att = attributes[i][j];

			if (att == "Image")
			{
				fade.push_back(new FadeAnimation);
				fade[fade.size() - 1]->LoadContent("", contents[i][j], 0, 0, renderer);
				fade[fade.size() - 1]->getActive() = true;
			}
		}
	}
}

void SplashScreen::UnloadContent()
{
	GameScreen::UnloadContent();
	for (int i = 0; i < fade.size(); i++)
	{
		fade[i]->UnloadContent();
		delete fade[i];
	}
	fade.clear();
}

void SplashScreen::Draw(SDL_Renderer *renderer)
{
	fade[imageNumber]->Draw(renderer);
}

void SplashScreen::Update(SDL_Renderer *renderer, SDL_Event &event)
{
	if (fade[imageNumber]->getAlpha() == 0.0f);
	{
		imageNumber++;
	}

	if (imageNumber != fade.size()-1)
	{
		fade[imageNumber]->Update(Fanimation);
	}

	if (imageNumber >= fade.size()-1)
	{
		ScreenManager::GetInstance().AddScreen("TitleScreen", renderer);
	}
}

void SplashScreen::UpdateEvent(SDL_Event &event)
{
	input.Update(event);
}