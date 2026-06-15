#include <iostream>
#include <cstdlib>
using namespace std;
int main(void)
{
	int i;
	try {
		while( 1 ) {
			cin >> i;
			if( i > 6 ) throw "輸入超過  6 發生了!";
			else if( i == 5 ) throw i;
		}
	}
	catch(const char *MsgStr) {
		cout << MsgStr << "例外產生了" << endl;
	}
	catch(const int i) {
		cout << i << "的例外產生了" << endl;
	}
	system("pause"); return(0);
}