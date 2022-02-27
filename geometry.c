#include "geomfunc.h"
#include <ctype.h>
#include <stdio.h>
#define STRINGSIZE 30
#define COORDSIZE 5

int main()
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

    int opnBrCheck = isOpnBracket(inputStr, j);
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
 	       printf("[ERROR] - Problem with brackets");
        return 1;
    }
    int correctNameCheck = isCorrectName(nameObject, cir, cirSize);
    if (correctNameCheck == 0) {
        printf("[ERROR] - Problems with object name");
        return 1;
    }
    int correctCntCommaCheck = isCorrectCntComma(coords);
    if (correctCntCommaCheck == 0) {
        printf("[ERROR] - Too many or too few arguments");
        return 1;
    }
    i = 0;
    while (coords[i] != ' ') {
        firstCenterCoord[i] = coords[i];
        i++;
    }
    i++;
    j=0;
    while (coords[i] != ',') {
        secondCenterCoord[j] = coords[i];
        i++;
        j++;
    }
    i++;
    k=0;
    while (coords[i] != ')') {
        if (coords[i] == ' '){
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
