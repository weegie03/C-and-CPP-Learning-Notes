#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

#define NUM 10

struct sCircle
{
	int x, y;
	int r, g, b;
	int radius;

	void gen()
	{
		x = rand() % 600 - 300;
		y = rand() % 600 - 300;
		radius = 10 + rand() % 40;
		r = rand() % 155 + 100;
		g = rand() % 155 + 100;
		b = rand() % 155 + 100;
	}

	void draw()
	{
		setcolor(COLOR(r, g, b));  // 設定顏色
		circle(X(x), Y(y), radius);
	}
};

int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "Stuct Example");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	struct sCircle c[10];
	
	// 延伸範例，讓 pc 取得10個儲存空間並，運用以下程式碼
	// 產生 10 個圓的內容，畫出來，然後釋放資源

	for (i = 0; i < NUM; i++)
	{
		c[i].gen();
		c[i].draw();
	}
	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}