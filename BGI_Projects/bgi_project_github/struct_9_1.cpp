#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#define p4
#ifdef p

//#define DRAW_EXAMPLE
// 宣告結構變數，投影片範例 1 到 19

#define NUM 10

struct sShape
{
	char name[NUM];
	int x, y;
	int cr, cg, cb;
	//int radius;
};
struct sCircle//宣告出新的資料型別
{
	//char name[NUM];
	////int pos[2];//如果結構成員是陣列變數
	//int x, y;
	//int cr, cg, cb;
	sShape info;
	int radius;
};
	

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "第九章結構基本觀念，投影片範例 1 到 19");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	sCircle c1[10];

	/*strcpy(c1.name, "ABC");
	c1.x = -100; c1.y = 200; c1.cr = 200; c1.cg = 150; c1.cb = 250;
	c1.radius = 50;*/

	// 宣告結構變數，投影片範例 1 到 18
	//struct sCircle c1 = { "abc",-100,200,200,150,250,50 };
	
	for (int i = 0; i < 10; i++)
	{
		sprintf(c1[i].info.name, "%2d", i + 1);
		c1[i].info.x = rand() % 600 - 300;
		c1[i].info.y = rand() % 600 - 300;
		c1[i].radius = 10 + rand() % 40;
		c1[i].info.cr = rand() % 155 + 100;
		c1[i].info.cg = rand() % 155 + 100;
		c1[i].info.cb = rand() % 155 + 100;
	}
	for (int i = 0; i < 10; i++)
	{
		setcolor(COLOR(c1[i].info.cr, c1[i].info.cg, c1[i].info.cb));  // 設定顏色
		outtextxy(X(c1[i].info.x), Y(c1[i].info.y), c1[i].info.name);
		circle(X(c1[i].info.x), Y(c1[i].info.y), c1[i].radius);
	}
	
	//printf("輸入名稱: "); scanf("%s",c1.name);  // 輸入名稱
	//printf("X 與 Y 座標 : "); scanf("%d%d",&c1.x,&c1.y); // 輸入 X/Y 座標
	//printf("顏色 rgb "); scanf("%d%d%d"); // 輸入顏色
	//printf("半徑: "); scanf("%d"); // 輸入半徑

	// 畫出該圓形
	//setcolor(COLOR(c1.cr, c1.cg, c1.cb));  // 設定顏色
	//outtextxy(X(c1.x), Y(c1.y),c1.name);
	//circle(X(c1.x), Y(c1.y), c1.radius);

#ifdef DRAW_EXAMPLE
	// ------------ 固定畫出10個圓形 ----------------
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
#endif