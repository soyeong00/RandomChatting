#pragma once
#include <iostream>
#include "MainDialog.h"
using namespace std;
class Request
{
public:
	Request();
	~Request();
	//초대를 기다리는 펑션 returns the ip주소 of inviter
	void SendRequestToAnyone(string name); //아무한테나 초대하기
	void SendRequestByName(string inviter, string receiver); //이름을 같이 넘겨주는 방법
	void WaitForInvite();
	void SendMessageRequest(string ip, string message);
};
