#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int a, b, k, x;
	printf("Input a number:\n");
	scanf("%d",&a);
	b=0;
	k=0;
	x=a;
	while (a>0){
		k=a%10;
		a=a/10;
		b=b+k;
		b=b*10;
	}
	b=b/10;
	if (x==b){
		printf("Yes");
	}
	else{
		printf("No");
	}
	return 0;
}
