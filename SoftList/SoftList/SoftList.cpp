// SoftList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <GPEdit.h>

#define KEY_LENGTH 255


int main()
{
    // Registry Key: Computer\HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall

	//To get handle of registry
	HKEY result;
	//Get List of subkeys
	TCHAR KeyClass[KEY_LENGTH];
	DWORD KeyClassLength = 0;
	DWORD SubKeys = 0;
	DWORD MaxSubKeyLen;
	DWORD MaxClassLen;
	DWORD KeyValues;
	DWORD MaxKeyValuesNameLen;
	DWORD MaxKeyValuesLen;
	DWORD SecurityDesc;
	FILETIME LastWriteTime;
	DWORD Name = KEY_LENGTH;

	unsigned long int error;

	if (ERROR_SUCCESS == RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall", 0, KEY_ALL_ACCESS, &result)) {

		error = RegQueryInfoKeyW(result,(LPWSTR)& KeyClass,	&KeyClassLength, NULL, &SubKeys, &MaxSubKeyLen, &MaxClassLen, &KeyValues, 
			&MaxKeyValuesNameLen, &MaxKeyValuesLen, &SecurityDesc, &LastWriteTime);
	}
	printf("Number of Softwares installed on host: %d\n", SubKeys);

	TCHAR SubKeyName[KEY_LENGTH];
	DWORD SubKeyNameLen, j;

	for (j = 0; j < SubKeys; j++) {
		SubKeyNameLen = KEY_LENGTH;
		if (RegEnumKeyExW(result, j, (LPWSTR)& SubKeyName, &SubKeyNameLen, NULL, 0, 0, &LastWriteTime) == ERROR_SUCCESS) {
			TCHAR subkey1[255] = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\";
			lstrcatW(subkey1, SubKeyName);
			
			TCHAR Data[MAX_PATH];
			DWORD Data_len = MAX_PATH;
			if (ERROR_SUCCESS == RegGetValue(HKEY_LOCAL_MACHINE, (LPCWSTR)& subkey1, L"DisplayName", RRF_RT_ANY, NULL, Data, &Data_len)) {
				printf("Software No %d: %ws\n", j+1, Data);
			}

		}
	}

	RegCloseKey(result);
}


