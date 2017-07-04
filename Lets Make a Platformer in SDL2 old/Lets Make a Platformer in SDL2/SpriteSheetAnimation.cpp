/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include "SpriteSheetAnimation.h"

SpriteSheetAnimation::SpriteSheetAnimation()
{
	frameCounter = 0;
	switchFrame = 100;
}
SpriteSheetAnimation::~SpriteSheetAnimation()
{
}

void SpriteSheetAnimation::Draw(Animation &a, SDL_Renderer *renderer)
{
	a.Draw(renderer, SourceRect);
}

void SpriteSheetAnimation::Update(Animation &a)
{
	if (a.getActive())
	{
		frameCounter++;

		ticks = SDL_GetTicks();
		sprite = (ticks*6/1000) % 4;

		if (frameCounter >= switchFrame)
		{
			frameCounter = 0;
			a.CurrentFrame().first++;

			if (a.CurrentFrame().first * a.FrameDimentions().first >= a.Image().getWidth())
			{
				a.CurrentFrame().first = 0;
			}
		}
	}
	else
	{
		frameCounter = 0;
		a.CurrentFrame().first = 1;
		sprite = 1;
	}

	SourceRect.x = a.FrameDimentions().first * sprite;
	SourceRect.y = a.CurrentFrame().second *a.FrameDimentions().second;
	SourceRect.w = a.FrameDimentions().first;
	SourceRect.h = a.FrameDimentions().second;
}