CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS)
EXEC = hw11
OBJS  = hw11.o maze.o mazehelper.o solver.o list.o
LIBS = maze.h mazehelper.h solver.h list.h
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC) : $(OBJS) $(LIBS)
	$(GCC) $(OBJS) -o $(EXEC)

test: test1 test2 test3

test1: $(EXEC)
		./$(EXEC) ./inputs/maze1 ./outputs/path1

test2: $(EXEC)
	./$(EXEC) ./inputs/maze2 ./outputs/path2

test3: $(EXEC)
	./$(EXEC) ./inputs/maze3 ./outputs/path3

memory: $(EXEC)
	$(VALGRIND) -- log-file=log1 ./$(EXEC) ./inputs/maze1 ./outputs/path1
	$(VALGRIND) -- log-file=log2 ./$(EXEC) ./inputs/maze2 ./outputs/path2
	$(VALGRIND) -- log-file=log3 ./$(EXEC) ./inputs/maze3 ./outputs/path3

%.o : %.c
	$(GCC) -c $<

checkoutput: $(EXEC)
		./$(EXEC) ./inputs/maze1 ./outputs/path1
		./$(EXEC) ./inputs/maze2 ./outputs/path2
		./$(EXEC) ./inputs/maze3 ./outputs/path3

		diff ./outputs/path1 ./expected/path_out1
		diff ./outputs/path2 ./expected/path_out2
		diff ./outputs/path3 ./expected/path_out3


clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f log?
	/bin/rm -f ./outputs/path?
