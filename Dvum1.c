#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, j, sum, m, n, p, q;
	printf("Input size of matrix:\n");
	scanf("%d",&m);
	scanf("%d",&n);
	int mas[m][n];
	printf("Input elements of matrix:\n");
	for (i=0; i<m; i++){
		for (j=0; j<n; j++){
			scanf("%d",&mas[i][j]);
			if (j==n-1){
				printf("\n");
			}
		}
	}
	
	printf("The matrix:\n");
	for (i=0; i<m; i++){
		for (j=0; j<n; j++){
			printf("%d ",mas[i][j]);
			if (j==n-1){
				printf("\n");
			}
		}
	}
	
	printf("\nSumma vseh elementov:\n");
	sum=0;
	for (i=0; i<m; i++){
		for (j=0; j<n; j++){
			sum+=mas[i][j];
		}
	}
	printf("%d\n",sum);
	
	printf("\nSumma nad 2 diagonalyu:\n");
	sum=0;
	p=n;
	for (i=0; i<m; i++){
		for (j=0; j<p; j++){
			sum+=mas[i][j];
		}
		p-=1;
	}
	printf("%d\n",sum);
	
	printf("\nSumma 1 diagonali:\n");
	sum=0;
	for (i=0; i<m; i++){
		sum+=mas[i][i];
	}
	printf("%d\n",sum);
	
	printf("\nSumma 2 diagonali:\n");
	sum=0;
	for (i=0; i<m; i++){
		sum+=mas[i][n-i-1];
	}
	printf("%d\n",sum);
	
	printf("\nSumma verhnego treugolnika:\n");
	sum=0;
	p=n;
	q=0;
	for (i=0; i<m; i++){
		for (j=q; j<p; j++){
			sum+=mas[i][j];
		}
		p-=1;
		q+=1;
	}
	printf("%d\n",sum);
	
	printf("\nSumma levogo treugolnika:\n");
	sum=0;
	p=m;
	q=0;
	for (i=0; i<n; i++){
		for (j=q; j<p; j++){
			sum+=mas[j][i];
		}
		p-=1;
		q+=1;
	}
	printf("%d\n",sum);
	return 0;
}
