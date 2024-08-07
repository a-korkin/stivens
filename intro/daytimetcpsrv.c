#include "../lib/unp.h"
#include "../lib/error.h"
#include <stdio.h>
#include <sys/socket.h>
#include <time.h>

int main(int argc, char **argv) {
    int listenfd, connfd, n;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];
    time_t ticks;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(13);

     if ((n = bind(listenfd, (SA *) &servaddr, sizeof(servaddr))) < 0) 
        err_sys("bind error");

     if ((n = listen(listenfd, LISTENQ)) < 0)
         err_sys("listen error");

     for (;;) {
         if ((connfd = accept(listenfd, (SA *) NULL, NULL)) < 0)
             err_sys("accept error");
         ticks = time(NULL);
         snprintf(buff, sizeof(buff), "%.24s\er\en", ctime(&ticks));
         if ((n = write(connfd, buff, strlen(buff))) < 0)
             err_sys("write error");
         if ((n = close(connfd)) < 0)
             err_sys("close error");
     }

    return 0;
}

