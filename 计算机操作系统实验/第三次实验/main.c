/* ************************************************************************
 *       Filename:  1.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2018年11月24日 22时21分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define SIZE 11

typedef int QueueData;
typedef struct _queue //队列结构
{
	int data[SIZE];
	int front;
	int rear;
}Queue;

int init(Queue* q)
{
	if (q == NULL)
	{
		return FALSE;
	}
	q->rear = q->front;
	return TRUE;
}

int isEmpty(Queue* q)
{
	if (q == NULL)
	{
		return FALSE;
	}
	return q->front == q->rear;
}

int isFull(Queue* q)
{
	if (q == NULL)
	{
		return FALSE;
	}
	return q->front == (q->rear + 1) % SIZE;
}

int dequeue(Queue* q,int *x)
{
	if (q == NULL)
	{
		return FALSE;
	}

	if (isEmpty(q))	
	{
		return FALSE;
	}

	*x = q->data[q->front];
	q->front = (q->front + 1) % SIZE;
	return TRUE;
}

int enqueue(Queue* q,int x)
{
	if (q == NULL)
	{
		return FALSE;
	}

	if (isFull(q))
	{
		return FALSE;
	}

	q->data[q->rear] = x;
	q->rear = (q->rear + 1) % SIZE;
	return TRUE;
}


struct data //信号量结构体
{
    sem_t empty;
    sem_t full;
    Queue q;
};

pthread_mutex_t mutex;
int num = 0;
struct data sem;

void *Producer()
{
    while( 1 )
    {
        int time = rand() % 10 + 1;//随机睡眠
        usleep(time * 100000);

        sem_wait(&sem.empty); // 信号量的p操作
        pthread_mutex_lock(&mutex);//互斥锁上锁

        num ++;
        enqueue(&(sem.q),num); // 消息进队列
        printf("生产了一条消息:%d\n",num);

        pthread_mutex_unlock(&mutex);//互斥锁解锁
        sem_post(&sem.full);//信号量V的操作
    }
}

void *Consumer()
{
    while(1)
    {
        int time = rand() % 10 + 1;//随机睡眠0.几秒
        usleep(time * 100000);

        sem_wait(&sem.full);//信号量p操作
        pthread_mutex_lock(&mutex);//互斥锁上锁

        num --;
        dequeue(&(sem.q),&num);//消息出队列
        printf("消费了一条消息\n");

        pthread_mutex_unlock(&mutex);//互斥锁解锁
        sem_post(&sem.empty);//信号量v的操作

    }
}

int main(int argc, char const *argv[])
{
    srand((unsigned int) time(NULL));

    sem_init(&sem.empty,0,10);
    sem_init(&sem.full,0,0);

    pthread_mutex_init(&mutex,NULL);//互斥锁初始化

    init(&(sem.q));

    pthread_t producid;
    pthread_t consumid;

    pthread_create(&producid,NULL,Producer,NULL);
    pthread_create(&consumid,NULL,Consumer,NULL);

    pthread_join(consumid,NULL);

    sem_destroy(&sem.empty);
    sem_destroy(&sem.full);

    pthread_mutex_destroy(&mutex);
	return 0;
}
