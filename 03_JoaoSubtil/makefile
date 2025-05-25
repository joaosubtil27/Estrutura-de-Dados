all: debug_compile valgrind

compile:
	gcc *.c -c
	gcc *.o main

debug_compile:
	gcc *.c -c -Wall -Wextra -Werror
	gcc *.o -o main

clean:
	rm *.o

run:
	./main <teste.txt

valgrind:
	valgrind --leak-check=full ./main <teste.txt