#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <functional>
#include <unistd.h>
#include <unistd.h> // For close()
using namespace std;
#define PORT 9909

struct sockaddr_in srv; // include netinet/in.h
fd_set fr, fw, fe;      // FR -> READ SOCKET, FE -> WRITE SOCKET, FE -> EXCEPTION SOCKET
int nMaxFd;

void ProcessTheNewRequest()
{
    if(FD_ISSET)
}

int main()
{
    int nRet = 0;
    // iNITIALIZE THE SOCKET
    int nSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (nSocket < 0)
    {
        std::cout << "Socket not open\n";
    }
    else
    {
        std::cout << "Socket opened successfully " << nSocket << "\n";
    }

    // INITIALIZE THE ENVIRONMENT FOR SOCKADDR STRUCTURE
    srv.sin_family = AF_INET;
    srv.sin_port = htons(PORT);

    // srv.sin_addr.s_addr = inet_addr("127.0.0.1");
    srv.sin_addr.s_addr = INADDR_ANY;
    memset(&(srv.sin_zero), 0, 8); // include cstring

    int nOptVal = 0;
    int nOptLen = sizeof(nOptVal);
    nRet = setsockopt(nSocket, SOL_SOCKET, SO_REUSEADDR, (const char*)&nOptVal, nOptLen);
    if(!nRet)
    {
        std::cout<<"The setsockopt call successful. \n";
    }
    else
    {
        std::cout<<"The setsockopt call unsuccessful. \n";
        close(nSocket);
        exit(EXIT_FAILURE);
    }

    //Blocking and non blocking socket

    // BIND THE SOCKET TO THE LOCAL PORT
    nRet = bind(nSocket, (sockaddr *)&srv, sizeof(sockaddr));
    if (nRet < 0)
    {
        std::cout << "Failed to bid to local port\n";
        close(nSocket);
        exit(EXIT_FAILURE);
    }
    else
    {
        std::cout << "Successfully bind to local port\n";
    }

    // LISTEN THE REQUEST FROM THE CLIENT
    nRet = listen(nSocket, 5); // 5 tells how many request at a time your server can pull, how many request in the active queue

    if (nRet < 0)
    {
        std::cout << "Failed to start listen to local port\n";
        close(nSocket);
        exit(EXIT_FAILURE);
    }
    else
    {
        std::cout << "Successfully listen to local port\n";
    }

    nMaxFd = nSocket;
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    while (1)
    {
        FD_ZERO(&fr);
        FD_ZERO(&fw);
        FD_ZERO(&fe);

        FD_SET(nSocket, &fr);
        FD_SET(nSocket, &fe);

        // KEEP WAITING FOR THE NEW REQUEST AND PROCEED AS PER REQUEST
        nRet = select(nMaxFd + 1, &fr, &fw, &fe, &tv);
        if (nRet > 0)
        {
            // When someone connects or communicate with a message over a dedicated connection
        }
        else if (nRet == 0)
        {
            // No connection or any communication request made or you can say non of the socet descripto are ready
            std::cout<<"Nothing on port\n";
        }
        else
        {
            // It fail and your application should show some useful message
            std::cout << "Nothing of port: " << PORT << std::endl;
            close(nSocket);
            exit(EXIT_FAILURE);
        }
        sleep(2);
    }
}