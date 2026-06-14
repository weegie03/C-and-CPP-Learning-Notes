#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p3
#ifdef p
#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED

#define X_MAX 200	// 定義可活動的範圍
#define Y_MAX 200	// 定義可活動的範圍
using namespace std;
void drawFence();

class CMouse
{
private:
	int x, y;
	int *status; // 1:正常狀態, 2:在邊界上, 0: 死亡
	int color;
	int ncolor, dcolor;
public:
	CMouse();//建構元
	~CMouse();//解構元
	int init() {//void改int
		x = 0; y = 0;
		*status = 1;
		/*color = NORMAL_COLOR;
		ncolor = NORMAL_COLOR;
		dcolor = DANGER_COLOR;*/
		return(*status);//加上狀態值傳回去
	}
	void setXY(int ix, int iy)
	{
		x = ix, y = iy;
	}
	int update(char cIn);
	void draw()
	{
		drawColorBox(x, y, color); // 畫出老鼠
	}
	void setColor(int nc, int dc);
	//friend int getStatus(CMouse m);//友誼函式(/原型宣告一定要寫在類別內
};
//int getStatus(CMouse m) { return(m.status); }//不用再寫friend 一定是類別(物件)的引數

CMouse::CMouse()
{
	status = nullptr;
	x = 0; y = 0;
	status = new int;//取得空間
	*status = 1;
	/*color = NORMAL_COLOR;
	ncolor = NORMAL_COLOR;
	dcolor = DANGER_COLOR;*/
}
CMouse::~CMouse()
{
	if (status != nullptr) delete status;
	cout << "解構元被呼叫" << endl;
	system("pause");
}
void CMouse::setColor(int nc, int dc)
{
	ncolor = nc; // 正常顏色
	dcolor = dc; // 邊界顏色
	color = nc;// 初始顯示正常顏色
	//color = ncolor = nc; color = dcolor = dc;
}
int CMouse::update(char cIn)
{
	switch (cIn) {
	case 'w': // 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
		y = y + 20; break;
	case 's': // 往下
		y = y - 20; break;
	case 'a': // 往左
		x = x - 20; break;
	case 'd': // 往右
		x = x + 20; break;
	}
	if (x > -X_MAX && x < X_MAX && y > -Y_MAX && y < Y_MAX) { // 安全區域內
		*status = 1; color =ncolor;//color = NORMAL_COLOR改掉
	}
	else if (x < -X_MAX || x > X_MAX || y < -Y_MAX || y > Y_MAX) {
		*status = 0; // 移除邊界 老鼠死亡 遊戲結束			
	}
	else {	// 在邊界上
		*status = 2; color =dcolor;
	}
	return (*status);
}


int main()
{
	char cIn;
	int status;//原本int status=1改掉
	srand((unsigned)time(NULL)); 
	initwindow(SCREENWIDTH, SCREENWIDTH, "N12-3 老鼠控制的物件導向設計");
	
	{
		CMouse mx;
		for (int i = 0; i < 2; i++)
		{
			status = mx.init();//加上狀態
			int nx, ny;
			nx = (rand() % 8 + 1) * 20;
			ny = -(rand() % 8 + 1) * 20;//亂數生成的位置
			mx.setXY(nx, ny);

			int normal = rand() % 14 + 1; // 1~14 (避免抽到 15 或 0)
			int danger = (normal + 2) % 15 + 1; // 確保與 normal 不同
			mx.setColor(normal, danger);
			//mx.setColor(rand() % 15 + 1, rand() % 15 + 1);

			//status = getStatus(mx);
			while (status != 0)
			{
				cleardevice();
				drawFence(); // 畫出範圍
				mx.draw();	// 畫出老鼠
				swapbuffers();
				cIn = getch();
				status = mx.update(cIn);
				rewind(stdin);
			}
		}
		cleardevice();
		drawFence();
		setcolor(COLOR_WHITE);
		outtextxy(X(-100), Y(0), "!! 老鼠死了 GG 按任意鍵結束!! ");
		swapbuffers();
	}
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