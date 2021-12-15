CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
TESTS = -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE
GCC = gcc $(CFLAGS) $(TESTS)
EXEC = hw7
OBJS =  main.o shuffle.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): $(OBJS) shuffle.h
	$(GCC) $(OBJS) -o $(EXEC)

test: $(EXEC)
	./$(EXEC) 4 | sort | uniq > output4
	./$(EXEC) 8 | sort | uniq > output8
	./$(EXEC) 11 | sort | uniq > output11


check: $(EXEC)
	./$(EXEC) 4 | sort > output4
	./$(EXEC) 8 | sort > output8
	./$(EXEC) 11 | sort > output11
	diff -w output4 ./expected/expected4
	diff -w output8 ./expected/expected8
	diff -w output11 ./expected/expected11

memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) 4
	$(VALGRIND) --log-file=log2 ./$(EXEC) 8
	$(VALGRIND) --log-file=log3 ./$(EXEC) 11


%.o : %.c
	$(GCC) -c $<

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f log? output*
