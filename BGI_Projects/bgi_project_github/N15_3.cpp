#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p3
#ifdef p
using namespace std;
//class C2Shape
//{
//protected:
//	int _ix, _iy, _icolor;
//public:
//	C2Shape(int ix = 0, int iy = 0, int icolor = COLOR_WHITE)
//	{
//		_ix = ix; _iy = iy; _icolor = icolor;
//	}
//	void setColor(int icolor) { _icolor = icolor; }
//};
//class CTriangle :public C2Shape
//{
//private:
//	int _len, _rot;
//public:
//	CTriangle() { _len = 200; _rot = 45; };
//	CTriangle(int icolor, int len = 100, int rot = 60):C2Shape(0,0,icolor ){ _len = len; _rot = 60; }
//	void setRot(int r) { _rot = r; }
//	void draw() { setcolor(_icolor); drawTriRot(_ix, _iy, _len, _rot); }
//};
//class CRect :public C2Shape
//{
//private:
//	int _w, _h;
//public:
//	CRect() { _w = 200, _h = 100; }
//	CRect(int icolor, int w = 100, int h = 100) :C2Shape(0, 0, icolor)
//	{
//		_w = w, _h = h;
//	}
//	void draw()
//	{
//		setcolor(_icolor);
//		drawRect(_ix, _iy, _w, _h);
//	}
//};
//class CCircle :public C2Shape
//{
//private:
//	int _rad;
//public:
//	CCircle() { _rad = 200; }
//	CCircle(int icolor, int rad = 100) :C2Shape(0, 0, icolor)
//	{
//		_rad = rad;
//	}
//	void draw()
//	{
//		setcolor(_icolor);
//		circle(X(_ix), Y(_iy), _rad);
//	}
//};
//int main()
//{
//	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-3 基礎類別建構元的指定");
//	CTriangle t1, t2(11, 400);
//	t1.draw(); t2.draw();
//	CRect r1, r2(12, 150, 250);
//	r2.draw();
//	CCircle c1(10, 300);
//	c1.draw();
//	/*CMouse mx1, mx2(13, 6), mx3(100, 100, 12, 6);
//	mx1.draw();	mx1.showAttack();
//	mx2.setPos(0, 100);
//	mx2.draw();	mx2.showAttack();
//	mx3.draw();*/
//	while (!kbhit()) { delay(200); }//畫面暫停案空白鍵繼續
//	t1.setColor(13);
//	for (int i = 0; i <360; i+=5)
//	{
//		cleardevice();
//		t1.setRot(i);
//		t1.setColor(i % 10 + 5);
//		t1.draw();
//		Sleep(100);
//	}
//	while (!kbhit()) { delay(200); } return 0;
//}
class CCharacter {
private:
	int  _ix, _iy, _icolor;	// 座標與顏色
public:
	CCharacter(int ix=0, int iy=0, int icolor=COLOR_WHITE) { // 建構元	
		_ix = ix; _iy = iy; _icolor = icolor; // 設定位置與顏色
		cout << "CCharacter 建構元被呼叫" << endl;
	}
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
	void setColor(int icolor) { _icolor = icolor; }
	void setPos(int ix, int iy) { _ix = ix; _iy = iy; }
};
class CMouse : public CCharacter {
private:
	int _iattack;	// 設定攻擊力
public:
	CMouse(int ivalue = 10) { _iattack = ivalue; }
	CMouse(int ix, int iy, int icolor, int ivalue = 10) :CCharacter(ix, iy, icolor)
	{
		_iattack = ivalue;
		cout << "CMouse 呼叫角色顏色建構元" << endl;
	}
	CMouse(int icolor, int ivalue = 10) : CCharacter( 0, 0, icolor) {
		_iattack = ivalue; 
		cout << "CMouse 呼叫角色顏色建構元" << endl;
	}
	void showAttack() { cout << "攻擊力=" << _iattack << endl; }
};
class C2Shape
{
protected:
	int _ix, _iy, _icolor;
public:
	C2Shape(int ix = 0, int iy = 0, int icolor = COLOR_WHITE)
	{
		_ix = ix, _iy = iy; _icolor = icolor;
		cout << "C2Shape 建構元被呼叫" << endl;
	}
	
	void setColor(int icolor) { _icolor = icolor; }
	void setPos(int ix, int iy) { _ix = ix, _iy = iy; }
};
class CTriangle :public C2Shape
{
private:
	int len,rot;
public:
	CTriangle() { len = 200; rot = 45; }//圖形旋轉
	CTriangle(int _icolor,int lenght=100,int _rot=60) :C2Shape(0,0,_icolor)
	{
		len = lenght; rot = 60;
	}
	void setLenght(int lenght) { len = lenght; }
	void setRot(int r) { rot = r; }
	void draw()
	{
		setcolor(_icolor);//父類別不能放在私有的
		drawTriRot(_ix, _iy, len,rot);
	}
};
class CRect:public C2Shape
{
private:
	int _w, _h;
public:
	CRect() { _w = 200, _h = 100; }
	CRect(int icolor,int w=100, int h=100):C2Shape(0,0,icolor)
	{ _w = w, _h = h; }
	void draw()
	{
		setcolor(_icolor);
		drawRect(_ix, _iy, _w, _h);
	}
};
class CCircle :public C2Shape
{
private:
	int _rad;
public:
	CCircle() { _rad = 200; }
	CCircle(int icolor, int rad = 100) :C2Shape(0,0,icolor)
	{
		_rad = rad;
	}
	void draw()
	{
		setcolor(_icolor);
		circle(X(_ix), Y(_iy), _rad);
	}
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-3 基礎類別建構元的指定");
	CTriangle t1, t2(11, 400);
	t1.draw();
	t2.draw();
	CRect r1,r2(12,150,250);
	r2.draw();
	CCircle c1(10,300);
	c1.draw();
	/*CMouse mx1, mx2(13, 6), mx3(100, 100, 12, 6);
	mx1.draw();	mx1.showAttack();
	mx2.setPos(0, 100);
	mx2.draw();	mx2.showAttack();
	mx3.draw();*/
	while (!kbhit()) { delay(200); }//畫面暫停案空白鍵繼續
	t1.setColor(13);
	for (int i = 0; i < 360; i+=5)
	{
		cleardevice();
		t1.setRot(i);
		t1.setColor(i % 10 + 5);
		t1.draw();
		Sleep(100);
	}
	while (!kbhit()) { delay(200); } return 0;
}
#endif