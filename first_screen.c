#include"head.h"
void first() {//ù ȭ�� �Դϴ� 
	int x=30, y=4;
	gotoxy(x, y++);
	printf("  �����     �����   ��          ��");
	gotoxy(x, y++);
	printf("��        �� ��        �� ��          ��");
	gotoxy(x, y++);
	printf("��           ��            ��        ��");
	gotoxy(x, y++);
	printf("��           ��             ��      ��");
	gotoxy(x, y++);
	printf("��           ��              ��    ��");
	gotoxy(x, y++);
	printf("��           ��      ����   ��  ��");
	gotoxy(x, y++); 
	printf("��        �� ��        ���    ���");
	gotoxy(x, y++);
	printf("  �����     �����  ��     ��");
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
	printf("  �α���");
	gotoxy(x, y++);
	gotoxy(x, y++);
	printf("  ȸ������");
	gotoxy(x, y++);
	gotoxy(x, y++);
	printf("  ��ȸ�������� �������ּ���!��");
}
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}