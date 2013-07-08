#include "SoundManager.h"
#include "SoundData.h"

#include <iostream>


SoundManager::SoundManager(void)
{
	this->soundBuffer = new std::vector<sf::SoundBuffer>();
    this->listSounds = new std::vector<sf::Sound*>();
	this->listMusics = new std::vector<sf::Music*>();
	this->volumeSound = 100;
	this->volumeMusic = 100;
}

SoundManager::~SoundManager(void)
{
	delete this->soundBuffer;
	delete this->listSounds;
	delete this->listMusics;
}

void SoundManager::initializeSoundManager()
{
	for (int i = 0; i < NUMBER_SOUNDDATA; ++i)
	{
		sf::SoundBuffer buffer;
		const SoundData * soundData = &soundDataArray[i];
		if (buffer.loadFromFile(soundData->getFileName()))
		{
			this->soundBuffer->push_back(buffer);
		}
		else
		{
			cerr << "Error in the loading of the sound " << soundData->getFileName() << " !" << std::endl;
		}
	}
}

void SoundManager::updateSoundManager()
{
	for (unsigned int i = 0; i < this->listSounds->size(); ++i)
	{
		sf::Sound * sound = this->listSounds->at(i);
		if (!sound->getStatus())
		{
			sound->stop();
			this->listSounds->erase(this->listSounds->begin() + i);
			delete sound;
			--i;
		}
	}
	for (unsigned int i = 0; i < this->listMusics->size(); ++i)
	{
		sf::Music * music = this->listMusics->at(i);
		if (!music->getStatus())
		{
			music->stop();
			this->listMusics->erase(this->listMusics->begin() + i);
			delete music;
			--i;
		}
	}
}

void SoundManager::playSoundMusic(int indexSoundMusic)
{
	if (soundDataArray[indexSoundMusic].getIsMusic())
		this->playMusic(indexSoundMusic);
	else
		this->playSound(indexSoundMusic);
}

void SoundManager::playSound(int indexSound)
{
	if (this->listSounds->size() + this->listMusics->size() > 255)
	{
		this->listSounds->at(0)->stop();
		this->listSounds->erase(this->listSounds->begin());
		delete this->listSounds->at(0);
	}

	this->listSounds->push_back(new sf::Sound());
	sf::Sound * sound = this->listSounds->at(this->listSounds->size()-1);
	sound->setBuffer(this->soundBuffer->at(indexSound));
	sound->setLoop(soundDataArray[indexSound].getIsLoop());
	sound->play();
	sound->setVolume(this->volumeSound);
}

void SoundManager::playMusic(int indexMusic)
{
	if (this->listSounds->size() + this->listMusics->size() > 255)
	{
		this->listSounds->at(0)->stop();
		this->listSounds->erase(this->listSounds->begin());
		delete this->listSounds->at(0);
	}

	this->listMusics->push_back(new sf::Music());
	sf::Music * music = this->listMusics->at(this->listMusics->size()-1);
	const SoundData * soundData = &soundDataArray[indexMusic];
	if (music->openFromFile(soundData->getFileName()))
	{
		music->setLoop(soundData->getIsLoop());
		music->play();
        music->setVolume(this->volumeMusic);
	}
	else
	{
		cerr << "Error in the loading of the sound " << soundData->getFileName() << " !" << std::endl;
	}
}

void SoundManager::stopAll()
{
	for (unsigned int i = 0; i < this->listSounds->size(); ++i)
	{
		sf::Sound * sound = this->listSounds->at(i);
		sound->stop();
		this->listSounds->erase(this->listSounds->begin() + i);
        delete sound;
		--i;
	}
	for (unsigned int i = 0; i < this->listMusics->size(); ++i)
	{
		sf::Music * music = this->listMusics->at(i);
		music->stop();
		this->listMusics->erase(this->listMusics->begin() + i);
        delete music;
		--i;
	}
}

float SoundManager::getVolumeSound()
{
    return this->volumeSound;
}

void SoundManager::setVolumeSound(float volumeSound)
{
    this->volumeSound = volumeSound;
    if (this->volumeSound > MAX_VOLUME)
        this->volumeSound = MAX_VOLUME;
    else if (this->volumeSound < 0)
        this->volumeSound = 0;
	for (unsigned int i = 0; i < this->listSounds->size(); ++i)
	{
		this->listSounds->at(i)->setVolume(this->volumeSound);
	}
}

float SoundManager::getVolumeMusic()
{
    return this->volumeMusic;
}

void SoundManager::setVolumeMusic(float volumeMusic)
{
    this->volumeMusic = volumeMusic;
    if (this->volumeMusic > MAX_VOLUME)
        this->volumeMusic = MAX_VOLUME;
    else if (this->volumeMusic < 0)
        this->volumeMusic = 0;
	for (unsigned int i = 0; i < this->listMusics->size(); ++i)
	{
		this->listMusics->at(i)->setVolume(this->volumeMusic);
	}
}
