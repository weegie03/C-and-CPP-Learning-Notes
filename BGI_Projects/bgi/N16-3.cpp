#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

using namespace std;

class CCharacter {
protected:
	int  _ix, _iy, _icolor;	// 座標與顏色
public:
	CCharacter(int ix=0, int iy=0, int icolor=COLOR_WHITE) { _ix = ix; _iy = iy; _icolor = icolor; }
	virtual void draw() { drawBoxMan(_ix, _iy, _icolor); }
};
class CMouse : public CCharacter {
private:
	int _ishape;	// 設定不同的外型
public:
	CMouse(int x, int y, int color, int ishape = 1) : CCharacter(x, y, color) { _ishape = ishape; }
	void draw() { 
		if( _ishape == 1)  drawBoxMan(_ix, _iy, _icolor, COLOR_RED);
		else {
			drawSizeBox(_ix - 24, _iy + 60, COLOR_LIGHTBLUE, 22); // 左耳朵
			drawSizeBox(_ix + 24, _iy + 60, COLOR_LIGHTBLUE, 22); // 右耳朵	
			drawBoxMan(_ix, _iy, _icolor, COLOR_RED, COLOR_LIGHTMAGENTA);
		}
	}
};

void drawCharacter(CCharacter ch) { ch.draw(); } // 一般函式
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N16-3 虛擬函式(傳值)");
	CCharacter npc1(-100, 100, 12), npc2(100, 100, 12);
	CMouse m1(-100, -50, 2, 2), m2(100, -50, 2, 2);
	npc1.draw(); m1.draw();
	drawCharacter(npc2); drawCharacter(m2); // 顯示角色
	while (!kbhit()) { delay(200); } return 0;
}
