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
		c[i].x = rand() % 600 - 300;
		c[i].y = rand() % 600 - 300;
		c[i].radius = 10 + rand() % 40;
		c[i].r = rand() % 155 + 100;
		c[i].g = rand() % 155 + 100;
		c[i].b = rand() % 155 + 100;
		setcolor(COLOR(c[i].r, c[i].g, c[i].b));  // 設定顏色
		circle(X(c[i].x), Y(c[i].y), c[i].radius);
	}
	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}