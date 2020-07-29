PRO_NAME = demo
OBJ      = chains_list.o demo.o
CC       = gcc
#CC      = arm-linux-gnueabihf-gcc

$(PRO_NAME) : $(OBJ)
	$(CC) -o $@ $^

%.o  :   %.c
	$(CC) -o $@ -c $<

clean:
	rm -rf ./*.o $(PRO_NAME) ./*.so

share:
	$(CC) -o chains_list.o -c -fPIC chains_list.c
	$(CC) -o demo.o -c -fPIC demo.c
	$(CC) -o libchains_list.so -shared chains_list.o
	$(CC) -o $(PRO_NAME) demo.o -lchains_list
  
