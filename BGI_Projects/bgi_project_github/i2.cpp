#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#define p2
#ifdef p

using namespace std;

struct tNode
{
	int n;
	struct tNode*link;
};
int main()
{
	printf("Part 1 .....\n");
	int n = 6;//節點個數設定為6
	//pHead指向第一個node，pTail指向最後一個node，pGet用以取得新的節點
	//先讓pHead pTail內容為NULL
	tNode* pHead = NULL, * pTail = NULL, * pGet = NULL;
	pHead = new tNode;//pHead以malloc或new取得空間
	pHead->n=1;
	pHead->link = NULL;//如果沒有把第一個節點的 link 設為 NULL，這時候 pHead->link 裡面裝的是記憶體裡的垃圾值
	//設定ptail的內容
	pTail = pHead;

	//以下為建立剩下n-1節點的內容
	for (int i = 2; i <= n; i++)
	{
		//設定目前取得節點的內容
		pGet = new tNode;
		pGet->n= i;
		pGet->link = NULL;//宣告這節新車廂目前是最後一節，它的後面沒有連接任何人
		pTail->link = pGet;
		pTail = pGet;
	}
	tNode* temp = pHead;
	int count = 1;
	while (temp!=NULL)
	{
		printf("第%d個node的內容%d\n", count,temp->n );
		temp = temp->link;//往前走一個
		count++;
	}
	
	printf("Part 2 .....\n");
	printf("釋放節點內容:");
	//釋放所有節點
	int i = 0;//i用來紀錄釋放的節點個數
	tNode *pc = pHead;
	while (pc!=NULL)
	{
		tNode* target = pc;
		printf("%3d", target->n);
		pc = pc->link;
		delete target;
		//釋放節點
		i++;
	}
	printf("\n共釋放了 %d 個 node\n",i );
	system("pause");
	return 0;
}
#endif