#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

//#define DRAW_EXAMPLE

//void DrawCircles();
//#define ANIMATION

#define NUM 10
// 宣告結構變數，投影片範例 37 到 38 巢狀結構

struct sShape {
	char name[10];
	int x, y;
	int color[3];
};

struct sCircle
{
	struct sShape info;
	int radius;
};

int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "第九章範投影片範例 37 到 38 巢狀結構");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	struct sCircle c1;

	//printf("輸入名稱: "); scanf("%s");  // 輸入名稱
	//printf("X 與 Y 座標 : "); scanf("%d%d"); // 輸入 X/Y 座標
	//printf("顏色 rgb "); scanf("%d%d%d"); // 輸入顏色
	//printf("半徑: "); scanf("%d"); // 輸入半徑

	// 畫出該圓形
	//setcolor(COLOR(  ));  // 設定顏色
	//outtextxy(X( ), Y(), );
	//circle(X( ), Y(), );




#ifdef DRAW_EXAMPLE
	------------ 固定畫出10個圓形 ----------------
	int i;
	int x, y, radius;
	int cr, cg, cb;
	for ( i = 0; i < 10; i++)
	{
		x = rand() % 600 - 300;
		y = rand() % 600 - 300;
		radius = 10 + rand() %40 ;
		cr = rand() % 155 + 100;
		cg = rand() % 155 + 100;
		cb = rand() % 155 + 100;
		setcolor(COLOR(cr, cg, cb));  // 設定顏色
		circle(X(x), Y(y), radius);
	}
#endif
	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

//----- template.cpp 繪圖程式碼保留區 -------------------
//setfillstyle(1, 2);		// 設定填滿樣式
//fillellipse(X(-300), Y(-300), 100, 100);	// 填滿一個橢圓，長短軸給一樣就是圓

//drawRect(0, 0, 500, 100); // 長方形，給中心點與邊長
//drawRectRot(-50, -50, 50, 40, 30.0f);  // 長方形，給中心點、邊長與旋轉角度

//drawTri(0, 0, 100);  // 正三角形，給中心點與邊長
//drawTriRot(100, 100, 100, -30.0f);   // 正三角形，給中心點與邊長與旋轉角度

//drawSquRot(-100, -200, 100, -45.0f);  // 正四方型，給中心點與邊長與角度

//settextstyle(0, HORIZ_DIR, 3); // 1 for 8x8   2 for 16x16 bitmap font
//outtextxy(100, 200, "數位科技設計");
//for (int i = -300; i < 300; i++)
//{
//	cleardevice();
//	drawRect(i, 0, 200, 100); // 長方形，給中心點與邊長
//    settextstyle(0, HORIZ_DIR, 2);
//	outtextxy(i+200, 200, "數位科技設計");
//	Sleep(5);
//	swapbuffers();
//}
//---------------------------------------

//printf("輸入名稱: "); scanf("%s", c1.name);  // 輸入名稱
//printf("X 與 Y 座標 : "); scanf("%d%d", &c1.x, &c1.y); // 輸入 X/Y 座標
//printf("顏色 rgb "); scanf("%d%d%d", &c1.cr, &c1.cg, &c1.cb); // 輸入數學成績
//printf("半徑: "); scanf("%d", &c1.radius); // 輸入數學成績



////------------ 讓 10 個圓形動起來 ----------------
//int i, j;
//int x[NUM], y[NUM], radius[NUM];
//int cr[NUM], cg[NUM], cb[NUM];
//float vx[NUM], vy[NUM];
//float tx, ty, t;
//for (i = 0; i < 10; i++)
//{
//	x[i] = rand() % 600 - 300;
//	y[i] = rand() % 600 - 300;
//	radius[i] = 10 + rand() % 30;
//	cr[i] = rand() % 155 + 100;
//	cg[i] = rand() % 155 + 100;
//	cb[i] = rand() % 155 + 100;
//	//setcolor(COLOR(cr[i], cg[i], cb[i]));  // 設定顏色
//	//circle(X(x[i]), Y(y[i]), radius[i]);
//	// 產生方向向量
//	tx = (rand() % 1000) / 1000.0f - 0.5f;
//	ty = (rand() % 1000) / 1000.0f - 0.5f;
//	t = sqrtf(tx*tx + ty*ty);
//	vx[i] = tx / t; vy[i] = ty / t; // 單位向量
//}
//
//for (j = 0; j < 3000; j++)
//{
//	cleardevice();
//	for (i = 0; i < NUM; i++)
//	{
//		// 變更圓心的位置，朝目前的方向前進
//		x[i] = (int)(x[i] + 2.5f * vx[i]);
//		y[i] = (int)(y[i] + 2.5f * vy[i]);
//		setcolor(COLOR(cr[i], cg[i], cb[i]));  // 設定顏色
//		circle(X(x[i]), Y(y[i]), radius[i]);
//
//		// 產生新的偏移方向
//		tx = (rand() % 1000) / 1000.0f - 0.5f;
//		ty = (rand() % 1000) / 1000.0f - 0.5f;
//		t = sqrtf(tx*tx + ty*ty);
//		vx[i] = 0.8f * vx[i] + 0.2f * (tx / t);
//		vy[i] = 0.8f * vy[i] + 0.2f * (ty / t);
//		t = sqrtf(vx[i] * vx[i] + vy[i] * vy[i]);
//		vx[i] = vx[i] / t; vy[i] = vy[i] / t;
//		// 重新計算圓朝的方向
//		Sleep(1);
//	}
//	swapbuffers();
//}