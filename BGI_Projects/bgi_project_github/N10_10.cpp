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
	char name[10];
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
	if ((pfile = fopen("circles.txt", "w")) == NULL) {  // 判斷檔案是否開啟失敗
		printf("circles.txt 檔案無法開啟"); system("pause"); return(0);
	}

	struct sCircle cx[10];
	// 產生10個圓，並輸出	
	for (i = 0; i < 10; i++)
	{
		sprintf(cx[i].name, "%02d", i + 1);
		cx[i].x = rand() % 600 - 300;
		cx[i].y = rand() % 600 - 300;
		cx[i].radius = 40 + rand() % 40;
		cx[i].r = rand() % 155 + 100;
		cx[i].g = rand() % 155 + 100;
		cx[i].b = rand() % 155 + 100;
		setcolor(COLOR(cx[i].r, cx[i].g, cx[i].b));  // 設定顏色
		outtextxy(X(cx[i].x), Y(cx[i].y), cx[i].name);
		circle(X(cx[i].x), Y(cx[i].y), cx[i].radius);

		// 輸出圓的資料
		fprintf(pfile,"%s %d %d %d", cx[i].name, cx[i].x, cx[i].y, cx[i].radius);
		fprintf(pfile, " %d %d %d\n",cx[i].r, cx[i].g, cx[i].b);
	}
	fclose(pfile);



	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}
