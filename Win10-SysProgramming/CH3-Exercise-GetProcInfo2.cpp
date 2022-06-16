//#define BUILD_WINDOWS
#include <windows.h>
#include <stdio.h>
#include <psapi.h>
#include <tlhelp32.h>
#include <winnt.h>
#include <processthreadsapi.h>
#ifndef PCH_H
#define PCH_H

#include <wil\resource.h>
#include <memory>

#endif //PCH_H

//GetProcessMemoryInfo
//GetExitCodeProcess
//IsProcessInJob
//Changing Token prives - https://docs.microsoft.com/en-us/windows/win32/secbp/changing-privileges-in-a-token
//ThreadLoopHelper - https://docs.microsoft.com/en-us/windows/win32/toolhelp/taking-a-snapshot-and-viewing-processes
//ModuleLoopHelper

bool EnableDebugPrivilege() 
{
    HANDLE hToken;
    LPCTSTR lpszPrivilege = SE_DEBUG_NAME;
    BOOL bEnablePrivilege = NULL;
    TOKEN_PRIVILEGES tp;
    LUID luid;

    if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken))
    {

        if (!LookupPrivilegeValue(NULL, lpszPrivilege, &luid))
        {
            printf("LookupPrivilegeValue error: %u\n", GetLastError());
            return FALSE;
        }

        tp.PrivilegeCount = 1;
        tp.Privileges[0].Luid = luid;
        tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;


        // Enable the privilege or disable all privileges.

        if (!AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), (PTOKEN_PRIVILEGES)NULL, (PDWORD)NULL))
        {
            printf("AdjustTokenPrivileges error: %u\n", GetLastError());
            return FALSE;
        }

        if (GetLastError() == ERROR_NOT_ALL_ASSIGNED)

        {
            printf("The token does not have the specified privilege. \n");
            return FALSE;
        }
    }
    return TRUE;
}



void ProcNamePriority() {

    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;
    PROCESS_INFORMATION_CLASS pic = ProcessProtectionLevelInfo;
    PROCESS_PROTECTION_LEVEL_INFORMATION ProtectedLevel;
    LPVOID ProcInfo = &ProtectedLevel;
    DWORD ProcInfoSize = sizeof(PROCESS_PROTECTION_LEVEL_INFORMATION);
    //BOOL test;
    DWORD dwPriorityClass;

    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE)
    {
        printf("Failed to capture snapshot %d\n", GetLastError());
    }

    pe32.dwSize = sizeof(PROCESSENTRY32);


    if (!Process32First(hProcessSnap, &pe32))
    {
        printf("Failed to get first process %d\n", GetLastError());
    }


    do
    {


        HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pe32.th32ProcessID);
        if (hProcess == NULL)
        {
            printf("Error opening process: %ws -- Error code: %d\n", pe32.szExeFile, GetLastError());
        }
        else
        {
            printf("Process ID: %d -- Executable Filename: %ws\n", pe32.th32ProcessID, pe32.szExeFile);

            WCHAR fullPathExe[MAX_PATH];
            DWORD pdwSize = MAX_PATH;
            if (!QueryFullProcessImageName(hProcess, 0, fullPathExe, &pdwSize))
            {
                printf("Failed to retrieve full path of executable: %ws\n", pe32.szExeFile);
                printf("Error code: %d\n", GetLastError());
            }

            printf("Full executable path: %ws\n", &fullPathExe);

            dwPriorityClass = GetPriorityClass(hProcess);
            if (dwPriorityClass == 0)
            {
                printf("Erorr getting priority for process: %ws -- Error code: %d\n", pe32.szExeFile, GetLastError());
            }

            printf("Class priority: 0x%X\n\n", dwPriorityClass);
        }
    } while (Process32Next(hProcessSnap, &pe32));


}

int main(void) {



    if (EnableDebugPrivilege() == TRUE) 
    {
        printf("Enabled Debug privileges!\n");
    }

    ProcNamePriority();

    


    getchar();

    return 0;
}
