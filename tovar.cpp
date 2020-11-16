#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct tovar {
	string name;
	float price;
	int amount;
	tovar* next;
};



void addfirst(tovar **head, string name, int price, int amount){
	tovar* newtovar= new tovar;
	newtovar->name=name;
	newtovar->price=price;
	newtovar->amount=amount;
	newtovar->next=*head;
	*head=newtovar;
}

void printlist(tovar* k){
	while(k){
		cout<<"Name: "<<k->name<<"\tPrice: "<<k->price<<"\tAmount: "<<k->amount<<endl;
		k=k->next;
	}
}

void addlast(tovar **head, string name, int price, int amount){
	tovar* newtovar= new tovar;
	tovar* a=*head;
	while(a->next){
		a=a->next;
	}
	a->next=newtovar;
	newtovar->name=name;
	newtovar->price=price;
	newtovar->amount=amount;
	newtovar->next=NULL;
}

int addafter(){
}

int addbefore(){
}
 
//int printitem(){
//}

//int del (){
//}

int main() {
	tovar *head = NULL;
	int res,k,amount;
	string name, nameafter;
	int price;
	k=5;
	
	while(k!=0){
		 while(k!=0 && k!=1 && k!=2 && k!=3 && k!=4 && k!=6 && k!=7){
		 	cout<<" To add an item at the end of the list, enter 1; \nto add an item to the top of the list, enter 2;\nto delete an item, enter 3; \nto add after an item, enter 4; \nto add befor an item, enter 6; \nto find an item, enter 7;\nto exit,enter 0: ";
		 	cin>>k;
		 	cout<<"\n\n";
		 	
		 	if(k!=0 && k!=1 && k!=2 && k!=3 && k!=4 && k!=6 && k!=7){
		 		cout<<"Wrong code! \n\n";
		 		system ("pause");
		 	}
		 	
		 	else{
		 		switch(k){
		 			case 0:{
		 				break;
		 			}
					
		 			case 1:{
		 				cout<<"Enter the name of the product: ";
		 				cin>> name;
		 				cout<<"\n";
		 				
		 				cout<<"Enter the number of products: ";
		 				cin>> amount;
		 				cout<<"\n";
		 				
		 				
		 				cout<<"Enter the price of the product: ";
		 				cin>> price;
		 				cout<<"\n";
		 				
		 				addlast(&head, name, price, amount);
		 				printlist(head);
		 				k=5;
		 				break;
		 			}
		 			
		 			case 2:{
		 				cout<<"Enter the name of the product: ";
		 				cin>> name;
		 				cout<<"\n";
		 				
		 				cout<<"Enter the number of products: ";
		 				cin>> amount;
		 				cout<<"\n";
		 				
		 				
		 				cout<<"Enter the price of the product: ";
		 				cin>> price;
		 				cout<<"\n";
		 				
		 				addfirst(&head, name, price, amount);
		 				printlist(head);
		 				k=5;
		 				break;
		 			}
		 			
		 			case 3:{
		 				cout<<"Enter the name of the product you want to delete from the list: ";
		 				cin>> name;
		 				cout<<"\n";
		 				
		 				//res=del(buffet,name);
		 				
		 				if(res==1) cout<<"No match \n";
		 				if(res==0) printlist(head);
		 				if(res==2) cout<<"The list is empty \n";
		 				
		 				k=5;
		 				break;
		 			}

		 			case 4:{
		 				cout<<"Enter the name of the product, after which you want to add an item: ";
		 				cin>> nameafter;
		 				cout<<"\n";
		 				
		 				cout<<"Enter the name of the product: ";
		 				cin>> name;
		 				cout<<"\n";
		 				
		 				cout<<"Enter the number of products: ";
		 				cin>> amount;
		 				cout<<"\n";
		 				
		 				cout<<"Enter the price of the product: ";
		 				cin>> price;
		 				cout<<"\n\n";
		 				
		 				//res=addafter(buffet,name,price,amount);
		 				
		 				if(res==0) printlist(head);
		 				if(res==1) cout<<"No match \n";
		 				if(res==2) cout<<"The list is empty \n";
		 				
		 				k=5;
		 				break;
		 			}
		 			
		 			case 6:{
		 				cout<<"Enter the name of the product, before which you want to add an item: ";
		 				cin>> nameafter;
		 				cout<<"\n";
		 				
		 				cout<<"Enter the name of the product: ";
		 				cin>> name;
		 				cout<<"\n";
		 				
		 				cout<<"Enter the number of products: ";
		 				cin>> amount;
		 				cout<<"\n";
		 				
		 				cout<<"Enter the price of the product: ";
		 				cin>> price;
		 				cout<<"\n\n";
		 				
		 				//res=addbefore(buffet,name,price,amount,nameafter);
		 				
		 				if(res==0) printlist(head);
		 				if(res==1) cout<<"No match \n";
		 				if(res==2) cout<<"The list is empty \n";
		 				
		 				k=5;
		 				break;
		 			}
		 			
		 			case 7:{
		 				cout<<"Enter the name of the product, you want to find: ";
		 				cin>> nameafter;
		 				cout<<"\n";
		 				
		 				//res=printitem(buffet,nameafther);
		 				
		 				if(res==1) cout<<"No match \n";
		 				if(res==2) cout<<"The list is empty \n";
		 				
		 				k=5;
		 				break;
		 			}
		 			
		 		}
		 	}
		 	cout<<"\n\n";
		 }
		 }
		 return 0;	
 }
