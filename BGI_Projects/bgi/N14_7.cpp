#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p7
#ifdef p
using namespace std;

//
//class CMouse
//{
//public:
//	int _ix, _iy;		// 老鼠的起始位置
//	int* _pcolor;		// 老鼠的顏色，整數指標變數
//	CMouse(int x=0,int y=0,int color=COLOR_WHITE) {
//		_ix = x; _iy = y; _pcolor = new int; *_pcolor = color;
//	}
//	CMouse(const CMouse &m) {	// 拷貝建構元
//		_ix = m._ix; _iy = m._iy; _pcolor = new int; *_pcolor = *(m._pcolor); // 老鼠的起始位置與取得空間
//		
//	}
//	~CMouse() { delete _pcolor; }; // 解構元, 釋放資源
//	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
//};
//int main()
//{
//	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-7 物件指標變數");
//	CMouse mx(0, 0, 14); // 建立時就會自動呼叫CMouse 建構元
//	
//	CMouse* pmy = new CMouse(mx);// 讓老鼠自己畫出自己的位置
//	pmy->draw();
//	delete pmy;
//	CMouse *pmz=new CMouse[10];//pmz是一個物件指標變數
//	//new CMouse[10]跟系統要了可以放十個CMouse物件的空間
//	//(可能包含很多變數eg:座標、顏色)， 指向開頭(起始位置)
//	for (int i = 0; i < 10; i++)
//	{
//		pmz[i]._ix = i * 50;
//		pmz[i]._iy = 200;
//		*(pmz[i]._pcolor) = 11;
//		pmz[i].draw();
//		//pmz 雖然是指標，但當你加上中括號 pmz[i] 時，
//		//它就代表那第i隻老鼠本人（物件）了。本人就要改用.
//	}
//	delete[] pmz;//空間釋放
//
//	CMouse* pm[10];//宣告一個一維的物件指標變數 
//	///不是陣列 是10個獨立的物件指標變數
//	pm[0] = new CMouse;
//	pm[1] = new CMouse[2];
//	delete pm[0];//各別釋放
//	delete[] pm[1];
//	while (!kbhit()) { delay(200); } return 0;
//}
//class CMouse
//{
//public:
//	int _ix, _iy;		// 老鼠的起始位置
//	int *_pcolor;		// 老鼠的顏色，整數指標變數
//	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) { 
//		_pcolor = new int; 	*_pcolor = color; _ix = x; _iy = y;
//	}
//	CMouse(const CMouse &m) {	// 拷貝建構元
//		_ix = m._ix; _iy = m._iy; _pcolor = new int; // 老鼠的起始位置與取得空間
//		*_pcolor = *(m._pcolor);
//	}
//	~CMouse() { delete _pcolor; }; // 解構元, 釋放資源
//	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
//};
//int main()
//{
//	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-7 物件指標變數");
//	CMouse mx(0, 0, 14); // 建立時就會自動呼叫CMouse 建構元
//	CMouse *pmy = new CMouse(mx);
//	pmy->draw(); // 讓老鼠自己畫出自己的位置
//	delete pmy;
//
//	CMouse* pmz = new CMouse[10];//pmz是一個物件指標變數
//	//new CMouse[10]跟系統要了可以放十個CMouse物件的空間
//	//(可能包含很多變數eg:座標、顏色)， 指向開頭(起始位置)
//	delete[] pmz;//空間釋放
//
//	CMouse* pm[10];//宣告一個一維的物件指標變數 不是陣列 是10個獨立的物件指標變數
//	pm[0] = new CMouse;
//	pm[1] = new CMouse[2];
//	delete pm[0];
//	delete[] pm[1];//各別釋放
//
//	while (!kbhit()) { delay(200); } return 0;
//}
#endif