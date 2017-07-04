/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include "Map.h"

Map::Map()
{
}

Map::~Map()
{
}

void Map::LoadContent(std::string mapID, SDL_Renderer *renderer)
{
	system("cls");
	this->mapID = mapID;
	Layer layerInstance;
	layers.push_back(layerInstance);
	layers[0].LoadContent("Layer1", this->mapID, renderer);
}
void Map::UnloadContent()
{
	layers[0].UnloadContent();
}
void Map::Update(Player &e)
{
	layers[0].Update(e);
}
void Map::Draw(SDL_Renderer *renderer)
{
	layers[0].Draw(renderer);
}