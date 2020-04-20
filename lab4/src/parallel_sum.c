#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>
#include <pthread.h>
//-------------------
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <getopt.h>

struct SumArgs {
  int *array;
  int begin;
  int end;
};

pthread_mutex_t mutex;

int Sum(const struct SumArgs *args) {
  int sum = 0;
  // TODO: your code here 
    int n = args->end - args->begin;
    pthread_t threads[n];
    for(int i = args->begin; i < n; i++)
    {
        pthread_mutex_lock(&mutex);
        sum += args->array[i];
        pthread_mutex_unlock(&mutex);
    }
  return sum;
}

void *ThreadSum(void *args) {
  struct SumArgs *sum_args = (struct SumArgs *)args;
  return (void *)(size_t)Sum(sum_args);
}

int main(int argc, char **argv) {
    int seed = -1;
  int array_size = -1;
  int threads_num = -1;

  while (true) {
    int current_optind = optind ? optind : 1;

    static struct option options[] = {{"seed", required_argument, 0, 0},
                                      {"array_size", required_argument, 0, 0},
                                      {"thread_num", required_argument, 0, 0},
                                      {0, 0, 0, 0}};

    int option_index = 0;
    int c = getopt_long(argc, argv, "f", options, &option_index);

    if (c == -1) break;

    switch (c) {
      case 0:
        switch (option_index) {
          case 0:
            seed = atoi(optarg);
            // your code here
            if (seed <= 0) {
            printf("seed is a positive number\n");
            return 1;
            }
            // error handling
            break;
          case 1:
            array_size = atoi(optarg);
            // your code here
            if (array_size <= 0) {
            printf("array_size is a positive number\n");
            return 1;
            }
            // error handling
            break;
          case 2:
            threads_num = atoi(optarg);
            // your code here
            if (threads_num < 1) {
            printf("at least 1 parallel process should be started\n");
            return 1;
            }
            // error handling
            break;

          defalut:
            printf("Index %d is out of options\n", option_index);
        }
        break;

      case '?':
        break;

      default:
        printf("getopt returned character code 0%o?\n", c);
    }
  }

  if (optind < argc) {
    printf("Has at least one no option argument\n");
    return 1;
  }

  if (seed == -1 || array_size == -1 || threads_num == -1) {
    printf("Usage: %s --seed \"num\" --array_size \"num\" --pnum \"num\" \n",
           argv[0]);
    return 1;
  }

  if(threads_num > array_size)
  {
      threads_num = array_size;
  }

//   GenerateArray ниже




 

  /*
   * TODO:
   * your code here
   * Generate array here
   */


  pthread_t threads[threads_num];
  int *array = malloc(sizeof(int) * array_size);
  GenerateArray(array, array_size, seed);
  struct SumArgs args[threads_num];
  for (uint32_t i = 0; i < threads_num; i++) 
  {
    args[i].array = array;
    args[i].begin = array_size/threads_num*i;
    args[i].end = array_size/threads_num*(i+1);
    if (pthread_create(&threads[i], NULL, ThreadSum, (void *)&args[i])) {
      printf("Error: pthread_create failed!\n");
      return 1;
    }
  }

  int total_sum = 0;
 
  struct timeval start_time;
  gettimeofday(&start_time, NULL); //get time
  for (uint32_t i = 0; i < threads_num; i++) {
    int sum = 0;
    pthread_join(threads[i], (void **)&sum);
    total_sum += sum;
  }
  struct timeval finish_time;
  gettimeofday(&finish_time, NULL);

  double elapsed_time = (finish_time.tv_sec - start_time.tv_sec) * 1000.0;
  elapsed_time += (finish_time.tv_usec - start_time.tv_usec) / 1000.0;

  free(array);

  printf("Elapsed time: %fms\n", elapsed_time);
  printf("Total: %d\n", total_sum);
  return 0;
}
