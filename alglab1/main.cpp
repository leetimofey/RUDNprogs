//Ли Тимофей НФИбд-01-18
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	int N, M;
 	int i, k, s;
 	cout<<"Задача 14 (вывести элементы с нечетными индексами в порядке возрастания индекса, затем элементы с четными индексами в обратном порядке)"<<endl;
	cout<<"Введите длину массива:"<<endl;
 	cin>>N;
	int a[N];
 	cout<<"Введите элементы массива:"<<endl;
 	for(i=0;i<N;i++){
 		cin>>a[i];
 	};
 	cout<<"Итог:"<<endl;
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
	
	
	
	cout<<"\n\nЗадача 39 (найти количество промежутков монотонности)"<<endl;
	cout<<"Введите длину массива:"<<endl;
 	cin>>M;
	int b[M];
 	cout<<"Введите элементы массива:"<<endl;
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
	cout<<"Массив:"<<endl;
	for(i=0;i<M;i++){
 		cout<<b[i]<<" ";
 	};
	cout<<"\nКоличество промежутков монотонности:"<<endl;
	cout<<k<<endl;
	return 0;
};
