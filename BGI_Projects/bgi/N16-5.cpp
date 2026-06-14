#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p5
#ifdef p
using namespace std;

class CMonster
{
protected:
	int _ix, _iy;
public:
	CMonster(int x = 0, int y = 0) { _ix = x; _iy = y; }
	virtual ~CMonster() {cout << "CMonster 被釋放"<< endl;}
	virtual void attack() {
		cout << "普通攻擊！" << endl;
	}
	void setPos(int x, int y) { _ix = x; _iy=y; }
};
class CSlime:public CMonster
{
public:
	CSlime(int x=0, int y=0 ):CMonster(x, y) {};
	void attack() { cout << "史萊姆進行撞擊！" << endl; }
};
class CDragon :public CMonster
{
public:
	CDragon(int x=0, int y=0) :CMonster(x, y) {};
	void attack() { cout << "飛龍吐出烈火！" << endl; }
};
int main()
{
	int i;
	// 宣告一個可以容納 5 個 CMonster 指標的一維陣列
	CMonster* mon[5];
	cout << "--- 1. 個別單獨建立怪物 (零售小木屋) ---" << endl;
	mon[0] = new CMonster(0, 0);
	mon[1] = new CSlime(10, 10);
	mon[2] = new CDragon(20, 20);
	// 呼叫 0 到 2 的怪物集體發動攻擊
	for (int  i = 0; i < 3; i++)
	{
		mon[i]->attack();
	}
	cout << "\n--- 2. 動態配置物件陣列 (批發大樓) ---" << endl;
	// 在 pArmy[3] 位置，一口氣批發建立 2 隻連續的 CDragon
	mon[3] = new CDragon[2];



	// 讓這兩 2 隻陣列裡的飛龍排好位置並發動攻擊
		// 注意是用點還是箭頭？
	for (int i = 0; i < 2; i++)
	{
		mon[3][i].setPos(i * 150, -200);
		mon[3][i].attack();
	}
	cout << "\n--- 3. 集體清理記憶體 (拆除所有建築) ---" << endl;
	// 釋放 0 到 2 的單個物件空間
	for (int i = 0; i < 3; i++)
	{
		delete mon[i];
	}
	

	// 釋放 3 位置的飛龍物件陣列空間
	delete[] mon[3];

	cout << "\n--- 4. 程式安全結束 ---" << endl;
	system("pause"); return 0;
}
//class CCharacter {
//protected:
//	int  _ix, _iy, _icolor;;	// 座標與顏色
//public:
//	CCharacter(int ix=0, int iy=0, int icolor= COLOR_LIGHTGREEN) { _ix = ix; _iy = iy; _icolor = icolor; }
//	void setPos(int ix, int iy) { _ix = ix; _iy = iy; }
//	virtual void draw() { drawBoxMan(_ix, _iy, _icolor); }
//	virtual ~CCharacter(){cout<< "CCharacter被釋放" << endl;}
//};
//class CMouse : public CCharacter {
//public:
//	CMouse(int x=0, int y = 0, int color= COLOR_LIGHTRED) : CCharacter(x, y, color) {}
//	void draw() { 
//		drawSizeBox(_ix , _iy + 60, COLOR_WHITE, 30); // 頭髮
//		drawBoxMan(_ix, _iy, _icolor, COLOR_BLUE);
//	}
//};
//class CRabbit : public CCharacter {
//public:
//	CRabbit(int x = 0, int y = 0, int color = COLOR_YELLOW) : CCharacter(x, y, color) {  }
//	void draw() {
//		drawSizeBox(_ix - 24, _iy + 60, COLOR_LIGHTBLUE, 22); // 左耳朵
//		drawSizeBox(_ix + 24, _iy + 60, COLOR_LIGHTBLUE, 22); // 右耳朵	
//		drawBoxMan(_ix, _iy, _icolor, COLOR_RED, COLOR_LIGHTMAGENTA);
//	}
//};
//int main()
//{
//	int i;
//	initwindow(SCREENWIDTH, SCREENWIDTH, "N16-5 多型");
//	CCharacter* pChar[7];
//	pChar[0] = new CCharacter(-150, 50);
//	pChar[1] = new CMouse(0, 50);
//	pChar[2] = new CMouse(150, 50, COLOR_WHITE);
//	pChar[3] = new CRabbit(-150, -100);
//	pChar[4] = new CRabbit(0, -100, COLOR_LIGHTGREEN);
//	pChar[6] = new CRabbit(-150, -100, COLOR_BROWN);
//	for ( i = 0; i <5; i++)
//	{
//		pChar[i]->draw();
//	}
//	cout<< "\n--- 開始跑老師的批發兔子陣列 ---" << endl;
//	pChar[6] = new CRabbit[3];
//	for ( i = 0; i <3; i++)
//	{
//		pChar[6][i].setPos(i * 150 - 150, -200); // 讓三隻兔子排排站
//		pChar[6][i].draw(); // 畫出
//	}
//	for (i = 0; i < 5; i++) { delete pChar[i]; }
//	delete[] pChar[6];
//	/*for ( i = 0; i < 6; i++)
//	{
//		delete pChar[i];
//	}*/
//	
//	
//	
//	
//	
//	//CCharacter *pChar[7];
//	//pChar[0] = new CCharacter(-150, 50);  // 建立一般的角色
//	//pChar[1] = new CMouse(0, 50);
//	//pChar[2] = new CMouse(150, 50, COLOR_GREEN); // 老鼠
//	//pChar[3] = new CRabbit(-150, -100); //兔子
//	//pChar[4] = new CRabbit(0, -100, COLOR_LIGHTCYAN);
//	//pChar[5] = new CRabbit(150, -100, COLOR_BROWN);
//	//for (i = 0; i < 6; i++) pChar[i]->draw();
//	//for (i = 1; i < 6; i++) delete pChar[i]; // 釋放取得的物件空間
//
////	pChar[6] = new CRabbit[3];
////	for (i = 0; i < 3; i++) pChar[6][i].draw();
////	delete[] pChar[6];
//	
//	while (!kbhit()) { delay(200); } return 0;
//}
#endif

//--------------- link list -----------------
#ifdef LINK_LIST
struct tNode {
	int n;
	struct tNode* link;
};

tNode* head = NULL, * tail = NULL, * get = NULL, * cur = NULL;
int n = 4;

head = new tNode;
head->n = rand() % 9 + 1;
head->link = NULL;
tail = head;

for (int i = 2; i <= 4; i++)
{
	get = new tNode;
	get->n = rand() % 9 + 1;
	get->link = NULL;
	tail->link = get;
	tail = get;
}

cur = head;
while (cur != NULL)
{
	printf("%d\n", cur->n);
	cur = cur->link;
}

printf("\nfree\n");
while (head != NULL)
{
	cur = head;
	head = head->link;
	printf("%d\n", cur->n);
	free(cur);
}

#endif