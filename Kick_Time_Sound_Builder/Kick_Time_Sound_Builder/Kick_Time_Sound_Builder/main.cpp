#include "SoundLine.h"
#include "functions.h"

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
	char* soundLocation = new char[];
	char* outputLocation = new char[];
	char confirm = 'n';
	bool resetData = false;

	// Variables for files' creation
	char* headerOutputLocation = new char[];
	char* cppOutputLocation = new char[];

	// Variable to open/read/create/write files
	// Level file
	vector<SoundLine> listSounds;
	vector<SoundLine>::iterator it;
	ifstream soundFile;
	string currentLine;
	string delimiter = ";";
	vector<string> tempInformations;
	string fileName;
	string soundID;
	bool isMusic;
	bool isLoop;
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
			soundLocation = new char[strlen(argv[1])+1];
			strcpy_s(soundLocation, strlen(argv[1])+1, argv[1]);

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
				cout << "Set \"Sound file's location\" : ";
				cin >> soundLocation;
				cout << "Set \"Output class location\" : ";
				cin >> outputLocation;
				cout << endl << endl << endl;
			}
			cout << "Confirm : " << endl;
			cout << "Sound file's location : " << soundLocation << endl << endl;
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
			cout << "Set \"Sound file's location\" : ";
			cin >> soundLocation;
			cout << "Set \"Output class location\" : ";
			cin >> outputLocation;
			cout << endl << endl << endl;

			cout << "Confirm : " << endl;
			cout << "Sound file's location : " << soundLocation << endl << endl;
			cout << "Output class location : " << outputLocation << endl << endl;

			cout << "Confirm (y/n) : ";
			cin >> confirm;
			resetData = true;
		}
	}

	// Check the sound file
	// Check if it's a text file
	if(strcmp(subChar(soundLocation, findChar(soundLocation,'.',LAST), strlen(soundLocation)-1), ".txt") != 0)
	{
		cout << "Please select an sound file as a '.txt' file" << endl;
		system("Pause");
		return 1;
	}

	/************************/
	/* Read the sound files */
	/************************/
	
	// Open the sound file
	soundFile.open(soundLocation, ios::in);

	if(soundFile)
	{
		while(!soundFile.eof())
		{
			// Get the full current line
			getline(soundFile, currentLine);

			if(!currentLine.empty())
			{
				/****************************/
				/* Get the different values */
				/****************************/
				tempInformations = split(currentLine, delimiter);
				if (tempInformations.size() == 4)
				{
					fileName = tempInformations[0];
					soundID = tempInformations[1];
					// Get isMusic
					string tempIsMusic = tempInformations[2];
					transform(tempIsMusic.begin(), tempIsMusic.end(), tempIsMusic.begin(), ::tolower);
					if (strcmp(tempIsMusic.c_str(), "true") != 0 && strcmp(tempIsMusic.c_str(), "false") != 0)
					{
						cout << "ERROR GD002 - A problem occured while getting the music information value in this line:\n	" << currentLine << endl;
						system("Pause");
						return 1;
					}
					else
					{
						if (strcmp(tempIsMusic.c_str(), "true") == 0)
							isMusic = true;
						else
							isMusic = false;
					}
					// Get isLoop
					string tempIsLoop = tempInformations[3];
					transform(tempIsLoop.begin(), tempIsLoop.end(), tempIsLoop.begin(), ::tolower);
					if (strcmp(tempIsLoop.c_str(), "true") != 0 && strcmp(tempIsLoop.c_str(), "false") != 0)
					{
						cout << "ERROR GD003 - A problem occured while getting the loop sound value in this line:\n	" << currentLine << endl;
						system("Pause");
						return 1;
					}
					else
					{
						if (strcmp(tempIsLoop.c_str(), "true") == 0)
							isLoop = true;
						else
							isLoop = false;
					}

					listSounds.push_back(*new SoundLine(fileName, soundID, isMusic, isLoop));
				}
				else
				{
					cout << "ERROR GD001 - A problem occured while getting the informations of a sound in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}
			}
		}
	}
	else
	{
		cout << "ERROR OP001 - Can't open the sound file." << endl;
		system("Pause");
		return 1;
	}

	soundFile.close();

	/*********************/
	/* Set the '.h' file */
	/*********************/

	// Set the location of the file
	headerOutputLocation = new char[strlen(outputLocation) + strlen("\\SoundData.h") + 1];
	strcpy_s(headerOutputLocation,strlen(outputLocation)+1,outputLocation);
	strcat_s(headerOutputLocation,strlen(headerOutputLocation)+strlen("\\SoundData.h")+1,"\\SoundData.h");
	
	// Create and open the file
	headerFile.open(headerOutputLocation, ios::out|ios::trunc);

	if(headerFile)
	{
		sprintf_s(buffer, "%d", listSounds.size());
		headerContent = "#ifndef _SOUNDDATA_H\n";
		headerContent = headerContent + "#define _SOUNDDATA_H\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "#include <string>\n\n";
		headerContent = headerContent + "using namespace std;\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "class SoundData\n";
		headerContent = headerContent + "{\n";
		headerContent = headerContent + "private:\n";
		headerContent = headerContent + "\tstring fileName;\n";
		headerContent = headerContent + "\tint soundID;\n";
		headerContent = headerContent + "\tbool isMusic;\n";
		headerContent = headerContent + "\tbool isLoop;\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "public:\n";
		headerContent = headerContent + "\tSoundData();\n";
		headerContent = headerContent + "\tSoundData(string fileName, int soundID, bool isMusic, bool isLoop);\n";
		headerContent = headerContent + "\t~SoundData(void);\n";
		headerContent = headerContent + "\tstring getFileName() const;\n";
		headerContent = headerContent + "\tint getSoundID() const;\n";
		headerContent = headerContent + "\tbool getIsMusic() const;\n";
		headerContent = headerContent + "\tbool getIsLoop() const;\n";
		headerContent = headerContent + "};\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "#define NUMBER_SOUNDDATA " + buffer + "\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "extern const SoundData soundDataArray[NUMBER_SOUNDDATA];\n";
		headerContent = headerContent + "\n";
		

		// Define the sounds' name
		position = 0;
		for(it = listSounds.begin(); it != listSounds.end(); ++it)
		{
			sprintf_s(buffer, "%d", position);
			headerContent = headerContent + "#define " + it->getSoundID() + " " + buffer + "\n";
			++position;
		}

		headerContent = headerContent + "\n";
		headerContent = headerContent + "#endif _SOUNDDATA_H\n";

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
	cppOutputLocation = new char[strlen(outputLocation) + strlen("\\SoundData.cpp") + 1];
	strcpy_s(cppOutputLocation,strlen(outputLocation)+1,outputLocation);
	strcat_s(cppOutputLocation,strlen(cppOutputLocation)+strlen("\\SoundData.cpp")+1,"\\SoundData.cpp");
	
	// Create and open the file
	cppFile.open(cppOutputLocation, ios::out|ios::trunc);

	if(cppFile)
	{
		cppContent = "#include \"SoundData.h\"\n";
		cppContent = cppContent + "\n";

		cppContent = cppContent + "const SoundData soundDataArray[NUMBER_SOUNDDATA] =\n";
		cppContent = cppContent + "{\n";

		// Put all the data into the animationArray in the cpp file
		for(it = listSounds.begin(); it != listSounds.end(); it++)
		{
			// Put : SoundData
			cppContent = cppContent + "\tSoundData(\"" + it->getFileName() + "\", " + it->getSoundID() + ", ";

			// Put : isMusic
			if (it->getIsMusic())
				cppContent = cppContent + "true, ";
			else
				cppContent = cppContent + "false, ";

			// Put : isLoop
			if (it->getIsLoop())
				cppContent = cppContent + "true";
			else
				cppContent = cppContent + "false";

			cppContent = cppContent + "),\n";
		}
		
		cppContent = cppContent + "};\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "SoundData::SoundData()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tthis->fileName = \"\";\n";
		cppContent = cppContent + "\tthis->soundID = 0;\n";
		cppContent = cppContent + "\tthis->isMusic = false;\n";
		cppContent = cppContent + "\tthis->isLoop = false;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "SoundData::SoundData(string fileName, int soundID, bool isMusic, bool isLoop)\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tthis->fileName = fileName;\n";
		cppContent = cppContent + "\tthis->soundID = soundID;\n";
		cppContent = cppContent + "\tthis->isMusic = isMusic;\n";
		cppContent = cppContent + "\tthis->isLoop = isLoop;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "SoundData::~SoundData(void)\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "string SoundData::getFileName() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->fileName;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int SoundData::getSoundID() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->soundID;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "bool SoundData::getIsMusic() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->isMusic;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "bool SoundData::getIsLoop() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->isLoop;\n";
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
	cout << "	- SoundData.h" << endl;
	cout << "	- SoundData.cpp" << endl;
	cout << "into the folder :" << endl;
	cout << "	- " << outputLocation << endl << endl;

	system("Pause");
	return 0;
}