#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    unsigned char ch;
    cout << "#\n# �������-��������� ��������������\n#\n\n";
    cout << ">>> ������� ������: ";
    ch = _getch();
    while ((int) ch != 27) {
        if (((int) ch < 91) || (((int) ch > 191) && (((int) ch < 224)))) {
            cout << ch << "\n��������������� ������: " << (char) (ch + 32) << endl;
        } else if ((((int) ch > 96) && (((int) ch < 123))) || (((int) ch > 223) && (((int) ch <= 255)))) {
            cout << ch << "\n��������������� ������: " << (char) (ch - 32) << endl;
        } else if ((int) ch == 168) {
            cout << ch << "\n��������������� ������: " << (char) (ch + 16) << endl;
        } else if ((int) ch == 184) {
            cout << ch << "\n��������������� ������: " << (char) (ch - 16) << endl;
        } else {
            cout << ch << "\n��������������� ������: " << ch << endl;
        }
        cout << ">>> ������� ������: ";
        ch = _getch();
    }
    cout << "ESC" << endl;
    return 0;
}
