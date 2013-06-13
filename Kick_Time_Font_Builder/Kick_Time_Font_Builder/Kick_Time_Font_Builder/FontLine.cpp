#include "FontLine.h"


FontLine::FontLine(void)
{
	this->fileName = "";
	this->fontID = "";
}

FontLine::FontLine(string fileName, string fontID)
{
	this->fileName = fileName;
	this->fontID = fontID;
}

FontLine::~FontLine(void)
{
}

string FontLine::getFileName()
{
	return this->fileName;
}

string FontLine::getFontID()
{
	return this->fontID;
}