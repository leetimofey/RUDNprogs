#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int x, a, b, c, d, k;
	k=0;
	x=1000;
	for (x=1000; x<2\000; x++){
		a=x/1000;
		d=x%10;
		b=(x%1000)/100;
		c=(x%100)/10;
		if (a!=3 && b!=3 && c!=3 && d!=3){
			k+=0;
		}
		else{
			printf("%d\n",x);
		}
	}
	
	
}
