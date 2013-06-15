#ifndef _LEVELDATA_H
#define _LEVELDATA_H

#include <string>
#include <vector>
#include <map>

#include "Templates.h"
#include "LevelAnimationData.h"

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
	const vector<LevelAnimationData> getLevelAnimationData() const;
};

#define NUMBER_LEVELDATA 2

extern const LevelData levelDataArray[NUMBER_LEVELDATA];

extern const map<int, vector<LevelAnimationData>> levelAnimDataArray;

#define LEVEL_0 0
#define LEVEL_1 1

#endif _LEVELDATA_H_
