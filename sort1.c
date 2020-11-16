#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n, i, p, m, j, x;
	printf("Input the length of array:\n");
	scanf("%d",&n);
	int a[n];
	printf("Input elements of array:\n");
	for (i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	for (x=n; x>0; x--){
		m=a[0];
		j=0;
		for (i=1; i<x; i++){
			if (a[i]>m){
				m=a[i];
				j=i;
			}
		}
		p=a[x-1];
		a[x-1]=m;
		a[j]=p;
	}
	printf("Sorted array:\n");
	for (i=0; i<n; i++){
		printf("%d ",a[i]);
	}
	return 0;
}
