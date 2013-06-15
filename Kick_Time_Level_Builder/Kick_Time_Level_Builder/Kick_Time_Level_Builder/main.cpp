#include "LevelLine.h"
#include "functions.h"
#include "AnimationLine.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[])
{
	// Variables to get/set data for locations
	char* levelLocation = new char[];
	char* outputLocation = new char[];
	char confirm = 'n';
	bool resetData = false;

	// Variables for files' creation
	char* headerOutputLocation = new char[];
	char* cppOutputLocation = new char[];

	// Variable to open/read/create/write files
	// Level file
	vector<LevelLine> listLevels;
	vector<LevelLine>::iterator it;
	ifstream levelFile;
	string currentLine;
	string delimiter = ";";
	vector<string> tempInformations;
	string fileName;
	string levelName;
	string levelID;
	int posYCharacter;
	// Header file
	ofstream headerFile;
	string headerContent;
	int position;
	char buffer[500];
	// CPP file
	ofstream cppFile;
	string cppContent;

	//Level Animations
	vector<char*> animFilesList;
	vector<AnimationLine> animArray;
	vector<AnimationLine>::iterator itAnim;
	ifstream animFile;
	//string currentLine;
	//string delimiter = ";";
	//vector<string> tempInformations;
	//string fileName;
	int animationNumber;
	int posX;
	int posY;
	int spriteWidth;
	int spriteHeight;
	int framerate;
	int spriteNb;
	bool animationLoop;
	int posXAnim;
	int posYAnim;
	int levelNumber;
	int tempLevelNumber;
	//// Header file
	//ofstream headerFile;
	//string headerContent;
	//int position;
	//char buffer[500];
	//// CPP file
	//ofstream cppFile;
	//string cppContent;

	/*****************************/
	/* Get and set the locations */
	/*****************************/

	// Get the info from the arguments if there is any set
	if(argc > 1)
	{
		if(argc == 3)
		{
			// Put the arguments into the variables
			levelLocation = new char[strlen(argv[1])+1];
			strcpy_s(levelLocation, strlen(argv[1])+1, argv[1]);

			outputLocation = new char[strlen(argv[2])+1];
			strcpy_s(outputLocation, strlen(argv[2])+1, argv[2]);
		}
		else
		{
			// Error message - Not enough argument
			cout << "Not enough argument provided!\nPlease check your settings." << endl;
			system("Pause");
			return 1;
		}

		// We ask the user if the data are ok
		while(confirm != 'y')
		{
			// If the user pressed 'n', then he can reset the data as he wishes
			if(resetData)
			{
				cout << "Set \"Level file's location\" : ";
				cin >> levelLocation;
				cout << "Set \"Output class location\" : ";
				cin >> outputLocation;
				cout << endl << endl << endl;
			}
			cout << "Confirm : " << endl;
			cout << "Level file's location : " << levelLocation << endl << endl;
			cout << "Output class location : " << outputLocation << endl << endl;

			cout << "Confirm (y/n) : ";
			cin >> confirm;
			resetData = true;
		}

	}
	// No argument set, so the user has to define them
	else
	{
		while(confirm != 'y')
		{
			cout << "Set \"Level file's location\" : ";
			cin >> levelLocation;
			cout << "Set \"Output class location\" : ";
			cin >> outputLocation;
			cout << endl << endl << endl;

			cout << "Confirm : " << endl;
			cout << "Level file's location : " << levelLocation << endl << endl;
			cout << "Output class location : " << outputLocation << endl << endl;

			cout << "Confirm (y/n) : ";
			cin >> confirm;
			resetData = true;
		}
	}

	// Check the level file
	// Check if it's a text file
	/*if(strcmp(subChar(levelLocation, findChar(levelLocation,'levels.',LAST), strlen(levelLocation)-1), ".txt") != 0)
	{
		cout << "Please select an level file as a '.txt' file" << endl;
		system("Pause");
		return 1;
	}*/

	/************************/
	/* Read the level files */
	/************************/
	char* levelTXT = new char[];
	levelTXT = new char [strlen(levelLocation)+1];
	strcpy_s(levelTXT, strlen(levelLocation)+1, levelLocation);
	strcat_s(levelTXT,strlen(levelTXT)+12, "/levels.txt");
	// Open the level file
	
	levelFile.open(levelTXT, ios::in);

	if(!levelFile)
	{
		cout << endl << "ERROR - The level file \"levels.txt\" is missing." << endl << endl;
		cout << "It should be placed in the folder:\n\t- " << levelLocation << "\\" << endl <<endl << endl;
		system("Pause");
		return 1;
	}

	if(levelFile)
	{
		while(!levelFile.eof())
		{
			// Get the full current line
			getline(levelFile, currentLine);

			if(!currentLine.empty())
			{
				/****************************/
				/* Get the different values */
				/****************************/
				tempInformations = split(currentLine, delimiter);
				if (tempInformations.size() == 4)
				{
					fileName = tempInformations[0];
					levelID = tempInformations[1];
					levelName = tempInformations[2];
					posYCharacter = 0;
					if (isNumeric(tempInformations[3].c_str(), 10))
						posYCharacter = strtol(tempInformations[3].c_str(), NULL, 10);
					else
					{
						cout << "ERROR GD002 - A problem occured while getting the Y position of the character in this line:\n	" << currentLine << endl;
						system("Pause");
						return 1;
					}

					listLevels.push_back(*new LevelLine(fileName, levelID, levelName, posYCharacter));
				}
				else
				{
					cout << "ERROR GD001 - A problem occured while getting the informations of a level in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}
			}
		}
	}
	else
	{
		cout << "ERROR OP001 - Can't open the level file." << endl;
		system("Pause");
		return 1;
	}

	levelFile.close();

	/**********************************************************/
	/* Get the location and the name of the animation's files */
	/**********************************************************/

	getFilesLocation(levelLocation, animFilesList, "anim.txt");
	
	// Check if at least one file has been found
	if(animFilesList.size() == 0){
		cout << "ERROR - No animation file found" << endl;
		system("Pause");
		return 1;
	}
	
	/***************************/
	/* Read the animation file */
	/***************************/

	// Go to the beginning of the list
	vector<char*>::iterator iteratorFile;
	
	for(iteratorFile = animFilesList.begin(); iteratorFile != animFilesList.end(); iteratorFile++)
	{
		// Open the animation file
		animFile.open(*iteratorFile,ios::in);

		if(animFile)
		{
			while(!animFile.eof())
			{
				// Get the full current line
				getline(animFile, currentLine);

				if(!currentLine.empty())
				{
					/****************************/
					/* Get the different values */
					/****************************/
					tempInformations = split(currentLine, delimiter);
					if (tempInformations.size() >= 10)
					{
						// Get levelNumber
						levelNumber = 0;
						if (isNumeric(tempInformations[0].c_str(), 10))
							levelNumber = strtol(tempInformations[0].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD001 -A problem occured while getting the level number in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}

						fileName = tempInformations[1];

						// Get animationNumber
						animationNumber = 0;
						if (isNumeric(tempInformations[2].c_str(), 10))
							animationNumber = strtol(tempInformations[2].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD002 -A problem occured while getting the animation number in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}

						// Get posX
						posX = 0;
						if (isNumeric(tempInformations[3].c_str(), 10))
							posX = strtol(tempInformations[3].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD003 -A problem occured while getting the X position in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}
						// Get posY
						posY = 0;
						if (isNumeric(tempInformations[4].c_str(), 10))
							posY = strtol(tempInformations[4].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD004 - A problem occured while getting the Y position in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}
						// Get spriteWidth
						spriteWidth = 0;
						if (isNumeric(tempInformations[5].c_str(), 10))
							spriteWidth = strtol(tempInformations[5].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD005 - A problem occured while getting the sprite's width in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}
						// Get spriteHeight
						spriteHeight = 0;
						if (isNumeric(tempInformations[6].c_str(), 10))
							spriteHeight = strtol(tempInformations[6].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD006 - A problem occured while getting the sprite's height in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}
						// Get framerate
						framerate = 0;
						if (isNumeric(tempInformations[7].c_str(), 10))
							framerate = strtol(tempInformations[7].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD007 - A problem occured while getting the framerate in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}
						// Get spriteNb
						spriteNb = 0;
						if (isNumeric(tempInformations[8].c_str(), 10))
							spriteNb = strtol(tempInformations[8].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD008 - A problem occured while getting the number of sprites in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}
						// Get animationLoop
						string tempAnimationLoopStr = tempInformations[9];
						transform(tempAnimationLoopStr.begin(), tempAnimationLoopStr.end(), tempAnimationLoopStr.begin(), ::tolower);
						if (strcmp(tempAnimationLoopStr.c_str(), "true") != 0 && strcmp(tempAnimationLoopStr.c_str(), "false") != 0)
						{
							cout << "ERROR GD009 - A problem occured while getting the loop animation value in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}
						else
						{
							if (strcmp(tempAnimationLoopStr.c_str(), "true") == 0)
								animationLoop = true;
							else
								animationLoop = false;
						}
						// Get posXAnim
						posXAnim = 0;
						if (isNumeric(tempInformations[10].c_str(), 10))
							posXAnim = strtol(tempInformations[10].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD010 -A problem occured while getting the X position of the animation in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}
						// Get posYAnim
						posYAnim = 0;
						if (isNumeric(tempInformations[11].c_str(), 10))
							posYAnim = strtol(tempInformations[11].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD011 - A problem occured while getting the Y position of the animation in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}

						animArray.push_back(*new AnimationLine(levelNumber, fileName, animationNumber, posX, posY, spriteWidth, spriteHeight, framerate, spriteNb, animationLoop, posXAnim, posYAnim));
					}
					else
					{
						cout << "ERROR GD001 - A problem occured while getting the informations of an animation in this line:\n	" << currentLine << endl;
						system("Pause");
						return 1;
					}
				}
			}
			animFile.close();
		}
		else
		{
			cout << "ERROR OP001 - Can't open the animation file." << endl;
			system("Pause");
			return 1;
		}
	}

	/*********************/
	/* Set the '.h' file */
	/*********************/

	// Set the location of the file
	headerOutputLocation = new char[strlen(outputLocation) + strlen("\\LevelData.h") + 1];
	strcpy_s(headerOutputLocation,strlen(outputLocation)+1,outputLocation);
	strcat_s(headerOutputLocation,strlen(headerOutputLocation)+strlen("\\LevelData.h")+1,"\\LevelData.h");
	
	// Create and open the file
	headerFile.open(headerOutputLocation, ios::out|ios::trunc);

	if(headerFile)
	{
		sprintf_s(buffer, "%d", listLevels.size());
		headerContent = "#ifndef _LEVELDATA_H\n";
		headerContent = headerContent + "#define _LEVELDATA_H\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "#include <string>\n";
		headerContent = headerContent + "#include <vector>\n";
		headerContent = headerContent + "#include <map>\n\n";
		headerContent = headerContent + "#include \"Templates.h\"\n";
		headerContent = headerContent + "#include \"LevelAnimationData.h\"\n\n";
		headerContent = headerContent + "using namespace std;\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "class LevelData\n";
		headerContent = headerContent + "{\n";
		headerContent = headerContent + "private:\n";
		headerContent = headerContent + "\tstring fileName;\n";
		headerContent = headerContent + "\tstring levelName;\n";
		headerContent = headerContent + "\tint levelID;\n";
		headerContent = headerContent + "\tint posYCharacter;\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "public:\n";
		headerContent = headerContent + "\tLevelData();\n";
		headerContent = headerContent + "\tLevelData(string fileName, string levelName, int levelID, int posYCharacter);\n";
		headerContent = headerContent + "\t~LevelData(void);\n";
		headerContent = headerContent + "\tstring getFileName() const;\n";
		headerContent = headerContent + "\tstring getLevelName() const;\n";
		headerContent = headerContent + "\tint getLevelID() const;\n";
		headerContent = headerContent + "\tint getPosYCharacter() const;\n";
		headerContent = headerContent + "\tconst vector<LevelAnimationData> getLevelAnimationData() const;\n";
		headerContent = headerContent + "};\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "#define NUMBER_LEVELDATA " + buffer + "\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "extern const LevelData levelDataArray[NUMBER_LEVELDATA];\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "extern const map<int, vector<LevelAnimationData>> levelAnimDataArray;\n";
		headerContent = headerContent + "\n";
		

		// Define the animations' name
		position = 0;
		for(it = listLevels.begin(); it != listLevels.end(); ++it)
		{
			sprintf_s(buffer, "%d", position);
			headerContent = headerContent + "#define " + it->getLevelID() + " " + buffer + "\n";
			++position;
		}

		headerContent = headerContent + "\n";
		headerContent = headerContent + "#endif _LEVELDATA_H_\n";

		headerFile << headerContent;
	}
	else
	{
		cout << "ERROR OP002 - Can't create the header file." << endl;
		system("Pause");
		return 1;
	}

	headerFile.close();
	
	/***********************/
	/* Set the '.cpp' file */
	/***********************/
	
	// Set the location of the file
	cppOutputLocation = new char[strlen(outputLocation) + strlen("\\LevelData.cpp") + 1];
	strcpy_s(cppOutputLocation,strlen(outputLocation)+1,outputLocation);
	strcat_s(cppOutputLocation,strlen(cppOutputLocation)+strlen("\\LevelData.cpp")+1,"\\LevelData.cpp");
	
	// Create and open the file
	cppFile.open(cppOutputLocation, ios::out|ios::trunc);

	if(cppFile)
	{
		cppContent = "#include \"LevelData.h\"\n";
		cppContent = cppContent + "\n";

		cppContent = cppContent + "const LevelData levelDataArray[NUMBER_LEVELDATA] =\n";
		cppContent = cppContent + "{\n";

		// Put all the data into the animationArray in the cpp file
		for(it = listLevels.begin(); it != listLevels.end(); it++)
		{
			// Put : LevelData
			sprintf_s(buffer, "%d", it->getPosYCharacter());
			cppContent = cppContent + "\tLevelData(\"" + it->getFileName() + "\", \"" + it->getLevelName() + "\", " +
				it->getLevelID() + ", " + buffer + "),\n";
		}
		
		cppContent = cppContent + "};\n";
		cppContent = cppContent + "\n";

		cppContent = cppContent + "const map<int, vector<LevelAnimationData>> levelAnimDataArray = create_map<int, vector<LevelAnimationData>>\n";

		// Put all the data into the map in the cpp file
		tempLevelNumber = -1;
		for(itAnim = animArray.begin(); itAnim != animArray.end(); ++itAnim)
		{
			if(itAnim->getLevelNumber() != tempLevelNumber)
			{
				if(itAnim != animArray.begin())
					cppContent = cppContent + "\t)\n";

				tempLevelNumber = itAnim->getLevelNumber();

				// Put : animationNumber
				sprintf_s(buffer, "%d", itAnim->getLevelNumber());
				cppContent = cppContent + "\t(LEVEL_" + buffer + ", create_vector<LevelAnimationData>\n";
			}
			
			// Put the data
			cppContent = cppContent + "\t\t(LevelAnimationData(\"" + itAnim->getFileName() + "\", ";

			// Put : fileName 
			//cppContent = cppContent + "\tAnimationData(\"" + itAnim->getFileName() + "\", ";
			
			// Put : animationNumber
			sprintf_s(buffer, "%d", itAnim->getAnimationNumber());
			cppContent = cppContent + buffer + ", ";

			// Put : posX
			sprintf_s(buffer, "%d", itAnim->getPosX());
			cppContent = cppContent + buffer + ", ";

			// Put : posY
			sprintf_s(buffer, "%d", itAnim->getPosY());
			cppContent = cppContent + buffer + ", ";
			
			// Put : spriteWidth
			sprintf_s(buffer, "%d", itAnim->getSpriteWidth());
			cppContent = cppContent + buffer + ", ";
			
			// Put : spriteHeight
			sprintf_s(buffer, "%d", itAnim->getSpriteHeight());
			cppContent = cppContent + buffer + ", ";

			// Put : framerate
			sprintf_s(buffer, "%d", itAnim->getFramerate());
			cppContent = cppContent + buffer + ", ";

			// Put : spriteNb
			sprintf_s(buffer, "%d", itAnim->getSpriteNb());
			cppContent = cppContent + buffer + ", ";

			// Put : animationLoop
			if (itAnim->getAnimationLoop())
				cppContent = cppContent + "true, ";
			else
				cppContent = cppContent + "false, ";

			// Put : posXAnim
			sprintf_s(buffer, "%d", itAnim->getPosXAnim());
			cppContent = cppContent + buffer + ", ";

			// Put : posYAnim
			sprintf_s(buffer, "%d", itAnim->getPosYAnim());
			cppContent = cppContent + buffer;

			cppContent = cppContent + "))\n";
		}
		
		cppContent = cppContent + ");\n";

		cppContent = cppContent + "\n";
		cppContent = cppContent + "LevelData::LevelData()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tthis->fileName = \"\";\n";
		cppContent = cppContent + "\tthis->levelName = \"\";\n";
		cppContent = cppContent + "\tthis->levelID = 0;\n";
		cppContent = cppContent + "\tthis->posYCharacter = 0;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "LevelData::LevelData(string fileName, string levelName, int levelID, int posYCharacter)\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tthis->fileName = fileName;\n";
		cppContent = cppContent + "\tthis->levelName = levelName;\n";
		cppContent = cppContent + "\tthis->levelID = levelID;\n";
		cppContent = cppContent + "\tthis->posYCharacter = posYCharacter;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "LevelData::~LevelData(void)\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "string LevelData::getFileName() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->fileName;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "string LevelData::getLevelName() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->levelName;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int LevelData::getLevelID() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->levelID;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int LevelData::getPosYCharacter() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->posYCharacter;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "const vector<LevelAnimationData> LevelData::getLevelAnimationData() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn levelAnimDataArray.at(this->levelID);\n";
		cppContent = cppContent + "}\n";
		
		cppFile << cppContent;
	}
	else{
		cout << "ERROR OP003 - Can't create the .cpp file." << endl;
		system("Pause");
		return 1;
	}

	cppFile.close();

	/*****************/
	/* Final message */
	/*****************/

	cout << endl << endl << "The following 2 files have been successfully generated :" << endl;
	cout << "	- LevelData.h" << endl;
	cout << "	- LevelData.cpp" << endl;
	cout << "into the folder :" << endl;
	cout << "	- " << outputLocation << endl << endl;

	system("Pause");
	return 0;
}