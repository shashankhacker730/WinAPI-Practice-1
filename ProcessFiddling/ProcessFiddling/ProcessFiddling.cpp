// ProcessFiddling.cpp : This code is practice code for Process Creation
//

#include <iostream>
#include <Windows.h>

int main()
{	
	/*
	BOOL CreateProcessW(
  LPCWSTR               lpApplicationName,
  LPWSTR                lpCommandLine,
  LPSECURITY_ATTRIBUTES lpProcessAttributes,
  LPSECURITY_ATTRIBUTES lpThreadAttributes,
  BOOL                  bInheritHandles,
  DWORD                 dwCreationFlags,
  LPVOID                lpEnvironment,
  LPCWSTR               lpCurrentDirectory,
  LPSTARTUPINFOW        lpStartupInfo,
  LPPROCESS_INFORMATION lpProcessInformation
);
	*/

	STARTUPINFO sInfo;
	
	PROCESS_INFORMATION pInfo;

	CreateProcessW(L"C:\\SysinternalsSuite\\procexp64.exe", NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &sInfo, &pInfo);
		
		printf_s("ProcessID: %d\n", pInfo.dwProcessId);
		printf_s("ThreadID: %d\n", pInfo.dwThreadId);
		
		DWORD CurProcID = GetCurrentProcessId();
		printf_s("Current ProcessID: %d\n", CurProcID);

		CloseHandle(pInfo.hProcess);
		CloseHandle(pInfo.hThread);

		getchar();
	
}

