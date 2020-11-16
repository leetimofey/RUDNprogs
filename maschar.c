#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int bukv(int x, int y){
	int k, i;
	k=y-x+1;
	char l[k];
	for (i=0; i<k; i++){
		l[i]=x+i;
		printf("%c ",l[i]);
	}
	printf("\n");
	return 0;
}
int main(int argc, char *argv[]) {
	char r, t, m;
	r='a';
	t='z';
	bukv(r, t);
	r='A';
	t='Z';
	bukv(r, t);
	return 0;
}
