#pragma once

// MainDialog 대화 상자
#include "InvitationDialog.h"

#define MESSAGE_RANDOM_CHAT WM_USER

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
	void SetName(CString* str);

	void ReceiveRequest();

	class InvitationDialog* invDialog;

private:
	CString mGuest;
public:
	afx_msg void OnBnClickedButton1();
	CEdit m_edit;
};
