#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MiniProject1.h"
struct SV {
	int pass;
	char name[20];
	int idnum;
	int bal;
	} s,s1;
void nhap(FILE*f){
	printf("Input user infomation: ");
	printf("\n Name, password: ");
	scanf("%s%d",&s.name,&s.pass);
	printf("\n Balance: ");
	scanf("%d",&s.bal);
	printf("\nID NUMBER:");
	scanf("%d",&s.idnum);
	}

void ghi(FILE *f){
	fprintf(f,"%d\t",s.idnum);
	fprintf(f,"%s\t",s.name);
	fprintf(f,"%d\t",s.pass);
	fprintf(f,"%d\t",s.bal);
	fprintf(f,"\n");}
	
void doc(FILE *f){
	fscanf(f,"%d",&s1.idnum);
	fscanf(f,"%s",&s1.name);
	fscanf(f,"%d",&s1.pass);
	fscanf(f,"%d",&s1.bal);
	}
void TransferWriteTo(FILE *f)
{
	char ttk[20];
	int t;
	fprintf(f,"Balance of %s user:%d",s1.name,s1.bal);
	printf("Your balance amount:%d",s1.bal);
//	scanf("%d",&b);
//	fprintf(f,"%d",s1.bal);
	printf("\nInput amount you want to transfer:");
	scanf("%d",&t);
	while (t>s1.bal) {
		printf("Input again your account cannot afford to transfer:");
		printf("\nYou have %d in account",s1.bal);
		scanf("%d",&t);
	}
	s1.bal=s1.bal-t;
	fprintf(f,"\nAmount transfer:%d",t);
	fprintf(f,"\nThe remain after transaction in %s acccount:%d\n\n",s1.name,s1.bal);
	
	printf("Do you want to continue:");
	printf("Come back to main menu press C or Q to quit:");
	scanf("%s",ttk);
		if ((strcmp(ttk,"c") ==0)||(strcmp(ttk,"C") ==0)) 
		{	system("cls"); 
			main1();		}
				else if ((strcmp(ttk,"q")==0)||(strcmp(ttk,"Q")==0)) printf("Thank you for your trust and See you again");
					else printf("Wrong character to execute");

}
int main()
{	char nameinput[20];
	int idinput,e=0;
const char *filePath ="D:\NgocTram\ID.txt";
	FILE *f;
	f = fopen(filePath, "a");
	if (!f)
	printf("Can not open this file");
else
	printf("File is opened\n");
	nhap(f);
	ghi(f);
	fclose(f);
	
	f = fopen(filePath, "r");
	printf("Input IDNUM of person you want to transfer:");
	scanf("%d",&idinput);
	printf("\nInput name of user to transfer:");
	scanf("%s",nameinput);
	
	while (!feof(f)){
	doc (f);
	if ((strcmp(nameinput,s1.name)==0) && (idinput == s1.idnum)) 
	{//printf("E");
	e++;}
	else printf("N");}
		f = fopen(filePath, "a+");
	if (e!=0) TransferWriteTo(f);
	else printf("The person, who you want to transfer, is non-existed");
	fclose(f);
	return 0;
}
