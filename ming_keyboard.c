#include "head.h"
int a;
int number_x=0;
int number_y=0;
int A_check = 0;
int B_check = 0;
int num=0;
int map_x=21, map_y=9;
int seat[15][30] = { {1,1,0,1,1,1,1,1,1,1,1,1,0,1,1},{1,1,0,1,1,1,1,1,1,1,1,1,0,1,1},{1,1,0,1,1,1,1,1,1,1,1,1,0,1,1},{1,1,0,1,1,1,1,1,1,1,1,1,0,1,1},
    {1,1,0,1,1,1,1,1,1,1,1,1,0,1,1}, {1,1,0,1,1,1,1,1,1,1,1,1,0,1,1}, {1,1,0,1,1,1,1,1,1,1,1,1,0,1,1},{1,1,0,1,1,1,1,1,1,1,1,1,0,1,1},
    {1,1,0,1,1,1,1,1,1,1,1,1,0,1,1}, {1,1,0,1,1,1,1,1,1,1,1,1,0,1,1}, {1,1,0,1,1,1,1,1,1,1,1,1,0,1,1},{1,1,0,1,1,1,1,1,1,1,1,1,0,1,1} };
int key(void) {
    char c;
    c = _getch();        
    if (c == -32) {
        c = _getch();        
        switch (c) {
        case UP:
            if (mapy > 14) {
                mapy--;
            }
            break;
        case DOWN:
            if (mapy < 20) {
                mapy++;
            }
            break;
        }
    }
    else if (c == ENTER) {
        if (mapy == 14) {
            gotoxy(36, 14);
            scanf_s("%s", ID, sizeof(ID));
            fopen_s(&fp2, "IDcheck.txt", "wt");
            fprintf(fp2, "%s\n", ID);
            fclose(fp2);
        }
        if (mapy == 16) {
            gotoxy(36, 16);
            scanf_s("%s", PW, sizeof(PW));
            fopen_s(&fp4, "PWcheck.txt", "wt");
            fprintf(fp4, "%s\n", PW);
            fclose(fp4);
        }

        if (mapy == 18) {
            check();
            check_PW();
            if (A_check == 1&& B_check == 1) {
                screen();
                while (1) {
                    Keyboard_screen(x, y);
                }
            }
            else {
                exit(1);
            }
        }
        if (mapy == 20) {
            gotoxy(40, 20);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            printf("회원이 되셨습니다!");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            Sleep(1000);
        }
    }
}

void choice() {
    mapx = 60;
    mapy = 14;
    while (1) {
        first();
        gotoxy(mapx, mapy);
        printf("◀");
        key();
        system("cls");
    }
}


void screen(){

    int x = 10, y = 2;
    int a = 21, b = 9;
    int c = 19, d = 54;
    char seatn = 'A';
    

    gotoxy(x, y++);
    printf(" ■■■    ■■■  ■■■  ■■■ ■■■ ■    ■");
    gotoxy(x, y++);
    printf("■       ■     ■ ■   ■ ■     ■     ■■  ■");
    gotoxy(x, y++);
    printf(" ■■■  ■        ■■■  ■■■ ■■■ ■ ■ ■");
    gotoxy(x, y++);
    printf("      ■ ■     ■ ■   ■ ■     ■     ■  ■■");
    gotoxy(x, y++);
    printf(" ■■■    ■■■  ■   ■ ■■■ ■■■ ■    ■");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    gotoxy(21, 8);
    printf("A B   C D E F G H I J K   L M");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);


    gotoxy(a++, b);
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 30; j++) {
            if (seat[i][j] == 1)
            {
                printf("□");
            }
            else if (seat[i][j] == 0) {
                printf("  ");
            }
            else if (seat[i][j] == 2) {
                printf("▣");
            }
            else
                printf("■");
        }
        gotoxy(a = 21, b++);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    b = 9;
    for (int i = 0; i < 11; i++) {
        gotoxy(c, b++);
        printf("%c", seatn++);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    gotoxy(d, 10);
    printf("총 128석");

    gotoxy(d, 11);

    printf("잔여");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
    printf("%d", 128 - num);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("석");
    

    gotoxy(d, 15);
    printf("선택 : ▣");

    gotoxy(d, 16);
    printf("예매 가능 : □");

    gotoxy(d, 17);
    printf("예매 불가 : ■ ");
    gotoxy(80, 20);


    
}

void Keyboard_screen(int x, int y) {

    char c;
    c = _getch();
    if (c == -32) {
        c = _getch();
        switch (c) {
        case LEFT:
            if (map_x > 21) {
                if (map_x != 27 && map_x !=47) {
                    number_x-=1;
                    if (seat[number_y+1][number_x+1] == 3) {
                        gotoxy(map_x, map_y);
                        printf("■");
                    }
                    else if (seat[number_y+1][number_x+1] == 1) {
                        gotoxy(map_x, map_y);
                        printf("□");
                    }
                    gotoxy(map_x -= 2, map_y);
                    printf("▣");
                }
                else {
                    number_x-=2;
                    gotoxy(map_x, map_y);
                    printf("□");
                    gotoxy(map_x -= 4, map_y);
                    printf("▣");
                }
            }
                break;
            
        case RIGHT:
            if (map_x < 48) {
                if (map_x != 23 && map_x != 43) {
                    number_x+=1;
                    if (seat[number_y + 1][number_x-1] == 3) {
                        gotoxy(map_x, map_y);
                        printf("■");
                    }
                    else if (seat[number_y + 1][number_x-1] == 1) {
                        gotoxy(map_x, map_y);
                        printf("□");
                    }
                    gotoxy(map_x += 2, map_y);
                    printf("▣");
                }
                else {
                    number_x+=2;
                    gotoxy(map_x, map_y);
                    printf("□");
                    gotoxy(map_x += 4, map_y);
                    printf("▣");
                }
            }
            break;
        case UP:
            if (map_y > 9) {
                number_y-=1;
                if (seat[number_y+2][number_x] == 3) {
                    gotoxy(map_x, map_y);
                    printf("■");
                }
                else if (seat[number_y+2][number_x] == 1) {
                    gotoxy(map_x, map_y);
                    printf("□");
                }
                gotoxy(map_x, map_y -= 1);
                printf("▣");
            }
            break;
        case DOWN:
            if (map_y < 19) {
                number_y+=1;
                if (seat[number_y][number_x] == 3) {
                    gotoxy(map_x, map_y);
                    printf("■");
                }
                else if (seat[number_y][number_x] == 1) {
                    gotoxy(map_x, map_y);
                    printf("□");
                }
                gotoxy(map_x, map_y += 1);
                printf("▣");
            }
            break;
        }
    }
    else if (c == ENTER) {
        if (seat[number_y + 1][number_x] != 3) {
            num++;
            seat[number_y + 1][number_x] = 3;
            system("cls");
            buy_screen();
            screen();
        }
    }
}
void buy_screen() {
}
void check() {

    FILE* a = fopen("ID.txt", "rt");
    FILE* b = fopen("IDcheck.txt", "rt");
    char aString[512];
    char bString[512];
    int i = 0, aLength, bLength, out;
    bool check = true;
    while (1)   
    {
        /* 두 파일이 모두 읽혀졌다면 탈출합니다. */
        out = 0;
        if (fgets(aString, 512, a) == 0)
            out++;
        if (fgets(bString, 512, b) == 0)
            out++;
        if (out == 2)
            break;
        /* 읽혀지는 길이가 다르다면 탈출합니다. */
        aLength = strlen(aString);
        bLength = strlen(bString);
        if (aLength != bLength)
        {
            check = false;
        }
        /* 읽혀진 문자가 하나라도 다르다면 탈출합니다. */
        for (int i = 0; i < aLength; i++)
        {
            if (aString[i] != bString[i])
            {
                check = false;
            }
        }
        if (!check)
        {
            break;
        }
    }
    if (check)
    {
        printf("하이엽");
        A_check = 1;
        system("cls");
    }
    else
    {
        printf("아이디 또는 비번이 다릅니다");
        exit(1);
    }
    fclose(a);
    fclose(b);
}
void check_PW() {

    FILE* a = fopen("PW.txt", "rt");
    FILE* b = fopen("PWcheck.txt", "rt");
    char aString[512];
    char bString[512];
    int i = 0, aLength, bLength, out;
    bool check = true;
    while (1)
    {
        /* 두 파일이 모두 읽혀졌다면 탈출합니다. */
        out = 0;
        if (fgets(aString, 512, a) == 0)
            out++;
        if (fgets(bString, 512, b) == 0)
            out++;
        if (out == 2)
            break;
        /* 읽혀지는 길이가 다르다면 탈출합니다. */
        aLength = strlen(aString);
        bLength = strlen(bString);
        if (aLength != bLength)
        {
            check = false;
        }
        /* 읽혀진 문자가 하나라도 다르다면 탈출합니다. */
        for (int i = 0; i < aLength; i++)
        {
            if (aString[i] != bString[i])
            {
                check = false;
            }
        }
        if (!check)
        {
            break;
        }
    }
    if (check)
    {
        if (A_check == 1) {
            B_check = 1;
        }
        else {
            printf("아이디 또는 비번이 다릅니다");
            exit(1);
        }
    }
    else
    {
        printf("아이디 또는 비번이 다릅니다");
        exit(1);
    }
    fclose(a);
    fclose(b);
}