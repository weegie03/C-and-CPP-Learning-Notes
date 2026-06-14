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
void drawFence();

class CMouse
{
private:
	int x, y;
public:
	CMouse();
};

CMouse::CMouse()
{
	x = 1; y = 1;
	cout << "x = " << x << ", y = " << y << endl;
}


int main()
{
	cout << "mx 物件變數建立前" << endl;
	CMouse mx;
	cout << "mx 物件變數建立後" << endl;
	system("pause"); return(0);
}

void drawFence()
{
	for (int i = -200; i <= 200; i += 20) {
		drawColorBox(i, 200, COLOR_LIGHTGREEN);
		drawColorBox(i, -200, COLOR_LIGHTGREEN);
	}
	for (int i = -180; i <= 180; i += 20) {
		drawColorBox(-200, i, COLOR_LIGHTGREEN);
		drawColorBox(200, i, COLOR_LIGHTGREEN);
	}
}