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
	void progression();
	void ifsum(int r);
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
void Mas::progression(){
	cout<<"Задача 19(если массив - арифметическая прогрессия, вывести сумму и разность (иначе 0))."<<endl;
	int razn=mas[1]-mas[0];
	int sum=0;
	for(int i=2;i<LEN;i++){
		if((mas[i]-mas[i-1])!=razn){
			cout<<"Массив не является арифметической прогрессией"<<endl<<0<<endl;
			return;
		}
	}
	for(int j=0;j<LEN;j++){
		sum+=mas[j];
	}
	cout<<"Массив является арифметической прогрессией"<<endl<<"Сумма: "<<sum<<endl<<"Разность: "<<razn<<endl;
}
void Mas::ifsum(int r){
	cout<<"\nЗадача 44(поиск соседних элементов с суммой наиболее близкой к числу)."<<endl;
	int minrazn, indexmin;
	minrazn=1000000;
	for (int i=0;i<LEN-1;i++){
		if(abs(mas[i]+mas[i+1]-r)<minrazn){
			minrazn=abs(mas[i]+mas[i+1]-r);
			indexmin=i;
		}
	}
	cout<<"Соседние элементы с суммой наиболее близкой к r: "<<mas[indexmin]<<" "<<mas[indexmin+1]<<endl;
}
int main() {
	int r;
	setlocale(LC_ALL, "Russian");
	Mas obj;
	obj.enter();
	obj.print();
	obj.progression();
	cout<<"Введите число для сравнения:"<<endl;
	cin>>r;
	obj.ifsum(r);
	return 0;
}
