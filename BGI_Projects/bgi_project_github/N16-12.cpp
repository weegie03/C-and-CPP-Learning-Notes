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
	CCharacter(int ix=0, int iy=0, int icolor= 3) {_ix = ix; _iy = iy; _icolor = icolor; }
	virtual ~CCharacter() { cout << "CCharacter 解構元被呼叫" << endl; }
	void setPos(int ix, int iy) { _ix = ix; _iy = iy; }
	virtual void draw() = 0; //虛擬函式
};
class CAnimal : public CCharacter {
protected:
	int _ihp;
public:
	CAnimal(int ihp, int icolor = 15) : CCharacter(0,0,icolor) { _ihp = ihp; }
	~CAnimal() { cout << "CAnimal 解構元被呼叫" << endl; }

};
class CMouse : public CAnimal {
public:
	CMouse(int icolor= 10, int ihp = 10) : CAnimal(ihp, icolor) {}
	~CMouse() { cout << "CMouse 解構元被呼叫" << endl; }
	void draw() {
		char str[20]; sprintf(str, "HP = %2d", _ihp); outtextxy(X(_ix + 60), Y(_iy), str);
		drawBoxMan(_ix, _iy, _icolor, COLOR_BLUE);
	}
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N16-12 多層次繼承下的虛擬結構元");
	CMouse mx( 2, 50); mx.setPos(0, 100); mx.draw();
	CCharacter *pChar = new CMouse;
	pChar->draw();
	delete pChar;
	while (!kbhit()) { delay(200); } return 0;
}