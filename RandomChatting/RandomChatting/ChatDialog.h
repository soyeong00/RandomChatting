#pragma once

// ChatDialog 대화 상자
#include "Request.h"

class ChatDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ChatDialog)

public:
	ChatDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ChatDialog();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ChatDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CString* myName;
	CString* yourName;
	afx_msg void OnBnClickedButton2();

	CEdit m_edit;
	CEdit m_input;

	Request* req;
	virtual BOOL OnInitDialog();

	void SendMsg();
	void ReceiveMsg();
};
