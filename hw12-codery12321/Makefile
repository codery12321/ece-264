CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS)
EXEC = hw12
OBJS = hw12.o calc.o
LIBS = calc.h
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): $(OBJS) $(LIBS)
	$(GCC) $(OBJS) -o $(EXEC)

all: $(EXEC)

test: test1 test2 test3 test4 test5

test1: $(EXEC)
		./$(EXEC) ./inputs/test1
test2: $(EXEC)
		./$(EXEC) ./inputs/test2
test3: $(EXEC)
		./$(EXEC) ./inputs/test3
test4: $(EXEC)
		./$(EXEC) ./inputs/test4
test5: $(EXEC)
		./$(EXEC) ./inputs/test5
memory: $(EXEC)
		$(VALGRIND) --log-file=log1 ./$(EXEC) ./inputs/test1
		$(VALGRIND) --log-file=log2 ./$(EXEC) ./inputs/test2
		$(VALGRIND) --log-file=log3 ./$(EXEC) ./inputs/test3
		$(VALGRIND) --log-file=log4 ./$(EXEC) ./inputs/test4
		$(VALGRIND) --log-file=log5 ./$(EXEC) ./inputs/test5

%.o : %.c
	$(GCC) -c $<

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f log?
