#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p2
#ifdef p
using namespace std;
class CCharacter
{
private:
	int _ix, _iy, _icolor;
public:
	CCharacter(int ix,int iy,int icolor)
	{
		_ix = ix; _iy = iy; _icolor = icolor;
		cout << "CCharacter 建構元被呼叫" << endl;
	}
	~CCharacter() {
		cout << "CCharacter 解構元被呼叫"<< endl;
	}
	void draw(){ drawBoxMan(_ix, _iy, _icolor); }
	void setColor(int icolor) { _icolor = icolor; }
};

class CMouse :public CCharacter
{
private:
	int _iattack;
public:
	CMouse(int ix = 0, int iy = 0, int icolor = 14, int iattack = 10) :CCharacter(ix, iy, icolor)
	{
		_iattack = iattack;
		cout << "CMouse 建構元被呼叫" << endl;
	}
	~CMouse() {
		cout << "CMouse 解構元被呼叫"<< endl;
	}
	void showAttack() {
		cout << "攻擊力="<< _iattack << endl;
	}
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-2 基礎類別建構元的指定");
	{
		CMouse mx1, mx2(0, 100, 13, 5);
		mx1.draw();
		mx2.draw();
		mx2.showAttack();
	}
	while (!kbhit()) { delay(200); }
	return 0;
}



//class CCharacter {
//private:
//	int  _ix, _iy, _icolor;	// 座標與顏色
//public:
//	CCharacter(int ix, int iy, int icolor) { // 不給預設值的建構元	
//		_ix = ix; _iy = iy; _icolor = icolor; // 設定位置與圖示
//		cout << "CCharacter 建構元被呼叫" << endl;
//	}
//	void draw() { drawBoxMan(_ix, _iy, _icolor); }
//	void setColor(int icolor) { _icolor = icolor; }
//};
//class CMouse : public CCharacter {
//private:
//	int _iattack;	// 設定攻擊力
//public:
//	CMouse(int ix = 0, int iy = 0, int icolor = 14, int ivalue = 10) :
//	CCharacter(ix, iy, icolor) {//子類別建構元必須要有預設值
//		_iattack = ivalue;
//		cout << "CMouse 建構元被呼叫" << endl;
//	}
//	void showAttack() { cout << "攻擊力=" << _iattack << endl; }
//};
//int main()
//{
//	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-2 基礎類別建構元的指定");
//	CMouse mx1, mx2(0, 100, 13, 5);//m1的變數值是0,0,14,10
//	mx1.draw();
//	mx2.draw(); mx2.showAttack();
//	while (!kbhit()) { delay(200); } return 0;
//}
#endif