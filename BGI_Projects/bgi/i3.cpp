#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstdlib>
#include <iomanip>

#define p3
#ifdef p
using namespace std;
//以struct宣告tNode結構
struct tNode
{
	int n;
	struct tNode *link;
};
int main()
{
	tNode n1, n2, n3, n4;
	n1.n = 6;
	n2.n = 7;
	n3.n = 3;
	n4.n = 9;
	// 拿地址符號 & 取出下一間房子的地址，交給目前的 link
	n1.link = &n2;
	n2.link = &n3;
	n3.link = &n4;
	n4.link = NULL;
	tNode* temp = &n1;

	int i = 1;
	while (temp != NULL)//輸出linked list的內容
	{

		printf("第%d個node的內容是%d\n", i, temp->n);
		temp = temp->link;//走到下一間房子
		i++;
	}
	system("pause"); return(0);
}
#endif