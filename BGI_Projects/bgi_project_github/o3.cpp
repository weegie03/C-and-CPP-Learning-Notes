//程式設計二，第二次上機考試，第3題（3 + 1分）
//計分方式：完成下述的要求3分
//使用類別呼叫靜態函式 show_cnt（）1分
//宣告 CMouse 類別裡面包含
// 私有包含（都是整數型別）
// 座標_x,_y與顏色_color
// 計數器_cnt為靜態成員變數，型別為 int
//公有包含
//建構元必須使用引數預設值，設定預設座標與顏色為 0 0 COLOR_WHITE
//必須將_cnt加1
//
//拷貝建構元：設定對應內容並將_cnt 加1
//解構元必須將 _cnt 減1
//靜態成員函式 show_cnt，回傳 cnt 的內容
//函式可寫在類別宣告内
//參考主程式的物件宣告，完成指定的建構元，並畫出對應的老鼠（p3.jpg）
// 要求：靜態成員變數的初始值必須寫在類別外
//  輸出如圖 p3.jpg與以下的結果
//  2隻老鼠被建立
//  3隻老鼠被建立
//  1隻老鼠被建立

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED
#define X_MAX 200
#define Y_MAX 200
#define p3
#ifdef p
using namespace std;
//參考N13-13

class CMouse
{
private:
	int _x, _y, _color;
	static int _cnt;
public:
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE)//預設值中間不是分號是逗號
	{
		//建構元必須使用引數預設值，設定預設座標與顏色為 0 0 COLOR_WHITE
		//必須將_cnt加1
		_x = x; _y = y; _color = color;
		_cnt++;
	}
	CMouse(const CMouse &m)//拷貝建構元的參數必須是該類別的參照（通常加上 const）
	{
		//拷貝建構元：設定對應內容並將_cnt 加1
		_x = m._x; _y = m._y; _color =m._color;
		_cnt++;
	}
	~CMouse()
	{
		_cnt--;
	}
	//靜態成員函式 show_cnt，回傳 cnt 的內容
	int static show_cnt()
	{
		return _cnt;
	}
	void draw() { drawBoxMan(_x, _y, _color); }
	//int _cnt = 0;//設定_cnt的初始值為0
};
int CMouse::_cnt = 0;//設定_cnt的初始值為0
//靜態變數的初始化必須在類別定義之外
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "p3 靜態變數與指標物件");
	CMouse mx(100, 100, COLOR_LIGHTRED);//宣告mx為一般物件
	
	CMouse* p = new CMouse(mx);	//宣告p為指標物件，以new 取得物件，並以 mx該物件為內容的來源

		//呼叫靜態函式時則需要使用 類別名稱::函式名() 的格式
	cout<<CMouse::show_cnt() << "隻老鼠被建立" << endl; //必須使用類別名稱去呼叫 show_cnt 函式
	mx.draw();	//呼叫 draw 繪製
	delete p;	//以delete釋放p所取得的空間
	p = new CMouse [2];	//以new取得2個空間
	p[0] = CMouse(-100, 0);//設定索引值為1的物件座標在（-100, 0）；
	p[1]=CMouse(0,0,COLOR_YELLOW);//設定索引值為1的物件顏色為 COLOR_YELLOW
	p[0].draw();	// 設定索引值為0的物件呼叫 draw 畫出自己
	p[1].draw();	//設定索引值為1的物件時中draw 畫出自己
	cout<< CMouse::show_cnt()<<"隻老鼠被建立" << endl; //必須使用類別名稱去呼叫 show_cnt函式 
	delete[] p;//釋放 pm 取得的空間
	cout<< CMouse::show_cnt()<<"隻老鼠被建立" << endl;//必須使用類別名稱去呼叫 show_cnt 函式
	system("pause"); return(0);

}
#endif
//錯的地方:
//拷貝建構元的參數必須是該類別的參照（通常加上 const）
//靜態變數的初始化必須在類別定義之外
//呼叫靜態函式時則需要使用 類別名稱::函式名() 的格式。