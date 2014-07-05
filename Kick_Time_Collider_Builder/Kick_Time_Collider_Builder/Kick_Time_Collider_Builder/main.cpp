#include "functions.h"
#include "ColliderLine.h"

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
	char* colliderLocation = new char[];
	char* outputLocation = new char[];
	char confirm = 'n';
	bool resetData = false;

	// Variables for files' creation
	char* headerOutputLocation = new char[];
	char* cppOutputLocation = new char[];

	// Variable to open/read/create/write files
	// Collider file
	vector<char*> colliderFilesList;
	vector<ColliderLine> colliderArray;
	vector<ColliderLine>::iterator it;
	ifstream colliderFile;
	string currentLine;
	string delimiter = ";";
	vector<string> tempInformations;
	string colliderName;
	int posX;
	int posY;
	int halfSizeX;
	int halfSizeY;
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
			colliderLocation = new char[strlen(argv[1])+1];
			strcpy_s(colliderLocation, strlen(argv[1])+1, argv[1]);
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
				cout << "Set \"collider file's location\" : ";
				cin >> colliderLocation;
				cout << "Set \"Output class location\" : ";
				cin >> outputLocation;
				cout << endl << endl << endl;
			}
			cout << "Confirm : " << endl;
			cout << "Collider file's location : " << colliderLocation << endl << endl;
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
			cout << "Set \"collider file's location\" : ";
			cin >> colliderLocation;
			cout << "Set \"Output class location\" : ";
			cin >> outputLocation;
			cout << endl << endl << endl;

			cout << "Confirm : " << endl;
			cout << "Collider file's location : " << colliderLocation << endl << endl;
			cout << "Output class location : " << outputLocation << endl << endl;

			cout << "Confirm (y/n) : ";
			cin >> confirm;
			resetData = true;
		}
	}

	/**********************************************************/
	/* Get the location and the name of the collider's files */
	/**********************************************************/

	getFilesLocation(colliderLocation, colliderFilesList, "collider.txt");
	
	// Check if at least one file has been found
	if(colliderFilesList.size() == 0){
		system("Pause");
		return 1;
	}
	
	/***************************/
	/* Read the collider file */
	/***************************/

	// Go to the beginning of the list
	vector<char*>::iterator iteratorFile;
	
	for(iteratorFile = colliderFilesList.begin(); iteratorFile != colliderFilesList.end(); iteratorFile++)
	{
		// Open the collider file
		colliderFile.open(*iteratorFile,ios::in);

		if(colliderFile)
		{
			while(!colliderFile.eof())
			{
				// Get the full current line
				getline(colliderFile, currentLine);

				if(!currentLine.empty())
				{
					/****************************/
					/* Get the different values */
					/****************************/
					tempInformations = split(currentLine, delimiter);
					if (tempInformations.size() == 5)
					{
						colliderName = tempInformations[0];
						// Get posX
						posX = 0;
						if (isNumeric(tempInformations[1].c_str(), 10))
							posX = strtol(tempInformations[1].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD002 -A problem occured while getting the X position in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}
						// Get posY
						posY = 0;
						if (isNumeric(tempInformations[2].c_str(), 10))
							posY = strtol(tempInformations[2].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD003 - A problem occured while getting the Y position in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}
						// Get halfSizeX
						halfSizeX = 0;
						if (isNumeric(tempInformations[3].c_str(), 10))
							halfSizeX = strtol(tempInformations[3].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD002 -A problem occured while getting the half size X in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}
						// Get halfSizeY
						halfSizeY = 0;
						if (isNumeric(tempInformations[4].c_str(), 10))
							halfSizeY = strtol(tempInformations[4].c_str(), NULL, 10);
						else
						{
							cout << "ERROR GD003 - A problem occured while getting the half size Y in this line:\n	" << currentLine << endl;
							system("Pause");
							return 1;
						}

						colliderArray.push_back(*new ColliderLine(colliderName, posX, posY, halfSizeX, halfSizeY));
					}
					else
					{
						cout << "ERROR GD001 - A problem occured while getting the informations of a collider in this line:\n	" << currentLine << endl;
						system("Pause");
						return 1;
					}
				}
			}
			colliderFile.close();
		}
		else
		{
			cout << "ERROR OP001 - Can't open the collider file." << endl;
			system("Pause");
			return 1;
		}
	}


	/*********************/
	/* Set the '.h' file */
	/*********************/

	// Set the location of the file
	headerOutputLocation = new char[strlen(outputLocation) + strlen("\\ColliderData.h") + 1];
	strcpy_s(headerOutputLocation,strlen(outputLocation)+1,outputLocation);
	strcat_s(headerOutputLocation,strlen(headerOutputLocation)+strlen("\\ColliderData.h")+1,"\\ColliderData.h");
	
	// Create and open the file
	headerFile.open(headerOutputLocation, ios::out|ios::trunc);

	if(headerFile)
	{
		sprintf_s(buffer, "%d", colliderArray.size());
		headerContent = "#ifndef _COLLIDERDATA_H\n";
		headerContent = headerContent + "#define _COLLIDERDATA_H\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "#include <string>\n\n";
		headerContent = headerContent + "using namespace std;\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "class ColliderData\n";
		headerContent = headerContent + "{\n";
		headerContent = headerContent + "private:\n";
		headerContent = headerContent + "\tint colliderID;\n";
		headerContent = headerContent + "\tint posX;\n";
		headerContent = headerContent + "\tint posY;\n";
		headerContent = headerContent + "\tint halfSizeX;\n";
		headerContent = headerContent + "\tint halfSizeY;\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "public:\n";
		headerContent = headerContent + "\tColliderData();\n";
		headerContent = headerContent + "\tColliderData(int colliderID, int posX, int posY, int halfSizeX, int halfSizeY);\n";
		headerContent = headerContent + "\t~ColliderData(void);\n";
		headerContent = headerContent + "\tint getColliderID() const;\n";
		headerContent = headerContent + "\tint getPosX() const;\n";
		headerContent = headerContent + "\tint getPosY() const;\n";
		headerContent = headerContent + "\tint getHalfSizeX() const;\n";
		headerContent = headerContent + "\tint getHalfSizeY() const;\n";
		headerContent = headerContent + "};\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "#define NUMBER_COLLIDERDATA " + buffer + "\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "extern const ColliderData colliderDataArray[NUMBER_COLLIDERDATA];\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "#define COLLIDER_NULL (-1)\n";
		

		// Define the colliders' name
		position = 0;
		for(it = colliderArray.begin(); it != colliderArray.end(); ++it)
		{
			sprintf_s(buffer, "%d", position);
			headerContent = headerContent + "#define " + it->getColliderName() + " " + buffer + "\n";
			++position;
		}

		headerContent = headerContent + "\n";
		headerContent = headerContent + "#endif //_COLLIDERDATA_H\n";

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
	cppOutputLocation = new char[strlen(outputLocation) + strlen("\\ColliderData.cpp") + 1];
	strcpy_s(cppOutputLocation,strlen(outputLocation)+1,outputLocation);
	strcat_s(cppOutputLocation,strlen(cppOutputLocation)+strlen("\\ColliderData.cpp")+1,"\\ColliderData.cpp");
	
	// Create and open the file
	cppFile.open(cppOutputLocation, ios::out|ios::trunc);

	if(cppFile)
	{
		cppContent = "#include \"ColliderData.h\"\n";
		cppContent = cppContent + "\n";

		cppContent = cppContent + "const ColliderData colliderDataArray[NUMBER_COLLIDERDATA] =\n";
		cppContent = cppContent + "{\n";

		// Put all the data into the animationArray in the cpp file
		for(it = colliderArray.begin(); it != colliderArray.end(); ++it)
		{
			// Put : colliderName
			cppContent = cppContent + "\tColliderData(" + it->getColliderName() + ", ";

			// Put : posX
			sprintf_s(buffer, "%d", it->getPosX());
			cppContent = cppContent + buffer + ", ";

			// Put : posY
			sprintf_s(buffer, "%d", it->getPosY());
			cppContent = cppContent + buffer + ", ";
			
			// Put : halfSizeX
			sprintf_s(buffer, "%d", it->getHalfSizeX());
			cppContent = cppContent + buffer + ", ";
			
			// Put : halfSizeY
			sprintf_s(buffer, "%d", it->getHalfSizeY());
			cppContent = cppContent + buffer;

			cppContent = cppContent + "),\n";
		}
		
		cppContent = cppContent + "};\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "ColliderData::ColliderData()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tthis->colliderID = 0;\n";
		cppContent = cppContent + "\tthis->posX = 0;\n";
		cppContent = cppContent + "\tthis->posY = 0;\n";
		cppContent = cppContent + "\tthis->halfSizeX = 0;\n";
		cppContent = cppContent + "\tthis->halfSizeY = 0;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "ColliderData::ColliderData(int colliderID, int posX, int posY, int halfSizeX, int halfSizeY)\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tthis->colliderID = colliderID;\n";
		cppContent = cppContent + "\tthis->posX = posX;\n";
		cppContent = cppContent + "\tthis->posY = posY;\n";
		cppContent = cppContent + "\tthis->halfSizeX = halfSizeX;\n";
		cppContent = cppContent + "\tthis->halfSizeY = halfSizeY;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "ColliderData::~ColliderData(void)\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int ColliderData::getColliderID() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->colliderID;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int ColliderData::getPosX() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->posX;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int ColliderData::getPosY() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->posY;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int ColliderData::getHalfSizeX() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->halfSizeX;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int ColliderData::getHalfSizeY() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->halfSizeY;\n";
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
	cout << "	- ColliderData.h" << endl;
	cout << "	- ColliderData.cpp" << endl;
	cout << "into the folder :" << endl;
	cout << "	- " << outputLocation << endl << endl;

	system("Pause");
	return 0;
}

