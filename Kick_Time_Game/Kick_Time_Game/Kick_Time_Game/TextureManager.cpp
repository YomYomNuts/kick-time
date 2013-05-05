#include "TextureManager.h"
#include "AnimationData.h"
#include "LevelData.h"

#include <iostream>

TextureManager::TextureManager(void)
{
	this->textureList = new map<string, sf::Texture>();
}


TextureManager::~TextureManager(void)
{
	delete[] textureList;
}

void TextureManager::initializeTextureManager()
{
	int i;
	string currentFile = "";


	for(i = 0; i < NUMBER_ANIMATIONDATA; ++i)
	{
		if(strcmp(currentFile.c_str(),animationDataArray[i].getFileName().c_str()) != 0)
		{
			sf::Texture currentTexture;

			currentFile = animationDataArray[i].getFileName();

			if (!currentTexture.loadFromFile(currentFile))
			{
				cout << "Sprite didn't find!" << endl << currentFile << endl;
			}
			else
			{
				this->textureList->insert(pair<string, sf::Texture>(currentFile, currentTexture));
			}
			
		}
	}

	currentFile = "";

	for(i = 0; i < NUMBER_LEVELDATA; ++i)
	{
		if(strcmp(currentFile.c_str(),levelDataArray[i].getFileName().c_str()) != 0)
		{
			sf::Texture currentTexture;

			currentFile = levelDataArray[i].getFileName();

			if (!currentTexture.loadFromFile(currentFile))
			{
				cout << "Sprite didn't find!" << endl << currentFile << endl;
			}
			else
			{
				this->textureList->insert(pair<string, sf::Texture>(currentFile, currentTexture));
			}
			
		}
	}
}

void TextureManager::updateTextureManager()
{

}

sf::Texture* TextureManager::getTexture(string textureName)
{
	return &textureList->at(textureName);
}
