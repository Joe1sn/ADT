SRC:=.
DEBUG:= -g
CFLAGS:= -std=c99
INCLUDE:=-I ../../include

.PHONY: clean
clean:
	del *.exe

.PHONY: calc
calc: $(SRC)/postfix_calc.c $(SRC)/stack.c
	gcc $(DEBUG) $(INCLUDE) $(CFLAGS) $^ -o $@

PHONY .bt_test
bt_test: $(SRC)/bt_test.c $(SRC)/bt_tree.c
	gcc $(DEBUG) $(INCLUDE) $(CFLAGS) $^ -o $@