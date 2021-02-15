#include"head.h"
void first() {//첫 화면 입니다 
	int x=30, y=4;
	gotoxy(x, y++);
	printf("  ■■■■     ■■■■   ■          ■");
	gotoxy(x, y++);
	printf("■        ■ ■        ■ ■          ■");
	gotoxy(x, y++);
	printf("■           ■            ■        ■");
	gotoxy(x, y++);
	printf("■           ■             ■      ■");
	gotoxy(x, y++);
	printf("■           ■              ■    ■");
	gotoxy(x, y++);
	printf("■           ■      ■■■   ■  ■");
	gotoxy(x, y++); 
	printf("■        ■ ■        ■■    ■■");
	gotoxy(x, y++);
	printf("  ■■■■     ■■■■  ■     ■");
	gotoxy(x, y++);
	gotoxy(x, y++);
	if(ID!='a')
	{
		gotoxy(36, 14);
		printf("%s", ID);
	}
	gotoxy(x, y++);
	printf("  ID :");
	gotoxy(x, y++);
	if (PW != 'a')
	{
		gotoxy(36, 16);
		printf("%s", PW);
	}
	gotoxy(x, y++);
	printf("  PW :");
	gotoxy(x, y++);
	gotoxy(x, y++);
	printf("  로그인");
	gotoxy(x, y++);
	gotoxy(x, y++);
	printf("  회원가입");
	gotoxy(x, y++);
	gotoxy(x, y++);
	printf("  ※회원가입을 먼저해주세요!※");
}
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}