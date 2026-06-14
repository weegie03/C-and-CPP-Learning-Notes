//  程式設計II，第三次上機考試 ，第 4 題 (4 分)
//   
// CMouse 類別包含
//		私有包含
//			int 型別的成員變數 x 、 y 與顏色 color
//			bool 型別的變數 btracer
//			CMouse 的【指標變數】 target
//		公有成員函式 
//         建構元：沒有引數，直接設定 x 與 y 為 0, 0，color 為  COLOR_YELLOW
//                 btracer 為 false (預設為【被】追蹤者)
//				   target 為 nullptr
//         setTracer 函式 : 一個 bool 型別的引數，設定 btracer 為傳入的值
//		   setTarget 函式 : 一個 CMouse 型別的【參照】引數，
//							設定 target 為指向該傳入【物件的位址】
//	 	   getPos 函式   : 兩個 int 型別以【傳指標】或【傳參照】的形式傳入
//                         將目前老鼠的位置利用該傳入的變數傳回給呼叫者
//		   updatePos 函式: 透過 target 所指向的被追蹤者，呼叫其 getPos 函釋，
//						   取得被追蹤者的座標，並設定給【自己】
// 
//         draw  函式    : 根據自己的狀態(追蹤還是被追蹤)呼叫對應的函式畫出自己，
//						   補強所給的程式內容
// 
//		   update 函式   : 直接使用所給的函式內容
// 
//   完成以下的程式碼，並控制四方塊上下左右移動即可，
//					   追蹤者保持在玩家控制方塊的正下方即可
//   

#define P4
#ifdef P4

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include "functions.h"

using namespace std;
class CMouse
{
private:
	int x, y, color;
	bool btracer;
	CMouse* target;
public:
	CMouse()
	{
		x = 0; y = 0; color = COLOR_YELLOW;
		btracer = false;
		target = nullptr;
	}
	void setTracer(bool b) { btracer=b; }//把傳入的引數 b 賦值給成員變數 btracer
	void setTarget(CMouse& m) { target = &m; } //設定 target 為指向該傳入【物件的位址】
	void getPos(int& ix, int& iy) { ix = x; iy = y; }//把自己的座標 (x, y) 傳出去給引數 (ix, iy)
	void updatePos() {
		if (target != nullptr) {
			int tx, ty;
			target->getPos(tx, ty); // 取得被追蹤者的座標
			x = tx;                 // 設定給自己
			y = ty;
		}//「不需引數」，直接透過 target 指標去取得被追蹤者的座標，並設定給自己
	}
	void draw()
	{
		if (btracer == true) drawBoxMan(x, y-100, color);
		else drawColorBox(x, y, color);
	}
	void update(char c);
};
void CMouse::update(char c)
{
		switch (c) {
		case 'w': // 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
			y += 20;			// Y 軸增 20	
			break;
		case 's': // 往下
			y -= 20;			// Y 軸減 20
			break;
		case 'a': // 往左
			x -= 20;			// X 軸減 20
			break;
		case 'd': // 往右
			x += 20;			// X 軸增 20
			break;
		}
}


int main()
{
	char cIn;
	int i = 0;
	initwindow(SCREENWIDTH, SCREENWIDTH, " P4 ");
	CMouse m1, m2;					// 以 CMouse 宣告 兩個物件 m1 與 m2
	m2.setTracer(true);			// m2 呼叫 setTracer 設定本身為追蹤者
	m2.setTarget(m1);					// m2 呼叫 setTarget 為 m1 為追蹤對象
	m2.updatePos();// m2 呼叫.....
	while (i < 10)	// 移動 10 次程式就會離開迴圈
	{
		cleardevice();
		m1.draw();				// 畫出 m1 老鼠
		m2.draw();				// 畫出 m2 老鼠
		swapbuffers();
		cIn = getch();
		m1.update(cIn);				// m1 呼叫 update 給予 cIn 更新自己的位置 
		m2.updatePos();			// m2 呼叫....
		rewind(stdin);
		i++;
	}
	cleardevice();
	swapbuffers();
	while (!kbhit()) { delay(200); } return 0;
}





//class Cmouse {
//private:
//	int x, y, color;
//	bool tracer;
//	Cmouse* target;
//public:
//	Cmouse():x(0),y(0),color(COLOR_YELLOW),tracer(false),target(nullptr){};
//	void setTracer(bool b) { tracer = b; }
//	void setTarget(Cmouse& c) { target = &c; }
//	void getPos(int& a, int& b) { a = x; b = y; }
//	void updatePos(Cmouse& c) {
//		c.getPos(x, y);
//	}
//	void draw() {
//		if (tracer== false) drawBoxMan(x, y - 100, color);
//		else drawColorBox(x, y, color);
//	}
//	void update(char c) {
//		switch (c) {
//		case 'w': // 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
//			y += 20;			// Y 軸增 20	
//			break;
//		case 's': // 往下
//			y -= 20;			// Y 軸減 20
//			break;
//		case 'a': // 往左
//			x -= 20;			// X 軸減 20
//			break;
//		case 'd': // 往右
//			x += 20;			// X 軸增 20
//			break;
//		}
//
//	}
//};
//

//int main()
//{
//	char cIn;
//	int i = 0;
//	initwindow(SCREENWIDTH, SCREENWIDTH, " P4 ");
//	Cmouse m1, m2;					// 以 CMouse 宣告 兩個物件 m1 與 m2
//	m2.setTracer(true);					// m2 呼叫 setTracer 設定本身為追蹤者
//	m2.setTarget(m1);						// m2 呼叫 setTarget 為 m1 為追蹤對象
//	m2.updatePos(m1);// m2 呼叫.....
//	while ( i < 10 )	// 移動 10 次程式就會離開迴圈
//	{
//		cleardevice();
//		m1.draw();				// 畫出 m1 老鼠
//		m2.draw();				// 畫出 m2 老鼠
//		swapbuffers();
//		m1.update(getch());				// m1 呼叫 update 給予 cIn 更新自己的位置 
//		m2.updatePos(m1);				// m2 呼叫....
//		rewind(stdin);
//		i++;
//	}
//	cleardevice();
//	swapbuffers();
//	while (!kbhit()) { delay(200); } return 0;
//}

#endif