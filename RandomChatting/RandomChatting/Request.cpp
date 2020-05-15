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
	WSADATA data; //WSAStartup()�� �����ϱ� ���� �ʿ��� ����
	WORD version = MAKEWORD(2, 2); //WSAStartup�� version�� �־�� �����Ҽ� ����
	//WinSock�� �����ϴ� ��
	int wsOk = WSAStartup(version, &data);
	if(wsOk != 0) //WinSock�� �˿������� �����ִ� ��!!!
		return;
	//������ �����ϴ� �ܰ�
	//������ ���� hint structure �����
	sockaddr_in server;
	server.sin_family = AF_INET; //AF_INET =IPv4 address �� ���ڴٰ� ���ִ°�
	server.sin_port = htons(54000); //��Ʈ ����
	PCSTR ip = "192.168.43.255"; //�������ִ� ip //������
	inet_pton(AF_INET, ip, &server.sin_addr);//string�� byte array�� ��ȯ ���ִ� ���

	//Socket����� :Socket�� ���� datagram
	SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);
	//Socket�� string������ �� -> �׷��� ��ٸ��� ������ ����
	string s = inviter;
	int sendOk = sendto(out, s.c_str(), s.size() + 1, 0, (sockaddr*) &server, sizeof(server));
	if(sendOk == SOCKET_ERROR)
	{
	}
	//������ �ݴ´�
	closesocket(out);
	//close down Winsock
	WSACleanup();
}

void Request::SendRequestByName(string inviter,string receiver)
{
	WSADATA data; //WSAStartup()�� �����ϱ� ���� �ʿ��� ����
	WORD version = MAKEWORD(2, 2); //WSAStartup�� version�� �־�� �����Ҽ� ����
	//WinSock�� �����ϴ� ��
	int wsOk = WSAStartup(version, &data);
	if(wsOk != 0) //WinSock�� �˿������� �����ִ� ��!!!
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
	string s = inviter + " " + receiver;
	int sendOk = sendto(out, s.c_str(), s.size() + 1, 0, (sockaddr*) &server, sizeof(server));
	if(sendOk == SOCKET_ERROR)
	{
	}
	//������ �ݴ´�
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
		//�� �޾������� Ȯ���ϴ� �ܰ�
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
	server.sin_family = AF_INET; //AF_INET =IPv4 address �� ���ڴٰ� ���ִ°�
	server.sin_port = htons(54000); //��Ʈ ����
	PCSTR pcstrIP = ip.c_str();
	inet_pton(AF_INET, pcstrIP, &server.sin_addr);
	SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);
	//sends message
	int sendOk = sendto(out, message.c_str(), message.size() + 1, 0, (sockaddr*)&server, sizeof(server));
	if (sendOk == SOCKET_ERROR)
	{
	}
	//������ �ݴ´�
	closesocket(out);
	//close down Winsock
	WSACleanup();
}
