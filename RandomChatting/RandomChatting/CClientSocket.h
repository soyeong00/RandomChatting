#pragma once

// CClientSocket 명령 대상

#include <afxsock.h>

class CClientSocket : public CAsyncSocket
{
public:
	CClientSocket();
	virtual ~CClientSocket();

	void SetListenSocket(CAsyncSocket* pSocket);
	void OnClose(int nErrorCode);
	void OnReceive(int nErrorCode);
};
