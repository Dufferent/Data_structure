PRO_NAME = demo
OBJ      = order_list.o demo.o
CC       = gcc
#CC      = arm-linux-gnueabihf-gcc

$(PRO_NAME) : $(OBJ)
	$(CC) -o $@ $^

%.o  :   %.c
	$(CC) -o $@ -c $<

clean:
	rm -rf ./*.o $(PRO_NAME) ./*.so

share:
	$(CC) -o order_list.o -c -fPIC order_list.c
	$(CC) -o demo.o -c -fPIC demo.c
	$(CC) -o liborder_list.so -shared order_list.o
	$(CC) -o $(PRO_NAME) demo.o -lorder_list
  
