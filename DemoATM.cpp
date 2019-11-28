#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <Windows.h>
#include "Menu_Graphical.h"
#include "Money_Graphical.h"
#include "Movement.h"
//Create a struct of Student
struct Student 
	{
		char pass[7];
		char name[30];
		int idnum,idnumtrs;
		char passnew[7];
		int bal,balnew,baladd,balminus,baldepo;
	} s1; 	
//Function read file 
void read(FILE *f)
	{	//Read ID number
		fscanf(f,"\n\nID Number: %d",&s1.idnum);
		//Read Name
		fscanf(f,"\nName: %[^\n]s",&s1.name);
		//Read pass
		fscanf(f,"\nPass: %[^\n]s",&s1.pass);
		//Read Balance
		fscanf(f,"\nBalance: %d",&s1.bal);
	}

void printnew(FILE *fup)
	{	
		//Print ID number
		fprintf(fup,"\n\nID Number: %d",s1.idnum);
		//Print Name
		fprintf(fup,"\nName: %s",&s1.name);
		//Print pass
		fprintf(fup,"\nPass: %s",&s1.passnew);
		//Print Balance
		fprintf(fup,"\nBalance: %d",s1.bal);	
	}
void printnew1(FILE *fup)
	{	
		//Print ID number
		fprintf(fup,"\n\nID Number: %d",s1.idnum);
		//Print Name
		fprintf(fup,"\nName: %s",&s1.name);
		//Print pass
		fprintf(fup,"\nPass: %s",&s1.pass);
		//Print Balance
		fprintf(fup,"\nBalance: %d",s1.balnew);	
	}
void printnew2(FILE *fup)
	{	
		//Print ID number
		fprintf(fup,"\n\nID Number: %d",s1.idnum);
		//Print Name
		fprintf(fup,"\nName: %s",&s1.name);
		//Print pass
		fprintf(fup,"\nPass: %s",&s1.pass);
		//Print Balance
		fprintf(fup,"\nBalance: %d",s1.baladd);	
	}
void printnew3(FILE *fup)
	{	
		//Print ID number
		fprintf(fup,"\n\nID Number: %d",s1.idnum);
		//Print Name
		fprintf(fup,"\nName: %s",&s1.name);
		//Print pass
		fprintf(fup,"\nPass: %s",&s1.pass);
		//Print Balance
		fprintf(fup,"\nBalance: %d",s1.balminus);	
	}
void printnew4(FILE *fup)
	{	
		//Print ID number
		fprintf(fup,"\n\nID Number: %d",s1.idnum);
		//Print Name
		fprintf(fup,"\nName: %s",&s1.name);
		//Print pass
		fprintf(fup,"\nPass: %s",&s1.pass);
		//Print Balance
		fprintf(fup,"\nBalance: %d",s1.baldepo);	
	}
void print(FILE *fup)
	{	
		//Print ID number
		fprintf(fup,"\n\nID Number: %d",s1.idnum);
		//Print Name
		fprintf(fup,"\nName: %s",&s1.name);
		//Print pass
		fprintf(fup,"\nPass: %s",&s1.pass);
		//Print Balance
		fprintf(fup,"\nBalance: %d",s1.bal);	
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
		printf("\t\t\t\t\t\t\t************************\n\n");	
}
void outputinfor() 
{
	textcolor(6);
		textcolor(6);
		printf("\n\t\t\t\t\t\t\t*************************\n");
		printf("\t\t\t\t\t\t\t*                       *\n");
		textcolor(10);
		printf("\t\t\t\t\t\t\t*  CUSTOMER INFORMATION *\n"); 
		textcolor(6);  
		printf("\t\t\t\t\t\t\t*                       *\n");
		printf("\t\t\t\t\t\t\t************************\n\n");	
	textcolor(7);
	textcolor(15);
	printf("\n");
	printf("\n\t\t\t\t\t\t\t Name: %s",&s1.name);
	printf("\n\t\t\t\t\t\t\t ID number: %d",s1.idnum);
	printf("\n\t\t\t\t\t\t\t Balance: %d VND\n",s1.bal);
	textcolor(7);
	
}
//Encryptionpass by inverting
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
void screenchangepass() 
{
	textcolor(6);
		textcolor(6);
		printf("\n\t\t\t\t\t\t\t*************************\n");
		printf("\t\t\t\t\t\t\t*                       *\n");
		textcolor(10);
		printf("\t\t\t\t\t\t\t*  CHANGE YOUR PASSWORD *\n"); 
		textcolor(6);  
		printf("\t\t\t\t\t\t\t*                       *\n");
		printf("\t\t\t\t\t\t\t************************\n\n");	
	textcolor(7);
	
	printf("\n");
}
void screentransfer() 
{
	textcolor(6);
		textcolor(6);
		printf("\n\t\t\t\t\t\t\t*************************\n");
		printf("\t\t\t\t\t\t\t*                       *\n");
		textcolor(10);
		printf("\t\t\t\t\t\t\t*   TRANSFER MONEY      *\n"); 
		textcolor(6);  
		printf("\t\t\t\t\t\t\t*                       *\n");
		printf("\t\t\t\t\t\t\t************************\n\n");	
	textcolor(7);
	
	printf("\n");
}
void screendeposite() 
{
	textcolor(6);
		textcolor(6);
		printf("\n\t\t\t\t\t\t\t*************************\n");
		printf("\t\t\t\t\t\t\t*                       *\n");
		textcolor(10);
		printf("\t\t\t\t\t\t\t*   DEPOSITE MONEY      *\n"); 
		textcolor(6);  
		printf("\t\t\t\t\t\t\t*                       *\n");
		printf("\t\t\t\t\t\t\t************************\n\n");	
	textcolor(7);
	
	printf("\n");
}
void transferpass(char password[])
{
		char c = '.'; password[10];
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
                		printf("\b \b");
                		i--;
                		password[i] ='\0';
            		}
        	}
        }
  	//return atoi(password);
}
void wait(int sec)
{
	clock_t endwait;
	endwait = clock() + sec * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}

const char *fileUpdate ="E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\FileUpdate.txt";
	FILE *fup;
const char *filePath ="E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt";
const char *fileTrans = "E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Transaction.txt";
	FILE *ftrs;
	
int main()
{
	int idinput,choice,withdraw,success,enpass;
	int counttrans =0;
	char passinput[7];
	char c,pass,a;
Bling();
	//Input ID and Password
	int countlog=3;
login:{
	
	//Clean screen
	system("cls");
	printf("\n");
	
	//Call screenlogin function
	screenlogin();
	textcolor(10);
	printf("\t\t\t\t\t\tInput ID number: ");
	textcolor(15);
	scanf("%d",&idinput);
	textcolor(10);
	printf("\t\t\t\t\t\tInput password: ");
	textcolor(15);
	transferpass(passinput);
	
	              
	//Open file
	FILE *f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","r");
			
	//Check login and Transaction
	while (!feof(f))
	{
		read (f);
	    encryptionpass(s1.pass); 
   		enpass=atoi(s1.pass); 	
		if ((idinput == s1.idnum) && (atoi(passinput) == enpass)) 
			{	success=1;	
				printf("\n\n\t\t\t\t\t\tLogin Successful\n"); 
				system("pause");
				
		menu:{	system("cls");
				menu(); 
				scanf("%d",&choice);
				switch (choice)
				{	
					case 1: //check information
					{	system("cls");
						FILE *f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","r");
						while (!feof(f))
						{
							read (f);
	    					if ((idinput == s1.idnum) && (atoi(passinput) == enpass)) 
							{	outputinfor();
								break;
							}
						}
						break;
					}//Finish information
					case 2: //Change password.
					{	system("cls");
						screenchangepass();
						char passcur[7], passconf[7]; 
						//int passcur, passconf,passnew;
						textcolor(3);
						printf("\t\t\t\t\tInput the current password: ");
						textcolor(15);
						transferpass(passcur);
						if (atoi(passcur) == enpass)
						{	textcolor(3);
							printf("\n\n\t\t\t\t\tInput new password: ");
							textcolor(15);
							transferpass(s1.passnew);
						
							textcolor(3);
							printf("\n\t\t\t\t\tConfirm new password: ");
							textcolor(15);
							transferpass(passconf);
							if (atoi(passconf)== atoi(s1.passnew) ) 
							{	
								textcolor (10);
								printf("\n\n\t\t\t\t\tCongratulation! Your password has been changed. \n");
								//Open file Update
								FILE *fup =fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\FileUpdate.txt","a+");
								encryptionpass(s1.passnew); 
								fclose(f);
							
								//Scan file into new file
								FILE *f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","r");
								int ssptr =0;
								
								while (!feof(f))
								{		
										read(f);
										if (s1.idnum==ssptr) break;
										encryptionpass(s1.pass);
										if (atoi(passinput)==atoi(s1.pass)) printnew(fup);
										else {
												encryptionpass(s1.pass);
												print(fup);
											 }
										ssptr=s1.idnum;
								}
								fclose(fup);
								
								//Create Null file Account
								f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","w");
								fclose(f);
								
								//Update file Account
								fup =fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\FileUpdate.txt","r");
								ssptr=0;
								while (!feof(fup))
								{
									read(fup);
									f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","a+");
									if (s1.idnum==ssptr) break;
									print(f);
									ssptr=s1.idnum;
									fclose(f);
								}
								fclose(fup);
								fup=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\FileUpdate.txt","w");
								fclose(fup);
							}
								else 
								{
									printf("\n\t\t\t\t\tWrong password!\n");
									break;
								}
							
						} else 
							{	textcolor(10);
								printf("\n\n\t\t\t\t\tWrong password ");
								break;
							}
						break;
						
					}//Finish change password
			
	Withdraw: {	case 4: //withdraw 
					{
						
						FILE *f = fopen(filePath, "r");
						int choice1,withdraw;
						int p[4];
						p[4]=50000;
						p[3]=100000;
						p[2]=200000;
						p[1]=500000;
						system("cls");
						money();
						textcolor(10);
						printf("n\n\t\t\t\t\t\t\tInput your choice: ");
						textcolor(15);
						fflush(stdin);
						scanf("%d",&choice1);
						
						switch (choice1)
						{
							case 1: //50.000
							{
								withdraw = 50000;
								break;
							}
							case 2: //100.000
							{
								withdraw = 100000;
								break;
							}
							case 3: //200.000
							{
								withdraw = 200000;
								break;
							}
							case 4: //500.000
							{
								withdraw = 500000;
								break;
							}
							case 5: //1.000.000
							{
								withdraw = 1000000;
								break;
							}
							case 6: //other
							{
								printf("\n\n\t\t\t\t\t\t\tInput the money: ");
								scanf("%d",&withdraw);
								break;
							}
							default:
								{
									printf("\n\n\t\t\t\t\t\t\tWrong Input\n");
									goto Question;
								}
						}
						 if ((withdraw > s1.bal) || ((withdraw % 50000)!=0))
						 {	textcolor(10);
						 	printf("\n\n\t\t\t\t\t\t\tInput another money, your account cannot satified or your money not suitable\n");
						 	textcolor(15);
							printf("\n\n\t\t\t\t\t\t\tContinued or not Y/N: ");
							fflush(stdin);
							scanf("%c",&c);
							if ((c=='Y')||(c=='y')) goto Withdraw ; else 
								{
									system("cls");
									Decor ();
									//printf("Thanks for using my service");
									break;
								}
						 	
						} else 
							{
								s1.balnew = s1.bal - withdraw;
								for (int a=1;a<=4;a++)
								{ 
									if ( (withdraw%p[a] ==0) && (withdraw>=p[a])) 
										{
											printf("\n\n\t\t\t\t\t\t\tPrint out : %d papers of %d \n",withdraw/p[a],p[a]); 
											break;
										}
									if ( ( withdraw % p[a] !=0) && (withdraw >= p[a])) 
										{
											printf ("\n\n\t\t\t\t\t\t\tPrint out : %d Papers of %d \n",withdraw/p[a],p[a]); 
											withdraw = withdraw - p[a] * (withdraw/p[a]);
										}
								} textcolor(10);
								printf("\n\n\t\t\t\t\t\t\t Your updated information: \n");
								textcolor(15);
								//Print ID Num
								printf("\n\n\t\t\t\t\t\t\tID Number: %d",s1.idnum);
								//Print Name
								printf("\n\n\t\t\t\t\t\t\tName: %s",&s1.name);
								//Print Balance
								printf("\n\n\t\t\t\t\t\t\tBalance: %d",s1.balnew);	
								fclose(f);
								
							}
								f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","r");
								FILE *fup =fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\FileUpdate.txt","a+");
								int ssptr =0;
								while (!feof(f))
								{		
										read(f);
										if (s1.idnum==ssptr) break;
										if ((s1.idnum)==(idinput)) printnew1(fup);
										else {
												print(fup);
											 }
										ssptr=s1.idnum;
								}
								fclose(fup);
								fclose(f);
								//Create Null file Account
								f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","w");
								fclose(f);
								
								//Update file Account
								fup =fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\FileUpdate.txt","r");
								ssptr=0;
								while (!feof(fup))
								{
									read(fup);
									f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","a+");
									if (s1.idnum==ssptr) break;
									print(f);
									ssptr=s1.idnum;
									fclose(f);
								}
								fclose(fup);
								fup=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\FileUpdate.txt","w");
								fclose(fup);
								fclose(f);
									
								//Update transaction
								counttrans++;
								FILE *ftrs=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Transaction.txt","a+");
								f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","r");
								while (!feof(f))
									{
										read(f);
										if(idinput == s1.idnum)
											{
												fprintf(ftrs,"\n\nTransaction ID: %d",counttrans);
												fprintf(ftrs,"\nID Number: %d",s1.idnum);
												fprintf(ftrs,"\nType: Withdraw");
												fprintf(ftrs,"\nFromUser ID: %d",s1.idnum);
												fprintf(ftrs,"\nAmount: %d",withdraw);
												break;
											}
									}
								fclose(f);
								fclose(ftrs);		
						break;	
					}
				} //Finish withdraw
				case 5: //Deposite
				{	
					int moneyadd;
					system("cls");
					screendeposite();
					//Get your information of user
					textcolor(10);
					printf("\n\n\t\t\t\t\t\t\tYOUR INFORMATION:\n");
					f=fopen(filePath,"r");
					while(!feof(f))
					{
						read(f);
						if (idinput == s1.idnum) 
						{	textcolor(15);
							printf("\n\n\t\t\t\t\t\t\tID Number: %d\n",s1.idnum);
							printf("\n\n\t\t\t\t\t\t\tName: %s\n",s1.name);
							printf("\n\n\t\t\t\t\t\t\tBalance: %d\n",s1.bal);
						}
					}
					textcolor(10);
					printf("\n\n\t\t\t\t\t\t\tINPUT MONEY YOU WANT TO ADD: "); 
					textcolor(15);
					scanf("%d",&moneyadd);
					fclose(f);
					// Update money after adding
					f=fopen(filePath,"r");
					while(!feof(f))
					{
						read(f);
						if (idinput == s1.idnum) 
							{
								s1.baldepo = s1.bal + moneyadd;
								printf("\n\n\n\n\t\t\t\t\t\t\tDEPOSITE SUCCESSFUL");
							}
					}
					fclose(f);
					
					//Scan intro new file
					f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","r");
					FILE *fup =fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\FileUpdate.txt","a+");
					int ssptr =0;
					while (!feof(f))
						{		
							read(f);
							if (s1.idnum==ssptr) break;
							if ((s1.idnum)==(idinput)) printnew4(fup);
								else print(fup);
							ssptr=s1.idnum;
						}
						fclose(fup);
						fclose(f);
						
					//Create Null file Account
					f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","w");
					fclose(f);
								
					//Update file Account
					fup =fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\FileUpdate.txt","r");
					ssptr=0;
					while (!feof(fup))
						{
					  		read(fup);
							f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","a+");
							if (s1.idnum==ssptr) break;
							print(f);
							ssptr=s1.idnum;
							fclose(f);
						}
							fclose(fup);
							fup=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\FileUpdate.txt","w");
							fclose(fup);
							//Update transaction
							counttrans++;
							FILE *ftrs=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Transaction.txt","a+");
							FILE *f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","r");
							while (!feof(f))
								{
									read(f);
									if(idinput == s1.idnum)
										{
											fprintf(ftrs,"\n\nTransaction ID: %d",counttrans);
											fprintf(ftrs,"\nID Number: %d",s1.idnum);
											fprintf(ftrs,"\nType: Deposite");
											fprintf(ftrs,"\nToUser ID: %d",s1.idnum);
											fprintf(ftrs,"\nAmount: %d",moneyadd);
											break;
										}
									}
								fclose(f);
								fclose(ftrs);		
					
					break;
				} //Finish Deposite
				case 3://transfer 
				{	
					int idinput1; char choice2; int suc=0;
					system("cls");
					screentransfer();
					fclose(f);
					f = fopen(filePath, "r");
					//input reciver id number
					printf("\n\n\t\t\t\t\t\t\tInput ID NUMBER of person you want to transfer: ");
					scanf("%d",&idinput1);
					int moneytrans=0;
					//Transfer
					while (!feof(f))
					{
						read(f);
						//system("Pause");
						if (idinput1 == s1.idnum)
						{	suc=1;
							textcolor(10);
							//Ouput information reciver
							printf("\n\n\t\t\t\t\t\t\tINFORMATION OF RECIEVER \n");
							textcolor(15);
							printf("\n\n\t\t\t\t\t\t\tID Number: %d\n",s1.idnum);
							printf("\n\n\t\t\t\t\t\t\tName: %s\n",s1.name);
							textcolor(10);
							printf("\n\n\n\t\t\t\t\t\t\tDo you want to continue transfer to ID account or back to menu (Y/N): ");
							textcolor(15);
							fflush(stdin);
							scanf("%c",&choice2);
							//Transfer
							if (choice2 == 'Y')
							{	
								fclose(f);
								f = fopen(filePath,"r");
								while (!feof(f))
									{
										read(f);
										if (idinput==s1.idnum) 
											{	
												printf("\n\n\t\t\t\t\t\t\tYour balance amount:%d",s1.bal);
												printf("\n\n\n\t\t\t\t\t\t\tInput amount you want to transfer:");
												scanf("%d",&moneytrans);
												//Check moneytrans with balance
												if (moneytrans>s1.bal) 
													{	fflush(stdin);
														printf("\n\n\n\t\t\t\t\t\t\tYour account cannot afford to transfer");
														printf("\n\n\n\t\t\t\t\t\t\tYou have %d in account:",s1.bal);
														goto Question;
													} else 
														{
															s1.balminus = s1.bal - moneytrans;
															printf("\n\n\t\t\t\t\t\t\tRemain in account: %d",s1.balminus);
															
														}
											} 
									}
							fclose(f);
							f = fopen(filePath,"r");
							//Updated money of reciver	
								while (!feof(f))
								{
									read(f);
									if (idinput1==s1.idnum)
									{
										s1.baladd = s1.bal + moneytrans;
									}
								}
							textcolor(10);
							printf("\n\n\n\n\t\t\t\t\t\t\tTRANSFER SUCCESSFUL");
							textcolor(15);
							
							} else goto menu;
						}
					}
						if (suc==0)
						{
							printf("\n\n\t\t\t\t\t\t\tCan not find the person of ID Number: \n");
							goto Question;
						}
						fclose(f);
						//Scan intro new file
						f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","r");
						FILE *fup =fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\FileUpdate.txt","a+");
						int ssptr =0;
						while (!feof(f))
								{		
										read(f);
										if (s1.idnum==ssptr) break;
										if ((s1.idnum)==(idinput)) printnew3(fup);
										else if ((s1.idnum)==idinput1) printnew2(fup);
												else print(fup);
											 
										ssptr=s1.idnum;
								}
						fclose(fup);
						fclose(f);
						//Create Null file Account
						f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","w");
						fclose(f);
						//Update file Account
						fup =fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\FileUpdate.txt","r");
						ssptr=0;
						while (!feof(fup))
						{
							read(fup);
							f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","a+");
							if (s1.idnum==ssptr) break;
							print(f);
							ssptr=s1.idnum;
							fclose(f);
						}
							fclose(fup);
							fup=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\FileUpdate.txt","w");
							fclose(fup);			
						//Update transaction
							counttrans++;
							FILE *ftrs=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Transaction.txt","a+");
							FILE *f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","r");
							while (!feof(f))
								{
									read(f);
									if(idinput == s1.idnum)
										{
											fprintf(ftrs,"\n\nTransaction ID: %d",counttrans);
											fprintf(ftrs,"\nID Number: %d",s1.idnum);
											fprintf(ftrs,"\nType: Transfer");
											fprintf(ftrs,"\nFromUser ID: %d",s1.idnum);
											fclose(f);
											FILE *f=fopen("E:\\Study in IU\\C\\Mini Project\\ATM_Machine\\Account.txt","r");
											while (!feof(f))
											{
												read(f);
												if(idinput1 == s1.idnum) 
													{
														fprintf(ftrs,"\nToUser ID: %d",s1.idnum);
														break;
													}
											}
											fprintf(ftrs,"\nAmount: %d",moneytrans);
											break;
											
										}
									}
							fclose(f);
							fclose(ftrs);	
					break;
				}//Finish case transfer
				case 6://End
					{
						break;
					}
			}
				
	//Continued to do the menu nor not
	Question:{ 
				textcolor(10);
				printf("\n\n\t\t\t\t\t\t\tContinued or not Y/N: ");
				fflush(stdin);
				textcolor(15);
				scanf("%c",&c);
				if ((c=='Y')||(c=='y')) goto menu ; else 
				{
					system("cls");
					Decor ();
					//printf("Thanks for using my service");
					break;
				}
			}
	}
	}
	}
	//Login unccessful
	if (success==0) 
	{	printf("\n\n");
		printf("\t\t\t\t\t\tID or Password is incorrect.\n"); 
		if (countlog>0)
		{	textcolor(10);
			printf("\t\t\t\t\t\tYou have %d times to login\n",countlog--);
			textcolor(15);
		printf("\n\t\t\t\t\t\tLogin again or not Y/N: ");
		fflush(stdin);
		scanf("%c",&c);
		if ((c=='Y')||(c=='y')) goto login ; else
				 {
					system("cls");
					Decor();
					//printf("Thanks for using my service");
				}
		} else
			{
				printf("\n\t\t\t\t\tWait for 5s to log in again\n"); 
				for (int cnt=1;cnt<=5;cnt++){
				printf("\n\t\t\t\t\t%d\n", cnt);
				wait(1);}
				system("cls"); goto login;
			}
			
	}
	}

return 0;
}
