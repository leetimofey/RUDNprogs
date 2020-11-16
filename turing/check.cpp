#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

const int N=1024;

class turing{
    private:
        int* a; //input
        int* b; //output
    public:
        turing();    
        void input();
        void output();
        void reverse();
        void inverse();  
        void multiplic();
};

turing::turing(){
    a=new int[N];
    b=new int[N];
}

void turing::input(){
    cout<<"Введите последовательность: "<<endl;
    for (int i=0; i<N; i++){
        cin>>a[i];
        if (a[i]!=0 && a[i]!=1){
            cout<<"Последовательность зафиксирована!"<<endl;
            break;    
        }
    }
}

void turing::output(){
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
    for (n=0; n<N && (a[n]==0 || a[n]==1) ; n++);
    
    for (int i=0; i<n; i++){
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

void turing::multiplic(){
    int n;
    for (n=0; n<N && (a[n]==0 || a[n]==1) ; n++);
    int k=0;
    
    for (int i=n-1; i>=0; i--){
        if (a[i]) k+=pow(2,i);
    }
    
    k*=k;
  
    bitset<128> bit=k;
    
    int i=127;
    while (bit[i]==0) i--;
    b[i+1]=2;
    int j=0;
    while (i>=0){
        b[j]=bit[i];
        i--;
        j++;
    }

}

int main(){
    setlocale(LC_ALL,"Russian");
    turing t;
    int k = 1;

    t.input();

    while (k!=0){
        
        cout<<"Укажите номер операции: "<<endl;
        cout<<"1.Реверс"<<endl;
        cout<<"2.Инверсия"<<endl;
        cout<<"3.Умножение"<<endl;
        cout<<"4.Изменить последовательность"<<endl;
        cout<<"0.Выход"<<endl;
        cin>>k;
    
        switch (k){
            case 1:{
                t.reverse();
                t.output();
                break;
            }
                
            case 2:{
                t.inverse();
                t.output();
                break;
            }
            
            case 3:{
                t.multiplic();
                t.output();
                break;
            }
            
            case 4:{
                t.input();
                break;
            }
        }
    }
    
    cout<<"Пока!";

    return 0;
}
