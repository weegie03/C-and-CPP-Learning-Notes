//#include <iostream>
//#include <cstdlib>
//using namespace std;
//int& min(int& a, int& b)//區域變數是不能被傳回來的
//{
//	if (a > b) return b;
//	else return a;
//}
//int main(void)
//{
//	int i = 10, j = 20;
//	cout << "Before min(i,j) = 50 ";
//	cout << "i = " << i << ", j = " << j << endl;
//	min(i, j) = 50;	// 將 min() 傳回的參照(變數)設定成 50
//    //動作: 呼叫min(i,j) 對應到a,b 傳回a =i 所以i=50;
//	cout << "After  min(i,j) = 50 ";
//	cout << "i = " << i << ", j = " << j << endl;
//	i = min(i, j);	// 將變數 i 設定成 min() 函式傳回的參照內容
//	cout << "After  i = min(i,j)  ";
//	cout << "i = " << i << ", j = " << j << endl;
//	system("pause"); return(0);
//}

//#include <iostream>
//#include <cstdlib>
//using namespace std;
//char* getString(char* cText) { // 為傳入的字串取得空間，並傳回
//	char* pch;
//	pch = new char[strlen(cText) + 1];
//	strcpy(pch, cText);
//	return pch;
//}
//int main(void)
//{
//	char* pch;
//	pch = getString("new & delete");
//	cout << "pch = " << pch << endl;
//	delete[] pch;  // 釋放取得的空間
//	system("pause"); return(0);
//}
