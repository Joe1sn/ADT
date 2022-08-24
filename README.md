> 中文请阅读 [README_zh.md](./README_zh.md)

# ADT

abstruct data type in Data Structure and Algorithm

a way of implementation

- [x] Chapter I   : Basic Theory & History
- [x] Chapter II  : Linear table
- [x] Chapter III : Stack & Queue
- [x] Chapter IV  : Array & Strings
- [x] Chapter V   : Tree & Binary tree
- [x] Chapter VI  : Set & Searching
- [x] Chapter VII : Search Tree
- [x] Chapter IIX : Hash table
- [x] Chapter IX  : Graph
- [x] Chapter X   : Sort

## usage

### 1. complie

```
cd ./src && make
```

### 2. linkage

linux_x64
```
cd ./build/
export LD_LIBRARY_PATH="$(pwd)"
cd ./test_case
gcc ./hash_table.c -std=c99 -ladt -L.. -I ../../src/include -o testcase
```

linux_x32
```
cd ./build/
export LD_LIBRARY_PATH="$(pwd)"
cd ./test_case
gcc -m32 ./hash_table.c -std=c99 -ladt -L.. -I ../../src/include -o testcase
```

windows_x32
```
cd .\build
gcc .\test_case\hash_table.c -std=c99 -ladt -L. -I ..\src\include -o testcase.exe
```

### flaws
Supported
- [x] array.c
- [ ] bt_test.c
- [x] dbs_bfs.c
- [x] hash_table.c
- [x] my_str.c
- [ ] postfix_calc.c
- [x] prior_q.c
- [x] queue.c
- [x] seq_list.c
- [ ] single_link_list.c
- [x] stack.c
- [ ] tree.c