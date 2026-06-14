#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED

#define X_MAX 200	// 定義可活動的範圍
#define Y_MAX 200	// 定義可活動的範圍
using namespace std;
void drawFence();

bool g_bBoss = false; // 全域變數。false: 正常狀態，true: 隱藏狀態

class CMouse
{
private:
	int _ix, _iy, _icolor;
	int _istatus; // 1:正常狀態, 2:在邊界上, 0: 死亡
	int _ncolor, _dcolor;
public:
	CMouse() {  
		_ix = 0; _iy = 0;	// 老鼠的起始位置
		_istatus = 1;		// 1 : 正常狀態, 2: 離開邊界0: 死亡狀態
		_icolor = _ncolor = NORMAL_COLOR; _dcolor = DANGER_COLOR;	// 設定老鼠的初始顏色為 mcolor[0]
	}
	void draw();
	void setColor(int ncolor, int dcolor) { _icolor = _ncolor = ncolor; _dcolor = dcolor; };
	int update(char cIn);
	int getStatus() { return (_istatus); }
};

void CMouse::draw() {
	if ( g_bBoss) {
		drawBoxMan(0, 0, COLOR_WHITE);
	}
	else drawColorBox(_ix, _iy, _icolor); 
}

int CMouse::update(char cIn)
{
	switch (cIn) {
	case 'w': // 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
		_iy = _iy + 20; break;
	case 's': // 往下
		_iy = _iy - 20; break;
	case 'a': // 往左
		_ix = _ix - 20; break;
	case 'd': // 往右
		_ix = _ix + 20; break;
	}
	if (_ix > -X_MAX && _ix < X_MAX && _iy > -Y_MAX && _iy < Y_MAX) { // 安全區域內
		_istatus = 1; _icolor = _ncolor;
	}
	else if (_ix < -X_MAX || _ix > X_MAX || _iy < -Y_MAX || _iy > Y_MAX) {
		_istatus = 0; // 移除邊界 老鼠死亡 遊戲結束			
	}
	else {	// 在邊界上
		_istatus = 2; _icolor = _dcolor;
	}
	return (_istatus);
}

int main()
{
	char cIn;
	int status;
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-11 全域變數的使用");
	CMouse mx;
	mx.setColor(COLOR_CYAN, COLOR_LIGHTBLUE); // 設定新的顏色
	status = mx.getStatus();
	while (status != 0)
	{
		cleardevice();
		drawFence(); // 畫出範圍
		mx.draw();	// 畫出老鼠
		swapbuffers();
		cIn = getch();
		if (cIn == 'b') g_bBoss = !g_bBoss;  //判斷是否按下按鍵 b
		status = mx.update(cIn);
		fflush(stdin);
	}
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