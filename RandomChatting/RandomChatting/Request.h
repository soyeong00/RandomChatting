#pragma once
#include <iostream>
using namespace std;
class Request
{
public:
	Request();
	~Request();
	//초대를 기다리는 펑션 returns the ip주소 of inviter
	void SendRequestToAnyone(); //아무한테나 초대하기
	void SendRequestByName(string name); //이름을 같이 넘겨주는 방법
	//void WaitForRequest();	// 메인화면으로 넘어가자마자 시작 될, 초대를 기다리는 기능

};