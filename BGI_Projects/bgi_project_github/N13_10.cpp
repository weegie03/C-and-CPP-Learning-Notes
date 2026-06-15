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
	int _ix, _iy, _icolor;
public:
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) : _ix(x), _iy(y), _icolor(color) { 
		cout << "建構元被呼叫" << endl;
	}
	CMouse(const CMouse &ma) {	// 建構元
		_ix = ma._ix, _iy = ma._iy; // 老鼠的起始位置
		_icolor = ma._icolor;
		cout << "拷貝建構元被呼叫" << endl;
	}
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N13-10 拷貝建構元");
	CMouse mx(0, 100, 3); // 建立時就會自動呼叫CMouse 建構元
	CMouse my(mx);  // my 的內容來自 mx
	// CMouse my = mx; // 這樣寫也行
	my.draw(); 
	while (!kbhit()) { delay(200); } return 0;
}