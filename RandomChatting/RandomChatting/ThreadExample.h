#pragma once

// ThreadExample 대화 상자

#define MESSAGE_INCREASE_COUNT WM_USER

class ThreadExample : public CDialogEx
{
	DECLARE_DYNAMIC(ThreadExample)

public:
	ThreadExample(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ThreadExample();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ThreadExample };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	afx_msg void OnBnClickedButton1();

public:
	CWinThread* m_Thread;
	bool IsWorkingThread;
	int m_Count;
	LRESULT UpdateCount(WPARAM wParam, LPARAM lParam);
};
