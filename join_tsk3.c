#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

struct thread_arg1 {
	char * str;
	int num;
};

struct thread_arg2 {
	int min;
	int max;
	int num;
	int close;
};

void * func1(void * arg) {
	int i;
	struct thread_arg1 temp = *(struct thread_arg1 *) arg;
	for (i = 1; i <= temp.num; i++){
		printf("Child - %s - Iteration - %d.\n", temp.str, i);
		sleep(1);
	}
}

void * func2(void * arg) {
	int i,x;
	struct thread_arg2 temp = *(struct thread_arg2 *) arg;
	srand(time(NULL));
	for (i = 1; i <= temp.num; i++){
  		x = rand() % temp.max + 1;
  		if (x == temp.close){
  			printf("Error: %d\n", temp.close);
  			pthread_exit(NULL);
  		}
  		printf("%d -  %d\n",i, x);
  		sleep(1);
	}
}

int main(void) {
	pthread_t thread1, thread2;	

	struct thread_arg1 temp1;
	struct thread_arg2 temp2;
	
	temp1.str = "Hello World!";
	temp1.num = 10;
	
	temp2.num = 15;
	temp2.min = 1;
	temp2.max = 10;
	temp2.close = 5;

	if (pthread_create(&thread1, NULL, &func1, &temp1) != 0) {
		fprintf(stderr, "Error1\n");
		return 1;
	}
	
	if (pthread_create(&thread2, NULL, &func2, &temp2) != 0) {
		fprintf(stderr, "Error2\n");
		return 1;
	}
	
	if (pthread_join(thread1, NULL) != 0) {
		fprintf(stderr, "Error\n");
		return 1;		
	}

	if (pthread_join(thread2, NULL) != 0) {
		fprintf(stderr, "Error\n");
		return 1;		
	}
	printf("Finished...\n");
	return 0;
}