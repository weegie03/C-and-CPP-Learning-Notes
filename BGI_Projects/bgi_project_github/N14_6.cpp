#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p6
#ifdef p
using namespace std;
class CMouse
{
public:
	int _ix, _iy;		// ρ公癬﹍竚
	int *_pcolor;// ρ公肅︹俱计夹跑计
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) {
		_ix = x; _iy = y; _pcolor = new int; *_pcolor = color;
	}
	~CMouse() { delete _pcolor; };
	void draw() { drawBoxMan(_ix,_iy,*_pcolor); }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-6 ン夹");
	CMouse* pmx = new CMouse;// ン夹跑计眔丁

	pmx->_ix=0; pmx->_iy=100;//硓筁ノ ->э硂唉ρ公ず场畒夹
	*(pmx->_pcolor) = 14; // 砞﹚独︹(硓筁тρ公硓筁ρ公ず场 *_pcolor э肅︹)
	//_pcolor セō琌 int*ウぃ琌ン┮ぃノΩ ->
	pmx->draw();//琵ρ公礶竚(夹糶猭)
	(*pmx).draw();//ン糶猭
	delete pmx;
	while (!kbhit()) { delay(200); } return 0;
}
//class CMouse
//{
//public:
//	int _ix, _iy;		// ρ公癬﹍竚
//	int *_pcolor;		// ρ公肅︹俱计夹跑计
//	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) { 
//		_pcolor = new int; 	*_pcolor = color; _ix = x; _iy = y;
//	}
//	~CMouse() { delete _pcolor; };
//	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
//};
//int main()
//{
//	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-6 ン夹");
//	CMouse *pmx = new CMouse; // ン夹跑计眔丁
//	
//	pmx->_ix = 0; pmx->_iy = 100; //硓筁ノ ->э硂唉ρ公ず场畒夹
//	*(pmx->_pcolor) = 14; // 砞﹚独︹(硓筁тρ公硓筁ρ公ず场 *_pcolor э肅︹)
//	
//	pmx->draw(); // 琵ρ公礶竚(夹糶猭)
//	//(*pmx).draw();//ン糶猭
//	delete pmx;
//	while (!kbhit()) { delay(200); } return 0;
//}
#endif