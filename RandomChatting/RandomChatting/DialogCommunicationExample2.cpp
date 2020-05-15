// DialogCommunicationExample2.cpp: 구현 파일
//

#include "pch.h"
#include "RandomChatting.h"
#include "DialogCommunicationExample2.h"
#include "afxdialogex.h"

// DialogCommunicationExample2 대화 상자

IMPLEMENT_DYNAMIC(DialogCommunicationExample2, CDialogEx)

DialogCommunicationExample2::DialogCommunicationExample2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DialogCommunicationExample2, pParent)
{
}

DialogCommunicationExample2::~DialogCommunicationExample2()
{
}

void DialogCommunicationExample2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, m_edit);
	//DDX_Control(pDX, IDC_EDIT2, ChattingBoard);
	//DDX_Control(pDX, IDC_EDIT1, ChattingView);
}

BEGIN_MESSAGE_MAP(DialogCommunicationExample2, CDialogEx)
	//ON_BN_CLICKED(IDC_BUTTON1, &DialogCommunicationExample2::OnBnClickedSendButton)
	//ON_BN_CLICKED(IDCANCEL, &DialogCommunicationExample2::OnBnClickedCloseButton)
END_MESSAGE_MAP()

// DialogCommunicationExample2 메시지 처리기

void DialogCommunicationExample2::OnBnClickedSendButton()
{
	CString ChatBufUp;
	CString ChatBufDown;

	ChattingBoard.GetWindowText(ChatBufDown);
	ChattingView.GetWindowText(ChatBufUp);

	ChattingView.SetWindowText(ChatBufUp + "\r\n" + ChatBufDown);
	ChattingBoard.SetWindowText((LPCTSTR) "");
}

void DialogCommunicationExample2::OnBnClickedCloseButton()
{
	closesocket(Dialog1->hSocket);
	WSACleanup();
	CDialogEx::OnCancel();
}