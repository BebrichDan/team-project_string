CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror 
LDFLAGS = -lcheck -lm -lsubunit -lgcov 
SRC = $(wildcard s21_*.c) $(wildcard $(ARITHMETIC)*.c) $(wildcard $(EDITOR)*.c) $(wildcard $(OTHER)*.c)
OBJ = $(SRC:.c=.o)
TESTS_DIR_ARITHMETIC = tests/arithmetic_test/
TESTS_DIR_EDITOR= tests/editor_test/
TESTS_DIR_OTHER = tests/other_test/
ARITHMETIC = arithmetic/
EDITOR = editor/
OTHER = other/
TESTS = $(wildcard $(TESTS_DIR_ARITHMETIC)*.c) $(wildcard $(TESTS_DIR_EDITOR)*.c) $(wildcard $(TESTS_DIR_OTHER)*.c)
TEST = test_main.c
T_OBJ = $(TEST:.c=.o)
TEST_OBJ = $(TESTS:.c=.o)
EXEC = tests/test

s21_matrix.a: clean
	$(CC) $(CFLAGS) -c $(SRC) 
	ar rsc s21_matrix.a *.o
	rm *.o

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(EXEC) $(T_OBJ)
	rm -f s21_matrix.a
	rm -f *.gcda *.gcno *.gcov
	rm -f tests/*.gcda tests/*.gcno tests/*.gcov
	rm -rf coverage

test: s21_matrix.a
	$(CC) $(CFLAGS) $(TEST) $(TESTS) s21_matrix.a -o $(EXEC) -lcheck -lm -lsubunit  
	./$(EXEC)

rebuild: clean $(EXEC) test

clang-format-formating:
	clang-format -i -style=Google *.c *.h    
	clang-format -i -style=Google $(TESTS_DIR_ARITHMETIC)*.c     
	clang-format -i -style=Google $(TESTS_DIR_EDITOR)*.c
	clang-format -i -style=Google $(TESTS_DIR_OTHER)*.c
	clang-format -i -style=Google $(ARITHMETIC)*.c $(ARITHMETIC)*.h
	clang-format -i -style=Google $(EDITOR)*.c
	clang-format -i -style=Google $(OTHER)*.c
	
clang-format-check:    
	clang-format -n -style=Google *.c *.h   
	clang-format -n -style=Google $(TESTS_DIR_ARITHMETIC)*.c     
	clang-format -n -style=Google $(TESTS_DIR_EDITOR)*.c 
	clang-format -n -style=Google $(TESTS_DIR_OTHER)*.c
	clang-format -n -style=Google $(ARITHMETIC)*.c $(ARITHMETIC)*.h
	clang-format -n -style=Google $(EDITOR)*.c
	clang-format -n -style=Google $(OTHER)*.c

valgrind: clean s21_matrix.a
	$(CC) $(CFLAGS) $(TEST) $(TESTS) s21_matrix.a -o $(EXEC) -lcheck -lm -lsubunit
	valgrind --tool=memcheck --leak-check=yes -q ./$(EXEC)

open:
	open coverage/html/index.html

gcov_report: clean s21_matrix.a
	$(CC) $(CFLAGS) $(TEST) $(TESTS) $(SRC) -fprofile-arcs -ftest-coverage -o $(EXEC) -lcheck -lm -lsubunit  
	./$(EXEC)
	mkdir -p coverage
	lcov --capture --directory . --output-file coverage/*.info --include 'arithmetic/*.c' --include 'editor/*.c' --include 'other/*.c'
	lcov --add-tracefile coverage/*.info --output-file coverage/coverage.info
	genhtml coverage/coverage.info --output-directory coverage/html
	rm -f tests/*.gcda tests/*.gcno tests/*.gcov

all: s21_matrix.a

.PHONY: clean test rebuild all s21_matrix.a gcov_report valgrind clang-format-check clang-format-formating