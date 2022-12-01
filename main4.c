#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int factorial (int n){
  return (n < 2) ? 1 : n * factorial (n - 1);
}

void * findNumber(void * arg) { 
	int size = *(int*) arg;
    int *a = (int*)malloc(size*sizeof(int));
   	int i;
   	for (i = 0; i < size; i++){
   		a[i] = factorial(2*i)/(factorial(i + 1)*factorial(i));
   	}
   	pthread_exit((void *) a);
}

void * findSimpleNumber(void * arg) {
	int size = *(int*) arg;
	int *a = (int*)malloc(size*sizeof(int));
	int i,s,j;

	for(i = 0; i < size; i++){
           a[i] = i;
    }
    a[1] = 0;
    for(s = 2; s < size; s++){
        if(a[s] != 0){
            for(j = s*2; j < size; j += s){
                a[j] = 0;
            }
        }
    }
    pthread_exit((void*) a);
}

int main(void) {
	pthread_t thread1, thread2;	
	int a = 7;
	int b = 100;
	int *x, *y;

	if (pthread_create(&thread1, NULL, &findNumber, &a) != 0) {
		fprintf(stderr, "Error (thread1)\n");
		return 1;
	}
	
	if (pthread_create(&thread2, NULL, &findSimpleNumber, &b) != 0) {
		fprintf(stderr, "Error (thread2)\n");
		return 1;
	}
		
	pthread_join(thread1, (void **)&x);
	pthread_join(thread2, (void **)&y);
	int i;
	printf("Числа Катлана: ");
	for(i = 0;i < a; i++){
		printf("%d ", x[i]);
	}
	printf("\nПростые числа: ");
	 for(i = 0; i < b; i++){
        if(y[i] != 0)
            printf("%d ", y[i]);
        }
	printf("\nAll threads finished...\n");
	free(x);
	free(y);
	return 0;
}
