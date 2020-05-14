#pragma once

// InvitationDialog 대화 상자

class InvitationDialog : public CDialogEx
{
	DECLARE_DYNAMIC(InvitationDialog)

public:
	InvitationDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~InvitationDialog();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_InvitationDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
