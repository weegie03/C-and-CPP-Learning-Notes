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
	int *_pcolor; // 老鼠的顏色，整數指標變數
public:
	CMouse(int ix=0,int iy=0,int color=COLOR_WHITE) {
		_pcolor= new int;//動態申請一塊整數大小的記憶體空間
		*_pcolor=color;// 把傳進來的顏色數值，存進記憶體空間裡
		_ix = ix; _iy = iy;
	}
	~CMouse() {
		if (_pcolor!=nullptr) delete _pcolor;// 物件消失時，自動釋放動態記憶體
	};
	CMouse(const CMouse &m)
	{
		_ix = m._ix+100; _iy = m._iy-100; //物件本身來自m 所以要寫成m.(代表舊老鼠)
		if (_pcolor!=nullptr)//檢查是不是nullptr 不是的話才要取得空間
		{
			_pcolor = new int;// 新老鼠自己申請一塊全新的記憶體空間
			*_pcolor = *(m._pcolor);// 把{舊老鼠}記憶體裡的值，複製到{新老鼠}的新空間裡
		}
		else ;
	}
	void draw() { drawBoxMan(_ix, _iy, *_pcolor ); }//指標要加上*
	friend void xxx(CMouse& m) {
		m.draw();
	}//朋友函數 讓外部函數 xxx 可以直接存取 CMouse 的私有成員
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-1 動態記憶體配置");
	CMouse mx(0, 100, 3); // 建立時就會自動呼叫CMouse 建構元
	CMouse my(mx);//建立 my 老鼠，並用 mx 初始化
	//mx.draw(); 
	my.draw();
	xxx(mx);
	while (!kbhit()) { delay(200); } return 0;
}
//class CMouse
//{
//private:
//	int _ix, _iy;
//	int *_pcolor; // 老鼠的顏色，整數指標變數
//public:
//	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) { 
//		_pcolor = new int; //動態申請一塊整數大小的記憶體空間
//		*_pcolor = color;// 把傳進來的顏色數值，存進記憶體空間裡
//		_ix = x; _iy = y;
//	}
//	~CMouse() {
//		if(_pcolor!=nullptr) delete _pcolor;// 物件消失時，自動釋放動態記憶體
//	};
//	CMouse(const CMouse& m)
//	{
//		_ix = m._ix; _iy = m._iy;//物件本身來自m 所以要寫成m.
//		if (m._pcolor != nullptr)//檢查是不是nullptr 不是的話才要取得空間
//		{
//			_pcolor = new int;// 新老鼠自己申請一塊全新的記憶體空間
//			*_pcolor = *(m._pcolor);// 把{舊老鼠}記憶體裡的值，複製到{新老鼠}的新空間裡
//		}
//		else _pcolor = nullptr;
//	}
//	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }//指標要加上*
//	friend void xxx(CMouse& m) { m.draw(); }//朋友函數 讓外部函數 xxx 可以直接存取 CMouse 的私有成員
//};
//
//int main()
//{
//	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-1 動態記憶體配置");
//	CMouse mx(0, 100, 3); // 建立時就會自動呼叫CMouse 建構元
//	CMouse my(mx);//建立 my 老鼠，並用 mx 初始化
//	//mx.draw(); 
//	my.draw();
//	xxx(mx);
//	while (!kbhit()) { delay(200); } return 0;
//}
#endif