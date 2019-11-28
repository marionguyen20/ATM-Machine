#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
//#include "MiniProject1.h"
#include <time.h>
void blingbling(){
	printf("******\t******\t******\t\t**     **   **\n");
	printf("**    \t**    \t**    \t\t  ** **    ** **\n");
	printf("******\t******\t******\t\t   **     *******\n");
	printf("    **\t**    \t**    \t\t   **    **     **\n");
	printf("******\t******\t******\t\t   **   **       **\n");}
void Bling()
{int move=0;
textcolor(10);
for(int k=0;k<10;k++){
system("cls");
for(int i=0;i<move;i++)
	printf("\n");
	printf("**      **   **   ******  ******\t********  ********   \t******\t******\t******\t  **     **   **\n");
for(int i=0;i<move;i++)
	printf("\n");
	printf("** **   **   **   **      **    \t   **     **    **   \t**    \t**    \t**    \t    ** **    ** **\n");
for(int i=0;i<move;i++)
	printf("\n");
	printf("**  **  **   **   **      ******\t   **     **    **   \t******\t******\t******\t     **     *******\n");
for(int i=0;i<move;i++)
	printf("\n");
	printf("**   ** **   **   **      **    \t   **     **    **   \t    **\t**    \t**    \t     **    **     **\n");
for(int i=0;i<move;i++)
	printf("\n");
	printf("**      **   **   ******  ******\t   **     ********   \t******\t******\t******\t     **   **       **\n");
	printf("\n");
	move++;
		if (move==3) {move=0; continue;}
	Sleep(300);}
	textcolor(7);
}
void MoneyFly()
{	
	textcolor(11);
//	if textcolor(14);
	printf("____________________\n");
	printf("|  --------------  |\n");
	printf("|  )            (  |\n");
	printf("| |     VND      | |\n");
	printf("|  )            (  |\n");
	printf("|  --------------  |\n");
	printf("|__________________|\n");
}


void Run()
{
	printf("\t\t\t\t\t\t\t|||||||||    ||||||||||    ||||||||||    ||||||||     |||||||    |||     |||  ||||||||| \n");
	printf("\t\t\t\t\t\t\t|||          |||    |||    |||    |||    |||    |||   |||   |||   |||   |||   |||\n");
	printf("\t\t\t\t\t\t\t|||  ||||    |||    |||    |||    |||    |||     |||  |||||||||      |||      ||||||||| \n");
	printf("\t\t\t\t\t\t\t|||   |||    |||    |||    |||    |||    |||    |||   |||     |||    |||      ||| \n");
	printf("\t\t\t\t\t\t\t|||||||||    ||||||||||    ||||||||||    ||||||||     |||||||||||    |||      ||||||||| \n");
}
void Goodbye()
{	int move=0;
	while(1){
		system("cls");
		printf("\n\n\n");
		textcolor(10);
		for (int i=0;i<=move;i++)
			printf("\t");
		printf("|||||||||    ||||||||||    ||||||||||    ||||||||     |||||||    |||     |||  |||||||||\n");
		for (int i=0;i<=move;i++)
			printf("\t");
		printf("|||          |||    |||    |||    |||    |||    |||   |||   |||   |||   |||   |||\n");
		for (int i=0;i<=move;i++)
			printf("\t");
		printf("|||  ||||    |||    |||    |||    |||    |||     |||  |||||||||      |||      |||||||||\n");
		for (int i=0;i<=move;i++)
			printf("\t");
		printf("|||   |||    |||    |||    |||    |||    |||    |||   |||     |||    |||      |||\n");
		for (int i=0;i<=move;i++)
			printf("\t");
		printf("|||||||||    ||||||||||    ||||||||||    ||||||||     |||||||||||    |||      |||||||||\n");
		move++;
		if (move==15) {move=0; continue;}
		Sleep(150);}}
void niceto()
{
	printf("**      **   **   ******  ******\t********  ********\n");
	printf("** **   **   **   **      **    \t   **     **    **\n");
	printf("**  **  **   **   **      ******\t   **     **    **\n");
	printf("**   ** **   **   **      **    \t   **     **    **\n");
	printf("**      **   **   ******  ******\t   **     ********\n");
}

int Decor(){
//	Run();
//	for(int i=0;i<256;i++)
//	{textcolor(i);printf("hello");}
//	MoneyFly();
	Goodbye();
//	blingbling();
Bling();
//niceto();
/*while(1)
{	for(int i=0;i<10;i++) {system("cls");Sleep(50);}
	printf("hello");}*/
	return 0;
}
