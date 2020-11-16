#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int discr(a, b, c){
	int disc;
	float x1,x2;
	disc = b*b-4*a*c;
	if (disc>0){
		x1=(-b+sqrt(disc))/(2*a);
		x2=(-b-sqrt(disc))/(2*a);
		printf("x1=%f\n",x1);
		printf("x2=%f",x2);
		return 0;
	}
	if (disc==0){
		x1=x2=(-b/(2*a));
		printf("Korni sovpadayut\n");
		printf("x1=x2=%f",x1);
		return 0;
	}
	if (disc<0){
		printf("Korney net");
		return 0;
	}
}
int main(int argc, char *argv[]) {
	int a, b, c;
	printf("Vvedite koefficienty uravneniya ax^2+bx+c=0:\n");
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	printf("Uravneniye:\n");
	printf("%d*x^2 + %d*x + %d = 0\n",a,b,c);
	discr(a, b, c);
	return 0;
}
