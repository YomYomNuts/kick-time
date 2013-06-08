#ifndef _SOUNDMANAGER_H
#define _SOUNDMANAGER_H

#include <SFML/Audio.hpp>

#include <vector>

using namespace std;

class SoundManager
{
private:
    vector<sf::SoundBuffer> * soundBuffer;
	sf::Sound * sound;

public:
	SoundManager(void);
	~SoundManager(void);
	void initializeSoundManager();
	void updateSoundManager();
	void playSound(int indexSound);
};

#endif