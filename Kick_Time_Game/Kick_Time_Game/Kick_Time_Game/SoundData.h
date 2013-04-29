#ifndef _SOUNDDATA_H
#define _SOUNDDATA_H

#include <string>

using namespace std;

class SoundData
{
private:
	string fileName;
	int soundID;
	bool isMusic;
	bool isLoop;
public:
	SoundData();
	SoundData(string fileName, int soundID, bool isMusic, bool isLoop);
	~SoundData(void);
	string getFileName() const;
	int getSoundID() const;
	bool getIsMusic() const;
	bool getIsLoop() const;
};

#define NUMBER_SOUNDDATA 1

extern const SoundData soundDataArray[NUMBER_SOUNDDATA];

#define SOUND_LEVEL_SCORPION 0

#endif _SOUNDDATA_H
