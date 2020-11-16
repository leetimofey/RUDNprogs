//�� ������� �����-01-18
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
	//cout<<"������� ����� �������:"<<endl;
 	//cin>>len;
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
void Mas::sredn(int k, int l){
	cout<<"������ 24(������� ������� ��������� ����� �� k-�� �� l-��)."<<endl;
	if(k<0 || l>LEN-1 || k>l){
		cout<<"������������ �������"<<endl;
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
		cout<<"������� �������������� ��������� ����� �� k-�� �� l-��: "<<sr<<endl;
	}
}
void Mas::endwith(int n){
	cout<<"������ 49(������� ����� ������ �� ���������, �������������� �� ����� n)."<<endl;
	int mas2[LEN];
	int check=0;
	if(n<0 || n>9){
		cout<<"�� ����� �� �����"<<endl;
		return;
	}
	else{
		for(int i=0;i<LEN;i++){
			if(abs(mas[i]%10)==n){
				mas2[check]=mas[i];
				check+=1;
			}
		}
		cout<<"������ ���������, �������������� �� n"<<endl;
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
	cout<<"������� �����, 0<=k<=l<=10:"<<endl;
	cin>>k;
	cin>>l;
	obj.sredn(k, l);
	cout<<"������� ����� n:"<<endl;
	cin>>n;
	obj.endwith(n);
	return 0;
}
