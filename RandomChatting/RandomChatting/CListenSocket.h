#pragma once

// CListenSocket 명령 대상
#include <afxsock.h>

class CListenSocket : public CAsyncSocket
{
public:
	CListenSocket();
	virtual ~CListenSocket();

	CPtrList m_ptrClientSocketList;
	void OnAccept(int eErrorCode);
	void CloseClientSocket(CSocket* pClient);
	void SendAllMessage(TCHAR* pszMessage);
};
