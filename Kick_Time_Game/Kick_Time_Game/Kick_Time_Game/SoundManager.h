#ifndef _SOUNDMANAGER_H
#define _SOUNDMANAGER_H

#include <SFML/Audio.hpp>

#include <vector>

using namespace std;

class SoundManager
{
private:
    vector<sf::SoundBuffer> * soundBuffer;
    vector<sf::Sound*> * listSounds;
	vector<sf::Music*> * listMusics;
	void playSound(int indexSound);
	void playMusic(int indexMusic);

public:
	SoundManager(void);
	~SoundManager(void);
	void initializeSoundManager();
	void updateSoundManager();
	void playSoundMusic(int indexSoundMusic);
	void stopAll();
};

#endif