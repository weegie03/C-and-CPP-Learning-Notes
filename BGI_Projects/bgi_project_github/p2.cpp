//  程式設計II，第三次上機考試 ，第 2 題 (3 + 2 分)
//
// 子類別的建構元呼叫父類別的建構元
// 子類別拷貝建構元呼叫父類別的拷貝建構元
//
//  完成以下兩個類別的內容， 
//  CCharacter 類別
//     【被保護的(protected)】成員變數 x/y 座標(int 型別)，與顏色 (【unsigned char】 型別)
//     公有的成員函式
//        三個引數建構元 : x/y 座標與顏色，都必須用引數的預設值，分別是 0,0, COLOR_WHITE
//						   記得設定變數的內容
//        一個引數建構元 : 一個引數，設定顏色，【不要】設定預設值， x/y 座標設定為 0，
//						   顏色為傳入的引數值
//		  拷貝建構元 
//        draw() 函式 : 呼叫 drawBoxMan()函式，給座標跟顏色
//        setPos()函式 : 兩個引數，設定 x/y 座標
//  CMouse 類別公有繼承自 CCharacter 類別 
//     私有的成員變數儲存【攻擊力】，int 型別
//     公有的成員函式
//        四個引數的建構元 : 引數分別為 x/y 座標、顏色(型別是【unsigned char】)與攻擊力，
//							 其中 x/y 座標與顏色，不能給引數預設值，攻擊力必須給預設值 10
//							 指定呼叫 CCharacter 類別中有【三個引數的建構元】
//        兩個引數建構元 : 引數分別為顏色(型別是【unsigned char】)與攻擊力，
//                 其中顏色不給引數預設值，攻擊力給預設值 10
//                 指定呼叫 CCharacter 類別【一個引數的建構元】，傳入內容為顏色
// // 
//		  拷貝建構元 : 【指定呼叫】 CCharacter 的拷貝建構元
//		  showAttack() 函式：(已經給了)
//
//   讓主程式能正常執行，並顯示如圖 p2.jpg 的結果
//	 Part 1. 完成上半部 3 分(子類別對父類別建構元的呼叫)
//	 Part 2. 完成下半部 2 分(子類別對父類別拷貝建構元的呼叫)
//

#define P
#ifdef P2
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

using namespace std;
class Character {
protected:
	int x, y;
	unsigned char color;
public:
	Character(int a=0, int b=0, unsigned char c= COLOR_WHITE) :x(a), y(b), color(c) {};
	Character(unsigned char c) :x(0), y(0), color(c) {};
	Character(const Character& c) {
		this->x = c.x; this->y = c.y; this->color = c.color;
	}
	void draw() { drawBoxMan(x, y, color); }
	void setPos(int a, int b) { x = a; y = b; }
};

class Cmouse :public Character {
private:
	int atk;
public:
	Cmouse(int a, int b, unsigned char c, int d = 10) :Character(a, b, c), atk(d) {};
	Cmouse(unsigned char c, int d = 10) :Character(c), atk(d) {};
	Cmouse(const Character& e) :Character(e) {
	};
	void showAttack() {
		char str[80];
		sprintf(str, "攻擊力=%2d", atk);  // 空格填上所宣告的攻擊力的變數名稱
		settextstyle(3, 0, 24);
		setcolor(COLOR_WHITE);
		outtextxy(X(x + 80), Y(y), str);
	}

};


int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, " P2 ");
	// ------------- Part 1  -------------
	Cmouse m1(0, 100, 14);
	Cmouse m2(12, 30);
	m1.draw(); m1.showAttack();
	m2.draw(); m2.showAttack();

	// ------------- Part 2  -------------
	Cmouse m3(m1);
	Cmouse m4(m2);
	m3.setPos(0,-300); m3.draw(); m3.showAttack();
	m4.setPos(0,-200); m4.draw(); m4.showAttack();

	while (!kbhit()) { delay(200); } return 0;
}

#endif