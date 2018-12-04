//Kaila Piscitelli
//December 1st
//CMSC 226
//threads

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void * Saver(int *id);
void * Spender(int *id);

int thread_id[2];
pthread_mutex_t lock;
int i=0;
int j=0;
double spent;
double save;
double account=0;

int main(){
	pthread_t thread[2];
	pthread_create(&thread[0], NULL, (void *)Spender, &thread_id[0]); /* create threads*/
	pthread_create(&thread[1], NULL, (void *)Saver, &thread_id[1]);
	
	for(int i=0; i<2; i++){
		pthread_join(thread[i], NULL);
		}

	printf("account balance: %f\n", spent+ save);
	printf("spent + saved: %f\n", spent + save);
	printf("spent: %f\n", spent);
	printf("saved: %f\n", save);
	}


void* Spender(int *id){
	time_t start= time(NULL);
	time_t end= start+5; //duration is 5 seconds
	//double account;
		while(time(NULL)<end){
			spent= (double)(rand() % 100);
			pthread_mutex_lock(&lock);
			if(account >0)
				account = account -1;
				spent= spent- 1;
		pthread_mutex_unlock(&lock);
		if (rand()%100 >= 50)
			sleep(rand()%2);
	}
	return 0;
}

void* Saver(int *id){
	time_t start= time(NULL);
	time_t end= start+5; //duration is 5 seconds
	//double account;
	while(time(NULL)<end){
		save= (double)(rand() %100); /*generate radnom number to save*/
		pthread_mutex_lock(&lock); /* lock the variable */
			account= account +1; 
			save= save +1;
		pthread_mutex_unlock(&lock);
		if (rand() %100 >= 50)
			sleep(rand()%2);
	}
	return 0;
}
