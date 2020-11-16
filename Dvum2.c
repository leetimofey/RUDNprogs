#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, j, sum, m, n, l, p, q;
	printf("Input size of 1 matrix:\n");
	scanf("%d",&m);
	scanf("%d",&n);
	int mas[m][n];
	printf("Input elements of 1 matrix:\n");
	for (i=0; i<m; i++){
		for (j=0; j<n; j++){
			scanf("%d",&mas[i][j]);
			if (j==n-1){
				printf("\n");
			}
		}
	}
	
	printf("Input size of 2 matrix:\n");
	scanf("%d",&n);
	scanf("%d",&l);
	int mas2[n][l];
	printf("Input elements of 2 matrix:\n");
	for (i=0; i<n; i++){
		for (j=0; j<l; j++){
			scanf("%d",&mas2[i][j]);
			if (j==l-1){
				printf("\n");
			}
		}
	}
	
	int mas3[m][l];
	
	for (i=0; i<m; i++){
		for (j=0; j<l; j++){
			mas3[i][j]=0;
		}
	}
	
	for (i=0; i<m; i++){
		for (j=0; j<l; j++){
			for (p=0; p<n; p++){
				mas3[i][j]+=(mas[i][p]*mas2[p][j]);
			}
		}
	}
	
	printf("The matrix 1:\n");
	for (i=0; i<m; i++){
		for (j=0; j<n; j++){
			printf("%d ",mas[i][j]);
			if (j==n-1){
				printf("\n");
			}
		}
	}
	printf("\nThe matrix 2:\n");
	for (i=0; i<n; i++){
		for (j=0; j<l; j++){
			printf("%d ",mas2[i][j]);
			if (j==l-1){
				printf("\n");
			}
		}
	}
	printf("\nThe result m1*m2:\n");
	for (i=0; i<m; i++){
		for (j=0; j<l; j++){
			printf("%d ",mas3[i][j]);
			if (j==l-1){
				printf("\n");
			}
		}
	}
	return 0;
}
