import math
from math import *
def func_y(x):
    return exp(2*x**3/3) #������� y(x), ����������� ������������

def Eiler(a,b,n,masx):
    eN=[0]*(n+1)
    eN[0]=1
    c=(b-a)/n
    for i in range (1,n+1):
        eN[i]=eN[i-1]+c*(2*masx[i-1]*masx[i-1]*eN[i-1]) #14 �������, f(x,y)=2*x^2*y
    return eN

def mas_x(a,b,n):
    masx=[0]*(n+1)
    masx[0]=a
    c=(b-a)/N
    for i in range(1,N+1):
        masx[i]+=masx[i-1]+c
    return masx

def mas_y(masx,n):
    masy=[0]*(n+1)
    for i in range(0,N+1):
        masy[i]=func_y(masx[i])
    return masy

a=0 #����� ����� ������� [a,b]
b=pow(3/2,1/3) #������ ����� ������� [a,b]
N=int(input("������� N (�� ������� ������ ����������� �������): "))
x=mas_x(a,b,N)
y=mas_y(x,N)
yE=Eiler(a,b,N,x)
for i in range(N+1):
    print("x[",i,"] = %.8f"%x[i]," yE[",i,"] = %.8f"%yE[i]," y[",i,"] = %.8f"%y[i]," sigma[",i,"] = %.8f"%abs(yE[i]-y[i]))

#����� ������������ N, ���������������� ������� (< 0.01)
print("\n��� N=650 ����������� ������������� ������� (< 0.01)", "\n��������:")
N=650
masx=mas_x(a,b,N)
masy=mas_y(masx,N)
yEN=Eiler(a,b,N,masx)
for i in range(N+1):
    print("x[",i,"] = %.8f"%masx[i]," yE[",i,"] = %.8f"%yEN[i]," y[",i,"] = %.8f"%masy[i]," sigma[",i,"] = %.8f"%abs(yEN[i]-masy[i]))