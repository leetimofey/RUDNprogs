#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct student{
	char name[10];
	char group[7];
	int mark;
};
int perezd(student st){
	if (st.mark<52){
		st.mark=100;
	}
	return st.mark;
}
int main(int argc, char** argv) {
	student st;
	FILE *fp;
	int i;
	if ((fp = fopen("student.dat","r"))==NULL){
		perror("student.dat");
		return 1;
	}
	int kolv;
	fscanf(fp, "%d", &kolv);
	for (i=0; i<kolv; i++){
		fscanf(fp,"%s",&st.name);
		fscanf(fp,"%s",&st.group);
		fscanf(fp,"%d",&st.mark);
		st.mark= perezd(st);
		printf("%s ",st.name);
		printf("%s ",st.group);
		printf("%d\n",st.mark);
	}
	
	return 0;
}
