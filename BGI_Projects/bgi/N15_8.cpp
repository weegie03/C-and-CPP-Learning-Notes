#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p8
#ifdef p
using namespace std;

class CCharacter {
protected:
	int  _ix, _iy, _icolor;	// 座標與顏色
public:
	CCharacter(int ix=0, int iy=0, int icolor=COLOR_WHITE) { 
		_ix = ix; _iy = iy; _icolor = icolor; 
		cout << "CCharacter 建構元被呼叫" << endl;
	}
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
	void setPos(int ix, int iy) { _ix = ix;  _iy = iy; };
};
class CMouse : public CCharacter {
private:
	int _iattack;	// 設定攻擊力
public:
	CMouse(int x, int y, int color, int ivalue = 10) : CCharacter(x,y,color) { _iattack = ivalue; }
	void showAttack() { cout << "攻擊力=" << _iattack << endl; }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-8 拷貝宣告的處理");
	CMouse mx(0, 0, 14);
	CMouse my(mx);
	CMouse mz = my;
	mx.draw();
	my.setPos(0,120); my.draw(); my.showAttack();
	mz.setPos(0, -120); mz.draw(); mz.showAttack();
	while (!kbhit()) { delay(200); } return 0;
}

#endif