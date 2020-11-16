import math
from math import *
def func(x):
    return (x**2)*exp(x)

def mas_x(a,b,n):
    masx=[0]*(n+1)
    masx[0]=a
    c=(b-a)/n
    for i in range(1, n+1):
        masx[i]+=masx[i-1]+c  
    return masx

def mas_y(masx,n):
    masy=[0]*(n+1)
    for i in range(0, n+1):
        masy[i]=func(masx[i])
    return masy

def Leviy(masy,N,length):
    integral=0.0;
    for i in range(1, N+1):
        integral+=masy[i]
    return(integral*length)

def Praviy(masy,N,length):
    integral=0.0;
    for i in range(N):
        integral+=masy[i]
    return(integral*length)

def Trapecia(masy,N,length):
    integral=(masy[0]+masy[N])/2
    for i in range(1,N):
        integral+=masy[i]
    return(integral*length)

def Simpson(masy,N,length):
    integral=masy[0]+masy[N]
    for i in range (1,N):
        if((i%2)==1):
            integral+=4*masy[i]
        else:
            integral+=2*masy[i]
    return(integral*(length/3))

def Sheetprint(N,length,integral,masy):
    print("N=",N,"интеграл=",integral,"левый пр-к=",Leviy(masy,N,length),"правый пр-к=",Praviy(masy,N,length),"трапеция=",Trapecia(masy,N,length),"Симпсон=",Simpson(masy,N,length))
    
def MinLeviy(a,b,integral):
    res=1
    zLength=(b-a)/res
    x=mas_x(a,b,res)
    y=mas_y(x,res)
    while(abs(integral-Leviy(y,res,zLength))>=0.001):
        res+=1
        zLength=(b-a)/res
        x=mas_x(a,b,res)
        y=mas_y(x,res)
    return res

def MinPraviy(a,b,integral):
    res=1
    zLength=(b-a)/res
    x=mas_x(a,b,res)
    y=mas_y(x, res)
    while(abs(integral-Praviy(y,res,zLength))>=0.001):
        res+=1
        zLength=(b-a)/res
        x=mas_x(a,b,res)
        y=mas_y(x,res)
    return res

def MinTrapecia(a,b,integral):
    res=1
    zLength=(b-a)/res
    x=mas_x(a,b,res)
    y=mas_y(x, res)
    while(abs(integral-Trapecia(y,res,zLength))>=0.001):
        res+=1
        zLength=(b-a)/res
        x=mas_x(a,b,res)
        y=mas_y(x,res)
    return res

def MinSimpson(a,b,integral):
    res=1
    zLength=(b-a)/res
    x=mas_x(a,b,res)
    y=mas_y(x,res)
    while(abs(integral-Simpson(y,res,zLength))>=0.001):
        res+=1
        zLength=(b-a)/res
        x=mas_x(a,b,res)
        y=mas_y(x,res)
    return res

def Sheetres(a,b,integral):
    minLeviy=MinLeviy(a,b,integral)
    minPraviy=MinPraviy(a,b,integral)
    minTrapecia=MinTrapecia(a,b,integral)
    minSimpson=MinSimpson(a,b,integral)
    z=Leviy(mas_y(mas_x(a,b,minLeviy-2),minLeviy-2),minLeviy-2,(b-a)/(minLeviy-2))
    print("\n\nM-2=",minLeviy-2,"интеграл=",integral,"левый пр-к=",z,"|интеграл-левый|=",abs(integral-z))
    z=Leviy(mas_y(mas_x(a,b,minLeviy-1),minLeviy-1),minLeviy-1,(b-a)/(minLeviy-1))
    print("M-1=",minLeviy-1,"интеграл=",integral,"левый пр-к=",z,"|интеграл-левый|=",abs(integral-z))
    z=Leviy(mas_y(mas_x(a,b,minLeviy),minLeviy),minLeviy,(b-a)/(minLeviy))
    print("M=",minLeviy,"интеграл=",integral,"левый пр-к=",z,"|интеграл-левый|=",abs(integral-z))   
    z=Leviy(mas_y(mas_x(a,b,minLeviy+1),minLeviy+1),minLeviy+1,(b-a)/(minLeviy+1))
    print("M+1=",minLeviy+1,"интеграл=",integral,"левый пр-к=",z,"|интеграл-левый|=",abs(integral-z),"\n")
    
    z=Praviy(mas_y(mas_x(a,b,minPraviy-2),minPraviy-2),minPraviy-2,(b-a)/(minPraviy-2))
    print("M-2=",minPraviy-2,"интеграл=",integral,"правый пр-к=",z,"|интеграл-правый|=",abs(integral-z))
    z=Praviy(mas_y(mas_x(a,b,minPraviy-1),minPraviy-1),minPraviy-1,(b-a)/(minPraviy-1))
    print("M-1=",minPraviy-1,"интеграл=",integral,"правый пр-к=",z,"|интеграл-правый|=",abs(integral-z))
    z=Praviy(mas_y(mas_x(a,b,minPraviy),minPraviy),minPraviy,(b-a)/(minPraviy))
    print("M=",minPraviy,"интеграл=",integral,"правый пр-к=",z,"|интеграл-правый|=",abs(integral-z))   
    z=Praviy(mas_y(mas_x(a,b,minPraviy+1),minPraviy+1),minPraviy+1,(b-a)/(minPraviy+1))
    print("M+1=",minPraviy+1,"интеграл=",integral,"правый пр-к=",z,"|интеграл-правый|=",abs(integral-z),"\n")
                                                                            
    z=Trapecia(mas_y(mas_x(a,b,minTrapecia-2),minTrapecia-2),minTrapecia-2,(b-a)/(minTrapecia-2))
    print("M-2=",minTrapecia-2,"интеграл=",integral,"трапеция=",z,"|интеграл-трапеция|=",abs(integral-z))
    z=Trapecia(mas_y(mas_x(a,b,minTrapecia-1),minTrapecia-1),minTrapecia-1,(b-a)/(minTrapecia-1))
    print("M-1=", minTrapecia - 1, "интеграл=", integral, "трапеция=", z, "|интеграл-трапеция|=", abs(integral - z))
    z=Trapecia(mas_y(mas_x(a,b,minTrapecia),minTrapecia),minTrapecia,(b-a)/(minTrapecia))
    print("M=",minTrapecia,"интеграл=",integral,"трапеция=",z,"|интеграл-трапеция|=",abs(integral-z))   
    z=Trapecia(mas_y(mas_x(a,b,minTrapecia+1),minTrapecia+1),minTrapecia+1,(b-a)/(minTrapecia+1))
    print("M+1=",minTrapecia+1,"интеграл=",integral,"трапеция=",z,"|интеграл-трапеция|=",abs(integral-z),"\n")

    z=Simpson(mas_y(mas_x(a,b,minSimpson-4),minSimpson-4),minSimpson-4,(b-a)/(minSimpson-4))
    print("M-4=",minSimpson-4,"интеграл=",integral,"Симпсон=",z,"|интеграл-Симпсон|=",abs(integral-z))
    z=Simpson(mas_y(mas_x(a,b,minSimpson-2),minSimpson-2),minSimpson-2,(b-a)/(minSimpson-2))
    print("M-2=",minSimpson-2,"интеграл=",integral,"Симпсон=",z,"abs(integral - Simpson) = ",abs(integral-z))
    z=Simpson(mas_y(mas_x(a,b,minSimpson),minSimpson),minSimpson,(b-a)/(minSimpson))
    print("M=",minSimpson,"интеграл=",integral,"Симпсон=",z,"abs(integral - Simpson) = ",abs(integral-z))   
    z=Simpson(mas_y(mas_x(a,b,minSimpson+2),minSimpson+2),minSimpson+2,(b-a)/(minSimpson+2))
    print("M+2=",minSimpson+2,"интеграл=",integral,"Симпсон=",z,"abs(integral - Simpson) = ",abs(integral-z))
    
a=-1.0 
b=1.0 
N=int(input("Введите N (на сколько частей разбивается отрезок): "))
integral=0.8788846226018336 #значение определенного интеграла из условия
Sheetprint(N,(b-a)/N,integral,mas_y(mas_x(a,b,N),N))
Sheetprint(2*N,(b-a)/(2*N),integral,mas_y(mas_x(a,b,2*N),2*N))
Sheetprint(5*N,(b-a)/(5*N),integral,mas_y(mas_x(a,b,5*N),5*N))
Sheetprint(10*N,(b-a)/(10*N),integral,mas_y(mas_x(a,b,10*N),10*N))

Sheetres(a,b,integral)
