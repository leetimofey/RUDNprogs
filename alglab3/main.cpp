//Ли Тимофей НФИбд-01-18
#include <iostream>
#include <cmath>
using namespace std;

const int LEN=10;

class Mas{
	//int len;
	int mas[LEN];
	public:
	void enter();
	void print();
	void equal();
	void raznitsa();
};
void Mas::enter(){
	//cout<<"Введите длину массива:"<<endl;
 	//cin>>len;
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
void Mas::equal(){
	cout<<"Задача 17(проверяем, есть ли одинаковые элементы в массиве)."<<endl;
	int kolvequal=0;
	for(int i=0;i<LEN;i++){
		for(int j=0;j<LEN;j++){
			if (mas[i]==mas[j]&&i!=j){
				kolvequal+=1;
			}
		}
	}
	if (kolvequal==0){
		cout<<"Одинаковых элементов нет."<<endl;
	}
	else{
		cout<<"Одинаковые элементы есть."<<endl;
	}
}
void Mas::raznitsa(){
	cout<<"Задача 42(поиск соседних элементов с суммой наиболее близкой к числу)."<<endl;
	int chislo;
	cout<<"Введите число, с которым сравнивать(r):"<<endl;
	cin>>chislo;
	int minrazn, indexmin;
	minrazn=1000000;
	for (int i=0;i<LEN-1;i++){
		if(abs(mas[i]+mas[i+1]-chislo)<minrazn){
			minrazn=abs(mas[i]+mas[i+1]-chislo);
			indexmin=i;
		}
	}
	cout<<"Соседние элементы с суммой наиболее близкой к r: "<<mas[indexmin]<<" "<<mas[indexmin+1]<<endl;
}
int main() {
	setlocale(LC_ALL, "Russian");
	Mas obj;
	obj.enter();
	obj.print();
	obj.equal();
	obj.raznitsa();
	return 0;
}
