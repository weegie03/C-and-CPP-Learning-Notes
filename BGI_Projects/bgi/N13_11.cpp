#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p11
#ifdef p
using namespace std;

//class CMouse
//{
//private:
//	int _ix, _iy, _icolor;
//public:
//	static int _icount;//靜態變數
//	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) : _ix(x), _iy(y), _icolor(color) {
//		_icount++;
//	}
//	CMouse(const CMouse& m)//為了呼叫出正確的老鼠數量，加上const便成唯讀(傳進來的東西不能更改
//	{//只要涉及 static 計數器，一定要記得手寫拷貝建構函式
//		_ix=m._ix, _iy=m._iy, _icolor=m._icolor; 
//		_icount++;
//	}
//	~CMouse() { _icount--; }
//	void draw() { drawBoxMan(_ix, _iy, _icolor); }
//};
//
//int CMouse::_icount = 0; // 設定初始值(在外面)
//因為 static 變數是屬於整個類別（Class）共有
//必須使用 ::（範疇解析運算子）告訴電腦：「我是代表整個類別，而不是某隻特定老鼠。」
//
//int main()
//{
//	initwindow(SCREENWIDTH, SCREENWIDTH, "N13-11 靜態成員變數");
//	CMouse mx;// 建立 1 隻老鼠（呼叫普通的建構函式）
//	CMouse my[10];// 建立一個老鼠陣列，裡面有 10 隻老鼠 -> 計數器累加 10
//	CMouse mz = mx;//讓拷貝宣告可以呼叫正確的拷貝建構元
//	//// 用 mx 複製出 mz（呼叫拷貝建構函式）
//	cout << CMouse::_icount << "隻老鼠被建立" << endl;//透過類別名稱存取
//	//「請幫我印出，CMouse 類別裡共用的 _icount 數字，然後後面接『隻老鼠被建立』。」
//	system("pause"); return 0;
//}
#endif