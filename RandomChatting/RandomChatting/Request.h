#pragma once
#include <iostream>
using namespace std;
class Request
{
public:
	Request();
	~Request();
	//�ʴ븦 ��ٸ��� ��� returns the ip�ּ� of inviter
	void SendRequestToAnyone(); //�ƹ����׳� �ʴ��ϱ�
	void SendRequestByName(string name); //�̸��� ���� �Ѱ��ִ� ���
	//void WaitForRequest();	// ����ȭ������ �Ѿ�ڸ��� ���� ��, �ʴ븦 ��ٸ��� ���

};