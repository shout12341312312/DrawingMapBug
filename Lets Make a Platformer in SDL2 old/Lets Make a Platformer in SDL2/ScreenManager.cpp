/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include "ScreenManager.h"

ScreenManager::ScreenManager(void)
{
}

ScreenManager::~ScreenManager()
{
}

ScreenManager &ScreenManager::GetInstance()
{
	static ScreenManager instance;
	return instance;
}

void ScreenManager::Initialize(SDL_Renderer *renderer)
{
	transition = false;

	screenDirectory["SplashScreen"] = new SplashScreen();
	screenDirectory["TitleScreen"] = new TitleScreen();
	screenDirectory["XScreen"] = new XScreen();
	screenDirectory["GameplayScreen"] = new GameplayScreen();
	screenDirectory["OptionsScreen"] = new OptionsScreen();

	currentScreen = screenDirectory["GameplayScreen"];
}

void ScreenManager::LoadContent(SDL_Renderer *renderer)
{
	currentScreen->LoadContent(renderer);

	float posX, posY;
	posX = posY = 0;
}

void ScreenManager::Update(SDL_Renderer *renderer, SDL_Event &event)
{
	if (!transition)
	{
		currentScreen->Update(renderer, event);
	}
	else
		Transition(renderer);
}

void ScreenManager::UpdateEvent(SDL_Event &event)
{
	currentScreen->UpdateEvent(event);
}

void ScreenManager::Draw(SDL_Renderer *renderer)
{
	currentScreen->Draw(renderer);
}

void ScreenManager::AddScreen(std::string screenName, SDL_Renderer *renderer)
{
	fade.SetIncrease(true);
	transition = true;
	newScreen = screenDirectory[screenName];
	animationType.getActive() = true;
	animationType.getAlpha() = 0;
}

void ScreenManager::UnloadContent()
{
	animationType.UnloadContent();
	newScreen->UnloadContent();
	currentScreen->UnloadContent();
	delete currentScreen;
	delete newScreen;

	std::map<std::string, GameScreen*>::iterator tempIterator;

	for (tempIterator = screenDirectory.begin(); tempIterator != screenDirectory.end(); tempIterator++)
	{
	delete tempIterator->second;
	}
	screenDirectory.clear();
}

void ScreenManager::Transition(SDL_Renderer *renderer)
{
	if (transition)
	{
		fade.Update(animationType);
		if (animationType.getAlpha() >= 1.0f)
		{
			animationType.getAlpha() = 1;
			currentScreen->UnloadContent();
			currentScreen = newScreen;
			currentScreen->LoadContent(renderer);
			newScreen = NULL;
		}
		else if (animationType.getAlpha() <= 0.0f)
		{
			transition = false;
			animationType.getActive() = false;
		}
	}
}

float ScreenManager::getAlpha()
{
	return animationType.getAlpha();
}

void ScreenManager::SetCurrentScreen(GameScreen *currentScreen)
{
	this->currentScreen = currentScreen;
}