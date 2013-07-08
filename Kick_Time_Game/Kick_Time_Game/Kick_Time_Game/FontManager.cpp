#include "FontManager.h"
#include "FontData.h"

#include <iostream>


FontManager::FontManager(void)
{
	this->listFonts = new vector<sf::Font>();
}

FontManager::~FontManager(void)
{
	delete this->listFonts;
}

void FontManager::initializeFontManager()
{
	for (int i = 0; i < NUMBER_FONTDATA; ++i)
	{
		sf::Font buffer;
		const FontData * fontData = &fontDataArray[i];
		if (buffer.loadFromFile(fontData->getFileName()))
		{
			this->listFonts->push_back(buffer);
		}
		else
		{
			cerr << "Error in the loading of the sound " << fontData->getFileName() << " !" << endl;
		}
	}
}

void FontManager::updateFontManager()
{
}

sf::Font* FontManager::getFont(int indexFont)
{
	return &this->listFonts->at(indexFont);
}
