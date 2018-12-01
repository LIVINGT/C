#include<iostream>
using namespace std;

/**
 * 残缺棋盘问题
 * 问题描述:
 * 在一个2^k * 2^k的棋盘中只有一个损坏的棋盘,要求用3方块将残缺棋盘填充满
 * 要求:
 * 填充过程中,三方块不能重叠,不能覆盖残缺的块 
 **/

int **board;//棋盘
int tile;//当前可用填充块


/**
 * 参数:
 * topRow:棋盘左上角行
 * topColumn:棋盘左上角列
 * defectColumn:残缺棋盘列
 * defectRow:残缺棋盘行
 * size:棋盘边长
**/
void TileBoard(int topRow,int topColumn,int defectRow,int defectColumn,int size)
{
    if (size < 2)
        return;

    int currentSize = size/2;
    int currentTile = tile ++;
    //残缺在左上角
    if(topRow < defectRow - currentSize && topColumn < defectColumn - currentSize)
    {
        board[topRow + currentSize - 1][topColumn + currentSize] = currentTile;
        board[topRow + currentSize][topColumn + currentSize - 1] = currentTile;
        board[topRow + currentSize][topColumn + currentSize] = currentTile;

        TileBoard(topRow,topColumn,defectRow,defectColumn,currentSize);//覆盖左上方
        TileBoard(topRow,topColumn + currentSize,defectRow + currentSize -1,defectColumn + currentSize,currentSize);//覆盖右上方
        TileBoard(topRow + currentSize,topColumn,topRow + currentSize,topColumn + currentSize - 1,currentSize);//覆盖左下
        TileBoard(topRow + currentSize,topColumn + currentSize,topRow + currentSize,topColumn + currentSize,currentSize);//覆盖右下

    }
    //残缺在右上角
    else if(topRow + currentSize > defectRow && topColumn + currentSize < defectColumn)
    {
        //代码类似
    }
    //残缺在左下角
    else if(topRow + currentSize < defectRow && topColumn + currentSize > defectColumn)
    {

    }
    //残缺在右下角
    else
    {

    }
    
}


int main(){

    return 0;
}