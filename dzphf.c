#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char c, s;
	int k;
	printf("Input string:\n");
	c=getchar();
	printf("Changed string:\n");
	while ((s=getchar())!='.'){
		if (c=='p' && s=='h'){
			printf("f");
			c=getchar();
			k=0;
		}
		else{
			printf("%c",c);
			c=s;
			k=1;
		}
		}
	if (k==1){
		printf("%c",c);
		printf("%c",s);
	}
	if ((k==0) && (s=='.')){
		printf("%c",c);
		printf("%c",s);
		
	}
	return 0;
}
