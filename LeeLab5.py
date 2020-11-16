import math
from math import *
def func_y(x):
    return exp(2*x**3/3)#функция y(x), посчитанная аналитически

def Eiler(a,b,n,masx):
    eN=[0]*5000
    eN[0]=1
    c=(b-a)/n
    for i in range (1,n+1):
        eN[i]=eN[i-1]+c*(2*masx[i-1]*masx[i-1]*eN[i-1])#14 вариант, f(x,y)=2*x^2*y
    return eN

def RungeKutta(a,b,n,masx):
    masRK=[0]*5000
    masRK[0]=1
    с=(b-a)/n
    for i in range(1,n+1):
        masRK[i]=masRK[i-1]+(с/2)*(2*masx[i-1]*masx[i-1]*masRK[i-1]+2*(masx[i-1]+с)*(masx[i-1]+с)*(masRK[i-1]+с*2*masx[i-1]*masx[i-1]*masRK[i-1]))
    return masRK

def mas_x(a,b,n):
    masx=[0]*5000
    masx[0]=a
    с=(b-a)/n
    for i in range(1,n+1):
        masx[i]+=masx[i-1]+с  
    return masx

def mas_y(masx,n):
    masy=[0]*5000
    for i in range(0,n+1):
        masy[i]=func_y(masx[i])
    return masy

def maxDelta(yE, y, N):
    maxS=abs(yE[0]-y[0])
    for i in range(1,N+1):
        if maxS<abs(yE[i]-y[i]):
            maxS=abs(yE[i]-y[i])
    return maxS

a=0 #левый конец отрезка [a,b]
b=pow(3/2,1/3) #правый конец отрезка [a,b]
N=int(input("Введите N (на сколько частей разбивается отрезок): "))
x=mas_x(a,b,N)
y=mas_y(x,N)
yE=RungeKutta(a,b,N,x)
for i in range(N+1):
    print("x[",i,"] = %.8f"%x[i]," yE[",i,"] = %.8f"%yE[i]," y[",i,"] = %.8f"%y[i]," delta[",i,"] = %.8f"%abs(yE[i]-y[i]))

#Поиск минимального N для метода Рунге-Кутта, удовлетворяющего условию(<0.01)
p=3
x1=mas_x(a,b,p)
y1=mas_y(x1,p)
yE1=RungeKutta(a,b,p,x1)
maxD=maxDelta(yE1,y1,p)
while maxD>=0.01:
    p+=1
    x1=mas_x(a,b,p)
    y1=mas_y(x1,p)
    yE1=RungeKutta(a,b,p,x1)    
    maxD=maxDelta(yE1,y1,p)
print("\nПри N = ",p," для метода Рунге-Кутта погрешность удовлетворяет условию(<0.01)","\nПроверка:")
N=p
masx=mas_x(a,b,N)
masy=mas_y(masx,N)
yEN=RungeKutta(a,b,N,masx)
for i in range(N+1):
    print("x[",i,"] = %.8f"%masx[i]," yE[",i,"] = %.8f"%yEN[i]," y[",i,"] = %.8f"%masy[i]," sigma[",i,"] = %.8f"%abs(yEN[i]-masy[i]))  

#Поиск минимального N для метода Эйлера, удовлетворяющего условию (< 0.01)
p=3
x2=mas_x(a,b,p)
y2=mas_y(x2,p)
yE2=Eiler(a,b,p,x2)
maxD=maxDelta(yE2,y2,p)
while maxD>=0.01:
    p+=1
    x2=mas_x(a,b,p)
    y2=mas_y(x2,p)
    yE2=Eiler(a,b,p,x2)    
    maxD=maxDelta(yE2,y2,p)
print("\nПри N = ",p," для метода Эйлера погрешность удовлетворяет условию(<0.01)","\nПроверка:")
N=p
masx=mas_x(a,b,N)
masy=mas_y(masx,N)
yEN=Eiler(a,b,N,masx)
for i in range(N+1):
    print("x[",i,"] = %.8f"%masx[i]," yE[",i,"] = %.8f"%yEN[i]," y[",i,"] = %.8f"%masy[i]," sigma[",i,"] = %.8f"%abs(yEN[i]-masy[i]))