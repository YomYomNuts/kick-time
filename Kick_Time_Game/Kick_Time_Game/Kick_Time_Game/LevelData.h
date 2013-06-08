#ifndef _LEVELDATA_H
#define _LEVELDATA_H

#include <string>

using namespace std;

class LevelData
{
private:
	string fileName;
	string levelName;
	int levelID;
	int posYCharacter;

public:
	LevelData();
	LevelData(string fileName, string levelName, int levelID, int posYCharacter);
	~LevelData(void);
	string getFileName() const;
	string getLevelName() const;
	int getLevelID() const;
	int getPosYCharacter() const;
};

#define NUMBER_LEVELDATA 1

extern const LevelData levelDataArray[NUMBER_LEVELDATA];

#define LEVEL_0 0

#endif _LEVELDATA_H
