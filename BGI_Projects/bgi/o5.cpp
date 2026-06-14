//程式設計二，第二次上機考試，第5題（3分）
//宣告 CCircle 類別
//私有包含（都是 float型別）
//座標_x,_y (宣告為 float型刺）與原點距離平方_d2
//公有包含 
//建構元：兩個引數x與y（宣告為float型別），引數預設值為3,3
// 設定座標內容，並計算圓心與原點距離平方放在_d2變數中
// 
//三個運算子
//三個＜運算子：分別執行 物件<物件，物件 < 數值 與數值 < 物件。
//	數值的型別都是 float，回傳值都是 bool
//	物件 < 物件:比較兩個圓與原點的距離
//  物件 < 數值:比較圓與原點的距離是否小於該數值
//  數值 < 物件:比較圓與原點的距離是大於該數值
//	getDist2()函式，回傳_d2 內容，回傳值型別為float
//  show函式:如題目所給，不用撰寫
//要求:
//  1.數值 < 物件 的運算子必須宣告成 CMouse 類別的{友誼函式}
//	2.私有與公有變數與函式必須依照題目需求放置，不能擅自改動
//	3.不能變更主程式的所有程式碼
//	完成以下的程式碼，並讓主程式能順利執行，同時輸出如下的結果
//	c1 與圓點距離一4.24264
//	c2.與圓點距離 = 5
//  c1 比c2 更靠近原點
//	c1 離原點距離大於3
//	c2 離原點距離大於4
// 
// 
//	c3 與圓點距離 = 2.82843
//	c4 與圓點距離 = 2.23607
//	c4 比c3 更靠近原點
//  c3 離原點距離小於 3
//	c4 離原點距離小於 4

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#define p5
#ifdef p
using namespace std;

class CCircle
{
private:
	float _x, _y, _d2;
public:
	CCircle(float x=3, float y=3)
	{
		_x = x; _y = y;
		_d2 = (_x * _x + _y * _y);
	}
	bool operator<(const CCircle& m)//物件 < 物件
	{
		/*_x = m._x; _y = m._y;//「賦值」，把對方的座標抄過來，會毀掉自己的資料
		m._x < m._x; m._y < m._y;//「無效運算」，自己比自己，且結果沒存起來
		*/
		/*return(*this);//*this 代表的是「物件本身」
			return(d2);*/
		return this->_d2 < m._d2; 
		//通常只有在 operator=（賦值運算子） 或需要「連鎖動作」（例如 c1 = c2 = c3）時，才會 return *this。
	}
	bool operator<(float a)//物件 <常數
	{//如果是寫在類別裡面的「成員函式」，引數（參數）只能寫一個。
		//成員函式預設了「左手邊那個人」就是物件自己（由 this 代表）。
		//左邊那個人被「隱藏」在類別內部
		// 距離是否小於 a -> 距離平方是否小於 a*a
		return sqrtf(_d2) < a;
	}
	
	float getDist()const { return(_d2); }
	void show() { cout << sqrtf(_d2) << endl; }
	friend bool operator<(float a, const CCircle& m)//常數<物件
	{//因為 float 不是類別
		//獨立函式：既然它不屬於 CCircle 物件，就沒有隱藏的 this，所以它必須清楚交代兩個人是誰
		return sqrtf(m._d2) > a;//類別裡宣告它為「友誼函式」，它就有特權去拿 m._d2 來用。
	}
};

int main()
{
	CCircle cl, c2(-4.0f, 3.0f);
	cout << "c1 與圓點距離 ="; cl.show();
	cout << "c2 與圓點距離 ="; c2.show();
	if (cl < c2)cout << "c1 比 c2 更靠近原點" << endl;
	else cout << "c2 比cl 更靠近原點" << endl;

	if (cl < 3)cout << "cl 離原點距離小於 3" << endl;
	else cout << "cl 離原點距離大於3" << endl;
	if (4 < c2) cout << "c2 離原點距離大於 4" << endl;
	else  cout << "c2 離原點距離小於 4" << endl;
	cout << "\n\n";
	CCircle c3(2.0f, 2.0f), c4(1.0f, 2.0f);
	cout << "c3 與圓點距離="; c3.show();
	cout << "c4 與圓點距離="; c4.show();
	if (c3 < c4) cout << "c3 比t c4 更靠近原點" << endl;
	else cout << "c4 比 c3 更靠近原點" << endl;
	if (c3 < 3) cout << "c3 離原點距離小於3" << endl;
	else cout << "c3 離原點距離大於3" << endl;
	
	if (4 < c4) cout << "c4 離原點距離大於4" << endl;
	else cout << "c4 離原點距離小於 4" << endl;
	system("pause"); return(0);
}
#endif
//錯的地方
//運算子是bool的型別 *this 代表的是「物件本身」
//通常只有在 operator=（賦值運算子） 或需要「連鎖動作」（例如 c1 = c2 = c3）時，才會 return *this。和做復值的動作
//*this 代表的是「物件本身」
//如果是寫在類別裡面的「成員函式」，引數（參數）只能寫一個。
//成員函式預設了「左手邊那個人」就是物件自己（由 this 代表）。
//左邊那個人被「隱藏」在類別內部
//friend是獨立函式：既然它不屬於 CCircle 物件，就沒有隱藏的 this，所以它必須清楚交代兩個人是誰
//因為 float 不是類別
//return sqrtf(m._d2) > a;//類別裡宣告它為「友誼函式」，它就有特權去拿 m._d2 來用。(not _d2)