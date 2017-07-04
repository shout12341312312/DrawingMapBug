/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include "FloatRect.h"

FloatRect::~FloatRect(void)
{
}

FloatRect::FloatRect(float x, float y, float w, float h)
	: Left(x), Right(x+w), Top(y), Bottom(y+h)
{

}


bool FloatRect::Collision(FloatRect f)
{
	if (Right < f.Left || Left> f.Right || Top > f.Bottom || Bottom < f.Top)
	{
		return false;
	}
	return true;
}