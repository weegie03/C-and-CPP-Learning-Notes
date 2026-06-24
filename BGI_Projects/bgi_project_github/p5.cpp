//  程式設計II，第三次上機考試 ，第 5 題 (3 分)
//   
// CSticker 類別包含
//		私有包含
//			int 型別的成員變數 x 、 y 與顏色 color
//		公有成員函式 
//         建構元：沒有引數，根據全域變數 g_idx 內容從 pos 二維陣列中取得
//				   並設定自己的成員變數  x 、 y 與顏色 color的內容
// 				   將 g_idx 內容加1
//         draw  函式 : 呼叫 drawColorBox，以儲存的座標與顏色畫一個方塊
//  
// CPainter 類別包含
//		私有包含
//			CSticker 類別的指標變數 psticker
//		公有成員函式 
//         建構元：為 psticker 取得 10 個 CSticker 儲存位置
//		   解構元：釋放 psticker 所取得的空間
//         draw  函式 : 以迴圈讓 psticker 中的每一個物件都呼叫 draw
//   
//  主程式:
//      以 CPainter 宣告一個物件，並以該物件呼叫 draw 函式，輸出如 P5.jpg 即可
// 
//  全域變數以所給的宣告以及根據註解宣告全域變數 g_idx
//


#define P5
#ifdef P

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

using namespace std;

// 宣告二維陣列 pos 如下
int pos[10][3] = {
	-300,  100,  6, -150,  100, 7,  0,  100, 8,   150,  100, 9,  300,  100, 10,
	-300, -100, 11, -150, -100, 12, 0, -100, 13,  150, -100, 14, 300, -100, 15 };

int id = 0;
class CSticker
{
private:
	int x, y, color;
public:
	CSticker() { x=pos[id][0];y= pos[id][1]; color=pos[id][2]; id++; }
	void draw() { drawColorBox(x, y, color); }
};
class CPainter
{
private:
	CSticker* psticker;
public:
	CPainter() { psticker = new CSticker[10];}
	~CPainter() { delete[] psticker; }
	void draw()
	{
		for (int i = 0; i < 10; i++)
		{
			psticker[i].draw();
		}
	}
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, " P5 ");
	srand((unsigned)time(NULL)); // 設定亂數產生器的初始值
	cleardevice();
	CPainter pic;
	pic.draw();
	swapbuffers();
	while (!kbhit()) { delay(200); } return 0;
}






//
//int id = 0;
//class CSticker {
//private:
//	int x, y, color;
//public:
//	CSticker() :x(pos[id][0]), y(pos[id][1]), color(pos[id][2]) { id++; };
//	void draw() { drawColorBox(x, y, color); }
//};
//class CPainter {
//private:
//	CSticker* psticker;
//public:
//	CPainter() { psticker = new CSticker[10]; }
//	~CPainter() { delete[] psticker; }
//	void draw() { for (int i = 0; i < 10; i++) { (psticker+i)->draw(); } }
//};
//
//
//int main()
//{
//	initwindow(SCREENWIDTH, SCREENWIDTH, " P5 ");
//	srand((unsigned)time(NULL)); // 設定亂數產生器的初始值
//	cleardevice();
//	CPainter pic;					// CPainter 宣告 pic 物件
//	pic.draw();					// pic  物件呼叫 draw() 函式
//	swapbuffers();
//	while (!kbhit()) { delay(200); } return 0;
//}

#endif