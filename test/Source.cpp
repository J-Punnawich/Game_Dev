#include<stdio.h>
#include<windows.h>
#include<conio.h>
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x,int y)
{
	gotoxy(x, y); printf(" <-0-> ");
}
int main()
{
	char ch = '.';
	int x = 38, y = 20;
	
	
	do { 
		draw_ship(x,y);
		if (_kbhit()) {
			ch =_getch();
			
			if (ch == 'a') { gotoxy(--x, y); }
			 if (ch == 'd') { gotoxy(++x, y); }
			 if (ch == 's') { gotoxy(x, ++y); }
			 if (ch == 'w') { gotoxy(x, --y); }
			fflush(stdin);
		}
		Sleep(50);
	} while (ch != 'x');
	return 0;
}