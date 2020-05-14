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
{

}

MainDialog::~MainDialog()
{
}

void MainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MainDialog, CDialogEx)
END_MESSAGE_MAP()


// MainDialog 메시지 처리기
