 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <Windows.h>
//Create a struct of Student
struct Student 
	{
		char pass[30];
		char name[30];
		int idnum;
		int bal;
	} s1; 	
//Function read file 
void read(FILE *f)
	{	//Read ID number
		fscanf(f,"\nID Number: %d",&s1.idnum);
		//Read Name
		fscanf(f,"\nName: %[^\n]s",&s1.name);
		//Read pass
		fscanf(f,"\nPass: %[^\n]s",&s1.pass);
		//Read Balance
		fscanf(f,"\nBalance: %d",&s1.bal);
	}
//Function output information	
void output()
	{
		printf("\n Name:%s \n ID number: %d \n Balance: %d VND\n",s1.name,s1.idnum,s1.bal);
	}
void encryptionpass(char hasher[])
{
	char tempt;
    int n=strlen(hasher);
    for(int x=0; x < n/2; x++)
  {
     tempt=hasher[x];
     hasher[x]=hasher[n-x-1];
     hasher[n-x-1]=tempt;
  }
}
//function text color
void textcolor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
 
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void screenlogin()
{
		textcolor(6);
		printf("\t\t\t\t\t\t\t*************************\n");
		printf("\t\t\t\t\t\t\t*                       *\n");
		textcolor(10);
		printf("\t\t\t\t\t\t\t*      LOGIN SYSTEM     *\n"); 
		textcolor(6);  
		printf("\t\t\t\t\t\t\t*                       *\n");
		printf("\t\t\t\t\t\t\t\************************\n\n");
}
int main()
{
	int idinput, passinput,choice,deposite,success,enpass;
	char c,pass;
	//Input ID and Password
	//Clean screen
	system("cls");
	printf("\n");
	screenlogin();
	textcolor(10);
	printf("\t\t\t\t\t\tInput ID number: ");
	textcolor(15);
	scanf("%d",&idinput);
	textcolor(10);
	printf("\t\t\t\t\t\tInput password: ");
	textcolor(15);
	 c='.'; char password[10];
    int i = 0;
    // 13 is enter transfer pass into *
        while(c != 13)
		{
        	if (kbhit())
        	{
            	c = getch();
            	if (c != 8)
            	{
                	printf("*");
                	password[i] = c;
                	i++;
            	}
            		else
            		{
                		printf("\b_\b");
                		i--;
                		password[i] = '\0';
            		}
        	}
    	}
    passinput=atoi(password);
	//Open file
	FILE *f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","r");
	//Check login and Transaction
	while (!feof(f))
	{
		read (f);
		encryptionpass(s1.pass); 
   		enpass=atoi(s1.pass); 	
		if ((idinput == s1.idnum) && (passinput == enpass)) 
			{	success=1;	
				printf("\nLogin Successful\n"); 
				system("cls");
			//Choose case
			
				system("cls");
				printf("\n1. Check information\n2. Deposite\n3. Transfer\n");
				printf("Which service would you want to choose: ");
				scanf("%d",&choice);
				switch (choice)
				{	
					case 1: //check information
					{	system("cls");
						output();
						break;
					}
					
				}
				}
			
	}
	return 0;
}
