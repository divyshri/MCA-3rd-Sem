#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
pthread_t *producers;
pthread_t *consumers;

int *buff,p_count,c_count,buff_pos=-1,buff_len;
sem_t mutex,empty_count,full_count;


void *producer(void *args){
	int x=3;
	while(x--){
		int f;
		f=((int)args);
		int p = 1 + rand()%40;    //Genrate Random Number
		sem_wait(&empty_count);
		sem_wait(&mutex);
		buff_pos++;
		*(buff+buff_pos)=p;
		printf(" Producer %d produced: %d \n",f,p);
		sem_post(&mutex);
		sem_post(&full_count);
		sleep(3);
	}
	return NULL;
}

void *consumer(void *args){
	int x=3;
	while(x--)
	{
		int f;
		f=((int)args);
		sem_wait(&full_count);
		sem_wait(&mutex);
		printf("consumer %d consumes :  %d \n",f,*(buff+buff_pos));
		buff_pos--;
		sem_post(&mutex);
		sem_post(&empty_count);
		sleep(5);
	}
	return NULL;
}


int main()
{
	int i;
	sem_init(&mutex,0,1);
	sem_init(&full_count,0,0);

	printf("\nEnter the number of producer: ");
	scanf("%d",&p_count);

	producers=(pthread_t*)malloc(p_count*(sizeof(pthread_t)));
	printf("\nEnter the number of consumer: ");
	scanf("%d",&c_count);

	consumers=(pthread_t*)malloc(c_count*sizeof(pthread_t));
	printf("Enter buffer capacity:");
	scanf("%d",&buff_len);

	buff=(int*)malloc(buff_len*sizeof(int));

	sem_init(&empty_count,0,buff_len);

	for(i=0;i<p_count;i++){
		pthread_create(producers+i,NULL,producer,i+1);
	}
	for(i=0;i<c_count;i++){
		pthread_create(consumers+i,NULL,consumer,i+1);
	}
	for(i=0;i<p_count;i++){
		pthread_join(*(producers+i),NULL);
	}
	for(i=0;i<c_count;i++){
		pthread_join(*(consumers+i),NULL);
	}
	return 0;
}
