#include <iostream>
#include "functions.h"
#include <fstream>
#include <list>
#include "AnimationLine.h"
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc,const char * argv[]){

	// Variables to get/set data for locations
	char* animLocation = new char[1024];
	char* outputLocation = new char[1024];
	char* className = new char[1024];
	char confirm = 'n';
	bool resetData = false;

	// Variables for files' creation
	char* headerOutputLocation = new char[];
	char* cppOutputLocation = new char[];

	// Variable to open/read/create/write files
	// Animation file
	list <AnimationLine> animArray;
	ifstream animFile;
	string currentLine;
	int posDelimStart = -1;
	int posDelimEnd = 0;
	char* fileName = new char[];
	char* animationName = new char[];
	int posX;
	int posY;
	int spriteWidth;
	int spriteHeight;
	int framerate;
	int spriteNb;
	//char* animationLoop = new char[];
	char* animationLoopStr = new char[];
	// Header file
	ofstream headerFile;
	ostringstream animationData;
	string headerContent;
	int position;
	// CPP file
	ofstream cppFile;
	string cppContent;

	/*****************************/
	/* Get and set the locations */
	/*****************************/

	// Get the info from the arguments if there is any set
	if(argc > 1){
		if(argc == 4){
			// Put the arguments into the variables
			strcpy_s(animLocation,strlen(argv[1])+1,argv[1]);
			strcpy_s(outputLocation,strlen(argv[2])+1,argv[2]);
			strcpy_s(className,strlen(argv[3])+1,argv[3]);

			
		}
		else{
			// Error message - Not enough argument
			cout << "Not enough argument provided!\nPlease check your settings." << endl;
			system("Pause");
			return 1;
		}

		// We ask the user if the data are ok
		while(confirm != 'y'){

			// If the user pressed 'n', then he can reset the data as he wishes
			if(resetData){

				cout << "Set \"animation file's location\" : ";
				cin >> animLocation;
				cout << "Set \"Output class location\" : ";
				cin >> outputLocation;
				cout << "Set \"Class name\" : ";
				cin >> className;
				cout << endl << endl << endl;
			}
			cout << "Confirm : " << endl;
			cout << "Animation file's location : " << animLocation << endl << endl;
			cout << "Output class location : " << outputLocation << endl << endl;
			cout << "Class name : " << className << endl << endl << endl;

			cout << "Confirm (y/n) : ";
			cin >> confirm;
			resetData = true;
		}

	}
	// No argument set, so the user has to define them
	else{

		while(confirm != 'y'){

			cout << "Set \"animation file's location\" : ";
			cin >> animLocation;
			cout << "Set \"Output class location\" : ";
			cin >> outputLocation;
			cout << "Set \"Class name\" : ";
			cin >> className;
			cout << endl << endl << endl;

			cout << "Confirm : " << endl;
			cout << "Animation file's location : " << animLocation << endl << endl;
			cout << "Output class location : " << outputLocation << endl << endl;
			cout << "Class name : " << className << endl << endl << endl;

			cout << "Confirm (y/n) : ";
			cin >> confirm;
			resetData = true;
		}
	}

	// Check the animation file
	// Check if it's a text file
	if(strcmp(subChar(animLocation,findChar(animLocation,'.',LAST),4),".txt") != 0){
		cout << "Please select an animation file as a '.txt' file" << endl;
		system("Pause");
		return 1;
	}

	/***************************/
	/* Read the animation file */
	/***************************/

	// Open the animation file
	animFile.open(animLocation,ios::in);

	if(animFile){
		while(!animFile.eof()){
			// Get the full current line
			getline(animFile,currentLine);

			if(!currentLine.empty()){
				posDelimStart = -1;

				/****************************/
				/* Get the different values */
				/****************************/

				// Get fileName
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1){
					cout << "ERROR GD001 - A problem occured while getting the file's name in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				fileName = mySubStringToChar(currentLine,posDelimStart,posDelimEnd-1);
				if(fileName == ""){
					cout << "ERROR GD002 - A problem occured while getting the file's name in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get animationName
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1){
					cout << "ERROR GD003 - A problem occured while getting the animation's name in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				animationName = mySubStringToChar(currentLine,posDelimStart,posDelimEnd-1);
				if(animationName == ""){
					cout << "ERROR GD004 - A problem occured while getting the animation's name in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get posX
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1){
					cout << "ERROR GD005 - A problem occured while getting the X position in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				posX = myAtoi(mySubStringToChar(currentLine,posDelimStart,posDelimEnd));
				if(posX == -1){
					cout << "ERROR GD006 - A problem occured while getting the X position in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get posY
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1){
					cout << "ERROR GD007 - A problem occured while getting the Y position in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				posY = myAtoi(mySubStringToChar(currentLine,posDelimStart,posDelimEnd));
				if(posY == -1){
					cout << "ERROR GD008 - A problem occured while getting the Y position in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get spriteWidth
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1){
					cout << "ERROR GD009 - A problem occured while getting the sprite's width in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				spriteWidth = myAtoi(mySubStringToChar(currentLine,posDelimStart,posDelimEnd));
				if(spriteWidth == -1){
					cout << "ERROR GD010 - A problem occured while getting the sprite's width in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get spriteHeight
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1){
					cout << "ERROR GD011 - A problem occured while getting the sprite's height in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				spriteHeight = myAtoi(mySubStringToChar(currentLine,posDelimStart,posDelimEnd));
				if(spriteHeight == -1){
					cout << "ERROR GD012 - A problem occured while getting the sprite's height in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get framerate
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1){
					cout << "ERROR GD013 - A problem occured while getting the framerate in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				framerate = myAtoi(mySubStringToChar(currentLine,posDelimStart,posDelimEnd));
				if(framerate == -1){
					cout << "ERROR GD014 - A problem occured while getting the framerate in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get spriteNb
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1){
					cout << "ERROR GD015 - A problem occured while getting the number of sprites in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				spriteNb = myAtoi(mySubStringToChar(currentLine,posDelimStart,posDelimEnd));
				if(spriteNb == -1){
					cout << "ERROR GD016 - A problem occured while getting the number of sprites in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get animationLoop
				posDelimStart = posDelimEnd;

				posDelimStart++;

				transform(currentLine.begin(),currentLine.end(),currentLine.begin(),::tolower);
				animationLoopStr = mySubStringToChar(currentLine,posDelimStart,currentLine.at(currentLine.length()-1));			
				if((strcmp(animationLoopStr,"true") != 0) && (strcmp(animationLoopStr,"false") != 0)){
					cout << "ERROR GD017 - A problem occured while getting the loop animation value in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				/*cout << "fileName : " << fileName << endl << "animationName : " << animationName << endl << "posX : " << posX << endl << "posY : " << posY << endl;
				cout << "spriteWidth : " << spriteWidth << endl << "spriteHeight : " << spriteHeight << endl << "framerate : " << framerate << endl;
				cout << "spriteNb : " << spriteNb << endl << "animationLoop : " << animationLoop << endl;*/
			
				animArray.push_back(*new AnimationLine(fileName,animationName,posX,posY,spriteWidth,spriteHeight,framerate,spriteNb,animationLoopStr));
			}
		}
	}
	else{
		cout << "ERROR OP001 - Can't open the animation file." << endl;
	}

	animFile.close();

	/*********************/
	/* Set the '.h' file */
	/*********************/

	// Set the location of the file
	headerOutputLocation = new char[strlen(outputLocation) + 2 + strlen(className) + 3];
	strcpy_s(headerOutputLocation,strlen(outputLocation)+1,outputLocation);
	strcat_s(headerOutputLocation,strlen(headerOutputLocation)+2,"\\");
	strcat_s(headerOutputLocation,strlen(headerOutputLocation)+strlen(className)+1,className);
	strcat_s(headerOutputLocation,strlen(headerOutputLocation)+3,".h");
	
	// Create and open the file
	headerFile.open(headerOutputLocation, ios::out|ios::trunc);
	animationData << animArray.size();

	if(headerFile){
		headerContent = "#ifndef __ANIMATION__\n";
		headerContent = headerContent + "#define __ANIMATION__\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "#include <iostream>\n";
		headerContent = headerContent + "using namespace std;\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "class Animation{\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "private:\n";
		headerContent = headerContent + "	char* fileName;\n";
		headerContent = headerContent + "	char* animationName;\n";
		headerContent = headerContent + "	int posX;\n";
		headerContent = headerContent + "	int posY;\n";
		headerContent = headerContent + "	int spriteWidth;\n";
		headerContent = headerContent + "	int spriteHeight;\n";
		headerContent = headerContent + "	int framerate;\n";
		headerContent = headerContent + "	int spriteNb;\n";
		headerContent = headerContent + "	bool animationLoop;\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "public:\n";
		headerContent = headerContent + "	AnimationLine::AnimationLine();\n";
		headerContent = headerContent + "	Animation(char* fileName, char* animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop);\n";
		headerContent = headerContent + "	char* getFileName();\n";
		headerContent = headerContent + "	char* getAnimationName();\n";
		headerContent = headerContent + "	int getPosX();\n";
		headerContent = headerContent + "	int getPosY();\n";
		headerContent = headerContent + "	int getSpriteWidth();\n";
		headerContent = headerContent + "	int getSpriteHeight();\n";
		headerContent = headerContent + "	int getFramerate();\n";
		headerContent = headerContent + "	int getSpriteNb();\n";
		headerContent = headerContent + "	bool getAnimationLoop();\n";
		headerContent = headerContent + "	~AnimationLine(void);\n";
		headerContent = headerContent + "};\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "#define NUMBER_ANIMATION " + animationData.str() + "\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "extend const Animation animationArray[NUMBER_ANIMATION];\n";
		headerContent = headerContent + "\n";
		

		// Go to the beginning of the list
		std::list<AnimationLine>::iterator it = animArray.begin();

		// Define the animations' name
		for(position = 0; position < animArray.size(); position++){
			std::advance(it, position);
			animationData.str("");
			animationData << it->getAnimationName();
			headerContent = headerContent + "#define " + animationData.str() + " ";
			animationData.str("");
			animationData << position;
			headerContent = headerContent + animationData.str() + "\n";
		}

		headerContent = headerContent + "\n";
		headerContent = headerContent + "#endif __ANIMATION__\n";

		headerFile << headerContent;
	}
	else{
		cout << "ERROR OP002 - Can't create the header file." << endl;
	}

	headerFile.close();

	/***********************/
	/* Set the '.cpp' file */
	/***********************/

	// Set the location of the file
	cppOutputLocation = new char[strlen(outputLocation) + 2 + strlen(className) + 5];
	strcpy_s(cppOutputLocation,strlen(outputLocation)+1,outputLocation);
	strcat_s(cppOutputLocation,strlen(cppOutputLocation)+2,"\\");
	strcat_s(cppOutputLocation,strlen(cppOutputLocation)+strlen(className)+1,className);
	strcat_s(cppOutputLocation,strlen(cppOutputLocation)+5,".cpp");
	
	// Create and open the file
	cppFile.open(cppOutputLocation, ios::out|ios::trunc);

	if(cppFile){

		animationData.str("");
		animationData << className;

		cppContent = "#include \"" + animationData.str() + ".h\"\n";
		cppContent = cppContent + "\n";

		animationData.str("");
		animationData << animArray.size();
		cppContent = cppContent + "const Animation animationArray[NUMBER_ANIMATION] =\n";
		cppContent =cppContent + "{\n";

		// Go to the beginning of the list
		std::list<AnimationLine>::iterator it = animArray.begin();

		// Put all the data into the animationArray in the cpp file
		for(position = 0; position < animArray.size(); position++){
			std::advance(it, position);

			cppContent =cppContent + "	{\n";
			
			// Put : fileName
			animationData.str("");
			animationData << it->getFileName();
			cppContent = cppContent + "		\"" + animationData.str() + "\",\n";

			// Put : animatioName
			animationData.str("");
			animationData << it->getAnimationName();
			cppContent = cppContent + "		" + animationData.str() + ",\n";

			// Put : posX
			animationData.str("");
			animationData << it->getPosX();
			cppContent = cppContent + "		" + animationData.str() + ",\n";

			// Put : posY
			animationData.str("");
			animationData << it->getPosY();
			cppContent = cppContent + "		" + animationData.str() + ",\n";
			
			// Put : spriteWidth
			animationData.str("");
			animationData << it->getSpriteWidth();
			cppContent = cppContent + "		" + animationData.str() + ",\n";
			
			// Put : spriteHeight
			animationData.str("");
			animationData << it->getSpriteHeight();
			cppContent = cppContent + "		" + animationData.str() + ",\n";

			// Put : framerate
			animationData.str("");
			animationData << it->getFramerate();
			cppContent = cppContent + "		" + animationData.str() + ",\n";

			// Put : spriteNb
			animationData.str("");
			animationData << it->getSpriteNb();
			cppContent = cppContent + "		" + animationData.str() + ",\n";

			// Put : animationLoop
			animationData.str("");
			animationData << it->getAnimationLoop();
			cppContent = cppContent + "		" + animationData.str() + "\n";

			cppContent =cppContent + "	}";

			if(animArray.size() > 1){
				if(position != animArray.size()-1)
					cppContent =cppContent + ",";
			}

			cppContent =cppContent + "\n";
		}
		
		cppContent =cppContent + "}\n";
		cppContent =cppContent + "\n";
		cppContent =cppContent + "AnimationLine::AnimationLine(){\n";
		cppContent =cppContent + "	this->fileName = \"\";\n";
		cppContent =cppContent + "	this->animationName = \"\";\n";
		cppContent =cppContent + "	this->posX = 0;\n";
		cppContent =cppContent + "	this->posY = 0;\n";
		cppContent =cppContent + "	this->spriteWidth = 0;\n";
		cppContent =cppContent + "	this->spriteHeight = 0;\n";
		cppContent =cppContent + "	this->framerate = 0;\n";
		cppContent =cppContent + "	this->spriteNb = 0;\n";
		cppContent =cppContent + "	this->animationLoop = \"\";\n";
		cppContent =cppContent + "}\n";
		cppContent =cppContent + "\n";
		cppContent =cppContent + "AnimationLine::AnimationLine(char* fileName, char* animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, char* animationLoop){\n";
		cppContent =cppContent + "	this->fileName = new char[strlen(fileName)+1];\n";
		cppContent =cppContent + "	strcpy_s(this->fileName,strlen(fileName)+1, fileName);\n\n";
		cppContent =cppContent + "	this->animationName = new char[strlen(animationName)+1];\n";
		cppContent =cppContent + "	strcpy_s(this->animationName,strlen(animationName)+1, animationName);\n";
		cppContent =cppContent + "	this->posX = posX;\n";
		cppContent =cppContent + "	this->posY = posY;\n";
		cppContent =cppContent + "	this->spriteWidth = spriteWidth;\n";
		cppContent =cppContent + "	this->spriteHeight = spriteHeight;\n";
		cppContent =cppContent + "	this->framerate = framerate;\n";
		cppContent =cppContent + "	this->spriteNb = spriteNb;\n\n";
		cppContent =cppContent + "	this->animationLoop = new char[strlen(animationLoop)+1];\n";
		cppContent =cppContent + "	strcpy_s(this->animationLoop,strlen(animationLoop)+1, animationLoop);\n";
		cppContent =cppContent + "}\n";
		cppContent =cppContent + "\n";
		cppContent =cppContent + "char* Animation::getFileName(){\n";
		cppContent =cppContent + "	return fileName;\n";
		cppContent =cppContent + "}\n";
		cppContent =cppContent + "\n";
		cppContent =cppContent + "char* Animation::getAnimationName(){\n";
		cppContent =cppContent + "	return animationName;\n";
		cppContent =cppContent + "}\n";
		cppContent =cppContent + "\n";
		cppContent =cppContent + "int Animation::getPosX(){\n";
		cppContent =cppContent + "	return posX;\n";
		cppContent =cppContent + "}\n";
		cppContent =cppContent + "\n";
		cppContent =cppContent + "int Animation::getPosY(){\n";
		cppContent =cppContent + "	return posY;\n";
		cppContent =cppContent + "}\n";
		cppContent =cppContent + "\n";
		cppContent =cppContent + "int Animation::getSpriteWidth(){\n";
		cppContent =cppContent + "	return spriteWidth;\n";
		cppContent =cppContent + "}\n";
		cppContent =cppContent + "\n";
		cppContent =cppContent + "int Animation::getSpriteHeight(){\n";
		cppContent =cppContent + "	return spriteHeight;\n";
		cppContent =cppContent + "}\n";
		cppContent =cppContent + "\n";
		cppContent =cppContent + "int Animation::getFramerate(){\n";
		cppContent =cppContent + "	return framerate;\n";
		cppContent =cppContent + "}\n";
		cppContent =cppContent + "\n";
		cppContent =cppContent + "int Animation::getSpriteNb(){\n";
		cppContent =cppContent + "	return spriteNb;\n";
		cppContent =cppContent + "}\n";
		cppContent =cppContent + "\n";
		cppContent =cppContent + "bool Animation::getAnimationLoop(){\n";
		cppContent =cppContent + "	return animationLoop;\n";
		cppContent =cppContent + "}\n";
		cppContent =cppContent + "AnimationLine::~AnimationLine(void){\n";
		cppContent =cppContent + "	delete[] this->fileName;\n";
		cppContent =cppContent + "	delete[] this->animationName;\n";
		cppContent =cppContent + "	delete[] this->animationLoop;\n";
		cppContent =cppContent + "}\n";
		
		cppFile << cppContent;
	}
	else{
		cout << "ERROR OP003 - Can't create the .cpp file." << endl;
	}

	cppFile.close();

	/*****************/
	/* Final message */
	/*****************/

	cout << endl << endl << "The following 2 files have been successfully generated :" << endl;
	cout << "	- " << className << ".h" << endl;
	cout << "	- " << className << ".cpp" << endl;
	cout << "into the folder :" << endl;
	cout << "	- " << outputLocation << endl << endl;

	system("Pause");
	return 0;
}