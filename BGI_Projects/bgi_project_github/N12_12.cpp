#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED

#define X_MAX 200	// 定義可活動的範圍
#define Y_MAX 200	// 定義可活動的範圍
using namespace std;

class CMouse {
public:
	CMouse() { x = 1; y = 1; cout << "CMouse 建構元被呼叫" << endl; }
	~CMouse();
private:
	int x, y;		// 老鼠的起始位置
};
CMouse::~CMouse() {
	cout << "~CMouse 解構元被呼叫" << endl;
	system("pause"); // 讓程式暫停,可看到訊息
}
void TestFunc() {
	cout << "m2 物件變數建立前" << endl;
	CMouse m2;
	cout << "m2 物件變數建立後" << endl;
}
int main(void) {
	TestFunc();
	cout << "m1 物件變數建立前" << endl;
	CMouse mouse1;
	cout << "m1 物件變數建立後" << endl;
	TestFunc();
	return(0);
}

