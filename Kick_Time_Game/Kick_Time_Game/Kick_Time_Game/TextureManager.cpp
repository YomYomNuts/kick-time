#include "TextureManager.h"
#include "AnimationData.h"
#include "LevelData.h"
#include "CharacterData.h"
#include "HudManager_Defines.h"
#include "Menu_Defines.h"

#include <string.h>
#include <iostream>


TextureManager::TextureManager(void)
{
	this->textureList = new map<string, sf::Texture>();
}


TextureManager::~TextureManager(void)
{
	delete textureList;
}

void TextureManager::initializeTextureManager()
{
	int i;
	string currentFile = "";
	sf::Texture currentTexture;

	// Textures Animations
	for(i = 0; i < NUMBER_ANIMATIONDATA; ++i)
	{
		if(strcmp(currentFile.c_str(),animationDataArray[i].getFileName().c_str()) != 0)
		{
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

	// Textures Levels
	currentFile = "";
	for(i = 0; i < NUMBER_LEVELDATA; ++i)
	{
		if(strcmp(currentFile.c_str(),levelDataArray[i].getFileName().c_str()) != 0)
		{
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

	// Textures Character
	currentFile = "";
	for(i = 0; i < NUMBER_CHARACTERDATA; ++i)
	{
		if(strcmp(currentFile.c_str(),characterDataArray[i].getPathAvatar().c_str()) != 0)
		{
			currentFile = characterDataArray[i].getPathAvatar();
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

	// Texture Menu
	if (!currentTexture.loadFromFile(FILE_MENU))
	{
		cout << "Sprite didn't find!" << endl << FILE_MENU << endl;
	}
	else
	{
		this->textureList->insert(pair<string, sf::Texture>(FILE_MENU, currentTexture));
	}

	// Texture Menu Selection
	if (!currentTexture.loadFromFile(FILE_MENU_SELECTION))
	{
		cout << "Sprite didn't find!" << endl << FILE_MENU_SELECTION << endl;
	}
	else
	{
		this->textureList->insert(pair<string, sf::Texture>(FILE_MENU_SELECTION, currentTexture));
	}

	// Texture HUD
	if (!currentTexture.loadFromFile(FILE_HUD))
	{
		cout << "Sprite didn't find!" << endl << FILE_HUD << endl;
	}
	else
	{
		this->textureList->insert(pair<string, sf::Texture>(FILE_HUD, currentTexture));
	}
}

void TextureManager::updateTextureManager()
{

}

sf::Texture* TextureManager::getTexture(string textureName)
{
	return &textureList->at(textureName);
}
