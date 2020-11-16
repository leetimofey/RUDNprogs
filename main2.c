#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int a, b, x, y, z, p;
	printf("Input size of the hole:\n");
	scanf("%d",&a);
	scanf("%d",&b);
	printf("Input size of the brick:\n");
	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%d",&z);
	if(a>b){
        p = b;
        b = a;
        a = p;
    }
    if(x>y){
        p = y;
        y = x;
        x = p;
    }
    if(x>z){
        p = z;
        z = x;
        x = p;
    }
    if(y>z){
        p = z;
        z = y;
        y = p;
    }
    if (a>=x && b>=y){
    	printf("Yes, you can");
	}
	else{
		printf("No, you can't");
	}
	return 0;
}
