#define _USE_MATH_DEFINES
#include <ctype.h>
#include <geometrylib/geomfunc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define STRINGSIZE 30
#define COORDSIZE 5

struct circle circleN;
char cir[] = "circle";

float charToFloat(char* c)
{
    double z = atof(c);
    float r = (float)z;
    return r;
}

void printCoords()
{
    printf("\nObject - %s\nCoordinates of center - (%0.2f,%0.2f)\nRadius - "
           "%0.2f\n",
           cir,
           circleN.c1,
           circleN.c2,
           circleN.radius);
}

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

int coordsFind()
{
    int cirSize = 8;
    char inputStr[STRINGSIZE], nameObject[STRINGSIZE], coords[STRINGSIZE];
    char firstCenterCoord[COORDSIZE], secondCenterCoord[COORDSIZE],
            radius[COORDSIZE];
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
    float coord1 = charToFloat(firstCenterCoord);
    float coord2 = charToFloat(secondCenterCoord);
    float radiusF = charToFloat(radius);

    circleN.c1 = coord1;
    circleN.c2 = coord2;
    circleN.radius = radiusF;

    return 0;
}

int areaPerimeter()
{
    float perimeter = M_PI * 2 * circleN.radius;
    float area = circleN.radius * circleN.radius * M_PI;

    printf("Area = %0.2lf\nPerimeter = %0.2lf", area, perimeter);
    return 0;
}