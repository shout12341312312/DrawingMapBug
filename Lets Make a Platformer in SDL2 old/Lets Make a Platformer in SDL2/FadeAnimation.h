/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#pragma once
#include "Animation.h"

class FadeAnimation : public Animation
{
public:
	FadeAnimation();
	~FadeAnimation();

	void Update(Animation &a);
	void SetIncrease(bool value);

private:

	bool increase;
	float fadeSpeed;
};
