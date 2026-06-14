#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#define p
#ifdef p6
using namespace std;
class C2DShape {
protected:
	int _x, _y, _color;
public:
	C2DShape(int x = 0, int y = 0, int color = COLOR_WHITE)
	{
		_x = x; _y = y; _color = COLOR_WHITE;
	}
	void setPos(int x, int y) { _x = x; _y = y; }
	void setColor(int c) { _color = c; }
	virtual void draw() { drawColorBox(_x, _y, _color); }//加上virtual才會被宣告成多型(父類別被改寫的成員函式)
};

class CRect : public C2DShape {
private:
	int _w, _h;
public:
	CRect(int w = 100, int h = 100) { _w = w; _h = h; }
	void draw() {
		setcolor(_color);
		drawRect(_x, _y, _w, _h);
	}
};

class CTri : public C2DShape {
private:
	int _w;
public:
	CTri(int w = 100) { _w = w; }
	void draw() {
		setcolor(_color);
		drawTri(_x, _y, _w);
	}
};

class CCir : public C2DShape {
private:
	int _w;
public:
	CCir(int w = 100) { _w = w; }
	void draw() {
		setcolor(_color);
		circle(X(_x), Y(_y), _w);
	}
};

struct tNode {
	int n;//整數 n
	C2DShape* ps;//拿父類別宣告一個指標變數
	struct tNode *link;//指向下一個車廂的指標 link
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "Stuct Example");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	tNode* head = NULL, * tail = NULL, *get = NULL, *cur = NULL;//宣告指標：head, tail, get, cur 並全部初始化為 nullptr。
	int n = 6;

	head =new tNode;//取得車廂
	head->n=1;//n放入1
	head->ps = new C2DShape(0,300);//幫ps取得空間放入2DShape
	head->link = NULL;//指向NULL歸零
	tail = head;//尾巴指向頭

	for (int i = 1; i <= 5; i++)
	{
		get = new tNode;//動態配置（new）一個新節點空間給「新取得」指標。
		get->n = i % 3 + 1;//將「新取得」的整數 n 設定
		if ( get->n== 1) {
			get->ps=new CCir(150);//把圓放進座標
			get->ps->setPos(i * 150 - 450, 0);//設定座標
			get->ps->setColor(8 + i);//設定顏色
		}
		else if (get->n == 2) {
			 get->ps=new CTri(150);//把三角形放進座標
			 get->ps->setPos(i * 150 - 450, 0);//設定座標
			 get->ps->setColor(8 + i);//設定顏色
		}
		else {
			get->ps=new CRect(150);//把三角形放進座標
			get->ps->setPos(i * 150 - 450, 0);//設定座標
			get->ps->setColor(8 + i);//設定顏色
		}
		get->link = NULL;//將「新取得」的 link 設定為空指標(最後一節)
		tail->link = get;// 「尾」指標所指車廂的 link，死死勾住這個「新取得」的車廂地址。
		tail = get;//「尾」指標的標籤，移到最新的「新取得」車廂身上
	}

	cur = head;//目前巡邏」指標先站在「頭」的位置。
	while (cur != NULL)
	{
		printf("%d\n", cur->n);//印出來現在的連結串列
		cur->ps->draw();//先呼叫車廂的貨物 再呼叫畫出來
		cur = cur->link; //「目前巡邏」指標移向下一節車廂的 link 地址。
	}

	printf("\nfree\n");
	while ( head!= NULL)//只要火車「頭」還不是空指標
	{
		cur = head;//「目前巡邏」指標幫忙抓住現在的火車「頭」。
		head = head->link;//「頭」指標往後移，指向下一節車廂的 link 地址。
		printf("%d\n", cur->n);//印出現在的連結串列
		delete cur->ps;//把車廂內存放2DShape的貨物(存放物件的指標變數)放掉
		delete cur;//釋放節點本身
	}

	while (!kbhit())
	{
		delay(200);
	}
	return 0;

}


//class C2DShape {
//protected:
//	int _x, _y, _color;
//public:
//	C2DShape(int x = 0, int y = 0, int color = COLOR_WHITE)
//	{
//		_x = x; _y = y; _color = COLOR_WHITE;
//	}
//	void setPos(int x, int y) { _x = x; _y = y; }
//	void setColor(int c) { _color = c;}
//	virtual void draw(){ drawColorBox(_x, _y, _color); 	}//加上virtual才會被宣告成多型(父類別被改寫的成員函式)
//};
//
//class CRect : public C2DShape {
//private:
//	int _w, _h;
//public:
//	CRect(int w = 100, int h = 100) { _w = w; _h = h; }
//	void draw() {
//		setcolor(_color);
//		drawRect(_x, _y, _w, _h);
//	}
//};
//
//class CTri: public C2DShape {
//private:
//	int _w;
//public:
//	CTri(int w = 100) { _w = w;}
//	void draw() {
//		setcolor(_color);
//		drawTri(_x, _y, _w);
//	}
//};
//
//class CCir : public C2DShape {
//private:
//	int _w;
//public:
//	CCir(int w = 100) { _w = w; }
//	void draw() {
//		setcolor(_color);
//		circle(X(_x), Y(_y), _w);
//	}
//};
//
//struct tNode {
//	int n;
//	C2DShape* ps;//拿父類別宣告一個指標變數
//	struct tNode* link;
//};
//
//int main()
//{
//	int i;
//	initwindow(SCREENWIDTH, SCREENWIDTH, "Stuct Example");
//	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
//	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
//	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
//	srand(time(NULL));
//
//	tNode* head=nullptr, * tail = nullptr, * get = nullptr, *cur= nullptr;
//	int n = 6;
//
//	head = new tNode;//取得車廂
//	head->n = 1;//n放入1
//	head->ps = new C2DShape(0, 300);//幫ps取得空間放入2DShape
//	head->link = NULL;//指向NULL歸零
//	tail = head;//尾巴指向頭
//
//	for (int i = 1; i <= 5; i++)
//	{
//		get = new tNode;
//		get->n = i%3+1;
//		if (get->n == 1) {
//			get->ps = new CCir(150);//把圓放進座標
//			get->ps->setPos(i * 150 - 450, 0);//設定座標
//			get->ps->setColor(8 + i);//設定顏色
//		}
//		else if (get->n == 2) {
//			get->ps = new CTri(150);//把三角形放進座標
//			get->ps->setPos(i * 150 - 450, 0);//設定座標
//			get->ps->setColor(8 + i);//設定顏色
//		}
//		else {
//			get->ps = new CRect(150);//把三角形放進座標
//			get->ps->setPos(i * 150 - 450, 0);//設定座標
//			get->ps->setColor(8 + i);//設定顏色
//		}
//		get->link = NULL;
//		tail->link = get;
//		tail = get;
//	}
//
//	cur = head;
//	while ( cur != NULL )
//	{
//		printf("%d\n", cur->n);
//		cur->ps->draw();//先呼叫車廂的貨物 再呼叫畫出來
//		cur = cur->link;
//	}
//
//	printf("\nfree\n");
//	while( head != NULL ) 
//	{
//		cur = head;
//		head = head->link;
//		printf("%d\n", cur->n);
//		delete cur->ps;//把車廂內存放2DShape的貨物(存放物件的指標變數)放掉
//		delete cur;//釋放節點本身
//	}
//
//	while (!kbhit())
//	{
//		delay(200);
//	}
//	return 0;
//
//}

//.x = rand() % 600 - 300;
//.y = rand() % 600 - 300;
//.radius = 50 + rand() % 50;
//.cr = rand() % 155 + 100;
//.cg = rand() % 155 + 100;
//.cb = rand() % 155 + 100;

//using namespace std;
//class C2DShape {
//public:
//	virtual void draw() { printf("基礎圖形\n"); }
//	virtual ~C2DShape() {}
//};
//class CCir : public C2DShape {
//public:
//	void draw() { printf("圓形\n"); }
//};
//struct tNode {
//	int n;
//	C2DShape* ps;
//	struct tNode*link;
//};
//int main()
//{
//	tNode* head = NULL, * tail = NULL, * get = NULL, * cur = NULL;
//	head = new tNode;
//	head->n = 1;
//	head->ps = new C2DShape;
//	head->link = NULL;
//	tail = head;
//
//	for (int i = 1; i <= 3; i++)
//	{
//		get = new tNode;
//		get->n = i + 1;
//		get->ps = new CCir();
//		get->link = NULL;
//		tail->link = get;
//		tail = get;
//	}
//	printf("巡邏開始 ---\n");
//	cur = head;
//	while (cur!=NULL)
//	{
//		cur->ps->draw();
//		printf("%d", cur->n);
//		cur = cur->link;
//	}
//	printf("\n--- 拆除開始 ---\n");
//	cur = head;
//	while (head!=NULL)
//	{
//		cur = head;
//		head = head->link;
//		printf("%d", cur->n);
//		delete cur->ps;
//		delete cur;
//	}
//	printf("結束!");
//	system("pause"); return(0);
//}
#endif