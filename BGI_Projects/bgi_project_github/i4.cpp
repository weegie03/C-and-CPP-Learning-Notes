#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <cstdio>

#define p4
#ifdef p
using namespace std;
int main()
{
	int i;
	char cD[24] = "1A2B3C4D5E6F7G8H";//共16個字元，索引值從0到15
	char* pc;
	pc = cD;
	for (i = 0; i < 16; i+=2) printf("%c", pc[i]); printf("\n");
	for (i = 0; i <= 12; i+=4) printf("%s\n", &pc[i]); //%s 的運作邏輯是：從指標指向的第i個位置開始『往後』一路印到字串結尾的\0
	for (i = 0; i < 4; i++) printf("%c%c ", pc[15 -2* i], pc[2*i]);
	printf("\n");
	system("pause"); return(0);
}
#endif // p4
//第二個迴圈也可以這樣寫(等差數列的想法)
// i 代表字串長度，從 16 開始，每次減 4，直到 4
//for (i = 16; i >= 4; i -= 4) {
	// 16 - i 就會剛好是起點索引：
	// i = 16 時，16 - 16 = 0  --> 印出從索引 0 開始的字串
	// i = 12 時，16 - 12 = 4  --> 印出從索引 4 開始的字串
	// i = 8  時，16 - 8  = 8  --> 印出從索引 8 開始的字串
	// i = 4  時，16 - 4  = 12 --> 印出從索引 12 開始的字串
	//printf("%s\n", &pc[16 - i]);
//}