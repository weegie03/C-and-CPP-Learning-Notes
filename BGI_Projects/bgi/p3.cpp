//  程式設計II，第三次上機考試 ，第 3 題 (4 分)
//
//  完成以下兩個類別的內容， 
//  CCharacter 類別
//     【被保護的(protected)】int 型別的成員變數 x/y 座標與顏色
//     公有的成員函式
//        建構元 : 有三個引數，x/y 座標與顏色，都必須用引數的預設值，分別是 0,0, COLOR_LIGHTGREEN
//		  解構元 ：使用已經給的輸出
//        draw() 函式 : 宣告成【純虛擬函式】
//  CMouse 類別公有繼承自 CCharacter 類別 
//        建構元 : 有三個引數，x/y 座標與顏色，都必須用引數的預設值，
//				   分別是 0,0, COLOR_LIGHTRED
//				   呼叫 CCharacter 的建構元時，將宣告物件時所傳入的引數值傳給 CCharacter 建構元
//        draw() 函式 : 直接使用給的呼叫內容，成員變數名稱自行修改
//		  解構元：使用已經給的輸出
//  CRabbit 類別公有繼承自 CCharacter 類別 
//        建構元 : 有三個引數，x/y 座標與顏色，都必須用引數的預設值，
//				   分別是 0,0, COLOR_YELLOW
//				   呼叫 CCharacter 的建構元時，將宣告物件時所傳入的引數值傳給 CCharacter 建構元
//        draw() 函式 : 直接使用給的呼叫內容，成員變數名稱自行修改
//		  解構元：使用已經給的輸出 
//
// 要求 : CCharacter 類別中的 draw() 函式必須宣告成【純虛擬函式】，才給分
// 
// 圖形與解構元的輸出必須與 p3.jpg 相符
//

#define P
#ifdef P3
#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

class Character {
protected:
	int x, y,color;
public:
	Character(int a = 0, int b = 0, int c = COLOR_LIGHTGREEN) :x(a), y(b), color(c) {};
	Character(unsigned char c) :x(0), y(0), color(c) {};
	virtual ~Character() { std::cout << "CCharacter 解構元被呼叫" << std::endl; }
	virtual void draw() = 0;
};

class Cmouse :public Character {
private:
public:
	Cmouse(int a = 0, int b = 0, int c = COLOR_LIGHTRED) :Character(a, b, c){};
	void draw() {
		drawSizeBox(x, y + 60, COLOR_WHITE, 30);   // 可自行修改成員變數
		drawBoxMan(x, y, color, COLOR_BLUE);		// 可自行修改成員變數
	}
	~Cmouse() {std::cout << "CMouse 解構元被呼叫" << std::endl;}
};

class CRabbit:public Character {
private:
public:
	CRabbit(int a=0, int b=0, int c= COLOR_YELLOW) :Character(a, b, c) {};
	void draw() {
		drawBoxMan(x, y, color, COLOR_BLUE);
	}
	~CRabbit() { std::cout << "CRabbit 解構元被呼叫" << std::endl; }
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, " P3 ");
	// 宣告 CCharacter 指標變數 c2m，並以 new 取得 CMouse 物件，初始值為  (150,0)
	Character* c2m = new Cmouse(150, 0);

	// 宣告 CCharacter 指標變數 c2r，並以 new 取得 CRabbit 物件，初始值為 (-150,0)
	Character* c2r = new CRabbit(-150, 0);

	// 宣告 CMouse 指標變數 m ，並以 new 取得 CMouse 物件，不用給初始值
	Cmouse* m = new  Cmouse;

	c2m->draw();			// c2m 呼叫 draw 函式
	c2r->draw();			// c2r 呼叫 draw 函式
	m->draw();				// m 呼叫 draw 函式
	delete c2m;				// 以 delete 釋放 c2m 所取得的資源
	delete c2r;				// 以 delete 釋放 c2r 所取得的資源
	delete m;				// 以 delete 釋放 m 所取得的資源
	while (!kbhit()) { delay(200); } return 0;
}

#endif