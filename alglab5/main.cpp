//�� ������� �����-01-18
#include <iostream>
#include <cmath>
using namespace std;

const int LEN=10;

class Mas{
	int mas[LEN];
	public:
	void enter();
	void print();
	void betw();
	void ifsum(int r);
};
void Mas::enter(){
 	cout<<"������� �������� �������:"<<endl;
 	for(int i=0;i<LEN;i++){
 		cin>>mas[i];
 	}
}
void Mas::print(){
	cout<<"������:"<<endl;
	for(int i=0;i<LEN;i++){
 		cout<<mas[i]<<" ";
 	}
 	cout<<endl;
}
void Mas::betw(){
	cout<<"������ 14(������� ������ ���������� ��������, ��������, ��� ������, � ��������, ��� ���������, � ������� ������������ ���� ��������� �� ����)."<<endl;
	int p=0;
	for(int i=1;i<LEN-1;i++){
		if(mas[i]>mas[0] && mas[i]<mas[LEN-1]){
			p=i;
		}
	}
	cout<<p<<endl;
	if (p!=0){
		int m=1;
		for(int j=0;j<=p;j++){
			m=m*mas[j];
		}
		cout<<m<<endl;
	}
	else{
		cout<<0<<endl;
	}
}
void Mas::ifsum(int r){
	cout<<"\n������ 39(����� �������� ��������� � ������ �������� ������� � �����)."<<endl;
	int minrazn, indexmin;
	minrazn=1000000;
	for (int i=0;i<LEN-1;i++){
		if(abs(mas[i]+mas[i+1]-r)<minrazn){
			minrazn=abs(mas[i]+mas[i+1]-r);
			indexmin=i;
		}
	}
	cout<<"�������� �������� � ������ �������� ������� � r: "<<mas[indexmin]<<" "<<mas[indexmin+1]<<endl;
}
int main() {
	int r;
	setlocale(LC_ALL, "Russian");
	Mas obj;
	obj.enter();
	obj.print();
	obj.betw();
	cout<<"������� ����� ��� ���������:"<<endl;
	cin>>r;
	obj.ifsum(r);
	return 0;
}
