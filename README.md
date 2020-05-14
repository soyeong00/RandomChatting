# RandomChatting

원형	BOOL ShowWindow(HWND hWnd, int nCmdShow);
인수	
▶hWnd : 대상 윈도우 핸들

▶nCmdShow : 지정하고자 하는 보이기 상태이며 다음 값중 하나를 지정한다.

값	설명

SW_FORCEMINIMIZE - 2000 이후에만 쓸 수 있는 플레그이다. 윈도우를 소유한 스레드가 블록된 상태에서도 윈도우를 최소화시킨다.

SW_HIDE	- 윈도우를 숨긴다.

SW_MAXIMIZE	- 윈도우를 최대화시킨다.

SW_MINIMIZE	- 윈도우를 최소화시키며 다음 Z순서를 가지는 윈도우가 활성화된다.

SW_RESTORE	- 최대, 최소화된 윈도우를 이전 위치로 복구한다.

SW_SHOW	 - 윈도우를 활성화하며 보인다.

SW_SHOWDEFAULT	- STARTUPINFO 구조체가 지정하는 보이기 상태로 만든다.

SW_SHOWMAXIMIZED	- 윈도우를 최대화된 상태로 활성화한다.

SW_SHOWMINIMIZED	- 윈도우를 최소화한 상태로 활성화한다.

SW_SHOWMINNOACTIVE	- 윈도우를 최소화 상태로 보이며 활성화 상태는 변경되지 않는다.

SW_SHOWNA	- 윈도우를 헌재 상태로 보이며 활성화 상태는 변경되지 않는다.

SW_SHOWNOACTIVATE	- 최근 크기와 위치에 윈도우를 보이며 활성화 상태는 변경되지 않는다.

SW_SHOWNORMAL	- 윈도우를 보이며 활성화한다. 만약 윈도우가 최소화되어 있거나 최대화되어 있다면 윈도우를 원래 크기대로 복구한다. 윈도우를 처음 화면에 보일 때는 이 플래그를 사용해야 한다.


리턴

윈도우가 이전에 보이는 상태였으면 0이 아닌 값을 리턴하며 보이지 않는 상태였으면 0을 리턴한다.

설명	

윈도우의 보이기 상태를 지정한다. 보이기 상태(show state)란 보이기/숨기기는 물론이고 최대화/최소화/복구 상태 등 윈도우의 현재 상태를 통칭하는 용어이며 nCmdShow 인수가 지정하는 여러 가지 보이기 상태 중 하나를 선택할 수 있다.
단, 이 함수가 처음 호출될 때는 반드시 WinMain의 인수로 전달된 nCmdShow를 그대로 넘겨 주는 것이 좋다. 쉘은 프로그램을 실행할 때 사용자가 지정해 놓은 등록 정보를 WinMain으로 전달해 주는데 이 설정 상태대로 보여야 하기 때문이다. 만약 이 프로그램이 STARTUPINFO 구조체의 정보대로 생성되었다면 첫번째 ShowWindow 호출에서 nCmdShow 인수 지정은 무시되며 이 구조체가 지정하는 보이기 상태가 적용된다. 두번째 호출부터는 원하는 보이기 상태로 변경할 수 있다.



출처: https://3dmpengines.tistory.com/544 [3DMP]
