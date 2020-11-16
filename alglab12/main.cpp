#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h> // Обязательно для SetConsoleCP() и SetConsoleOutputCP()
using namespace std;

struct voc{
	string name;
	string rus;
	int amount;
	voc* next;
};



void addfirst(voc **head, string name, string rus, int amount){
	voc* newvoc= new voc;
	newvoc->name=name;
	newvoc->rus=rus;
	newvoc->amount=amount;
	newvoc->next=*head;
	*head=newvoc;
}

void printlist(voc* k){
	while(k){
		cout<<"Слово: "<<k->name<<"\tПеревод: "<<k->rus<<"\tКоличество обращений: "<<k->amount<<endl;
		k=k->next;
	}
}

void addlast(voc **head, string name, string rus, int amount){
	voc* newvoc= new voc;
	voc* a=*head;
	if (a==NULL){
		addfirst(head,name,rus,amount);
	}
	else{
		while(a->next){
		a=a->next;
		}
		a->next=newvoc;
		newvoc->name=name;
		newvoc->rus=rus;
		newvoc->amount=amount;
		newvoc->next=NULL;
	}
}
 
int printitem(voc ** head, string name){
	voc* a=new voc;
	a=*head;
	while(a){
		while((a->name!=name)&&(a)){
			a=a->next;
		}
		if(a){
			a->amount+=1;
			cout<<"Слово: "<<a->name<<"\tПеревод: "<<a->rus<<"\tКоличество обращений: "<<a->amount<<endl;	
			a=a->next;
			}
	}
	return 0;
}

int addbefore(voc **head, string beforewhat, string name, string rus, int amount){
	voc* newvoc= new voc;
	voc* a=*head;
	if(a->name==beforewhat){
		addfirst(head,name,rus,amount);
	}
	else{
		voc* b=a->next;
		while(b->name!=beforewhat){
			a=b;
			b=b->next;}
		newvoc->name=name;
		newvoc->rus=rus;
		newvoc->amount=amount;
		newvoc->next=b;
		a->next=newvoc;
	}
	return 0;
}

void sort_name(voc** head){ 
	voc* a=*head; 
	voc* newlist=NULL; 
	if(a!=NULL) { 
		addfirst(&newlist, a->name, a->rus, a->amount); 
		a=a->next; 
		while(a!=NULL){ 
			voc* tmp = newlist; 
			while(tmp && tmp->name < a->name) { 
				tmp=tmp->next; 
			} 
			if(tmp!=NULL) { 
				addbefore(&newlist, tmp->name, a->name, a->rus, a->amount); 
			} else { 
				addlast(&newlist, a->name, a->rus, a->amount); 
			} 
			a=a->next; 
		} 
		*head=newlist; 
	} 
}

void sort_amount(voc** head){
	voc* a=*head; 
	voc* newlist=NULL; 
	if(a!=NULL) { 
		addfirst(&newlist, a->name, a->rus, a->amount); 
		a=a->next; 
		while(a!=NULL){ 
			voc* tmp = newlist; 
			while(tmp && tmp->amount > a->amount) { 
				tmp=tmp->next; 
			} 
			if(tmp!=NULL) { 
				addbefore(&newlist, tmp->name, a->name, a->rus, a->amount); 
			} else { 
				addlast(&newlist, a->name, a->rus, a->amount); 
			} 
			a=a->next; 
		} 
		*head=newlist; 
	} 
}

int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	voc *head = NULL;
	int res,k,amount;
	string name, rus;
	k=6;
	int kolvo=0;
	
	while(k!=0){
		 while(k!=0 && k!=1 && k!=2 && k!=3 && k!=4 && k!=5){
		 	cout<<"Чтобы добавить слово в конец словаря, введите 1; \nЧтобы добавить слово в начало словаря, введите 2;\nЧтобы найти перевод, введите 3;\nЧтобы отсортировать словарь по алфавиту, введите 4;\nЧтобы отсортировать словарь по количеству обращений, введите 5;\nЧтобы выйти, введите 0: ";
		 	cin>>k;
		 	cout<<"\n\n";
		 	
		 	if(k!=0 && k!=1 && k!=2 && k!=3 && k!=4 && k!=5){
		 		cout<<"Wrong code! \n\n";
		 		system ("pause");
		 	}
		 	
		 	else{
		 		switch(k){
		 			case 0:{
		 				break;
		 			}
					
		 			case 1:{
		 				cout<<"Введите английское слово: ";
		 				cin>> name;
		 				cout<<"\n";
		 				
		 				cout<<"Введите перевод: ";
		 				cin>> rus;
		 				cout<<"\n";
		 				
		 				
		 				cout<<"Введите количество обращений: ";
		 				cin>> amount;
		 				cout<<"\n";
		 				
		 				addlast(&head, name, rus, amount);
		 				printlist(head);
		 				kolvo+=1;
		 				k=6;
		 				break;
		 			}
		 			
		 			case 2:{
		 				cout<<"Введите английское слово: ";
		 				cin>> name;
		 				cout<<"\n";
		 				
		 				cout<<"Введите перевод: ";
		 				cin>> rus;
		 				cout<<"\n";
		 				
		 				
		 				cout<<"Введите количество обращений: ";
		 				cin>> amount;
		 				cout<<"\n";
		 				
		 				addfirst(&head, name, rus, amount);
		 				printlist(head);
		 				k=6;
		 				kolvo+=1;
		 				break;
		 			}
		 			
		 			case 3:{
		 				cout<<"Введите английское слово, перевод которого ищете: ";
		 				cin>> name;
		 				cout<<"\n";
		 				
		 				res=printitem(&head,name);
		 				
		 				if(res==1) cout<<"No match \n";
		 				if(res==2) cout<<"The list is empty \n";
		 				
		 				k=6;
		 				break;
		 			}
		 			case 4:{
		 				sort_name(&head);
		 				printlist(head);
		 				k=6;
						break;
					 }
					case 5:{
		 				sort_amount(&head);
		 				printlist(head);
		 				k=6;
						break;
					 }
		 		}
		 	}
		 	cout<<"\n\n";
		 }
		 }
		 cout<<"I've seen things you people wouldn't believe.\nAttack ships on fire off the shoulder of Orion.\nI watched C-beams glitter in the dark near the Tannhauser Gate.\nAll those moments will be lost in time, like tears in rain.\nTime to die.";
		 return 0;	

}
