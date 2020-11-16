#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n, m;
	FILE *fp;
	int *mas;
	if ((fp = fopen("pr1.dat","r"))==NULL){
		perror("pr1.dat");
		return 1;
	}
	fscanf(fp,"%d",&n);
	fscanf(fp,"%d",&m);
	mas = new int [n];
	for (int i=0; i<n; i++){
		mas[i]= int [m];
	}
	for (i=0; i<n; i++){
		for (int j=0; j<m; j++){
			fscanf(fp, "%d", &mas[i][j]);
		}
	}
	for (i=0; i<n; i++){
		for (j=o; j<m; j++){
			printf("%d ", mas[i][j]);
			if (j==(m-1)){
				printf("\n");
			}
		}
	}
	//int *vect = fun(mas,n,m);
	return 0;
}
//int* fun(int **a, int n, int m){
//	int *v = new int[m];
//	return v;
//}
