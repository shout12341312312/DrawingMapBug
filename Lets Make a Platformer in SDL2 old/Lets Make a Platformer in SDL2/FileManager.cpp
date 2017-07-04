/*Written 2017 by Michał Przekota.
To the extent possible under law, the author(s) have dedicated all copyright to men who want to help with the problem.
*/
#include "FileManager.h"

FileManager::FileManager()
{
	idFound = false;
}


FileManager::~FileManager()
{
}

void FileManager::LoadContent(std::string fileName, std::vector<std::vector<std::string>> &attributes, std::vector<std::vector<std::string>> &content)
{
	attributes.clear();
	content.clear();

	std::ifstream openFile(fileName.c_str());
	if (openFile.is_open())
	{
		while (!openFile.eof())
		{
			std::string line;
			std::getline(openFile, line);

			line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

			if (line.find("Load=") != std::string::npos)
			{
				state = ATTRIBUTES;
				line.erase(0, line.find('=') + 1);
				tempAttributes.clear();
			}
			else
			{
				state = CONTENTS;
				tempContents.clear();
			}
			line.erase(std::remove(line.begin(), line.end(), '['), line.end());
			std::stringstream str(line);
			while (str)
			{
				std::getline(str, line, ']');
				if (line != "")
				{
					if (state == ATTRIBUTES)
					{
						tempAttributes.push_back(line);
					}
					else
					{
						tempContents.push_back(line);
					}
					std::cout << line << std::endl;
				}
			}
			if (state == CONTENTS && tempContents.size() > 0)
			{
				attributes.push_back(tempAttributes);
				content.push_back(tempContents);
			}
		}
	}
}

void FileManager::LoadContent(std::string fileName, std::vector<std::vector<std::string>> &attributes, std::vector<std::vector<std::string>> &content, std::string id)
{
	attributes.clear();
	content.clear();

	std::ifstream openFile(fileName.c_str());

	idFound = false;
	if (openFile.is_open())
	{
		while (!openFile.eof())
		{
			std::string line;
			std::getline(openFile, line);
			
			if(line.find("Start=[" + id + "]") != std::string::npos) // npos zwraca true jeśli nie znajdzie żadnego tekstu w pliku
			{
				idFound = true;
				continue;
			}
			else if (line.find("End=") != std::string::npos && line.find(id) != std::string::npos)
			{
				idFound = false;
				break;
			}

			if (idFound)
			{
				if (line.find("Load=") != std::string::npos)
				{
					state = ATTRIBUTES;
					line.erase(0, line.find('=') + 1);
					tempAttributes.clear();
				}
				else
				{
					state = CONTENTS;
					tempContents.clear();
				}
				line.erase(std::remove(line.begin(), line.end(), '['), line.end());
				std::stringstream str(line);
				while (str)
				{
					std::getline(str, line, ']');
					if (line != "")
					{
						if (state == ATTRIBUTES)
						{
							tempAttributes.push_back(line);
						}
						else
						{
							tempContents.push_back(line);
						}
						std::cout << line << std::endl;
					}
				}
				if (state == CONTENTS && tempContents.size()>0)
				{
					attributes.push_back(tempAttributes);
					content.push_back(tempContents);
				}
			}
		}
	}
}

void FileManager::UnloadContent()
{
	tempAttributes.clear();
	tempContents.clear();
}