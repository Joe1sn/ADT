BUILD:=../build
SRC:=.
DEBUG:= -g
CFLAGS:= -std=c11
CFLAGS+= -shared
INCLUDE:=-I ./include

$(BUILD)/%.o: $(SRC)/%.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD)/libadt.dll: \
	$(SRC)/algorithm/queue.c \
	$(SRC)/algorithm/stack.c \
	$(SRC)/algorithm/array.c \
	$(SRC)/algorithm/double_link.c \
	$(SRC)/algorithm/graph.c \
	$(SRC)/algorithm/hash.c \
	$(SRC)/algorithm/link_list.c \
	$(SRC)/algorithm/my_str.c \
	$(SRC)/algorithm/seq_list.c \
	$(SRC)/algorithm/set.c \
	$(SRC)/algorithm/sort.c \
	$(SRC)/algorithm/set.c \
	$(SRC)/algorithm/priority_queue.c \
	$(SRC)/algorithm/hash.c 

	gcc $(DEBUG) $(INCLUDE) $(CFLAGS) $^ -o $@

.PHONY: run
run:
	$(BUILD)\main.exe

.PHONY: clean
clean:
	del $(BUILD)\main.exe