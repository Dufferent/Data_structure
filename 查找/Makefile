PRO_NAME = demo
OBJ      = inspect.o demo.o
CC       = gcc
#CC      = arm-linux-gnueabihf-gcc

$(PRO_NAME) : $(OBJ)
	$(CC) -o $@ $^

%.o  :   %.c
	$(CC) -o $@ -c $<

clean:
	rm -rf ./*.o $(PRO_NAME) ./*.so

share:
	$(CC) -o inspect.o -c -fPIC inspect.c
	$(CC) -o demo.o -c -fPIC demo.c
	$(CC) -o libinspect.so -shared inspect.o
	$(CC) -o $(PRO_NAME) demo.o -linspect
  
