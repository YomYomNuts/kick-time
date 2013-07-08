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
    vector<int> * characterDataIndex;
	void addCharacter(int indexTypeCharacter);
	void removeCharacter(int indexCharacter);
public:
	CharacterManager(void);
	~CharacterManager(void);
	void initializeCharacterManager();
	void updateCharacterManager();
	void addCharacterDataIndexAt(int indexCharacter, int indexTypeCharacter);
	void removeCharacterDataIndex(int indexCharacter);
	vector<int>* getCharactersDataIndex();
	void loadCharacters();
	void unloadCharacters();
	vector<Character*>* getCharacters();
	void renderCharacterManager();
	Character* getClosestCharacter(int withoutThisIndex, Position * position);
	Character* getFarestCharacter(int withoutThisIndex, Position * position);
	Character* getCharacterWithMaxHp();
};

#endif
