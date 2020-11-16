#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int fun(int *a, int m){
	int max;
	int i;
	max=a[0];
	for (i=1; i<m; i++){
		if (a[i]>max){
			max=a[i];
		}
	}
	return max;
}
int main(int argc, char *argv[]) {
	int n, m, i, j;
	FILE *fp;
	int **mas;
	if ((fp = fopen("pr1.dat","r"))==NULL){
		perror("pr1.dat");
		return 2;
	}
	fscanf(fp,"%d",&n);
	fscanf(fp,"%d",&m);
	mas = new int *[n];
	for (i=0; i<n; i++){
		mas[i]= new int [m];
	}
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			fscanf(fp, "%d", &mas[i][j]);
		}
	}
	printf("Vash massiv:\n");
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			printf("%d ", mas[i][j]);
			if (j==(m-1)){
				printf("\n");
			}
		}
	}
	printf("Maksimumy strok:\n");
	int vect;
	for (i=0; i<n; i++){
		vect=fun(mas[i], m);
		printf("%d ",vect);
	}
	return 0;
}
