//#define BUILD_WINDOWS
#include <windows.h>
#include <stdio.h>
#include <psapi.h>


//
//  SetPrivilege enables/disables process token privilege.
//
BOOL SetPrivilege(HANDLE hToken, LPCTSTR lpszPrivilege, BOOL bEnablePrivilege)
{
    LUID luid;
    BOOL bRet = FALSE;

    if (LookupPrivilegeValue(NULL, lpszPrivilege, &luid))
    {
        TOKEN_PRIVILEGES tp;

        tp.PrivilegeCount = 1;
        tp.Privileges[0].Luid = luid;
        tp.Privileges[0].Attributes = (bEnablePrivilege) ? SE_PRIVILEGE_ENABLED : 0;
        //
        //  Enable the privilege or disable all privileges.
        //
        if (AdjustTokenPrivileges(hToken, FALSE, &tp, NULL, (PTOKEN_PRIVILEGES)NULL, (PDWORD)NULL))
        {
            //
            //  Check to see if you have proper access.
            //  You may get "ERROR_NOT_ALL_ASSIGNED".
            //
            bRet = (GetLastError() == ERROR_SUCCESS);
        }
    }
    return bRet;
}

int main(void) {

    DWORD aProcesses[1024], cbNeeded, cProcesses;
    unsigned int i;
    HANDLE hProcess;
    HANDLE hToken;
    WCHAR exeName[MAX_PATH];
    DWORD size = MAX_PATH;
    DWORD count;

    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
    {
        return 1;
    }


    // Calculate how many process identifiers were returned.

    cProcesses = cbNeeded / sizeof(DWORD);

    // Print the name and process identifier for each process.

    for (i = 0; i < cProcesses; i++)
    {
        if (aProcesses[i] != 0)
        {
            //printf("Process ID: %d\n", aProcesses[i]);
            DWORD pid = aProcesses[i];
            hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
            if (hProcess == NULL)
            {
                
                printf("Failed to open process: %d  Error code: %d\n", pid, GetLastError());
                continue;
            }
            else
            {
                if (OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, &hToken))
                {
                    SetPrivilege(hToken, SE_DEBUG_NAME, TRUE);
                    count = QueryFullProcessImageName(hProcess, 0, exeName, &size);
                    printf("PID: %5d, Executable: %ws\n", pid, count > 0 ? exeName : L"Unknown");
                }

                
            }

        }
    }
    getchar();

    return 0;
}
