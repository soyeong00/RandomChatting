// MainDialog.cpp: 구현 파일
//

#include "pch.h"
#include "RandomChatting.h"
#include "MainDialog.h"
#include "afxdialogex.h"

// MainDialog 대화 상자

IMPLEMENT_DYNAMIC(MainDialog, CDialogEx)

MainDialog::MainDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MainDialog, pParent)
	, mGuest(_T(""))
{
	m_Count = 0;
}

MainDialog::~MainDialog()
{
}

void MainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_GUEST, mGuest);
}

BEGIN_MESSAGE_MAP(MainDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDialog::OnBnClickedButton2)
	ON_WM_TIMER()
	ON_MESSAGE(MESSAGE_RANDOM_CHAT, &MainDialog::UpdateCount)
END_MESSAGE_MAP()

UINT ThreadForCounting(LPVOID param)
{
	MainDialog* main = (MainDialog*) param;

	while(main->m_IsWorkingThread)
	{
		Sleep(100);

		PostMessage(main->m_hWnd, MESSAGE_RANDOM_CHAT, NULL, NULL);
	}

	return 0;
}

// MainDialog 메시지 처리기
void MainDialog::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//SetTimer(1, 1000/*freq*/, 0);
	CString caption;
	GetDlgItemText(IDC_BUTTON2, caption);

	if(caption == _T("검색 시작"))
	{
		m_IsWorkingThread = true;

		m_Thread = AfxBeginThread(ThreadForCounting, this);

		SetDlgItemText(IDC_BUTTON2, _T("검색 중지"));
	}
	else
	{
		m_IsWorkingThread = false;

		WaitForSingleObject(m_Thread->m_hThread, 5000);

		SetDlgItemText(IDC_BUTTON2, _T("검색 시작"));
	}
}

LRESULT MainDialog::UpdateCount(WPARAM wParam, LPARAM lParam)
{
	CString text;
	text.Format(_T("%d"), m_Count++);

	SetDlgItemText(IDC_STATIC_COUNT, text);

	return 0;
}

void MainDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnTimer(nIDEvent);

	/*if(1)
	{
		KillTimer(1);
	}*/
}