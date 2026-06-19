//  程式設計II，第三次上機考試 ，第 7 題 (5 分)
// 
//  功能要求：畫面上四個象限中間與圓點(0,0)個有一個顏色方塊， BoxMan 預設出現在圓點(0,0)
//            以'w'、's'、'a'、'd' 四個鍵來控制 BoxMan 移動
//            BoxMan 臉的顏色則依照距離其最近的彩色方塊而變化
//            控制 BoxMan 往上，然後往左走到第二象限的顏色點、
//            然後往下、往右、再往上，再往左，最後回到原點，讓 BoxMan 的臉隨著要求改變顏色
//   
//   CCBox 類別：負責畫面上固定的顏色方塊
//    私有成員變數： int 型別 _x, _y, _color
//    公有成員函式：
//      建構元 : 三個 int 型別的引數，x/y 座標與顏色，皆有預設值
//      draw 函式 : 無引數，呼叫 drawColorBox 畫出色塊
//      getPos 函式 : 兩個 int 型別的傳入【參照或指標】參數，傳回 _x 與 _y
//      getColor 函式 : 無引數，回傳 color
//      setPos 函式 : 兩個 int 型別的引數，設定座標
//      setColor 函式 : 一個 int 型別的引數，設定顏色
// 
//  CCBoxMgr 類別：負責管理多個 CCBox（共 5 個，）
//    私有成員變數：
//      int 型別 _boxCount (CBox 的個數)
//      CCBox * 型別的指標變數 _pboxes
//    公有成員函式：
//      建構元 : 初始化 _boxCount，並配置 5 個固定位置與顏色的 CCBox
//      解構元 : 正確釋放 _pboxes 所取得的陣列空間
//      drawAllBoxes 函式 : 無引數，畫出所有 CCBox 繪製自己
//      getBox 函式 : 一個 int 型別的引數，傳回對應索引的 CCBox 參考
//      getBoxCount 函式 : 無引數，傳回 _boxCount 整數值
// 
//  CBoxMan 類別：可移動的 BoxMan，其顏色由距離最近的 CCBox 決定
//    私有成員變數： int 型別 _x, _y，int 型別 _faceColor， BoxMan 臉部顏色
//    公有成員函式：
//      建構元 : 
//          兩個 int 型別的引數，x/y 座標，皆有預設值 0,0，
//          _faceColor 則直接設定成 COLOR_WHITE    
//      update 函式 : 
//          一個 char 型別的引數，處理鍵盤 w/s/a/d 移動指令
//          更新 boxman 位置, 並重新設定臉部顏色
//      draw 函式 : 繪製 BoxMan
// 
//	輸出結果：參考 p7.exe
//

#define P7
#ifdef P7
#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
//CCBox 類別函式
//draw()畫色塊、getPos()傳回位址(傳指標)、getColor()傳回顏色、setPos()設定座標、setColor()設定顏色
//CCBox類別
class CCbox {
private:
    int x, y, color;//私有成員變數x、y、color
public:
    CCbox(int a, int b ,int c) :x(a), y(b), color(c) {};//建構元:三個int型別的引數、x/y座標與顏色預設值0,0,COLOR_WHITE
    void draw() {drawColorBox(x,y,color);}//draw無引數，呼叫drawColorBox畫出色塊
    void getPos(int& a, int& b) { a = x; b = y; }//getPos:兩個int型別傳入(參照或指標)參數，傳回x,y
    int getColor() { return color; }//getColor無引數回傳color
    //setPos函式:兩個int型別的引數，設定座標
    //setColor函式:一個int型別的引數，設定顏色
};
//  CCBoxMgr 類別函式
//    私有成員變數： int 型別 _boxCount (CBox 的個數)、 CCBox * 型別的指標變數 _pboxes
//    公有成員函式：
//      建構元 : 初始化 _boxCount，並配置 5 個固定位置與顏色的 CCBox
//                設定_boxCount內容為5
//                以new取得_boxCount個數的CCBox物件，並設定個別CCBox的初始值
{
    { 0, 0, COLOR_LIGHTRED },
    { 200,200,COLOR_LIGHTGREEN },
    { -200,200,COLOR_LIGHTBLUE },
    { -200,-200,COLOR_YELLOW },
    { 200,-200,COLOR_LIGHTCYAN },
};
//      解構元 : 正確釋放 _pboxes 所取得的陣列空間
//      drawAllBoxes 函式 : 無引數，畫出所有 CCBox 繪製自己
//      getBox 函式 : 一個 int 型別的引數，傳回對應索引的 CCBox 參考
//      getBoxCount 函式 : 無引數，傳回 _boxCount 整數值
};

//以CCBoxMgr宣告一個全域物件，讓CBoxMan可以在類別成員函式內使用
//  CBoxMan 類別：
//    私有成員變數： int 型別 _x, _y，int 型別 _faceColor， BoxMan 臉部顏色
//    公有成員函式：
//      建構元 : 
//          兩個 int 型別的引數，x/y 座標，皆有預設值 0,0，
//          _faceColor 則直接設定成 COLOR_WHITE    
//      update 函式 : 
//          一個 char 型別的引數，處理鍵盤 w/s/a/d 移動指令
//          更新 boxman 位置, 並重新設定臉部顏色
      switch (cIn) {
        case 'w': // 往上
            y += 20;			// Y 往上 20	
            break;
        case 's': // 往下
            y -= 20;			// Y 往下 20
            break;
        case 'a': // 往左
            x -= 20;			// X 往左 20
            break;
        case 'd': // 往右
            x += 20;			// X 往右 20
            break;
        }
        //更新_faceColor:計算與所有color box距離
//      draw 函式 : 繪製 BoxMan
      void draw() { drawBoxMan(x, y, c); }//單純畫出BoxMan 顏色使用_faceColor

int main(void)
{
    initwindow(SCREENWIDTH, SCREENWIDTH, "P7");
    char cIn
    int i = 0;
                          // BoxMan 初始再畫面中心
    while (i < 100) {
        cleardevice();
        //由CCBoxMgr全域物件畫出所有color box
        //畫BoxMan
        swapbuffers();
        cIn = getch();
        //呼叫BoxMan的update
        rewind(stdin);

        i++;

    }
    cleardevice();
    swapbuffers();
    while (!kbhit()) { delay(200); } return 0;
}

#endif