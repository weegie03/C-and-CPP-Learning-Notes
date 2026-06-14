#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p1
#ifdef p
using namespace std;
struct sCircle
{
	char name[12];
	int x, y, r, g, b, rad;
};
int main()
{

	initwindow(SCREENWIDTH, SCREENWIDTH, "程式設計2第一次上機第一題");
	// --- Part 1 ---
	printf("Part 1 .....\n");
	struct sCircle cc[10];
	//開啟檔案
	FILE* pfile;
	pfile = fopen("circles.txt", "r");
	if (pfile == NULL)
	{
		printf("circles.txt檔案無法開啟\n");
		system("pause"); return 0;
	}
	int count;
	fscanf(pfile, "%d", &count);//讀第一筆資料
	//第一筆資料是圓的個數
	for (int i = 0; i < count; i++)
	{
		fscanf(pfile, "%s %d %d %d", cc[i].name, &cc[i].x, &cc[i].y, &cc[i].rad);//不然要用這個寫法(cc + i)->name
		fscanf(pfile, "%d %d %d", &cc[i].r, &cc[i].g, &cc[i].b);
		setcolor(COLOR(cc[i].r, cc[i].g, cc[i].b));
		circle(X(cc[i].x), Y(cc[i].y), cc[i].rad);
		outtextxy(X(cc[i].x), Y(cc[i].y), cc[i].name);
	}
	fclose(pfile);
	// --- Part 2 ---
	printf("\nPart 2 .....\n");
	pfile = fopen("circles.txt", "r");
	int n[10] = { 0 };
	char ch;
	while (!feof(pfile))
	{
		ch = fgetc(pfile);
		if (ch >= '0' && ch <= '9')
		{
			n[ch - '0']++;
		}
	}
	fclose(pfile);
	for (int i = 0; i < 10; i++)
	{
		if (n[i] > 0 && n[i] % 2 == 0)
		{
			printf("%d 出現 %d 次\n", i, n[i]);
		}
	}
	while (!kbhit()) { delay(200); } return 0;
}


#endif