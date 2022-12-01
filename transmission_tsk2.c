#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

struct thread_arg {
	char * name;
	char * str;
	int num;
};

void * any_func(void * arg) {
	int i;
	struct thread_arg temp = *(struct thread_arg *) arg;
	for (i = 1; i <= temp.num; i++){
		printf("Thread - %s -  %s - %d\n",temp.name, temp.str, i);
		sleep(1);
	}
	return NULL;
}

int main(void) {
	pthread_t thread1, thread2, thread3, thread4;
	
	struct thread_arg temp;
	struct thread_arg temp1;
	struct thread_arg temp2;
	struct thread_arg temp3;
	
	temp.name = "Thread1";
	temp.str = "Hello World";
	temp.num = 3;
	
	temp1.name = "Thread2";
	temp1.str = "Hello";
	temp1.num = 2;

	temp2.name = "Thread3";
	temp2.str = "World";
	temp2.num = 5;

	temp3.name = "Thread4";
	temp3.str = "H";
	temp3.num = 4;

	// if (pthread_create(&thread1, NULL, &any_func, &temp) != 0) {
	// 	fprintf(stderr, "Error (thread1)\n");
	// 	return 1;
	// }
	
	// if (pthread_create(&thread2, NULL, &any_func, &temp1) != 0) {
	// 	fprintf(stderr, "Error (thread2)\n");
	// 	return 1;
	// }
	
	// if (pthread_create(&thread3, NULL, &any_func, &temp2) != 0) {
	// 	fprintf(stderr, "Error (thread3)\n");
	// 	return 1;
	// }

	// if (pthread_create(&thread4, NULL, &any_func, &temp3) != 0) {
	// 	fprintf(stderr, "Error (thread4)\n");
	// 	return 1;
	// }
	
	sleep(5);
	return 0;
}
