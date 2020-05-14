// ThreadExample.cpp: 구현 파일
//

#include "pch.h"
#include "RandomChatting.h"
#include "ThreadExample.h"
#include "afxdialogex.h"

// ThreadExample 대화 상자

IMPLEMENT_DYNAMIC(ThreadExample, CDialogEx)

ThreadExample::ThreadExample(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ThreadExample, pParent)
{
}

ThreadExample::~ThreadExample()
{
}

void ThreadExample::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(ThreadExample, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ThreadExample::OnBnClickedButton1)

	// 작성 필요
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(MESSAGE_INCREASE_COUNT, &ThreadExample::UpdateCount)
END_MESSAGE_MAP()

UINT ThreadForCounting(LPVOID param)
{
	ThreadExample* Main = (ThreadExample*) param;

	while(Main->IsWorkingThread)
	{
		Sleep(30);

		PostMessage(Main->m_hWnd, MESSAGE_INCREASE_COUNT, NULL, NULL);
	}

	return 0;
}
// ThreadExample 메시지 처리기

void ThreadExample::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString caption;
	GetDlgItemText(IDC_BUTTON1, caption);

	if(caption == _T("Start"))
	{
		IsWorkingThread = true;
		m_Thread = AfxBeginThread(ThreadForCounting, this);

		SetDlgItemText(IDC_BUTTON1, _T("Stop"));
	}
	else
	{
		IsWorkingThread = false;

		WaitForSingleObject(m_Thread->m_hThread, 5000);

		SetDlgItemText(IDC_BUTTON1, _T("Start"));
	}
}

LRESULT ThreadExample::UpdateCount(WPARAM wParam, LPARAM lParam)
{
	CString text;
	text.Format(_T("%d"), m_Count++);

	SetDlgItemText(IDC_STATIC, text);

	return 0;
}