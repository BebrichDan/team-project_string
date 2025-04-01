CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror
LDFLAGS = -lcheck -lm -lsubunit -lgcov 
SRC = $(wildcard s21_*.c)
OBJ = $(SRC:.c=.o)
TESTS_DIR_STRING = tests/string/
TESTS_DIR_SPRINTF= tests/sprintf/
TESTS_DIR_SSCANF = tests/sscanf/
TESTS = $(wildcard $(TESTS_DIR_SSCANF)*.c) $(wildcard $(TESTS_DIR_SPRINTF)*.c) $(wildcard $(TESTS_DIR_STRING)*.c)
TEST = test_main.c
T_OBJ = $(TEST:.c=.o)
TEST_OBJ = $(TESTS:.c=.o)
EXEC = tests/test

# Создание статической библиотеки из исходников библиотеки
s21_string.a: clean
	$(CC) $(CFLAGS) -c $(SRC)
	ar rsc s21_string.a $(OBJ)
	rm $(OBJ)

# Очистка сгенерированных файлов
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(EXEC) $(T_OBJ)
	rm -f s21_string.a
	rm -f *.gcda *.gcno *.gcov
	rm -f tests/*.gcda tests/*.gcno tests/*.gcov
	rm -f tests/sscanf/*.o
	rm -rf coverage

# Запуск тестов (всегда выполнять)
test: s21_string.a
	$(CC) $(CFLAGS) $(TEST) $(TESTS) s21_string.a -o $(EXEC) -lcheck -lm -lsubunit  
	./$(EXEC)

# Компиляция и запуск тестов
rebuild: clean $(EXEC) test

clang-format-formating:
	clang-format -i *.c    
	clang-format -i *.h 
	clang-format -i tests/string/*.c     
	clang-format -i tests/sprintf/*.c 
	clang-format -i tests/sscanf/*.c 	
	
clang-format-check:    
	clang-format -n *.c
	clang-format -n *.h     
	clang-format -n tests/string/*.c 
	clang-format -n tests/sprintf/*.c     
	clang-format -n tests/sscanf/*.c

valgrind: clean s21_string.a
	$(CC) $(CFLAGS) $(TEST) $(TESTS) s21_string.a -o $(EXEC) -lcheck -lm -lsubunit
	valgrind --tool=memcheck --leak-check=yes -q ./$(EXEC)

open:
	open coverage/html/index.html

gcov_report: clean
	$(CC) $(CFLAGS) $(TEST) $(TESTS) $(SRC) -fprofile-arcs -ftest-coverage -o $(EXEC) -lcheck -lm -lsubunit  
	./$(EXEC)
	mkdir -p coverage
	lcov --capture --directory . --output-file coverage/coverage.info --include 's21_string.c'
	lcov --capture --directory . --output-file coverage/s21_sprintf.info --include 's21_sprintf.c'
	lcov --capture --directory . --output-file coverage/s21_sscanf.info --include 's21_sscanf.c'
	lcov --add-tracefile coverage/coverage.info --add-tracefile coverage/s21_sprintf.info --add-tracefile coverage/s21_sscanf.info --output-file coverage/coverage.info
	genhtml coverage/coverage.info --output-directory coverage/html
	rm -f tests/*.gcda tests/*.gcno tests/*.gcov

all: s21_string.a

.PHONY: clean test rebuild all s21_string.a gcov_report valgrind clang-format-check clang-format-formating