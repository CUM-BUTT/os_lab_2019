#!/bin/bash
./tcpserver.out --buf_size 100 --port 2001 --ip 127.0.0.1
./tcpclient.out --buf_size 100 --port 2000 --ip 127.0.0.1