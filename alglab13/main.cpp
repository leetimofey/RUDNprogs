//Ли Тимофей НФИбд-01-18
#include <iostream>
#include <cmath>
using namespace std;


class Mas{
	int* x;
	public:
	void createarray(int n, int** A, int** B);
	void print(int n);
};
void Mas::createarray(int n, int** A, int** B){
	int a[n], b[n];
	x = new int[n];
	int maxa=-1000000, maxb=-1000000;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(A[i][j]>maxa){
				maxa=A[i][j];
			}
			if(B[i][j]>maxb){
				maxb=B[i][j];
			}
		}
		if(maxa>maxb){
			x[i]=1;
		}
		else{
			x[i]=0;
		}
		maxa=-1000000;
		maxb=-1000000;
	}
}

void Mas::print(int n){
	for(int i=0;i<n;i++){
		cout<<x[i]<<" ";
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	Mas obj;
	int n;
	cout<<"Введите размерность матриц:"<<endl;
	cin>>n;
	int** A= new int*[n];
	int** B= new int*[n];
	cout<<"Введите элементы матрицы А:"<<endl;
	for(int i=0;i<n;i++){
		A[i]=new int[n];
		for(int j=0;j<n;j++){
			cin>>A[i][j];
		}
	}
	cout<<"Введите элементы матрицы В:"<<endl;
	for(int k=0;k<n;k++){
		B[k]=new int[n];
		for(int l=0;l<n;l++){
			cin>>B[k][l];
		}
	}
	cout<<"Матрица А:"<<endl;
	for(int c=0;c<n;c++){
		for(int d=0;d<n;d++){
			cout<<A[c][d]<<" ";
		}
		cout<<endl;
	}
	cout<<"Матрица B:"<<endl;
	for(int e=0;e<n;e++){
		for(int f=0;f<n;f++){
			cout<<B[e][f]<<" ";
		}
		cout<<endl;
	}
	cout<<"Массив Х:"<<endl;
	obj.createarray(n,A,B);
	obj.print(n);
	return 0;
}
