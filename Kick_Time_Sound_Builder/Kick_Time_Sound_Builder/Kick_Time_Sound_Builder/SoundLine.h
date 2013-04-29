#ifndef _SOUNDLINE_H
#define _SOUNDLINE_H

#include <string>
using namespace std;

class SoundLine
{
private:
	string fileName;
	string soundID;
	bool isMusic;
	bool isLoop;
public:
	SoundLine(void);
	SoundLine(string fileName, string soundID, bool isMusic, bool isLoop);
	~SoundLine(void);
	string getFileName();
	string getSoundID();
	bool getIsMusic();
	bool getIsLoop();
};

#endif