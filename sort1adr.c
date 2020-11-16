#include <stdio.h> 
#include <stdlib.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() { 
	int n, i, k, *max, *ind, *p, *p2, c; 
	printf("Input the length of array:\n");
	scanf("%d",&n);
	int a[n];
	printf("Input elements of array:\n");
	for (i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	for (i = n; i > 0; i--){
		max = a; 
		p2 = &a[i-1]; 
		for (k = 1, p = &a[k]; k < i; k++, p++){ 
			if (*p > *max){ 
				max = p; 
			} 
		} 
	c = *p2; 
	*p2 = *max; 
	*max = c; 
	} 
	printf("Sorted array:\n");
	for (i = 0, p = a; i < n; i++, p++){ 
		printf("%d ", *p);
	}

return 0; 
}
