#include "functions.h"

#include <iostream>

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
