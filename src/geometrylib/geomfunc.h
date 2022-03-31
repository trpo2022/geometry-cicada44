#pragma once

struct circle {
    float c1;
    float c2;
    float radius;
};

int isOpnBracket(char* arr);
int isClsBracket(char* arr, int cnt);
int isCorrectName(char* nameObject, char* cir, int cirSize);
int isCorrectCntComma(char* arrCoords);
int coordsFind();
int areaPerimeter();
void printCoords();
float charToFloat(char* c1);