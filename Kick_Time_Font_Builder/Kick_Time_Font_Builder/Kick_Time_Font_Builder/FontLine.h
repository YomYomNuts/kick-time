#ifndef _FONTLINE_H
#define _FONTLINE_H

#include <string>
using namespace std;

class FontLine
{
private:
	string fileName;
	string fontID;
public:
	FontLine(void);
	FontLine(string fileName, string fontID);
	~FontLine(void);
	string getFileName();
	string getFontID();
};

#endif