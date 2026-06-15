//程式設計二，第二次上機考試，第4題（4分）
//宣告 CCircle 類別
//私有包含（都是 int 型別）
//座標 _x,_y、半徑 _r：與額色_color
//公有包含
//1個建構元，4個引數，依序是圓的x/y座標、半徑與顏色使用引數預設值，分別是0,0,100.COLOR_WHITE
//拷貝建構元：
//x座標為複製來源 X座標+100;y座標為複製來源 座標-200
//顏色與半徑直接複製來源
//void setPos（） 函式：兩個引數×與了，設定圓的座標
//void setRadColor（）函式：兩個引數：與 col，設定圓的半徑與顏色
// =運算子
//draw（）函式：根據所給函式內容，依座標與半徑畫出對應的圓
//要求：
//1. 不改動主程式下，完成類別的所有內容，同時輸出如結果如圖p4.jpg

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p4
#ifdef p
using namespace std;
class CCircle
{
private:
	int _x, _y, _r,_color;
public:
	CCircle(int x = 0, int y = 0, int r = 100, int color = COLOR_WHITE)
	{
		_x = x; _y = y; _r = r; _color = color;
	}
	CCircle(const CCircle& m)
	{
		_x = m._x + 100; _y = m._y - 200; _r = m._r; _color = m._color;
	}
	void setPos(int x, int y)
	{
		_x = x; _y = y;
	}
	void setRadColor(int r, int color)
	{
		_r = r; _color = color;
	}
	CCircle operator=(const CCircle &m)//不是回傳int 是CCircle
	{
		//可以加上檢查自我賦值
		if (this == &m) return *this;
		_x = m._x; _y = m._y; _r = m._r; _color = m._color;
		return (*this);
		//回傳 CCircle& 確保了(c2 = c1) 執行完後
		//回傳的是 c2 物件本身，這樣 c3 才能接著從 c2 取得資料。
	}
	void draw()
	{
		setcolor(_color);
		circle(X(_x), Y(_y), _r);
	}
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "p4建構元引數、拷貝建構員與指定運算子");
	CCircle c1(0, 100, 150, 12);
	CCircle c2(c1);
	c2.setRadColor(50, 10);
	c1.draw();
	c2.draw();

	CCircle c3;
	c3 = c2 = c1;
	c3.setPos(-250,100);
	c3.draw();

	system("pause"); return(0);
}
#endif
//錯的地方:
//運算子不是回傳int 是CCircle(物件)
//回傳this指標