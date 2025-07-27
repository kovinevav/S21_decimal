CC=gcc
TESTFLAG=--coverage -Wall -Wextra -Werror
TESTLIB=-lcheck -lsubunit -lm -lpthread -lgcov
CLF=clang-format
FOLDERS:=. common dec_to_int int_to_dec is_greater is_less is_not_equal s21_add s21_decimal.h s21_mul dec_to_float float_to_dec is_equal is_greater_or_equal is_less_or_equal Makefile s21_decimal.c s21_div s21_sub
OBJECTS=$(foreach fldr,$(FOLDERS),$(foreach file, $(wildcard $(fldr)/*.c), $(file).o))
TEST_DIR=../test

all: clean s21_decimal.a

clean:
	$(foreach dir,$(FOLDERS),rm -rf $(dir)/*.c.*;)
	rm -rf $(TEST_DIR)/*.c.*
	rm -Rf $(TEST_DIR)/result
	rm -f $(TEST_DIR)/test
	rm -f *.a

clf:
	$(eval CLF=clang-format-18)

show: clean check gcov_report

clang: clf show

clangi: clf
	$(CLF) -i */*.c
	$(CLF) -i */*.h
	$(CLF) -i *.c
	$(CLF) -i *.h
	$(CLF) -i $(TEST_DIR)/*.c

check:
	@clear
	@echo ' '
	@echo '--== Check for mistakes'
	@if [ ! -f .clang-format ]; then \
		cp ../materials/linters/.clang-format .; \
		echo '--   .clang-format copyed'; \
	fi

	$(CLF) -n */*.c
	$(CLF) -n */*.h
	$(CLF) -n *.c
	$(CLF) -n *.h
	$(CLF) -n $(TEST_DIR)/*.c

	@echo ' ';
	cppcheck --enable=all --check-level=exhaustive --suppress=missingIncludeSystem */*.c
	@echo ' ';
	@echo '++--- clan-format -n; cppcheck; done...   press enter...'
	@read ans
	clear

test: clean
	$(foreach fldr,$(FOLDERS),$(foreach file, $(wildcard $(fldr)/*.c), gcc $(TESTFLAG) -c $(file) -o $(file).o;))
	$(foreach file, $(wildcard $(TEST_DIR)/*.c), gcc $(CFLAGS) -c $(file) -o $(file).o;)
	@if [ ! -d "$(TEST_DIR)/result" ]; then mkdir $(TEST_DIR)/result; fi
	gcc *.o */*.o $(TEST_DIR)/*.o -o $(TEST_DIR)/$@ $(TESTLIB)
	$(TEST_DIR)/$@

gcov_report: test
	lcov --directory . --capture -o $(TEST_DIR)/result/coverage.info #надо исправить каталог назначения
	genhtml --output-directory $(TEST_DIR)/result/report --legend $(TEST_DIR)/result/coverage.info

s21_decimal.a: $(OBJECTS)
	rm -f $@
	ar rcs $@ $^
	rm -rf $^

$(OBJECTS): %.c.o: %.c
	$(CC) -Wall -Wextra -Werror -c $^ -o $@

