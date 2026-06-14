#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p13
#ifdef p
using namespace std;

class CMouse
{
private:
	int _ix, _iy, _icolor;
	static int _icount;//靜態成員放在私有
public:
	CMouse(int ix=0,int iy=0,int icolor=COLOR_WHITE) {
		if (_icount < 5)
		{
			_ix = ix; _iy = iy; _icolor = icolor;
			_icount++;
		}
		else
		{
			cout << "老鼠太多了，不准再蓋了！" << endl;
		}
	}
	~CMouse() { _icount--; }
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
	
	static void count() { cout <<_icount  << "隻老鼠被建立" << endl; }//透過靜態成員函式
};
int CMouse::_icount = 0; // 設定初始值
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N13-13 靜態成員變數");
	CMouse m1;//存取某個特定範圍內的成員
	CMouse m2[10];
	m1.count();
	CMouse::count();
	while (!kbhit()) { delay(200); } return 0;
}
//class CMouse
//{
//private:
//	int _ix, _iy, _icolor;
//	static int _icount;
//public:
//	//static int _icount;
//	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) {
//		_ix = x; _iy = y; _icolor = color;_icount++;
//	}
//	~CMouse() { _icount--; }
//	void draw() { drawBoxMan(_ix, _iy, _icolor); }
//	static void showCount() { cout << _icount << "隻老鼠被建立" << endl; }//透過靜態成員函式
//};
//int CMouse::_icount = 0; // 設定初始值
//int main()
//{
//	initwindow(SCREENWIDTH, SCREENWIDTH, "N13-13 靜態成員變數");
//	CMouse mx;
//	CMouse::showCount();//存取某個特定範圍內的成員
//	CMouse my[10];
//	mx.showCount();
//	while (!kbhit()) { delay(200); } return 0;
//}
#endif