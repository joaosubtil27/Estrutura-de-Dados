all: debug_compile debug_run

compile:
	gcc *.c -c
	gcc *.o main

debug_compile:
	gcc *.c -c -Wall -Wextra -Werror
	gcc *.o -o main

clean:
	rm *.o

debug_run:
	valgrind --leak.check=full ./main <in.txt >out.txt

run:
	./main <teste.txt

valgrind:
	valgrind ./main <teste.txt