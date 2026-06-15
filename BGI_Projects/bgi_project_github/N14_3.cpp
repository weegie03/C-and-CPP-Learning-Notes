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
	~CMouse() {
		delete _pcolor;
	};
	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
	friend void drawM(CMouse m) {
		drawBoxMan(m._ix, m._iy, *(m._pcolor));
	}
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-3 動態記憶體配置 資源的不預警釋放");
	CMouse mx(0, 100, 3); // 建立時就會自動呼叫CMouse 建構元
	drawM(mx);
	while (!kbhit()) { delay(200); } return 0;
}