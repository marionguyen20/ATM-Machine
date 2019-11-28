#include <stdio.h>
struct SV {
	int pass;
	char name[20];
	int idnum;
	int bal;
	} s,s1;
void nhap(){
	printf("Input user infomation: ");
	printf("\n Name, password: ");
	scanf("%s%d",&s.name,&s.pass);
	printf("\n Balance: ");
	scanf("%d",&s.bal);
	printf("\nID NUMBER:");
	scanf("%d",&s.idnum);
	}
	
void ghi(FILE *f){
//	fprintf(f,"");
	fprintf(f,"%d\t",s.idnum);
	fprintf(f,"%s\t",s.name);
	fprintf(f,"%d\t",s.pass);
	fprintf(f,"%d\t",s.bal);}
	
int main(){
	FILE *f=fopen("C:/Users/FPT/Documents/Programming C/codycody","a");
	nhap();
	ghi(f);
	fclose(f);
	return 0;}
