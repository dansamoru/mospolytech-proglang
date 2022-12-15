#include <iostream>
#include <bitset>
#include <fstream>

using namespace std;

const int N = 1000000;

int main() {
    ifstream fIn("../in.txt");
    ofstream fOut("../out.txt");
    bitset <N> set;
    
    if (fIn) {
        int x;
        while (fIn >> x) {
            set.set(x, true);
        }
    } else {
        cout << "Ошибка...";
    }
    
    for (int i = 0; i < N; ++i) {
        if (set[i] == 1) {
            fOut << i << " ";
        }
    }
    return 0;
}
