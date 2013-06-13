#ifndef _FONTMANAGER_H
#define _FONTMANAGER_H

#include <SFML\Graphics.hpp>

#include <vector>

using namespace std;

class FontManager
{
private:
	vector<sf::Font> * listFonts;

public:
	FontManager(void);
	~FontManager(void);
	void initializeFontManager();
	void updateFontManager();
	sf::Font* getFont(int indexFont);
};

#endif