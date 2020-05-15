#pragma once


// ServerDialog 대화 상자

class ServerDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ServerDialog)

public:
	ServerDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ServerDialog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ServerDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
