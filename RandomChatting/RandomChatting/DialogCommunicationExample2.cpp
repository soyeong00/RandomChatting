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
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BEGIN_MESSAGE_MAP(DialogCommunicationExample2, CDialogEx)
END_MESSAGE_MAP()

// DialogCommunicationExample2 메시지 처리기