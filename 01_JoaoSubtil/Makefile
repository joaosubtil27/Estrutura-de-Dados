all: debug_compile clean debug_run

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
	./main