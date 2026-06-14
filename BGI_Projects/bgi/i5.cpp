#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <cstdio>
//這題要重寫
#define p5
#ifdef p
using namespace std;
//三個pc函式
//你會用到width(),fill(),endl等cout的方法
void pc(int n)
{
	char old = cout.fill('*');
	//它把 cout 接下來的填滿字元改成 '*'（原本預設是空格）
	//同時，它會把「原本舊的填滿字元（也就是空格）」當作回傳值交出來
	//把原本的預設值（空格）先存到 old_fill 這個變數裡
	//你把畫筆沾上紅色（*）之前先拿個蓋子把原本的透明水（空格）裝起來，等一下畫完才能換回來。
	cout.width(n);
	//不論內容多短，都要給我留出n個字元的總寬度
	//**cout.width(n) 的特性：它只會對緊接著的下一次輸出有效，輸出完後寬度就會自動恢復成 0
	cout << "";
	//前一步規定寬度是 n，但我們卻只給它一個長度為 0 的空字串。
	// cout 發現格子不夠，就會啟動「填滿機制」，用我們剛剛設定的 '*' 把剩下的格子全部補滿
	cout.fill(old);
	//把 cout 的填滿字元改回原本的空格
	cout << endl;
}
void pc(int n, char ch)
{
	char old = cout.fill(ch);
	cout.width(n);
	cout <<"";
	cout.fill(old);
}
void pc(char ch,int s=1,int e=15)
{
	// 計算需要印出的字元數量
	int count = e - s + 1;

	char old = cout.fill(ch);
	cout.width(count);
	cout << ""<<endl;
	cout.fill(old);
}
int main()
{
	for (int i = 1; i <5; i++)
	{
		pc(8-i,' ');//呼叫pc 給2個引數
		pc(i*2-1);//呼叫pc給1個引數
	}
	pc('!');//此行不能修改
	//在編譯器眼裡等同於：pc('@', 1, 15);
	for (int i = 1; i < 5; i++)//此行不能修改
	{
		pc(3 + i,' ');

		// 呼叫 3 個引數的 pc。因為主程式傳入 i，對應到 ch (i會被轉成字元或數字)
		// 題目原本空著 `pc(i, );` 這裡補上參數：
		// 配合迴圈 i = 1~4，輸出對應的 1111111, 22222, 333, 4
		// 字元分別為 '0'+i，起點 s 隨 i 增加，終點 e 隨 i 減少
		//pc(4 - i, ' ');//呼叫pc 給2個引數
		pc('0' + i,0, 8-2* i);//呼叫pc給3個引數
	}
	system("pause"); return(0);
}
#endif