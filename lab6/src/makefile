
all: client server

dbg: client-dbg server-dbg

client-dbg: client.c libnetfac
	gcc -std=c99 -o client-dbg.out client.c -I./libnetfac -L./ -lpthread -lm -lnetfac -g -O0

server-dbg: server.c libnetfac
	gcc -std=c99  -o server-dbg.out  server.c -I./libnetfac -L./ -lpthread -lm -lnetfac -g -O0

client: client.c libnetfac
	gcc -std=c99  -o client.out client.c -I./libnetfac -L./ -lpthread -lm -lnetfac

server: server.c libnetfac
	gcc -std=c99  -o server.out server.c -I./libnetfac -L./ -lpthread -lm -lnetfac

libnetfac: ./libnetfac/netfac.c
	gcc -std=c99  -o ./libnetfac/libnetfac.o -c ./libnetfac/netfac.c -I./libnetfac
	ar rcs ./libnetfac.a ./libnetfac/libnetfac.o

clean:
	rm -r *.o *.a *.out -f
