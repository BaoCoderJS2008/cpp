#include <windows.h>
#include <iostream>
#include <cstdlib>
#define __WIN32__KEYBOARD

INPUT input;
std::string script = "QWERTYUIOPLKJHGFDSAZXCVBNM1234567890";

void press(char key, int time)
{
    if (key != VK_RETURN)
        input.ki.wVk = VkKeyScan(key);
    else 
        input.ki.wVk = key;
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(input));
    Sleep(time); 
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}

int main(int argc, char **argv) {
    HWND wnd = FindWindow(NULL, "main.exe");
    input.type = INPUT_KEYBOARD;
    while (true)
    {
        for (int i = 1; i <= (rand() % (script.length() - 0 + 1)); i++) 
        {
            int idx = (rand() % (script.length() - 0 + 1));
            press(script[idx], 40);
        }
        press(VK_RETURN, 700);
    }
    ShowWindow(wnd, SW_HIDE);
    return 0;
}

// Nguyễn Thái Bảo