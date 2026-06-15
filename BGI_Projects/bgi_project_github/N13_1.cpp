#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p1
#ifdef p
using namespace std;

class CMouse
{
private:
	int _ix, _iy;
	int _icolor;
public:
	//CMouse(int x=0, int y=0, int color= COLOR_WHITE):_ix(x), _iy(y), _icolor(color)//﹍て秨﹍
	//{	// 篶じ                                  //_ix(x)硂ぃ琌ㄧ计㊣τ琌禗絪亩竟р把计 x 钡﹍て _ix
	//	//_ix = x; _iy = y; // ρ公癬﹍竚
	//	//_icolor = color;
	//}
	CMouse(int x = 0, int y = 0,int color=COLOR_WHITE):_ix(x),_iy(y),_icolor(color){}
	//CMouse(int x, int y) {	// 篶じ
	//	_ix = x; _iy = y; // ρ公癬﹍竚
	//	_icolor = COLOR_WHITE;
	//}
	//CMouse( int color) {	// 篶じ
	//	_ix = 100; _iy = -100; // ρ公癬﹍竚
	//	_icolor = color;
	//}
	//CMouse() {	// 篶じ
	//	_ix = -100; _iy = -100; // ρ公癬﹍竚
	//	_icolor = COLOR_WHITE;
	//}
	void draw() {
		drawBoxMan( _ix, _iy, _icolor); // 礶ρ公
	}
	void draw(int x,int y) {
		_ix = x; _iy = y;
		drawBoxMan(_ix, _iy, _icolor); // 礶ρ公
	}
	void draw(int x,int y,int color) {
		_ix = x; _iy = y;
		_icolor = color;
		drawBoxMan(_ix, _iy, _icolor); // 礶ρ公
	}
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N13-1 篶じ更");
	CMouse mx(-100,0,COLOR_YELLOW); // ミ砞﹚ρ公癬﹍竚籔肅︹
	//CMouse my(COLOR_RED);
	CMouse mz(100, 100);
	CMouse m1;//狦珹┓杠穦琌ㄧ计
	mx.draw();	//琵ρ公赣竚礶
	//my.draw();
	mz.draw();
	m1.draw(); // タ m1 硂︽Τ
	mz.draw(200, -200);//ぃ竚礶材
	while (!kbhit()) { delay(200); } return 0;
}
#endif