/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#pragma once
#include "Tile.h"
#include "FileManager.h"
#include <string>
#include <algorithm>

class Layer
{
public:
	Layer();
	~Layer();

	void LoadContent(std::string layerID, std::string mapID, SDL_Renderer *renderer);
	void UnloadContent();
	void Update(Player &player);
	void Draw(SDL_Renderer *renderer);
private:

	Texture tileSheet;
	FileManager file;

	SDL_Rect imageRectXXXX;

	std::vector<std::vector<std::string>> attributes;
	std::vector<std::vector<std::string>> contents;

	std::vector<std::pair<int, int>> solidTiles;
	std::vector<Tile> tiles;

	std::pair<int, int> SetTiles(std::string tileString);

	float posX;
	float posY;
};