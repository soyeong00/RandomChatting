// ChatDialog.cpp: 구현 파일
//

#include "pch.h"
#include "RandomChatting.h"
#include "ChatDialog.h"
#include "afxdialogex.h"

// ChatDialog 대화 상자

IMPLEMENT_DYNAMIC(ChatDialog, CDialogEx)

ChatDialog::ChatDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChatDialog, pParent), myName(nullptr), yourName(nullptr), req(nullptr)
{
}

ChatDialog::ChatDialog(CWnd* pParent, MainDialog* main)
	: ChatDialog(pParent)
{
	this->main = main;
}

ChatDialog::~ChatDialog()
{
}

void ChatDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_INPUT, m_input);
}

BEGIN_MESSAGE_MAP(ChatDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &ChatDialog::OnBnClickedButton2)
END_MESSAGE_MAP()

// ChatDialog 메시지 처리기

void ChatDialog::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SendMsg();
}

BOOL ChatDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	req = new Request();

	myName = main->mName;
	SetDlgItemText(IDC_STATIC_MYNAME, *myName + " 님");

	yourName = &main->invitingName;
	SetDlgItemText(IDC_STATIC_YOURNAME, *yourName);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void ChatDialog::SendMsg()
{
	CString* strEdit = new CString();
	m_edit.GetWindowText(*strEdit);

	CString* strInput = new CString();
	m_input.GetWindowText(*strInput);

	CT2CA pszConvertedAnsiString(*strInput);
	std::string inputString(pszConvertedAnsiString);

	m_input.SetWindowText(L"");

	CString cs(string("\r\n").c_str());
	strEdit->Append(cs);
	if(myName != nullptr)
	{
		strEdit->Append(*myName);
	}
	cs = string(" : ").c_str();
	strEdit->Append(cs);
	strEdit->Append(*strInput);
	m_edit.SetWindowText(*strEdit);

	if(!main->ip.IsEmpty())
	{
		*pszConvertedAnsiString = *main->ip;
		std::string ipString(pszConvertedAnsiString);

		req->SendMessageRequest(ipString, inputString);
	}
}

void ChatDialog::ReceiveMsg()
{
	CString* strEdit = new CString();
	m_edit.GetWindowText(*strEdit);

	CString cs(string("\r\n").c_str());
	strEdit->Append(cs);
	if(yourName != nullptr)
	{
		strEdit->Append(*yourName);
	}
	cs = string(" : ").c_str();
	strEdit->Append(cs);

	CString* strReceive = new CString(); //---> 받아온 값으로 초기화 필요
	strEdit->Append(*strReceive);

	m_edit.SetWindowText(*strEdit);
}

void ChatDialog::DisplayMessage(string name, string message)
{
}