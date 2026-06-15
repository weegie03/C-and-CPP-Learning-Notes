#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p9
#ifdef p
using namespace std;

class CMouse
{
private:
	//允許這幾個變數在 const 函數中也能被修改
	mutable int _ix, _iy, _icolor;
	int *_pi;//新增一個整數指標
public:
	CMouse(int ix = 0, int iy = 0, int icolor=7) : _ix(ix),_iy(iy),_icolor(icolor){
		_pi =nullptr;// 先把指標歸零
		cout << "建構元被呼叫" << endl;
		_pi =new int;//給記憶體
		//裝「什麼型態」的資料
	}

	CMouse(const CMouse(&m))//用 const 和引用的方式 (&m) 傳入要被複製的來源物件
	{
		_ix = m._ix;//複製座標和顏色
		_iy = m._iy;
		_icolor =m._icolor;
		
		if (m._pi!=nullptr) {//檢查{來源物件}的指標是不是空的
			_pi = new int;    // 分配新記憶體 自己去挖!
			*_pi = *(m._pi);    // 複製裡面的數值(不是複製地址
			//把「對方記憶體裡的值」拿過來放進「我的記憶體
			//檢查 m._pi，然後把記憶體挖在 _pi。
		}
		else {
			_pi = nullptr;// 如果來源(m._pi)是空的，自己也設為空
		}
		cout << "Copy建構元" << endl;
	}
	~CMouse()
	{
		if (_pi != nullptr) delete _pi;//釋放剛剛new的記憶體
		cout << "de解構元被呼叫" << endl;

	}
	/*CMouse(const CMouse &ma)  {
		_ix = ma._ix;  _iy = ma._iy; _icolor = ma._icolor;
		cout << "拷貝建構元被呼叫" << endl;
	}*/
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
	friend void xxx(CMouse &m) { m.draw(); }//建議寫成傳參照

};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N13-9 拷貝建構元");
	CMouse mx(100, 100, 7); // 建立時就會自動呼叫CMouse 建構元
	CMouse my(mx);// my 的內容來自 mx
	//建立 my 物件，並用 mx 當範本。此時會呼叫「拷貝建構元」進行深拷貝
	// CMouse my = mx; // 這樣寫也行
	my.draw();
	xxx(mx);
	while (!kbhit()) { delay(200); } return 0;
}






class CMouse
{
private:
	// mutable 允許這幾個變數在 const 函數中也能被修改
	mutable int _ix, _iy, _icolor;
	int* _pi;//新增一個整數指標
public:
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) : _ix(x), _iy(y), _icolor(color) { 
		_pi = nullptr;// 先把指標歸零
		cout << "建構元被呼叫" << endl;
		_pi = new int;//給記憶體
	}

	CMouse(const CMouse  &m)//用 const 和引用的方式 (&m) 傳入要被複製的來源物件
	{
		_ix = m._ix;//複製座標和顏色
		_iy = m._iy;
		_icolor = m._icolor;
		if (m._pi != nullptr) {//檢查來源物件的指標是不是空的
			_pi = new int;      // 分配新記憶體
			*_pi = *(m._pi);    // 複製裡面的數值(不是複製地址
		}
		else {
			_pi = nullptr;// 如果來源是空的，自己也設為空
		}//如果沒有這兩行會產生淺拷貝問提(mi._pi和my._pi指向同一個地方)
		//現在在my之前先去new_int把mx內容複製過來
		
		cout << "Copy建構元" << endl;
	}
	~CMouse()
	{
		if (_pi != nullptr) delete _pi;//釋放剛剛new的記憶體
		cout << "de解構元被呼叫" << endl;

	}
	/*CMouse(const CMouse &ma)  {
		_ix = ma._ix;  _iy = ma._iy; _icolor = ma._icolor;
		cout << "拷貝建構元被呼叫" << endl;
	}*/
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
	friend void xxx(CMouse &m) { m.draw(); }//建議寫成傳參照

};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N13-9 拷貝建構元");
	CMouse mx(100, 100, 7); // 建立時就會自動呼叫CMouse 建構元
	CMouse my(mx);  // my 的內容來自 mx
	//建立 my 物件，並用 mx 當範本。此時會呼叫「拷貝建構元」進行深拷貝
	// CMouse my = mx; // 這樣寫也行
	my.draw();
	xxx(mx);
	while (!kbhit()) { delay(200); } return 0;
}
#endif