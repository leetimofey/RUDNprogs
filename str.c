#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char c;
	char s;
	int k;
	printf("Input string:\n");
	while ((c=getchar())!='.'){
		if (c!=43){
			printf("%c",c);
		}
		if (c==43){
			s=getchar();
			if (s>=48 && s<=57){
				printf("%c",s);
			}
			if (s!=43){
				printf("%c",c);
				printf("%c",s);
			}
			else{
				printf("%c",c);
			}
		}
		c=s;
	}
	printf(".");
	return 0;
}
