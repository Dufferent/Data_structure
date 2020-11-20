ProName = demo
CC  = gcc
OBJ = demo.o circle_queue.o

$(ProName) : $(OBJ)
	gcc -o $@ $^

%.o : %.c
	gcc -o $@ -c $<

clean:
	rm ./*.o $(ProName) -f