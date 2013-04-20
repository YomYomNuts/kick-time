#include <string>
#define _OPEN_SYS
#include <iostream>
#include <list>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#undef _OPEN_SYS

using namespace std;

enum position{FIRST,LAST};
char* subChar(char* string, int startPos,int size);
int findChar(char* string, char toFind, position type);
char* mySubStringToChar(string str, int posStart, int posEnd);
int findFrom(string str, int posStart, char toFind);
int myAtoi(char* str);
void getAnimFilesLocation(char* folder, list<char*> &filesNameList);