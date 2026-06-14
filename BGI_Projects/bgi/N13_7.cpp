#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p7
#ifdef p
using namespace std;

class CMouse//建立一個類別
{
private:
	int _ix, _iy;//座標
	int _icolor;//顏色
public:
	//建構元，用「成員初始化列表」，直接把參數指定給私有變數，用冒號開頭，後面用 變數名稱(參數) 的方式
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) : _ix(x), _iy(y), _icolor(color) { }
	 //【比較函式】：傳入另一隻老鼠 mt，比較兩者的 X 座標
	// 回傳型態是「CMouse」，代表這個函式執行完後，會吐回一隻完整的老鼠物件
	CMouse Compare(CMouse mt) {//函式不是建構元，前面不要加括號。它的格式是 回傳型態 函式名稱(參數)。
		 //如果「自己(_ix)」的 X 座標等於「對方(mt._ix)」的 X 座標
		if (_ix == mt._ix) return(*this);// 就把「自己這隻老鼠」回傳回去！
		else return(mt);//// 否則，就把「對方那隻老鼠」回傳回去！
	}
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
	/*bool Compare(CMouse mt) { //回傳的是「對或錯(bool)」
		this->_ix 明確指明是「自己的_ix」，跟直接寫 _ix 是一樣的意思。
		if (this->_ix == mt._ix) return(true);
		else return(false);
	}*/
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N13-7 this指標");
	CMouse mx(200, 100, 10);//宣告物件變數
	CMouse my(100, 0);//宣告物件變數
	//步驟 1：mx 呼叫 Compare(my)，此時 mx 的 X(200) 不等於 my 的 X(100)。
	//步驟 2：根據 Compare 的邏輯，它會 return(mt)，也就是回傳了「my」這隻老鼠。
	//步驟 3：所以整句變成 「my.draw();」，最終畫面上會畫出 my（在 100, 0 的位置）。
	mx.Compare(my).draw();
	/*if (mx.Compare(my)) cout << "mx 與 my 在同直線上" << endl;
	else cout << "mx 與 my 不在同一直線上" << endl;*/
	system("pause"); return 0;
}
#endif