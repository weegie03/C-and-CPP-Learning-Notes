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
	static int _icount;
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) {
		_ix = x; _iy = y; _icolor = color;  _icount++;
	}
	~CMouse() { _icount--; }
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
};
int CMouse::_icount = 0; // 設定初始值
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N13-12 靜態成員變數");
	CMouse mx; 
	CMouse my[10];
	CMouse mz = mx;
	mz.draw();
	cout << CMouse::_icount << "隻老鼠被建立" << endl;
	while (!kbhit()) { delay(200); } return 0;
}