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
	void draw(int x, int y) {
		_ix = x; _iy = y;
		drawBoxMan(x, y, _icolor); // 礶ρ公
	}
	void draw(int x, int y, int color) {
		_ix = x; _iy = y; _icolor = color;
		drawBoxMan(x, y, color); // 礶ρ公
	}
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N13-6 ΘㄧΑ更");
	CMouse mx(-200, 0, 12);// ま计常倒
	mx.draw();
	mx.draw(0, 0);
	mx.draw(200, 0, 3);
	while (!kbhit()) { delay(200); } return 0;
}