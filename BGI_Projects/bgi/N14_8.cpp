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
public:
	int _ix, _iy, * _pcolor;
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) {  // 建構元
		_ix = x; _iy = y; _pcolor = new int; *_pcolor = color;
	}
	CMouse(const CMouse &m) {	// 拷貝建構元
		_ix = m._ix; _iy = m._iy; _pcolor = new int; *_pcolor = *(m._pcolor); // 老鼠的起始位置與取得空間
	}
	//回傳型態是類別的參照，傳入參數也是常數參照
	CMouse & operator=(const CMouse &m)//1.改成物件+CMouse 2.把呼叫者this指標丟回去(return) 3.通常會傳參照(避免物件複製
	{
		if (this==&m) return(*this);//好習慣是檢查一下
		_ix = m._ix; _iy = m._iy; *_pcolor = *(m._pcolor);
		return(*this);
	}
	/*void operator=(const CMouse& m) {
		_ix = m._ix; _iy = m._iy;
		*_pcolor = *(m._pcolor);
	}*/
	
	~CMouse() { delete _pcolor; }; // 解構元, 釋放資源
	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-8 指定運算子 =");
	CMouse m1(0, 100, 14); // 建立時就會自動呼叫 CMouse 建構元
	CMouse m2 = m1;// 呼叫拷貝建構元來建立物件 mouse2
	CMouse m3;
	m3 =m2= m1;	// 執行指定運算子
	m3.draw();
	while (!kbhit()) { delay(200); } return 0;
}
//class CMouse
//{
//public:
//	int _ix, _iy, *_pcolor;	
//	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) {  // 建構元
//		_pcolor = new int; 	*_pcolor = color; _ix = x; _iy = y;
//	}
//	CMouse(const CMouse &m) {	// 拷貝建構元
//		_ix = m._ix; _iy = m._iy; _pcolor = new int; // 老鼠的起始位置與取得空間
//		*_pcolor = *(m._pcolor);
//	}
//	//回傳型態是類別的參照，傳入參數也是常數參照
//	CMouse& operator=(const CMouse& m)//1.改成物件+CMouse 2.把呼叫者this指標丟回去(return) 3.通常會傳參照(避免物件複製
//	{
//		if (this == &m) return *this;//好習慣是檢查一下
//		_ix = m._ix; _iy = m._iy;
//		*_pcolor = *(m._pcolor);
//		return(*this);
//	}
//	/*void operator=(const CMouse& m) {
//		_ix = m._ix; _iy = m._iy;
//		*_pcolor = *(m._pcolor);
//	}*/
//	//~CMouse() { delete _pcolor; }
//	~CMouse() { delete _pcolor; }; // 解構元, 釋放資源
//	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
//};
//int main()
//{
//	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-8 指定運算子 =");
//	CMouse m1(0, 100, 14); // 建立時就會自動呼叫 CMouse 建構元
//	CMouse m2 = m1;	// 呼叫拷貝建構元來建立物件 mouse2
//	CMouse m3;
//	m3 = m1;		// 執行指定運算子
//	m3.draw();
//	while (!kbhit()) { delay(200); } return 0;
//}
#endif