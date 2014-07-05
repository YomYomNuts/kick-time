#ifndef _FONTDATA_H
#define _FONTDATA_H

#include <string>

using namespace std;

class FontData
{
private:
	string fileName;
	int fontID;

public:
	FontData();
	FontData(string fileName, int fontID);
	~FontData(void);
	string getFileName() const;
	int getFontID() const;
};

#define NUMBER_FONTDATA 1

extern const FontData fontDataArray[NUMBER_FONTDATA];

#define FONT_ARIAL 0

#endif //_FONTDATA_H
