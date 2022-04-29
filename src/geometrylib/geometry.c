#define _USE_MATH_DEFINES
#include <ctype.h>
#include <geometrylib/geomfunc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void printCoords(struct circle C)
{
    printf("\nObject - %s\nCoordinates of center - (%0.2f,%0.2f)\nRadius - "
           "%0.2f\n",
           cir,
           C.c1,
           C.c2,
           C.radius);
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

float area(float radius)
{
    float area = radius * radius * M_PI;
    return area;
}

float perimeter(float radius)
{
    float perimeter = M_PI * 2 * radius;
    return perimeter;
}

int printAreaPerimeter(struct circle C)
{
    float per = perimeter(C.radius);
    float ar = area(C.radius);

    printf("Area = %0.2lf\nPerimeter = %0.2lf", ar, per);
    return 0;
}

struct circle coordsFind()
{
    struct circle circ;
    char inputStr[STRINGSIZE], nameObject[STRINGSIZE], coords[STRINGSIZE];
    char firstCenterCoord[COORDSIZE], secondCenterCoord[COORDSIZE],
            radius[COORDSIZE];
    int j = 0, k = 0, i = 0;

    printf("\nInput the object\n");

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
        exit(-1);
    }
    int correctNameCheck = strcmp(nameObject, cir);
    if (correctNameCheck != 0) {
        printf("[ERROR] - Problems with object name\n");
        exit(-1);
    }
    int correctCntCommaCheck = isCorrectCntComma(coords);
    if (correctCntCommaCheck == 0) {
        printf("[ERROR] - Too many or too few arguments\n");
        exit(-1);
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

    circ.c1 = coord1;
    circ.c2 = coord2;
    circ.radius = radiusF;

    return circ;
}

void isintersection(struct circle c1, struct circle c2)
{
    float fint
            = sqrt((c2.c1 - c1.c1) * (c2.c1 - c1.c1)
                   + (c2.c2 - c1.c2) * (c2.c2 - c1.c2));
    if (fint <= (c1.radius + c2.radius))
        printf("The first two circles have instersection\n");
    else
        printf("The first two circles haven't instersection\n");
}

void manysircles()
{
    int nObjects;
    printf("How many odjects you want to input: ");
    do {
        scanf("%d", &nObjects);
    } while (getchar() != '\n');
    struct circle circls[nObjects];
    for (int x = 0; x < nObjects; x++) {
        circls[x] = coordsFind();
        printCoords(circls[x]);
        printAreaPerimeter(circls[x]);
        printf("\n");
    }
    printf("\n\n");
    if (nObjects >= 2)
        isintersection(circls[0], circls[1]);
}