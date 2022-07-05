BUILD:=..\build
SRC:=.
DEBUG:= -g
CFLAGS:= -std=c11
INCLUDE:=-I .\include

$(BUILD)/%.o: $(SRC)/%.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD)\main.exe: \
	$(SRC)/main.c \
	$(SRC)/algorithm/seq_list.c \
	$(SRC)/algorithm/link_list.c \
	$(SRC)/algorithm/postfix_calc.c \
	$(SRC)/algorithm/t_stack.c \
	$(SRC)/algorithm/t_queue.c \
	$(SRC)/algorithm/array.c \
	$(SRC)/algorithm/my_str.c \
	$(SRC)/algorithm/bin_tree.c \
	$(SRC)/algorithm/priority_queue.c \
	$(SRC)/algorithm/hash.c

	gcc $(DEBUG) $(INCLUDE) $(CFLAGS) $^ -o $@

.PHONY: run
run:
	$(BUILD)\main.exe

.PHONY: clean
clean:
	del $(BUILD)\main.exe