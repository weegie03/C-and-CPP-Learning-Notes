#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "functions.h"
#define p15
#ifdef p
using namespace std;
class CMouse
{
private:
	int _ix, _iy; // 老鼠的座標
public:
	CMouse(int ix = 0, int iy = 0) { _ix = ix; _iy = iy; }
	bool operator>(const CMouse &m){// 定義 > 運算子(物件>物件)
		int d1, d2;
		d1 = this->_ix * this->_ix + this->_iy * this->_iy;
		d2 = m._ix * m._ix + m._iy * m._iy;
		if (d1 > d2) return (true);
		else return(false);
	}
	bool operator>=(const CMouse& m) { // 定義 >= 運算子(物件>=物件)
		int d1, d2;
		d1 = this->_ix * this->_ix + this->_iy * this->_iy;
		d2 = m._ix * m._ix + m._iy * m._iy;
		if (d1 >= d2) return(true);
		else return(false);
	}
	bool operator>(const int d) {// 定義 > 運算子(物件>常數)
		//老鼠距離平方，是否大於常數的平方
		int d1;
		d1 = this->_ix * this->_ix + this->_iy * this->_iy;
		if (d1 > d * d) return(true);
		else return(false);
	}
	bool operator>=(const int d){ // 定義 > 運算子(物件>=常數)
		int d1;
		d1 = this->_ix * this->_ix + this->_iy * this->_iy;
		if (d1 >=d * d) return(true);
		else return(false);
	}
	bool operator==(const int d){// 定義 > 運算子(物件==常數)
		int d1;
		d1 = this->_ix * this->_ix + this->_iy * this->_iy;
		if (d1 == d * d) return(true);
		else return(false);
	}
	float dis()const//成員函數：計算並回傳距離平方
	{
		//const 物件，只能呼叫有加 const 的成員函數。
		return(_ix * _ix + _iy * _iy);
	}
	friend bool operator<(const int d,const CMouse& m)//定義「常數 < 物件」
	{// 因為常數（如 3）在左邊，不能當成 class 的成員函數呼叫，所以必須用 friend 寫在外頭
		if (d * d<m.dis()) return(true);
		else return(false);
	}
};

int main()
{
	CMouse mx(4, 4);
	CMouse my(1, 5);
	if (mx >= my) cout << "mx 離原點比較遠" << endl;
	else cout << "my 離原點比較遠" << endl;
	if (mx >= 3) cout << "mx 離3比較遠" << endl;
	else cout << "3 離原點比較遠" << endl;
	if (3 < mx) cout << "mx 離3比較遠" << endl;
	else cout << "3 離原點比較遠" << endl;
	system("pause");
}
//class CMouse
//{
//private:
//	int _ix, _iy; // 老鼠的座標
//public:
//	CMouse(int x = 0, int y = 0) { _ix = x;  _iy = y; }
//	bool operator >(CMouse &m) { // 定義 > 運算子
//		int d1, d2;
//		d1 = this->_ix*this->_ix + this->_iy*this->_iy;
//		d2 = m._ix*m._ix + m._iy*m._iy;
//		if (d1 > d2) return(true);
//		else return(false);
//	}	
//	bool operator >=(CMouse& m) { // 定義 > 運算子(物件>物件)
//		int d1, d2;
//		d1 = this->_ix * this->_ix + this->_iy * this->_iy;
//		d2 = m._ix * m._ix + m._iy * m._iy;
//		if (d1 >= d2) return(true);
//		else return(false);
//	}
//	bool operator >(const int d) { // 定義 > 運算子(物件>常數)
//		int d1;
//		d1 = this->_ix * this->_ix + this->_iy * this->_iy;//d1就是呼叫者本身
//		if (d1 >d*d) return(true);
//		else return(false);
//	}
//	bool operator >=(int d) { // 定義 > 運算子(物件>=常數)
//		int d1;
//		d1 = this->_ix * this->_ix + this->_iy * this->_iy;//d1就是呼叫者本身
//		if (d1 > d * d) return(true);
//		else return(false);
//	}
//	bool operator ==(float d) { // 定義 > 運算子(物件==常數)
//		int d1;
//		d1 = this->_ix * this->_ix + this->_iy * this->_iy;//d1就是呼叫者本身
//		if (d1 > d * d) return(true);
//		else return(false);
//	}
//	float dist() const
//	{
//		return(_ix * _ix + _iy * _iy);
//	}
//	friend bool operator <(const float d, const CMouse& m)
//	{
//		if (d * d < m.dist()) return (true);
//		else return (false);
//	}
//};
//
//int main()
//{
//	CMouse mx(4, 4);
//	CMouse my(1, 5);
//	if (mx >= my) cout << "mx 離原點比較遠" << endl;
//	else cout << "my 離原點比較遠" << endl;
//	if (mx >= 3) cout << "mx 離3比較遠" << endl;
//	else cout << "3 離原點比較遠" << endl;
//	if (3<mx) cout << "mx 離3比較遠" << endl;
//	else cout << "3 離原點比較遠" << endl;
//	system("pause");
//}
#endif