#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p15
#ifdef p
using namespace std;
class CCharacter{//定義一個名為 CCharacter 的類別（基礎角色）
private:
	int _ix, _iy, _icolor;// 座標與顏色
public:
	CCharacter(int ix=0, int iy=0, int icolor=COLOR_WHITE)// 建構元
	{
		_ix = ix; _iy = iy; _icolor = icolor;// 設定位置與顏色
		cout << "CCharacter 建構元被呼叫" << endl;
	}
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
	void setColor(int icolor) {
		_icolor = icolor;
	}//賦予顏色
};
class CMouse:public CCharacter{//子類別繼承自父類別
private:
	int _iattack;// 設定攻擊力
public:
	CMouse(int ix=0, int iy=0, int icolor=COLOR_WHITE, int iattack = 10) :CCharacter(ix, iy, icolor) {
		 _iattack = iattack;// 初始化攻擊力
		cout << "CMouse 建構元被呼叫" << endl;
	}
	void showAttack() { cout << "攻擊力=" << _iattack << endl; }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-1 繼承的定義與使用");
	CCharacter npc(0, 100);//創造一個父類別物件(0,100)
	CMouse mx(50,50,14,99);//創造一個子類別物件
	npc.draw();//畫出父類別角色
	//mx.setColor(14);//子類別角色呼叫父類別函式 決定顏色
	mx.draw();//畫出子類別角色
	mx.showAttack();// 顯示老鼠的攻擊力
	cout << "sizeof(npc) = " << sizeof(npc) << endl;
	cout << "sizeof(mx)  = " << sizeof(mx) << endl;
	while (!kbhit()) { delay(200); } return 0;
}
//class CCharacter {//// 定義一個名為 CCharacter 的類別（基礎角色）
//private:
//	int  _ix, _iy, _icolor;	// 座標與顏色
//public:
//	CCharacter(int ix = 0, int iy = 0, int icolor = COLOR_WHITE) { // 建構元	
//		_ix = ix; _iy = iy; _icolor = icolor; // 設定位置與顏色
//		cout << "CCharacter 建構元被呼叫" << endl;
//	}
//	void draw() { drawBoxMan(_ix, _iy, _icolor); }
//	void setColor(int icolor) { _icolor = icolor; }//賦予顏色
//};
//class CMouse : public CCharacter {//子類別繼承自父類別
//private:
//	int _iattack;	// 設定攻擊力
//public:
//	CMouse(int ivalue = 10) {
//		_iattack = ivalue;// 初始化攻擊力
//		cout << "CMouse 建構元被呼叫" << endl;
//	}
//	void showAttack() { cout << "攻擊力=" << _iattack << endl; }
//};
//int main()
//{
//	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-1 繼承的定義與使用");
//	CCharacter npc(0, 100);//創造一個父類別物件(0,100)
//	CMouse mx;///創造一個子類別物件
//	npc.draw();//畫出父類別角色
//	mx.setColor(14);//子類別角色呼叫父類別函式 決定顏色
//	mx.draw();//畫出子類別角色
//	mx.showAttack();// 顯示老鼠的攻擊力
//	cout << "sizeof(npc) = " << sizeof(npc) << endl;
//	cout << "sizeof(mx)  = " << sizeof(mx) << endl;
//	while (!kbhit()) { delay(200); } return 0;
//}
#endif