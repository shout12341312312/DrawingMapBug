/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#pragma once
#include "Animation.h"
class SpriteSheetAnimation : public Animation
{
public:
	SpriteSheetAnimation();
	~SpriteSheetAnimation();

	void Draw(Animation &a, SDL_Renderer *renderer);
	void Update(Animation &a);

private:
	Uint32 ticks, sprite;

	int frameCounter, switchFrame;
	SDL_Rect SourceRect;
};

