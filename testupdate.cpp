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
void calbal(int *bal,int *m){
	*bal=*bal-*m;
}
void TransferWriteTo(FILE *f,int *moneyptr)
{
	char ttk[20];
	int t=0;
	calbal(&s1.bal,&t);
//	fprintf(f,"Balance of %s user:%d",s1.name,s1.bal);
	printf("Your balance amount:%d",s1.bal);

	printf("\nInput amount you want to transfer:");
	scanf("%d",&t);
	while (t>s1.bal) {
		printf("\nInput again your account cannot afford to transfer");
		printf("\nYou have %d in account:",s1.bal);
		scanf("%d",&t);
	}
	calbal(&s1.bal,&t);
	printf("Remain in account: %d",s1.bal);
//	fprintf(f,"\nAmount transfer:%d",t);
	*moneyptr=t;
}
void UpdateMinus(FILE *fup){	
//	printf("Update balance in your account:%d %s %d %d",s1.idnum,s1.name,s1.pass,s1.bal);
	fprintf(fup,"%d %s %d %d\n",s1.idnum,s1.name,s1.pass,s1.bal);}
	
void UpdatePlus(FILE *fup,int somtiu){	//sum_of_money_in_update
	int bap; //balance after plus
	bap=s1.bal+somtiu; 
//	printf("bap is:%d",bap);
//	printf("Update balance in other account:%d %s %d %d",s1.idnum,s1.name,s1.pass,bap);
	fprintf(fup,"%d %s %d %d\n",s1.idnum,s1.name,s1.pass,bap);}
	
void Remain(FILE *fup){
//	printf("Paste old information into another file");
	fprintf(fup,"%d %s %d %d\n",s1.idnum,s1.name,s1.pass,s1.bal);}
	
void Copy(FILE *fup /*,int *ssptr*/){
//	printf("Start copy");
	fscanf(fup,"%d",&s1.idnum);
	fscanf(fup,"%s",&s1.name);
	fscanf(fup,"%d",&s1.pass);
	fscanf(fup,"%d",&s1.bal);}
//	printf("\nThing get by copy:%d %s %d %d\n",s1.idnum,s1.name,s1.pass,s1.bal);}

void Pasteupintoid(FILE *f,int *ssptr){
	if (s1.idnum==*ssptr) return;
//	printf("Paste file:");
	fprintf(f,"%d\t",s1.idnum);
	fprintf(f,"%s\t",s1.name);
	fprintf(f,"%d\t",s1.pass);
	fprintf(f,"%d\t",s1.bal);
	*ssptr=s1.idnum;
	fprintf(f,"\n");}
	
int main()
{	char nameinput[20],start[20],ttk[20],con[20];
	int idinput, passinput,sucess,choice,tienrut,idinputuser,passinputuser,e=0;
	
const char *fileUpdate ="D:\ Update_ID.txt";
	FILE *fup;
const char *filePath ="D:\NgocTram\ID.txt";
	FILE *f;
	f = fopen(filePath, "a+");
	if (!f)
	printf("Can not open this file");
else
	printf("File is opened\n");
	
	printf("NICE TO MEET YOU, CUSTOMER\n LET'S LOG IN OR REGISTER ACCOUNT\n press L to log in, R to register:");
	scanf("%s",start);
	if (strcmpi(start,"r")==0) { nhap(f); ghi(f);printf("You have registed, now start log in");}
	else if (strcmpi(start,"l")==0)
		{ 	printf("Input ID number: ");
			scanf("%d",&idinputuser);
			printf("\nInput password: ");
			scanf("%d",&passinputuser);
			while (!feof(f)){
			doc(f);
		if ((idinputuser == s1.idnum) && (passinputuser == s1.pass)) 
		{printf("successful"); sucess=1;}}
		if (sucess!=1) printf("Wrong ID, password or you haven't registed\nLet's create your account\n");}	
	
	
	
	if (sucess==1) {printf("\n1. Xem thong tin\n2. Rut tien\n3. Chuyen tien\n");
		system("pause");
		system("cls"); 
		main1();
		scanf("%d",&choice);}
	switch (choice)
{ 	
	case 1: {fclose(f);
	f = fopen(filePath, "r"); 
	while(!feof(f)){ doc(f); if (idinputuser==s1.idnum) {printf ("id number: %d\tname: %s\tpass:%d\tbalance:%dVND",s1.idnum,s1.name,s1.pass,s1.bal);break;}}break;}
	case 2: {printf("rut tien thoiii"); break;}
	case 3:
	fclose(f);
	f = fopen(filePath, "r");
{	printf("Input IDNUM of person you want to transfer:");
	scanf("%d",&idinput);
	printf("\nInput name of user to transfer:");
	scanf("%s",nameinput);
	
	while (!feof(f)){
	doc (f);
	if ((strcmp(nameinput,s1.name)==0) && (idinput == s1.idnum)) 
	{printf("E");
	e++;}
	else printf("N");}
	fclose(f);
	
	int money=0,somt=0; //sum_of_amount_transfer
	f = fopen(filePath, "r+");
	while (!feof(f))
{	doc(f);
	if ((e!=0)&&(idinputuser==s1.idnum)){
		fclose(f);
		fopen(filePath,"a"); 
		printf("\nDo you want to continue transfer to ID account: %d\nN to break and Y to continue:",idinput);
		scanf("%s",&con);
		if (strcmpi(con,"n")==0) break;
		else if (strcmpi(con,"y")==0){
		TransferWriteTo(f,&money);
		somt=somt+money;
		fclose(f);}
		else printf("\nEnter your choice again,  N to break and Y to continue, terrible =)))");}
	printf("\nTotal amount to transfer is:%d",somt);
}
	fup = fopen(fileUpdate,"a+");
	UpdateMinus(fup);
	fclose(fup);
	f=fopen(filePath,"r");
		while (!feof(f)){	
			doc(f);
			if ((e!=0)&&(idinput==s1.idnum)){
		//	printf("id = idinput: %d",s1.idnum); 
			fup = fopen(fileUpdate,"a+");  UpdatePlus(fup,somt); fclose(fup);}}
	fclose(f);
	f=fopen(filePath,"r");
		while (!feof(f)){	
			doc(f);
			if ((e!=0)&&(s1.idnum!=idinput)&&(s1.idnum!=idinputuser)){
		//	printf("id unchanged: %d",s1.idnum); 
			fup= fopen(fileUpdate,"a+");  Remain(fup); fclose(fup);}}	
	fclose(f);

	f=fopen(filePath,"w");
	fprintf(f,NULL);
	fclose(f);
	fup=fopen(fileUpdate,"r");
	int ss=0;
		while (!feof(fup)){
			Copy(fup);
		//	printf("ss trong while:%d",ss);
			f=fopen(filePath,"a+");
			Pasteupintoid(f,&ss);
		}
	fclose(f);
	fclose(fup);
	fup=fopen(fileUpdate,"w");
	fprintf(fup,NULL);
	fclose(fup);
	
	printf("\nDo you want to continue:\nCome back to main menu press C or Q to quit:");
	scanf("%s",ttk);
		if ((strcmp(ttk,"c") ==0)||(strcmp(ttk,"C") ==0)) 
		{	system("cls"); 
			main1();		}
				else if (strcmpi(ttk,"q")==0) printf("Thank you for your trust and See you again");
						else printf("Wrong character to execute");
break;}
}
	fclose(f);
	return 0;

}
