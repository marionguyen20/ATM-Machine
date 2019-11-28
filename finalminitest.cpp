#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "MiniProject1.h"
#include "Movement.h"
struct SV {
	int pass;
	char name[20];
	int idnum;
	int bal;
	} s,s1;
void Register(FILE*f){
	printf("Input user infomation: ");
	printf("\n Name, password: ");
	scanf("%s%d",&s.name,&s.pass);
	printf("\n Balance: ");
	scanf("%d",&s.bal);
	printf("\nID NUMBER:");
	scanf("%d",&s.idnum);
	}

void Write(FILE *f){
	fprintf(f,"%d\t",s.idnum);
	fprintf(f,"%s\t",s.name);
	fprintf(f,"%d\t",s.pass);
	fprintf(f,"%d\t",s.bal);
	fprintf(f,"\n");}
	
void Read(FILE *f){
	fscanf(f,"%d",&s1.idnum);
	fscanf(f,"%s",&s1.name);
	fscanf(f,"%d",&s1.pass);
	fscanf(f,"%d",&s1.bal);}

void wait(int sec){
clock_t endwait;
endwait = clock() + sec * CLOCKS_PER_SEC;
while (clock() < endwait) {}}

void Calbalaftertrans(int *bal,int *m){
	*bal=*bal-*m;
}
void Calbalafteradd(int *bal, int *m){
	*bal=*bal+*m;
	printf("Tien sau nap:%d",*bal);
}
void TransferWriteTo(FILE *f,int *moneyptr)
{
	char ttk[20];
	int t=0;
	Calbalaftertrans(&s1.bal,&t);
//	fprintf(f,"Balance of %s user:%d",s1.name,s1.bal);
	printf("Your balance amount:%d",s1.bal);

	printf("\nInput amount you want to transfer:");
	scanf("%d",&t);
	while (t>s1.bal) {
		printf("\nInput again your account cannot afford to transfer");
		printf("\nYou have %d in account:",s1.bal);
		scanf("%d",&t);
	}
	Calbalaftertrans(&s1.bal,&t);
	printf("\n\nRemain in account: %d",s1.bal);
//	fprintf(f,"\nAmount transfer:%d",t);
	*moneyptr=t;
}
void Update(FILE *fup){	
//	printf("Update balance in your account:%d %s %d %d",s1.idnum,s1.name,s1.pass,s1.bal);
	fprintf(fup,"%d %s %d %d\n",s1.idnum,s1.name,s1.pass,s1.bal);}
	
void UpdatePlus(FILE *fup,int somtiu){	//sum_of_money_in_update
	int bap; //balance after plus
	bap=s1.bal+somtiu; 
//	printf("bap is:%d",bap);
//	printf("Update balance in other account:%d %s %d %d",s1.idnum,s1.name,s1.pass,bap);
	fprintf(fup,"%d %s %d %d\n",s1.idnum,s1.name,s1.pass,bap);}
	
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
//	if (!f)
//	printf("Can not open this file");
//else
//	printf("File is opened\n");
						
							//GREETING CUSTOMER,LOG IN, REGISTER AND IF WRONGPASS MORE THAN 3 TIME, WAIT 5S TO CONTINUE
							
	printf("\t\t\t\t\t\t\t\t\t\tNICE TO MEET YOU, CUSTOMER\n"); system("pause");
	Bling();
	printf("\n\t\t\t\t\t\t\t\t\t\t\tLET'S LOG IN OR REGISTER ACCOUNT\n\n\t\t\t\t\t\t\t press L to log in, R to register:");
	scanf("%s",start);
	if (strcmpi(start,"r")==0) { Register(f); Write(f); printf("You have registed, now start log in");}
	else if (strcmpi(start,"l")==0)
	{ while(1){
		for(int ctlog=4;ctlog>0;ctlog--) //counter_time_login
		{	printf("Input ID number: ");
			scanf("%d",&idinputuser);
			printf("\nInput password: ");
			scanf("%d",&passinputuser);
			while (!feof(f)){
			Read(f);
			if ((idinputuser == s1.idnum) && (passinputuser == s1.pass)) sucess=1;}
		fseek(f,0,SEEK_SET);
		if (sucess!=1) printf("You have %d time to log in again\n",ctlog-1);
		else if (sucess==1) break;}
		
		if (sucess!=1){
			printf("Wait for 5s to log in again\n"); 
			for (int cnt=1;cnt<=5;cnt++){
			printf("%d\n", cnt);
			wait(1);}
			system("cls");}
		if (sucess==1) break;
		continue;}
	}
												//STARTING PROGRAM BY CHOOSING CHOICE 
												
	if (sucess==1) {printf("\n1. Check Information\n2. Withdraw\n3. Transfer\n4. Deposit\n");
		system("pause");
		system("cls"); 
		Menu();
		scanf("%d",&choice);}
	switch (choice)
{ 	
																case 1: 
	{system("cls");
	fclose(f);
	f = fopen(filePath, "r"); 
	while(!feof(f)){ Read(f); if (idinputuser==s1.idnum) {printf ("id number: %d\tname: %s\tpass:%d\tbalance:%dVND",s1.idnum,s1.name,s1.pass,s1.bal);break;}}break;}
																
																case 2: 
	system("cls");
	fclose(f);
	f = fopen(filePath, "r");
	{	int money;
		int p[4];
		int hoadon,a;
	
	do {
		while(!feof(f))
		{ Read(f); if(idinputuser==s1.idnum)
			{ printf ("Nhap so tien can rut: "); 
			  scanf("%d",&tienrut);
			  while (tienrut > s1.bal) { printf("Input another money, your account cannot satified"); scanf("%d",&tienrut);}
				printf("Ban se rut: %d\n",tienrut);
				money = tienrut;
				s1.bal = s1.bal - tienrut;
				printf("ndung cap nhat: %d %s %d %d\n",s1.idnum,s1.name,s1.pass,s1.bal);
				FILE *fup=fopen(fileUpdate,"a+");
				Update(fup);
				fclose(fup);
				break; }}}
			while (money % 50000 !=0) ;	
	p[4]=50000;
	p[3]=100000;
	p[2]=200000;
	p[1]=500000;

	for (a=1;a<=4;a++)
	{ 
	if ( (money%p[a] ==0) && (money>=p[a])) 
		{printf("\nprint out : %d papers of %d \n",money/p[a],p[a]); break;}
	if ( (money%p[a] !=0) && (money >= p[a])) 
		{printf ("%d papers of %d \n",money/p[a],p[a]); money = money - p[a] * (money/p[a]);}
	}
	
	
		printf("\nBan co muon in hoa don khong? "); scanf("%d", &hoadon);
		if (hoadon==1) printf("\n\nIn hoa don : \nSo the: %d \nTen: %s \nSo du: %d", s1.idnum, s1.name, s1.bal);
		// luu tru vao file
		
		fclose(f);
		f=fopen(filePath,"r");
		while (!feof(f)){	
			Read(f);
			if (s1.idnum!=idinputuser){
	//	printf("%d\n",s1.idnum);
		fup=fopen(fileUpdate,"a+");  Update(fup); fclose(fup);}}	
		fclose(f);
		
	fopen(filePath,"w");
	fprintf(f,NULL);
	fclose(f);
	fup=fopen(fileUpdate,"r");
	int ss=0;
		while (!feof(fup)){
			Copy(fup);
			f=fopen(filePath,"a+");
			Pasteupintoid(f,&ss);
		}
	fclose(fup);
	fclose(f);
fup=fopen(fileUpdate,"w");
fprintf(fup,NULL);
fclose(fup);
		break;}
		
	case 3:
	system("cls");																	
	fclose(f);
	f = fopen(filePath, "r");
{	system("cls");
	printf("Input IDNUM of person you want to transfer:");
	scanf("%d",&idinput);
	printf("\nInput name of user to transfer:");
	scanf("%s",nameinput);
	
	while (!feof(f)){
	Read(f);
	if ((strcmp(nameinput,s1.name)==0) && (idinput == s1.idnum)) 
	{printf("E");
	e++;}
	else printf("N");}
	fclose(f);
	
	int money=0,somt=0; //sum_of_amount_transfer
	f = fopen(filePath, "r+");
	while (!feof(f))
{	Read(f);
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
	Update(fup);
	fclose(fup);
	f=fopen(filePath,"r");
		while (!feof(f)){	
			Read(f);
			if ((e!=0)&&(idinput==s1.idnum)){
		//	printf("id = idinput: %d",s1.idnum); 
			fup = fopen(fileUpdate,"a+");  UpdatePlus(fup,somt); fclose(fup);}}
	fclose(f);
	f=fopen(filePath,"r");
		while (!feof(f)){	
			Read(f);
			if ((e!=0)&&(s1.idnum!=idinput)&&(s1.idnum!=idinputuser)){
		//	printf("id unchanged: %d",s1.idnum); 
			fup= fopen(fileUpdate,"a+");  Update(fup); fclose(fup);}}	
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
			Menu();		}
				else if (strcmpi(ttk,"q")==0) {
				printf("Thank you for your trust and See you again");
				Goodbye();}
						else printf("Wrong character to execute");
break;}
															case 4:
{	system("cls");
	int money;
	printf("Your information:\n");
	f=fopen(filePath,"r");
	while(!feof(f)){
		Read(f);
		if (idinputuser == s1.idnum) printf("Name:%s\tID Number:%d\tBalance:%d",s1.name,s1.idnum,s1.bal);}
	printf("How much money you want to add");
	scanf("%d",&money);
	fclose(f);
	f=fopen(filePath,"r");
	
	while(!feof(f)){
		Read(f);
		if (idinputuser == s1.idnum) 
	{Calbalafteradd(&s1.bal,&money); 
	printf("Have received your money, %d account have %d after transaction",s1.idnum,s1.bal);
	fup=fopen(fileUpdate,"a+");
	Update(fup);
	fclose(fup);}}

	fclose(f);
	f=fopen(filePath,"r");
	while(!feof(f)){
		Read(f);
		if (idinputuser!=s1.idnum) {fup=fopen(fileUpdate,"a+"); Update(fup); fclose(fup);}}

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
}}
	fclose(f);
	return 0;

}
