/* ************************************************************************
 *       Filename:  switchpage.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2018年12月01日 14时19分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
   int num;//页号
    int time;//等待时间
}Pro;

int pageNum;//系统分配给作业的主存中的页面数

int memoryNum;//可用内存页面数

void print(Pro *page1);//打印当前内存中的页面
int search(int num1,Pro *memory1);//在页面集memory1中查找num1,如果找到,返回其在memory1中的下标,否则返回-1
int max(Pro* memory1);
int optimal(int num,int tag,Pro* memory1,Pro* page1);


int main()
{
    int i;
    int curmemory;//调入内存的页面个数
    int missNum;//缺页次数
    float missRate;//缺页率
    char c;//得到用户的输入字符,来选则相应的置换算法

    Pro* page;//作业页面集
    Pro* memory;//内存页面集

    printf("输入系统分配给作业的主存中的页面数:");
    scanf("%d", &pageNum);
    printf("输入内存页面数:");
    scanf("%d", &memoryNum);

    page = (Pro*)malloc(sizeof(Pro)*pageNum);
    memory = (Pro*)malloc(sizeof(Pro)*memoryNum);

    for( i = 0 ; i < pageNum ; i ++ )
    {
        printf("第%d个页面号为:",i);
        scanf("%d",&page[i].num);
        page[i].time = 0;//等待时间开始默认为0
    }

    do
    {
        for( i = 0 ; i < pageNum ; i ++ )//初始化内存中的页面
        {
            memory[i].num = -1;
            memory[i].time = -1;
        }
        
        printf("*********f:FIFO页面置换算法***********\n");
        printf("*********o:OPT页面置换算法************\n");
        printf("*********l:LRU页面置换算法************\n");
        printf("*********请选择操作的类型(f,o,l),其他键位结束程序\n");

        getchar();
        scanf("%c", &c);

        i = 0;
        curmemory = 0;

        if( c == 'f' )
        {
            missNum = 0;

            printf("FIFO页面置换情况:   \n");
            for( i = 0 ; i < pageNum ; i ++ )
            {
                if( search(page[i].num, memory) < 0 )
                {
                    missNum ++;
                    memory[curmemory].num = page[i].num;
                    print(memory);
                    curmemory = (curmemory + 1) % memoryNum; //找出最先进入内存的页面
                }
            }
           missRate = (float)missNum / pageNum;
           printf("缺页次数:%d  缺页率:  %f\n",missNum, missRate);
        }

        if( c == 'o' )
        {
            missNum = 0;
            curmemory = 0;

            printf("Optimal页面置换情况:     \n");
            for( i = 0 ; i < pageNum ; i ++ )
            {
                if( search(page[i].num, memory) < 0){
                    int tem;
                    int opt = 0;
                    for( int k = 0 ; k < memoryNum ; k ++ )
                    {
                        if( memory[k].num == -1 )
                        {
                            curmemory = k;
                            break;
                        }
                        tem = 0;
                        int j;
                        for( j = i + 1 ; j < pageNum ; j ++ )
                        {
                            if( page[j].num == memory[k].num )
                            {
                                if( tem > opt )
                                {
                                    opt = tem;
                                    curmemory = k;
                                }
                                break;
                            }
                            else tem ++;
                        }
                        if( j == pageNum )
                        {
                            opt = tem;
                            curmemory = k;
                        }
                    }
                    missNum ++;
                    memory[curmemory].num = page[i].num;
                    print(memory);
                }
            }
            missRate = (float)missNum / pageNum;
            printf("缺页次数:   %d  缺页率:    %f\n",missNum, missRate);
        }

        if( c == 'l' )
        {
            missNum = 0;
            curmemory = 0;

            printf("LRU页面置换情况:    \n");

            for( i = 0 ; i < pageNum ; i ++ )
            {
                int rec = search(page[i].num,memory);
                if( rec < 0 )
                {
                    missNum++;
                    for( int j = 0 ; j < memoryNum ; j ++ )
                    {
                        if( memory[j].time == -1 )
                        {
                            curmemory = j;
                            break;
                        }
                        else if( memory[j].time > memory[curmemory].time )
                        {
                            curmemory = j;
                        }
                    }
                    memory[curmemory].num = page[i].num;
                    memory[curmemory].time = 0;
                    print(memory);
                }
                else memory[rec].time = 0;

                for( int j = 0 ; j < memoryNum ; j ++ )
                {
                    if( memory[j].num != -1 )
                    {
                        memory[j].time ++;
                    }
                }
                
            }
            missRate = (float)missNum / pageNum;
            printf("缺页次数: %d    缺页率:   %f\n",missNum, missRate);
        }

    }while(c == 'f' || c == 'l' || c == 'o');
    return 0;
    
}


void print(Pro* memory1)
{
    int j;

    for( j = 0 ; j < memoryNum ; j ++ )
    {
        printf("%d  ",memory1[j].num);
    }
    printf("\n");
}

int search(int num1, Pro* memory1)
{
    int j;

    for( j = 0 ; j < memoryNum ; j ++ )
    {
        if( num1 == memory1[j].num )
        {
            return j;
        }
    }
    return -1;
}

