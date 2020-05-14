// ChatDialog.cpp: 구현 파일
//

#include "pch.h"
#include "RandomChatting.h"
#include "ChatDialog.h"
#include "afxdialogex.h"


// ChatDialog 대화 상자

IMPLEMENT_DYNAMIC(ChatDialog, CDialogEx)

ChatDialog::ChatDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChatDialog, pParent)
{

}

ChatDialog::~ChatDialog()
{
}

void ChatDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ChatDialog, CDialogEx)
END_MESSAGE_MAP()


// ChatDialog 메시지 처리기
