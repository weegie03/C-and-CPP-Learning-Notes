#include <iostream>
#include <cstdlib>
#include <iomanip>
#define p4
#ifdef p
#include <iostream>
#include <cstdlib>
using namespace std;
//void pc( )
//{
//	cout << ' ' << endl;//ま计箇砞
//}
void pc(char ch='$')
{
	cout << ch << endl;
}
void pc(int n, char ch)
{
	/*for (int i = 0; i <n; i++)
	{
		cout << ch;
	}*/
	cout.width(n);/*N */cout.fill(ch);//恶骸逞N-1
	cout << ch << endl;

}
//int main(void)
//{
//	pc();
//	pc('@');
//	pc(10, '#');
//	//ㄧ计嘿ぃず甧
//}
//int add(int, int);	// –更ㄧΑ常ㄧΑ
//float add(float, float);
//int main(void)
//{
//	int  ia = 1, ib = 2;
//	float fx = 1.3f, fy = 5.5f;
//	cout << ia << " + " << ib << " = " << add(ia, ib) << endl;
//	cout << fx << " + " << fy << " = " << add(fx, fy) << endl;
//
//	system("pause"); return(0);
//}
//int add(int i, int j)
//{	// 璹ㄧ计add()
//	return(i + j);	// 肚 i+j 
//}
//float add(float i, float j)
//{	// 璹ㄧ计add()
//	return(i + j);	// 肚 i+j 
//}

void showChar(char ch, int s = 1, int e = 16)
{
	if (s > 1) cout << setw(s - 1) << setfill(' ') << ' ';
	cout << setw(e - s + 1) << setfill(ch) << ch << endl;
}
int main(void)
{
	showChar('#');		// s 籔 e 常ㄏノ箇砞
	showChar('!', 2);	// e 常ㄏノ箇砞
	for (int i = 3; i <= 8; i++) showChar('*', i, 16 - i);
	system("pause"); return(0);
}

#endif