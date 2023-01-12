#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;

string readFile(ifstream &);
void print(string);

int main()
{
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    system("color a && chcp 65001 > nul");
    ifstream file("ascii.txt");
    string ascii = readFile(file);
    print(ascii);
    getchar();
}

void print(string txt)
{
    for (int i = 0; i < txt.length(); i++)
    {
        Sleep(0.9);
        cout << txt[i];
    }
}

string readFile(ifstream &File)
{
    string Lines = ""; 

    if (File)
    {
        while (File.good())
        {
            string TempLine;    
            getline(File, TempLine);
            TempLine += "\n";         

            Lines += TempLine; 
        }
        return Lines;
    }
}