import math
from math import *

def direct_A(N,A): #прямой ход метода Гаусса для матрицы
    for k in range(N):
        for j in range(k+1,N):
            d=A[j][k]/A[k][k]
            for i in range(N):
                A[j][i]=A[j][i]-d*A[k][i]
    return A

def direct_b(N,A,b): #прямой ход метода Гаусса для правого столбца
    for k in range(N):
        for j in range(k+1,N):
            d=A[j][k]/A[k][k]
            b[j]=b[j]-d*b[k]
    return b

def direct_output(N,A,b): #прямой ход метода Гаусса 
    for i in range(N):
        for j in range(N):
            print("%.4f"%A[i][j],end="  ")
        print("    %.4f"%b[i])    

def back(N,A,b): #обратный ход метода Гаусса (решение СЛАУ)
    x=[0]*N
    for k in range(N-1,-1,-1):
        d=0
        for j in range(k+1,N):
            s=A[k][j]*x[j]
            d+=s
        x[k]=(b[k]-d)/A[k][k]
    return x

def mult(A,b,N): #умножение матрицы на вектор
    m=[0]*N
    for i in range(N):
        s=0
        for j in range(N):
            s+=A[i][j]*b[j]
        m[i]=s
    return m

def summ(a,b,N): #сумма векторов
    s=[0]*N
    for i in range(N):
        s[i]=a[i]+b[i]
    return s

def diff(a,b,N): #разность векторов
    d=[0]*N
    for i in range(N):
        d[i]=a[i]-b[i]
    return d

def euclid(a,N): #евклидова норма вектора (погрешность)
    s=0
    for i in range(N):
        s+=a[i]*a[i]
    return sqrt(s)
    
N=4
matrix_A=[[6*pi,4,1,1],[2,6*pi,3,1],[4,4,8*pi,2],[1,4,3,6*pi]]
vector_b=[4,8,2,8]

print("Матрица A и вектор b:")
for i in range(N):
    for j in range(N):
        print("%.4f"%matrix_A[i][j],end="  ")
    print("    %.4f"%vector_b[i])
    
A1=direct_A(N,matrix_A)
b1=direct_b(N,matrix_A,vector_b)

print("Верхний треугольник A и вектор b:")
direct_output(N,A1,b1)

print("Решение:")
x=back(N,matrix_A,vector_b)
for i in range(N):
    print("x[",i,"] = %.4f"%x[i])

m=mult(matrix_A,x,N)
d=diff(m,vector_b,N)
print("Евклидова норма: %.4f"%euclid(d,N))