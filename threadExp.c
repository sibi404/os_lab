#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

sem_t s;

void *fun(void *p){
	sem_wait(&s);
	printf("%i thread entered\n",*(int*)p);
	for (int i = 0; i < 5; i++){
		printf("%i Inside fun\n",*(int*)p);
		sleep(.10);
	}

	printf("%i thread exiting\n",*(int*)p);
	sem_post(&s);
}

void *fun2(){
	for (int i = 0; i < 5; i++){
		printf("Inside fun2\n");
		sleep(1);
	}
}


int main(){
	sem_init(&s,0,2);
	int first = 1,second = 2,third = 3;
	pthread_t id1,id2,id3;
	pthread_create(&id1,NULL,fun,&first);
	pthread_create(&id2,NULL,fun,&second);
	pthread_create(&id3,NULL,fun,&third);
	// sleep(1);
	pthread_exit(&id1);
	pthread_exit(&id2);
	pthread_exit(&id3);
	return 0;
}