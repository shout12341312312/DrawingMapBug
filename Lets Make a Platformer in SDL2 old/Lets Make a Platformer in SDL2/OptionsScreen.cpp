/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include "OptionsScreen.h"

OptionsScreen::OptionsScreen()
{
}

OptionsScreen::~OptionsScreen()
{
}

void OptionsScreen::LoadContent(SDL_Renderer *renderer)
{
	options.LoadContent("Options", renderer);
}
void OptionsScreen::UnloadContent()
{
	GameScreen::UnloadContent();
	options.UnloadContent();
}
void OptionsScreen::Update(SDL_Renderer *renderer, SDL_Event &event)
{
	options.Update(renderer, input);
}
void OptionsScreen::UpdateEvent(SDL_Event &event)
{
	input.Update(event);
	options.UpdateEvent(input);
}
void OptionsScreen::Draw(SDL_Renderer *renderer)
{
	options.Draw(renderer);
}