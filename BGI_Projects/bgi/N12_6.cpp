#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

#define NORMAL_COLOR YELLOW
#define DANGER_COLOR RED

#define X_MAX 200	// 定義可活動的範圍
#define Y_MAX 200	// 定義可活動的範圍
using namespace std;
void drawFence();

class CMouse
{
public:
	int x, y;
	int status; // 1:正常狀態, 2:在邊界上, 0: 死亡
	int color;

	void init() {
		x = 0; y = 0;
		status = 1;
		color = NORMAL_COLOR;
	}
	int update(char cIn);
	void draw()
	{
		drawColorBox(x, y, color); // 畫出老鼠
	}
};
int CMouse::update(char cIn)
{
	switch (cIn) {
	case 'w': // 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
		y = y + 20; break;
	case 's': // 往下
		y = y - 20; break;
	case 'a': // 往左
		x = x - 20; break;
	case 'd': // 往右
		x = x + 20; break;
	}
	if (x > -X_MAX && x < X_MAX && y > -Y_MAX && y < Y_MAX) { // 安全區域內
		status = 1; color = NORMAL_COLOR;
	}
	else if (x < -X_MAX || x > X_MAX || y < -Y_MAX || y > Y_MAX) {
		status = 0; // 移除邊界 老鼠死亡 遊戲結束			
	}
	else {	// 在邊界上
		status = 2; color = DANGER_COLOR;
	}
	return (status);
}

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N12-6 老鼠控制的物件導向設計");
	char cIn;
	int status;
	CMouse mx1;
	mx1.init();
	status = mx1.status;
	while (status != 0)
	{
		cleardevice();
		drawFence(); // 畫出範圍
		mx1.draw();	// 畫出老鼠
		swapbuffers();
		cIn = getch();
		status = mx1.update(cIn);
		rewind(stdin);
	}
	cleardevice();
	drawFence();
	setcolor(COLOR_WHITE);
	outtextxy(X(-100), Y(0), "!! 1 號老鼠死了 GG 按任意鍵繼續!! ");
	swapbuffers();
	while (!kbhit()) { delay(200); }

	CMouse mx2;
	mx2.status = 1;
	mx2.x = 20; mx2.y = 20;
	mx2.color = NORMAL_COLOR;
	status = mx2.status;
	while (status != 0)
	{
		cleardevice();
		drawFence(); // 畫出範圍
		mx2.draw();	// 畫出老鼠
		swapbuffers();
		cIn = getch();
		status = mx2.update(cIn);
		rewind(stdin);
	}
	cleardevice();
	drawFence();
	setcolor(COLOR_WHITE);
	outtextxy(X(-100), Y(0), "!! 2 號老鼠死了 GG 按任意鍵結束!! ");
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