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

int objNameCheck(char *arr, char *cir){
	for (int x=0; x<7; x++){
		if (nameObject[x]!=cir[x] && toupper(nameObject[x])!=cir[x] && tolower(nameObject[x])!=cir[x]){
			return 0;
		}
	}
	return 1;
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
			isCorrectName = objNameCheck(nameObject, cir);
			if (isCorrectName==0){
				printf("[ERROR] - Problems with object name");
			}
			short commaCnt = 0;
			for (int x=0; x<20; x++) if (coords[x]==',') commaCnt++
			
		case 2:
			
	}

	return 0;
}
