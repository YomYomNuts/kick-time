#include "functions.h"
#include "AnimationLine.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc,const char * argv[])
{
	// Variables to get/set data for locations
	char* animLocation = new char[];
	char* outputLocation = new char[];
	char confirm = 'n';
	bool resetData = false;

	// Variables for files' creation
	char* headerOutputLocation = new char[];
	char* cppOutputLocation = new char[];

	// Variable to open/read/create/write files
	// Animation file
	vector<char*> animFilesList;
	vector<AnimationLine> animArray;
	vector<AnimationLine>::iterator it;
	ifstream animFile;
	string currentLine;
	string delimiter = ";";
	vector<string> tempInformations;
	string fileName;
	string animationName;
	int posX;
	int posY;
	int spriteWidth;
	int spriteHeight;
	int framerate;
	int spriteNb;
	bool animationLoop;
	// Header file
	ofstream headerFile;
	string headerContent;
	int position;
	char buffer[500];
	// CPP file
	ofstream cppFile;
	string cppContent;

	/*****************************/
	/* Get and set the locations */
	/*****************************/

	// Get the info from the arguments if there is any set
	if(argc > 1)
	{
		if(argc == 3)
		{
			// Put the arguments into the variables
			animLocation = new char[strlen(argv[1])+1];
			strcpy_s(animLocation, strlen(argv[1])+1, argv[1]);
			outputLocation = new char [strlen(argv[2])+1];
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
				cout << "Set \"animation file's location\" : ";
				cin >> animLocation;
				cout << "Set \"Output class location\" : ";
				cin >> outputLocation;
				cout << endl << endl << endl;
			}
			cout << "Confirm : " << endl;
			cout << "Animation file's location : " << animLocation << endl << endl;
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
			cout << "Set \"animation file's location\" : ";
			cin >> animLocation;
			cout << "Set \"Output class location\" : ";
			cin >> outputLocation;
			cout << endl << endl << endl;

			cout << "Confirm : " << endl;
			cout << "Animation file's location : " << animLocation << endl << endl;
			cout << "Output class location : " << outputLocation << endl << endl;

			cout << "Confirm (y/n) : ";
			cin >> confirm;
			resetData = true;
		}
	}

	/**********************************************************/
	/* Get the location and the name of the animation's files */
	/**********************************************************/

	getAnimFilesLocation(animLocation, animFilesList);
	
	// Check if at least one file has been found
	if(animFilesList.size() == 0){
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
					if (tempInformations.size() == 9)
					{
						fileName = tempInformations[0];
						animationName = tempInformations[1];
						// Get posX
						posX = 0;
						if (isNumeric(tempInformations[2].c_str(), 10))
							posX = strtol(tempInformations[2].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD002 -A problem occured while getting the X position in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}
						// Get posY
						posY = 0;
						if (isNumeric(tempInformations[3].c_str(), 10))
							posY = strtol(tempInformations[3].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD003 - A problem occured while getting the Y position in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}
						// Get spriteWidth
						spriteWidth = 0;
						if (isNumeric(tempInformations[4].c_str(), 10))
							spriteWidth = strtol(tempInformations[4].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD004 - A problem occured while getting the sprite's width in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}
						// Get spriteHeight
						spriteHeight = 0;
						if (isNumeric(tempInformations[5].c_str(), 10))
							spriteHeight = strtol(tempInformations[5].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD005 - A problem occured while getting the sprite's height in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}
						// Get framerate
						framerate = 0;
						if (isNumeric(tempInformations[6].c_str(), 10))
							framerate = strtol(tempInformations[6].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD006 - A problem occured while getting the framerate in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}
						// Get spriteNb
						spriteNb = 0;
						if (isNumeric(tempInformations[7].c_str(), 10))
							spriteNb = strtol(tempInformations[7].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD007 - A problem occured while getting the number of sprites in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}
						// Get animationLoop
						string tempAnimationLoopStr = tempInformations[8];
						transform(tempAnimationLoopStr.begin(), tempAnimationLoopStr.end(), tempAnimationLoopStr.begin(), ::tolower);
						if (strcmp(tempAnimationLoopStr.c_str(), "true") != 0 && strcmp(tempAnimationLoopStr.c_str(), "false") != 0)
						{
							cout << "ERROR GD008 - A problem occured while getting the loop animation value in this line:\n	" << currentLine << endl;
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

						animArray.push_back(*new AnimationLine(fileName, animationName, posX, posY, spriteWidth, spriteHeight, framerate, spriteNb, animationLoop));
					}
					else
					{
						cout << "ERROR GD001 - A problem occured while getting the informations of a level in this line:\n	" << currentLine << endl;
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
	headerOutputLocation = new char[strlen(outputLocation) + strlen("\\AnimationData.h") + 1];
	strcpy_s(headerOutputLocation,strlen(outputLocation)+1,outputLocation);
	strcat_s(headerOutputLocation,strlen(headerOutputLocation)+strlen("\\AnimationData.h")+1,"\\AnimationData.h");
	
	// Create and open the file
	headerFile.open(headerOutputLocation, ios::out|ios::trunc);

	if(headerFile)
	{
		sprintf_s(buffer, "%d", animArray.size());
		headerContent = "#ifndef _ANIMATIONDATA_H\n";
		headerContent = headerContent + "#define _ANIMATIONDATA_H\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "#include <string>\n\n";
		headerContent = headerContent + "using namespace std;\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "class AnimationData\n";
		headerContent = headerContent + "{\n";
		headerContent = headerContent + "private:\n";
		headerContent = headerContent + "\tstring fileName;\n";
		headerContent = headerContent + "\tint animationName;\n";
		headerContent = headerContent + "\tint posX;\n";
		headerContent = headerContent + "\tint posY;\n";
		headerContent = headerContent + "\tint spriteWidth;\n";
		headerContent = headerContent + "\tint spriteHeight;\n";
		headerContent = headerContent + "\tint framerate;\n";
		headerContent = headerContent + "\tint spriteNb;\n";
		headerContent = headerContent + "\tbool animationLoop;\n";
		headerContent = headerContent + "public:\n";
		headerContent = headerContent + "\tAnimationData();\n";
		headerContent = headerContent + "\tAnimationData(string fileName, int animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop);\n";
		headerContent = headerContent + "\t~AnimationData(void);\n";
		headerContent = headerContent + "\tstring getFileName() const;\n";
		headerContent = headerContent + "\tint getAnimationName() const;\n";
		headerContent = headerContent + "\tint getPosX() const;\n";
		headerContent = headerContent + "\tint getPosY() const;\n";
		headerContent = headerContent + "\tint getSpriteWidth() const;\n";
		headerContent = headerContent + "\tint getSpriteHeight() const;\n";
		headerContent = headerContent + "\tint getFramerate() const;\n";
		headerContent = headerContent + "\tint getSpriteNb() const;\n";
		headerContent = headerContent + "\tbool getAnimationLoop() const;\n";
		headerContent = headerContent + "};\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "#define NUMBER_ANIMATIONDATA " + buffer + "\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "extern const AnimationData animationDataArray[NUMBER_ANIMATIONDATA];\n";
		headerContent = headerContent + "\n";
		

		// Define the animations' name
		position = 0;
		for(it = animArray.begin(); it != animArray.end(); ++it)
		{
			sprintf_s(buffer, "%d", position);
			headerContent = headerContent + "#define " + it->getAnimationName() + " " + buffer + "\n";
			++position;
		}

		headerContent = headerContent + "\n";
		headerContent = headerContent + "#endif _ANIMATIONDATA_H\n";

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
	cppOutputLocation = new char[strlen(outputLocation) + strlen("\\AnimationData.cpp") + 1];
	strcpy_s(cppOutputLocation,strlen(outputLocation)+1,outputLocation);
	strcat_s(cppOutputLocation,strlen(cppOutputLocation)+strlen("\\AnimationData.cpp")+1,"\\AnimationData.cpp");
	
	// Create and open the file
	cppFile.open(cppOutputLocation, ios::out|ios::trunc);

	if(cppFile)
	{
		cppContent = "#include \"AnimationData.h\"\n";
		cppContent = cppContent + "\n";

		cppContent = cppContent + "const AnimationData animationDataArray[NUMBER_ANIMATIONDATA] =\n";
		cppContent = cppContent + "{\n";

		// Put all the data into the animationArray in the cpp file
		for(it = animArray.begin(); it != animArray.end(); ++it)
		{
			// Put : fileName and animatioName
			cppContent = cppContent + "\tAnimationData(\"" + it->getFileName() + "\", " + it->getAnimationName() + ", ";

			// Put : posX
			sprintf_s(buffer, "%d", it->getPosX());
			cppContent = cppContent + buffer + ", ";

			// Put : posY
			sprintf_s(buffer, "%d", it->getPosY());
			cppContent = cppContent + buffer + ", ";
			
			// Put : spriteWidth
			sprintf_s(buffer, "%d", it->getSpriteWidth());
			cppContent = cppContent + buffer + ", ";
			
			// Put : spriteHeight
			sprintf_s(buffer, "%d", it->getSpriteHeight());
			cppContent = cppContent + buffer + ", ";

			// Put : framerate
			sprintf_s(buffer, "%d", it->getFramerate());
			cppContent = cppContent + buffer + ", ";

			// Put : spriteNb
			sprintf_s(buffer, "%d", it->getSpriteNb());
			cppContent = cppContent + buffer + ", ";

			// Put : animationLoop
			if (it->getAnimationLoop())
				cppContent = cppContent + "true";
			else
				cppContent = cppContent + "false";

			cppContent = cppContent + "),\n";
		}
		
		cppContent = cppContent + "};\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "AnimationData::AnimationData()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tthis->fileName = \"\";\n";
		cppContent = cppContent + "\tthis->animationName = 0;\n";
		cppContent = cppContent + "\tthis->posX = 0;\n";
		cppContent = cppContent + "\tthis->posY = 0;\n";
		cppContent = cppContent + "\tthis->spriteWidth = 0;\n";
		cppContent = cppContent + "\tthis->spriteHeight = 0;\n";
		cppContent = cppContent + "\tthis->framerate = 0;\n";
		cppContent = cppContent + "\tthis->spriteNb = 0;\n";
		cppContent = cppContent + "\tthis->animationLoop = false;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "AnimationData::AnimationData(string fileName, int animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop)\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tthis->fileName = fileName;\n";
		cppContent = cppContent + "\tthis->animationName = animationName;\n";
		cppContent = cppContent + "\tthis->posX = posX;\n";
		cppContent = cppContent + "\tthis->posY = posY;\n";
		cppContent = cppContent + "\tthis->spriteWidth = spriteWidth;\n";
		cppContent = cppContent + "\tthis->spriteHeight = spriteHeight;\n";
		cppContent = cppContent + "\tthis->framerate = framerate;\n";
		cppContent = cppContent + "\tthis->spriteNb = spriteNb;\n";
		cppContent = cppContent + "\tthis->animationLoop = animationLoop;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "AnimationData::~AnimationData(void)\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "string AnimationData::getFileName() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->fileName;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int AnimationData::getAnimationName() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->animationName;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int AnimationData::getPosX() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->posX;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int AnimationData::getPosY() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->posY;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int AnimationData::getSpriteWidth() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->spriteWidth;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int AnimationData::getSpriteHeight() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->spriteHeight;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int AnimationData::getFramerate() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->framerate;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int AnimationData::getSpriteNb() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->spriteNb;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "bool AnimationData::getAnimationLoop() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->animationLoop;\n";
		cppContent = cppContent + "}\n";
		
		cppFile << cppContent;
	}
	else
	{
		cout << "ERROR OP003 - Can't create the .cpp file." << endl;
		system("Pause");
		return 1;
	}

	cppFile.close();

	/*****************/
	/* Final message */
	/*****************/

	cout << endl << endl << "The following 2 files have been successfully generated :" << endl;
	cout << "	- AnimationData.h" << endl;
	cout << "	- AnimationData.cpp" << endl;
	cout << "into the folder :" << endl;
	cout << "	- " << outputLocation << endl << endl;

	system("Pause");
	return 0;
}

