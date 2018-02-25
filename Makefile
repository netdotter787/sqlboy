target:
	gcc sqlboy.c `mysql_config --cflags --libs` `pkg-config --libs --cflags gtk+-2.0` -o sqlboy.bin