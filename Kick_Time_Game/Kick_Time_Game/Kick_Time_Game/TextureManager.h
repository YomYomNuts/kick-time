#ifndef __TEXTUREMANAGER__
#define __TEXTUREMANAGER__

#include <SFML/Graphics.hpp>

#include <map>
#include <string>

using namespace std;

class TextureManager
{
private:
	map<string, sf::Texture> * textureList;

public:
	TextureManager(void);
	~TextureManager(void);
	void initializeTextureManager();
	void updateTextureManager();
	sf::Texture* getTexture(string textureName);
};

#endif