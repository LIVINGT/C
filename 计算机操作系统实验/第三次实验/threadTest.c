/* ************************************************************************
 *       Filename:  threadTest.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2018年11月25日 10时54分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/

#include <stdio.h>
#include<pthread.h>
#include<stdlib.h>


void thread()
{
    int i;
    for( i = 0 ; i < 3 ; i ++ )
    {
        printf("this is a thread\n");
    }
    
}


int main()
{
    pthread_t id;
    int i,ret;
    ret = pthread_create(&id,NULL,(void*)thread,NULL);//成功返回0,错误返回编号
    if( ret!=0 )
    {
        printf("create pthread error!\n");
        exit(1);
    }

    for( i = 0 ; i < 3 ; i ++ )
    {
        printf("this is the main process!\n");
    }
   
    pthread_join(id,NULL);
    return 0;
}



