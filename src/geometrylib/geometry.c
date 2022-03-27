#include <geometrylib/geomfunc.h>
#include <ctype.h>
#include <stdio.h>
#define STRINGSIZE 30
#define COORDSIZE 5

int isOpnBracket(char* arr)
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
        if (arrCoords[x] == ',') {
            commaCnt++;
        }
    }
    if (commaCnt == 1) {
        return 1;
    }
    return 0;
}

int coords()
{
    int cirSize = 8;
    char inputStr[STRINGSIZE], nameObject[STRINGSIZE], coords[STRINGSIZE];
    char firstCenterCoord[COORDSIZE], secondCenterCoord[COORDSIZE],
            radius[COORDSIZE];
    char cir[cirSize];
    // cir[cirSize] = "circle\0" is not working
    // the line below means cir="circle\0"
    cir[0] = 'c';
    cir[1] = 'i';
    cir[2] = 'r';
    cir[3] = 'c';
    cir[4] = 'l';
    cir[5] = 'e';
    cir[6] = '\0';
    int j = 0, k = 0, i = 0;

    printf("Input the object\n");

    fgets(inputStr, STRINGSIZE, stdin);

    int opnBrCheck = isOpnBracket(inputStr);
    int clsBrCheck = isClsBracket(inputStr, j);
    if (opnBrCheck && clsBrCheck && clsBrCheck > opnBrCheck) {
        while (inputStr[k] != '(') {
            nameObject[k] = inputStr[k];
            k++;
        }
        while (inputStr[k] != ')') {
            coords[i] = inputStr[k + 1];
            i++;
            k++;
        }
    } else {
        printf("[ERROR] - Problem with brackets\n");
        return 1;
    }
    int correctNameCheck = isCorrectName(nameObject, cir, cirSize);
    if (correctNameCheck == 0) {
        printf("[ERROR] - Problems with object name\n");
        return 1;
    }
    int correctCntCommaCheck = isCorrectCntComma(coords);
    if (correctCntCommaCheck == 0) {
        printf("[ERROR] - Too many or too few arguments\n");
        return 1;
    }
    i = 0;
    while (coords[i] != ' ') {
        firstCenterCoord[i] = coords[i];
        i++;
    }
    i++;
    j = 0;
    while (coords[i] != ',') {
        secondCenterCoord[j] = coords[i];
        i++;
        j++;
    }
    i++;
    k = 0;
    while (coords[i] != ')') {
        if (coords[i] == ' ') {
            i++;
            continue;
        }
        radius[k] = coords[i];
        i++;
        k++;
    }
    printf("\nObject - %s\nCoordinates of center - (%s,%s)\nRadius - %s\n",
           nameObject,
           firstCenterCoord,
           secondCenterCoord,
           radius);
    return 0;
}
