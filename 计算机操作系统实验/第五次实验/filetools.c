/* ************************************************************************
 *       Filename:  filetools.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2018年12月01日 15时30分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include<string.h>
#include<unistd.h>

void help()
{
    printf("***************文件系统********************\n");
    printf("**************0:退出**********************\n");
    printf("**************1:创建新的文件**************\n");
    printf("**************2:写文件*******************\n");
    printf("**************3:读文件*******************\n");
    printf("**************4:复制文件*****************\n");
    printf("**************5:修改文件权限*****************\n");
    printf("**************6:查看文件权限*****************\n");
    printf("**************7:创建子文件目录*****************\n");
    printf("**************8:删除子目录*****************\n");
    printf("**************9:改变当前目录到指定目录********\n");
    printf("**************10:链接操作*****************\n");
}

//创建件文件
int create()
{
    char file[100];
    
    printf("请输入新文件的路径(path+filename):\n");
    //gets(file);
    scanf("%s",file);
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;  
    int fd = creat(file,mode);
    if( fd > 0 )
    {
        printf("创建文件完成\n");
    }
    return fd;
}

//写文件
int writein()
{
    printf("请输入要写入的文件(没有则创建):\n");
    char file[100];
    scanf("%s",file);
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
    printf("已有文件是否覆盖?(0,1)");
    int c;
    scanf("%d",&c);
    int oflag;
    if (c == 0)
        
         oflag = O_RDWR | O_APPEND | O_EXCL | O_CREAT | O_SYNC;
    else oflag = O_RDWR | O_EXCL | O_CREAT | O_SYNC;
    fd = open(file,oflag,mode);
    if(fd < 0){
        printf("文件不可打开\n");
        return -1;
    }
    printf("请输入要写入的文件内容:\n");
    char buf[1000];
    size_t nbytes;
    ssize_t bytes_written;


    char content[1000];
    getchar();
    gets(content);
    strcpy(buf,content);
    nbytes = strlen(buf);

    bytes_written = write(fd,buf,nbytes);
    if( bytes_written > 0 )
    {
        printf("写入完成\n");
    }
    close(fd);
    return 1;
}


//读文件

int read_()
{
    printf("请输入查看的文件路径:\n");
    char file[100];
    getchar();
    gets(file);
    int oflag = O_RDONLY;
    int fd = open(file,oflag);
    if(fd < 0)
    {
        printf("打开文件失败\n");
        return -1;
    }
    char buf[10];
    int nbytes = sizeof(buf);
    int num = 0;
    while(1)
    {
        num = read(fd,buf,nbytes);
        if(num <= 0)
            break;
        write(STDOUT_FILENO,buf,num);
        printf("\n");
    }

    close(fd);
    return 1;
    
}

int copy_()
{
    printf("请输入源文件:\n");
    char srcfile[100];
    getchar();
    gets(srcfile);
    printf("请输入目标文件:\n");
    char dstfile[100];
    gets(dstfile);

    int fdsrc;
    int fddst;

    fdsrc = open(srcfile,O_RDONLY);
    if(fdsrc < 0)
    {
        printf("文件不可读\n");
        return -1;
    }
    int oflag = O_RDWR | O_EXCL | O_CREAT | O_SYNC;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
    fddst = open(dstfile,oflag,mode);
    if(fddst < 0)
    {
        printf("文件不可写\n");
        return -1;
    }
    
    char buf[10];

    int num;
    int nbytes = sizeof(buf);
    while(1)
    {
        num = read(fdsrc,buf,nbytes);
        if(num < 0){
            printf("文件读取失败\n");
            break;
        }
        if(num == 0)
        {
            printf("文件复制完成\n");
            break;
        }
        write(fddst,buf, num);
    }

    close(fddst);
    close(fdsrc);
    return 1;

}

//修改文件权限
int chmod_()
{
    printf("请输入修改权限文件:\n");
    char file[100];
    getchar();
    gets(file);
    printf("请输入权限代码:\n");
    int mode;
    scanf("%d",&mode);
    int s = chmod(file, mode);
    if(s < 0)
    {
        printf("权限修改失败\n");
        return -1;
    }
    printf("权限修改完成\n");
    return 1;
}

//查看文件权限
int look()
{
    printf("请输入需要查看的文件:\n");
    char file[100];
    getchar();
    gets(file);
    struct stat buf;
    memset(&buf, 0, sizeof(buf));
    int s = stat(file,&buf);
    if(s < 0)
    {
        printf("获取文件属性失败\n");
        return -1;
    }
    printf("st_ino = %d\n",buf.st_ino);
	printf("st_size = %d\n",buf.st_size);
	printf("st_blksize = %d\n",buf.st_blksize);
	printf("st_blocks = %d\n",buf.st_blocks);
    printf("st_mode = %d\n",buf.st_mode);
    return 1;
}
//创建目录
int mkdir_()
{
    printf("请输入目录路径:\n");
    char menu[100];
    getchar();
    gets(menu);
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
    int s = mkdir(menu,mode);
    if(s < 0)
    {
        printf("创建目录失败\n");
        return -1;
    }
    printf("创建目录成功\n");
    return 1;
}

//删除目录
int rmdir_()
{
    printf("请输入目录:\n");
    char menu[100];
    getchar();
    gets(menu);
    int s = rmdir(menu);
    if(s < 0)
    {
        printf("删除目录失败\n");
        return -1;
    }
    printf("删除目录成功\n");
    return 1;
}
//改变当前目录到指定目录
int chdir_()
{
    printf("请输入目的目录:\n");
    char menu[100];
    getchar();
    gets(menu);
    int s = chdir(menu);

    if(s < 0)
    {
        printf("改变目录失败\n");
        return -1;
    }
    printf("改变目录成功\n");
    return 1;
}

//链接文件
int link_()
{
    printf("源文件或者文件夹路径:\n");
    char srcfile[100];
    getchar();
    gets(srcfile);
    printf("目的文件或者文件夹路径:\n");
    char dstfile[100];
    getchar();
    gets(dstfile);

    int s = link(srcfile,dstfile);
    
    if(s < 0)
    {
        printf("链接操作失败\n");
        return -1;
    }
    printf("链接操作完成\n");
    return 1;
}
int main()
{
    int o = 0;
    while(1)
    {

        help();
        char dir[80];
        getcwd(dir,sizeof(dir));

        printf("当前目录:%s \n" , dir);
        scanf("%d",&o);
        switch ( o )
        {
        case 0 :
            exit(0);

            break;
        case 1 :
            create();
            break;
        case 2:
            writein();
            break;
        case 3:
            read_();
            break;
        case 4:
            copy_();
            break;
        case 5:
            chmod_();
            break;
        case 6:
            look();
            break;
        case 7:
            mkdir_();
            break;
        case 8:
            rmdir_();
            break;
        case 9:
            chdir_();
            break;
        case 10:
            link_();
            break;
        default :
            break;
        }
    }
    return 0;
}



