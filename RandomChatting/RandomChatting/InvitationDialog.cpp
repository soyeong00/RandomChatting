// InvitationDialog.cpp: 구현 파일
//

#include "pch.h"
#include "RandomChatting.h"
#include "InvitationDialog.h"
#include "afxdialogex.h"

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
	CDialogEx::OnOK();
}

void InvitationDialog::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}

void InvitationDialog::SetText(CString* Name)
{
	CString* str = Name;
	str->Append(*text);
	m_text = *str;
}