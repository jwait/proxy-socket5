// proxy.cpp : Defines the entry point for the console application.
//

#include <assert.h>
#include <tchar.h>
#include <WinSock2.h>

#include "proxy.h"
int _tmain(int argc, _TCHAR* argv[])
{
    WSADATA	ws;
    WSAStartup(MAKEWORD(2, 2), &ws);;

    struct proxy* prox;

    prox = proxy_create();
    assert(prox);

    char* buff = "test";
    proxy_set(prox, "192.168.1.1", 1080, "test", "0");
    proxy_connect(prox, "127.0.0.1", 8080);
    proxy_recv_line(prox, buff, 512);

    return 0;
}

