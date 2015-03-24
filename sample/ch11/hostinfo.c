/*
 * p622
 *
 * 检索并打印一个 DNS 主机条目
 *
 * unix> cc -I../../common ../../common/csapp.c hostinfo.c -lpthread -o hostinfo
 *
 * unix> ./hostinfo localhost #1
 * unix> ./hostname #2
 * unix> ./hostinfo bluefish.ics.cs.cmu.edu
 * unix> ./hostinfo cs.mit.edu
 * unix> ./hostinfo google.com
 * unix> ./hostinfo edu
 */

#include "csapp.h"

int main(int argc, char **argv)
{
        char **pp;
        struct in_addr addr;
        struct hostent *hostp;

        if (argc != 2) {
                fprintf(stderr, "usage: %s <domain name or dotted-decimal>\n", argv[0]);
                exit(0);
        }

        if (inet_aton(argv[1], &addr) != 0)
                hostp = Gethostbyaddr((const char *)&addr, sizeof(addr), AF_INET);
        else
                hostp = Gethostbyname(argv[1]);

        printf("official hostname: %s\n", hostp->h_name);

        for (pp = hostp->h_aliases; *pp != NULL; pp++)
                printf("alias: %s\n", *pp);

        for (pp = hostp->h_addr_list; *pp != NULL; pp++) {
                addr.s_addr = ((struct in_addr *)*pp)->s_addr;
                printf("address: %s\n", inet_ntoa(addr));
        }

        exit(0);
}
