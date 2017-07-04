/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include "FadeAnimation.h"

FadeAnimation::FadeAnimation()
{
	increase = false;
	fadeSpeed = 0.003f;
}


FadeAnimation::~FadeAnimation()
{
}
void FadeAnimation::SetIncrease(bool value)
{
	increase = value;
}

void FadeAnimation::Update(Animation &a)
{
	if (a.getActive() = true)
	{
		if (!increase) a.getAlpha() -= fadeSpeed;
		else a.getAlpha() += fadeSpeed;

		if (a.getAlpha() >= 1.0f)
		{
			a.getAlpha() = 1.0f;
			increase = false;
		}
		else if (a.getAlpha() <= 0.0f)
		{
			a.getAlpha() = 0.0f;
			increase = true;
		}
	}
	else
	{
		a.getAlpha() = 1.0f;
	}
}
