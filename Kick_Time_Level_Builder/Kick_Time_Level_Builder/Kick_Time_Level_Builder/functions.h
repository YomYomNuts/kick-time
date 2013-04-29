#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum position{FIRST,LAST};
char* subChar(char* string, int startPos,int size);
int findChar(char* string, char toFind, position type);
vector<string> split(string initString, string delimiter);
bool isNumeric(const char* pszInput, int nNumberBase);