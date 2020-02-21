all: dmxd dmxdummy dmxtest dmxcli

dmxd: dmxd.c
	gcc -o dmxd dmxd.c -lusb

dmxdummy: dmxdummy.c
	gcc -o dmxdummy dmxdummy.c -lusb

dmxtest: dmxtest.c
	gcc -o dmxtest dmxtest.c

dmxcli: dmxcli.c
	gcc -o dmxcli dmxcli.c

clean:
	rm -f *.o dmxtest dmxd dmxcli
