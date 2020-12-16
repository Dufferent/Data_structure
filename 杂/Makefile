PRO=algorithm
OBJ=algorithm.o
CC =gcc

$(PRO) : $(OBJ)
	$(CC) -o $@ $^

%.o : %.c
	$(CC) -o $@ -c $< -std=c99

clean:
	rm ./$(OBJ) ./$(PRO) -rf