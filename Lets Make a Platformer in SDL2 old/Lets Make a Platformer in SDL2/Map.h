/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#pragma once
#include "Layer.h"
class Map
{
public:
	Map();
	~Map();

	void LoadContent(std::string mapID, SDL_Renderer *renderer);
	void UnloadContent();
	void Update(Player &e);
	void Draw(SDL_Renderer *renderer);
private:
	std::vector<Layer> layers;
	std::string mapID;
};

