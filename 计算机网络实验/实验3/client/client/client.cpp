/*****************************************************************************
* @author  : ljf                                                             *
* @date    : 2020/03/17                                                      *
* @file    : Client.cpp                                                      *
* @brief   : 基于TCP协议通信——客户端                                       *
*----------------------------------------------------------------------------*
*                           Change History                                   *
*----------------------------------------------------------------------------*
* Date        | Version   | Author         | Description                     *
*----------------------------------------------------------------------------*
* 2020/03/17  | 1         | ljf            |  创建并简单实现                 *
*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <winsock.h>

#pragma comment(lib, "wsock32.lib")	//隐式加载

int main() {
	//服务器端口
	int SERVER_PORT = 5678;
	//服务器IP
	char SERVER_IP[20] = "127.0.0.1";
	//缓冲区大小
	const int BUFF_SIZE = 1024;
	char SEND_BUFF[BUFF_SIZE];
	char RECV_BUFF[BUFF_SIZE];

	//初始化套接字
	WSADATA wsadata;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata)) {
		printf("WSAStartup error ---- Error Code: %d", WSAGetLastError());
		WSACleanup();
		return -1;
	}
	//创建客户端套接字
	SOCKET client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == client_socket) {
		printf("Create socket error ---- Error Code: %d", WSAGetLastError());
		WSACleanup();
		return -2;
	}

	//初始化服务端连接信息
	sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5678);
	server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

	//连接到服务端
	if (SOCKET_ERROR == connect(client_socket, (sockaddr*)&server_addr, sizeof(server_addr))) {
		printf("Connect %s:%d failed ---- Error Code: %d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port), WSAGetLastError());
		WSACleanup();
		return -3;
	}
	else {
		printf("[Connect %s:%d success]\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));
	}

	//信息交互
	while (true) {
		//清空缓冲区
		memset(SEND_BUFF, 0, BUFF_SIZE);
		memset(RECV_BUFF, 0, BUFF_SIZE);

		printf("[Send]: ");
		//读取一行字符串，回车结束，回车会被读入
		fgets(SEND_BUFF, BUFF_SIZE, stdin);
		//处理末尾的回车
		SEND_BUFF[strlen(SEND_BUFF) - 1] = '\0';

		//收发数据
		if (strlen(SEND_BUFF) != 0) {
			send(client_socket, SEND_BUFF, strlen(SEND_BUFF), 0);
			recv(client_socket, RECV_BUFF, BUFF_SIZE, 0);
			printf("[Recv]: %s\n", RECV_BUFF);
		}
	}
	closesocket(client_socket);
	WSACleanup();
	system("pause");
	return 0;
}