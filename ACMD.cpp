#include <iostream>
#include <windows.h>
#include <bits/stdc++.h>

using namespace std;

HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);

int main(int argc, char const *argv[])
{
    STARTUPINFO info = {sizeof(info)};
    PROCESS_INFORMATION processInfo;
    if (CreateProcess("cmd.exe", "dir", NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
    {
        WaitForSingleObject(processInfo.hProcess, INFINITE);
        CloseHandle(processInfo.hProcess);
        CloseHandle(processInfo.hThread);
    }
    string command;
    while (true)
    {
        command = "";
        SetConsoleTextAttribute(col, 3);
        auto a = system("cd");
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b>";
        // cout << "\033[F>";
        // printf("\b\b\b\b\b>");
        SetConsoleTextAttribute(col, 15);
        getline(cin, command);
        const char *str = command.c_str();
        system(str);
    }

    return 0;
}

/*
1  : Blue
2  : Green
3  : Cyan
4  : Red
5  : Purple
6  : Yellow(dark)
7  : Default white
8  : Grey
9  : Bright blue
10 : Bright green
11 : Bright cyan
12 : Bright red
13 : pink
14 : yellow
15 : Bright white
*/