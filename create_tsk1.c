#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void * any_func(void * args) {
	int i;
	for (i = 1; i < 11; i++){
		printf("Child - Iteration: %d\n", i);
		sleep(2);
	} 
	return NULL;
}

int main(void) {
	pthread_t thread;
	int result, i;
	result = pthread_create(&thread, NULL, &any_func, NULL);
	for (i = 1; i < 11; i++){
		printf("Main - Iteration: %d\n", i);
		sleep(2);
	}
	return 0;
}
