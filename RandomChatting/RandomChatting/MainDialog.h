#pragma once

// MainDialog 대화 상자
#include "InvitationDialog.h"

#define MESSAGE_RANDOM_CHAT 9298

class MainDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MainDialog)

public:
	MainDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~MainDialog();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MainDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
public:
	CWinThread* m_Thread;
	bool m_IsWorkingThread;
	CString ip;
	LRESULT UpdateIp(WPARAM wParam, LPARAM lParam);
	CString* mName;
	//=============종은추가코드============//
	CString invitingName;
	CString wantingName;
	bool m_IsChatting;
	//CString chattingIP;
	//LRESULT UpdateChat(WPARAM wParam, LPARAM lParam);

	//=============종은추가코드============//
	void SetName(CString* str);
	void runThread();
	void ReceiveRequest();
	class InvitationDialog* invDialog;

private:
	CString mGuest;
public:
	afx_msg void OnBnClickedButton1();
	CEdit m_edit;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();

	void goToChat();
};
