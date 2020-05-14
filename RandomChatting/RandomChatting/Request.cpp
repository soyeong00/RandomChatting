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
	WSADATA data; //WSAStartup()�� �����ϱ� ���� �ʿ��� ����
	WORD version = MAKEWORD(2, 2); //WSAStartup�� version�� �־�� �����Ҽ� ����
	//WinSock�� �����ϴ� ��
	int wsOk = WSAStartup(version, &data);
	if (wsOk != 0) //WinSock�� �˿������� �����ִ� ��!!!
		return;
	//������ �����ϴ� �ܰ�
	//������ ���� hint structure �����
	sockaddr_in server;
	server.sin_family = AF_INET; //AF_INET =IPv4 address �� ���ڴٰ� ���ִ°�
	server.sin_port = htons(54000); //��Ʈ ����
	PCSTR ip = "192.168.43.255";
	inet_pton(AF_INET, ip, &server.sin_addr);//string�� byte array�� ��ȯ ���ִ� ���

	//Socket����� :Socket�� ���� datagram
	SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);
	//Socket�� string������ �� -> �׷��� ��ٸ��� ������ ����
	string s = "";
	int sendOk = sendto(out, s.c_str(), s.size() + 1, 0, (sockaddr*)&server, sizeof(server));
	if (sendOk == SOCKET_ERROR)
	{
	}
	//������ �ݴ´�
	closesocket(out);
	//close down Winsock
	WSACleanup();
}

void Request::SendRequestByName(string name)
{
	WSADATA data; //WSAStartup()�� �����ϱ� ���� �ʿ��� ����
	WORD version = MAKEWORD(2, 2); //WSAStartup�� version�� �־�� �����Ҽ� ����
	//WinSock�� �����ϴ� ��
	int wsOk = WSAStartup(version, &data);
	if (wsOk != 0) //WinSock�� �˿������� �����ִ� ��!!!
		return;
	//������ �����ϴ� �ܰ�
	//������ ���� hint structure �����
	sockaddr_in server;
	server.sin_family = AF_INET; //AF_INET =IPv4 address �� ���ڴٰ� ���ִ°�
	server.sin_port = htons(54000); //��Ʈ ����
	PCSTR ip = "192.168.43.255";
	inet_pton(AF_INET, ip, &server.sin_addr);//string�� byte array�� ��ȯ ���ִ� ���

	//Socket����� :Socket�� ���� datagram
	SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);
	//Socket�� string������ �� -> �׷��� ��ٸ��� ������ ����
	string s = name;
	int sendOk = sendto(out, s.c_str(), s.size() + 1, 0, (sockaddr*)&server, sizeof(server));
	if (sendOk == SOCKET_ERROR)
	{
	}
	//������ �ݴ´�
	closesocket(out);
	//close down Winsock
	WSACleanup();
}
