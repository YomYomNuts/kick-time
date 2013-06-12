#include <string>
#include <iostream>
#include <vector>
#define _OPEN_SYS
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#undef _OPEN_SYS

using namespace std;

enum position{FIRST,LAST};
char* subChar(char* string, int startPos, int size);
int findChar(char* string, char toFind, position type);
vector<string> split(string initString, string delimiter);
bool isNumeric(const char* pszInput, int nNumberBase);
void getFilesLocation(char* folder, vector<char*> &filesNameList, string typeFile);