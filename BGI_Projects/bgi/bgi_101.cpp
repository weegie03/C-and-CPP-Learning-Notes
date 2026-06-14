#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"  // BGI 繪圖函式標頭檔
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"				// 基本繪圖函式標頭檔

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "BGI template");	// 開啟視窗
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand((unsigned int)time(NULL));

	// 單張繪圖
	// 畫一個圓、三角形、正方形、長方形
	//------  BGI 預設提供的函式  -----------
	//可參考  https://www.cs.colorado.edu/~main/bgi/doc/
	//
	int x = 100, y = 100;
	setcolor(COLOR(100, 200, 250)); // 設定顏色
	circle(X(x-100), Y(y), 100);	// BGI 預設提供的函式
	setfillstyle(1, 2);				// 設定填滿樣式
	fillellipse(X(-300), Y(-300), 50, 50);	// 填滿一個橢圓，長短軸給一樣就是圓
	settextstyle(0, HORIZ_DIR, 3); // 1 for 8x8   2 for 16x16 bitmap font
	outtextxy(100, 200, "數位科技設計");

	//------  functions.cpp 中提供的函式 (沒有提供填色功能) ---------
	setcolor(COLOR(250, 200, 100)); // 設定顏色
	drawTri(x, y, 50);
	//drawTriRot(X(x), Y(y), 50, 90); // 逆時針方向，所給為角度

	setcolor(COLOR(200, 250, 100)); // 設定顏色
	drawSquare(x+100, y, 100);
	//drawSquRot(X(x + 100), Y(y), 100, 45); // 逆時針方向，所給為角度

	setcolor(COLOR(200, 250, 200)); // 設定顏色
	drawRect(x + 200, y - 200, 100, 20); 

	//drawRectRot(X(x + 200), Y(y - 200), 100, 20, 30); // 逆時針方向，所給為角度
	
	// 複雜的範例
	// 隨機產生 10 個圓的座標、半徑與顏色，並依序的畫出來
	 
	//int i, radius;
	//int cr, cg, cb;
	//for (i = 0; i < 10; i++)
	//{
	//	x = rand() % 600 - 300;
	//	y = rand() % 600 - 300;
	//	radius = 10 + rand() % 40;
	//	cr = rand() % 155 + 100;
	//	cg = rand() % 155 + 100;
	//	cb = rand() % 155 + 100;
	//	setcolor(COLOR(cr, cg, cb));  // 設定顏色
	//	circle(X(x), Y(y), radius);
	//}

	//int i, j;
	//for (i = -300; i <= 300; i += 50)
	//{
	//	for (j = -300; j <= 300; j += 50)
	//	{
	//		moveto(X(i), Y(300)); // 設定線段的起點
	//		lineto(X(j), Y(-300)); // 設定線段的終點
	//	}

	//}


	// 畫完後，進入無窮迴圈，直到你按下任一鍵盤按鍵後結束程式
	while (!kbhit()) { delay(200); }
	return 0;

}

//----- bgi_101.cpp 繪圖程式碼保留區 -------------------
//setfillstyle(1, 2);		// 設定填滿樣式
//fillellipse(X(-300), Y(-300), 100, 100);	// 填滿一個橢圓，長短軸給一樣就是圓

//drawRect(0, 0, 500, 100); // 長方形，給中心點與邊長
//drawRectRot(-50, -50, 50, 40, 30.0f);  // 長方形，給中心點、邊長與旋轉角度

//drawTri(0, 0, 100);  // 正三角形，給中心點與邊長
//drawTriRot(100, 100, 100, -30.0f);   // 正三角形，給中心點與邊長與旋轉角度

//drawSquRot(-100, -200, 100, -45.0f);  // 正四方型，給中心點與邊長與角度