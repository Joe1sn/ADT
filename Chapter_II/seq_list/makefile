SRC:=.
DEBUG:= -g
CFLAGS:= -std=c99

main: $(SRC)/main.c $(SRC)/seq_list.c
	gcc $(DEBUG) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	del main.exe