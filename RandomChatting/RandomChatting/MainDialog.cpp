// MainDialog.cpp: 구현 파일
//
#include "pch.h"
#include "RandomChatting.h"
#include "MainDialog.h"
#include "afxdialogex.h"
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

// MainDialog 대화 상자

IMPLEMENT_DYNAMIC(MainDialog, CDialogEx)

MainDialog::MainDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MainDialog, pParent)
	, mGuest(_T(""))
	, invDialog(nullptr)
{
}

MainDialog::~MainDialog()
{
}

void MainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_GUEST, mGuest);
}

BEGIN_MESSAGE_MAP(MainDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDialog::OnBnClickedButton2)
	ON_MESSAGE(MESSAGE_RANDOM_CHAT, &MainDialog::UpdateIp)
END_MESSAGE_MAP()

UINT ThreadForWaiting(LPVOID param)
{
	WSADATA data;
	WORD version = MAKEWORD(2, 2);
	int wsOk = WSAStartup(version, &data);
	if(wsOk != 0)
	{
		return 0;
	}
	SOCKET in = socket(AF_INET, SOCK_DGRAM, 0);
	sockaddr_in serverHint;
	serverHint.sin_addr.S_un.S_addr = ADDR_ANY; // Us any IP address available on the machine
	serverHint.sin_family = AF_INET; // Address format is IPv4
	serverHint.sin_port = htons(54000); // Convert from little to big endian
	if(bind(in, (sockaddr*) &serverHint, sizeof(serverHint)) == SOCKET_ERROR)
	{
		return 0;
	}
	sockaddr_in client; // Use to hold the client information (port / ip address)
	int clientLength = sizeof(client); // The size of the client information
	char buf[1024];
	MainDialog* main = (MainDialog*) param;
	//while (main->m_IsWorkingThread)
	//{
	ZeroMemory(&client, clientLength); // Clear the client structure
	ZeroMemory(buf, 1024); // Clear the receive buffer

	// Wait for message
	int bytesIn = recvfrom(in, buf, 1024, 0, (sockaddr*) &client, &clientLength);

	if(bytesIn == SOCKET_ERROR)
	{
	}
	// Display message and client info
	char clientIp[256]; // Create enough space to convert the address byte array
	ZeroMemory(clientIp, 256); // to string of characters

	// Convert from byte array to chars
	inet_ntop(AF_INET, &client.sin_addr, clientIp, 256);
	main->ip = clientIp;
	PostMessage(main->m_hWnd, MESSAGE_RANDOM_CHAT, NULL, NULL);
	//}
	return 0;
}

// MainDialog 메시지 처리기
void MainDialog::OnBnClickedButton2()
{
	CString caption;
	GetDlgItemText(IDC_BUTTON2, caption);

	if(caption == _T("검색 시작"))
	{
		m_IsWorkingThread = true;

		m_Thread = AfxBeginThread(ThreadForWaiting, this);

		SetDlgItemText(IDC_BUTTON2, _T("검색 중지"));
	}
	else
	{
		m_IsWorkingThread = false;

		WaitForSingleObject(m_Thread->m_hThread, 5000);

		SetDlgItemText(IDC_BUTTON2, _T("검색 시작"));
	}
}

LRESULT MainDialog::UpdateIp(WPARAM wParam, LPARAM lParam)
{
	//CString text = (CString)"Got an Invite";
	SetDlgItemText(IDC_STATIC_COUNT, this->ip);
	return 0;
}

void MainDialog::SetName(CString* str)
{
	mName = str;

	CString newString = *str;
	newString.Append(CString(" 님"));

	mGuest = newString;
}

void MainDialog::ReceiveRequest()
{
	if(invDialog == nullptr)
	{
		invDialog = new InvitationDialog();
	}

	if(invDialog != nullptr)
	{
		// 들어가는 내용 변경
		invDialog->SetText(&ip);
		invDialog->DoModal();
	}
}