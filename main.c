#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int n, m, i, a;
	printf("Input n, then n numbers\n");
	scanf("%d",&n);
	scanf("%d",&m);
	i=2;
	while (i<=n) {
		scanf("%d",&a);
		if (a>m)
			m=a;
		i++;
	}
	printf("Maximum is: ");
	printf("%d",m);
	return 0;
}
