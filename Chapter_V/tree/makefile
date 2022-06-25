SRC:=.
DEBUG:= -g
CFLAGS:= -std=c11
INCLUDE:=-I ../../src/include

.PHONY: bt_test
bt_test: $(SRC)/bt_test.c $(SRC)/stack.c $(SRC)/bin_tree.c $(SRC)/queue.c
	gcc $(DEBUG) $(INCLUDE) $(CFLAGS) $^ -o $@

.PHONY: run
run:
	$(BUILD)/main.exe

.PHONY: clean
clean:
	del *.exe