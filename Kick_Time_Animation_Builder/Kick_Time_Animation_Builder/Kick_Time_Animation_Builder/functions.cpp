#include "functions.h"



// Return a part of a char*
char* subChar(char* string, int startPos,int size)
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

// Return part of a string into a char* format
char* mySubStringToChar(string str, int posStart, int posEnd)
{
	char* finalString = new char[posEnd-posStart+2];
	unsigned int i;
	int counter = 0;
	
	for(i = posStart; i < posEnd+1; i++)
	{
		if(i < str.size())
		{
			finalString[counter] = str[i];
			counter++;
		}
	}

	finalString[counter] = '\0';

	return finalString;

}

// Find a char in string from a specific position
int findFrom(string str, int posStart, char toFind)
{
	int i;

	for( i = posStart; i < str.size(); i++)
	{
		if(str[i] == toFind)
		{
			return i;
		}
	}

	return -1;
}

// Return the int value of a char* value, return -1 if can't convert
// This function has been redifined to do not get 0 if the function can't convert, but -1 instead
int myAtoi(char* str)
{
	int i;
	int coefficient = 1;
	int finalNumber = 0;

	for( i = 0 ; i < strlen(str); i++)
	{
		if((str[i] - 48) >= 0 && (str[i] - 48) <= 9)
		{
			finalNumber *= coefficient;
			finalNumber += str[i] - 48;
			coefficient = 10;
		}
		else if(str[i] != '\0' && str[i] != ' ')
		{
			return -1;
		}
	}

	return finalNumber;
}

// Put in a list all the .txt files found in the directory sent. It will also check all the sub-directories
void getAnimFilesLocation(char* folder, list<char*> &filesNameList) {
	
	char* name = new char [];
	DIR *dir;
	struct dirent *entry;
	char* path = new char []; 
	struct stat info;

	if ((dir = opendir(folder)) == NULL){
		perror("opendir() error");
	}
	else {
		while ((entry = readdir(dir)) != NULL) {
			
			// If the current file is a .txt file, we add it to the list
			if(strcmp(subChar(entry->d_name,findChar(entry->d_name,'.',LAST),strlen(entry->d_name)-1),".txt") == 0){
				name = new char [strlen(folder)+1];
				strcpy_s(name, strlen(folder)+1, folder);
				strcat_s(name,strlen(name)+2, "/");
				strcat_s(name, strlen(name)+strlen(entry->d_name)+1,entry->d_name);
				filesNameList.push_back(name);
			}
			
			if (entry->d_name[0] != '.') {
				path = new char[strlen(folder)+1];

				strcpy_s(path,strlen(folder)+1, folder);
				strcat_s(path,strlen(path)+2, "/");
				strcat_s(path,strlen(path)+strlen(entry->d_name) + 1, entry->d_name);
				stat(path, &info);
				// If the current file is a directory, we go in and check the content
				if (S_ISDIR(info.st_mode))
						getAnimFilesLocation(path,filesNameList);
			}
		}
		closedir(dir);
	}
}
