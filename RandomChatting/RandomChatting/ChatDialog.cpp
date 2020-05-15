// ChatDialog.cpp: 구현 파일
//

#include "pch.h"
#include "RandomChatting.h"
#include "ChatDialog.h"
#include "afxdialogex.h"
#include <sstream>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

// ChatDialog 대화 상자

IMPLEMENT_DYNAMIC(ChatDialog, CDialogEx)

ChatDialog::ChatDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChatDialog, pParent)//, myName(nullptr), yourName(nullptr)
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
	ON_MESSAGE(MESSAGE_CHAT_RECEIVED, &ChatDialog::UpdateChat)
	ON_BN_CLICKED(IDC_BUTTON2, &ChatDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &ChatDialog::OnBnClickedButton1)
END_MESSAGE_MAP()

// ChatDialog 메시지 처리기

void ChatDialog::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SendMsg();
}

LRESULT ChatDialog::UpdateChat(WPARAM wParam, LPARAM lParam)
{
	ReceiveMsg();
	return 0;
}

UINT ThreadForWaitingMessage(LPVOID param)
{
	WSADATA data;
	WORD version = MAKEWORD(2, 2);
	int wsOk = WSAStartup(version, &data);
	if (wsOk != 0)
	{
		return 0;
	}
	SOCKET in = socket(AF_INET, SOCK_DGRAM, 0);
	sockaddr_in serverHint;
	serverHint.sin_addr.S_un.S_addr = ADDR_ANY; // Us any IP address available on the machine
	serverHint.sin_family = AF_INET; // Address format is IPv4
	serverHint.sin_port = htons(54000); // Convert from little to big endian
	if (bind(in, (sockaddr*)&serverHint, sizeof(serverHint)) == SOCKET_ERROR)
	{
		return 0;
	}
	sockaddr_in client; // Use to hold the client information (port / ip address)
	int clientLength = sizeof(client); // The size of the client information
	char buf[1024];
	ChatDialog* chat = (ChatDialog*)param;
	while (chat->m_IsChatting)
	{
		ZeroMemory(&client, clientLength); // Clear the client structure
		ZeroMemory(buf, 1024); // Clear the receive buffer

		// Wait for message
		int bytesIn = recvfrom(in, buf, 1024, 0, (sockaddr*)&client, &clientLength);

		if (bytesIn == SOCKET_ERROR)
		{
		}
		// Display message and client info
		char clientIp[256]; // Create enough space to convert the address byte array
		ZeroMemory(clientIp, 256); // to string of characters
		//=============종은추가코드============//
		string sBuf = string(buf);
		stringstream ssBuf(sBuf);
		// Convert from byte array to chars
		inet_ntop(AF_INET, &client.sin_addr, clientIp, 256);
		//받아온 ip가 chattingIP인지 확인
		if (chat->chattingIP.Compare((CString)clientIp) == 0)
			chat->receivedChat = (CString)buf;
		PostMessage(chat->m_hWnd, MESSAGE_CHAT_RECEIVED, NULL, NULL);
	}
	//소켓을 닫는다
	closesocket(in);
	//close down Winsock
	WSACleanup();
	return 0;
}


BOOL ChatDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	req = new Request();



	myName = *main->mName;
	SetDlgItemText(IDC_STATIC_MYNAME, myName + " 님");

	yourName = *main->invitingName;
	SetDlgItemText(IDC_STATIC_YOURNAME, yourName);

	m_IsChatting = true;
	m_Thread = AfxBeginThread(ThreadForWaitingMessage, this);
	CT2CA pszConvertedAnsiString(chattingIP);
	std::string ipString(pszConvertedAnsiString);
	req->SendMessageRequest(ipString, "+");

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
	if(&myName != nullptr)
	{
		strEdit->Append(myName);
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
	if(&yourName != nullptr)
	{
		strEdit->Append(yourName);
	}
	cs = string(" : ").c_str();
	strEdit->Append(cs);

	CString* strReceive = &this->receivedChat; //---> 받아온 값으로 초기화 필요
	strEdit->Append(*strReceive);
	m_edit.SetWindowText(*strEdit);
}



void ChatDialog::DisplayMessage(string name, string message)
{
}

void ChatDialog::OnBnClickedButton1()
{
	m_IsChatting = false;
	WaitForSingleObject(m_Thread->m_hThread, 0);
	OnDestroy();
	OnOK();

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}