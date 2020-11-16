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
	void minlocalmax();
	void numsofequal();
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
void Mas::minlocalmax(){
	cout<<"������ 19(����������� ��������� ��������)."<<endl;
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
		cout<<"���������� ��������� ���"<<endl;
	}
	else{
		cout<<"����������� ��������� ��������: "<<minmax<<endl;
	}
}
void Mas::numsofequal(){
	cout<<"\n������ 44(������� ������ ������������ ���� ���������� ���������)."<<endl;
	int ifno=0;
	for(int i=0;i<LEN-1;i++){
		for(int j=i+1;j<LEN;j++){
			if(mas[i]==mas[j]){
				ifno+=1;
				if(ifno>1){
					cout<<"� ������� ������ ����� ���� ���������� ���������!"<<endl;
					exit(1);
				}
				cout<<"������� ������ ���������: "<<i<<" "<<j<<endl;
			}
		}
	}
	if(ifno==0){
		cout<<"� ������� ��� �� ����� ���� ���������� ���������!"<<endl;
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
