#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int n, max, i, a, k;
	printf("Input n, then n numbers\n");
	scanf("%d",&n);
	scanf("%d",&max);
	i=0;
	k=1;
	for (i=2;i<=n;i++){
		scanf("%d",&a);
		if (a==max){
			k++;
		}
		if (a>max){
			max=a;
			k=1;
		}
	}
	printf("Amount of max: ");
	printf("%d",k);
	return 0;
}
