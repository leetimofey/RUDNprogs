//�� ������� �����-01-18
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	int N, M;
 	int i, j, num, proisv, min, nummin;
 	cout<<"������ 14 (������� ����� ������� � ����������� ������������� ��������� � ���� ����������� ������������)"<<endl;
	cout<<"������� ����� �������:"<<endl;
 	cin>>N;
 	cout<<"������� ������ �������:"<<endl;
 	cin>>M;
 	int a[N][M];
 	cout<<"������� �������� �������:"<<endl;
 	for (i=0;i<N;i++){
 		for (j=0;j<M;j++){
 			cin>>a[i][j];
		};
	};
	min=1000000;
	proisv=1;
	for (j=0;j<M;j++){
		num=j;
 		for (i=0;i<N;i++){
 			proisv=proisv*a[i][j];
		};
		if(proisv<min){
			min=proisv;
			nummin=num;
		};
		proisv=1;
	};
	cout<<"�������:"<<endl;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	};
	cout<<"����� ������� � ����������� ������������� ���������:"<<endl;
	cout<<nummin+1<<endl;
	cout<<"������������ ��������� � ���� �������:"<<endl;
	cout<<min<<endl;
	
	
	
	cout<<"������ 39 (�������� ������� ������� � ������ �������� �������)"<<endl;
	cout<<"������� ����� �������:"<<endl;
 	cin>>N;
 	if(N%2==1){
 		cout<<"������. ����� ������ ���� ������."<<endl;
	}
	else{
		cout<<"������� ������ �������:"<<endl;
 		cin>>M;
 		int b[N][M];
 		cout<<"������� �������� �������:"<<endl;
 		for (i=0;i<N;i++){
 			for (j=0;j<M;j++){
 				cin>>b[i][j];
			};
		};
		cout<<"�������:"<<endl;
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				cout<<b[i][j]<<" ";
			};
			cout<<endl;
		};
		int verh[N][M];
		int niz[N][M];
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				niz[i][j]=0;
				verh[i][j]=0;
			};
		};
		for (i=0;i<N/2;i++){
			for(j=0;j<M;j++){
				verh[i+N/2][j]=b[i][j];
			};
		};
		for (i=N/2;i<N;i++){
			for(j=0;j<M;j++){
				niz[i-N/2][j]=b[i][j];
			};
		};
		for (i=0;i<N/2;i++){
			for(j=0;j<M;j++){
				b[i][j]=niz[i][j];
			};
		};
		for (i=N/2;i<N;i++){
			for(j=0;j<M;j++){
				b[i][j]=verh[i][j];
			};
		};
		cout<<"���������� �������:"<<endl;
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				cout<<b[i][j]<<" ";
			};
			cout<<endl;
		};
	};
 	
	return 0;
}
