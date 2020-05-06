#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex,writeblock;		//Semaphores Global Variable Defined in <semaphore.h>
int data = 0,read_count = 0;	

void *reader(void *arg){
	int c=0;
	while(c<3){
		c++;
		int f;
		f = ((int)arg);
		sem_wait(&mutex);
		read_count = read_count + 1;
		if(read_count==1){
			sem_wait(&writeblock);
		}
		sem_post(&mutex);
		printf("Data read by the reader%d is %d\n",f,data);
		sleep(1);
		sem_wait(&mutex);
		read_count = read_count - 1;
		if(read_count==0){
			sem_post(&writeblock);
		}
		sem_post(&mutex);
	}
}
void *writer(void *arg){
	int c=0;
	while(c<3){
		c++;
		int f;
		f = ((int) arg);
		sem_wait(&writeblock);
		data++;
		printf("Data writen by the writer%d is %d\n",f,data);
		sleep(1);
		sem_post(&writeblock);
	}
}

int main()
{
	int i,b; 
	pthread_t rtid[5],wtid[5];
	sem_init(&mutex,0,1);   	//int sem_init(sem_t *sem, int pshared, unsigned int value); for mutex
	sem_init(&writeblock,0,1);	//int sem_init(sem_t *sem, int pshared, unsigned int value); for Write Block
	for(i=0;i<=5;i++){
		pthread_create(&wtid[i],NULL,writer,(void *)i);
			//pthread_create(pthread_t *thread,pthread_attr_t *attr,void *(*start_routine), void *arg);
			//Thread Creation for Write Operation
		pthread_create(&rtid[i],NULL,reader,(void *)i);
`			//pthread_create(pthread_t *thread,pthread_attr_t *attr,void *(*start_routine), void *arg);
			//Thread Creation for Read Operation
	}
	for(i=0;i<=5;i++){
		pthread_join(wtid[i],NULL);
			//pthread_join(pthread_t thread, void **retval); 
			//If retval is not NULL, then pthread_join() copies the exit status of the target thread.
			// Join with a terminated thread
		pthread_join(rtid[i],NULL);
	}
return 0;
}
