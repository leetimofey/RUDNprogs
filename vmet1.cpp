//Тимофей Ли НФИбд-01-18

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void razbienieOtrezka(double *x, double n, double m, int k){
	double s=(m-n)/k;
	x[0]=n;
	x[k]=m;
	for (int i=1;i<k;i++){
		x[i]=x[i-1]+s;
	}
}

void znachenieF(double *x, double *f, int k){
	for(int i=0;i<k;i++){
		f[i]=sqrt(sin(x[i])*sin(x[i])/(cos(x[i])*cos(x[i])+2));
	}
}

double polinom(double *x, double *f, int k, double a){
	double polin=0;
	double p;
	for(int i=0;i<=k;i++){
		p=1;
		for(int j=0;j<=k;j++){
			if (j!=i){
				p=p*(a-x[j])/(x[i]-x[j]);
			}
		}
		polin+=f[i]*p;
	}
	return polin;
}

int main(){
	const int k=10;
    const int l=k*3;
    double n = 0; //начало отрезка
    double m = M_PI; //конец отрезка
    double *x = new double [k+1]; //узлы интерполяции
    double *f = new double [k+1]; //значения функции f(x) в узлах
    
    double *nx = new double [l+1]; //точки при повторном разбиении   
    double *a = new double [l+1];
    double *b = new double [l+1];
    double *error = new double [l+1];
    
    razbienieOtrezka(x,n,m,k);
    znachenieF(x,f,k);
    razbienieOtrezka(nx,n,m,l);
    znachenieF(nx,a,l);
    
    for(int i=0;i<=l;i++){    
        b[i]=polinom(x,f,k,nx[i]);
        error[i]=abs(a[i]-b[i]);
    }
    
    cout<<fixed<<setprecision(4);
    for(int i=0;i<=l;i++){
      cout<<nx[i]<<"	"<<a[i]<<"	"<<b[i]<<"	"<<error[i]<<endl;
	}
    return 0;
}
