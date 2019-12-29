# A simple, but flawed iterative server program

## Description 
In this assignment, we analyzed and tested a simple but flawed server application.

## How to run
1. Build the server program
```
$ g++ -Wall -Wextra -g3 server-iterative.cpp -o server-iterative
```

2. Start the server
```
./server <PORT>
```

3. Build the standard single-client program
```
$ g++ -Wall -Wextra -g3 client-simple.cpp -o client-simple
```

4. Start the client
```
$ ./client-simple remote.example.com <PORT>
```

5. Build the multi-client emulator program
```
$ g++ -Wall -Wextra -g3 client-multi.cpp -o client-multi -lrt
```

The following command would emulates 255 clients that each send 1705 messages to a host called remote.example.com on port 5703. The message template used is “Client %d says
hello.”
```
$ ./client-multi remote.example.com 5703 255 1705 ’Client %d says hello.’
```