#include "tcp_servers.h"
#include <cstdio>

void Conn_Client::msgDealProc()
{
    while (true)
    {
        int len = recv(sockConn, recvBuf, 1023, 0);
        // TODO������������ͷ��˶������ε����ߣ���Ҫ����
        if (len <= 0)
        {
            // TODO: Are you core?
            // pSrv->delConn(this);
            break;
        }

        char clientIpStr[20];
        inet_ntop(AF_INET, &addrClient, clientIpStr, 20); // inet_ntoa(addrClient.sin_addr)

        recvBuf[len] = '\0';
        
        printf("%s: %s\n", clientIpStr, recvBuf);
        fflush(stdout);
    }
}

DWORD WINAPI msgProc(LPVOID lpParameter)
{
    if (NULL == lpParameter)
    {
        return -1;
    }

    Conn_Client *connClient = (Conn_Client *)lpParameter;
    connClient->msgDealProc();

    TCP_Srv *pSrv = connClient->getSrv();
    pSrv->delConn(connClient);

    return 0;
}

int TCP_Srv::startSrv()
{
    // �����׽��ֿ⣬ȷ��ʹ�õ�socket�汾
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData))
    {
        return -1;
    }

    if ((2 != LOBYTE(wsaData.wHighVersion)) || (2 != HIBYTE(wsaData.wVersion)))
    {
        WSACleanup();
        return -1;
    }

    // �����׽���
    sockSrv = socket(AF_INET, SOCK_STREAM, 0);
    if (INVALID_SOCKET == sockSrv)
    {
        // WSAGetLastError()
        WSACleanup();
        return -1;
    }

    flagVec.set(INIT_DONE);

    // ���׽���
    if (SOCKET_ERROR == bind(sockSrv, (SOCKADDR*)&addrSrvBind, sizeof(SOCKADDR)))
    {
        printf("Bind fail!");
        return -2;
    }

    // ���׽�����Ϊ����ģʽ
    listen(sockSrv, SOMAXCONN);

    SOCKADDR_IN addrClient;
    int len;

    while (true)
    {
        len = sizeof(SOCKADDR);
        SOCKET sockConn = accept(sockSrv, (SOCKADDR *)&addrClient, &len);
        if (INVALID_SOCKET != sockConn)
        {
            Conn_Client *connClient = new(std::nothrow) Conn_Client(this, sockConn, addrClient);
            if (NULL != connClient)
            {
                connClientVec.insert(connClient);

                HANDLE handle = CreateThread(NULL, 0, msgProc, connClient, 0, NULL);
                CloseHandle(handle);
            }
        }
    }

    return 0;
}