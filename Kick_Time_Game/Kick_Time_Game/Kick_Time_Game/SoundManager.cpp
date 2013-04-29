#include "SoundManager.h"
#include "SoundData.h"

#include <iostream>

SoundManager::SoundManager(void)
{
	this->soundBuffer = new std::vector<sf::SoundBuffer>();
	this->sound = new sf::Sound();
}

SoundManager::~SoundManager(void)
{
	delete[] this->soundBuffer;
	delete[] this->sound;
}

void SoundManager::initializeSoundManager()
{
	for (int i = 0; i < NUMBER_SOUNDDATA; ++i)
	{
		sf::SoundBuffer buffer;
		if (buffer.loadFromFile(soundDataArray[i].getFileName()))
		{
			this->soundBuffer->push_back(buffer);
		}
		else
		{
			cerr << "Error in the loading of the sound " << soundDataArray[i].getFileName() << "!" << std::endl;
		}
	}
}

void SoundManager::updateSoundManager()
{
}

void SoundManager::playSound(int indexSound)
{
	this->sound->stop();
	this->sound->setBuffer(this->soundBuffer->at(indexSound));
	this->sound->play();
}