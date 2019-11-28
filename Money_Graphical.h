#include <stdio.h>
#include <conio.h>
#include <Windows.h>

/*void textcolor(int x)
{	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
void tomau(int x, int y, char *a, int color)
{ 	gotoxy(x, y); 	
	textcolor(color); 	
	printf("%s",a);
	textcolor(7);
}*/
int money()
{
	printf("\n \n");
	textcolor(3);
	printf("\t\t\t\t\t\t\t\t\tINPUT THE AMOUNT OF MONEY\n\n");
	printf("\n\t\t\t*******************************************************************************************************************************\n");
	printf("\t\t\t*                                                                                                                               *\n");
	printf("\t\t\t*                                                                                                                               *\n");
	textcolor(12);
	printf("\t\t\t*     =========================================\t\t\t\t            =========================================   *\n");
	printf("\t\t\t*     \\\\            1.50.000 VND             //\t\t\t\t            \\\\\          4. 500.000 VND             //   *\n");
	printf("\t\t\t*     //                                     \\\\\t\t\t\t            //                                     \\\\   *\n");
	printf("\t\t\t*     =========================================\t\t\t\t            =========================================   *\n");
	for (int i=1;i<3;i++) 
	printf("\t\t\t*                                                                                                                               *\n");
	textcolor(14);
    printf("\t\t\t*     =========================================\t\t\t\t            =========================================   *\n");
	printf("\t\t\t*     \\\\            2.100.000 VND            //\t\t\t\t            \\\\\           5.1.000.000 VND           //   *\n");
	printf("\t\t\t*     //                                     \\\\\t\t\t\t            //                                     \\\\   *\n");
	printf("\t\t\t*     =========================================\t\t\t\t            =========================================                    *\n");
	for (int i=1;i<3;i++) 
	printf("\t\t\t*                                                                                                                               *\n");
	textcolor(10);
	printf("\t\t\t*     =========================================\t\t\t\t            =========================================   *\n");
	printf("\t\t\t*     \\\\             3. 200.000 VND          //\t\t\t\t            \\\\\            6.Input the money        //   *\n");
	printf("\t\t\t*     //                                     \\\\\t\t\t\t            //                                     \\\\   *\n");
	printf("\t\t\t*     =========================================\t\t\t\t            =========================================   *\n");
	textcolor(3);
	for (int i=1;i<3;i++)
	printf("\t\t\t*                                                                                                                               *\n");
	printf("\t\t\t*******************************************************************************************************************************\n");
	textcolor(7);

		return 0;
}
