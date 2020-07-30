PRO_NAME = demo
OBJ      = graph.o demo.o
CC       = gcc
#CC      = arm-linux-gnueabihf-gcc

$(PRO_NAME) : $(OBJ)
	$(CC) -o $@ $^

%.o  :   %.c
	$(CC) -o $@ -c $<

clean:
	rm -rf ./*.o $(PRO_NAME) ./*.so

share:
	$(CC) -o graph.o -c -fPIC graph.c
	$(CC) -o demo.o -c -fPIC demo.c
	$(CC) -o libgraph.so -shared graph.o
	$(CC) -o $(PRO_NAME) demo.o -lgraph
  
