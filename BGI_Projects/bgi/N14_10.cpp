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
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) {  // 建構元
		_pcolor = new int; 	*_pcolor = color; _ix = x; _iy = y;
	}
	CMouse(const CMouse &m) {	// 拷貝建構元
		_ix = m._ix; _iy = m._iy; _pcolor = new int; // 老鼠的起始位置與取得空間
		*_pcolor = *(m._pcolor);
	}
	~CMouse() { delete _pcolor; }; // 解構元, 釋放資源
	CMouse& operator= (const CMouse &m) { // 設定運算子
		_ix = m._ix; _iy = m._iy;
		*_pcolor = *(m._pcolor); // 將傳入物件的相對應的字元填入即可
		return(*this);
	}
	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-10 指定運算子 =");
	CMouse m1(0, 100, 14); // 建立時就會自動呼叫 CMouse 建構元
	CMouse m2 = m1;	// 呼叫拷貝建構元來建立物件 mouse2
	CMouse m3;
	m3 = m1;		// 執行指定運算子
	m3.draw();
	while (!kbhit()) { delay(200); } return 0;
}