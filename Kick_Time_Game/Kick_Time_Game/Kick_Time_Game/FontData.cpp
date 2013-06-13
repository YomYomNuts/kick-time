#include "FontData.h"

const FontData fontDataArray[NUMBER_FONTDATA] =
{
	FontData("../Ressources/Fonts/arial.ttf", FONT_ARIAL),
};

FontData::FontData()
{
	this->fileName = "";
	this->fontID = 0;
}

FontData::FontData(string fileName, int fontID)
{
	this->fileName = fileName;
	this->fontID = fontID;
}

FontData::~FontData(void)
{
}

string FontData::getFileName() const
{
	return this->fileName;
}

int FontData::getFontID() const
{
	return this->fontID;
}
