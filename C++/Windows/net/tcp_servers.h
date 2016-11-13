#pragma once

#include <Winsock2.h>
#include <WS2tcpip.h>
#include <bitset>
#include <set>

#pragma comment(lib, "ws2_32.lib")

class TCP_Srv;
class Conn_Client
{
public:
    Conn_Client(TCP_Srv *srv, SOCKET sock, SOCKADDR_IN addrSock)
        : pSrv(srv), sockConn(sock), addrClient(addrSock)
    {
        //
    }

    ~Conn_Client()
    {
        closesocket(sockConn);
    }

    TCP_Srv *getSrv() const
    {
        return pSrv;
    }

    // static DWORD WINAPI msgDealProc(LPVOID lpParameter);
    void msgDealProc();   

private:
    TCP_Srv *pSrv;
    SOCKET sockConn;
    SOCKADDR_IN addrClient;
    char recvBuf[1024];
};

class TCP_Srv
{
public:
    enum FLAG_BIT { INIT_DONE };

public:
    TCP_Srv(char *ip, int port) : sockSrv(INVALID_SOCKET)
    {
        addrSrvBind.sin_family = AF_INET;

        if ((NULL == ip) || (0 == port))
        {
            addrSrvBind.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
            addrSrvBind.sin_port = htons(38361);
        }
        else
        {
            inet_pton(AF_INET, ip, &addrSrvBind); // addrSrvBind.sin_addr.S_un.S_addr = inet_pton(ip);
            addrSrvBind.sin_port = htons(port);
        }
    }

    ~TCP_Srv()
    {
        if (flagVec.test(INIT_DONE))
        {
            closesocket(sockSrv);
            WSACleanup();
        }
    }

    void delConn(Conn_Client *p)
    {
        delete p;
        connClientVec.erase(p);
    }

    int startSrv();

private:
    SOCKET sockSrv;
    SOCKADDR_IN addrSrvBind;
    std::bitset<8> flagVec;
    std::set<Conn_Client *> connClientVec;
};