/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include "TitleScreen.h"

TitleScreen::TitleScreen()
{
}

TitleScreen::~TitleScreen()
{
}

void TitleScreen::LoadContent(SDL_Renderer *renderer)
{
	keys.push_back(SDLK_ESCAPE);
	menu.LoadContent("Menu",renderer);
}

void TitleScreen::UnloadContent()
{
	GameScreen::UnloadContent();
	menu.UnloadContent();
}
void TitleScreen::Draw(SDL_Renderer *renderer)
{
	menu.Draw(renderer);
}

void TitleScreen::Update(SDL_Renderer *renderer, SDL_Event &event)
{
	menu.Update(renderer,input);
}

void TitleScreen::UpdateEvent(SDL_Event &event)
{
	input.Update(event);
	menu.UpdateEvent(input);
}