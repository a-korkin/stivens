#include "error.h"
#include "unp.h"

int Socket(int family, int type, int protocol) {
    int n;
    if ((n = socket(family, type, protocol)) < 0)
        err_sys("socket error");
    return n;
}

