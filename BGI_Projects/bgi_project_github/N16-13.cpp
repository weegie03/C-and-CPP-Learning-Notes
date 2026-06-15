#include <stdio.h>
#include <stdlib.h>

typedef struct tNode {
	int num;	// 改這裡
	struct tNode *link;
} NODE, *PNODE;

int main(void)
{
	int i, num, in;
	PNODE pHead, pTail, pGet;	// 宣告所需要的結構指標變數
	pHead = pTail = NULL;		// 讓指標變數內容為NULL
	printf("請輸入需要幾個 node : "); scanf("%d",&num);
	if( (pHead = (PNODE) malloc(sizeof(NODE))) == NULL  ) { // 取的第一個 node
		printf("記憶體不足\n"); exit(0);
	}
	printf("請輸入第1 個node 的內容: "); scanf("%d",&in);
	pHead->num = in; // 改這裡
	pHead->Link = NULL; // 設定 Head 節點的內容
	pTail = pHead;

	//-------------------------------------------------------------
	pGet = (PNODE)malloc(sizeof(NODE));
	pGet->num = in; // 改這裡
	pGet->Link = NULL;	// 設定目前取得節點的內容
	pTail->Link = pGet; 
	pTail = pGet;	// 建立節點間的鏈結

	//-------------------------------------------------------------

	pGet = pHead; i = 1;
	while( pGet != NULL ) { // 輸出 link list 的內容
		// pGet->... 改這裡
		pGet = pGet->Link; i++;
	}
	system("pause"); return(0);
}