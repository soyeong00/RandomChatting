#pragma once
#include <iostream>
#include "MainDialog.h"
using namespace std;
class Request
{
public:
	Request();
	~Request();
	//�ʴ븦 ��ٸ��� ��� returns the ip�ּ� of inviter
	void SendRequestToAnyone(string name); //�ƹ����׳� �ʴ��ϱ�
	void SendRequestByName(string inviter, string receiver); //�̸��� ���� �Ѱ��ִ� ���
	void WaitForInvite();
	void SendMessageRequest(string ip, string message);
};
