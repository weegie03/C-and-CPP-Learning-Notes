#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

using namespace std;
#define p6
#ifdef p

class CCharacter {
protected:
	int  _ix, _iy, _icolor;;	// 座標與顏色
public:
	CCharacter(int ix=0, int iy=0, int icolor= 3) {_ix = ix; _iy = iy; _icolor = icolor; }
	void setPos(int ix, int iy) { _ix = ix; _iy = iy; }
	virtual void draw() = 0; //虛擬函式
};
class CAnimal : public CCharacter {
protected:
	int _ihp;
public:
	CAnimal(int ihp, int icolor = 15) : CCharacter(0,0,icolor) { _ihp = ihp; }
};
class CMouse : public CAnimal {
public:
	CMouse(int icolor= 10, int ihp = 10) : CAnimal(ihp, icolor) {}
	void draw() {
		char str[20];
		sprintf(str, "HP = %2d", _ihp);
		outtextxy(X(_ix + 60), Y(_iy), str);
		drawBoxMan(_ix, _iy, _icolor, COLOR_BLUE);
	}
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N16-9 多層次繼承");
	CMouse mx( 2, 50);
	mx.setPos(0, 100);
	mx.draw();
	CCharacter *pChar = new CMouse;
	pChar->draw();
	delete pChar;
	while (!kbhit()) { delay(200); } return 0;
}
#endif
//class CCharacter
//{
//protected:
//	int _ix, _iy, _icolor;
//public:
//	CCharacter(int ix = 0, int iy = 0, int icolor = 3) :_ix(ix), _iy(iy), _icolor(icolor) {};
//	void setPos(int ix, int iy) { _ix = ix; _iy = iy; }
//	virtual void draw() = 0;
//};
//class CAnimal :public CCharacter
//{
//protected:
//	int _ihp;
//public:
//	CAnimal(int hp, int color = 15) :CCharacter(0, 0, color), _ihp(hp) {};
//};
//class CMouse :public CAnimal
//{
//public:
//	CMouse(int color = 10, int hp = 10) :CAnimal(hp,color) {};
//	void draw() {
//		cout<< "血量 = " << _ihp << endl;
//		cout << "顏色:" << _icolor << " 座標:(" << _ix << "," << _iy << ")" << endl;
//	}
//};
//int main()
//{
//	initwindow(SCREENWIDTH, SCREENWIDTH, "N16-9 多層次繼承模擬");
//	CMouse mx(2, 50);
//	mx.setPos(10, 20);
//	mx.draw();
//	CCharacter* pChar = new CMouse(14,99);
//	pChar->draw();
//	delete pChar;
//	while (!kbhit()) { delay(200); }
//	return 0;
//}
