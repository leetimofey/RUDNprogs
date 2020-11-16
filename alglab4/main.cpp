//Ли Тимофей НФИбд-01-18
#include <iostream>
#include <cmath>
using namespace std;

const int LEN=10;

class Mas{
	int mas[LEN];
	public:
	void enter();
	void print();
	void minlocalmax();
	void numsofequal();
};
void Mas::enter(){
 	cout<<"Введите элементы массива:"<<endl;
 	for(int i=0;i<LEN;i++){
 		cin>>mas[i];
 	}
}
void Mas::print(){
	cout<<"Массив:"<<endl;
	for(int i=0;i<LEN;i++){
 		cout<<mas[i]<<" ";
 	}
 	cout<<endl;
}
void Mas::minlocalmax(){
	cout<<"Задача 19(минимальный локальный максимум)."<<endl;
	int minmax=1000000;
	for(int i=1;i<LEN-1;i++){
		if (mas[i]>mas[i-1] && mas[i]>mas[i+1] && mas[i]<minmax){
			minmax=mas[i];
		}
	}
	//if(mas[1]<mas[0] && mas[0]<minmax){
	//	minmax=mas[0];
	//}
	//if(mas[LEN-2]<mas[LEN-1] && mas[LEN-1]<minmax){
	//	minmax=mas[LEN-1];
	//}
	if(minmax==1000000){
		cout<<"Локального максимума нет"<<endl;
	}
	else{
		cout<<"Минимальный локальный максимум: "<<minmax<<endl;
	}
}
void Mas::numsofequal(){
	cout<<"\nЗадача 44(вывести номера единственных двух одинаковых элементов)."<<endl;
	int ifno=0;
	for(int i=0;i<LEN-1;i++){
		for(int j=i+1;j<LEN;j++){
			if(mas[i]==mas[j]){
				ifno+=1;
				if(ifno>1){
					cout<<"В массиве больше одной пары одинаковых элементов!"<<endl;
					exit(1);
				}
				cout<<"Индексы равных элементов: "<<i<<" "<<j<<endl;
			}
		}
	}
	if(ifno==0){
		cout<<"В массиве нет ни одной пары одинаковых элементов!"<<endl;
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	Mas obj;
	obj.enter();
	obj.print();
	obj.minlocalmax();
	obj.numsofequal();
	return 0;
}
