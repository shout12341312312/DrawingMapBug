
/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

class FileManager
{
public:
	FileManager();
	~FileManager();

	void LoadContent(std::string fileName, std::vector<std::vector<std::string>> &attributes, std::vector<std::vector<std::string>> &content);
	void LoadContent(std::string fileName, std::vector<std::vector<std::string>> &attributes, std::vector<std::vector<std::string>> &content, std::string id);
	void UnloadContent();

private:

	std::vector<std::string> tempAttributes;
	std::vector<std::string> tempContents;

	enum loadState { ATTRIBUTES, CONTENTS };
	int state;

	bool idFound;
};

