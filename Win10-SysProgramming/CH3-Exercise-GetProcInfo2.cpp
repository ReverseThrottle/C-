//#define BUILD_WINDOWS
#include <windows.h>
#include <stdio.h>
#include <psapi.h>
#include <tlhelp32.h>
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

bool EnableDebugPrivilege() {
    HANDLE hToken = NULL;
    LUID PrivRequired;
    LPWSTR PrivName = NULL;
    DWORD cName = NULL;

    if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken)); {

        printf("Handle to token: 0x%08x\n", hToken);

        if (LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &PrivRequired))
        {
            //LookupPrivilegeName(NULL, &PrivRequired, NULL, &cName);

            //PrivName = (LPWSTR)sizeof(cName);

            //if (LookupPrivilegeName(NULL, &PrivRequired, PrivName, &cName))
            //{
            //    printf("Privileges: %p", PrivName);
            //}
            //
            //printf("Error getting privilege name - Error code: %d\n", GetLastError());

            //Do Something...


        }
        else {
            printf("Error getting priv LUID - Error code : % d\n", GetLastError());
        }
        
    }

    CloseHandle(hToken);
    


    return ::GetLastError() == ERROR_SUCCESS;
}

int main(void) {

    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;
    PROCESS_INFORMATION_CLASS pic = ProcessProtectionLevelInfo;
    PROCESS_PROTECTION_LEVEL_INFORMATION ProtectedLevel;
    LPVOID ProcInfo = &ProtectedLevel;
    DWORD ProcInfoSize = sizeof(PROCESS_PROTECTION_LEVEL_INFORMATION);
    //BOOL test;
    DWORD dwPriorityClass;

    if (!EnableDebugPrivilege()) {
        printf("Failed to enable Debug privilege!\n");
    }


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
            /*test = GetProcessInformation(hProcess, pic, ProcInfo, ProcInfoSize);
            if (test == 0)
            {
                printf("Error retriving info: %d\n", GetLastError());
            }
            else
            {
                printf("Protection level: %d", ProtectedLevel.ProtectionLevel);

            }*/
            printf("Process ID: %d -- Executable Filename: %ws\n", pe32.th32ProcessID, pe32.szExeFile);

            WCHAR fullPathExe [MAX_PATH];
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
    

    

    getchar();

    return 0;
}