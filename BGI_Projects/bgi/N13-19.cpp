#include <iostream>
#include <cstdlib>
#define p19
#ifdef p
using namespace std;
int main(void)
{
	int i;
	try {
		for( i = 1; i <= 10 ; i++ ) {
			if( i == 6 )  throw "i = 6 發生了!!!";
		}
	}
	catch(const char *MsgStr) {
		cout << MsgStr << "例外產生了" << endl;
	}
	system("pause"); return(0);
}//可以用來查bug的工具
#endif