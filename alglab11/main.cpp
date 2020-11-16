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
	void progression();
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
void Mas::progression(){
	cout<<"������ 19(���� ������ - �������������� ����������, ������� ����� � �������� (����� 0))."<<endl;
	int razn=mas[1]-mas[0];
	int sum=0;
	for(int i=2;i<LEN;i++){
		if((mas[i]-mas[i-1])!=razn){
			cout<<"������ �� �������� �������������� �����������"<<endl<<0<<endl;
			return;
		}
	}
	for(int j=0;j<LEN;j++){
		sum+=mas[j];
	}
	cout<<"������ �������� �������������� �����������"<<endl<<"�����: "<<sum<<endl<<"��������: "<<razn<<endl;
}
void Mas::ifsum(int r){
	cout<<"\n������ 44(����� �������� ��������� � ������ �������� ������� � �����)."<<endl;
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
	obj.progression();
	cout<<"������� ����� ��� ���������:"<<endl;
	cin>>r;
	obj.ifsum(r);
	return 0;
}
