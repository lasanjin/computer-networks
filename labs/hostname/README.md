# Translate hostname into IPv4 and IPv6

## Description 
In this assignment we resolved a host name into an IPv4 address. It is an short easy introduction to network programming using the BSD socket API in C/C++.

## How to run
1. Compile 
```
$ g++ -o thn translate_host_name.cpp
```

2. Make file executable
```
$ chmod +x thn
```

3. Run executable
```
$ ./thn chalmers.se
```

4. Result
```
Resolving `chalmers.se' from `<hostname>':
IPv4: 129.16.71.10
IPv6: 2001:6b0:2:200c::7110
```

5. Check result
```
$ host chalmers.se
```

</br>

## Documentation

- [getaddrinfo()](http://man7.org/linux/man-pages/man3/getaddrinfo.3.html)
  - The getaddrinfo() function allocates and initializes a linked list of addrinfo structures, one for each network address that matches node and service, subject to any restrictions imposed by hints, and returns a pointer to the start of the list in res.  The items in the linked list are linked by the ai_next field.

```c
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

</br>

- sockaddr
  - sa_family 
    - Tells us the address family of this instance of sockaddr
    - The AF_INET address family represents IPv4 addresses. There are others, such as AF_INET6 (IPv6) or AF_UNSPEC (IPv4 or/and IPv6). 
    - **NOTE** 
      - AF_INET has sockaddr_in. We cast sockaddr to sockaddr_in to access sin_addr variable were the internet adress is stored.
      - AF_INET6 har sockaddr_in6
```c
struct sockaddr {
    sa_family_t sa_family;
    char
    sa_data[14];
}
```

</br>

- sockaddr_in
```c
struct sockaddr_in {
    sa_family_t
    sin_family;                 // address family: AF_INET, AF_INET6
    in_port_t
    sin_port;                   // port in network byte order
    struct in_addr sin_addr;    // internet address
};
```

</br>

- in_addr
```c
struct in_addr {
    uint32_t	s_addr;         // Address in network byte order
};
```

</br>

- [inet_ntop()](http://man7.org/linux/man-pages/man3/inet_ntop.3.html)
  - Method to convert in_addr struct to IP string