SRC:=.
DEBUG:= -g
CFLAGS:= -std=c11
INCLUDE:=-I ../../include

.PHONY: bt_test
bt_test: $(SRC)/bt_test.c $(SRC)/bin_tree.c $(SRC)/queue.c 
	gcc $(DEBUG) $(INCLUDE) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	del *.exe

.PHONY: calc
calc: $(SRC)/postfix_calc.c $(SRC)/stack.c
	gcc $(DEBUG) $(INCLUDE) $(CFLAGS) $^ -o $@