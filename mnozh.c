#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int a, i, k, x;
	printf("Input a number:\n");
	scanf("%d",&a);
	printf("Prostie deliteli:\n");
	i=0;
	k=0;
	x=0;
	for (i=1;i<=a;i++){
		if (a%i==0){
			for (k=1;k<=i;k++){
				if (i%k==0){
					x+=1;
				}
			}
			if (x<=2){
				printf("%d\n",i);
			}
			x=0;
		}
	}
	return 0;
}
