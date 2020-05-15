#pragma once

// ChatDialog 대화 상자
#include "Request.h"
#include "MainDialog.h"

#define MESSAGE_CHAT_RECEIVED 8405

class ChatDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ChatDialog)

public:
	ChatDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	ChatDialog(CWnd* pParent, MainDialog* main);
	virtual ~ChatDialog();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ChatDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	/////////////종은추가코드/////////////////////
	CString chattingIP;
	bool m_IsChatting;
	CWinThread* m_Thread;


	///////////////종은추가코드////////////////////
	CString myName;
	CString yourName;
	
	afx_msg void OnBnClickedButton2();

	CEdit m_edit;
	CEdit m_input;
	CString ip;
	CString receivedChat;
	Request* req;
	class MainDialog* main;
	LRESULT UpdateChat(WPARAM wParam, LPARAM lParam);
	virtual BOOL OnInitDialog();

	void SendMsg();
	void ReceiveMsg();
	void DisplayMessage(string name, string message);
	afx_msg void OnBnClickedButton1();
};
