/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#pragma once
class FloatRect
{
public:
	FloatRect(float x, float y, float w, float h);
	~FloatRect(void);

	bool Collision(FloatRect f);
	
	const float Left, Right, Top, Bottom;
};

