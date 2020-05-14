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

void Request::SendRequestToAnyone()
{
	WSADATA data; //WSAStartup()을 시작하기 위해 필요한 파일
	WORD version = MAKEWORD(2, 2); //WSAStartup에 version이 있어야 시작할수 있음
	//WinSock을 시작하는 곳
	int wsOk = WSAStartup(version, &data);
	if (wsOk != 0) //WinSock이 알여렸으면 나가주는 곳!!!
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
	string s = "";
	int sendOk = sendto(out, s.c_str(), s.size() + 1, 0, (sockaddr*)&server, sizeof(server));
	if (sendOk == SOCKET_ERROR)
	{
	}
	//소켓을 닫는다
	closesocket(out);
	//close down Winsock
	WSACleanup();
}

void Request::SendRequestByName(string name)
{
	WSADATA data; //WSAStartup()을 시작하기 위해 필요한 파일
	WORD version = MAKEWORD(2, 2); //WSAStartup에 version이 있어야 시작할수 있음
	//WinSock을 시작하는 곳
	int wsOk = WSAStartup(version, &data);
	if (wsOk != 0) //WinSock이 알여렸으면 나가주는 곳!!!
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
	string s = name;
	int sendOk = sendto(out, s.c_str(), s.size() + 1, 0, (sockaddr*)&server, sizeof(server));
	if (sendOk == SOCKET_ERROR)
	{
	}
	//소켓을 닫는다
	closesocket(out);
	//close down Winsock
	WSACleanup();
}
