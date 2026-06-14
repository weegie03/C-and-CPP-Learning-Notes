#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

using namespace std;

class CCircle {
public:
	CCircle();
	~CCircle();
	void draw();
	void setName(char *);
private:
	char* name;
	int x, y, r;		// 老鼠的起始位置
	int color;
};

CCircle::CCircle()
{
	x = y = 0;
	r = 100;
	color = COLOR_LIGHTBLUE;
	name = nullptr;
}

CCircle::~CCircle()
{ 
	// 使用 delete[] name 釋放資源時，務必確認 name 確實是取得超過一個以上的儲存空間
	// 一般而言，字元指標變數就是常用在取得空間來儲存字串
	if (name != nullptr) delete[] name; 
}

void CCircle::draw()
{
	setcolor(color);
	circle(X(x), Y(y), r);
	if (name != nullptr) outtextxy(X(x),Y(y),name);
}

void CCircle::setName(char* cname)
{
	name = new char[strlen(cname) + 1];
	strcpy(name, cname);
}

int main(void) 
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "Stuct Example");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式

	CCircle cx;
	cx.setName("ABC");
	cx.draw();

	while (!kbhit())
	{
		delay(200);
	}
	return 0;

}

