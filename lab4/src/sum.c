#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

pthread_mutex_t mutex;

void sum(int*arr,int begin,int end,int *s)
{
    
    int n = end - begin;
    pthread_t threads[n];
    for(int i = begin; i < n; i++)
    {
        pthread_mutex_lock(&mutex);
        s[0] += arr[i];
        pthread_mutex_unlock(&mutex);
    }
    
}

void main()
{


}