CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS)
EXEC = hw13
OBJS = hw13.o expressionTree.o scanner.o tree.o
LIBS = expressionTree.h scanner.h tree.h
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): $(OBJS) $(LIBS)
	$(GCC) $(OBJS) -o $(EXEC)

all: test1 test2 test3 test4

test1: $(EXEC)
		./$(EXEC) ./inputs/test1 ./outputs/out1
test2: $(EXEC)
		./$(EXEC) ./inputs/test2 ./outputs/out2
test3: $(EXEC)
		./$(EXEC) ./inputs/test3 ./outputs/out3
test4: $(EXEC)
		./$(EXEC) ./inputs/test4 ./outputs/out4

memory: $(EXEC)
		$(VALGRIND) --log-file=log1 ./$(EXEC) ./inputs/test1 ./outputs/out1
		$(VALGRIND) --log-file=log2 ./$(EXEC) ./inputs/test2 ./outputs/out2
		$(VALGRIND) --log-file=log3 ./$(EXEC) ./inputs/test3 ./outputs/out3
		$(VALGRIND) --log-file=log4 ./$(EXEC) ./inputs/test4 ./outputs/out4


%.o : %.c
	$(GCC) -c $<

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f log?
