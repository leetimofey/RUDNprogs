#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

/*
Функция splitSegment делит отрезок [a,b] на равные части.
x - массив узлов
a - начало отрезка
b - конец отрезка
n - количество равных частей
*/

void splitSegment(double *x, double a, double b, int n){
    double part = (b-a)/n;
    x[0]=a;
    x[n]=b;
    for (int i=1; i<n; i++)
        x[i] = x[i-1] + part;
}

/*
Функция calculateValues рассчитывает значения функции f(x) в узлах.
x - массив узлов
y - массив значений функции
n - количество равных частей
*/

void calculateValues(double *x, double *y, int n){
    for (int i=0; i<=n; i++)
        y[i]=sqrt(sin(x[i])*sin(x[i])/(cos(x[i])*cos(x[i])+2));  
}

/*
Функция lagrangePolinomial считает значение полинома Лагранжа в точке z.
x - массив узлов
y - массив значений функции
n+1 - размер массивов x, y
z - точка отсчета полинома
*/

double lagrangePolinomial(double *x, double *y, int n, double z){
    double l=0; //для значения полинома Лагранжа
    double q; //для каждого отдельного полинома Q[i]
    
    for(int i=0; i<=n; i++){
        q = 1;//считаем новый Q[i]
    for(int j=0; j<=n; j++)
        if(j!=i)
            q=q*(z-x[j])/(x[i]-x[j]);
    
    l=l+y[i]*q;
    }    
    return l;
}

int main(){
    const int n=60; //количество разбиений отрезка [a,b]
    const int m=n*3;
    double a = 0; //начало отрезка
    double b = M_PI; //конец отрезка
    double *x = new double [n+1]; //узлы интерполяции
    double *y = new double [n+1]; //значения функции f(x) в узлах
    
    double *x_ = new double [m+1]; //точки при повторном разбиении   
    double *f = new double [m+1];
    double *l = new double [m+1];
    double *err = new double [m+1];
    
    splitSegment(x,a,b,n);
    calculateValues(x,y,n);
    splitSegment(x_,a,b,m);
    calculateValues(x_,f,m);
    
    for (int i=0; i<=m; i++){    
        l[i]=lagrangePolinomial(x,y,n,x_[i]);
        err[i]=abs(f[i]-l[i]);
    }
    
    cout<<fixed << setprecision (4);
    for (int i=0; i<=m; i++)
      cout<< setw (11) <<x_[i]<< setw (11)<< f[i] << setw (11) <<l[i]<< setw (11) << err[i] <<endl;

    return 0;
}
