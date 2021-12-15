CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS)
LIBS = -lm
EXEC = hw3

testall: hw3

test1: hw3-test1 hw3-test2 hw3-test3 hw3-test4 hw3-test5

#make hw3 executable
hw3: hw3.o hw3.h answer3.o func1.c func2.c func3.c func4.c func5.c
	$(GCC) -DTEST_INTEGRATE -DRUN_INTEGRATE hw3.o answer3.o func1.c func2.c func3.c func4.c func5.c -lm

#execution of test files
hw3-test1: hw3
	./hw3 testdir/test1 outputs/output-1

hw3-test2: hw3
	./hw3 testdir/test2 outputs/output-2

hw3-test3: hw3
	./hw3 testdir/test3 outputs/output-3

hw3-test4: hw3
	./hw3 testdir/test4 outputs/output-4

hw3-test5: hw3
	./hw3 testdir/test5 outputs/output-5

#build hw3 with runIntegrate
hw3.o: hw3.c answer3.c hw3.h func1.c func2.c func3.c func4.c func5.c
	$(GCC) -c -DTEST_INTEGRATE -DRUN_INTEGRATE hw3.c answer3.c func1.c func2.c func3.c func4.c func5.c -lm

#compile answer3
answer3.o: answer3.c hw3.h func1.c func2.c func3.c func4.c func5.c
	$(GCC) -c -DTEST_INTEGRATE -DRUN_INTEGRATE answer3.c func1.c func2.c func3.c func4.c func5.c -lm

%.o: %.c
	$(GCC) -c $<

#test cases
testgen: testgen.c answer3.c hw3.h | testdir
	$(GCC) -DTEST_INTEGRATE testgen.c answer.c func1.c func2.c func3.c func4.c func5.c -o testgen -lm
	./testgen test-1 1.0 2.0 10000
	./testgen test-2 -1.0 3.0 10000
	./testgen test-3 0.8 2.9 10000
	mv test-* tests/

testdir:
	mkdir -p tests

outdir:
	mkdir -p outputs

clean:
	/bin/rm -f input*
	/bin/rm -f *.o
	/bin/rm -f testgen
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f hw3 hw3.prof
	/bin/rm -f -r testdir
