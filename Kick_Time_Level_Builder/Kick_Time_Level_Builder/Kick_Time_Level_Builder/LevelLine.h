#ifndef _LEVELLINE_H
#define _LEVELLINE_H

#include <string>

using namespace std;

class LevelLine
{
private:
	string fileName;
	string levelID;
	string levelName;
	int posYCharacter;
public:
	LevelLine(void);
	LevelLine(string fileName, string levelID, string levelName, int posYCharacter);
	~LevelLine(void);
	string getFileName();
	string getLevelID();
	string getLevelName();
	int getPosYCharacter();
};

#endif