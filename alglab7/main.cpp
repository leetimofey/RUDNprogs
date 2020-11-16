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
	void masincludek(int k);
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
void Mas::masincludek(int k){
	int mas2[LEN];
	int check=0;
	int elem;
	for(int i=0; i<LEN; i++){
		elem=mas[i];
		if(elem==0){
			mas2[check]=mas[i];
			check+=1;
		}
		while(elem!=0 || elem!=elem/10){
			if(abs(elem%10)==k){
				mas2[check]=mas[i];
				check+=1;
				break;
			}
			elem=elem/10;
		}
	}
	cout<<"Массив элементов, содержащих цифру k"<<endl;
	for(int j=0; j<check; j++){
		cout<<mas2[j]<<" ";
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	Mas obj;
	int k;
	obj.enter();
	obj.print();
	obj.minlocalmax();
	cout<<"Введите цифру"<<endl;
	cin>>k;
	obj.masincludek(k);
	return 0;
}
