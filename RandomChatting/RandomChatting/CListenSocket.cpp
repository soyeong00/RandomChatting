// CListenSocket.cpp: 구현 파일
//

#include "pch.h"
#include "RandomChatting.h"
#include "CClientSocket.h"
#include "CListenSocket.h"
#include "ChatDialog.h"
// CListenSocket

CListenSocket::CListenSocket()
{
}

CListenSocket::~CListenSocket()
{
}

void CListenSocket::OnAccept(int nErrorCode) // 사용자가 추가되었을때
{
}

void CListenSocket::CloseClientSocket(CSocket* pClient) // Client 접속이 끊겼을때
{
}

void CListenSocket::SendAllMessage(TCHAR* pszMessage) // Client가 보낸 메시지가 있을 때
{
}

// CListenSocket 멤버 함수