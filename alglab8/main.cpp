//�� ������� �����-01-18
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
 	cout<<"������� �������� �������:"<<endl;
 	for(int i=0;i<LEN;i++){
 		for(int j=0;j<WIDTH;j++){
 			cin>>mas[i][j];
		}
 	}
}
void Mas::print(){
	cout<<"������:"<<endl;
	for(int i=0;i<LEN;i++){
		for(int j=0;j<WIDTH;j++){
			cout<<mas[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Mas::maxeven(int k){
	cout<<"������ 14(������� k-� ������� � ������������ ������ ������� � ���)."<<endl;
	int maxev=-1000000;
	if (k<0 || k>=WIDTH){
		cout<<"������ ������� ���."<<endl;
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
			cout<<"������������ ������ ������� �������: "<<maxev<<endl;
		}
		else{
			cout<<"������ ��������� � ������� ���."<<endl;
		}
	}
}
void Mas::switchmaxmin(int k){
	cout<<"������ 39(�������� ������� �������� � ������� � k-� ������ � ������� �� ������� � ������)."<<endl;
	int indmax,indmin;
	int max=-1000000;
	int min=1000000;
	if (k<0 || k>=LEN){
		cout<<"����� ������ ���."<<endl;
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
		cout<<"���������� ������:"<<endl;
		for(int j=0;j<WIDTH;j++){
			cout<<mas[k][j]<<" ";
		}
		cout<<endl;
		cout<<"������� �������������� ��������� � ��������: "<<(float(max)+float(min))/2<<endl;
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	Mas obj;
	int k,n;
	obj.enter();
	obj.print();
	cout<<"������� ����� �������"<<endl;
	cin>>k;
	obj.maxeven(k);
	cout<<"������� ����� ������"<<endl;
	cin>>n;
	obj.switchmaxmin(n);
	return 0;
}
