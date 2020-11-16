#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for (i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	int k;
	for (i=0; i<n-1; i+=2){
		int *pi=&a[i];
		int *ppi=&a[i+1];
		k=*pi;
		*pi=*ppi;
		*ppi=k;
	}
	for (i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
