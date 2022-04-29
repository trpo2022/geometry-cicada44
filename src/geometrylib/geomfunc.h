#pragma once

struct circle {
    float c1;
    float c2;
    float radius;
};

int isOpnBracket(char* arr);
int isClsBracket(char* arr, int cnt);
int isCorrectCntComma(char* arrCoords);
struct circle coordsFind();
int printAreaPerimeter(struct circle C);
void printCoords(struct circle C);
float charToFloat(char* c1);
float perimeter(float radius);
float area(float radius);
int isintersection(struct circle c1, struct circle c2);
void manysircles();