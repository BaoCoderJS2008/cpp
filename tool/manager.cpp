#include <iostream>
#include <windows.h>
#include <fstream>
#include <unistd.h>
#include <dirent.h>
#include <conio.h>
#include <string.h>
#include <ctime>
#define mgrver 1.0
using namespace std;

/*
    Source được viết bởi đồng chí Nguyễn Thái Bảo
    Đây là 1 chương trình dùng để quản lý hệ điều hành Windows của bạn
    Phiên bản hiện tại là 1.0 beta
    from thành phố Hồ Chí Minh with love :))
*/

void clearTrash();
void boot();
void cls();
void pause();
void calc();
void readFile();
void newUserAccount();
void deleteUserAccount();
void deleteUsrPass();
void setGroup();
void shutdown(char);
void loading_progress(int, int);
void loading();
void mkdir_cf();
void writer(string, int);
void writef(string, string);
string sinput(string);
void startup(string);
void log(string);

time_t now = time(0);
tm *ltm = localtime(&now);
int h = ltm->tm_hour;
int m = ltm->tm_min;
int s = ltm->tm_sec;
int day = ltm->tm_mday;
int year = 1900 + ltm->tm_year;
int month = ltm->tm_mon + 1;
string timeNow = "Ngày " + to_string(day) + "/" + to_string(month) + "/" + to_string(year) + " " + to_string(h) + ":" + to_string(m) + ":" + to_string(s);
string cmd;
string center = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t";
string userprofile = getenv("userprofile");

int main()
{
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    const COLORREF black = 0x00000000;
    byte Alpha = 230;
    SetConsoleOutputCP(65001);
    HWND hWnd = GetConsoleWindow();
    SetLayeredWindowAttributes(hWnd, black, Alpha, LWA_ALPHA);
    SetConsoleTitle("Comrade tool (Home)");
    HANDLE han1 = GetStdHandle(STD_OUTPUT_HANDLE);

    short X = GetSystemMetrics(SM_CXSCREEN);
    short Y = GetSystemMetrics(SM_CYSCREEN);

    string inpdir;
    string fname;
    string text;
    system("color a");
    boot();
    cout << endl
         << endl
         << endl
         << endl
         << endl;
    Sleep(10);
    cout << "                                        [33m                                                     6E672043                                     \n";
    cout << "                                                                                                1101EA3                                   \n";
    cout << "                                                                                      4C69EA6E    1ED96E6                                 \n";
    cout << "                                                                                   2058F4206D75    720531E                                \n";
    cout << "                                                                                  F46E206E1036D      A36E205                              \n";
    cout << "                                                                                 2100000000000         6691EC7                             \n";
    cout << "                                                                               4C69EA6E2042616E         74204E6                            \n";
    cout << "                                                                                67204E6761206D75F       16D206D                            \n";
    cout << "                                                                                  46E206E1036D210000    75F46E2                            \n";
    cout << "                                                                                          000000000000  06E1036                            \n";
    cout << "                                                                                             D21000000000000000                            \n";
    cout << "                                                                             01000             110E3201111EA36                             \n";
    cout << "                                                                           07111110001           F2063681EE72                              \n";
    cout << "                                                                        06E67681296120741B020621EA36E210000000                             \n";
    cout << "                                                                       431ED96E672048F26102078E320481ED969204368                           \n";
    cout << "                                                                       1EE7204     E676812961205669 1EC774204E616                          \n";
    cout << "                                                                         D20          6D75F46E20       6E1036D210                          \n";
    cout << endl;
    loading();
manager:
    time_t curtime;
    time(&curtime);
    int choose;
    system("color a");
    cls();
    cout << endl;
    cout << "                                           ░█████╗░░█████╗░███╗░░░███╗██████╗░░█████╗░██████╗░███████╗  ████████╗░█████╗░░█████╗░██╗░░░░░          \n";
    cout << "                                           ██╔══██╗██╔══██╗████╗░████║██╔══██╗██╔══██╗██╔══██╗██╔════╝  ╚══██╔══╝██╔══██╗██╔══██╗██║░░░░░          \n";
    cout << "                                           ██║░░╚═╝██║░░██║██╔████╔██║██████╔╝███████║██║░░██║█████╗░░  ░░░██║░░░██║░░██║██║░░██║██║░░░░░          \n";
    cout << "                                           ██║░░██╗██║░░██║██║╚██╔╝██║██╔══██╗██╔══██║██║░░██║██╔══╝░░  ░░░██║░░░██║░░██║██║░░██║██║░░░░░          \n";
    cout << "                                           ╚█████╔╝╚█████╔╝██║░╚═╝░██║██║░░██║██║░░██║██████╔╝███████╗  ░░░██║░░░╚█████╔╝╚█████╔╝███████╗          \n";
    cout << "                                           ░╚════╝░░╚════╝░╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═════╝░╚══════╝  ░░░╚═╝░░░░╚════╝░░╚════╝░╚══════╝          \n";
    Sleep(20);
    cout << "\n [32m=====================================================================================================================\n";
    Sleep(20);
    cout << "  [36mNgười dùng: " << getenv("username") << endl;
    Sleep(20);
    Sleep(20);
    cout << "  Tên máy: " << getenv("computername") << endl;
    cout << "  Thời gian: " << timeNow << "\n";
    Sleep(20);
    cout << " [32m=====================================================================================================================\n";
    Sleep(20);
    cout << "  [36mHệ thống | thời gian[33m\n";
    Sleep(20);
    cout << "  - - - - - - - - - - \n\n";
    Sleep(20);
    cout << "  [1] |  Xem địa chỉ IP của bạn                   [7]  | Thay đổi thời gian                           \n";
    Sleep(20);
    cout << "  [2] |  Xem thông tin hệ thống                   [8]  | Thay đổi ngày tháng                          \n";
    Sleep(20);
    cout << "  [3] |  Các chương trình đang chạy               [9]  | Phiên bản Windows hiện tại                   \n";
    Sleep(20);
    cout << "  [4] |  chế độ tắt máy                           [10] | Máy tính                                     \n";
    Sleep(20);
    cout << "  [5] |  Cài đặt\n";
    Sleep(20);
    cout << endl;
    cout << "  [32mQuản lý file[33m\n";
    cout << "  - - - - - - - -\n\n";
    cout << "  [6]  |  Xóa file rác                                                                                \n";
    cout << "  [11] |  Xem nội dung trong file                 [12] | Soạn thảo                                    \n";
    cout << "  [13] |  Quản lý thư mục và tập tin\n";
    cout << "  [19] |  Tự mở (App startup)\n";
    cout << endl;
    Sleep(20);
    cout << "  [34mQuản lý tài khoản[33m\n";
    Sleep(20);
    cout << "  - - - - - - - - - - - - -\n\n";
    Sleep(20);
    cout << "  [14] |  Thêm tài khoản                          [15] |  Xóa tài khoản\n";
    Sleep(20);
    cout << "  [16] |  Các tài khoản đang tồn tại              [17] |  Xóa mật khẩu tài khoản\n";
    Sleep(20);
    cout << "  [18] |  Thêm người dùng vào nhóm\n";
    Sleep(20);
    cout << endl;
    Sleep(20);
    cout << "  [31mKhác[33m\n";
    Sleep(20);
    cout << "  - - -\n\n";
    Sleep(20);
    cout << "  [0]    | Thoát\n";
    Sleep(20);
    cout << "  [2008] | Thông tin tác giả\n";
    Sleep(20);
    cout << endl;
    Sleep(20);
    cout << "  Nhập lựa chọn của bạn : [34m";
    cin >> choose;
    system("color a");
    switch (choose)
    {
    case 0:
        exit(0);
        break;
    case 1:
        cls();
        system("ipconfig");
        pause();
        goto manager;
        break;
    case 6:
        clearTrash();
        goto manager;
        break;
    case 3:
        cls();
        system("tasklist");
        pause();
        goto manager;
        break;
    case 4:
        cls();
        char mode;
        cout << "l: Đăng xuất | r: Khởi động lại | s: Tắt máy | h: Ngủ đông\n";
        cout << "Nhập chế độ: ";
        cin >> mode;
        shutdown(mode);
        break;
    case 2:
        system("color a");
        cls();
        system("systeminfo");
        pause();
        goto manager;
        break;
    case 5:
        cls();
        system("set");
        pause();
        goto manager;
        break;
    case 7:
        cls();
        system("time");
        pause();
        goto manager;
        break;
    case 8:
        cls();
        system("date");
        pause();
        goto manager;
        break;
    case 9:
        system("winver");
        goto manager;
        break;
    case 10:
        cls();
        calc();
        pause();
        goto manager;
        break;
    case 11:
        cls();
        readFile();
        pause();
        goto manager;
        break;
    case 12:
        system("start notepad.exe");
        goto manager;
        break;
    case 13:
        goto fileManager;
        break;
    case 14:
        cls();
        newUserAccount();
        pause();
        goto manager;
        break;
    case 15:
        cls();
        deleteUserAccount();
        pause();
        goto manager;
        break;
    case 16:
        cls();
        system("net user");
        pause();
        goto manager;
        break;
    case 17:
        cls();
        deleteUsrPass();
        pause();
        goto manager;
        break;
    case 18:
        cls();
        setGroup();
        goto manager;
        break;
    case 19:
         startup(sinput("Nhập đường dẫn đến app cần mở khi khởi động Windows: "));
         break;
         goto manager;
    case 2008:
        cls();
        text = center + "Chào bạn!";
        writer(text, 30);
        Sleep(800);
        cls();
        text = center + "Mình tên Bảo, sinh năm 2008 là đứa viết ra cái script này :3";
        writer(text, 30);
        Sleep(800);
        cls();
        Sleep(30);
        cout << "\n\n\n\n\n\n\n\n                                                                     Thẻ thông tin điện tử\n";
        Sleep(30);
        cout << "                                                     +---------------------------------------------------+\n";
        Sleep(30);
        cout << "                                                     |  Tác giả: Nguyễn Thái Bảo                         |\n";
        Sleep(30);
        cout << "                                                     |  Email: baovn1179@gmail.com                       |\n";
        Sleep(30);
        cout << "                                                     |  Facebook: Nguyễn Thái Bảo                        |\n";
        Sleep(30);
        cout << "                                                     |  Github: BaoCoderJS2008                           |\n";
        Sleep(30);
        cout << "                                                     |  Thông tin: Lập trình web và Windows, Người dùng  |\n";
        Sleep(30);
        cout << "                                                     |  Windows, Linux, Android và là 1 VOZer :v         |\n";
        Sleep(30);
        cout << "                                                     |                                                   |\n";
        Sleep(30);
        cout << "                                                     +---------------------------------------------------+\n";

        pause();
        goto manager;
        break;
    default:
        cls();
        system("color 4");
        cout << "Lựa chọn không hợp lệ, thử lại sau 3 giây\n";
        sleep(3);
        goto manager;
    }

fileManager:
    string __dirname__ = userprofile;
    int fc;
    DIR *dir;
    dirent *pdir;
fileMM:
    int i = 0;
    cls();
    SetConsoleTitle("Comrade tool (File manager)");
    cout << endl;
    Sleep(30);
    cout << "                                           ░█████╗░░█████╗░███╗░░░███╗██████╗░░█████╗░██████╗░███████╗  ████████╗░█████╗░░█████╗░██╗░░░░░          \n";
    cout << "                                           ██╔══██╗██╔══██╗████╗░████║██╔══██╗██╔══██╗██╔══██╗██╔════╝  ╚══██╔══╝██╔══██╗██╔══██╗██║░░░░░          \n";
    cout << "                                           ██║░░╚═╝██║░░██║██╔████╔██║██████╔╝███████║██║░░██║█████╗░░  ░░░██║░░░██║░░██║██║░░██║██║░░░░░          \n";
    cout << "                                           ██║░░██╗██║░░██║██║╚██╔╝██║██╔══██╗██╔══██║██║░░██║██╔══╝░░  ░░░██║░░░██║░░██║██║░░██║██║░░░░░          \n";
    cout << "                                           ╚█████╔╝╚█████╔╝██║░╚═╝░██║██║░░██║██║░░██║██████╔╝███████╗  ░░░██║░░░╚█████╔╝╚█████╔╝███████╗          \n";
    cout << "                                           ░╚════╝░░╚════╝░╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═════╝░╚══════╝  ░░░╚═╝░░░░╚════╝░░╚════╝░╚══════╝          \n";
    cout << "\n [32m=====================================================================================================================\n";
    cout << " Bạn đang ở thư mục " << __dirname__ << endl;
    cout << " [0] | Về giao diện chính\n";
    cout << " [1] | Xóa file\n";
    cout << " [2] | Di chuyển đến đường dẫn khác (nhập đầy đủ đường dẫn)\n";
    cout << " [3] | Đổi tên file\n";
    cout << " [4] | Mở thư mục trong thư mục hiện tại\n";
    cout << " [5] | Mở file trong thư mục hiện tại\n";
    cout << " [32m=====================================================================================================================\n";
    cout << endl;
    cout << " ---------------------------------------------------------------------------------------------------------\n";
    cout << " | Các thư mục và tập hiện có: \n";

    dir = opendir(__dirname__.c_str());

    while (pdir = readdir(dir))
    {
        cout << " | " << i << "   " << pdir->d_name << endl;
        i++;
    }
    closedir(dir);
    cout << " ---------------------------------------------------------------------------------------------------------\n";
    cout << "  Nhập lựa chọn của bạn : [34m";
    cin >> fc;
    system("color a");
    switch (fc)
    {
    case 0:
        goto manager;
        break;
    case 1:
        remove(sinput("  Nhập tên thư mục/tập tin muốn xóa: ").c_str());
        cls();
        goto fileManager;
        break;
    case 2:
    {
        cout << "  Nhập đường dẫn của thư mục cần đến: ";
        cin >> inpdir;
        __dirname__ = inpdir;
        goto fileMM;
        break;
    }
    case 3:
        rename(sinput("  Nhập tên file muốn đổi tên: ").c_str(), sinput(" Nhập tên mới: ").c_str());
        goto fileManager;
        break;
    case 4:
        cout << " Nhập tên thư mục: ";
        cin >> fname;
        __dirname__ = __dirname__ + "\\" + fname;
        goto fileMM;
        break;
    case 5:
        cout << "  Nhập tên file: ";
        cin >> fname;
        cmd = "start " + __dirname__ + "\\" + fname;
        system(cmd.c_str());
        goto fileMM;
        break;
    }
    return EXIT_SUCCESS;
}

void clearTrash()
{
    string text = center + "Vui lòng đợi trong giây lát...";
    cls();
    writer(text, 40);
    Sleep(1200);
    cls();
    cout << "---------------------------------------------\n";
    system("del /s /q %temp%");
    system("del /s /q C:\\windows\\prefetch");
    system("rmdir /s /q C:\\Windows\\SoftwareDistribution\\Download");
    system("ipconfig /flushdns");
    system("del /s /q /a:a C:\\Windows\\LiveKernelReports\\*.dmp");
    cout << "---------------------------------------------\n";
    log("Xóa các tệp rác");
    pause();
}

void boot()
{
    log("Boot...");
    string text = center + "Viết bởi đồng chí Nguyễn Thái Bảo";
    string text2 = center + "Đang nạp các tài nguyên cần thiết...";
    writer(text2, 30);
    Sleep(950);
    cls();
    writer(text, 30);
    Sleep(500);
    cls();
}
void writer(string txt, int s)
{
    for (int i = 0; i < txt.length(); i++)
    {
        Sleep(s);
        cout << txt[i];
    }
}
void cls()
{
    system("cls");
}
void pause()
{
    string text = "Nhấn phím bất kì để thoát ";
    writer(text, 30);
    getch();
}

string sinput(string txt)
{
    string data;
    cout << txt;
    cin >> data;
    return data;
}

void readFile()
{
    ifstream file;
    string content;
    string line;
    string path = sinput("Nhập địa chỉ đến file cần đọc: ");
    file.open(path, ios::in);
    if (file.is_open())
    {
        log("Đọc nội dung file tại địa chỉ " + path);
        cls();
        string line;
        while (!file.eof())
        {
            Sleep(12);
            getline(file, line);
            content += line;
            content += "\n";
        }
        cout << content << endl
             << endl;
    }
    else
    {
        writer("Không tìm thấy file\n", 30);
        log("Đọc file tại địa chỉ " + path + " không thành công");
    }
    file.close();
}
void newUserAccount()
{
    string username;
    string user_password;
    string re_user_password;
    int setPwd;
    cout << "Nhập tên tài khoản: ";
    cin >> username;
    cout << "Bạn có muốn đặt mật khẩu? số 1 để đặt và 0 để thoát: ";
    cin >> setPwd;
    switch (setPwd)
    {
    case 1:
        cout << "Nhập mật khẩu: ";
        cin >> user_password;
        cout << "Nhập lại mật khẩu: ";
        cin >> re_user_password;
        if (user_password == re_user_password)
        {
            cmd = "net user " + username + " " + user_password + " /add";
            if (system(cmd.c_str()) == 0)
            {
                cls();
                Sleep(20);
                cout << "-------------------------------\n";
                Sleep(20);
                cout << "Tên tài khoản: " << username << endl;
                Sleep(20);
                cout << "Mật khẩu: " << user_password << endl;
                Sleep(20);
                cout << "-------------------------------\n";
                log("Thêm mật khẩu tài khoản " + username + " thành công");
            }
            else
            {
                cout << "Đã xảy ra lỗi\n";
                log("Tạo tài khoản không thành công\n");
            }
        }
        else
        {
            cout << "Mật khẩu nhập lại không khớp :v\n";
            log("Mật khẩu không khớp để đặt mật khẩu cho tài khoản " + username);
        }
        break;
    default:
        cmd = "net user " + username + " /add";
        if (system(cmd.c_str()) == 0)
        {
            cls();
            Sleep(20);
            cout << "-------------------------------\n";
            Sleep(20);
            cout << "Tên người dùng: " << username << endl;
            Sleep(20);
            cout << "Mật khẩu: "
                 << "không có\n";
            Sleep(20);
            cout << "-------------------------------\n";
            log("Thêm tài khoản " + username + " thành công và không đặt mật khẩu");
        }
        else 
        {
            cout << "Đã xảy ra lỗi\n";
            log("Tạo tài khoản không thành công\n");
        }
    }
}
void deleteUserAccount()
{
    string username;

    cout << "Nhập tên tài khoản cần xóa: ";
    cin >> username;
    cmd = "net user " + username + " " + "/delete";
    cout << "--------------------------\n";
    if (system(cmd.c_str()) == 0)
    {
        cout << "Đã xóa thành công tài khoản " << username << endl;
        log("Xóa thành công tài khoản " + username);
    }
    else
    {
        cout << "Xóa không thành công :(\n";
        log("Xóa không thành công tài khoản " + username);
    }
}

void deleteUsrPass()
{
    string username;
    cout << "Nhập tên tài khoản muốn xóa mật khẩu: ";
    cin >> username;
    cmd = "net user " + username + " " + "\"\"";
    if (system(cmd.c_str()) == 0)
    {
        cout << "--------------------------\n";
        cout << "Đã xóa thành công mật khẩu tài khoản " << username << endl;
        log("Xóa thành công mật khẩu tài khoản " + username);
    }
    else
    {
        log("Xóa mật khẩu tài khoản " + username + " không thành công");
    }
}
void startup(string fpath)
{
    cls();
    string path = userprofile + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup";
    cmd = "copy " + fpath + " " + path;
    system(cmd.c_str());
}
void writef(string pathf, string data)
{
    fstream wfile;
    wfile.open(pathf, ios_base::app);
    if (wfile.is_open())
    {
        wfile << data;
    }
    wfile.close();
}
void setGroup()
{
    string username;
    string Group;
    int status;
    cout << "Các nhóm người dùng: \n";
    system("net localgroup");
    cout << "--------------------------\n";
    cout << "Nhập tên người dùng: ";
    cin >> username;
    cout << "Nhập nhóm mà bạn muốn têm vào: ";
    cin >> Group;
    cmd = "net localgroup " + Group + " " + username + " /add";
    cls();
    cout << "--------------------------\n";
    if (system(cmd.c_str()) == 0)
    {
        cout << "Đã thêm " << username << " vào nhóm " << Group << " thành công!\n";
        log("Thêm tài khoản " + username + " vào group " + Group);
    }
    else
    {
        log("Thêm tài khoản " + username + " vào group " + Group + " không thành công");
        cout << "Thêm không thành công\n";
    }
    pause();
}
void calc()
{
    char op;
    float num1, num2;
    cout << "Nhập phép tính: ";
    cin >> num1 >> op >> num2;
    cout << "--------------------------\n";
    cout << "Kết quả: ";
    log("Sử dụng máy tính");
    switch (op)
    {

    case '+':
        cout << num1 + num2 << endl;
        break;

    case '-':
        cout << num1 - num2 << endl;
        break;
    case '*':
        cout << num1 * num2 << endl;
        break;

    case '/':
        cout << num1 / num2 << endl;
        break;

    default:
        cout << "Nhập không đúng\n";
        break;
    }
}
void mkdir_cf()
{
    string folder = userprofile + "\\desktop\\ComradeTool";
    mkdir(folder.c_str());
}

void loading_progress(int step, int total)
{
    const int pwidth = 50;
    int width = pwidth;
    int pos = (step * width) / total;
    int percent = (step * 100) / total;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
    printf("                                                                       [");

    for (int i = 0; i < pos; i++)
        cout << "█";

    printf("% *c", width - pos + 1, ']');
    printf(" %3d%%\r", percent);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08);
}

void log(string data)
{
    now = time(0);
    tm *ltm = localtime(&now);
    h = ltm->tm_hour;
    m = ltm->tm_min;
    s = ltm->tm_sec;
    day = ltm->tm_mday;
    year = 1900 + ltm->tm_year;
    month = ltm->tm_mon + 1;
    string timeNow = "Ngày " + to_string(day) + "/" + to_string(month) + "/" + to_string(year) + " " + to_string(h) + ":" + to_string(m) + ":" + to_string(s);
    string log_content = timeNow + " [công việc] :: " + data + "\n";
    writef(userprofile + "/desktop/ComradeTool/ComradeTool.log", log_content);
}
void loading()
{
    mkdir_cf();
    log("Loading...");
    int total = 100;
    int step = 0;

    while (step < total)
    {
        Sleep(20);
        step += 1;
        loading_progress(step, total);
    }

    printf("\n");
}

void shutdown(char mode)
{
    switch (mode)
    {
    case 's':
        cmd = "shutdown -s -t 3";
        system(cmd.c_str());
        break;
    case 'r':
        cmd = "shutdown -r -t 3";
        system(cmd.c_str());
        break;
    case 'h':
        cmd = "shutdown -h -t 3";
        system(cmd.c_str());
        break;
    case 'l':
        cmd = "shutdown -l";
        system(cmd.c_str());
        break;
    }
    pause();
}