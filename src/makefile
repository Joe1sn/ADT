BUILD:=..\build
SRC:=.
DEBUG:= -g
CFLAGS:= -std=c11
INCLUDE:=-I .\include

$(BUILD)/%.o: $(SRC)/%.c
	gcc $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(BUILD)\main.exe: \
	$(SRC)/main.c \
	$(SRC)/algorithm/queue.c \
	$(SRC)/algorithm/stack.c \
	$(SRC)/algorithm/graph.c

	gcc $(DEBUG) $(INCLUDE) $(CFLAGS) $^ -o $@

.PHONY: run
run:
	$(BUILD)\main.exe

.PHONY: clean
clean:
	del $(BUILD)\main.exe