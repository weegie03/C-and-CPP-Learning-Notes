#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"  // BGI 繪圖函式標頭檔
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"				// 基本繪圖函式標頭檔

#define EXAMPLE 1  // 設定成 1、2、3 ，執行對應的範例
#define NUM 10

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "BGI template");	// 開啟視窗
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand((unsigned int)time(NULL));

#if EXAMPLE == 1
	// ------ 第一個範例 ------ 
	// 讓一個半徑為 20 的圓從左邊(-300,0) 跑到右邊 (300,0) ，每次移動 1 的距離
	int i, x = -300, y  = 0;
	for ( i = 0; i < 600; i+=2)
	{
		cleardevice();
		circle(X(x + i), Y(y), 20);
		swapbuffers();
		Sleep(1); // 休息千分之一秒
	}

	// 讓一個長度為 50 的正方形從上方(0,300) 走道下方 (0,-300) ，每次移動 1 的距離
	// 邊走還要編旋轉

	float angle = 0;
	x = 0; y = 300;
	for (i = 0; i < 600; i+=2)
	{
		cleardevice();
		drawSquRot(x, y-i, 50, angle);
		swapbuffers();
		Sleep(1); // 休息千分之一秒
		angle = angle + 0.5f; // 每次增加 0.5 度
		if( angle >= 360.0f) angle = angle  -360.0f; // 超過 360，從 0 開始
	}

#elif EXAMPLE == 2
	// ------ 第二個範例 ------ 
	for (int i = -300; i < 300; i++)
	{
		cleardevice();
		drawRect(i, 0, 200, 100); // 長方形，給中心點與邊長
		settextstyle(0, HORIZ_DIR, 2);
		outtextxy(i + 200, 200, "數位科技設計");
		swapbuffers();
		Sleep(1); // 休息千分之一秒
	}
#else
	// ------ 第三個範例 ------ 
	//------------ 讓 10 個圓形動起來 ----------------

	int i, j;
	int x[NUM], y[NUM], radius[NUM];
	int cr[NUM], cg[NUM], cb[NUM];
	float vx[NUM], vy[NUM];
	float tx, ty, t;
	for (i = 0; i < 10; i++)
	{
		x[i] = rand() % 600 - 300;
		y[i] = rand() % 600 - 300;
		radius[i] = 10 + rand() % 30;
		cr[i] = rand() % 155 + 100;
		cg[i] = rand() % 155 + 100;
		cb[i] = rand() % 155 + 100;
		// 產生方向向量
		tx = (rand() % 1000) / 1000.0f - 0.5f;
		ty = (rand() % 1000) / 1000.0f - 0.5f;
		t = sqrtf(tx * tx + ty * ty);
		vx[i] = tx / t; vy[i] = ty / t; // 單位向量
	}

	for (j = 0; j < 3000; j++)
	{
		cleardevice();
		for (i = 0; i < NUM; i++)
		{
			// 變更圓心的位置，朝目前的方向前進
			x[i] = (int)(x[i] + 2.5f * vx[i]);
			y[i] = (int)(y[i] + 2.5f * vy[i]);
			setcolor(COLOR(cr[i], cg[i], cb[i]));  // 設定顏色
			circle(X(x[i]), Y(y[i]), radius[i]);
			// 產生新的偏移方向
			tx = (rand() % 1000) / 1000.0f - 0.5f;
			ty = (rand() % 1000) / 1000.0f - 0.5f;
			t = sqrtf(tx * tx + ty * ty);
			vx[i] = 0.8f * vx[i] + 0.2f * (tx / t);
			vy[i] = 0.8f * vy[i] + 0.2f * (ty / t);
			t = sqrtf(vx[i] * vx[i] + vy[i] * vy[i]);
			vx[i] = vx[i] / t; vy[i] = vy[i] / t;
			// 重新計算圓朝的方向
		}
		swapbuffers();
		Sleep(5);  // 休息千分之五秒
	}

#endif

	// 畫完後，進入無窮迴圈，直到你按下任一鍵盤按鍵後結束程式
	while (!kbhit()) { delay(200); }
	return 0;

}

//----- bgi_animate.cpp 繪圖程式碼保留區 -------------------

