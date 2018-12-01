/* ************************************************************************
 *       Filename:  process.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2018年11月24日 10时49分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<bits/stdc++.h>

int main(int argc, char *argv[])
{
	int pid,ppid;
	int ret = fork();
	if( ret > 0 )
	{
		pid = getpid();
		ppid = getppid();
		printf("我是父进程,pid=%d,ppid=%d,我是新建的子进程:pid=%d\n",pid,ppid,ret);
		sleep(3);
	}
    
	else if( ret == 0 )
	{
		pid = getpid();
		ppid = getppid();
		printf("我是子进程:pid=%d,ppid=%d \n",pid,ppid);
	}
	else if( ret == -1 )
	{
		perror("fork");
	}
    

}


