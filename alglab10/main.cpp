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
	void sredn(int k, int l);
	void endwith(int n);
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
void Mas::sredn(int k, int l){
	cout<<"Задача 24(считаем среднее элементов кроме от k-го до l-го)."<<endl;
	if(k<0 || l>LEN-1 || k>l){
		cout<<"Некорректные индексы"<<endl;
		return;
	}
	else{
		int sum=0;
		for(int i=0;i<k;i++){
			sum+=mas[i];
		}
		for(int j=l+1;j<LEN;j++){
			sum+=mas[j];
		}
		float sr=0.0;
		sr+=float(sum);
		sr=sr/(float(LEN-l+k-1));
		cout<<"Среднее арифметическое элементов кроме от k-го до l-го: "<<sr<<endl;
	}
}
void Mas::endwith(int n){
	cout<<"Задача 49(создать новый массив из элементов, оканчивающихся на цифру n)."<<endl;
	int mas2[LEN];
	int check=0;
	if(n<0 || n>9){
		cout<<"Вы ввели не цифру"<<endl;
		return;
	}
	else{
		for(int i=0;i<LEN;i++){
			if(abs(mas[i]%10)==n){
				mas2[check]=mas[i];
				check+=1;
			}
		}
		cout<<"Массив элементов, оканчивающихся на n"<<endl;
		for(int j=0; j<check; j++){
			cout<<mas2[j]<<" ";
		}
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	int k, l, n;
	Mas obj;
	obj.enter();
	obj.print();
	cout<<"Введите числа, 0<=k<=l<=10:"<<endl;
	cin>>k;
	cin>>l;
	obj.sredn(k, l);
	cout<<"Введите цифру n:"<<endl;
	cin>>n;
	obj.endwith(n);
	return 0;
}
