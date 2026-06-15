//程式設計二，第二次上機考試，第2題（2 + 3分）
//Part1
//宣告 CCircle類別
// 私有包含（都是int 型別）
//	座標 _x/_y 與半徑_r 
//公有包含
//三個建構元，
//第1個建構元：3個引數，依序是圓的x/y座標與半徑
//第2個建構元：2個引數，依序是圓的x/y座標，半徑的預設值100
//第3個建構元：1個引數，圓的半徑，x/y設定在0,0
//draw()函式：根據座標與半徑畫出對應的圓

//Part 2
//在 Part 1 所完成的類別之下，新增
//私有成員：字元指標變數 _name，用於儲存圓的名稱
//公有包含
//新増 2 個建構元
//第1個建構元：2個引數，依序是圓的名稱（宇元指標）與圓的半徑
//	設定座標在（200，-200），並為傳入的圓名稱以 new 取得儲存空間
//	利用 strcpy（char*目的，char *來源）：將傳入的圓名稱儲存到 _name
//第2個建構元：1個引數，圓的名稱（字元指標）
//	設定座標在（-200，-200），半徑為100，並為傳入的圓名稱以 new 取得儲存空間
//	利用 strcpy（char *目的，char*來源）；將傳入的圓名稱儲存到_name
//解構元
//釋放建構元所取得的空間
//要求：
//1.本題所有建構元【都不能使用引數預設值】
//2. 不可變更主程式中所給的程式碼
//3. Part 2 新增之建構元與解構元必須寫在類別外才計分
//4. 動態記憶體配置以所給程式碼補強即可
//執行結果參考 p2.jpg，上半部為 part1、下半部為 part2

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
#define p2
#ifdef p
using namespace std;

class CCircle
{
private:
	//part1
	int _x, _y, _r;
	//part2
	char* _name = nullptr;
public:
//part1的三個建構元
	CCircle(int x,int y,int r)
	{
		//第1個建構元：3個引數，依序是圓的x/y座標與半徑
		//x = _x; y = _y; r = _r;這樣寫反了
		_x = x; _y = y; _r = r;
	}
	CCircle(int x, int y)
	{
		//第2個建構元：2個引數，依序是圓的x/y座標，半徑的預設值100
		_x = x; _y = y; _r = 100;
	}
	CCircle(int r)
	{
		//第3個建構元：1個引數，圓的半徑，x/y設定在0,0
		_x = 0;_y=0;
		_r = r;
	}
	
	void draw()
	{
		setcolor(COLOR_RED);
		circle(X(_x), Y(_y), _r);
		if (_name != nullptr)
		{
			//part2
			setcolor(COLOR_LIGHTGREEN);
			outtextxy(X(_x), Y(_y), _name);
		}
	}
	CCircle(const char* ch, int r);
	CCircle(const char* ch);
	~CCircle();
};

CCircle::CCircle(const char* ch,int r)//收一串字的位址 用const(常數)來接受他 讓他唯讀
{
//第1個建構元：2個引數，依序是圓的名稱（字元指標）與圓的半徑
//設定座標在（200，-200），並為傳入的圓名稱以 new 取得儲存空間
//利用strcpy（char*目的，char *來源）：將傳入的圓名稱儲存到 _name
	_x = 200; _y = -200; _r = r;
	strlen(ch);//strlen取得傳入正確名稱的長度 strlen()是用小括弧
	_name = new char[strlen(ch)+1];//new取得空間
	strcpy( _name, ch);//strcpy的參數應該直接傳入指標變數名 
	//目標應該是_name 不是r
}
CCircle::CCircle(const char* ch)
{
	//第2個建構元：1個引數，圓的名稱（字元指標）
	//設定座標在（-200，-200），半徑為100
	//並為傳入的圓名稱以 new 取得儲存空間
	_x = -200; _y = -200; _r = 100;
	_name = new char[strlen(ch) + 1];
	strcpy(_name, ch);
}
CCircle::~CCircle()
{
	//解構元
	//利用 strcpy（char *目的，char*來源）；將傳入的圓名稱儲存到_name
	//釋放建構元所取得的空間
	//strcpy(char* _r, char* ch);
	if (_name != nullptr)
	{
		delete[] _name;
		_name = nullptr;
	}
}

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "p2 建構元的多載與動態記憶體的使用");
	//part1
	CCircle c1(100, 100, 150);
	CCircle c2(-100, 100);
	CCircle c3(50);
	c1.draw(); c2.draw(); c3.draw();

	//part2
	CCircle c4("part2-1", 150);
	CCircle c5("part2-2");
	c4.draw();
	c5.draw();
	system("pause"); return(0);
}
#endif
//錯的地方:
//字元指標變數 _name要先等於nullptr
//part2 建構元收一串字的位址 用const(常數)來接受他 讓他唯讀 字元指標變數加上*
//strlen()是用小括弧
// new char[strlen(ch)+1];//new取得空間要加1給\0
//strcpy( _name, ch);//strcpy的參數應該直接傳入{指標變數名 }
	//目標應該是_name 不是r ;來源是ch 不用加上*
//delete 釋放空間要再把_name=nullptr