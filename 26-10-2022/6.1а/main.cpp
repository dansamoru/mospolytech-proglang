#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fIn;
    ofstream fOut;
    string fio, nfio;
    cout << "Введите ваше ФИО: " << endl;
    getline(cin, fio);
    fOut.open("../fio.txt");
    if (fOut) {
        fOut << fio;
    } else {
        cout << "Ошибка...";
    }
    fOut.close();
    fIn.open("../fio.txt");
    if (fIn) {
        getline(fIn, nfio);
        cout << nfio;
    } else {
        cout << "Ошибка...";
    }
    return 0;
}
