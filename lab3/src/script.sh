#!/bin/bash 

#cd cpp-hello-world/lab3/src
#gcc -std=c99 find_min_max.c sequential_min_max.c utils.c -o 1_task
gcc -std=c99 find_min_max.c parallel_min_max.c utils.c -o 3_task 
./3_task --seed "10" --array_size "10" --pnum "10"
./3_task --seed "10" --array_size "10" --pnum "10" --by_files "0"
./3_task --seed "10" --array_size "10" --pnum "10" -f
#./1_task 10 10

git add ./src
git push
CUM-BUTT
1809-1832i
git commit -m 3_task