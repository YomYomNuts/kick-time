#include "functions.h"
#include "CharacterLine.h"

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
	char* characterLocation = new char[];
	char* outputLocation = new char[];
	char confirm = 'n';
	bool resetData = false;

	// Variables for files' creation
	char* headerOutputLocation = new char[];
	char* cppOutputLocation = new char[];

	// Variable to open/read/create/write files
	// Character file
	vector<char*> characterFilesList;
	vector<CharacterLine> characterArray;
	vector<CharacterLine>::iterator it;
	ifstream characterFile;
	string currentLine;
	string delimiter = ":";
	vector<string> tempInformations;
	string animationName;
	string name;
	string pathAvatar;
	int totalHP;
	int damageKick;
	int damageKickCrouch;
	int damageKickJumped;
	int damagePunch;
	int damagePunchCrouch;
	int damagePunchJumped;
	int speedKick;
	int speedKickCrouch;
	int speedKickJumped;
	int speedPunch;
	int speedPunchCrouch;
	int speedPunchJumped;
	string soundKick;
	string soundPunch;
	string soundJump;
	string soundHit;
	string soundGuard;
	string soundVictory;
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
			characterLocation = new char[strlen(argv[1])+1];
			strcpy_s(characterLocation, strlen(argv[1])+1, argv[1]);
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
				cout << "Set \"character file's location\" : ";
				cin >> characterLocation;
				cout << "Set \"Output class location\" : ";
				cin >> outputLocation;
				cout << endl << endl << endl;
			}
			cout << "Confirm : " << endl;
			cout << "Character file's location : " << characterLocation << endl << endl;
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
			cout << "Set \"character file's location\" : ";
			cin >> characterLocation;
			cout << "Set \"Output class location\" : ";
			cin >> outputLocation;
			cout << endl << endl << endl;

			cout << "Confirm : " << endl;
			cout << "Character file's location : " << characterLocation << endl << endl;
			cout << "Output class location : " << outputLocation << endl << endl;

			cout << "Confirm (y/n) : ";
			cin >> confirm;
			resetData = true;
		}
	}

	/**********************************************************/
	/* Get the location and the name of the character's files */
	/**********************************************************/

	getFilesLocation(characterLocation, characterFilesList, "character.txt");
	
	// Check if at least one file has been found
	if(characterFilesList.size() == 0){
		system("Pause");
		return 1;
	}
	
	/***************************/
	/* Read the character file */
	/***************************/

	// Go to the beginning of the list
	vector<char*>::iterator iteratorFile;
	
	for(iteratorFile = characterFilesList.begin(); iteratorFile != characterFilesList.end(); iteratorFile++)
	{
		// Open the character file
		characterFile.open(*iteratorFile,ios::in);

		if(characterFile)
		{
			while(!characterFile.eof())
			{
				// Get the full current line
				getline(characterFile, currentLine);

				if(!currentLine.empty())
				{
					/****************************/
					/* Get the different values */
					/****************************/
					tempInformations = split(currentLine, delimiter);
					if (tempInformations.size() == 2)
					{
						std::transform(tempInformations[0].begin(), tempInformations[0].end(), tempInformations[0].begin(), ::toupper);
						if (tempInformations[0] == "ANIMATIONNAME")
						{
							animationName = tempInformations[1];
						}
						else if (tempInformations[0] == "NAME")
						{
							name = tempInformations[1];
						}
						else if (tempInformations[0] == "PATHAVATAR")
						{
							pathAvatar = tempInformations[1];
						}
						else if (tempInformations[0] == "TOTALHP")
						{
							totalHP = 0;
							if (isNumeric(tempInformations[1].c_str(), 10))
								totalHP = strtol(tempInformations[1].c_str(), NULL, 10);
							else
							{
								cout << "ERROR GD002 -A problem occured while getting the total hp in this line:\n	" << currentLine << endl;
								system("Pause");
								return 1;
							}
						}
						else if (tempInformations[0] == "DAMAGEKICK")
						{
							damageKick = 0;
							if (isNumeric(tempInformations[1].c_str(), 10))
								damageKick = strtol(tempInformations[1].c_str(), NULL, 10);
							else
							{
								cout << "ERROR GD002 -A problem occured while getting the damage kick in this line:\n	" << currentLine << endl;
								system("Pause");
								return 1;
							}
						}
						else if (tempInformations[0] == "DAMAGEKICKCROUCH")
						{
							damageKickCrouch = 0;
							if (isNumeric(tempInformations[1].c_str(), 10))
								damageKickCrouch = strtol(tempInformations[1].c_str(), NULL, 10);
							else
							{
								cout << "ERROR GD002 -A problem occured while getting the damage kick crouch in this line:\n	" << currentLine << endl;
								system("Pause");
								return 1;
							}
						}
						else if (tempInformations[0] == "DAMAGEKICKJUMPED")
						{
							damageKickJumped = 0;
							if (isNumeric(tempInformations[1].c_str(), 10))
								damageKickJumped = strtol(tempInformations[1].c_str(), NULL, 10);
							else
							{
								cout << "ERROR GD002 -A problem occured while getting the damage kick jumped in this line:\n	" << currentLine << endl;
								system("Pause");
								return 1;
							}
						}
						else if (tempInformations[0] == "DAMAGEPUNCH")
						{
							damagePunch = 0;
							if (isNumeric(tempInformations[1].c_str(), 10))
								damagePunch = strtol(tempInformations[1].c_str(), NULL, 10);
							else
							{
								cout << "ERROR GD002 -A problem occured while getting the damage punch in this line:\n	" << currentLine << endl;
								system("Pause");
								return 1;
							}
						}
						else if (tempInformations[0] == "DAMAGEPUNCHCROUCH")
						{
							damagePunchCrouch = 0;
							if (isNumeric(tempInformations[1].c_str(), 10))
								damagePunchCrouch = strtol(tempInformations[1].c_str(), NULL, 10);
							else
							{
								cout << "ERROR GD002 -A problem occured while getting the damage punch crouch in this line:\n	" << currentLine << endl;
								system("Pause");
								return 1;
							}
						}
						else if (tempInformations[0] == "DAMAGEPUNCHJUMPED")
						{
							damagePunchJumped = 0;
							if (isNumeric(tempInformations[1].c_str(), 10))
								damagePunchJumped = strtol(tempInformations[1].c_str(), NULL, 10);
							else
							{
								cout << "ERROR GD002 -A problem occured while getting the damage punch jumped in this line:\n	" << currentLine << endl;
								system("Pause");
								return 1;
							}
						}
						else if (tempInformations[0] == "SPEEDKICK")
						{
							speedKick = 0;
							if (isNumeric(tempInformations[1].c_str(), 10))
								speedKick = strtol(tempInformations[1].c_str(), NULL, 10);
							else
							{
								cout << "ERROR GD002 -A problem occured while getting the speed kick in this line:\n	" << currentLine << endl;
								system("Pause");
								return 1;
							}
						}
						else if (tempInformations[0] == "SPEEDKICKCROUCH")
						{
							speedKickCrouch = 0;
							if (isNumeric(tempInformations[1].c_str(), 10))
								speedKickCrouch = strtol(tempInformations[1].c_str(), NULL, 10);
							else
							{
								cout << "ERROR GD002 -A problem occured while getting the speed kick crouch in this line:\n	" << currentLine << endl;
								system("Pause");
								return 1;
							}
						}
						else if (tempInformations[0] == "SPEEDKICKJUMPED")
						{
							speedKickJumped = 0;
							if (isNumeric(tempInformations[1].c_str(), 10))
								speedKickJumped = strtol(tempInformations[1].c_str(), NULL, 10);
							else
							{
								cout << "ERROR GD002 -A problem occured while getting the speed kick jumped in this line:\n	" << currentLine << endl;
								system("Pause");
								return 1;
							}
						}
						else if (tempInformations[0] == "SPEEDPUNCH")
						{
							speedPunch = 0;
							if (isNumeric(tempInformations[1].c_str(), 10))
								speedPunch = strtol(tempInformations[1].c_str(), NULL, 10);
							else
							{
								cout << "ERROR GD002 -A problem occured while getting the speed punch in this line:\n	" << currentLine << endl;
								system("Pause");
								return 1;
							}
						}
						else if (tempInformations[0] == "SPEEDPUNCHCROUCH")
						{
							speedPunchCrouch = 0;
							if (isNumeric(tempInformations[1].c_str(), 10))
								speedPunchCrouch = strtol(tempInformations[1].c_str(), NULL, 10);
							else
							{
								cout << "ERROR GD002 -A problem occured while getting the speed punch crouch in this line:\n	" << currentLine << endl;
								system("Pause");
								return 1;
							}
						}
						else if (tempInformations[0] == "SPEEDPUNCHJUMPED")
						{
							speedPunchJumped = 0;
							if (isNumeric(tempInformations[1].c_str(), 10))
								speedPunchJumped = strtol(tempInformations[1].c_str(), NULL, 10);
							else
							{
								cout << "ERROR GD002 -A problem occured while getting the speed punch jumped in this line:\n	" << currentLine << endl;
								system("Pause");
								return 1;
							}
						}
						else if (tempInformations[0] == "SOUNDKICK")
						{
							soundKick = tempInformations[1];
						}
						else if (tempInformations[0] == "SOUNDPUNCH")
						{
							soundPunch = tempInformations[1];
						}
						else if (tempInformations[0] == "SOUNDJUMP")
						{
							soundJump = tempInformations[1];
						}
						else if (tempInformations[0] == "SOUNDHIT")
						{
							soundHit = tempInformations[1];
						}
						else if (tempInformations[0] == "SOUNDGUARD")
						{
							soundGuard = tempInformations[1];
						}
						else if (tempInformations[0] == "SOUNDVICTORY")
						{
							soundVictory = tempInformations[1];
						}
					}
					else
					{
						cout << "ERROR GD001 - A problem occured while getting the informations of a character in this line:\n	" << currentLine << endl;
						system("Pause");
						return 1;
					}
				}
			}
			characterArray.push_back(*new CharacterLine(animationName, name, pathAvatar, totalHP, damageKick, damageKickCrouch, damageKickJumped, damagePunch, damagePunchCrouch, damagePunchJumped, speedKick, speedKickCrouch, speedKickJumped, speedPunch, speedPunchCrouch, speedPunchJumped, soundKick, soundPunch, soundJump, soundHit, soundGuard, soundVictory));
			characterFile.close();
		}
		else
		{
			cout << "ERROR OP001 - Can't open the character file." << endl;
			system("Pause");
			return 1;
		}
	}


	/*********************/
	/* Set the '.h' file */
	/*********************/

	// Set the location of the file
	headerOutputLocation = new char[strlen(outputLocation) + strlen("\\CharacterData.h") + 1];
	strcpy_s(headerOutputLocation,strlen(outputLocation)+1,outputLocation);
	strcat_s(headerOutputLocation,strlen(headerOutputLocation)+strlen("\\CharacterData.h")+1,"\\CharacterData.h");
	
	// Create and open the file
	headerFile.open(headerOutputLocation, ios::out|ios::trunc);

	if(headerFile)
	{
		sprintf_s(buffer, "%d", characterArray.size());
		headerContent = "#ifndef _CHARACTERDATA_H\n";
		headerContent = headerContent + "#define _CHARACTERDATA_H\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "#include <string>\n\n";
		headerContent = headerContent + "using namespace std;\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "class CharacterData\n";
		headerContent = headerContent + "{\n";
		headerContent = headerContent + "private:\n";
		headerContent = headerContent + "\tint animationID;\n";
		headerContent = headerContent + "\tstring name;\n";
		headerContent = headerContent + "\tstring pathAvatar;\n";
		headerContent = headerContent + "\tint totalHP;\n";
		headerContent = headerContent + "\tint damageKick;\n";
		headerContent = headerContent + "\tint damageKickCrouch;\n";
		headerContent = headerContent + "\tint damageKickJumped;\n";
		headerContent = headerContent + "\tint damagePunch;\n";
		headerContent = headerContent + "\tint damagePunchCrouch;\n";
		headerContent = headerContent + "\tint damagePunchJumped;\n";
		headerContent = headerContent + "\tint speedKick;\n";
		headerContent = headerContent + "\tint speedKickCrouch;\n";
		headerContent = headerContent + "\tint speedKickJumped;\n";
		headerContent = headerContent + "\tint speedPunch;\n";
		headerContent = headerContent + "\tint speedPunchCrouch;\n";
		headerContent = headerContent + "\tint speedPunchJumped;\n";
		headerContent = headerContent + "\tint soundKick;\n";
		headerContent = headerContent + "\tint soundPunch;\n";
		headerContent = headerContent + "\tint soundJump;\n";
		headerContent = headerContent + "\tint soundHit;\n";
		headerContent = headerContent + "\tint soundGuard;\n";
		headerContent = headerContent + "\tint soundVictory;\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "public:\n";
		headerContent = headerContent + "\tCharacterData();\n";
		headerContent = headerContent + "\tCharacterData(int animationID, string name, string pathAvatar, int totalHP, int damageKick, int damageKickCrouch, int damageKickJumped, int damagePunch, int damagePunchCrouch, int damagePunchJumped, int speedKick, int speedKickCrouch, int speedKickJumped, int speedPunch, int speedPunchCrouch, int speedPunchJumped, int soundKick, int soundPunch, int soundJump, int soundHit, int soundGuard, int soundVictory);\n";
		headerContent = headerContent + "\t~CharacterData(void);\n";
		headerContent = headerContent + "\tint getAnimationID() const;\n";
		headerContent = headerContent + "\tstring getName() const;\n";
		headerContent = headerContent + "\tstring getPathAvatar() const;\n";
		headerContent = headerContent + "\tint getTotalHP() const;\n";
		headerContent = headerContent + "\tint getDamageKick() const;\n";
		headerContent = headerContent + "\tint getDamageKickCrouch() const;\n";
		headerContent = headerContent + "\tint getDamageKickJumped() const;\n";
		headerContent = headerContent + "\tint getDamagePunch() const;\n";
		headerContent = headerContent + "\tint getDamagePunchCrouch() const;\n";
		headerContent = headerContent + "\tint getDamagePunchJumped() const;\n";
		headerContent = headerContent + "\tint getSpeedKick() const;\n";
		headerContent = headerContent + "\tint getSpeedKickCrouch() const;\n";
		headerContent = headerContent + "\tint getSpeedKickJumped() const;\n";
		headerContent = headerContent + "\tint getSpeedPunch() const;\n";
		headerContent = headerContent + "\tint getSpeedPunchCrouch() const;\n";
		headerContent = headerContent + "\tint getSpeedPunchJumped() const;\n";
		headerContent = headerContent + "\tint getSoundKick() const;\n";
		headerContent = headerContent + "\tint getSoundPunch() const;\n";
		headerContent = headerContent + "\tint getSoundJump() const;\n";
		headerContent = headerContent + "\tint getSoundHit() const;\n";
		headerContent = headerContent + "\tint getSoundGuard() const;\n";
		headerContent = headerContent + "\tint getSoundVictory() const;\n";
		headerContent = headerContent + "};\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "#define NUMBER_CHARACTERDATA " + buffer + "\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "extern const CharacterData characterDataArray[NUMBER_CHARACTERDATA];\n";
		headerContent = headerContent + "\n";
		

		// Define the characters' name
		position = 0;
		for(it = characterArray.begin(); it != characterArray.end(); ++it)
		{
			string name = it->getName();
			sprintf_s(buffer, "%d", position);
			std::transform(name.begin(),name.end(), name.begin(), ::toupper);
			headerContent = headerContent + "#define " + name + " " + buffer + "\n";
			++position;
		}

		headerContent = headerContent + "\n";
		headerContent = headerContent + "#endif //_CHARACTERDATA_H\n";

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
	cppOutputLocation = new char[strlen(outputLocation) + strlen("\\CharacterData.cpp") + 1];
	strcpy_s(cppOutputLocation,strlen(outputLocation)+1,outputLocation);
	strcat_s(cppOutputLocation,strlen(cppOutputLocation)+strlen("\\CharacterData.cpp")+1,"\\CharacterData.cpp");
	
	// Create and open the file
	cppFile.open(cppOutputLocation, ios::out|ios::trunc);

	if(cppFile)
	{
		cppContent = "#include \"CharacterData.h\"\n";
		cppContent = cppContent + "#include \"AnimationData.h\"\n";
		cppContent = cppContent + "#include \"SoundData.h\"\n";
		cppContent = cppContent + "\n";

		cppContent = cppContent + "const CharacterData characterDataArray[NUMBER_CHARACTERDATA] =\n";
		cppContent = cppContent + "{\n";

		// Put all the data into the animationArray in the cpp file
		for(it = characterArray.begin(); it != characterArray.end(); ++it)
		{
			// Put : animatioName
			cppContent = cppContent + "\tCharacterData(" + it->getAnimationName() + ", ";
			
			// Put : name
			cppContent = cppContent + "\"" + it->getName() + "\", ";

			// Put : pathAvatar
			cppContent = cppContent + "\"" + it->getPathAvatar() + "\", ";

			// Put : totalHP
			sprintf_s(buffer, "%d", it->getTotalHP());
			cppContent = cppContent + buffer + ", ";
			
			// Put : damageKick
			sprintf_s(buffer, "%d", it->getDamageKick());
			cppContent = cppContent + buffer + ", ";
			
			// Put : damageKickCrouch
			sprintf_s(buffer, "%d", it->getDamageKickCrouch());
			cppContent = cppContent + buffer + ", ";
			
			// Put : damageKickJumped
			sprintf_s(buffer, "%d", it->getDamageKickJumped());
			cppContent = cppContent + buffer + ", ";
			
			// Put : damagePunch
			sprintf_s(buffer, "%d", it->getDamagePunch());
			cppContent = cppContent + buffer + ", ";
			
			// Put : damagePunchCrouch
			sprintf_s(buffer, "%d", it->getDamagePunchCrouch());
			cppContent = cppContent + buffer + ", ";
			
			// Put : damagePunchJumped
			sprintf_s(buffer, "%d", it->getDamagePunchJumped());
			cppContent = cppContent + buffer + ", ";
			
			// Put : speedKick
			sprintf_s(buffer, "%d", it->getSpeedKick());
			cppContent = cppContent + buffer + ", ";
			
			// Put : speedKickCrouch
			sprintf_s(buffer, "%d", it->getSpeedKickCrouch());
			cppContent = cppContent + buffer + ", ";
			
			// Put : speedKickJumped
			sprintf_s(buffer, "%d", it->getSpeedKickJumped());
			cppContent = cppContent + buffer + ", ";
			
			// Put : speedPunch
			sprintf_s(buffer, "%d", it->getSpeedPunch());
			cppContent = cppContent + buffer + ", ";
			
			// Put : speedPunchCrouch
			sprintf_s(buffer, "%d", it->getSpeedPunchCrouch());
			cppContent = cppContent + buffer + ", ";
			
			// Put : speedPunchJumped
			sprintf_s(buffer, "%d", it->getSpeedPunchJumped());
			cppContent = cppContent + buffer + ", ";
			
			// Put : soundKick
			cppContent = cppContent + it->getSoundKick() + ", ";
			
			// Put : soundPunch
			cppContent = cppContent + it->getSoundPunch() + ", ";
			
			// Put : soundJump
			cppContent = cppContent + it->getSoundJump() + ", ";
			
			// Put : soundHit
			cppContent = cppContent + it->getSoundHit() + ", ";
			
			// Put : soundGuard
			cppContent = cppContent + it->getSoundGuard() + ", ";
			
			// Put : soundVictory
			cppContent = cppContent + it->getSoundVictory();

			cppContent = cppContent + "),\n";
		}
		
		cppContent = cppContent + "};\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "CharacterData::CharacterData()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tthis->animationID = 0;\n";
		cppContent = cppContent + "\tthis->name = \"\";\n";
		cppContent = cppContent + "\tthis->pathAvatar = \"\";\n";
		cppContent = cppContent + "\tthis->totalHP = 0;\n";
		cppContent = cppContent + "\tthis->damageKick = 0;\n";
		cppContent = cppContent + "\tthis->damageKickCrouch = 0;\n";
		cppContent = cppContent + "\tthis->damageKickJumped = 0;\n";
		cppContent = cppContent + "\tthis->damagePunch = 0;\n";
		cppContent = cppContent + "\tthis->damagePunchCrouch = 0;\n";
		cppContent = cppContent + "\tthis->damagePunchJumped = 0;\n";
		cppContent = cppContent + "\tthis->speedKick = 0;\n";
		cppContent = cppContent + "\tthis->speedKickCrouch = 0;\n";
		cppContent = cppContent + "\tthis->speedKickJumped = 0;\n";
		cppContent = cppContent + "\tthis->speedPunch = 0;\n";
		cppContent = cppContent + "\tthis->speedPunchCrouch = 0;\n";
		cppContent = cppContent + "\tthis->speedPunchJumped = 0;\n";
		cppContent = cppContent + "\tthis->soundKick = 0;\n";
		cppContent = cppContent + "\tthis->soundPunch = 0;\n";
		cppContent = cppContent + "\tthis->soundJump = 0;\n";
		cppContent = cppContent + "\tthis->soundHit = 0;\n";
		cppContent = cppContent + "\tthis->soundGuard = 0;\n";
		cppContent = cppContent + "\tthis->soundVictory = 0;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "CharacterData::CharacterData(int animationID, string name, string pathAvatar, int totalHP, int damageKick, int damageKickCrouch, int damageKickJumped, int damagePunch, int damagePunchCrouch, int damagePunchJumped, int speedKick, int speedKickCrouch, int speedKickJumped, int speedPunch, int speedPunchCrouch, int speedPunchJumped, int soundKick, int soundPunch, int soundJump, int soundHit, int soundGuard, int soundVictory)\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tthis->animationID = animationID;\n";
		cppContent = cppContent + "\tthis->name = name;\n";
		cppContent = cppContent + "\tthis->pathAvatar = pathAvatar;\n";
		cppContent = cppContent + "\tthis->totalHP = totalHP;\n";
		cppContent = cppContent + "\tthis->damageKick = damageKick;\n";
		cppContent = cppContent + "\tthis->damageKickCrouch = damageKickCrouch;\n";
		cppContent = cppContent + "\tthis->damageKickJumped = damageKickJumped;\n";
		cppContent = cppContent + "\tthis->damagePunch = damagePunch;\n";
		cppContent = cppContent + "\tthis->damagePunchCrouch = damagePunchCrouch;\n";
		cppContent = cppContent + "\tthis->damagePunchJumped = damagePunchJumped;\n";
		cppContent = cppContent + "\tthis->speedKick = speedKick;\n";
		cppContent = cppContent + "\tthis->speedKickCrouch = speedKickCrouch;\n";
		cppContent = cppContent + "\tthis->speedKickJumped = speedKickJumped;\n";
		cppContent = cppContent + "\tthis->speedPunch = speedPunch;\n";
		cppContent = cppContent + "\tthis->speedPunchCrouch = speedPunchCrouch;\n";
		cppContent = cppContent + "\tthis->speedPunchJumped = speedPunchJumped;\n";
		cppContent = cppContent + "\tthis->soundKick = soundKick;\n";
		cppContent = cppContent + "\tthis->soundPunch = soundPunch;\n";
		cppContent = cppContent + "\tthis->soundJump = soundJump;\n";
		cppContent = cppContent + "\tthis->soundHit = soundHit;\n";
		cppContent = cppContent + "\tthis->soundGuard = soundGuard;\n";
		cppContent = cppContent + "\tthis->soundVictory = soundVictory;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "CharacterData::~CharacterData(void)\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getAnimationID() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->animationID;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "string CharacterData::getName() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->name;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "string CharacterData::getPathAvatar() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->pathAvatar;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getTotalHP() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->totalHP;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getDamageKick() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->damageKick;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getDamageKickCrouch() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->damageKickCrouch;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getDamageKickJumped() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->damageKickJumped;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getDamagePunch() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->damagePunch;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getDamagePunchCrouch() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->damagePunchCrouch;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getDamagePunchJumped() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->damagePunchJumped;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getSpeedKick() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->speedKick;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getSpeedKickCrouch() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->speedKickCrouch;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getSpeedKickJumped() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->speedKickJumped;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getSpeedPunch() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->speedPunch;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getSpeedPunchCrouch() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->speedPunchCrouch;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getSpeedPunchJumped() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->speedPunchJumped;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getSoundKick() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->soundKick;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getSoundPunch() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->soundPunch;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getSoundJump() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->soundJump;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getSoundHit() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->soundHit;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getSoundGuard() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->soundGuard;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int CharacterData::getSoundVictory() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->soundVictory;\n";
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
	cout << "	- CharacterData.h" << endl;
	cout << "	- CharacterData.cpp" << endl;
	cout << "into the folder :" << endl;
	cout << "	- " << outputLocation << endl << endl;

	system("Pause");
	return 0;
}

