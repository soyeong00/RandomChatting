// DialogCommunicationExample1.cpp: 구현 파일
//

#include "pch.h"
#include "RandomChatting.h"
#include "DialogCommunicationExample1.h"
#include "afxdialogex.h"

// DialogCommunicationExample1 대화 상자

IMPLEMENT_DYNAMIC(DialogCommunicationExample1, CDialogEx)

DialogCommunicationExample1::DialogCommunicationExample1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DialogCommunicationExample1, pParent)
{
}

DialogCommunicationExample1::~DialogCommunicationExample1()
{
}

void DialogCommunicationExample1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(DialogCommunicationExample1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DialogCommunicationExample1::OnBnClickedButton1)
END_MESSAGE_MAP()

// DialogCommunicationExample1 메시지 처리기

#include "DialogCommunicationExample2.h"
void DialogCommunicationExample1::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	Dialog2->m_edit.SetWindowTextW(L"클릭");
}