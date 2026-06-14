#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

#define p8
#ifdef p

#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED

#define X_MAX 200	// 定義可活動的範圍
#define Y_MAX 200	// 定義可活動的範圍
using namespace std;
void drawFence();

bool g_Boss = false;
class CMouse
{
private:
	int x, y;
	int status;
	int color, ncolor, dcolor;

	int _tx, _ty;
	bool _bt;
	CMouse* target;
public:
	void init() {
		x = 0; y = 0; status = 1;
		_bt = false;
		_tx = 0; _ty = 0;
		target = nullptr;
		color = ncolor = NORMAL_COLOR; dcolor = DANGER_COLOR;
	}
	void setPos(int ix, int iy) { x = ix; y = iy; }
	void setColor(int ncol, int dcol) {color= ncolor = ncol; dcolor = dcol; }
	void setT(bool b) { _bt = b; }
	int getStatus() { return(status); }
	void getXY(int& tx, int& ty) { tx = x; ty = y; }
	void setTarget(CMouse& m) { target = &m; }
	void updatePos() { if (target != nullptr) target->getXY(_tx, _ty); }
	int update(char cIn)
	{
		switch (cIn)
		{
		case'w':
			y += 20; break;
		case's':
			y -= 20; break;
		case'a':
			x -= 20; break;
		case'd':
			x += 20; break;
		default:
			break;
		}
		if (x > -X_MAX && x < X_MAX && y > -Y_MAX && y < Y_MAX) { // 安全區域內
			status = 1; color = ncolor;
		}
		else if (x < -X_MAX || x > X_MAX || y < -Y_MAX|| y > Y_MAX) { // 超出安全區
			status = 0;
		}
		else {status = 2; color = dcolor;
		}
		return(status);
	}
	void draw()
	{
		if (g_Boss == true) { drawBoxMan(0, 0, COLOR_WHITE); }
		else 
		{
			if (_bt == true) { drawBoxMan(_tx, _ty-120, COLOR_WHITE); }
			else drawColorBox(x, y, color);
		}
	}
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N12-8 老鼠控制的物件導向設計");
	char cIn=' ';
	int status;

	CMouse mx,m2;
	mx.init();//mx要初始化
	m2.init();//m2要初始化
	mx.setPos(40, 40);
	mx.setColor(COLOR_CYAN, COLOR_LIGHTBLUE);
	m2.setT(true);
	m2.setTarget(mx);
	
	m2.updatePos();//不需要傳參數
	status = mx.getStatus();
	while (status != 0)
	{
		cleardevice();
		drawFence();
		mx.draw();
		m2.draw();
		swapbuffers();
		cIn=getch();
		if (cIn == 'b' || cIn == 'B')g_Boss =!g_Boss;
		
		status=mx.update(cIn);//一定要更新狀態才會死!!!!
		m2.updatePos();//不需要傳參數
		if (status == 0) break; 
		rewind(stdin);
	}

	cleardevice();
	drawFence();
	outtextxy(X(-100), Y(0), "!! 老鼠死了 GG 按任意鍵結束!! ");
	setcolor(COLOR_WHITE);
	swapbuffers();
	while (!kbhit()) { delay(200); } return 0;
}
	





//
//
//bool g_bBoss = false;//全域變數(main 和 CMouse 類別內部的 draw()直接看到並修改它)
//class CMouse
//{
//private:
//	int x, y;
//	int status; // 1:正常狀態, 2:在邊界上, 0: 死亡
//	int color;
//	int ncolor, dcolor;
//
//	int _tx, _ty;
//	bool _bt;
//
//	CMouse* target;//追蹤者機制:類別內的指標變數
//public:
//	void init();
//	void draw();
//	void setColor(int ncol, int dcol) { color = ncolor = ncol; color=dcolor = dcol; }
//	void setPos(int ix, int iy) { x = ix; y = iy; }
//	int update(char cIn);
//	int getStatus() { return (status); }
//
//	void getXY(int& tx, int& ty) {tx = x; ty = y; }//引用符號 &，本意應該是要「把老鼠內部的物件座標 x 和 y 傳給外面變數」
//	void setT(bool b) { _bt = b; }
//	void updatePos() //實時追蹤 m2 透過箭頭運算子 ->，直接隔空呼叫 mx 的 getXY 函式，把 mx 當前的座標讀取出來，存進 m2 自己的 _tx 和 _ty 變數裡。
//	{
//	/*	int x, y;
//		target->getXY(x, y);
//		_tx = x; _ty = y;*/
//		target->getXY(_tx, _ty);
//	};
//	void setTarget(CMouse& m) { target = &m; }
//
//	void setXY(int x, int y) { _tx = x; _ty = y; }
//};
//
//void CMouse::init() {
//	x = 0; y = 0;	// 老鼠的起始位置
//	status = 1;		// 1 : 正常狀態, 2: 離開邊界0: 死亡狀態
//	color = ncolor = NORMAL_COLOR; dcolor = DANGER_COLOR;	// 設定老鼠的初始顏色為 ncolor
//	_tx = 0; _ty = 0;
//	_bt = false;
//}
//
//void CMouse::draw()
//{
//	if (g_bBoss == true)
//	{
//		drawBoxMan(0, 0, COLOR_WHITE);	// 出現另外一個臉
//	}
//	else
//	{
//		if (_bt==true)
//		{
//			drawBoxMan(_tx, _ty - 120, COLOR_WHITE);
//		}
//		else drawColorBox(x, y, color); // 畫出老鼠
//	}
//}
//int CMouse::update(char cIn)
//{
//	switch (cIn) {
//	case 'w': // 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
//		y = y + 20; break;
//	case 's': // 往下
//		y = y - 20; break;
//	case 'a': // 往左
//		x = x - 20; break;
//	case 'd': // 往右
//		x = x + 20; break;
//	}
//	if (x > -X_MAX && x < X_MAX && y > -Y_MAX && y < Y_MAX) { // 安全區域內
//		status = 1; color = ncolor;
//	}
//	else if (x < -X_MAX || x > X_MAX || y < -Y_MAX || y > Y_MAX) {
//		status = 0; // 移除邊界 老鼠死亡 遊戲結束			
//	}
//	else {	// 在邊界上
//		status = 2; color = dcolor;
//	}
//	return (status);
//}
//
//int main()
//{
//	char cIn;
//	int status;
//
//	int x, y;
//
//	initwindow(SCREENWIDTH, SCREENWIDTH, "N12-8 老鼠控制的物件導向設計");
//	CMouse mx,m2;
//	mx.init();
//	mx.setPos(40, 40); // 設定老鼠的位置到新的地方
//	mx.setColor(COLOR_CYAN, COLOR_LIGHTBLUE); // 設定新的顏色
//	//告訴 m2追蹤目標（target）是 mx，並且開啟追蹤開關（_bt = true）。
//	m2.setT(true);//要先設定m2是追蹤者
//
//	m2.setTarget(mx);//mx 的地址（&m）交給了 m2 的 target 指標。從這一刻起，m2 隨時可以直接調閱 mx 的內部資料。
//	m2.updatePos();
//	/*mx.getXY(x, y);
//	m2.setXY(x, y);*/
//
//	status = mx.getStatus();
//	while (status != 0)
//	{
//		cleardevice();
//		drawFence(); // 畫出範圍
//		mx.draw();	// 畫出老鼠
//
//		m2.draw();
//
//		swapbuffers();
//		cIn = getch();
//		//接受鍵盤輸入之後才能判斷
//		if (cIn == 'b' || cIn == 'B') g_bBoss = !g_bBoss; //開關式切換
//		status = mx.update(cIn);
//
//		m2.updatePos();
//		/*mx.getXY(x, y);
//		m2.setXY(x, y);*/
//
//		rewind(stdin);
//	}
//	cleardevice();
//	drawFence();
//	setcolor(COLOR_WHITE);
//	outtextxy(X(-100), Y(0), "!! 老鼠死了 GG 按任意鍵結束!! ");
//	swapbuffers();
//	while (!kbhit()) { delay(200); } return 0;
//}

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
#endif // p8