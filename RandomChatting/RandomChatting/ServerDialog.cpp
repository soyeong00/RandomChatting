// ServerDialog.cpp: 구현 파일
//

#include "pch.h"
#include "RandomChatting.h"
#include "ServerDialog.h"
#include "afxdialogex.h"


// ServerDialog 대화 상자

IMPLEMENT_DYNAMIC(ServerDialog, CDialogEx)

ServerDialog::ServerDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ServerDialog, pParent)
{

}

ServerDialog::~ServerDialog()
{
}

void ServerDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ServerDialog, CDialogEx)
END_MESSAGE_MAP()


// ServerDialog 메시지 처리기
