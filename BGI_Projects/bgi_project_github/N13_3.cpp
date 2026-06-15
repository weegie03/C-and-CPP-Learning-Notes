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
	int _ix, _iy;
	int _icolor;
public:
	//CMouse(int color) {	// 篶じ
	//	_ix = 0; _iy = 0; // ρ公癬﹍竚
	//	_icolor = color;
	//}
	CMouse(int x, int y, int color=2) {	// 篶じ
		_ix = x; _iy = y; // ρ公癬﹍竚
		_icolor = color;
	}
	CMouse()  {	// 篶じ
		_ix = 0; _iy = 0; // ρ公癬﹍竚
		_icolor = 3;
	}

	void draw() {
		drawBoxMan( _ix, _iy, _icolor); // 礶ρ公
	}
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N13-3 篶じ更");
	CMouse mx(0, 0, COLOR_RED); // ミ砞﹚ρ公癬﹍竚籔肅︹
	CMouse mxe;
	mx.draw();
	while (!kbhit()) { delay(200); } return 0;
}