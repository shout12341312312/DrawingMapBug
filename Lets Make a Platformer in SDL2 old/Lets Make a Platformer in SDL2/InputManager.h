/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#pragma once
#include <SDL.h>
#include <vector>
#include <iostream>
class InputManager
{
public:
	InputManager();
	~InputManager();

	void Update(SDL_Event event);

	bool KeyPressed(int key);
	bool KeyPressed(std::vector <int> keys);

	bool KeyReleased(int key);
	bool KeyReleased(std::vector <int> keys);

	bool KeyDown(int key);
	bool KeyDown(std::vector <int> keys);
	
	bool KeyUp(int key);
	bool KeyUp(std::vector<int> keys);

private: 
	SDL_Event event;
};

