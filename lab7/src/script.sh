#!/bin/bash

git config credential.helper store
git add ./
git push
git commit -m "start lab6"
make

#cd cpp-hello-world/lab7/src
#./parallel_fac.out --k "21" --pnum "3" --mod "6"
#chmod ugo+x script.sh 
#git config credential.helper store