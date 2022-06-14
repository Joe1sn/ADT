SRC:=.
DEBUG:= -g
CFLAGS:= -std=c99
INCLUDE:=-I ../../include

main: $(SRC)/main.c $(SRC)/double_link.c
	gcc $(DEBUG) $(INCLUDE) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	del main.exe