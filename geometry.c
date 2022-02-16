#include <stdio.h>

struct Point{
	int x;
	int y;
};

struct Circle{
	struct Point;
	int o;
};

int isBracket(char *arr){
	for (int x=0; x<20; x++) if (arr[x]=='(') return 1;
	return 0;
}

int main(){
	char inputStr[20];
	struct Circle c1;
	int t;
	char nameObject[20];
	char coords[20];
	int j=0, k=0;
	char cir[]="circle\0";

	printf("Input the case\n1-stdin input\t2-file input\n");
	scanf("%d", &t);

	switch(t){
		case 1:
			scanf("%s", inputStr);
			int brCheck = isBracket(inputStr);
			if (brCheck==1) {
				while(inputStr[j]!='('){
					nameObject[k] = inputStr[j];
					k++;
					j++;
				}
			}
			else {
				printf("Missing the openbracket");
			}
			printf("%s", nameObject);
			
		case 2:
			
	}

	return 0;
}
