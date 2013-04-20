#ifndef __LEVELLINE__
#define __LEVELLINE__

class LevelLine
{
private:
	char * fileName;
	char * levelID;
	char * levelName;
	int posX;
	int posY;
public:
	LevelLine(void);
	LevelLine(char * fileName, char * levelID, char * levelName, int posX, int posY);
	~LevelLine(void);
	char* getFileName();
	char* getLevelID();
	char* getLevelName();
	int getPosX();
	int getPosY();
};

#endif