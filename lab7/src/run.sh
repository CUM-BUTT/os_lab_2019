#!/bin/bash
./tcpserver.out --buf_size 3 --port 3001 --ip 127.0.0.1
./tcpclient.out --buf_size 3 --port 3000 --ip 127.0.0.1