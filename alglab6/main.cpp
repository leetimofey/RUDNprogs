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
	void indsum(int k, int l);
	void amountofsame();
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
void Mas::indsum(int k, int l){
	cout<<"Задача 15(вывести сумму элементов с индексом от K до L включительно и их количество)."<<endl;
	int amount=0;
	int sum=0;
	if(k<0 || l>LEN-1){
		cout<<"Границы выходят за массив"<<endl;
		return;
	}
	for(int i=k;i<=l;i++){
		sum+=mas[i];
		amount+=1;
	}
	cout<<sum<<endl;
	cout<<amount<<endl;
}
void Mas::amountofsame(){
	cout<<"\nЗадача 40(вывести количество одинаковых и разных элементов отсортированного массива)."<<endl;
	int kolvorazn=1, kolvosame=0;
	int check=0;
	for (int i=0;i<LEN-1;i++){
		if(mas[i]<mas[i+1]){
			check=1;
		}
		if(mas[i]>mas[i+1]){
			check=-1;
		}
	}
	for(int k=0;k<LEN-1;k++){
		if(check==1 && mas[k]>mas[k+1]){
			cout<<"Массив неотсортированный"<<endl;
			return;
		}
		else if(check==-1 && mas[k]<mas[k+1]){
			cout<<"Массив неотсортированный"<<endl;
			return;
		}
	}
	for(int j=1;j<LEN;j++){
		if(mas[j-1]!=mas[j]){
			kolvorazn+=1;
		}
		else{
			kolvosame+=1;
		}
	}
	cout<<"Количество разных и количество одинаковых элементов: "<<kolvorazn<<" "<<kolvosame<<endl;
}
int main() {
	int k,l;
	setlocale(LC_ALL, "Russian");
	Mas obj;
	obj.enter();
	obj.print();
	cout<<"Введите индексы для подсчета суммы:"<<endl;
	cin>>k;
	cin>>l;
	obj.indsum(k,l);
	obj.amountofsame();
	return 0;
}
