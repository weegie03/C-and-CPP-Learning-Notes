#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "functions.h"
using namespace std;
class CMouse
{
private:
	int _ix, _iy; // 老鼠的重量
public:
	CMouse(int x = 0, int y = 0) { _ix = x;  _iy = y; }
	bool operator >(CMouse &m) { // 定義 > 運算子
		int d1, d2;
		d1 = this->_ix*this->_ix + this->_iy*this->_iy;
		d2 = m._ix*m._ix + m._iy*m._iy;
		if (d1 > d2) return(true);
		else return(false);
	}	
	bool operator>(const int &dist) { // 定義 > 運算子
		int d1 = this->_ix*this->_ix + this->_iy*this->_iy;
		if (d1 > dist*dist) return(true);
		else return(false);
	}
	int dist() { return(_ix*_ix + _iy*_iy); }
};
bool operator>(const int &dist, CMouse &m) { // 定義> 運算子
	if (dist*dist > m.dist()) return(true);
	else return(false);
}
int main()
{
	CMouse mx(4, 4);
	CMouse my(1, 5);
	if (mx > 10) cout << "mx 與原點距離超過 10" << endl;
	else if (6 > mx)  cout << "mx 與原點距小於6" << endl;
	else cout << "mx 與原點距介於 6 到 10 之間" << endl;
	system("pause"); return 0;
}