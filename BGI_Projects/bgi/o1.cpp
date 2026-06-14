//程式設計二，第二次上機考試，第1題（6+2分）
//宣告 CMouse 類別裡面包含
//私有包含（都是整數型別）
//座標_x/_y ，顏色 _color,狀態_status : 1：正常狀態，2 :在邊界上，0:死亡
//上面三個都是 int 型別
//公有包含
//建構元：設定位置在（0，0）。状態為正常状態・顔色為 NORMAL_COLOR.
//setPosStatus（）函式：三個引數 int型別的x與y，與 int 型別的狀態 status
//                      設定老鼠的位置與狀態
//draw函式，呼_drawColorBox（_x,_y,_color）；在_x / _y畫出指定額色的老鼠
//update（）函式，只有一個引數，型別為char，
//				  回傳值為目前老鼠移動後的狀態
//功能是依照輸入的w、a、s、d四個按鍵，讓老鼠上下左右個移動 20 個單位
//同時判断 老鼠是否在X / Y正負200的範圍內（不含）
//狀態設定成 正常狀顧 顏色為 NORIAL_COLOR
//剛好在X/Y 正負200的位置上
//狀態設定成 在邊界上顏色為 DANGER_COLOR
//超出X/ Y正負200的範圍外狀態設定成死亡
// 
//根據主程式的需求，完成可利用鍵盤 w、a、s、d四個按鍵，控制老鼠的移動，走到邊界改變顏色，移除並顯示死亡
//要求：
//計分方式與要求：
//1.6分：所有成員函式都必須寫在類別外，且程式正常執行並完成指定的功能才計分。
//2.2分：以【迴圈方式】讓遊戲可以進行兩次。
//3.【不得新增】題目沒有寫的函式
/// 善意提醒
//不要，在成員函式內再次宣告成員變數了

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
#define p
#ifdef p1
using namespace std;
void drawFence();
class CMouse
{
private:
	int _x, _y, _color, _status;
public:
	CMouse(int x, int y, int status, int color);
	//~CMouse();
	int setPosStatus(int x, int y, int status);
	void draw();
	int update(char cIn);
	
};

CMouse::CMouse(int x=0, int y=0, int status=1, int color= NORMAL_COLOR)
{
	_x = x; _y = y; _status = status; _color = color;
}
int CMouse::setPosStatus(int x,int y,int status)
{
	//三個引數 int型別的x與y，與 int 型別的狀態 status
	//設定老鼠的位置與狀態
	_x = x; _y = y; _status = status; _color;
	if (_status == 2) _color = DANGER_COLOR;
	else _color = NORMAL_COLOR;
	return(_status);
}
void CMouse::draw() { drawColorBox(_x, _y, _color); }
int CMouse::update(char cIn)
{
	switch (cIn) {
	case 'w': // 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
		_y = _y + 20;
		break;
	case 's': // 往下
		_y = _y - 20;
		break;
	case 'a': // 往左
		_x = _x - 20;
		break;
	case 'd': // 往右
		_x = _x + 20;
		break;
	}
	if (_x<X_MAX && _x>-X_MAX && _y<Y_MAX && _y>-Y_MAX)
	{
		_status = 1;
		_color = NORMAL_COLOR;
		return(_status);
	}
	else if (_x == X_MAX || _x==-X_MAX || _y==Y_MAX || _y == Y_MAX)
	{
		_status = 2;
		_color = DANGER_COLOR;
		return(_status);
	}
	else { _status = 0; return(_status);}
}

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N12-1 老鼠控制的程序導向設計");
	char cIn;
	int status;
	CMouse m;
	status = m.setPosStatus(0,0,1);
	for (int i = 0;  i < 2;  i++)
	{
		status = m.setPosStatus(0, 0, 1);
		//status = 1;
		while (status!=0)
		{
			
			cleardevice();//畫面清成黑色的
			drawFence(); // 畫出範圍
			m.draw();		//drawMouse();
			swapbuffers();
			cIn = getch();//不用按下enter建也可以接收字元
			status = m.update(cIn);//去接收狀態
			rewind(stdin);
		}
		
	}
	cleardevice();
	drawFence();
	setcolor(COLOR_WHITE);
	outtextxy(X(-100), Y(0), "!! 老鼠死了 GG 按任意鍵結束!! ");
	swapbuffers();

	while (!kbhit()) { delay(200); } return 0;
}
void drawFence()
{
	for (int i = -200; i <= 200; i += 20) {
		drawColorBox(i, 200, COLOR_LIGHTGREEN);
		drawColorBox(i, -200, COLOR_LIGHTGREEN);
	}
	for (int i = -180; i <= 180; i += 20) {
		drawColorBox(-200, i, COLOR_LIGHTGREEN);
		drawColorBox(200, i, COLOR_LIGHTGREEN);
	}
}
#endif
