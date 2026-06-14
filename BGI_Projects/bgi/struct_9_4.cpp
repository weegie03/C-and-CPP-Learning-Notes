#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#define p4
#ifdef p
//#define DRAW_EXAMPLE

//void DrawCircles();
//#define ANIMATION

#define NUM 5
// 宣告結構變數，投影片範例 38 到 48

struct sCircle
{
	char name[10];
	int x, y;
	int cr, cg, cb;
	int radius;
};

void Draw_pv(struct sCircle cc);
void Draw_pp(struct sCircle *cc);//sCircle *cc=&p
void Draw_pary(struct sCircle cc[NUM]);

void gen_pp(struct sCircle* cc);

struct sNode
{
	int n;
	sCircle cc;
	struct sNode* link;//在結構體內 拿結構本身做一個型別來作為指標變數
};

int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "第九章投影片範例 39 到 48");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	//傳值傳遞
	struct sCircle c1 = { "abc",-100,200,200,150,250,50 };
	sCircle* pc;
	pc = &c1;
	pc->x = 100;
	(*pc).y = -200;
	pc = (sCircle*)malloc(sizeof(sCircle));
	*pc = c1;
	Draw_pv(c1);
	//更新內容
	sNode* head = NULL, * tail = NULL, * get = NULL;
	get = (sNode*)malloc(sizeof(sNode));//透過這個指令跟系統要這個空間來給這個節點
	get->n = rand() % 10 + 1;
	gen_pp(&(get->cc));//cc是一般的結構變數，get指向他的成員(cc)，&把左值傳過去

	get->link = NULL;
	head = get; tail = get;

	for ( i = 0; i <3; i++)
	{
		get = (sNode*)malloc(sizeof(sNode));//透過這個指令跟系統要這個空間來給這個節點
		get->n = rand() % 10 + 1;

		gen_pp(&(get->cc));//指向的成員變數把左值傳過來然後生成圓

		get->link = NULL;

		tail->link = get;//連結指向尾巴2
		tail = get;//指向最後一節車廂1

	}//生成三次的節點把它們串再一起

	struct sNode* cur;
	cur = head;

	struct sNode* nextNode;

	while (cur != NULL)
	{
		nextNode = cur->link;
		printf("%2d\n", cur->n);
		Draw_pv(cur->cc);
		cur = cur->link;
		//free(cur);            // 拆掉目前的節點
		//cur = nextNode;       // 搬到剛才記下來的下一站
	}
	cur = head;
	while (cur!=NULL)
	{
		printf("%2d\n", cur->n);
		Draw_pv(cur->cc);
		head = cur->link;
		free(cur);         
	}
	//head = NULL;
	// 
	//struct sNode n1, n2, n3, n4;//宣告四個節點
	//n1.n = 6;
	//gen_pp(&(n1.cc));
	///*n1.cc.x = rand() % 600 - 300;
	//n1.cc.y = rand() % 600 - 300;
	//n1.cc.radius = 50 + rand() % 50;
	//n1.cc.cr = rand() % 155 + 100;
	//n1.cc.cg = rand() % 155 + 100;
	//n1.cc.cb = rand() % 155 + 100;*/
	//
	//n1.link = &n2;//第二節的門牌號碼
	
	//n4.n = 5;
	//n4.link = NULL;//接地

	/*struct sNode* cur;
	cur = &n1;
	while (cur != NULL)
	{
		printf("%2d\n", cur->n);
		Draw_pv(cur->cc);
		cur = cur->link;
	}*/
	
	//// 傳值傳遞
	//struct sCircle c1 = { "abc",-100,200,200,150,250,50 };
	//sCircle* pc;
	//pc = &c1;
	//pc->x = 100;//間接存取運算子本來在-100
	//(*pc).y = -200;
	//pc=(struct sCircle*)malloc(sizeof(sCircle)*1);//*代表是指標變數的行為，或是*幾個	pc = (struct sCircle*
	//*pc = c1;
	//pc->y= 200;
	//Draw_pp(pc);//指標變數不打星號就是他自己本身存的右值
	//Draw_pv(c1);
	//free(pc);
	//// 更新內容
	//
	////printf("輸入名稱: "); scanf("%s");  // 輸入名稱
	////printf("X 與 Y 座標 : "); scanf("%d%d"); // 輸入 X/Y 座標
	////printf("半徑: "); scanf("%d"); // 輸入半徑

	//// 結構的成員是陣列
	//// 結構陣列 畫 5 個圓4
	////struct sCircle cf[5];//靜態記憶體配置
	//sCircle* cf = (struct sCircle*)malloc(sizeof(struct sCircle) * 5);//動態記憶體配置
	//for (i = 0; i < 5; i++)
	//{
	//	(cf+i)->x = rand() % 600 - 300;//改成指標的寫法
	//	(cf+i)->y = rand() % 600 - 300;
	//	(cf+i)->radius = 50 + rand() % 50;
	//	(cf+i)->cr = rand() % 155 + 100;
	//	(cf+i)->cg = rand() % 155 + 100;
	//	(cf+i)->cb = rand() % 155 + 100;
	//}

	//// 傳結構陣列
	//Draw_pary(cf);//呼叫端只要寫上陣列名稱就可以了
	//

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

void gen_pp(struct sCircle *cc)//sCircle cc=c1
{
	sprintf(cc->name, "%02d", rand() % 10 + 1);
	cc->x = rand() % 600 - 300;
	cc->y = rand() % 600 - 300;
	cc->radius = 50 + rand() % 50;
	cc->cr = rand() % 155 + 100;
	cc->cg = rand() % 155 + 100;
	cc->cb = rand() % 155 + 100;
}

void Draw_pv(struct sCircle cc)//sCircle cc=c1
{
	setcolor(COLOR(cc.cr, cc.cg, cc.cb));  // 設定顏色
	outtextxy(X(cc.x), Y(cc.y),cc.name);
	circle(X(cc.x), Y(cc.y), cc.radius);
}
void Draw_pp(struct sCircle *cc)//設成指標變數格是要全部改1.(* )2.換成->
{
	setcolor(COLOR(cc->cr, cc->cg, cc->cb));  // 設定顏色
	outtextxy(X((*cc).x), Y((*cc).y), (*cc).name);//間接存取運算子
	circle(X((*cc).x), Y((*cc).y), (*cc).radius);
}

void Draw_pary(struct sCircle cc[NUM])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		setcolor(COLOR(cc[i].cr, cc[i].cg, cc[i].cb));  // 設定顏色
		circle(X(cc[i].x), Y(cc[i].y), cc[i].radius);
	}
}


//----- template.cpp 繪圖程式碼保留區 -------------------
//setfillstyle(1, 2);		// 設定填滿樣式
//fillellipse(X(-300), Y(-300), 100, 100);	// 填滿一個橢圓，長短軸給一樣就是圓

//drawRect(0, 0, 500, 100); // 長方形，給中心點與邊長
//drawRectRot(-50, -50, 50, 40, 30.0f);  // 長方形，給中心點、邊長與旋轉角度

//drawTri(0, 0, 100);  // 正三角形，給中心點與邊長
//drawTriRot(100, 100, 100, -30.0f);   // 正三角形，給中心點與邊長與旋轉角度

//drawSquRot(-100, -200, 100, -45.0f);  // 正四方型，給中心點與邊長與角度

//settextstyle(0, HORIZ_DIR, 3); // 1 for 8x8   2 for 16x16 bitmap font
//outtextxy(100, 200, "數位科技設計");
//for (int i = -300; i < 300; i++)
//{
//	cleardevice();
//	drawRect(i, 0, 200, 100); // 長方形，給中心點與邊長
//    settextstyle(0, HORIZ_DIR, 2);
//	outtextxy(i+200, 200, "數位科技設計");
//	Sleep(5);
//	swapbuffers();
//}
//---------------------------------------

//printf("輸入名稱: "); scanf("%s", c1.name);  // 輸入名稱
//printf("X 與 Y 座標 : "); scanf("%d%d", &c1.x, &c1.y); // 輸入 X/Y 座標
//printf("顏色 rgb "); scanf("%d%d%d", &c1.cr, &c1.cg, &c1.cb); // 輸入數學成績
//printf("半徑: "); scanf("%d", &c1.radius); // 輸入數學成績



////------------ 讓 10 個圓形動起來 ----------------
//int i, j;
//int x[NUM], y[NUM], radius[NUM];
//int cr[NUM], cg[NUM], cb[NUM];
//float vx[NUM], vy[NUM];
//float tx, ty, t;
//for (i = 0; i < 10; i++)
//{
//	x[i] = rand() % 600 - 300;
//	y[i] = rand() % 600 - 300;
//	radius[i] = 10 + rand() % 30;
//	cr[i] = rand() % 155 + 100;
//	cg[i] = rand() % 155 + 100;
//	cb[i] = rand() % 155 + 100;
//	//setcolor(COLOR(cr[i], cg[i], cb[i]));  // 設定顏色
//	//circle(X(x[i]), Y(y[i]), radius[i]);
//	// 產生方向向量
//	tx = (rand() % 1000) / 1000.0f - 0.5f;
//	ty = (rand() % 1000) / 1000.0f - 0.5f;
//	t = sqrtf(tx*tx + ty*ty);
//	vx[i] = tx / t; vy[i] = ty / t; // 單位向量
//}
//
//for (j = 0; j < 3000; j++)
//{
//	cleardevice();
//	for (i = 0; i < NUM; i++)
//	{
//		// 變更圓心的位置，朝目前的方向前進
//		x[i] = (int)(x[i] + 2.5f * vx[i]);
//		y[i] = (int)(y[i] + 2.5f * vy[i]);
//		setcolor(COLOR(cr[i], cg[i], cb[i]));  // 設定顏色
//		circle(X(x[i]), Y(y[i]), radius[i]);
//
//		// 產生新的偏移方向
//		tx = (rand() % 1000) / 1000.0f - 0.5f;
//		ty = (rand() % 1000) / 1000.0f - 0.5f;
//		t = sqrtf(tx*tx + ty*ty);
//		vx[i] = 0.8f * vx[i] + 0.2f * (tx / t);
//		vy[i] = 0.8f * vy[i] + 0.2f * (ty / t);
//		t = sqrtf(vx[i] * vx[i] + vy[i] * vy[i]);
//		vx[i] = vx[i] / t; vy[i] = vy[i] / t;
//		// 重新計算圓朝的方向
//		Sleep(1);
//	}
//	swapbuffers();
//}
#endif