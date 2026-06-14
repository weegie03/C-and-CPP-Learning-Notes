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
	CMouse(int x=0, int y=0, int color = COLOR_WHITE) : _ix(x), _iy(y), _icolor(color) 	{ 
		//_ix(x), _iy(y), _icolor(color) 单 _ix = x; _iy = y; _icolor = color;
	}
	void draw() {
		drawBoxMan( _ix, _iy, _icolor); // 礶ρ公
	}
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N13-5 篶じ更");
	CMouse mx(-200, 0, 12);	// ま计常倒
	CMouse mx1(0, 100);		// 材ま计ㄏノ箇砞
	CMouse mx2(100, 0);		// 材籔ま计ㄏノ箇砞
	CMouse mx3; 			// 场ㄏノ箇砞
	mx.draw(); mx1.draw(); mx2.draw(); mx3.draw();
	while (!kbhit()) { delay(200); } return 0;
}