#!/bin/bash

git config credential.helper store
git add ./
git push
git commit -m "add lab4 new"

#cd cpp-hello-world/lab5/src
#./parallel_sum --seed "10" --array_size "10" --threads_num "6"
#chmod ugo+x script.sh 
#git config credential.helper store