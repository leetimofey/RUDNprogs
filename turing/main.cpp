//Ли Тимофей НФИбд-01-18
#include <iostream>
#include <cmath>
using namespace std;

const int N=1024;

class turing{
    private:
        int* a;
        int* b;
    public:
        turing();    
        void enter();
        void print();
        void reverse();
        void inverse();  
        void mult();
};

turing::turing(){
    a=new int[N];
    b=new int[N];
}

void turing::enter(){
    cout<<"Введите последовательность: "<<endl;
    for (int i=0;i<N;i++){
        cin>>a[i];
        if (a[i]!=0 && a[i]!=1){
            cout<<"done"<<endl;
            break;    
        }
    }
}

void turing::print(){
	cout<<"result:"<<endl;
    for (int i=0; i<N; i++){
        if (b[i]==0 || b[i]==1){
            cout<<b[i]<<" ";
        } 
        else{
            cout<<endl;
            break;    
        }
    }
}

void turing::reverse(){
    int n;
    for (n=0;n<N && (a[n]==0 || a[n]==1) ;n++);
    for (int i=0;i<n;i++){
        b[i]=a[n-i-1];
    }
    b[n]=2;
}

void turing::inverse(){
    int n;
    for (n=0; n<N && (a[n]==0 || a[n]==1); n++){
        if (a[n]){
            b[n]=0;
        } 
        else{
            b[n]=1;    
        }
    }
    b[n]=2;
}

void turing::mult(){
    int n;
    for(n=0;n<N && (a[n]==0 || a[n]==1);n++);
    int sum=0;
    for (int i=n-1;i>=0;i--){
        if (a[i]==1){
			sum+=pow(2,n-1-i);
		}
    }
    sum=sum*sum;
    int c[N];
    int j=0;
    do{
    	c[j]=sum%2;
    	sum/=2;
    	j+=1;
    }while(sum!=0);
    c[j]=2;
    for(int k=0;k<N && (c[k]==0 || c[k]==1);k++){
    	j=k;
	};
    for(int l=0;l<N;l++){
    	b[l]=c[j-l];
	}
}

int main(){
    setlocale(LC_ALL,"Russian");
    turing obj;
    int k=1;
    obj.enter();
    while (k!=0){
        cout<<"Выберите номер функции: "<<endl<<"0 (закончить работу)"<<endl<<"1 (реверсия)"<<endl<<"2 (инверсия)"<<endl<<"3 (умножение)"<<endl<<"4 (поменять последовательность)"<<endl;
        cin>>k;
        switch (k){
            case 1:{
                obj.reverse();
                obj.print();
                break;
            }
            case 2:{
                obj.inverse();
                obj.print();
                break;
            }
            case 3:{
                obj.mult();
                obj.print();
                break;
            }
            case 4:{
                obj.enter();
                break;
            }
        }
    }
    cout<<"I've seen things you people wouldn't believe.\nAttack ships on fire off the shoulder of Orion.\nI watched C-beams glitter in the dark near the Tannhauser Gate.\nAll those moments will be lost in time, like tears in rain.\nTime to die.";
    return 0;
}
