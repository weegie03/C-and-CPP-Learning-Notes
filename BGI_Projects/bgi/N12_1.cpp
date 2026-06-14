#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED
#define X_MAX 200
#define Y_MAX 200
#define p1
#ifdef p
using namespace std;
//void drawMouse();
void drawFence();

//int x = 0, y = 0;
//int status = 1; // 1:正常狀態, 2:在邊界上, 0: 死亡
//int color = NORMAL_COLOR;

class CMouse//class宣告的東西叫類別 
{
private:
	int x, y;//類別中的變數叫做成員變數
	int status;
	int color;

public:
	int init();//類別中的函式叫成員函式 或叫行為或方法
	//void drawsColor(int nc, int dc);
	void draw();
	int update(char ch);
	void setXY(int ix, int iy);
	int getStatus() { return(status); }
	
};
void CMouse::setXY(int ix, int iy)//窗口
{
	//要先檢查
	if (ix > X_MAX) ix = X_MAX; 
	else if (ix < -X_MAX) ix = -X_MAX;
	if (iy > Y_MAX) iy = Y_MAX;
	else if (iy < -Y_MAX) iy = -Y_MAX;

	x = ix, y = iy;

	if ((x == X_MAX || x == -X_MAX || y == Y_MAX || y == -Y_MAX))
	{
		status = 2;
		color = DANGER_COLOR;
	}
}
void CMouse::draw()
{
	drawColorBox(x, y, color);
}
int CMouse::init()
{
	x = 0, y = 0;
	status = 1;
	color = NORMAL_COLOR;
	return(status);
}
//int getStatus(CMouse m)//友誼函式不是類別的成員函式所以不用::的寫法
//{
//	return(m.status);
//}



int CMouse::update(char ch)//把類別中的行為方法或函式寫在類別外時
{//把函式主體搬出來<回傳值類別放前面<在函式面前打上類別名稱<::後面這串屬於這一個類別中的函式
	switch (ch) {
	case 'w': // 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
		y = y + 20;
		break;
	case 's': // 往下
		y = y - 20;
		break;
	case 'a': // 往左
		x = x - 20;
		break;
	case 'd': // 往右
		x = x + 20;
		break;
	}
	// 根據目前的移動結果改變老鼠的狀態
	if (x > X_MAX || x<-X_MAX || y>Y_MAX || y < -Y_MAX)
	{
		status = 0;
	}
	else
	{
		if ((x == X_MAX || x == -X_MAX || y == Y_MAX || y == -Y_MAX))
		{
			status = 2;
			color = DANGER_COLOR;
		}
		else
		{
			status = 1;
			color = NORMAL_COLOR;
		}
	}
	return(status);
}
//inline void drawMouse()
//{
//	drawColorBox(x, y, color); // 畫出老鼠
//}
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N12-1 老鼠控制的程序導向設計");
	char cIn;
	CMouse m;//拿CMouse宣告告一個1變數//物件
	int status;
	status = m.init();//物件呼叫自己的行為(物件.函式/物件.變數可以直接存取 限公有
	m.setXY(300, 0);
	status = m.getStatus();//取得正確狀態	//m.init();//呼叫他的init 設他的初始值 
	//status = 1;//正常
	do
	{
		cleardevice();//畫面清成黑色的
		drawFence(); // 畫出範圍
		m.draw();		//drawMouse();
		swapbuffers();
		cIn = getch();//不用按下enter建也可以接收字元
		status = m.update(cIn);//去接收狀態
		rewind(stdin);
	} while (status != 0);
	//while (status != 0)//改成do while 的寫法
	//{	
	//}
	
	cleardevice();
	drawFence();
	setcolor(COLOR_WHITE);
	outtextxy(X(-100), Y(0), "!! 老鼠死了 GG 按任意鍵結束!! ");
	swapbuffers();

	while (!kbhit()) { delay(200); } return 0;
}


void drawFence()
{
	for (int i = -200; i <= 200; i += 20) {
		drawColorBox(i, 200, COLOR_LIGHTGREEN);
		drawColorBox(i, -200, COLOR_LIGHTGREEN);
	}
	for (int i = -180; i <= 180; i += 20) {
		drawColorBox(-200, i, COLOR_LIGHTGREEN);
		drawColorBox(200, i, COLOR_LIGHTGREEN);
	}
}
#endif