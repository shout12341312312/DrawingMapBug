/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#pragma once
#include <SDL.h>
#include "InputManager.h"
#include "FileManager.h"

class GameScreen
{
public:
	GameScreen();
	~GameScreen();

	virtual void LoadContent(SDL_Renderer *renderer);
	virtual void UnloadContent();
	virtual void UpdateEvent(SDL_Event &event);
	virtual void Update(SDL_Renderer *rendere, SDL_Event &event);
	virtual void Draw(SDL_Renderer *renderer);

protected:
	InputManager input;
	std::vector<int> keys;

	FileManager file;
	std::vector<std::vector<std::string>> attributes;
	std::vector<std::vector<std::string>> contents;
private:

};

