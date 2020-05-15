// MainDialog.cpp: 구현 파일
//
#include "pch.h"
#include "RandomChatting.h"
#include "MainDialog.h"
#include "afxdialogex.h"
#include <WS2tcpip.h>
#include "Request.h"
#include <sstream>
#include <string>
#include <atlconv.h>
#include "ChatDialog.h"
#pragma comment(lib, "ws2_32.lib")

// MainDialog 대화 상자

IMPLEMENT_DYNAMIC(MainDialog, CDialogEx)

MainDialog::MainDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MainDialog, pParent), mName(nullptr), m_IsWorkingThread(FALSE), ip()
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
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BEGIN_MESSAGE_MAP(MainDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDialog::OnBnClickedButton2)
	ON_MESSAGE(MESSAGE_RANDOM_CHAT, &MainDialog::UpdateIp)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &MainDialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &MainDialog::OnBnClickedButton3)
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
	//=============종은추가코드============//
	string sBuf = string(buf);
	string inviter; //초대한 사람 이름
	string wanting; // 채팅하고싶은사람
	stringstream ssBuf(sBuf);
	ssBuf >> inviter >> wanting;
	main->invitingName = inviter.c_str();
	main->wantingName = wanting.c_str();
	/*if (wanting.compare("") == 0)
		postmessage(main->m_hwnd, message_random_chat, null, null);
	else if(wanting.compare(ct2ca(*main->mname)) == 0)
		postmessage(main->m_hwnd, message_random_chat, null, null);*/

		//=============종은추가코드============//
		// Convert from byte array to chars
	inet_ntop(AF_INET, &client.sin_addr, clientIp, 256);
	main->ip = clientIp;
	PostMessage(main->m_hWnd, MESSAGE_RANDOM_CHAT, NULL, NULL);
	//}
	//소켓을 닫는다
	closesocket(in);
	//close down Winsock
	WSACleanup();
	return 0;
}

// MainDialog 메시지 처리기
void MainDialog::OnBnClickedButton2()
{
	CString caption;
	GetDlgItemText(IDC_BUTTON2, caption);

	if(caption == _T("검색 시작"))
	{
		//m_IsWorkingThread = true;

		m_Thread = AfxBeginThread(ThreadForWaiting, this);

		SetDlgItemText(IDC_BUTTON2, _T("검색 중지"));
	}
	else
	{
		//m_IsWorkingThread = false;

		WaitForSingleObject(m_Thread->m_hThread, 0);

		SetDlgItemText(IDC_BUTTON2, _T("검색 시작"));
	}
}

LRESULT MainDialog::UpdateIp(WPARAM wParam, LPARAM lParam)
{
	if(this->wantingName.CompareNoCase((CString) "") == 0 && this->invitingName.CompareNoCase((LPCTSTR) (*(this->mName))) != 0)
	{
		WaitForSingleObject(m_Thread->m_hThread, 0);
		ReceiveRequest();
		SetDlgItemText(IDC_STATIC_COUNT, (CString) "CorrectInvite");
	}
	else if((this->wantingName.CompareNoCase((LPCTSTR) (*(this->mName)))) == 0)
	{
		WaitForSingleObject(m_Thread->m_hThread, 0);
		ReceiveRequest();
		SetDlgItemText(IDC_STATIC_COUNT, (CString) "CorrectInvite");
	}
	else
	{
		WaitForSingleObject(m_Thread->m_hThread, 0);
		m_Thread = AfxBeginThread(ThreadForWaiting, this);
		SetDlgItemText(IDC_STATIC_COUNT, (CString) "NotYourInvite");
	}

	//SetDlgItemText(IDC_STATIC_COUNT, this->ip);
	return 0;
}
//LRESULT MainDialog::

void MainDialog::SetName(CString* str)
{
	mName = str;

	CString newString = *str;
	newString.Append(CString(" 님"));

	mGuest = newString;
}

void MainDialog::runThread()
{
	m_Thread = AfxBeginThread(ThreadForWaiting, this);
}

void MainDialog::ReceiveRequest()
{
	// 초대 다이얼로그 생성

	if(invDialog == nullptr)
	{
		invDialog = new InvitationDialog();
	}

	// 초대 다이얼로그 생성 된 경우
	if(invDialog != nullptr)
	{
		delete invDialog;
		invDialog = new InvitationDialog(this);
		// 내 이름 값 전달
		invDialog->myName = mName;
		invDialog->main = this;
		// 이름을 받아서 출력될 메시지 내용 변경
		invDialog->SetText(&invitingName);
		invDialog->DoModal();
	}
}

void MainDialog::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	// UDP 메시지 보내기
	Request* req = new Request();
	CString* str = &(CString) "";
	m_edit.GetWindowText(*str);
	CT2CA pszConvertedAnsiString(*str);
	std::string s(pszConvertedAnsiString);

	// 입력 텍스트가 없으면 SendRequestToAnyone 실행
	// 입력 텍스트가 있으면 SendRequestByName 실행
	CT2CA CInviter((*(this->mName)));
	string inviter(CInviter);
	if(s.empty())
	{
		req->SendRequestToAnyone(inviter);
	}
	else
	{
		req->SendRequestByName(inviter, s);
	}
}

void MainDialog::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	ChatDialog* chat = new ChatDialog(this, this);
	chat->main = this;
	chat->DoModal();
}

void MainDialog::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PostQuitMessage(0);
}