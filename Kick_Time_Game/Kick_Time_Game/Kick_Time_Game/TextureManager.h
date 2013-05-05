#ifndef __TEXTUREMANAGER__
#define __TEXTUREMANAGER__
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

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