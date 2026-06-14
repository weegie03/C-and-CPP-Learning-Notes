//程式設計二，第二次上機考試，第7題（3分）
//
//宣告 CMouse類別，裡面包含
// 私有成員1變數（變數名稱可自行更換）
// 老鼠座標_x，_y（f1oat 型別）
// 老鼠顏色 _pcol（int 指標型別）
// 公有成員函式
//draw函式（已經寫好直接使用）
//建構元:設定座標 ， x,y的預設值為0,0，預設額色為COLDR_WHITE（記得取得空間，並設定其內容）
//解構元:釋放建構元取得的空間
//拷貝建構元
// =運算子
// 要求:
//1.不改動主程式下，完成類別的所有內容，同時輸出如結果如圖p7.jpg
//2.程式結束時，不能出現錯誤才有分數

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#define p7
#ifdef p
//參考N14_1
using namespace std;
class CMouse
{
private:
	float _x, _y;
	int* _pcolor = nullptr;
public:
	CMouse(float x = 0, float y = 0, int color = COLOR_WHITE)
	{
		_x = x, _y = y;
		_pcolor = new int; *_pcolor = color;
	}
	CMouse(const CMouse&m)
	{
		_x = m._x; _y = m._y;
		_pcolor = new int; *_pcolor =*( m._pcolor);
	}
	~CMouse()
	{
		if (_pcolor != nullptr)
		{
			delete _pcolor;
			_pcolor = nullptr;
		}
	}
	void draw() { drawBoxMan(_x, _y, *_pcolor); }
	CMouse& operator=(const CMouse& m)//回傳 CMouse&)
	{
		if (this == &m)return *this;//避免自我賦值
		_x = m._x; _y = m._y;
		// 確保這裏有配置空間，並複製數值
		if (_pcolor == nullptr) _pcolor = new int;
		*_pcolor = *(m._pcolor);
		return (*this);
	}
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P7 動態記憶體配置的處理");
	CMouse m1(0, 0);
	CMouse m2(-200, 0,COLOR_RED);
	CMouse m3(200, 0, COLOR_RED);
	CMouse m4(m1), m5;
	m3.draw();
	m4.draw();
	m5 = m1 = m2;
	m5.draw();
	system("pause"); return(0);
}
#endif
//錯的地方:
// 忘記寫拷貝建構元
// 淺拷貝（Shallow Copy）:拷貝建構元：必須重新 new 一塊空間，並複製數值。
//你原本的 operator= 寫成 _pcolor = m._pcolor;
//  這只是把指標指過去，正確的做法應該是把對方指標裡的「內容」取出來，存進自己的空間裡。
//當類別成員裡有指標（例如你的 int* _pcolor）時，
// 拷貝建構元和賦值運算子都必須為新物件配置屬於自己的記憶體空間。
//operator= 的回傳型別必須是引用 (CMouse&)：
//原本寫 CMouse operator=（傳值回傳）
//在執行 m5 = m1 = m2 時，m1 = m2 會產生一個「臨時的副本物件」，然後這個副本會立刻被解構。
// 因為主程式是連續賦值，這會導致邏輯混亂甚至崩潰。正確做法是回傳物件本身的引用。