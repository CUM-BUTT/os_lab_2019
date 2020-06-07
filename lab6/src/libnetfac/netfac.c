#include "netfac.h"

struct sockaddr_in6 create_sockaddr(uint16_t port, uint64_t s_addr) {
  struct sockaddr_in6 sockaddr = {
    .sin6_family = AF_INET6, /* Always */
    .sin6_port = htons(port), /* Host to network short */
    .sin6_addr.s6_addr = htonl(s_addr), /* Host to network long */
    //.sin_zero = {0}
  };
  return sockaddr;
}

uint64_t MultModulo(uint64_t a, uint64_t b, uint64_t mod) {
  uint64_t result = 0;
  a = a % mod;

  while (b > 0) {
    if (b % 2 == 1)
      result = (result + a) % mod;
    a = (a * 2) % mod;
    b /= 2;
  }

  return result % mod;
}
//rm /projects/cpp-hello-world/.git/index.lock