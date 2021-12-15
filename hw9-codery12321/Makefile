CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS)
EXEC = hw9
OBJS =  maze.o path.o solver.o mazehelper.o
LIBS = $(OBJS:.o=.h)
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): hw9.o $(OBJS) $(LIBS)
	$(GCC) hw9.o $(OBJS) -o $(EXEC)

test: $(EXEC)
	mkdir outputs
	./$(EXEC) ./inputs/maze1 ./outputs/path1
	./$(EXEC) ./inputs/maze2 ./outputs/path2
	./$(EXEC) ./inputs/maze3 ./outputs/path3
	./$(EXEC) ./inputs/maze4 ./outputs/path4
	./$(EXEC) ./inputs/maze5 ./outputs/path5

memory: $(EXEC)
	mkdir outputs
	$(VALGRIND) --log-file=log1 ./$(EXEC) ./inputs/maze1 ./outputs/path1
	$(VALGRIND) --log-file=log2 ./$(EXEC) ./inputs/maze2 ./outputs/path2
	$(VALGRIND) --log-file=log3 ./$(EXEC) ./inputs/maze3 ./outputs/path3
	$(VALGRIND) --log-file=log4 ./$(EXEC) ./inputs/maze4 ./outputs/path4
	$(VALGRIND) --log-file=log5 ./$(EXEC) ./inputs/maze5 ./outputs/path5

%.o : %.c
	$(GCC) -c $<

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f log? 
	/bin/rm -r outputs
