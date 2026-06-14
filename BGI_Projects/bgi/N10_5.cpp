#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

#define NUM 10

struct sCircle
{
	char name[12];
	int x, y;
	int r,g,b;
	int radius;
};

int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "Stuct Example");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	FILE *pfile;// 宣告指向檔案的結構指標
	if ((pfile = fopen("circles.txt", "r")) == NULL) {  // 判斷檔案是否開啟失敗
		printf("circles.txt 檔案無法開啟"); system("pause"); return(0);
	}

	struct sCircle cx[10];
	// 讀取 circles.txt 並劃出圓	
	for (i = 0; i < 10; i++)
	{
		fscanf(pfile, "%s %d %d %d", cx[i].name, &cx[i].x, &cx[i].y, &cx[i].radius);
		fscanf(pfile, "%d %d %d", &cx[i].r, &cx[i].g, &cx[i].b);
		setcolor(COLOR(cx[i].r, cx[i].g, cx[i].b));  // 設定顏色
		outtextxy(X(cx[i].x), Y(cx[i].y), cx[i].name);
		circle(X(cx[i].x), Y(cx[i].y), cx[i].radius);
	}//直接從檔案讀進來

	fclose(pfile);

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}
