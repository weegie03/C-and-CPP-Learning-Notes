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
	int  _ix, _iy, _icolor;;	// 座標與顏色
public:
	CCharacter(int ix=0, int iy=0, int icolor= COLOR_LIGHTGREEN) { _ix = ix; _iy = iy; _icolor = icolor; }
	~CCharacter() { cout << "CCharacter 解構元被呼叫" << endl; }
	void setPos(int ix, int iy) { _ix = ix; _iy = iy; }
	virtual void draw() { drawBoxMan(_ix, _iy, _icolor); }; //虛擬函式
};
class CMouse : public CCharacter {
public:
	CMouse(int x=0, int y = 0, int color= COLOR_LIGHTRED) : CCharacter(x, y, color) {}
	~CMouse() { cout << "CMouse 解構元被呼叫" << endl; }
	void draw() { 
		drawSizeBox(_ix , _iy + 60, COLOR_WHITE, 30); drawBoxMan(_ix, _iy, _icolor, COLOR_BLUE);
	}
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N16-7 虛擬結構元");
	CCharacter *pc2c = new CCharacter;
	CCharacter *pc2m = new CMouse;
	CMouse *pm = new CMouse;
	delete pc2c;
	delete pm;
	delete pc2m;
	while (!kbhit()) { delay(200); } return 0;
}
