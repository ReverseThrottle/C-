#define BUILD_WINDOWS
#include <windows.h>
#include <stdio.h>
#include <secext.h>


int main(void) {

	//GetComputerName Function variables
	BOOL computerName;
	WCHAR bufferComName[MAX_COMPUTERNAME_LENGTH+1];
	LPDWORD bufferSizeComName[MAX_COMPUTERNAME_LENGTH+1];

	//GetWindowsDirectory
	UINT sizeDir;
	WCHAR bufferDir[MAX_PATH];
	UINT bufferSizeDir[MAX_PATH];

	//QueryPerformanceCounter
	BOOL queryCount;
	LARGE_INTEGER pPerformanceCount;

	//GetProductInfo & GetVersionEx
	OSVERSIONINFO osv;
	BOOL productInfoReturn;
	BOOL versionReturn;
	DWORD versionType;
	
	//GetNativeSystemInfo
	SYSTEM_INFO si;
	::GetNativeSystemInfo(&si);


	printf("Number of Logical Processors: %d\n", si.dwNumberOfProcessors);
	printf("Page size: %d Bytes\n", si.dwPageSize);
	printf("Processor Mask: 0x%p\n", (PVOID)si.dwActiveProcessorMask);
	printf("Minimum process address: 0x%p\n", si.lpMinimumApplicationAddress);
	printf("Maximum process address: 0x%p\n", si.lpMaximumApplicationAddress);
	printf("Processor Architecture: %d\n", si.wProcessorArchitecture);
	printf("Process Type: %d\n", si.dwProcessorType);

	computerName = ::GetComputerName(bufferComName, (LPDWORD)bufferSizeComName);
	if (!computerName)
	{
		printf("Failed to get Computer Name: %d\n", ::GetLastError());
	}

	printf("Computer Name: %S\n", &bufferComName);

	
	sizeDir = ::GetWindowsDirectory(bufferDir, *bufferSizeDir);
	if (!sizeDir)
	{
		printf("Failed to get Windows Directory: Error code: %d\n", ::GetLastError());
	}

	printf("Directory: %S\n", bufferDir);
	printf("Character Length: %d\n", sizeDir);


	queryCount = ::QueryPerformanceCounter(&pPerformanceCount);
	if (!queryCount)
	{
		printf("QueryPerfCounter Failed. Error code: %d\n", ::GetLastError());
	}

	printf("Query Counter: %d\n", queryCount);

	
	ZeroMemory(&osv, sizeof(OSVERSIONINFO));
	osv.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	versionReturn = ::GetVersionEx(&osv);
	if (!versionReturn)
	{
		printf("GetVersionEx Failed. Error code: %d\n", ::GetLastError());
	}

	printf("Return value of GetVersionEx: %d\n", versionReturn);

	versionType = ::GetVersion();
	printf("Version type is: %lu\n", versionType);

	
	return 0;
}
