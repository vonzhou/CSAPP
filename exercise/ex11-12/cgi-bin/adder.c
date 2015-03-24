/*
 * 11.12
 *
 * mofaph@gmail.com
 * 2013-6-11
 *
 * unix> cc -I../../../common ../../../common/csapp.c adder.c -lpthread -o adder
 */

#include "csapp.h"

int main(void)
{
        char *buf, *p;
        char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
        int n1 = 0, n2 = 0;

        char *method = getenv("REQUEST_METHOD");
        int is_response = !strcasecmp(method, "GET") || !strcasecmp(method, "POST");

        buf = getenv("QUERY_STRING");
        if (buf == NULL || strlen(buf) == 0) {
                snprintf(content, sizeof(content),
                         "<form name=\"input\" action=\"http://localhost:8192/cgi-bin/adder\" method=\"get\">"
                         "<input type=\"text\" name=\"num1\" />"
                         "+"
                         "<input type=\"text\" name=\"num2\" />"
                         "<br />"
                         "<input type=\"submit\" value=\"Submit\" />"
                         "</form>");
        } else {
                p = strchr(buf, '&');
                *p = '\0';

                char *index = strchr(buf, '=');
                if (index == NULL) {
                        strcpy(arg1, buf);
                } else {
                        strcpy(arg1, index+1);
                }
                n1 = atoi(arg1);

                index = strchr(p+1, '=');
                if (index == NULL) {
                        strcpy(arg2, p+1);
                } else {
                        strcpy(arg2, index+1);
                }
                n2 = atoi(arg2);

                /* Make the response body */
                if (is_response) {
                        snprintf(content, sizeof(content),
                                 "Welcome to add.com: "
                                 "THE Internet addition portal.\r\n<p>"
                                 "The answer is: %d + %d = %d\r\n<p>"
                                 "Thanks for visiting!\r\n",
                                 n1, n2, n1+n2);
                }
        }

        /* Generate the HTTP is_response */
        printf("Content-length: %d\r\n", is_response ? (int)strlen(content) : 0);
        printf("Content-type: text/html\r\n\r\n");
        printf("%s", content);

        fflush(stdout);
        exit(0);
}
