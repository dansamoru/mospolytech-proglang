#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
    ofstream f;
    f.open("../rnd.txt");
    srand(time(NULL));
    if (f) {
        for (int i = 0; i < 25; ++i) {
            f << rand() << " ";
        }
    } else {
        cout << "Ошибка...";
    }
    return 0;
}
