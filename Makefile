all: connection.o
	gcc sqlboy.c connection.o -Wall `pkg-config --libs --cflags gtk+-2.0` `mysql_config --cflags --libs` -o sqlboy.bin
connection.o : connection.c connection.h
	gcc -c -Wall connection.c -lsqlite3 `mysql_config --cflags --libs`