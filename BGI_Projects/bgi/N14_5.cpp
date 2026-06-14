#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

using namespace std;

class CMouse
{
private:
	int _ix, _iy, *_pcolor;
public:
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) { 
		_pcolor = new int; 	*_pcolor = color; _ix = x; _iy = y;
	}
	CMouse(const CMouse &ma) {	// 建構元
		_ix = ma._ix; _iy = ma._iy; // 老鼠的起始位置
		_pcolor = new int; // 取得空間
		*_pcolor = *(ma._pcolor); // 將傳入的老鼠圖示填入
		outtextxy(X(-60), Y(0), "拷貝建構元被呼叫");
	}
	~CMouse() { delete _pcolor; };
	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
	friend void drawM(CMouse m) { drawBoxMan(m._ix, m._iy, *(m._pcolor)); }
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-5 動態記憶體配置 資源的不預警釋放");
	CMouse mx(0, 100, 12); // 建立時就會自動呼叫CMouse 建構元
	mx.draw(); // 讓老鼠自己畫出自己的位置
	while (!kbhit()) { delay(200); } return 0;
}