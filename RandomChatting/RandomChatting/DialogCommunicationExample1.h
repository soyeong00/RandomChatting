#pragma once

// DialogCommunicationExample1 대화 상자
#include "DialogCommunicationExample2.h"

class DialogCommunicationExample1 : public CDialogEx
{
	DECLARE_DYNAMIC(DialogCommunicationExample1)

public:
	DialogCommunicationExample1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DialogCommunicationExample1();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DialogCommunicationExample1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();

public:
	class DialogCommunicationExample2* Dialog2;
};
