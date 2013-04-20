#include "LevelLine.h"
#include "functions.h"

#include <iostream>
#include <list>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, const char * argv[])
{
	// Variables to get/set data for locations
	char* levelLocation = new char[1024];
	char* outputLocation = new char[1024];
	char confirm = 'n';
	bool resetData = false;

	// Variables for files' creation
	char* headerOutputLocation = new char[];
	char* cppOutputLocation = new char[];

	// Variable to open/read/create/write files
	// Level file
	list<LevelLine> listLevel;
	ifstream levelFile;
	string currentLine;
	int posDelimStart = -1;
	int posDelimEnd = 0;
	char* fileName = new char[];
	char* levelName = new char[];
	char* levelID = new char[];
	int posX;
	int posY;
	// Header file
	ofstream headerFile;
	ostringstream levelData;
	string headerContent;
	int position;
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
			strcpy_s(levelLocation,strlen(argv[1])+1,argv[1]);
			strcpy_s(outputLocation,strlen(argv[2])+1,argv[2]);
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

	// Check the animation file
	// Check if it's a text file
	if(strcmp(subChar(levelLocation,findChar(levelLocation,'.',LAST),4),".txt") != 0){
		cout << "Please select an level file as a '.txt' file" << endl;
		system("Pause");
		return 1;
	}

	/************************/
	/* Read the level files */
	/************************/
	
	// Open the level file
	levelFile.open(levelLocation, ios::in);

	if(levelFile)
	{
		while(!levelFile.eof())
		{
			// Get the full current line
			getline(levelFile, currentLine);

			if(!currentLine.empty())
			{
				posDelimStart = -1;

				/****************************/
				/* Get the different values */
				/****************************/

				// Get fileName
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1)
				{
					cout << "ERROR GD001 - A problem occured while getting the file's name in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				fileName = mySubStringToChar(currentLine,posDelimStart,posDelimEnd-1);
				if(fileName == "")
				{
					cout << "ERROR GD002 - A problem occured while getting the file's name in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get levelID
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1)
				{
					cout << "ERROR GD003 - A problem occured while getting the level's id in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				levelID = mySubStringToChar(currentLine,posDelimStart,posDelimEnd-1);
				if(levelID == "")
				{
					cout << "ERROR GD004 - A problem occured while getting the level's id in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get levelName
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1)
				{
					cout << "ERROR GD003 - A problem occured while getting the level's name in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				levelName = mySubStringToChar(currentLine,posDelimStart,posDelimEnd-1);
				if(levelName == "")
				{
					cout << "ERROR GD004 - A problem occured while getting the level's name in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get posX
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1)
				{
					cout << "ERROR GD005 - A problem occured while getting the X position in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				posX = myAtoi(mySubStringToChar(currentLine,posDelimStart,posDelimEnd));
				if(posX == -1)
				{
					cout << "ERROR GD006 - A problem occured while getting the X position in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get posY
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1)
				{
					cout << "ERROR GD007 - A problem occured while getting the Y position in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				posY = myAtoi(mySubStringToChar(currentLine,posDelimStart,posDelimEnd));
				if(posY == -1)
				{
					cout << "ERROR GD008 - A problem occured while getting the Y position in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				listLevel.push_back(LevelLine(fileName, levelID, levelName, posX, posY));
			}
		}
	}
	else
	{
		cout << "ERROR OP001 - Can't open the level file." << endl;
	}

	levelFile.close();

	/*********************/
	/* Set the '.h' file */
	/*********************/

	// Set the location of the file
	headerOutputLocation = new char[strlen(outputLocation) + strlen("\\LevelData.h") + 1];
	strcpy_s(headerOutputLocation,strlen(outputLocation)+1,outputLocation);
	strcat_s(headerOutputLocation,strlen(headerOutputLocation)+strlen("\\LevelData.h")+1,"\\LevelData.h");
	
	// Create and open the file
	headerFile.open(headerOutputLocation, ios::out|ios::trunc);
	levelData << listLevel.size();

	if(headerFile)
	{
		headerContent = "#ifndef __LEVELDATA__\n";
		headerContent = headerContent + "#define __LEVELDATA__\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "class LevelData{\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "private:\n";
		headerContent = headerContent + "	char* fileName;\n";
		headerContent = headerContent + "	char* levelID;\n";
		headerContent = headerContent + "	char* levelName;\n";
		headerContent = headerContent + "	int posX;\n";
		headerContent = headerContent + "	int posY;\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "public:\n";
		headerContent = headerContent + "	LevelData();\n";
		headerContent = headerContent + "	LevelData(char* fileName, char* levelID, char* levelName, int posX, int posY);\n";
		headerContent = headerContent + "	char* getFileName();\n";
		headerContent = headerContent + "	char* getLevelID();\n";
		headerContent = headerContent + "	char* getLevelName();\n";
		headerContent = headerContent + "	int getPosX();\n";
		headerContent = headerContent + "	int getPosY();\n";
		headerContent = headerContent + "	~LevelData(void);\n";
		headerContent = headerContent + "};\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "#define NUMBER_LEVELDATA " + levelData.str() + "\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "extend const LevelData levelDataArray[NUMBER_LEVELDATA];\n";
		headerContent = headerContent + "\n";
		

		// Go to the beginning of the list
		std::list<LevelLine>::iterator it = listLevel.begin();

		// Define the animations' name
		for(position = 0; position < listLevel.size(); position++)
		{
			std::advance(it, position);
			levelData.str("");
			levelData << it->getLevelID();
			headerContent = headerContent + "#define " + levelData.str() + " ";
			levelData.str("");
			levelData << position;
			headerContent = headerContent + levelData.str() + "\n";
		}

		headerContent = headerContent + "\n";
		headerContent = headerContent + "#endif __LEVELDATA__\n";

		headerFile << headerContent;
	}
	else
	{
		cout << "ERROR OP002 - Can't create the header file." << endl;
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
		levelData.str("");
		levelData << "LevelData";

		cppContent = "#include \"" + levelData.str() + ".h\"\n";
		cppContent = cppContent + "\n";

		levelData.str("");
		levelData << listLevel.size();
		cppContent = cppContent + "const LevelData levelDataArray[NUMBER_LEVELDATA] =\n";
		cppContent = cppContent + "{\n";

		// Go to the beginning of the list
		std::list<LevelLine>::iterator it = listLevel.begin();

		// Put all the data into the animationArray in the cpp file
		for(position = 0; position < listLevel.size(); position++)
		{
			std::advance(it, position);

			cppContent = cppContent + "	{\n";
			
			// Put : fileName
			levelData.str("");
			levelData << it->getFileName();
			cppContent = cppContent + "		\"" + levelData.str() + "\",\n";

			// Put : levelID
			levelData.str("");
			levelData << it->getLevelID();
			cppContent = cppContent + "		" + levelData.str() + ",\n";

			// Put : levelName
			levelData.str("");
			levelData << it->getLevelName();
			cppContent = cppContent + "		" + levelData.str() + ",\n";

			// Put : posX
			levelData.str("");
			levelData << it->getPosX();
			cppContent = cppContent + "		" + levelData.str() + ",\n";

			// Put : posY
			levelData.str("");
			levelData << it->getPosY();
			cppContent = cppContent + "		" + levelData.str() + ",\n";
			
			cppContent = cppContent + "	}";

			if(listLevel.size() > 1)
			{
				if(position != listLevel.size()-1)
					cppContent = cppContent + ",";
			}

			cppContent = cppContent + "\n";
		}
		
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "LevelData::LevelData()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tthis->fileName = \"\";\n";
		cppContent = cppContent + "\tthis->levelID = \"\";\n";
		cppContent = cppContent + "\tthis->levelName = \"\";\n";
		cppContent = cppContent + "\tthis->posX = 0;\n";
		cppContent = cppContent + "\tthis->posY = 0;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "LevelData::LevelData(char* fileName, char* levelID, char* levelName, int posX, int posY)\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tthis->fileName = new char[strlen(fileName)+1];\n";
		cppContent = cppContent + "\tstrcpy_s(this->fileName,strlen(fileName)+1, fileName);\n\n";
		cppContent = cppContent + "\tthis->levelID = new char[strlen(levelID)+1];\n";
		cppContent = cppContent + "\tstrcpy_s(this->levelID,strlen(levelID)+1, levelID);\n";
		cppContent = cppContent + "\tthis->levelName = new char[strlen(levelName)+1];\n";
		cppContent = cppContent + "\tstrcpy_s(this->levelName,strlen(levelName)+1, levelName);\n";
		cppContent = cppContent + "\tthis->posX = posX;\n";
		cppContent = cppContent + "\tthis->posY = posY;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "char* LevelData::getFileName()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->fileName;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "char* LevelData::getLevelID()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->levelID;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "char* LevelData::getLevelName()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->levelName;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int LevelData::getPosX()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->posX;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int LevelData::getPosY()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->posY;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "LevelData::~LevelData(void)\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tdelete[] this->fileName;\n";
		cppContent = cppContent + "\tdelete[] this->levelID;\n";
		cppContent = cppContent + "\tdelete[] this->levelName;\n";
		cppContent = cppContent + "}\n";
		
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
	cout << "	- LevelData.h" << endl;
	cout << "	- LevelData.cpp" << endl;
	cout << "into the folder :" << endl;
	cout << "	- " << outputLocation << endl << endl;

	system("Pause");
	return 0;
}