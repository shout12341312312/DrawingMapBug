/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#pragma once
#include "GameScreen.h"
#include "FadeAnimation.h"
#include "FileManager.h"
#include "XScreen.h"
#include "TitleScreen.h"
#include "SplashScreen.h"
#include "MenuManager.h"
#include "GameplayScreen.h"
#include "OptionsScreen.h"

#include <map>

#define ScreenWidth 1280
#define ScreenHeight 720

class ScreenManager
{
public:
	~ScreenManager();
	static ScreenManager &GetInstance();

	void Initialize(SDL_Renderer *renderer);
	void LoadContent(SDL_Renderer *renderer);
	void UnloadContent();
	void Update(SDL_Renderer *renderer, SDL_Event &event);
	void UpdateEvent(SDL_Event &event);
	void Draw(SDL_Renderer *renderer);
	void AddScreen(std::string screenName, SDL_Renderer *renderer);
	void SetCurrentScreen(GameScreen* currentScreen);

	float getAlpha();

private:

	Animation animationType;
	FadeAnimation fade;

	GameScreen *currentScreen;
	GameScreen *newScreen;

	FileManager file;
	std::vector<std::vector<std::string>> attributes;
	std::vector<std::vector<std::string>> contentes;

	std::map<std::string, GameScreen*> screenDirectory;

	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator=(ScreenManager const&);

	void Transition(SDL_Renderer *renderer);
	bool transition;
};
