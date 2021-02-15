#include<stdio.h>
#include<Windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include<stdbool.h>
#pragma warning(disable:4996)

#define use_CRT_SECURE_NO_WARNINGS
#define ENTER 13
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int main();
void Keyboard_screen();
void first();
void gotoxy();
void choice();
void check();
void check_PW();
int key();
void print();
void screen();
void choice();
void buy_screen();
void check();
FILE* fp1, * fp2, * fp3, * fp4;

char file1[100];
char file2[100];
char file3[100];
char file4[100];
char ID[30];
char PW[30];
int mapx;
int mapy;
int No_1;
int No_2;
int x;
int y;
int check_block;
int num;