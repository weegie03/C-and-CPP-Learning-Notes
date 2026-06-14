//  程式設計二，第三次上機考試，第 1 題 (2 + 2 分)
// 
// 宣告 CVec2 類別裡面包含
//   私有包含(都是 float 型別)
//       向量的 x y 座標
//   公有包含
//       建構元：有兩個 float 型別的引數，引數的預設值都是 1.0f         
//               也就是設定預設的向量內容為 (1.0f, 1.0f)
//		 拷貝建構元 : 必須包含所給的"拷貝建構元被呼叫"的輸出部分
// 
//       三個運算子
//       +運算子 ：也就 物件+物件，執行向量的相減，回傳值為 CVec2 型別
//				   也就是 (a,b)+(c,d)的結果是 傳回內容是 (a+c, b+d) 的物件
//       *運算子 ：也就 物件*物件，執行向量的內積，回傳值為 float 型別
//				   也就是 (a,b)*(c,d)的結果是 傳回 a*c+b*d
//       =運算子 : 物件1 = 物件2，將物件2的內容給予物件1 
//         
//		show 函式 : 如題目所給，不用撰寫 
// 
//   完成以下的程式碼，並讓主程式能順利執行，part 1 與 part 2 各別都是 2 分
//   給分要求
//	 1. 輸出結果包含 拷貝建構元被呼叫 是否出現都必須一致
//      也就是 part1 不能看到拷貝建構元被呼叫, part2 開頭一定要有
//	 2. 拷貝建構元被呼叫 這些文字的輸出必須放在拷貝建構元中
//	 
//------ - Part 1 -------- -
//  v1 = (1, 1)
//  v2 = (2, 4)
//  v1 * v2 = 6
//  v3 = (3, 5)
//------ - Part 2 -------- -
//  拷貝建構元被呼叫
//  v4 = v2 = (2, 4)
//  v1 = v2 = v3 = (3, 5)

#define P
#ifdef P1

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

// CVec2 類別
class CVec2
{
private:
	float x, y;
public:
	CVec2(float ix = 1.0f, float iy = 1.0f) :x(ix), y(iy) {};
	CVec2(const CVec2& v) { x = v.x; y = v.y; cout << "拷貝建構元被呼叫" << endl; }
	float operator*(CVec2& v)
	{
		return (this->x * v.x + this->y * v.y);
	}
	CVec2 operator+(CVec2& v)
	{
		return CVec2(this->x + v.x, this->y + v.y);
	}
	CVec2& operator=(CVec2& v)
	{
		return CVec2(this->x = v.x,this->y = v.y);
	}
	void show() { cout << "(" << x << "," << y << ") " << endl; }
};
//都是傳一個物件進來喔


//class CVec2 {
//private:
//	float x, y;
//public:
//	CVec2(float a =1.0f, float b = 1.0f):x(a),y(b) {};
//	CVec2(CVec2& vec) {
//		cout << "拷貝建構元被呼叫" << endl;
//		this->x = vec.x;
//		this->y = vec.y;
//	};
//	CVec2 operator+(const CVec2& vec) {
//		CVec2 temp;
//		temp.x =this->x + vec.x;
//		temp.y =this->y + vec.y;
//		return temp;
//	};
//	float operator*(const CVec2& vec) {
//		return this->x * vec.x + this->y * vec.y;
//	};
//	CVec2& operator=(const CVec2& vec) {
//		this->x = vec.x;
//		this->y = vec.y;
//		return (*this);
//	};
//	void show() { cout << "(" << x << "," << y << ") " << endl; }
//};
int main(void)
{
	cout << "------- Part 1 ---------" << endl;
	CVec2 v1, v2(2,4), v3;
	cout << "v1 = "; v1.show();
	cout << "v2 = "; v2.show();
	cout << "v1 * v2 = " << v1 * v2 << endl;
	cout << "v3 = "; v3.show();
	
	cout << "------- Part 2 ---------" << endl;
	CVec2 v4(v2);
	cout << "v4 = v2 ="; v4.show();
	v1 = v2 = v3;
	cout << "v1 = v2 = v3 ="; v1.show();
	system("pause"); return(0);
}

#endif