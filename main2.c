#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

struct thread_arg {
	char * name;
	char *text;
	int number;
};

void * any_func(void * arg) {
	int i;
	struct thread_arg targ = *(struct thread_arg *) arg;
	for (i = 1; i <= targ.number; i++){
		printf("Thread # %s - name : %s  - number : %d\n", targ.name, targ.text, i);
		sleep(1);
	}
	return NULL;
}

int main(void) {

	pthread_t thread1, thread2, thread3, thread4;
	
	struct thread_arg targ;
	struct thread_arg targ1;
	struct thread_arg targ2;
	struct thread_arg targ3;
	
	targ.name = "Thread1";
	targ.text = "Hello Asia";
	targ.number = 5;
	
	targ1.name = "Thread2";
	targ1.text = "Hello Europe";
	targ1.number = 2;

	targ2.name = "Thread3";
	targ2.text = "Hello Amerika";
	targ2.number = 3;

	targ3.name = "Thread4";
	targ3.text = "Hello Afrika";
	targ3.number = 4;

	if (pthread_create(&thread1, NULL, &any_func, &targ) != 0) {
		fprintf(stderr, "Error (thread1)\n");
		return 1;
	}
	
	if (pthread_create(&thread2, NULL, &any_func, &targ1) != 0) {
		fprintf(stderr, "Error (thread2)\n");
		return 1;
	}
	
	if (pthread_create(&thread3, NULL, &any_func, &targ2) != 0) {
		fprintf(stderr, "Error (thread3)\n");
		return 1;
	}

	if (pthread_create(&thread4, NULL, &any_func, &targ3) != 0) {
		fprintf(stderr, "Error (thread4)\n");
		return 1;
	}
	
	sleep(5);
	return 0;
}
