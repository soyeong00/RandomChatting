#pragma once

// DialogCommunicationExample2 대화 상자
#include "DialogCommunicationExample1.h"

class DialogCommunicationExample2 : public CDialogEx
{
	DECLARE_DYNAMIC(DialogCommunicationExample2)

public:
	DialogCommunicationExample2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DialogCommunicationExample2();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DialogCommunicationExample2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	CEdit m_edit;

	class DialogCommunicationExample1* Dialog1;
	CEdit ChattingBoard;
	CEdit ChattingView;
//	afx_msg void OnBnClickedButton2();
//	afx_msg void OnBnClickedButton1();


	afx_msg void OnBnClickedSendButton();
	afx_msg void OnBnClickedCloseButton();
	//void ConsistentText();
};
