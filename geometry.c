#include <stdio.h>
#include <ctype.h>

struct Point{
	int x;
	int y;
};

struct Circle{
	struct Point;
	int o;
};

int isOpnBracket(char *arr, int c){
	for (int c=0; c<20; c++) if (arr[c]=='(') return c;
	return 0;
}

int isClsBracket(char *arr, int cnt){
	for (int x=cnt; x<20; x++) if (arr[x]==')') return x;
	return 0;
}

int isCorrectName(char *nameObject, char *cir){
	for (int x=0; x<7; x++){
		if (nameObject[x]!=cir[x] && toupper(nameObject[x])!=cir[x] && tolower(nameObject[x])!=cir[x]){
			return 0;
		}
	}
	return 1;
}

int isCorrectCntComma(char *arrCoords){
	unsigned short commaCnt;
	for (int x=0; x<20; x++) if (arrCoords[x]==',') commaCnt++;
	if (commaCnt==2) return 1;
	return 0;
}

int main(){
	struct Circle c1;
	char inputStr[20], nameObject[20], coords[20];
	char cir[]="circle\0";
	int t, j=0, k=0, i=0;

	printf("Input the case\n1-stdin input\t2-file input\n");
	scanf("%d", &t);

	switch(t){
		case 1:
			scanf("%s", inputStr);
			int opnBrCheck = isOpnBracket(inputStr, j);
			int clsBrCheck = isClsBracket(inputStr, j);
			if (opnBrCheck && clsBrCheck && clsBrCheck>opnBrCheck) {
				while(inputStr[k]!='('){
					nameObject[k] = inputStr[k];
					k++;
				}
				while(inputStr[k+1]!=')'){
					coords[i] = inputStr[k+1];
					i++;
					k++;
				}
			}
			else{
				printf("[ERROR] - Problem with brackets");
				break;
			}
			int correctNameCheck = isCorrectName(nameObject, cir);
			if (correctNameCheck==0){
				printf("[ERROR] - Problems with object name");
				break;
			}
			int correctCntCommaCheck = isCorrectCntComma(coords);
			if (correctCntCommaCheck==0){
				printf("[ERROR] - Too many or too few arguments");
				break;
			}
			
		case 2:
			
	}

	return 0;
}
