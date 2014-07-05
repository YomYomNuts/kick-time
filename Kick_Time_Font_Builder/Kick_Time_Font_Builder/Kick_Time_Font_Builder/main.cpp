#include "FontLine.h"
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
	char* fontLocation = new char[];
	char* outputLocation = new char[];
	char confirm = 'n';
	bool resetData = false;

	// Variables for files' creation
	char* headerOutputLocation = new char[];
	char* cppOutputLocation = new char[];

	// Variable to open/read/create/write files
	// Level file
	vector<FontLine> listFonts;
	vector<FontLine>::iterator it;
	ifstream fontFile;
	string currentLine;
	string delimiter = ";";
	vector<string> tempInformations;
	string fileName;
	string fontID;
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
			fontLocation = new char[strlen(argv[1])+1];
			strcpy_s(fontLocation, strlen(argv[1])+1, argv[1]);

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
				cout << "Set \"Font file's location\" : ";
				cin >> fontLocation;
				cout << "Set \"Output class location\" : ";
				cin >> outputLocation;
				cout << endl << endl << endl;
			}
			cout << "Confirm : " << endl;
			cout << "Font file's location : " << fontLocation << endl << endl;
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
			cout << "Set \"Font file's location\" : ";
			cin >> fontLocation;
			cout << "Set \"Output class location\" : ";
			cin >> outputLocation;
			cout << endl << endl << endl;

			cout << "Confirm : " << endl;
			cout << "Font file's location : " << fontLocation << endl << endl;
			cout << "Output class location : " << outputLocation << endl << endl;

			cout << "Confirm (y/n) : ";
			cin >> confirm;
			resetData = true;
		}
	}

	// Check the font file
	// Check if it's a text file
	if(strcmp(subChar(fontLocation, findChar(fontLocation,'.',LAST), strlen(fontLocation)-1), ".txt") != 0)
	{
		cout << "Please select an font file as a '.txt' file" << endl;
		system("Pause");
		return 1;
	}

	/************************/
	/* Read the font files */
	/************************/
	
	// Open the font file
	fontFile.open(fontLocation, ios::in);

	if(fontFile)
	{
		while(!fontFile.eof())
		{
			// Get the full current line
			getline(fontFile, currentLine);

			if(!currentLine.empty())
			{
				/****************************/
				/* Get the different values */
				/****************************/
				tempInformations = split(currentLine, delimiter);
				if (tempInformations.size() == 2)
				{
					fileName = tempInformations[0];
					fontID = tempInformations[1];

					listFonts.push_back(*new FontLine(fileName, fontID));
				}
				else
				{
					cout << "ERROR GD001 - A problem occured while getting the informations of a font in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}
			}
		}
	}
	else
	{
		cout << "ERROR OP001 - Can't open the font file." << endl;
		system("Pause");
		return 1;
	}

	fontFile.close();

	/*********************/
	/* Set the '.h' file */
	/*********************/

	// Set the location of the file
	headerOutputLocation = new char[strlen(outputLocation) + strlen("\\FontData.h") + 1];
	strcpy_s(headerOutputLocation,strlen(outputLocation)+1,outputLocation);
	strcat_s(headerOutputLocation,strlen(headerOutputLocation)+strlen("\\FontData.h")+1,"\\FontData.h");
	
	// Create and open the file
	headerFile.open(headerOutputLocation, ios::out|ios::trunc);

	if(headerFile)
	{
		sprintf_s(buffer, "%d", listFonts.size());
		headerContent = "#ifndef _FONTDATA_H\n";
		headerContent = headerContent + "#define _FONTDATA_H\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "#include <string>\n\n";
		headerContent = headerContent + "using namespace std;\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "class FontData\n";
		headerContent = headerContent + "{\n";
		headerContent = headerContent + "private:\n";
		headerContent = headerContent + "\tstring fileName;\n";
		headerContent = headerContent + "\tint fontID;\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "public:\n";
		headerContent = headerContent + "\tFontData();\n";
		headerContent = headerContent + "\tFontData(string fileName, int fontID);\n";
		headerContent = headerContent + "\t~FontData(void);\n";
		headerContent = headerContent + "\tstring getFileName() const;\n";
		headerContent = headerContent + "\tint getFontID() const;\n";
		headerContent = headerContent + "};\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "#define NUMBER_FONTDATA " + buffer + "\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "extern const FontData fontDataArray[NUMBER_FONTDATA];\n";
		headerContent = headerContent + "\n";
		

		// Define the fonts' name
		position = 0;
		for(it = listFonts.begin(); it != listFonts.end(); ++it)
		{
			sprintf_s(buffer, "%d", position);
			headerContent = headerContent + "#define " + it->getFontID() + " " + buffer + "\n";
			++position;
		}

		headerContent = headerContent + "\n";
		headerContent = headerContent + "#endif //_FONTDATA_H\n";

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
	cppOutputLocation = new char[strlen(outputLocation) + strlen("\\FontData.cpp") + 1];
	strcpy_s(cppOutputLocation,strlen(outputLocation)+1,outputLocation);
	strcat_s(cppOutputLocation,strlen(cppOutputLocation)+strlen("\\FontData.cpp")+1,"\\FontData.cpp");
	
	// Create and open the file
	cppFile.open(cppOutputLocation, ios::out|ios::trunc);

	if(cppFile)
	{
		cppContent = "#include \"FontData.h\"\n";
		cppContent = cppContent + "\n";

		cppContent = cppContent + "const FontData fontDataArray[NUMBER_FONTDATA] =\n";
		cppContent = cppContent + "{\n";

		// Put all the data into the animationArray in the cpp file
		for(it = listFonts.begin(); it != listFonts.end(); it++)
		{
			// Put : FontData
			cppContent = cppContent + "\tFontData(\"" + it->getFileName() + "\", " + it->getFontID();


			cppContent = cppContent + "),\n";
		}
		
		cppContent = cppContent + "};\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "FontData::FontData()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tthis->fileName = \"\";\n";
		cppContent = cppContent + "\tthis->fontID = 0;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "FontData::FontData(string fileName, int fontID)\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tthis->fileName = fileName;\n";
		cppContent = cppContent + "\tthis->fontID = fontID;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "FontData::~FontData(void)\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "string FontData::getFileName() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->fileName;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int FontData::getFontID() const\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->fontID;\n";
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
	cout << "	- FontData.h" << endl;
	cout << "	- FontData.cpp" << endl;
	cout << "into the folder :" << endl;
	cout << "	- " << outputLocation << endl << endl;

	system("Pause");
	return 0;
}