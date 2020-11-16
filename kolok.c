#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int k, s, n, m;
	scanf ("%d",&n);
	m=n+1;
	s=0;
	while (m>0){
		k=m%10;
		if (k%2==0){
			s+=1;
		}
		m=m/10;
	}
	printf("%d",s);
	return 0;
}
