//�� ������� �����-01-18
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	int N, M;
 	int i, k, s;
 	cout<<"������ 14 (������� �������� � ��������� ��������� � ������� ����������� �������, ����� �������� � ������� ��������� � �������� �������)"<<endl;
	cout<<"������� ����� �������:"<<endl;
 	cin>>N;
	int a[N];
 	cout<<"������� �������� �������:"<<endl;
 	for(i=0;i<N;i++){
 		cin>>a[i];
 	};
 	cout<<"����:"<<endl;
 	for(i=1;i<N;i+=2){
 		cout<<a[i]<<" ";
	};
	k=0;
	for(i=0;i<N;i+=2){
		k=i;
	};
	for(i=k;i>=0;i-=2){
		cout<<a[i]<<" ";
	};
	
	
	
	cout<<"\n\n������ 39 (����� ���������� ����������� ������������)"<<endl;
	cout<<"������� ����� �������:"<<endl;
 	cin>>M;
	int b[M];
 	cout<<"������� �������� �������:"<<endl;
 	for(i=0;i<M;i++){
 		cin>>b[i];
 	};
 	k=0;
 	s=3;
 	for(i=0;i<(M-1);i++){
 		if(b[i]>b[i+1]){
 			if(s!=0){
 				s=0;
 				k+=1;
			};
		};
		if(b[i]<b[i+1]){
 			if(s!=1){
 				s=1;
 				k+=1;
			};
		};
		if(b[i]==b[i+1]){
			s=-1;
		};
	};
	cout<<"������:"<<endl;
	for(i=0;i<M;i++){
 		cout<<b[i]<<" ";
 	};
	cout<<"\n���������� ����������� ������������:"<<endl;
	cout<<k<<endl;
	return 0;
};
