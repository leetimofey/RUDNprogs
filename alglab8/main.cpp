//Ли Тимофей НФИбд-01-18
#include <iostream>
#include <cmath>
using namespace std;

const int LEN=4;
const int WIDTH=4;

class Mas{
	int mas[LEN][WIDTH];
	public:
	void enter();
	void print();
	void maxeven(int k);
	void switchmaxmin(int k);
};
void Mas::enter(){
 	cout<<"Введите элементы массива:"<<endl;
 	for(int i=0;i<LEN;i++){
 		for(int j=0;j<WIDTH;j++){
 			cin>>mas[i][j];
		}
 	}
}
void Mas::print(){
	cout<<"Массив:"<<endl;
	for(int i=0;i<LEN;i++){
		for(int j=0;j<WIDTH;j++){
			cout<<mas[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Mas::maxeven(int k){
	cout<<"Задача 14(вывести k-й столбец и максимальный четный элемент в нем)."<<endl;
	int maxev=-1000000;
	if (k<0 || k>=WIDTH){
		cout<<"Такого столбца нет."<<endl;
		return;
	}
	else{
		for(int i=0;i<LEN;i++){
			cout<<mas[i][k]<<endl;
			if (mas[i][k]%2==0 && mas[i][k]>maxev){
				maxev=mas[i][k];
			}
		}
		if (maxev!=-1000000){
			cout<<"Максимальный четный элемент столбца: "<<maxev<<endl;
		}
		else{
			cout<<"Четных элементов в столбце нет."<<endl;
		}
	}
}
void Mas::switchmaxmin(int k){
	cout<<"Задача 39(поменять местами максимум и минимум в k-й строке и вывести их среднее и строку)."<<endl;
	int indmax,indmin;
	int max=-1000000;
	int min=1000000;
	if (k<0 || k>=LEN){
		cout<<"Такой строки нет."<<endl;
		return;
	}
	else{
		for(int i=0;i<WIDTH;i++){
			if(mas[k][i]<min){
				min=mas[k][i];
				indmin=i;
			}
			if(mas[k][i]>max){
				max=mas[k][i];
				indmax=i;
			}
		}
		mas[k][indmax]=min;
		mas[k][indmin]=max;
		cout<<"Измененная строка:"<<endl;
		for(int j=0;j<WIDTH;j++){
			cout<<mas[k][j]<<" ";
		}
		cout<<endl;
		cout<<"Среднее арифметическое максимума и минимума: "<<(float(max)+float(min))/2<<endl;
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	Mas obj;
	int k,n;
	obj.enter();
	obj.print();
	cout<<"Введите номер столбца"<<endl;
	cin>>k;
	obj.maxeven(k);
	cout<<"Введите номер строки"<<endl;
	cin>>n;
	obj.switchmaxmin(n);
	return 0;
}
