#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p6
#ifdef p
using namespace std;
struct sCircle
{
	char name[10];
	int x, y;
	int rad;
	int r, g, b;
};
void genC(sCircle&cc,int num);
void drawC(sCircle cc[], int n);
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "p6");
	registermousehandler(WM_MOUSEMOVE, move_handler);
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);
	registermousehandler(WM_LBUTTONUP, lbUp_handler);
	srand(time(NULL));
	sCircle cx[6];
	for (int i = 0; i < 6; i++)//此行不能修改
	{
		genC(cx[i], (i + 1));
	}
	drawC(cx, 6);
	while (!kbhit())
	{
		delay(200);
	}
	system("pause"); return(0);
}
void genC(sCircle& cc, int num)
{
	sprintf(cc.name, "%2d", num);//應該直接把傳進來的 num 填進去
	cc.x = -400+num*120;
	cc.y = rand() % 200 - 200;
	cc.rad= num*10 + rand() % 20;
	cc.r = rand() % 155 + 100;
	cc.g = rand() % 155 + 100;
	cc.b = rand() % 155 + 100;
}
void drawC(struct sCircle cc[],int n)
{
	for (int i = 0; i <n; i++)
	{//如果要用指標走訪陣列，必須加上索引 i
		setcolor(COLOR(cc[i].r, cc[i].g, cc[i].b));  // 設定顏色
		outtextxy(X(cc[i].x), Y(cc[i].y), (cc[i].name));
		circle(X(cc[i].x), Y(cc[i].y), (cc[i].rad));
	}
}

#endif