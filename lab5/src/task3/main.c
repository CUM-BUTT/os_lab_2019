#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void do1();//lock mut3
void do2();//lock mut1
void do3();//lock mut2
int var1 = 5;
int var2 = 6;
int var3 = 7;
pthread_mutex_t mut1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mut2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mut3 = PTHREAD_MUTEX_INITIALIZER;

int main() {
  pthread_t thread1, thread2, thread3;

  if (pthread_create(&thread1, NULL, (void *)do1, NULL) != 0) {
    perror("pthread_create");
    exit(1);
  }

  if (pthread_create(&thread2, NULL, (void *)do2, NULL) != 0) {
    perror("pthread_create");
    exit(1);
  }

  if (pthread_create(&thread3, NULL, (void *)do3, NULL) != 0) {
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

  if (pthread_join(thread3, NULL) != 0) {
    perror("pthread_join");
    exit(1);
  }

  return 0;
}

void do1() {
    pthread_mutex_lock(&mut2);
    printf("thread 1, lock  mut2\n");
    sleep(2);   // чтобы второй поток успел залочить mut2
    pthread_mutex_lock(&mut3);
    
    pthread_mutex_unlock(&mut3);
	pthread_mutex_unlock(&mut2);
    printf("do1 finished\n");
}

void do2() {
    pthread_mutex_lock(&mut3);
    printf("thread 2, lock  mut3\n");
    sleep(1);   // чтобы второй поток успел залочить mut2
    pthread_mutex_lock(&mut1);
    
    pthread_mutex_unlock(&mut1);
	pthread_mutex_unlock(&mut3);
    printf("do2 finished\n");
}

void do3() {
    pthread_mutex_lock(&mut1);
    printf("thread 3, lock  mut1\n");
    pthread_mutex_lock(&mut2);
    
    pthread_mutex_unlock(&mut2);
	pthread_mutex_unlock(&mut1);
    printf("do3 finished\n");
}