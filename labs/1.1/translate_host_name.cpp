#include <stddef.h>
#include <stdio.h>
#include <cstring>

#include <assert.h>
#include <limits.h>
#include <unistd.h>

// freeaddrinfo, getaddrinfo
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

// IPPROTO_TCP
#include <arpa/inet.h>

void print_usage(const char *aProgramName);
addrinfo get_params();
addrinfo **getaddrinfo(const char *remote_hostname, struct addrinfo *params);
void print_ip(addrinfo *res);

int main(int aArgc, char *aArgv[])
{
  // Check if the user supplied a command line argument.
  if (aArgc != 2)
  {
    print_usage(aArgv[0]);
    return 1;
  }

  // The (only) argument is the remote host that we should resolve.
  const char *remote_hostname = aArgv[1];

  // Get the local host's name (i.e. the machine that the program is
  // currently running on).
  const size_t hostname_max_length = HOST_NAME_MAX + 1;
  char local_hostname[hostname_max_length];

  if (-1 == gethostname(local_hostname, hostname_max_length))
  {
    perror("gethostname(): ");
    return 1;
  }

  // Print the initial message
  printf("Resolving `%s' from `%s':\n", remote_hostname, local_hostname);

  // Get criteria for selecting the socket address structures
  struct addrinfo params = get_params();

  // Get internet address(es) from hostname
  struct addrinfo **res = getaddrinfo(remote_hostname, &params);

  // Print IPv4 and/or IPv6
  print_ip(res);

  // Free linked list
  freeaddrinfo(res);

  // Ok, we're done. Return success.
  return 0;
}

addrinfo get_params()
{
  /*
   * Init addrinfo struct that specifies criteria for
   * selecting the socket address structures
   */
  struct addrinfo params;

  // Make sure the struct is empty
  memset(&params, 0, sizeof params);

  // Protocol parameter for TCP socket
  params.ai_protocol = IPPROTO_TCP;

  // TCP stream sockets
  params.ai_socktype = SOCK_STREAM;

  // Allow IPv4 and/or IPv6
  params.ai_family = AF_UNSPEC;

  // 0 indicates that we don’t care about those
  params.ai_canonname = 0;
  params.ai_addr = 0;
  params.ai_next = 0;

  return params;
}

addrinfo **getaddrinfo(const char *remote_hostname, struct addrinfo *params)
{
  // getaddrinfo returnes a linked list pointed to by res
  struct addrinfo **res;

  int msg_code = getaddrinfo(remote_hostname, NULL, params, res);

  // Check getaddrinfo return value for errors
  if (msg_code != 0)
  {
    printf("Error in getaddrinfo: %s\n", gai_strerror(msg_code));
    _exit;
  }

  return res;
}

void print_ip(addrinfo *res)
{
  // Pointer linked list
  struct addrinfo *next;

  // IPv4, IPv6 both fit
  char ip_arr[INET6_ADDRSTRLEN];

  for (next = res; next != NULL; next = next->ai_next)
  {
    // sockaddr_in, sockaddr_in6
    void *ip_addr;

    const char *ipv;
    int protocol_family = next->ai_family;

    // IPv4
    if (protocol_family == AF_INET)
    {
      // Cast sockaddr to sockaddr_in
      struct sockaddr_in *ipv4 = (struct sockaddr_in *)next->ai_addr;

      // Get in_addr from sockaddr_in struct
      ip_addr = &(ipv4->sin_addr);

      ipv = "IPv4";
    }

    // IPv6
    else
    {
      struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)next->ai_addr;
      ip_addr = &(ipv6->sin6_addr);
      ipv = "IPv6";
    }

    // Convert IP to string
    inet_ntop(protocol_family, ip_addr, ip_arr, sizeof ip_arr);

    printf("%s: %s\n", ipv, ip_arr);
  }
}

void print_usage(const char *aProgramName)
{
  fprintf(stderr, "Usage: %s <hostname>\n", aProgramName);
}
