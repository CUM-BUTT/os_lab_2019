#!/bin/bash
./tcpserver.out --buf_size 3 --port 3000 --ip 127.0.0.1
./tcpclient.out --buf_size 3 --port 1000 --ip 153.0.0.1