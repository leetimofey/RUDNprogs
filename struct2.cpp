#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct tovar{
	std::string name;
	int cost;
	int amount;
	tovar* next;
};
void addfirst(tovar **head, string name, int cost, int amount){
	tovar* newtovar= new tovar;
	newtovar->name=name;
	newtovar->cost=cost;
	newtovar->amount=amount;
	newtovar->next=*head;
	*head=newtovar;
}
int main(int argc, char** argv) {
	string name;
	int cost,amount;
	tovar carrot = {"Carrot", 11, 2, NULL};
	tovar apple = {"Apple", 10, 3, &carrot};
	tovar* head=&apple;
	cout<<"Enter name: ";
	cin>>name;
	cout<<"Enter cost: ";
	cin>>cost;
	cout<<"Enter amount: ";
	cin>>amount;
	addfirst(&head,name,cost,amount);
	tovar* k=head;
	while(k){
		cout<<"Name: "<<k->name<<"\tCost: "<<k->cost<<"\tAmount: "<<k->amount<<endl;
		k=k->next;
	}
	return 0;
}
