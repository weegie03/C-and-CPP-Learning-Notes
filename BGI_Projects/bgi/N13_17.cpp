#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "functions.h"
#define p17
#ifdef p

using namespace std;
class CMouse
{
private:
	int _iw; // ρ公秖
public:
	int operator+(const CMouse &m) {//ρ公 + ρ公
		//笆锣传Θ羬ンぃ璶厨岿惠璶р operator+(CMouse m) 柑把计эΘ 盽计まノconst Reference
		// ノまノ碞ぃノ狡籹Ωだōτ钡Μ羬ン
		return(_iw+m._iw);
	}
	//int operator+(int n){//ρ公 + 俱计
	//	return(_iw+n);
	//}
	CMouse(int w=100) {//篶じ:箇砞 w 碞琌 100
		_iw = w;
		cout << "CMouse 篶じ砆㊣" << endl;
	}
	CMouse(CMouse &m){//ī篶じ
		_iw = m._iw;
		cout << "CMouse copy篶じ砆㊣" << endl;
	}
	~CMouse() { cout << "CMouse 秆篶じ砆㊣" << endl; }//秆篶じ
	//CMouse() { _iw = 0; }
};
//class CMouse
//{
//private:
//	int _iw; // ρ公秖
//public:
//	int operator+(CMouse m) {//ρ公 + ρ公
//		return(_iw + m._iw);
//	}
//	int operator+(int n) {//ρ公 + 俱计
//		return(_iw + n);
//	}
//	CMouse(int w = 100) {//篶じ:箇砞 w 碞琌 100
//		_iw = w;
//		cout << "CMouse 篶じ砆㊣" << endl;
//	}
//	CMouse(const CMouse &m) {//ī篶じ
//		_iw = m._iw;
//		cout << "CMouse copy篶じ砆㊣" << endl;
//	}
//	~CMouse() { cout << "CMouse 秆篶じ砆㊣" << endl; }//秆篶じ
//	//CMouse() { _iw = 0; }
//};

int main()
{
	CMouse mx; 
	CMouse my(150);
	//CMouse my;
	cout << "ㄢ唉ρ公" << mx + 2 << endl;//mx+2穦笆ち传Θ mx+CMouse(2)
	cout << "ㄢ唉ρ公" << mx + my << endl;//ン+ン穦玻ネΩī篶じ㎝Ω秆篶じ
	system("pause");
}
#endif