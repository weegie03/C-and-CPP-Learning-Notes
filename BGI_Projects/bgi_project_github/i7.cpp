//  程式設計二，第一次上機考試 ，第 7 題 (5 分)
// 
//  宣告一個結構 sShape，裡面包含成員變數有座標(int) x/y 、顏色(int) r/g/b 
//  再宣告結構 sCircle，裡面包含成員變數有基本資料 info (型別是sShape)以及半徑(int) rad
//  在主程式宣告 sCircle 的兩個指標變數，cx 與 boss
//		cx 透過 new 取得儲存 6 個圓的儲存空間，boss 以 new 取得儲存一個圓的空間
//  以所提供的亂數搭配一個迴圈產生圓的基本資料，並儲存到此一維陣列中
//  第二個迴圈則是繪製隨機生成的圓，同時計算 boss 結構變數的內容
//      座標是所有圓座標的平均，顏色是所有圓座標的平均，半徑是所有圓座標總和的一半
//
//  要求：滿足以下要求，且執行達成需求才算分數
//      1. 本題是考【巢狀結構】與【動態記憶體配置】，
//		   必須完成指定的兩個結構指標變數的宣告與動態記憶體的取得
//      2. 第一個迴圈產生圓的內容，第二個迴圈畫出所儲存圓的內容，並計算 boss 的參數(加總)
//      3. 第二個迴圈離開後再計算 boss 的正確參數
//		4. 最後必須釋放 cx 與 boss 所取得變數
//   
// 提醒各位以下的程式碼不要刪除：此行是將 boss 結構變數內容都設定成 0
//		ZeroMemory(boss, sizeof(sCircle));  // 將 boss 結構變數內容都設定成 0 
// 
//  參考 p7.jpg 
//

#define P7
#ifdef P7

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <minwinbase.h>
#include "functions.h"

//以 struct 宣告 sShape 結構
struct sShape
{
	int x, y, r, g, b;
};
//以 struct 宣告 sCircle 結構
struct  sCircle
{
	sShape info;
	int rad;
	char name[10];
};
int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P7");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	//  sCircle 宣告兩個指標變數，cx 與 boss
	sCircle*cx;
	sCircle*boss;
	cx = new sCircle[6];//cx取得空間
	boss = new sCircle;//boss取得空間

	// 產生圓的內容並儲存到結構陣列中
	for (i = 0; i < 6; i++)
	{
		sprintf((cx+i)->name, "%02d",i+1);//名稱
		(cx + i)->info.x= -350 + i * 120; // 座標
		(cx + i)->info.y= rand() % 200 - 200;
		(cx + i)->rad = (i + 1) * 20 + rand() % 10;	// 半徑
		(cx + i)->info.r= rand() % 155 + 100;	// 顏色
		(cx + i)->info.g= rand() % 155 + 100;
		(cx + i)->info.b= rand() % 155 + 100;
	}

	ZeroMemory(boss, sizeof(sCircle));  // 將 boss 結構變數內容都設定成 0，此行不要刪
	//memset(boss, 0, sizeof(Circle));
	// 畫出圓並計算 boss 的相關參數
	sprintf(boss->name, "boss");       // 給 boss 一個名字方便顯示
	for (i = 0; i < 6; i++)
	{
		outtextxy(X((cx+i)->info.x), Y((cx+i)->info.y), (cx+i)->name);
		setcolor(COLOR((cx+i)->info.r, (cx+i)->info.g, (cx+i)->info.b));  // 設定顏色
		circle(X((cx + i)->info.x), Y((cx + i)->info.y),(cx+i)->rad );
		// 壘加相關變數內容到 boss 對應的變數中
		boss->info.x += cx[i].info.x;//因為boss不是陣列 只能用->
		boss->info.y += cx[i].info.y;
		boss->info.r += cx[i].info.r;
		boss->info.g += cx[i].info.g;
		boss->info.b += cx[i].info.b;
		boss->rad += cx[i].rad;
		
	}

	// boss 座標是所有圓座標的平均，顏色是所有圓座標的平均，半徑是所有圓座標總和的一半
	boss->info.x/= 6;
	boss->info.y/= 6;
	boss->info.r/= 6;
	boss->info.g/= 6;
	boss->info.b/= 6;
	// 半徑是所有圓半徑總和的一半（前面迴圈已經把所有 rad 加總在 boss->rad 了）
	boss->rad/=2;
	outtextxy(X(boss->info.x), Y(boss->info.y),boss->name);
	setcolor(COLOR((boss->info.r), boss->info.g, boss->info.b));  // 設定顏色
	circle(X(boss->info.x), Y(boss->info.y), boss->rad);

	delete[] cx;// 釋放 cx   結構指標變數
	delete boss;// 釋放 boss 結構指標變數
	cx = nullptr;
	boss = nullptr;
	

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}
////以 struct 宣告 sShape 結構
//struct shape {
//	int x, y, r, g, b;
//};
//
////以 struct 宣告 sCircle 結構
//struct Circle {
//	shape info;
//	int rad;
//	char name[10];
//};
//
//int main()
//{
//	int i;
//	initwindow(SCREENWIDTH, SCREENWIDTH, "P7");
//	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
//	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
//	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
//	srand(time(NULL));
//
//	Circle* cx; Circle* boss;//  sCircle 宣告兩個指標變數，cx 與 boss
//
//	cx = new Circle[6];
//	boss = new Circle;
//
//	// 產生圓的內容並儲存到結構陣列中
//	for (i = 0; i < 6; i++)
//	{
//		sprintf((cx + i)->name, "%02d", i + 1);//名稱
//		(cx + i)->info.x = -350 + i * 120; // 座標
//		(cx + i)->info.y = rand() % 200 - 200;
//		(cx + i)->rad = (i + 1) * 20 + rand() % 10;	// 半徑
//		(cx + i)->info.r = rand() % 155 + 100;	// 顏色
//		(cx + i)->info.g = rand() % 155 + 100;
//		(cx + i)->info.b = rand() % 155 + 100;
//	}
//
//	ZeroMemory(boss, sizeof(Circle));  // 將 boss 結構變數內容都設定成 0，此行不要刪
//	//memset(boss, 0, sizeof(Circle));
//	// 畫出圓並計算 boss 的相關參數
//	for (i = 0; i < 6; i++)
//	{
//		outtextxy(X((cx + i)->info.x), Y((cx + i)->info.y), (cx + i)->name);
//		setcolor(COLOR((cx + i)->info.r, (cx + i)->info.g, (cx + i)->info.b));  // 設定顏色
//		circle(X((cx + i)->info.x), Y((cx + i)->info.y), (cx + i)->rad);
//		// 壘加相關變數內容到 boss 對應的變數中
//		boss->info.x += (cx + i)->info.x;
//		boss->info.y += (cx + i)->info.y;
//		boss->info.r += (cx + i)->info.r;
//		boss->info.g += (cx + i)->info.g;
//		boss->info.b += (cx + i)->info.b;
//		boss->rad += (cx + i)->rad;
//	}
//
//	// boss 座標是所有圓座標的平均，顏色是所有圓座標的平均，半徑是所有圓座標總和的一半
//	boss->info.x /= 6;
//	boss->info.y /= 6;
//	boss->info.r /= 6;
//	boss->info.g /= 6;
//	boss->info.b /= 6;
//	boss->rad /= 2;
//
//	outtextxy(X(boss->info.x), Y(boss->info.y), boss->name);
//	setcolor(COLOR(boss->info.r, boss->info.g, boss->info.b));  // 設定顏色
//	circle(X(boss->info.x), Y(boss->info.y), boss->rad);
//
//	delete[] cx;			// 釋放 cx   結構指標變數
//	delete(boss);				// 釋放 boss 結構指標變數
//	cx = nullptr;
//	boss = nullptr;
//
//	while (!kbhit())
//	{
//		delay(200);
//	}
//	return 0;
//}

#endif