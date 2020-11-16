#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int s, x1, x2, n, i;
	s=0;
	x1=0;
	x2=0;
	printf("Input n:\n");
	scanf("%d",&n);
	for (i==0; i<=n; i++){
		s=s+(x1*x2);
		x1=x2;
		x2+=1;
	}
	printf("Answer is:\n%d",s);
	return 0;
}
