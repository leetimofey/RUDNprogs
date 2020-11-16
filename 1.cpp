#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

/*
������� splitSegment ����� ������� [a,b] �� ������ �����.
x - ������ �����
a - ������ �������
b - ����� �������
n - ���������� ������ ������
*/

void splitSegment(double *x, double a, double b, int n){
    double part = (b-a)/n;
    x[0]=a;
    x[n]=b;
    for (int i=1; i<n; i++)
        x[i] = x[i-1] + part;
}

/*
������� calculateValues ������������ �������� ������� f(x) � �����.
x - ������ �����
y - ������ �������� �������
n - ���������� ������ ������
*/

void calculateValues(double *x, double *y, int n){
    for (int i=0; i<=n; i++)
        y[i]=sqrt(sin(x[i])*sin(x[i])/(cos(x[i])*cos(x[i])+2));  
}

/*
������� lagrangePolinomial ������� �������� �������� �������� � ����� z.
x - ������ �����
y - ������ �������� �������
n+1 - ������ �������� x, y
z - ����� ������� ��������
*/

double lagrangePolinomial(double *x, double *y, int n, double z){
    double l=0; //��� �������� �������� ��������
    double q; //��� ������� ���������� �������� Q[i]
    
    for(int i=0; i<=n; i++){
        q = 1;//������� ����� Q[i]
    for(int j=0; j<=n; j++)
        if(j!=i)
            q=q*(z-x[j])/(x[i]-x[j]);
    
    l=l+y[i]*q;
    }    
    return l;
}

int main(){
    const int n=60; //���������� ��������� ������� [a,b]
    const int m=n*3;
    double a = 0; //������ �������
    double b = M_PI; //����� �������
    double *x = new double [n+1]; //���� ������������
    double *y = new double [n+1]; //�������� ������� f(x) � �����
    
    double *x_ = new double [m+1]; //����� ��� ��������� ���������   
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
