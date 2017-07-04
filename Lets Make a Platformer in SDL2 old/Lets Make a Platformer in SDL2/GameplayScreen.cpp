/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include "GameplayScreen.h"

GameplayScreen::GameplayScreen()
{
}

GameplayScreen::~GameplayScreen()
{
}

void GameplayScreen::LoadContent(SDL_Renderer *renderer)
{
	map.LoadContent("Map", renderer);
	player.LoadContent(renderer);
}
void GameplayScreen::UnloadContent()
{
	GameScreen::UnloadContent();
	player.UnloadContent();
	map.UnloadContent();
}
void GameplayScreen::Update(SDL_Renderer *renderer, SDL_Event &event)
{
	input.Update(event);
	player.Update(renderer,input);
	map.Update(player);
}

void GameplayScreen::Draw(SDL_Renderer *renderer)
{
	map.Draw(renderer);
	player.Draw(renderer);
}

void GameplayScreen::UpdateEvent(SDL_Event &event)
{
}