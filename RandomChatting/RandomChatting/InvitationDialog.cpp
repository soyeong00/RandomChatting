// InvitationDialog.cpp: 구현 파일
//

#include "pch.h"
#include "RandomChatting.h"
#include "InvitationDialog.h"
#include "afxdialogex.h"
#include "ChatDialog.h"

// InvitationDialog 대화 상자

IMPLEMENT_DYNAMIC(InvitationDialog, CDialogEx)

InvitationDialog::InvitationDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_InvitationDialog, pParent)
	, m_text(_T(""))
{
}

InvitationDialog::~InvitationDialog()
{
}

void InvitationDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_STATIC_INV, m_static);
	DDX_Text(pDX, IDC_STATIC_INV, m_text);
}

BEGIN_MESSAGE_MAP(InvitationDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &InvitationDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &InvitationDialog::OnBnClickedCancel)
END_MESSAGE_MAP()

// InvitationDialog 메시지 처리기

void InvitationDialog::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//
	ChatDialog* chat = new ChatDialog(this, main);
	chat->DoModal();
	chat->main = this->main;
	chat->myName = *(this->main->mName);
	chat->yourName = this->main->invitingName;
	CDialogEx::OnOK();
}

void InvitationDialog::OnBnClickedCancel()
{
	main->runThread();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}

void InvitationDialog::SetText(CString* Name)
{
	// 상대방 이름 값 저장
	yourName = Name;

	// 메시지 텍스트 값 설정
	CString* str = Name;
	str->Append(*text);
	m_text = *str;
}