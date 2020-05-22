#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void do_something();
const int mut_count = 3;

typedef struct 
{
  pthread_t thread[mut_count]; 
  int var[mut_count];
  pthread_mutex_t mut[mut_count];

} fac_thread_t;

int main() {
  

  if (pthread_create(&thread1, NULL, (void *)do_one_thing, NULL) != 0) {
    perror("pthread_create");
    exit(1);
  }

  if (pthread_create(&thread2, NULL, (void *)do_another_thing, NULL) != 0) {
    perror("pthread_create");
    exit(1);
  }

  if (pthread_join(thread1, NULL) != 0) {
    perror("pthread_join");
    exit(1);
  }

  if (pthread_join(thread2, NULL) != 0) {
    perror("pthread_join");
    exit(1);
  }

  return 0;
}

 

void do_something() {
    int temp1;
    int temp2;
    pthread_mutex_lock(&mut2);
    printf("thread 2, getting var2\n");
    temp1 = var2;
    // sleep(1);
    pthread_mutex_lock(&mut1);
    temp2 = var1;
    printf("thread 2, getting var1\n");
    printf("thread 2: sum = %d\n", temp1 + temp2);
    pthread_mutex_unlock(&mut1);
	pthread_mutex_unlock(&mut2);
}