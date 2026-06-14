#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <cstring>
#include "functions.h"
#define p9
#ifdef p

using namespace std;

//class C2Shape
//{
//protected:
//	int _ix, _iy;
//	char* _pname;
//public:
//	C2Shape(int x=0,int y=0,const char* name= "無名")
//	{
//		_ix = x; _iy = y;
//		_pname = new char[strlen(name) + 1]; strcpy(_pname,name);
//		cout << "Shape誕生" << endl;
//	}
//	C2Shape(const C2Shape& c) { 
//		_ix = c._ix; _iy = c._iy; _pname = new char[strlen(c._pname) + 1];strcpy(_pname,c._pname); 
//		cout << "Shape拷貝" << endl;
//	}
//	~C2Shape() { delete[] _pname; cout << "Shape消滅" << endl;}
//	void show() {
//		cout << "名稱: " <<_pname<< " 座標: (" <<_ix<< ")" <<  _iy << endl;
//	}
//};
//class CSquare:public C2Shape
//{
//private:
//	int _iside;
//public:
//	CSquare(int x = 0, int y = 0, const char* name= "無名", int side = 10) :C2Shape(x, y, name) { _iside = side; }
//	void showSide() { cout << "邊長=" << _iside << endl; }
//	void show() { C2Shape::show(); showSide(); }
//	CSquare& operator=(const CSquare& s)
//	{
//		if (this == &s) return *this;
//		else
//		{
//			delete[] _pname;
//			_ix = s._ix; _iy = s._iy; _iside = s._iside;
//			_pname = new char[strlen(s._pname) + 1]; strcpy(_pname,s._pname);
//			return(*this);
//		}
//	}
//};
//
//int main()
//{
//	cout << "--- 1. 創造本尊 sq1 ---" << endl;
//	CSquare sq1(10, 20, "正方形A", 50);
//	sq1.show();
//
//	cout << "\n--- 2. 拷貝宣告創造 sq2 (括號寫法) ---" << endl;
//	CSquare sq2(sq1);
//	sq2.show();
//
//	cout << "\n--- 3. 創造一個已經存在的 sq3，事後用等號賦值 ---" << endl;
//	CSquare sq3(0, 0, "暫時的名字", 5);
//	sq3 = sq2; // 這裡會觸發你寫的 = 運算子！
//	sq3.show();
//
//	cout << "\n--- 4. 程式結束，準備集體解構 ---" << endl;
//	system("pause"); return 0;
//}


class CCharacter {
protected:
	int  _ix, _iy, *_pcolor;	// 座標與顏色
public:
	CCharacter(int ix=0, int iy=0, int icolor=COLOR_WHITE) { 
		_ix = ix; _iy = iy; _pcolor = new int; *_pcolor = icolor;
		cout << "CCharacter 建構元被呼叫" << endl;
	}
	CCharacter(const CCharacter &ca) {	// 拷貝建構元
		_ix = ca._ix; _iy = ca._iy; // 設定老鼠的起始位置
		_pcolor = new int;  *_pcolor = *(ca._pcolor); // 取得空間與設定圖示
		cout << "CCharacter 拷貝建構元被呼叫" << endl; // 顯示訊息
	}
	~CCharacter() { delete _pcolor;  }
	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
	void setPos(int ix, int iy) { _ix = ix;  _iy = iy; };
};
class CMouse : public CCharacter {
private:
	int *_iattack;	// 設定攻擊力
public:
	CMouse(int x, int y, int color, int ivalue = 10) : CCharacter(x, y, color) { _iattack = new int; *_iattack = ivalue; }
	
	CMouse(const CMouse& m):CCharacter(m) {
		_iattack = new int; *_iattack = *(m._iattack);
	}
	~CMouse() { delete _iattack; }
	void showAttack() { cout << "攻擊力=" << *_iattack << endl; }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-9 拷貝宣告的處理");
	CMouse mx(0, 0, 14);
	CMouse my(mx);
	CMouse mz = my;
	mx.draw();
	my.setPos(0,120); my.draw(); my.showAttack();
	mz.setPos(0, -120); mz.draw(); mz.showAttack();
	while (!kbhit()) { delay(200); } return 0;
}
#endif // p9