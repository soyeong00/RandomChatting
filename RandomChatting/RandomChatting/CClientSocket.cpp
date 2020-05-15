// CClientSocket.cpp: 구현 파일
//

#include "pch.h"
#include "RandomChatting.h"
#include "CClientSocket.h"
#include "CListenSocket.h"
#include "ChatDialog.h"

// CClientSocket
// CClientSocket
int index = 0;
CString alias[100][2];

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}

// CClientSocket 멤버 함수
void CClientSocket::SetListenSocket(CAsyncSocket* pSocket) // 새로 접속한 소켓 값을 넣는다
{
}
// CClientSocket 멤버 함수

void CClientSocket::OnClose(int nErrorCode) // 연결이 종료되었을때 소켓을 닫는다
{
}

void CClientSocket::OnReceive(int nErrorCode) // 소켓에 데이터가 들어왔을 때
{
}

// CClientSocket 멤버 함수