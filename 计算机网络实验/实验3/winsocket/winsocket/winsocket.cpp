/*****************************************************************************
* @author  : ljf                                                             *
* @date    : 2020/03/17                                                      *
* @file    : Server.cpp                                                      *
* @brief   : 基于TCP协议通信——服务端                                       *
*----------------------------------------------------------------------------*
*                           Change History                                   *
*----------------------------------------------------------------------------*
* Date        | Version   | Author         | Description                     *
*----------------------------------------------------------------------------*
* 2020/03/17  | 1         | ljf            | 创建并简单实现                  *
*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <winsock.h>

#pragma comment(lib, "wsock32.lib")	//隐式加载

int main() {
	//服务器监听端口
	int SERVER_PORT = 5678;
	//缓冲区大小
	const int BUFF_SIZE = 1024;
	char SEND_BUFF[] = "已收到";
	char RECV_BUFF[BUFF_SIZE];

	//初始化套接字
	WSADATA wsadata;
	if (0 != WSAStartup(MAKEWORD(1, 1), &wsadata)) {
		printf("WSAStartup error ---- Error Code: %d", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	//创建服务端套接字（监听套接字）
	SOCKET server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == server_socket) {
		printf("Create socket error ---- Error Code: %d", WSAGetLastError());
		WSACleanup();
		return -2;
	}

	//初始化监听信息
	sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SERVER_PORT);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (SOCKET_ERROR == bind(server_socket, (sockaddr*)&server_addr, sizeof(server_addr))) {
		printf("socket bind error ---- Error Code: %d", WSAGetLastError());
		WSACleanup();
		return -3;
	}

	//监听数目（暂时没用，阻塞）
	if (SOCKET_ERROR == listen(server_socket, 5)) {
		printf("socket listen error ---- Error Code: %d", WSAGetLastError());
		WSACleanup();
		return -4;
	}
	printf("Listen port %d...\n", SERVER_PORT);

	sockaddr_in client_addr;
	int client_addr_len = sizeof(client_addr);
	//等待建立连接
	SOCKET client_socket = accept(server_socket, (sockaddr*)&client_addr, &client_addr_len);
	if (INVALID_SOCKET == client_socket) {
		printf("socket accept error ---- Error Code: %d", WSAGetLastError());
		WSACleanup();
		return -5;
	}
	else {
		printf("[Connect]: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
	}

	//信息交互
	while (true) {
		//清空缓冲区
		memset(RECV_BUFF, 0, BUFF_SIZE);

		//接收信息
		if (0 < recv(client_socket, RECV_BUFF, BUFF_SIZE, 0)) {
			printf("[Recv]: %s\n", RECV_BUFF);
			send(client_socket, SEND_BUFF, strlen(SEND_BUFF), 0);
		}
		//断开连接（客户端排除数据长度0）
		else {
			break;
		}
	}

	closesocket(client_socket);
	closesocket(server_socket);
	WSACleanup();
	system("pause");
	return 0;
}