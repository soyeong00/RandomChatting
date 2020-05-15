// DialogCommunicationExample1.cpp: 구현 파일
//

#include "pch.h"
#include "RandomChatting.h"
#include "DialogCommunicationExample1.h"
#include "afxdialogex.h"

// DialogCommunicationExample1 대화 상자

IMPLEMENT_DYNAMIC(DialogCommunicationExample1, CDialogEx)

DialogCommunicationExample1::DialogCommunicationExample1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DialogCommunicationExample1, pParent)
{
}

DialogCommunicationExample1::~DialogCommunicationExample1()
{
}

void DialogCommunicationExample1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(DialogCommunicationExample1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DialogCommunicationExample1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DialogCommunicationExample1::OnBnClickedButton2)
END_MESSAGE_MAP()

// DialogCommunicationExample1 메시지 처리기

#include "DialogCommunicationExample2.h"
void DialogCommunicationExample1::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	Dialog2->ChattingView.SetWindowTextW(L"클릭");
}

//정 준상
// 클라에서 Server로의 Connnect
#include<WS2tcpip.h>

int DialogCommunicationExample1::OnBnClickedAcceptButton()
{
	//1. 윈속을 초기화 해준다.
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)			// 윈속 초기화 2.2 버전 사용
		printf("WinSock 초기화에 실패했습니다. \n");			// 윈속 초기화가 안될 경우 메시지ㅣ 출력

	// 2. socket 생성
	hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(hSocket == INVALID_SOCKET)
		printf("Socket 생성에 실패했습니다.");

	// 3. 서버에 연결
	// 3-1. 연결할 서버 주소 셋팅
	memset(&servAddr, 0, sizeof(servAddr.sin_addr));		// 메모리 셋팅
	servAddr.sin_family = AF_INET;

	inet_pton(AF_INET, "123", &servAddr.sin_addr);	// 받아온 IP주소를 소켓 IP에 저장
	servAddr.sin_port = htons(9001);

	// 3-2. 서버에 연결 시도
	if(connect(hSocket, (SOCKADDR*) &servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		printf("서버 연결에 실패했습니다.");

	//	4. 서버로부터 통신 대기
	// 받을 데이터의 크기
	int recvSize;
	// 받을 데이터를 저장할 변수
	char recvData[1000];
	// 받은 데이터의 크기를 저장
	recvSize = recv(hSocket, recvData, sizeof(recvData), 0);

	return 0;
}

// 정준상
// 서버
int DialogCommunicationExample1::OnBnClickedInviteButton()
{
	// 1. 윈속 초기화
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		printf("Winsock 초기화에 실패했습니다. \n");

	// 2. socket 생성
	hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(hSocket == INVALID_SOCKET)
		printf("Socket 생성에 실패했습니다. \n");

	// 3. 서버 자신의 주소를 셋팅
	// 3-1 서버 주소 셋팅
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &servAddr.sin_addr);
	servAddr.sin_port = htons(9001);
	if(bind(hSocket, (SOCKADDR*) &servAddr, sizeof(servAddr) == SOCKET_ERROR))
		printf("Bind에 실패했습니다. \n");
	if(listen(hSocket, 5) == SOCKET_ERROR)
		printf("Listen에 실패했습니다. \n");

	// 3-2 클라이언트 연결 기다리기
	int sizeClientAddr = sizeof(ClientAddr);
	ClientSocket = accept(hSocket, (SOCKADDR*) &ClientAddr, &sizeClientAddr);
	if(ClientSocket == SOCKET_ERROR)
		printf("Accept에 실패했습니다.");

	return 0;
}

void DialogCommunicationExample1::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}