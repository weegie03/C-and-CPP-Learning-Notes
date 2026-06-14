#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p14
#ifdef p
#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED

#define X_MAX 200	// 定義可活動的範圍
#define Y_MAX 200	// 定義可活動的範圍
using namespace std;

class CSticker {
private:
	int  _ix, _iy, _icolor;	// 圖示的位置與顏色
public:
	CSticker() {
		_ix = rand() % 600 - 300; // 以亂數產生座標
		_iy = rand() % 600 - 300;
		_icolor = rand() % 15 + 1;  // 顏色隨機選擇 1 到 15
	}
	void draw() { drawColorBox(_ix, _iy, _icolor); }

	bool touchDown(int x, int y)
	{
		if (x >= _ix && y >= _iy)
		{
			_icolor = COLOR_RED; // 觸發成功：把顏色變成紅色（表示被點到了）
			return true;
		}
		else return false;
	}
};

class CPainter {
private:
	CSticker *psticker; // 指標變數
public:
	CPainter() { psticker = new CSticker[20]; }
	~CPainter() { delete[] psticker; }
	void draw() {
		for (int i = 0; i < 20; i++) (psticker + i)->draw(); // 每一個 sticker 都呼叫 draw
	}
	void touchDown(int x, int y)
	{
		for (int i = 0; i < 20; i++)
		{
			if ((psticker + i)->touchDown(x, y) == true) 
			{
				cout << "點擊到了第" << i << "個粒子！" << endl;
			}
		}
	}
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-14 類別的組合");
	srand((unsigned)time(NULL)); // 設定亂數產生器的初始值
	cleardevice();
	CPainter pic;
	while (!kbhit()) {
		cleardevice();
		pic.draw();      // 畫出所有粒子
		swapbuffers();

		// 【補齊】偵測滑鼠點擊事件
		if (ismouseclick(WM_LBUTTONDOWN)) { // 如果左鍵按下
			int x, y;
			getmouseclick(WM_LBUTTONDOWN, x, y); // 取得點擊的座標 (x, y)

			pic.touchDown(x, y); // 傳遞觸發事件給畫布
		}
	}
	/*pic.draw();

	pic.touchDown(x,y);*/
	swapbuffers();
	while (!kbhit()) { delay(200); } return 0;
}
#endif