# I/O multiplexing for concurrent connection handling

## Description 
In this assignment we changed the server from lab 1.2 to fix some of the flaws. Our task was to turn the simple iterative server into a concurrent server using I/O multiplexing. The assignment included source code, which we improved and extended.

## How to run
1. Build the server program
```
$ g++ -Wall -Wextra -g3 server-concurrent.cpp -o server-concurrent
```

2. Start the server
```
./server <PORT>
```

3. Build and execute client program. See instructions in [1.2](../1.2/README.md)