obj-m+=testchar.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
	$(CC) tester.c -o tester
rm:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
	rm tester
