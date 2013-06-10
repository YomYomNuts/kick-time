#ifndef _CHARACTERMANAGER_H
#define _CHARACTERMANAGER_H

#include "Character.h"

#include <vector>
#include <iostream>

using namespace std;

class CharacterManager
{
private:
	vector<Character*> * characterList;

public:
	CharacterManager(void);
	~CharacterManager(void);
	void initializeCharacterManager();
	void updateCharacterManager();
	void addCharacter();
	vector<Character*>* getCharacters();
	void renderCharacterManager();
	Character* getClosestCharacter(int withoutThisIndex, Position * position);
};

#endif