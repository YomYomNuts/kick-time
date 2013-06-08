#ifndef _CHARACTERMANAGER_H
#define _CHARACTERMANAGER_H
#include <vector>
#include <iostream>
#include "Character.h"

using namespace std;

class CharacterManager
{
private:
	vector<Character> * characterList;
public:
	CharacterManager(void);
	~CharacterManager(void);
	void initializeCharacterManager();
	void updateCharacterManager();
	void addCharacter();
	void renderCharacterManager();
	vector<Character>* getCharacters();
};

#endif