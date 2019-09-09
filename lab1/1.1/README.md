# Translate hostname into IPv4 and IPv6

## How to run
1. Compile 
```
$ g++ -o output lab1.cpp
```

2. Make file executable
```
$ chmod +x output
```

3. Run executable
```
$ ./output chalmers.se
```

4. Result
```
Resolving `chalmers.se' from `<hostname>':
IPv4: 129.16.71.10
IPv6: 2001:6b0:2:200c::7110
```

1. Check result
```
$ host chalmers.se
```

</br>

## Documentation

- [getaddrinfo()](http://man7.org/linux/man-pages/man3/getaddrinfo.3.html)

```
struct addrinfo {
    int              ai_flags;
    int              ai_family;
    int              ai_socktype;
    int              ai_protocol;
    socklen_t        ai_addrlen;
    struct sockaddr *ai_addr;
    char            *ai_canonname;
    struct addrinfo *ai_next;
};
```

- sockaddr
  - sa_family 
    - Tells us the address family of this instance of sockaddr
    - The AF_INET address family represents IPv4 addresses. There are others, such as AF_INET6 or AF_UNSPEC
```
struct sockaddr {
    sa_family_t sa_family;
    char
    sa_data[14];
}
```

- sockaddr_in
```
struct sockaddr_in {
    sa_family_t
    sin_family;                 // address family: AF_INET, AF_INET6
    in_port_t
    sin_port;                   // port in network byte order
    struct in_addr sin_addr;    // internet address
};
```

- in_addr
```
struct in_addr {
    uint32_t	s_addr;         // Address in network byte order
};
```

- [inet_ntop](http://man7.org/linux/man-pages/man3/inet_ntop.3.html)