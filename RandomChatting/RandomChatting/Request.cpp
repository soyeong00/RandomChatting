#include "pch.h"
#include "Request.h"
#include <iostream>
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")

Request::Request()
{
}

Request::~Request()
{
}

void Request::SendRequestToAnyone(string inviter)
{
	WSADATA data; //WSAStartup()을 시작하기 위해 필요한 파일
	WORD version = MAKEWORD(2, 2); //WSAStartup에 version이 있어야 시작할수 있음
	//WinSock을 시작하는 곳
	int wsOk = WSAStartup(version, &data);
	if(wsOk != 0) //WinSock이 알여렸으면 나가주는 곳!!!
		return;
	//서버와 연결하는 단계
	//서버에 대한 hint structure 만들기
	sockaddr_in server;
	server.sin_family = AF_INET; //AF_INET =IPv4 address 를 쓰겠다고 해주는거
	server.sin_port = htons(54000); //포트 지정
	PCSTR ip = "192.168.43.255"; //접속해있는 ip //보낼곳
	inet_pton(AF_INET, ip, &server.sin_addr);//string을 byte array로 변환 해주는 방법

	//Socket만들기 :Socket의 형은 datagram
	SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);
	//Socket에 string보내는 법 -> 그러면 기다리는 애한테 날라감
	string s = inviter;
	int sendOk = sendto(out, s.c_str(), s.size() + 1, 0, (sockaddr*) &server, sizeof(server));
	if(sendOk == SOCKET_ERROR)
	{
	}
	//소켓을 닫는다
	closesocket(out);
	//close down Winsock
	WSACleanup();
}

void Request::SendRequestByName(string inviter,string receiver)
{
	WSADATA data; //WSAStartup()을 시작하기 위해 필요한 파일
	WORD version = MAKEWORD(2, 2); //WSAStartup에 version이 있어야 시작할수 있음
	//WinSock을 시작하는 곳
	int wsOk = WSAStartup(version, &data);
	if(wsOk != 0) //WinSock이 알여렸으면 나가주는 곳!!!
		return;
	//서버와 연결하는 단계
	//서버에 대한 hint structure 만들기
	sockaddr_in server;
	server.sin_family = AF_INET; //AF_INET =IPv4 address 를 쓰겠다고 해주는거
	server.sin_port = htons(54000); //포트 지정
	PCSTR ip = "192.168.43.255";
	inet_pton(AF_INET, ip, &server.sin_addr);//string을 byte array로 변환 해주는 방법

	//Socket만들기 :Socket의 형은 datagram
	SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);
	//Socket에 string보내는 법 -> 그러면 기다리는 애한테 날라감
	string s = inviter + " " + receiver;
	int sendOk = sendto(out, s.c_str(), s.size() + 1, 0, (sockaddr*) &server, sizeof(server));
	if(sendOk == SOCKET_ERROR)
	{
	}
	//소켓을 닫는다
	closesocket(out);
	//close down Winsock
	WSACleanup();
}

void Request::WaitForInvite()
{
	WSADATA data;
	WORD version = MAKEWORD(2, 2);
	int wsOk = WSAStartup(version, &data);
	if(wsOk != 0)
	{
		return;
	}
	SOCKET in = socket(AF_INET, SOCK_DGRAM, 0);
	sockaddr_in serverHint;
	serverHint.sin_addr.S_un.S_addr = ADDR_ANY; // Us any IP address available on the machine
	serverHint.sin_family = AF_INET; // Address format is IPv4
	serverHint.sin_port = htons(54000); // Convert from little to big endian
	if(bind(in, (sockaddr*) &serverHint, sizeof(serverHint)) == SOCKET_ERROR)
	{
		return;
	}
	sockaddr_in client; // Use to hold the client information (port / ip address)
	int clientLength = sizeof(client); // The size of the client information
	char buf[1024];
	while(true)
	{
		ZeroMemory(&client, clientLength); // Clear the client structure
		ZeroMemory(buf, 1024); // Clear the receive buffer

		// Wait for message
		int bytesIn = recvfrom(in, buf, 1024, 0, (sockaddr*) &client, &clientLength);
		//잘 받아졌는지 확인하는 단계
		if(bytesIn == SOCKET_ERROR)
		{
		}
		// Display message and client info
		char clientIp[256]; // Create enough space to convert the address byte array
		ZeroMemory(clientIp, 256); // to string of characters

		// Convert from byte array to chars
		inet_ntop(AF_INET, &client.sin_addr, clientIp, 256);
	}
}

void Request::SendMessageRequest(string ip, string message)
{
	WSADATA data;
	WORD version = MAKEWORD(2, 2);
	int wsOk = WSAStartup(version, &data);
	if (wsOk != 0)
		return;
	sockaddr_in server;
	server.sin_family = AF_INET; //AF_INET =IPv4 address 를 쓰겠다고 해주는거
	server.sin_port = htons(54000); //포트 지정
	PCSTR pcstrIP = ip.c_str();
	inet_pton(AF_INET, pcstrIP, &server.sin_addr);
	SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);
	//sends message
	int sendOk = sendto(out, message.c_str(), message.size() + 1, 0, (sockaddr*)&server, sizeof(server));
	if (sendOk == SOCKET_ERROR)
	{
	}
	//소켓을 닫는다
	closesocket(out);
	//close down Winsock
	WSACleanup();
}
