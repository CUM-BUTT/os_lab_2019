#include "find_min_max.h"

#include <stdio.h>
#include <unistd.h>

void main(){
   if (fork()==0) wait(0);
    else execl("sequential_min_max","sequential_min_max","10","10",NULL); /* порожденный процесс */
}
