PRO_NAME = demo
OBJ      = procession.o demo.o
CC       = gcc
#CC      = arm-linux-gnueabihf-gcc

$(PRO_NAME) : $(OBJ)
	$(CC) -o $@ $^

%.o  :   %.c
	$(CC) -o $@ -c $<

clean:
	rm -rf ./*.o $(PRO_NAME) ./*.so

share:
	$(CC) -o procession.o -c -fPIC procession.c
	$(CC) -o demo.o -c -fPIC demo.c
	$(CC) -o libprocession.so -shared procession.o
	$(CC) -o $(PRO_NAME) demo.o -lprocession
  
