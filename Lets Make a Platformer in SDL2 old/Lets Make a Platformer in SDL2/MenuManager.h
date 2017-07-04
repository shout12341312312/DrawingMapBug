/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "FadeAnimation.h"
#include "FileManager.h"
#include "InputManager.h"
#include "Animation.h"

class MenuManager
{
public:
	MenuManager::MenuManager();
	MenuManager::~MenuManager();

	void LoadContent(std::string id, SDL_Renderer *renderer);
	void UnloadContent();
	void Draw(SDL_Renderer *renderer);
	void Update(SDL_Renderer *renderer, InputManager input);
	void UpdateEvent(InputManager input);

private:
	Texture null;
	Texture Image;
	FileManager file;
	FadeAnimation fade;

	std::vector<std::vector<std::string>> attributes;
	std::vector<std::vector<std::string>> contents;

	std::vector<Animation*> animation;
	std::vector<Texture> imageTexture;
	std::vector<std::string> menuItems;
	std::vector<std::string> animationTypes;
	std::vector<std::string> menuLinks;

	std::string align;

	int itemNumber;
	int posX, posY;
	int poSY, poSX;
	int axis;

	void EqualizeMenuItems();
	void SetAnimation(SDL_Renderer *renderer);
	void SetPosition();
};