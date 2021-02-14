#include <iostream>
#include <Windows.h>

using namespace std;

void main()
{
	HWND hwnd = FindWindowA(NULL, "DARK SOULS™: REMASTERED");

	//local = 0xDDB4290
	//hp = 0x3D8
	//stamina = 0x3E8

	int value = 500;

	if (hwnd)
	{
		DWORD ProcessId;
		GetWindowThreadProcessId(hwnd, &ProcessId);
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessId);

		if (ProcessId)
		{
			for (;;)
			{
				WriteProcessMemory(handle, (LPVOID)0xDDB4668, &value, sizeof(value), 0);
				WriteProcessMemory(handle, (LPVOID)0xDDB4678, &value, sizeof(value), 0);
			}
		}
	}
	else MessageBox(NULL, L"DARK SOULS™: REMASTERED is not open", NULL, NULL); exit(0);

	std::cin.get();
}