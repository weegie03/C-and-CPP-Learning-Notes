//程式設計二，第二次上機考試，第6題（3分）
//宣告 CVec2 類別裡面包含
//私有包含（都是float型別）
//	向量的x y座標
//公有包含
//建構元：有兩個 f1oat型別的引數，引數的預設值都是1.0f
//也就是設定預設的向量內容為（1.0f,1.0f）
//三個運算子
//
//+ 運算子：也就 物件 + 物件，執行向量的相減，回傳值為CVec2 型別
//			就是(a, b)＋(c、d)的結果傳回内容（a + c、b + d）的物件
//* 運算子：也就 物件 * 物件，執行向量的內積，同傳值為 float型別
//			也就是(a,b) *(c,d)的結果是 傳同a* c + b * d
//～運算子：也就～物件,計算向量的長度・回博値為 float型別
//			也就是sqrt(a*a+b*b)，傳回這個計算的結果
//			N0TE:~運算子為一元運算子，(不需要引數)
//show函式：如題目所給，不用撰寫
//完成以下的釋式碼，並讓主程式能順利執行，同時輸出如下的結果
//v1 = (1, 1)
//V2 = (2, 4)
//v3 = (3, 5)
//|| v3 || = 5.83095

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#define p6
#ifdef p
using namespace std;
class CVec2
{
private:
	float x, y;
public:
	CVec2(float ix = 1.0f, float iy = 1.0f)
	{
		x = ix; y = iy;
	}
	//~CVec2();
	CVec2 operator+(const CVec2& m)//v1 + v2 時，編譯器其實呼叫 v1.operator+(v2)。
	{
		//左邊的物件(v1)：就是 this。
		//右邊的物件(v2)：作為參數傳入。
		//回傳值：相加後會產生一個新的向量，所以回傳型別是 CVec2。
		// 建立一個暫時的物件，內容是兩者相加
		return CVec2(this->x + m.x, this->y + m.y);
	}
	float operator*(const  CVec2& m)
	{
		//內積的結果是一個純量（數字），不是向量。
		// 回傳值：型別應為 float。
		return (this->x * m.x) + (this->y * m.y);
	}
	float operator~()//一元運算子不需要額外參數，因為它只對「自己」做運算
	{
		//回傳值：長度是一個數字，所以是 float
		return sqrt(x* x + y * y);
	}
	void show() {cout<< "(" << x << "," << y << ")" << endl;}

};

int main()
{
	CVec2 v1, v2(2, 4), v3;
	cout << "v1="; v1.show();
	cout << "v2="; v2.show();
	cout << "v1* v2 = " << v1 * v2 << endl;
	v3 = v1 + v2;
	cout << "v3="; v3.show();
	cout << "||v3||=" << ~v3 << endl;// ~為一元運算子，放在物件之前
	system("pause"); return(0);
}
#endif
//錯的地方:
//建構元：建構元裡面不能是空的，這樣 x 和 y 會是隨機的亂碼，一定要記得賦值。
//一元 vs 二元：
//如果是 A + B，函式括號內要放一個參數（代表 B）。
//如果是 ~A，函式括號內不放參數。
//回傳型別：這行算完後，應該得到一個座標（物件）還是一個數字（float）？
//this：物件的地址（指標）。
//* this：物件本人（解引用）。
//this->x：去 this 指向的那個地址，找到裡面叫做 x 的變數。