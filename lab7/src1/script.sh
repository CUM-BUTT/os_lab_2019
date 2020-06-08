#!/bin/bash

git config credential.helper store
git add ./
git push
git commit -m "start lab6"

#cd cpp-hello-world/lab7/src1
#./parallel_fac.out --k "21" --pnum "3" --mod "6"
#chmod ugo+x script.sh 
#chmod ugo+x run.sh 
#git config credential.helper store
#./udpclient --port 20001 --bufsize 4 --ip 127.0.0.1
#./udpserver --port 20001 --bufsize 4