#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p6
#ifdef p
using namespace std;
//class CCharacter {//CCharacter父類別
//protected:
//	int  _ix, _iy, _icolor;;	// 座標與顏色
//public:
//	CCharacter(int ix = 0, int iy = 0, int icolor = COLOR_WHITE) { _ix = ix; _iy = iy; _icolor = icolor; }
//	void draw() { drawBoxMan(_ix, _iy, _icolor); }//draw()函式
//};
//class CMouse :public CCharacter {//CMouse繼承父類別
//private:
//	int _iattack;	// 設定攻擊力
//public:
//	CMouse(int x, int y, int color, int ivalue = 10) :CCharacter(x,y,color) { _iattack = ivalue; }
//	void showAttack() { cout << "攻擊力=" << _iattack << endl; }
//	//void draw() {
//	//	drawSizeBox(_ix - 64, _iy + 20, COLOR_LIGHTBLUE, 22); // 左耳朵
//	//	drawSizeBox(_ix + 64, _iy + 20, COLOR_LIGHTBLUE, 22); // 右耳朵	
//	//	drawBoxMan(_ix, _iy, _icolor, COLOR_YELLOW, COLOR_LIGHTMAGENTA);//draw()函式
//	//}
//};
//class CTiger : public CCharacter {//CTiger繼承父類別
//private:
//	int _ishape;	// 設定不同的外型
//public:
//	CTiger(int x, int y, int color, int ishape = 1) : CCharacter(x, y, color) { _ishape = ishape; }
//	void draw() {
//		if (_ishape==1)  drawBoxMan(_ix, _iy, _icolor, COLOR_RED);
//		else {
//			drawSizeBox(_ix - 24, _iy + 60, COLOR_LIGHTBLUE, 22); // 左耳朵
//			drawSizeBox(_ix + 24, _iy + 60, COLOR_LIGHTBLUE, 22); // 右耳朵	
//			drawBoxMan(_ix, _iy, _icolor, COLOR_RED, COLOR_LIGHTMAGENTA);
//		}
//	}
//};
//int main()
//{
//	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-7 成員函式的改寫");
//	CMouse mx(0, -50, 12);
//	CTiger tx(0, 100, 2, 2);
//	mx.draw(); // 基礎類別中的 draw() 
//	tx.draw(); // 衍生類別 CTiger 中的 draw() 
//	while (!kbhit()) { delay(200); } return 0;
//}
//改寫
class CCharacter {//CCharacter父類別
protected:
	int  _ix, _iy, _icolor;;	// 座標與顏色
public:
	CCharacter(int ix=0, int iy=0, int icolor=COLOR_WHITE) { _ix = ix; _iy = iy; _icolor = icolor; }
	void draw() { drawBoxMan(_ix, _iy, _icolor); }//draw()函式
};
class CMouse : public CCharacter {//CMouse繼承父類別
private:
	int _iattack;	// 設定攻擊力
public:
	CMouse(int x, int y, int color, int ivalue = 10):CCharacter(x,y,color) { _iattack = ivalue; }
	void showAttack() { cout << "攻擊力=" << _iattack << endl; }
	//void draw() {
	//	drawSizeBox(_ix - 64, _iy + 20, COLOR_LIGHTBLUE, 22); // 左耳朵
	//	drawSizeBox(_ix + 64, _iy + 20, COLOR_LIGHTBLUE, 22); // 右耳朵	
	//	drawBoxMan(_ix, _iy, _icolor, COLOR_YELLOW, COLOR_LIGHTMAGENTA);//draw()函式
	//}
};
class CTiger : public CCharacter {//CTiger繼承父類別
private:
	int _ishape;	// 設定不同的外型
public:
	CTiger(int x, int y, int color, int ishape = 1) : CCharacter(x, y, color) { _ishape = ishape; }
	void draw() { 
		if( _ishape == 1)  drawBoxMan(_ix, _iy, _icolor, COLOR_RED);
		else {
			drawSizeBox(_ix - 24, _iy + 60, COLOR_LIGHTBLUE, 22); // 左耳朵
			drawSizeBox(_ix + 24, _iy + 60, COLOR_LIGHTBLUE, 22); // 右耳朵	
			drawBoxMan(_ix, _iy, _icolor, COLOR_RED, COLOR_LIGHTMAGENTA);
		}
	}
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-7 成員函式的改寫");
	CMouse mx(0, -50, 12);
	CTiger tx(0, 100, 2,2);
	mx.draw(); // 基礎類別中的 draw() 
	tx.draw(); // 衍生類別 CTiger 中的 draw() 
	while (!kbhit()) { delay(200); } return 0;
}
#endif