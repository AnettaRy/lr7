#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

struct thread_arg1 {
	char * text;
	int numberber;
};

struct thread_arg2 {
	int minimum;
	int maximum;
	int number;
	int close;
};

void * func1(void * arg) {
	int i;
	struct thread_arg1 targ = *(struct thread_arg1 *) arg;
	for (i = 1; i <= targ.number; i++){
		printf("Child thread: %s Iteration %d.\n", targ.text, i);
		sleep(1);
	}
}

void * func2(void * arg) {
	int i,x;
	struct thread_arg2 targ = *(struct thread_arg2 *) arg;
	srand(time(NULL));
	for (i = 1; i <= targ.number; i++){
  		x = rand() % targ.maximum + 1;
  		if (x == targ.close){
  			printf("Invalid numberber: %d. Closing...\n", targ.close);
  			pthread_exit(NULL);
  		}
  		printf("%d.) numberber: %d\n",i, x);
  		sleep(1);
	}
}

int main(void) {
	pthread_t thread1, thread2;	

	struct thread_arg1 targ1;
	struct thread_arg2 targ2;
	
	targ1.text = "Hello World!";
	targ1.number = 10;
	
	targ2.number = 15;
	targ2.minimum = 1;
	targ2.maximum = 10;
	targ2.close = 5;

	if (pthread_create(&thread1, NULL, &func1, &targ1) != 0) {
		fprintf(stderr, "Error 1\n");
		return 1;
	}
	
	if (pthread_create(&thread2, NULL, &func2, &targ2) != 0) {
		fprintf(stderr, "Error 3\n");
		return 1;
	}
	
	if (pthread_join(thread1, NULL) != 0) {
		fprintf(stderr, "Join error\n");
		return 1;		
	}

	if (pthread_join(thread2, NULL) != 0) {
		fprintf(stderr, "Join error\n");
		return 1;		
	}
	printf("All threads finished...\n");
	return 0;
}