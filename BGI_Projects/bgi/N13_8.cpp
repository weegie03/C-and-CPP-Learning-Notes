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

class CMouse
{
private:
	int _ix, _iy, _icolor;
public:
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) : _ix(x), _iy(y), _icolor(color) { }
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
	CMouse Compare(CMouse mt) { 
		if (this->_ix > mt._ix) return(*this);
		else return(mt);
	}
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N13-8 物件的傳遞");
	CMouse mx(200, 100, 10);
	CMouse my(100, 0);
	mx.Compare(my).draw();

	while (!kbhit()) { delay(200); } return 0;
}
#endif