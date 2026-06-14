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
// 宣告結構變數，投影片範例 20 到 36
#define p2
#ifdef p

struct sCircle//struct 改成  class 就從結構體換成一種類別了
{
	char name[10];
	int x, y;
	int color[3];
	int radius;
};

int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "第九章宣告結構變數，投影片範例 20 到 36");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));


	// 設定初始值 {"abc",-100,200,200,150,250,50}
	//struct sCircle c1;

	//結構的成員是陣列

	//printf("輸入名稱: "); scanf("%s");  // 輸入名稱
	//printf("X 與 Y 座標 : "); scanf("%d%d"); // 輸入 X/Y 座標
	//printf("顏色 rgb "); scanf("%d%d%d"); // 輸入顏色
	//printf("半徑: "); scanf("%d"); // 輸入半徑

	// 畫出該圓形
	//setcolor(COLOR(c1.color[0], c1.color[1], c1.color[2]));  // 設定顏色
	//outtextxy(X(c1.x), Y(c1.y),c1.name);
	//circle(X(c1.x), Y(c1.y), c1.radius);


	// 結構陣列 畫 5 個圓

	//struct sCircle cf[10], boss = { "boss" , 0, 0, {0, 0, 0}, 0 };
	//for (i = 0; i < 10; i++)//錄影的最後一段
	//{
	//	sprintf(cf[i].name, "%02d", i + 1);
	//	cf[i].x = rand() % 600 - 300;
	//	cf[i].y = rand() % 600 - 300;
	//	cf[i].radius = 50 + rand() % 50;
	//	cf[i].color[0] = rand() % 155 + 100;
	//	cf[i].color[1] = rand() % 155 + 100;
	//	cf[i].color[2] = rand() % 155 + 100;
	//	outtextxy(X(cf[i].x), Y(cf[i].y), cf[i].name);
	//	setcolor(COLOR(cf[i].color[0], cf[i].color[1], cf[i].color[2]));  // 設定顏色
	//	circle(X(cf[i].x), Y(cf[i].y), cf[i].radius);
	//}

	//// 計算 boss 的位置
	//for (i = 0; i < 10; i++)
	//{

	//	boss.x += cf[i].x;
	//	boss.y += cf[i].y;
	//	boss.radius += cf[i].radius;
	//	boss.color[0] += cf[i].color[0];
	//	boss.color[1] += cf[i].color[1];
	//	boss.color[2] += cf[i].color[2];
	//}
	//boss.x = boss.x/10;
	//boss.y = boss.y/10;
	//boss.radius = boss.radius/5;
	//boss.color[0] /=10;
	//boss.color[1] /=10;
	//boss.color[2] /=10;

	//outtextxy(X(boss.x), Y(boss.y), boss.name);
	//setcolor(COLOR(boss.color[0], boss.color[1], boss.color[2]));  // 設定顏色
	//circle(X(boss.x), Y(boss.y), boss.radius);
	
	// 結構指標變數
	struct sCircle cx = { "abc",-100,200,200,150,250,50 };
	
	struct sCircle *pc;
	pc = &cx;//指向的位址照這個結構的宣告抓到記憶體
	//outtextxy(X(pc->x), Y(pc->y), pc->name);
	//setcolor(COLOR(pc->color[0], pc->color[1], pc->color[2]));  // 設定顏色
	//circle(X(pc->x), Y(pc->y), pc->radius);//.的優先權高於*
	//circle(X((*pc).x) 寫法2
	// 
	sCircle* px;//希望透過malloc存放這一個圓的所有相關資料
	px = (sCircle*)malloc(sizeof(sCircle)*10);//一個結構指標變數不能像陣列一樣看到所有的內容，只能看到第一個位置

	for (i = 0; i < 10; i++)//陣列的寫法改成指標的形式
	{
		sprintf(px[i].name, "%02d", i + 1);
		(px+i)->x = rand() % 600 - 300;
		(px+i)->y = rand() % 600 - 300;
		(px+i)->radius = 10 + rand() % 30;
		(px+i)->color[0] = rand() % 155 + 100;
		(px+i)->color[1] = rand() % 155 + 100;
		(px+i)->color[2] = rand() % 155 + 100;
		//px[i].是陣列寫法
		outtextxy(X(px[i].x), Y(px[i].y), px[i].name);
		setcolor(COLOR(px[i].color[0], px[i].color[1], px[i].color[2]));
		circle(X(px[i].x), Y(px[i].y), px[i].radius);

	}
	//(*px) = cx;//一般變數的寫法 把另一個結構變數的值塞進去給他
	//printf("sizeof(cx)=%4d\n", sizeof(cx));//一般的結構變數到底占用多大空間
	//printf("sizeof(cx)=%4d\n", sizeof(pc));//(下面兩個指標變數)//
	//printf("sizeof(cx)=%4d\n", sizeof(px));
	
	// 動態記憶體存取
	//pc = (struct sCircle *)malloc(sizeof(struct sCircle));
	//printf("輸入名稱: "); scanf("%s");  // 輸入名稱
	//printf("X 與 Y 座標 : "); scanf("%d%d"); // 輸入 X/Y 座標
	//printf("顏色 rgb "); scanf("%d%d%d"); // 輸入數學成績
	//printf("半徑: "); scanf("%d"); // 輸入數學成績

	// free(pc);

	// 巢狀結構




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
#endif