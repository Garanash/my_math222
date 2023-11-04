
CC=gcc
CFLAGS=-Wall -Wextra -Werror
LDFLAGS=$(shell pkg-config --cflags --libs check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage
OS=$(shell uname -s)

ifeq ($(OS),Linux)
	TEST_LIBS =-lcheck -lm -lsubunit
else
	TEST_LIBS =-lcheck
endif

all: s21_math.a test gcov_report

s21_math.a:
	$(CC) $(CFLAGS) -c s21_math.c
	ar rc s21_math.a *.o
	ranlib s21_math.a

clean:
	-rm -rf report/ *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt

test:
	$(CC) $(CFLAGS) s21_math.c tests/*.c -o s21_math_test $(TEST_LIBS)

gcov_report:
	$(CC) $(CFLAGS) $(LDFLAGS) $(GCOVFLAGS) s21_math.c tests/*.c -o s21_math_test $(TEST_LIBS)
	./s21_math_test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory report
	rm -rf *.gcda *.gcno
	open report/index.html