#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "functions.h"
#define p14
#ifdef p
using namespace std;

class CMouse
{
private:
	int _iw;// ρ公秖
public:
	int operator+(CMouse & m) {
		return(this->_iw + m._iw);
	}//セ㊣
	CMouse(int iw = 100) { _iw = iw; }
};

int main()
{
	CMouse m1;
	CMouse m2(250);
	cout << "ㄢ唉ρ公" << m1+m2<< endl;
	system("pause");
}
//class CMouse
//{
//private:
//	int _iw; // ρ公秖
//public:
//	int operator+(CMouse &m) { 	return(this->_iw + m._iw);  }//セ㊣
//	CMouse(int w = 100) {	_iw = w;  }
//};
//
//int main()
//{
//	CMouse mx; 
//	CMouse my(150);
//	cout << "ㄢ唉ρ公" << mx + my << endl;
//	system("pause");
//}
#endif