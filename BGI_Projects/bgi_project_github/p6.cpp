//  程式設計II，第三次上機考試 ，第 6 題 (5 分)
//
//  CShape 類別
//     被保護成員包含：
//          int 型別的成員變數 X/Y 座標與顏色
//     公有成員函式：
//          建構元 : 三個 int 型別的引數，x/y 座標與顏色，皆有預設值 0, 0, COLOR_WHITE
//          解構元 : 無引數，輸出 CShape 解構元被呼叫
//          setPos 函式 : 兩個 int 型別的引數，設定 x/y 座標
//          draw 函式 : 無引數，呼叫 drawColorBox() 畫色塊，顏色用成員變數
//
//  CTriangle 類別公有繼承自 CShape 類別 
//     私有成員包含：
//          int 型別的成員變數，儲存邊長大小
//     公有成員函式：
//          建構元 : 1 個 int 型別的引數，代表邊長，預設值為 100
//          draw 函式 : 無引數，呼叫 setcolor 與 呼叫 drawTri ，給中心點跟長度
// 
//  CRect 類別公有繼承自 CShape 類別 
//     私有成員包含：
//          2 個 int 型別的成員變數，分別儲存寬與高
//     公有成員函式：
//          建構元 : 2 個 int 型別的引數，代表邊寬與高，預設值都為 100
//          draw 函式 : 無引數，呼叫 setcolor 與 呼叫 drawRect ，給中心點、寬與高
//
//  CCircle 類別公有繼承自 CShape 類別 
//     私有成員包含：
//          int 型別儲存【半徑】的成員變數
//     公有成員函式：
//          建構元 : 1 個 int 型別的引數，儲存半徑，預設值 100
//          draw 函式 :  無引數，呼叫 setcolor 與 呼叫 circle ，給中心點與半徑
//
// 宣告 tNode 為一結構，包含成員變數如下:
//	int 型別 n、C2DShape 型別的指標變數 p、tNode 型別的指標變數 link
// 
// 主程式 : 依照程式中的註解完成指定的程式碼，並完成圖 p7.jpg 的繪製，
//	        同時輸出如圖上的訊息
// 

#define P
#ifdef P6

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include "functions.h"

using namespace std;
class C2DShape
{
protected:
	int x, y, color;
public:
	C2DShape(int ix = 0, int iy = 0, int icolor = COLOR_WHITE) :x(ix), y(iy), color(icolor) {};
	virtual ~C2DShape() {
		cout << " CShape 解構元被呼叫";
	}
	void setPos(int ix = 0, int iy = 0) { x = ix; y = iy; }
	void setColor(int icolor) { color = icolor; }
	virtual void draw() { drawColorBox(x, y, color); }
};
class CTriangle :public C2DShape
{
private:
	int n;
public:
	CTriangle(int in = 100) :n(in) {};
	void draw()
	{
		setcolor(color);
		drawTri(x, y, n);
	}
};
class CRect :public C2DShape
{
private:
	int w,h;
public:
	CRect(int iw = 100,int ih=100) :w(iw),h(ih) {};
	void draw()
	{
		setcolor(color);
		drawRect(x, y, w,h);
	}
};
class CCircle :public C2DShape
{
private:
	int r;
public:
	CCircle(int ir = 100) :r(ir){};
	void draw()
	{
		setcolor(color);
		circle(X(x),Y(y), r);
	}
};
struct tNode
{
	int n;
	C2DShape* p;
	struct tNode* link;
};
int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, " P6 ");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	tNode* head = nullptr, * tail = nullptr, * get = nullptr, * cur = nullptr;
	int n = 6;
	head = new tNode;
	head->n = 1;
	head->link = NULL;
	tail = head;
	head->p = new C2DShape;
	for (int i = 0; i < n; i++)
	{
		get = new tNode;
		get->n = i % 3 + 1;
		if (get->n == 1)
		{
			get->p = new CTriangle;
			get->p->setColor(10 + i);
			get->p->setPos(-300 + i * 100, 100);
		}
		else if (get->n == 2)
		{
			get->p = new CRect;
			get->p->setColor(10 + i);
			get->p->setPos(-300 + i * 100, 100);
		}
		else if (get->n == 3)
		{
			get->p = new CCircle;
			get->p->setColor(10 + i);
			get->p->setPos(-300 + i * 100, 100);
		}
		get->link = NULL;
		tail->link = get;
		tail = get;
	}
	cout << "節點遊歷: ";
	cur = head;
	while (cur != NULL)
	{
		cout << " " << cur->n;
		cur->p->draw();
		cur = cur->link;
	}
	cout << endl;
	cout << "節點釋放";
	while (head != NULL)
	{
		cur = head;
		head = head->link;
		cout << " " << cur->n<<endl;
		delete cur->p;
		delete cur;
	}
	cout << endl;
	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

//
//class C2DShape{
//protected:
//	int x, y, color;
//public:
//	C2DShape(int a=0 ,int b=0,int c= COLOR_WHITE):x(a),y(b),color(c){}
//	~C2DShape() { cout << "CShape 解構元被呼叫" << endl; }
//	void setColor(int a) { color =a; }
//	void setpos(int a, int b) { x = a; y = b; }
//	virtual void draw() { drawColorBox(x, y, color); }
//};
//class CTriangle :public C2DShape {
//private:
//	int side;
//public:
//	CTriangle(int a=100) :side(a) {};
//	void draw() {
//		setcolor(color); // 呼叫 setColor ，給顏色
//		drawTri(x, y, side); // 呼叫 drawTri ，給中心點跟長度
//	}
//};
//
//
//class CRect :public C2DShape {
//private:
//	int side_a, side_b;
//public:
//	CRect(int a = 100,int b =100) :side_a(a), side_b(b) {};
//	void draw() {
//		setcolor(color);
//		drawRect(x,y ,side_a ,side_b );
//	}
//};
//class CCircle :public C2DShape {
//private:
//	int side;
//public:
//	CCircle(int a = 100) :side(a) {};
//	void draw() {
//		setcolor(color);
//		circle(X(x), Y(y),side );
//	}
//};
//
//
//// 宣告 tNode 為一結構，包含成員變數如下:
//// int 型別 n
//// C2DShape 型別的指標變數 p
//// tNode 型別的指標變數 link
//
//struct tNode {
//	int n;
//	C2DShape* p;
//	tNode* link;
//};
//
//int main()
//{
//	int i;
//	initwindow(SCREENWIDTH, SCREENWIDTH, " P6 ");
//	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
//	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
//	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
//	srand(time(NULL));
//
//	tNode* head = nullptr, * tail = nullptr, * get = nullptr, * cur = nullptr;
//	int n = 6;
//
//	head = new tNode;						// 為 head 以 new 取得一個儲存 tNode 節點
//	head->n = 1;						// 設定 head 節點 n 值為 1
//	head->link = NULL;							// 設定 head 節點的 link 內容為 NULL
//	tail = head;							// tail 指向 head 節點
//	head->p = new C2DShape;							// 為 head 節點 p 以 new 取得一個儲存 C2DShape 的儲存空間
//
//	for (int i = 1; i <= 5; i++)
//	{
//		get = new tNode;					// 為 get 節點以 new 取得一個儲存 tNode 的儲存空間
//		get->n = i % 3 + 1; // 設定 get 節點 n 值為 i%3+1
//		if (get->n==1) {	// 當 get 節點 n 值為 1 時
//			get->p = new CTriangle;					// 為 get 節點 p 以 new 取得一個儲存 CTriangle 的儲存空間
//			get->p->setColor(10 + i);					// 以 get 節點 p 呼叫 setColor 函式，引數值為 10+i
//			get->p->setpos(-300 + i * 100, 100);					// 以 get 節點 p 呼叫 setPos 函式，引數值分別為為 -300 + i * 100 與 100
//			
//		}
//		else if (get->n == 2) {	// 當 get 節點 n 值為 2 時
//			get->p = new CRect;											// 為 get 節點 p 以 new 取得一個儲存 CRect 的儲存空間
//			get->p->setColor(10 + i);										// 以 get 節點 p 呼叫 setColor 函式，引數值為 10+i
//			get->p->setpos(-300 + i * 100, 100);							// 以 get 節點 p 呼叫 setPos 函式，引數值分別為為 -300 + i * 100 與 100
//			
//		}
//		else {	// 其他
//			get->p = new CCircle;											// 為 get 節點 p 以 new 取得一個儲存 CCircle 的儲存空間
//			get->p->setColor(10 + i);										// 以 get 節點 p 呼叫 setColor 函式，引數值為 10+i
//			get->p->setpos(-300 + i * 100, 100);	// 以 get 節點 p 呼叫 setPos 函式，引數值分別為為 -300 + i * 100 與 100
//			
//		}
//		get->link = NULL;					// 設定 get 節點 的 link 內容為 NULL
//		tail->link = get;					// 設定 tail 變數 link 為 get 節點
//		tail = get;					// 設定 tail 變數為 list 最後一個節點
//	}
//
//	cout << "節點遊歷: ";
//	cur = head;
//	while (cur != NULL)
//	{
//		cout << "  " <<cur->n		;		// 輸出節點內 n 的內容
//		cur->p->draw();							// cur 指向節點中的 p 呼叫 draw 繪製對應圖型
//		cur = cur->link;							// 讓 cur 走向下一個節點
//	}
//	cout << endl;
//
//	cout << "節點釋放: ";
//	// 資源釋放部分，用以下的架構自行完成
//	while (head != NULL)
//	{
//		cur = head;							// cur 指向 ....
//		head = head->link;							// 變更 head 節點的指向
//		cout << "  " <<		cur->n;		// 輸出節點內 n 的內容
//		delete cur->p;							// 刪除節點內 p 所指向的資源
//		delete cur;							// 刪除目前所指向節點
//	}
//	cout << endl;
//
//	while (!kbhit())
//	{
//		delay(200);
//	}
//	return 0;
//}

#endif