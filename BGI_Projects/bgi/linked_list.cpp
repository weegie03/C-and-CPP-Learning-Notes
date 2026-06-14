#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"


void draw_c(struct sCircle cc);

struct sCircle
{
	char name[10];
	int x, y;
	int cr, cg, cb;
	int radius;
};

struct tNode {
	int n;
	struct tNode* link;
};


int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "linked list");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	tNode* head=NULL, * tail = NULL, * get = NULL, *cur=NULL;
	int n = 4;

	head = (tNode*)malloc(sizeof(tNode));


	for (int i = 2; i <= 4; i++)
	{

	}

	cur = head;
	while ( cur != NULL )
	{
		printf("%d\n", cur->n);
		cur = cur->link;
	}

	printf("\nfree\n");



	while (!kbhit())
	{
		delay(200);
	}
	return 0;

}

void draw_c(struct sCircle cc)
{
	setcolor(COLOR(cc.cr, cc.cg, cc.cb));  // 設定顏色
	circle(X(cc.x), Y(cc.y), cc.radius);
}

//.x = rand() % 600 - 300;
//.y = rand() % 600 - 300;
//.radius = 50 + rand() % 50;
//.cr = rand() % 155 + 100;
//.cg = rand() % 155 + 100;
//.cb = rand() % 155 + 100;