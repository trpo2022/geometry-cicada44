#include <ctype.h>
#define STRINGSIZE 30
#define COORDSIZE 5

int isOpnBracket(char* arr, int c)
{
    for (int c = 0; c < STRINGSIZE; c++) {
        if (arr[c] == '(') {
            return c;
	}
    }
    return 0;
}

int isClsBracket(char* arr, int cnt)
{
    for (int x = cnt; x < STRINGSIZE; x++) {
        if (arr[x] == ')') {
            return x;
	}
    }
    return 0;
}

int isCorrectName(char* nameObject, char* cir, int cirSize)
{
    for (int x = 0; x < cirSize; x++) {
        if (nameObject[x] != cir[x] && toupper(nameObject[x]) != cir[x]
            && tolower(nameObject[x]) != cir[x]) {
            return 0;
        }
    }
    return 1;
}

int isCorrectCntComma(char* arrCoords)
{
    int commaCnt = 0;
    for (int x = 0; x < STRINGSIZE; x++) {
        if (arrCoords[x] == ',')
            commaCnt++;
    }
    if (commaCnt == 1) {
        return 1;
    }
    return 0;
}

