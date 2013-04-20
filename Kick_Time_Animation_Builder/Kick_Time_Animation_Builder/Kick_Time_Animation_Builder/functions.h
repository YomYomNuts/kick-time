#include <string>
using namespace std;

enum position{FIRST,LAST};
char* subChar(char* string, int startPos,int size);
int findChar(char* string, char toFind, position type);
char* mySubStringToChar(string str, int posStart, int posEnd);
int findFrom(string str, int posStart, char toFind);
int myAtoi(char* str);