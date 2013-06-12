#include "functions.h"

#include <sstream>

// Return a part of a char*
char* subChar(char* string, int startPos, int size)
{
	int i;
	int counter = 0;
	char* finalString = new char[size+1];

	for(i = startPos; i < startPos+size; i++)
	{
		if(i < strlen(string))
		{
			finalString[counter] = string[i];
			counter++;
		}
	}

	finalString[counter] = '\0';

	return finalString;
}

// Return the position of a specific char from a char*
int findChar(char* string, char toFind, position type)
{
	int i;

	if(type == FIRST)
	{
		for(i = 0; i < strlen(string); i++)
		{
			if(string[i] == toFind)
				return i;
		}
		return -1;
	}
	else if(type == LAST)
	{
		for(i = strlen(string)-1; i > -1; i--)
		{
			if(string[i] == toFind)
				return i;
		}
		return -1;
	}
	else
	{
		return -1;
	}
}

// Return the vector that contains all terms split by the delimiter
vector<string> split(string initString, string delimiter)
{
	vector<string> listSplit;
	size_t pos = 0;
	string token;

	while ((pos = initString.find(delimiter)) != string::npos) {
		token = initString.substr(0, pos);
		listSplit.push_back(token);
		initString.erase(0, pos + delimiter.length());
	}
	listSplit.push_back(initString);
	return listSplit;
}

// Verify if the string is a number in the base (8, 10 or 16)
bool isNumeric(const char* pszInput, int nNumberBase)
{
	istringstream iss(pszInput);

	if (nNumberBase == 10)
	{
		double dTestSink;
		iss >> dTestSink;
	}
	else if (nNumberBase == 8 || nNumberBase == 16)
	{
		int nTestSink;
		iss >> ((nNumberBase == 8) ? oct : hex) >> nTestSink;
	}
	else
		return false;

	// was any input successfully consumed/converted?
	if (!iss)
		return false;

	// was all the input successfully consumed/converted?
	return (iss.rdbuf()->in_avail() == 0);
}

// Put in a list all the .txt files found in the directory sent. It will also check all the sub-directories
void getFilesLocation(char* folder, vector<char*> &filesNameList, string typeFile) {
	
	char* name = new char [];
	DIR *dir;
	struct dirent *entry;
	char* path = new char []; 
	struct stat info;

	if ((dir = opendir(folder)) == NULL)
	{
		perror("opendir() error");
	}
	else
	{
		while ((entry = readdir(dir)) != NULL)
		{
			vector<string> list = split(entry->d_name, typeFile);
			// If the current file is a .txt file, we add it to the list
			if(list.size() > 1 && list.at(1) == "")
			{
				name = new char [strlen(folder)+1];
				strcpy_s(name, strlen(folder)+1, folder);
				strcat_s(name,strlen(name)+2, "/");
				strcat_s(name, strlen(name)+strlen(entry->d_name)+1, entry->d_name);
				filesNameList.push_back(name);
			}
			
			if (entry->d_name[0] != '.')
			{
				path = new char[strlen(folder)+1];

				strcpy_s(path,strlen(folder)+1, folder);
				strcat_s(path,strlen(path)+2, "/");
				strcat_s(path,strlen(path)+strlen(entry->d_name) + 1, entry->d_name);
				stat(path, &info);
				// If the current file is a directory, we go in and check the content
				if (S_ISDIR(info.st_mode))
					getFilesLocation(path, filesNameList, typeFile);
			}
		}
		closedir(dir);
	}
}